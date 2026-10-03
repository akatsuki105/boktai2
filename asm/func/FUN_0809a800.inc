	push {lr}
	ldr r0, _0809A814 @ =0x0000CEAA
	ldr r1, _0809A818 @ =0x00003002
	bl GetFile
	bl LoadParticleFile
	pop {r0}
	bx r0
	.align 2, 0
_0809A814: .4byte 0x0000CEAA
_0809A818: .4byte 0x00003002
