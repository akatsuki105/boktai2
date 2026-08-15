	push {lr}
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _08060C76
	movs r0, #0xd8
	bl sound_08240740
	b _08060C88
_08060C76:
	ldr r0, _08060C8C @ =0x00000239
	bl sound_08240740
	ldr r0, _08060C90 @ =0x00000202
	bl sound_08240740
	ldr r0, _08060C94 @ =0x00000366
	bl sound_08240740
_08060C88:
	pop {r0}
	bx r0
	.align 2, 0
_08060C8C: .4byte 0x00000239
_08060C90: .4byte 0x00000202
_08060C94: .4byte 0x00000366
