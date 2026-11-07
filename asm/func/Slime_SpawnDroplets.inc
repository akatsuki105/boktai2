	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x34
	mov r8, r0
	ldr r4, _08164814 @ =0x0203B400
	ldr r3, _08164818 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _0816481C @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r7, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	add r2, sp, #0x2c
	adds r3, r0, #6
	ldr r1, _08164820 @ =gSineTable
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _08164824
	asrs r1, r0, #0xc
	b _0816482A
	.align 2, 0
_08164814: .4byte 0x0203B400
_08164818: .4byte 0x030046B8
_0816481C: .4byte 0x000003FF
_08164820: .4byte gSineTable
_08164824:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816482A:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	ldr r1, _08164844 @ =gSineTable
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _08164848
	asrs r0, r0, #0xc
	b _0816484E
	.align 2, 0
_08164844: .4byte gSineTable
_08164848:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816484E:
	movs r4, #0
	strh r0, [r2, #4]
	add r1, sp, #0x2c
	movs r0, #0x30
	strh r0, [r1, #2]
	mov r6, r8
	adds r6, #8
	ldr r2, _081648D8 @ =0x0000B96C
	ldr r3, _081648DC @ =0x0000A929
	movs r0, #6
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	ldr r0, _081648E0 @ =0x0000047A
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #3
	add r1, r8
	ldrh r1, [r1]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	adds r0, r6, #0
	add r1, sp, #0x2c
	bl Entity081efa9c_Spawn
	ldr r4, _081648E4 @ =0x0203B400
	ldr r3, _081648E8 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _081648EC @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r7, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	add r3, sp, #0x2c
	adds r2, r0, #6
	ldr r1, _081648F0 @ =gSineTable
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _081648F4
	asrs r1, r0, #0xc
	b _081648FA
	.align 2, 0
_081648D8: .4byte 0x0000B96C
_081648DC: .4byte 0x0000A929
_081648E0: .4byte 0x0000047A
_081648E4: .4byte 0x0203B400
_081648E8: .4byte 0x030046B8
_081648EC: .4byte 0x000003FF
_081648F0: .4byte gSineTable
_081648F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081648FA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _08164914 @ =gSineTable
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _08164918
	asrs r0, r0, #0xc
	b _0816491E
	.align 2, 0
_08164914: .4byte gSineTable
_08164918:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0816491E:
	movs r4, #0
	strh r0, [r3, #4]
	add r1, sp, #0x2c
	movs r0, #0x25
	strh r0, [r1, #2]
	ldr r2, _081649A4 @ =0x0000B96C
	ldr r3, _081649A8 @ =0x0000A929
	movs r0, #7
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	ldr r0, _081649AC @ =0x0000047A
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #3
	add r1, r8
	ldrh r1, [r1]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	adds r0, r6, #0
	add r1, sp, #0x2c
	bl Entity081efa9c_Spawn
	ldr r4, _081649B0 @ =0x0203B400
	ldr r3, _081649B4 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _081649B8 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r7, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	add r3, sp, #0x2c
	adds r2, r0, #6
	ldr r1, _081649BC @ =gSineTable
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _081649C0
	asrs r1, r0, #0xc
	b _081649C6
	.align 2, 0
_081649A4: .4byte 0x0000B96C
_081649A8: .4byte 0x0000A929
_081649AC: .4byte 0x0000047A
_081649B0: .4byte 0x0203B400
_081649B4: .4byte 0x030046B8
_081649B8: .4byte 0x000003FF
_081649BC: .4byte gSineTable
_081649C0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081649C6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _081649E0 @ =gSineTable
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _081649E4
	asrs r0, r0, #0xc
	b _081649EA
	.align 2, 0
_081649E0: .4byte gSineTable
_081649E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081649EA:
	movs r4, #0
	strh r0, [r3, #4]
	add r1, sp, #0x2c
	movs r0, #0x20
	strh r0, [r1, #2]
	ldr r2, _08164A3C @ =0x0000B96C
	ldr r3, _08164A40 @ =0x0000A929
	movs r0, #7
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	ldr r0, _08164A44 @ =0x0000047A
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #3
	add r1, r8
	ldrh r1, [r1]
	adds r0, r0, r1
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	adds r0, r6, #0
	add r1, sp, #0x2c
	bl Entity081efa9c_Spawn
	add sp, #0x34
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08164A3C: .4byte 0x0000B96C
_08164A40: .4byte 0x0000A929
_08164A44: .4byte 0x0000047A
