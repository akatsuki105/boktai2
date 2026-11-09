	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _08181D98 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08181D9C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08181D9E
	.align 2, 0
_08181D98: .4byte 0x0000046C
_08181D9C:
	movs r0, #0
_08181D9E:
	cmp r0, #0
	beq _08181DEC
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _08181E54 @ =FUN_0818023c
	movs r2, #0x23
	ldr r0, _08181E58 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08181E5C @ =0x0000046B
	adds r0, r6, r1
	strb r3, [r0]
	ldr r3, _08181E60 @ =0x00000553
	adds r0, r6, r3
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r5, [r0]
	ldr r3, _08181E64 @ =0x0000088C
	adds r0, r7, r3
	ldrh r1, [r0]
	movs r5, #0x88
	lsls r5, r5, #4
	adds r0, r7, r5
	strh r1, [r0]
_08181DEC:
	ldr r1, _08181E5C @ =0x0000046B
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08181DF8
	b _08181F5C
_08181DF8:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
	ldr r1, _08181E68 @ =0xFFFFFEFF
	ldrh r0, [r2]
	ands r1, r0
	movs r4, #0
	movs r5, #0
	strh r1, [r2]
	ldr r2, _08181E6C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08181E70 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08181E74 @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _08181E80
	ldr r3, _08181E78 @ =FUN_0817fc24
	movs r2, #0x2e
	ldr r0, _08181E58 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08181E5C @ =0x0000046B
	adds r0, r6, r1
	strb r4, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r5, [r0]
	ldr r5, _08181E7C @ =0x0000089F
	adds r1, r7, r5
	movs r0, #0xa0
	b _08181EB2
	.align 2, 0
_08181E54: .4byte FUN_0818023c
_08181E58: .4byte 0x0000046D
_08181E5C: .4byte 0x0000046B
_08181E60: .4byte 0x00000553
_08181E64: .4byte 0x0000088C
_08181E68: .4byte 0xFFFFFEFF
_08181E6C: .4byte 0x030046B8
_08181E70: .4byte 0x000003FF
_08181E74: .4byte 0x0203B400
_08181E78: .4byte FUN_0817fc24
_08181E7C: .4byte 0x0000089F
_08181E80:
	ldr r2, _08181ED8 @ =FUN_0817fc84
	ldr r0, _08181EDC @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08181EE0 @ =0x0000046B
	adds r0, r6, r1
	strb r4, [r0]
	ldr r3, _08181EE4 @ =0x00000553
	adds r0, r6, r3
	strb r4, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r5, [r0]
	ldr r3, _08181EE8 @ =0x0000089C
	adds r0, r7, r3
	strb r4, [r0]
	ldr r5, _08181EEC @ =0x0000089F
	adds r1, r7, r5
	movs r0, #0x1e
_08181EB2:
	strb r0, [r1]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _08181EF0 @ =0x00000546
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r1, r0
	bgt _08181EF4
	ldr r5, _08181EEC @ =0x0000089F
	adds r0, r7, r5
	ldrb r0, [r0]
	lsrs r0, r0, #1
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r1, r6, r2
	b _08181F00
	.align 2, 0
_08181ED8: .4byte FUN_0817fc84
_08181EDC: .4byte 0x0000046D
_08181EE0: .4byte 0x0000046B
_08181EE4: .4byte 0x00000553
_08181EE8: .4byte 0x0000089C
_08181EEC: .4byte 0x0000089F
_08181EF0: .4byte 0x00000546
_08181EF4:
	ldr r3, _08181F48 @ =0x0000089F
	adds r0, r7, r3
	ldrb r0, [r0]
	movs r5, #0xc9
	lsls r5, r5, #1
	adds r1, r6, r5
_08181F00:
	strh r0, [r1]
	movs r0, #0xc9
	lsls r0, r0, #1
	adds r2, r6, r0
	ldrh r1, [r2]
	movs r3, #0xc8
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r3, #0
	movs r4, #0
	strh r1, [r0]
	ldrh r0, [r2]
	adds r0, #0x28
	ldr r5, _08181F4C @ =0x000008AA
	adds r1, r7, r5
	strh r0, [r1]
	movs r1, #2
	movs r2, #3
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r6, r5
	strb r3, [r0]
	ldr r3, _08181F50 @ =0x00000469
	adds r0, r6, r3
	strb r1, [r0]
	adds r5, #2
	adds r0, r6, r5
	strb r2, [r0]
	ldr r1, _08181F54 @ =0x00000484
	adds r0, r6, r1
	str r4, [r0]
	ldr r2, _08181F58 @ =0x0000046C
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
	b _08181F66
	.align 2, 0
_08181F48: .4byte 0x0000089F
_08181F4C: .4byte 0x000008AA
_08181F50: .4byte 0x00000469
_08181F54: .4byte 0x00000484
_08181F58: .4byte 0x0000046C
_08181F5C:
	ldr r3, _08181F6C @ =0x00000484
	adds r1, r6, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08181F66:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08181F6C: .4byte 0x00000484
