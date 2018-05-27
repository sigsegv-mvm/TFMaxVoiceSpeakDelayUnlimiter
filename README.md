TFMaxVoiceSpeakDelayUnlimiter
=============================

Were you bothered by the fact that Valve added a minimum value limit of `0.10`
to the `tf_max_voice_speak_delay` console variable in TF2's Jungle Inferno
update? Are you perturbed that you can no longer seem to set it to `-1`, and
that as a consequence of this, the players on your server(s) can no longer
adequately express just how desperately they need a dispenser?

Well, if so, then this is the SourceMod extension for you!

When this extension loads up, it removes the newly enforced limits on convar
`tf_max_voice_speak_delay`. This means that once it's loaded, you can then set
that convar to values like `-1` via `sm_cvar` (or other means), just as you
could before Jungle Inferno.

And then, when this extension is unloaded, it restores the convar value limits
back to how they were before it loaded, so that everything is put back neat and
tidy, as if nothing had been messed with. When the limits are restored, the
current convar value will be clamped, if necessary, to ensure that it's within
those limits.

Known Issues
------------
With the May 17 2018 update to Team Fortress 2, Valve attempted to counter the
recent plague of "lag bots": large groups of fake player bots deployed en
masse to TF2 matchmaking servers by antisocial s\*\*tbag cheat/"hack"
developers. Using **nullifiedcat**'s cheat framework as a basis for their bot
code, these fine upstanding individuals have designed their bots with the
explicit purpose and intent to ruin other players' game experiences by (a)
causing intense server lag at will, whenever they want; and then (b)
intentionally inducing the game server to crash if the players on the server
attempt to votekick the "lag bot" from the server.

These bots' lag and server-crash "features" were implemented by inundating the
server with literally **hundreds to tens of thousands** of `voicemenu` commands
per second. (`voicemenu` is the command that your TF2 client sends to the game
server whenever you do a voice command, whether you did it via the Z/X/C menus,
via a key binding, or just manually in the console.)

So in the May 17 update, one change Valve made was to make the `voicemenu`
command be rate-limited on the server side. This means that if a particular
player attempts to do `voicemenu` less than 300 milliseconds since the last
time they successfully did `voicemenu`, the server will ignore it. In other
words, voice commands are now limited to a maximum of 3.33x/second for each
player. (In this case, as in so many others, cheat developers are the reason
why we can't have nice things.)

This means that `tf_max_voice_speak_delay` values lower than `0.3` (including
`-1`) no longer function properly: even though `tf_max_voice_speak_delay` may
not be limiting the rate of voice commands from players, the new ratelimiting
constraint on the `voicemenu` command **is** still enforcing a minimum delay of
0.3 seconds between voice commands.

I know that this is a potentially extremely distressing problem, as players on
your server probably do still desperately need the ability to demand a
dispenser more frequently than a mere 3.33x/second. So I'll be looking into the
possibility of adding a bypass for the ratelimiting on the `voicemenu` command
to this extension in the near future.
