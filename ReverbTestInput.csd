<CsoundSynthesizer>
<CsOptions>
-o dac
-d
-i adc
</CsOptions>
<CsInstruments>
sr        = 44100
ksmps     = 64
nchnls    = 2
0dbfs      = 1
instr 1
kfeed init 0.05
kco init 12000
kpitch init 0.7
asig1 init 0
asig2 init 0
asig1,asig2 ins
arev, arev2 reverbsc asig1, asig2, 0.850000, 16000, sr, 0.700000, 1
outs arev, arev2
endin
</CsInstruments>
<CsScore>
f 1 0 16384 9 1
i 1 0 30
</CsScore>
</CsoundSynthesizer>
