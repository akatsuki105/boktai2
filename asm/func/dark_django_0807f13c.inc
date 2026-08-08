	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r4, [r0]
	cmp r4, #1
	bne _0807F1EC
	ldr r2, _0807F1B8 @ =0x030046A0
	mov r8, r2
	ldr r0, [r2]
	subs r1, #0xb0
	adds r3, r0, r1
	movs r7, #0xab
	lsls r7, r7, #2
	adds r0, r0, r7
	ldr r1, [r3]
	ldr r0, [r0]
	cmp r1, r0
	blt _0807F1DC
	ldr r2, _0807F1BC @ =0x0000044A
	adds r6, r5, r2
	ldrb r2, [r6]
	cmp r2, #0
	beq _0807F1C8
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bhi _0807F1FA
	movs r4, #0
	str r4, [r3]
	ldr r2, _0807F1C0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	adds r1, #0x83
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0807F1C4 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x64
	bl Mod
	mov r2, r8
	ldr r1, [r2]
	adds r1, r1, r7
	adds r0, #0xc8
	str r0, [r1]
	strb r4, [r6]
	adds r0, r5, #0
	movs r1, #2
	bl FUN_08060e90
	adds r0, r5, #0
	bl FUN_080801b0
	b _0807F1FA
	.align 2, 0
_0807F1B8: .4byte 0x030046A0
_0807F1BC: .4byte 0x0000044A
_0807F1C0: .4byte 0x030046B8
_0807F1C4: .4byte 0x0203B400
_0807F1C8:
	ldr r0, _0807F1D8 @ =0x00000449
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0807F1FA
	strb r4, [r6]
	strb r2, [r1]
	b _0807F1FA
	.align 2, 0
_0807F1D8: .4byte 0x00000449
_0807F1DC:
	ldr r2, _0807F1E8 @ =0x00000449
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	b _0807F1FA
	.align 2, 0
_0807F1E8: .4byte 0x00000449
_0807F1EC:
	ldr r1, _0807F204 @ =0x0000044A
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _0807F208 @ =0x00000449
	adds r0, r5, r2
	strb r1, [r0]
_0807F1FA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807F204: .4byte 0x0000044A
_0807F208: .4byte 0x00000449
