	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0x18
	ldr r1, _080DA808 @ =0x0000363C
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r0, #0x34
	ldr r1, _080DA80C @ =0x0000363D
	bl Video_GetAuxSprite
	ldr r0, _080DA810 @ =0x00001C1C
	bl GetParticleGroup
	str r0, [r5, #0x58]
	ldr r4, _080DA814 @ =0x0000922E
	ldr r1, _080DA818 @ =0x00006830
	adds r0, r4, #0
	bl GetFile
	str r0, [r5, #0x50]
	ldr r1, _080DA81C @ =0x0000D41F
	adds r0, r4, #0
	bl GetFile
	str r0, [r5, #0x54]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DA808: .4byte 0x0000363C
_080DA80C: .4byte 0x0000363D
_080DA810: .4byte 0x00001C1C
_080DA814: .4byte 0x0000922E
_080DA818: .4byte 0x00006830
_080DA81C: .4byte 0x0000D41F
