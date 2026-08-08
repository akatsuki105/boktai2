	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	adds r4, r0, #0
	mov sb, r4
	adds r7, r4, #0
	adds r7, #0x9c
	ldr r0, _080F2668 @ =0x0000046C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080F266C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080F266E
	.align 2, 0
_080F2668: .4byte 0x0000046C
_080F266C:
	movs r0, #0
_080F266E:
	cmp r0, #0
	beq _080F269C
	ldr r1, _080F2700 @ =0x000005A4
	adds r0, r4, r1
	ldr r3, [r0]
	movs r2, #0
	ldr r0, _080F2704 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080F2708 @ =0x0000046B
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r2, [r0]
_080F269C:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F26B2
	b _080F2852
_080F26B2:
	adds r0, r4, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080F26C2
	b _080F2852
_080F26C2:
	ldr r2, [r7, #8]
	ldrb r0, [r2, #6]
	lsrs r5, r0, #4
	cmp r5, #1
	bne _080F2714
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080F270C @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r5, [r0]
	adds r3, #0x1b
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _080F2710 @ =0x0000046C
	adds r0, r4, r1
	strb r5, [r0]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r4, r3
	movs r1, #0x21
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _080F2852
	.align 2, 0
_080F2700: .4byte 0x000005A4
_080F2704: .4byte 0x0000046D
_080F2708: .4byte 0x0000046B
_080F270C: .4byte 0x00000469
_080F2710: .4byte 0x0000046C
_080F2714:
	ldrb r1, [r7, #3]
	adds r0, r1, #1
	strb r0, [r7, #3]
	lsls r1, r1, #0x18
	ldrh r2, [r2, #4]
	ldr r0, _080F2784 @ =0x00000FFF
	lsrs r1, r1, #0x18
	ands r0, r2
	cmp r1, r0
	bhs _080F272A
	b _080F2848
_080F272A:
	movs r0, #0xca
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r0, [r2]
	cmp r0, #0
	beq _080F2762
	adds r0, r4, #0
	adds r0, #0x9e
	ldrb r0, [r0]
	str r0, [sp]
	ldrh r0, [r4]
	str r0, [sp, #4]
	ldr r1, _080F2788 @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	str r0, [sp, #8]
	ldr r1, _080F278C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	str r0, [sp, #0xc]
	add r1, sp, #0xc
	mov r3, sp
	str r3, [r1, #4]
	ldrh r0, [r2]
	bl FUN_082318ac
_080F2762:
	adds r0, r7, #0
	bl FUN_08234e3c
	adds r0, r4, #0
	bl FUN_080e6204
	ldr r0, [r7, #8]
	ldrb r0, [r0, #6]
	lsrs r5, r0, #4
	cmp r5, #4
	bne _080F2794
	ldr r0, _080F2790 @ =0x00000482
	adds r1, r4, r0
	movs r0, #2
	strh r0, [r1]
	movs r5, #2
	b _080F2814
	.align 2, 0
_080F2784: .4byte 0x00000FFF
_080F2788: .4byte 0x000001DF
_080F278C: .4byte 0xFFFF0000
_080F2790: .4byte 0x00000482
_080F2794:
	ldr r2, _080F27DC @ =0x00000482
	adds r1, r4, r2
	movs r6, #0
	movs r3, #1
	mov r8, r3
	movs r0, #1
	strh r0, [r1]
	cmp r5, #0
	bne _080F2814
	mov r1, sb
	adds r1, #8
	adds r0, r7, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_08235038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F27E8
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r6, [r0]
	ldr r3, _080F27E0 @ =0x00000469
	adds r0, r4, r3
	strb r6, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r3, #0x1b
	adds r0, r4, r3
	str r5, [r0]
	ldr r1, _080F27E4 @ =0x0000046C
	b _080F2804
	.align 2, 0
_080F27DC: .4byte 0x00000482
_080F27E0: .4byte 0x00000469
_080F27E4: .4byte 0x0000046C
_080F27E8:
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r6, [r0]
	ldr r1, _080F280C @ =0x00000469
	adds r0, r4, r1
	strb r6, [r0]
	ldr r2, _080F2810 @ =0x0000046A
	adds r0, r4, r2
	strb r6, [r0]
	adds r3, #0x1c
	adds r0, r4, r3
	str r5, [r0]
	adds r1, #3
_080F2804:
	adds r0, r4, r1
	mov r2, r8
	strb r2, [r0]
	b _080F2852
	.align 2, 0
_080F280C: .4byte 0x00000469
_080F2810: .4byte 0x0000046A
_080F2814:
	ldr r0, _080F2840 @ =0x085AD468
	adds r0, r5, r0
	ldrb r2, [r0]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _080F2844 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	b _080F2852
	.align 2, 0
_080F2840: .4byte 0x085AD468
_080F2844: .4byte 0x00000484
_080F2848:
	ldr r0, _080F2860 @ =0x00000484
	adds r1, r4, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080F2852:
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F2860: .4byte 0x00000484
