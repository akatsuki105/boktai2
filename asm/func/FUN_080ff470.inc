	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _080FF498 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _080FF49C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _080FF49E
	.align 2, 0
_080FF498: .4byte 0x0000046C
_080FF49C:
	movs r0, #0
_080FF49E:
	cmp r0, #0
	beq _080FF4EC
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _080FF5CC @ =FUN_080fb4d0
	movs r2, #0x22
	ldr r0, _080FF5D0 @ =0x0000046D
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080FF5D4 @ =0x0000046B
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _080FF5D8 @ =0x00000553
	adds r0, r7, r3
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	ldr r0, _080FF5DC @ =0x00000672
	add r0, sb
	ldrh r1, [r0]
	movs r0, #0xce
	lsls r0, r0, #3
	add r0, sb
	strh r1, [r0]
_080FF4EC:
	ldr r3, _080FF5D4 @ =0x0000046B
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080FF4F8
	b _080FF64C
_080FF4F8:
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r5, r5, r7
	mov r8, r5
	ldr r1, _080FF5E0 @ =0xFFFFFEFF
	ldrh r0, [r5]
	ands r1, r0
	movs r4, #0
	movs r6, #0
	strh r1, [r5]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r7, r0
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r0, _080FF5E4 @ =0x0000067E
	add r0, sb
	ldrh r3, [r0]
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r2, [r0]
	movs r5, #0xc
	mov ip, r5
	movs r0, #0xab
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r5, _080FF5E8 @ =0x00000554
	adds r0, r7, r5
	str r3, [r0]
	str r2, [r1]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _080FF5EC @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _080FF5F0 @ =0x00000552
	adds r0, r7, r3
	mov r5, ip
	strb r5, [r0]
	ldr r2, _080FF5F4 @ =0x080E6795
	movs r1, #0xe
	subs r3, #0xe5
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r5, _080FF5D4 @ =0x0000046B
	adds r0, r7, r5
	strb r4, [r0]
	adds r5, #0xe8
	adds r0, r7, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r6, [r0]
	movs r1, #3
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _080FF5F8 @ =0x00000469
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _080FF5FC @ =0x0000046A
	adds r0, r7, r2
	strb r4, [r0]
	adds r5, #0x1c
	adds r0, r7, r5
	str r6, [r0]
	adds r1, #3
	adds r0, r7, r1
	strb r3, [r0]
	adds r2, #0x3a
	adds r0, r7, r2
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r4, #0xcc
	lsls r4, r4, #3
	add r4, sb
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _080FF604
	ldr r0, _080FF600 @ =0xFFFFFDFF
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	b _080FF62E
	.align 2, 0
_080FF5CC: .4byte FUN_080fb4d0
_080FF5D0: .4byte 0x0000046D
_080FF5D4: .4byte 0x0000046B
_080FF5D8: .4byte 0x00000553
_080FF5DC: .4byte 0x00000672
_080FF5E0: .4byte 0xFFFFFEFF
_080FF5E4: .4byte 0x0000067E
_080FF5E8: .4byte 0x00000554
_080FF5EC: .4byte 0x00000551
_080FF5F0: .4byte 0x00000552
_080FF5F4: .4byte 0x080E6795
_080FF5F8: .4byte 0x00000469
_080FF5FC: .4byte 0x0000046A
_080FF600: .4byte 0xFFFFFDFF
_080FF604:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _080FF624
	cmp r0, #2
	beq _080FF620
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_080FF620:
	movs r0, #1
	b _080FF630
_080FF624:
	ldr r0, _080FF644 @ =0xFFFFFDFF
	mov r5, r8
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
_080FF62E:
	movs r0, #0
_080FF630:
	cmp r0, #0
	bne _080FF656
	ldr r1, _080FF648 @ =0x000005C4
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _080FF656
	.align 2, 0
_080FF644: .4byte 0xFFFFFDFF
_080FF648: .4byte 0x000005C4
_080FF64C:
	ldr r2, _080FF664 @ =0x00000484
	adds r1, r7, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080FF656:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080FF664: .4byte 0x00000484
