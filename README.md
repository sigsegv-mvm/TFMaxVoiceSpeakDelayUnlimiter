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
