	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	bl FUN_080ee2c8
	movs r0, #3
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	movs r4, #0
	strb r0, [r1]
	ldr r2, _080EE974 @ =0x00000469
	adds r2, r2, r7
	mov sb, r2
	strb r4, [r2]
	ldr r3, _080EE978 @ =0x0000046A
	adds r3, r3, r7
	mov sl, r3
	strb r4, [r3]
	ldr r6, _080EE97C @ =0x00000484
	adds r0, r7, r6
	str r4, [r0]
	ldr r0, _080EE980 @ =0x0000046C
	adds r0, r7, r0
	str r0, [sp]
	movs r2, #1
	strb r2, [r0]
	ldr r1, _080EE984 @ =FUN_080e48d0
	movs r0, #0x10
	ldr r3, _080EE988 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #4]
	strb r2, [r3]
	subs r6, #0x19
	adds r6, r6, r7
	mov ip, r6
	strb r4, [r6]
	ldr r3, _080EE98C @ =0x00000553
	adds r3, r7, r3
	str r3, [sp, #0xc]
	strb r0, [r3]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r3, r7, r6
	str r1, [r3]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r5, #0
	strh r4, [r0]
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #8]
	ldr r1, _080EE990 @ =0x0000055C
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [r6]
	movs r6, #0xbe
	lsls r6, r6, #1
	adds r1, r7, r6
	movs r6, #0xac
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _080EE994 @ =0x00000564
	adds r0, r7, r1
	ldrb r0, [r0]
	strb r0, [r7, #5]
	adds r6, #5
	adds r0, r7, r6
	ldrb r0, [r0]
	mov r1, r8
	strb r0, [r1]
	adds r6, #1
	adds r0, r7, r6
	ldrb r0, [r0]
	mov r1, sb
	strb r0, [r1]
	adds r6, #1
	adds r0, r7, r6
	ldrb r0, [r0]
	mov r1, sl
	strb r0, [r1]
	adds r6, #1
	adds r0, r7, r6
	ldr r0, [r0]
	str r0, [r3]
	ldr r1, _080EE998 @ =0x0000056C
	adds r0, r7, r1
	ldrb r0, [r0]
	ldr r3, [sp, #0xc]
	strb r0, [r3]
	adds r6, #0xa
	adds r0, r7, r6
	ldrh r1, [r0]
	ldr r3, _080EE99C @ =0x00000474
	adds r0, r7, r3
	strh r1, [r0]
	subs r6, #2
	adds r0, r7, r6
	ldrh r0, [r0]
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	movs r6, #0x95
	lsls r6, r6, #2
	adds r0, r7, r6
	ldrh r1, [r0]
	subs r3, #0x3a
	adds r0, r7, r3
	strh r1, [r0]
	subs r6, #0xd2
	adds r0, r7, r6
	strh r4, [r0]
	ldr r1, _080EE9A0 @ =0x00000222
	adds r0, r7, r1
	strh r4, [r0]
	subs r3, #4
	adds r0, r7, r3
	strh r4, [r0]
	mov r6, ip
	strb r5, [r6]
	ldr r0, [sp]
	strb r2, [r0]
	ldr r1, [sp, #4]
	strb r2, [r1]
	ldr r3, _080EE9A4 @ =0x0000046E
	adds r0, r7, r3
	strb r5, [r0]
	ldr r6, _080EE9A8 @ =0x0000024E
	adds r0, r7, r6
	strh r4, [r0]
	movs r1, #0xc9
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	adds r3, #0xd6
	adds r0, r7, r3
	strh r4, [r0]
	ldr r6, _080EE9AC @ =0x00000466
	adds r0, r7, r6
	strh r4, [r0]
	adds r1, #0x42
	adds r0, r7, r1
	str r4, [r0]
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	str r4, [r0]
	ldr r6, _080EE9B0 @ =0x000001DD
	adds r0, r7, r6
	strb r5, [r0]
	adds r1, #0x48
	adds r0, r7, r1
	strb r5, [r0]
	ldr r3, _080EE9B4 @ =0x00000482
	adds r0, r7, r3
	strh r2, [r0]
	movs r6, #0x93
	lsls r6, r6, #3
	adds r0, r7, r6
	str r4, [r0]
	ldr r1, _080EE9B8 @ =0x0000049C
	adds r0, r7, r1
	str r4, [r0]
	movs r2, #0x94
	lsls r2, r2, #3
	adds r0, r7, r2
	str r4, [r0]
	adds r3, #0xa
	adds r0, r7, r3
	strb r5, [r0]
	adds r6, #0x26
	adds r0, r7, r6
	strh r4, [r0]
	subs r1, #0xf
	adds r0, r7, r1
	strb r5, [r0]
	subs r2, #0x12
	adds r0, r7, r2
	strb r5, [r0]
	subs r3, #0x34
	adds r0, r7, r3
	movs r1, #8
	bl ClearMemory
	subs r6, #0x5a
	adds r0, r7, r6
	strh r4, [r0]
	movs r1, #0x8c
	lsls r1, r1, #3
	adds r0, r7, r1
	strh r4, [r0]
	ldr r2, _080EE9BC @ =0x00000462
	adds r0, r7, r2
	strh r4, [r0]
	ldr r1, _080EE9C0 @ =0x08251F68
	adds r0, r7, #0
	ldr r2, _080EE9C4 @ =0x00000982
	bl FUN_080e6768
	movs r3, #0xa8
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r5, [r0]
	adds r6, #0xdd
	adds r0, r7, r6
	strb r5, [r0]
	ldr r0, _080EE9C8 @ =0x00000542
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r0, r7, r1
	str r4, [r0]
	ldr r2, _080EE9CC @ =0x0000054C
	adds r0, r7, r2
	strb r5, [r0]
	adds r3, #0xd
	adds r0, r7, r3
	strb r5, [r0]
	adds r6, #0xd
	adds r0, r7, r6
	strb r5, [r0]
	adds r1, #7
	adds r0, r7, r1
	strb r5, [r0]
	adds r0, r7, #0
	bl FUN_080eeee0
	movs r1, #2
	ldr r2, [sp, #8]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r2, r7, #0
	adds r2, #0xde
	ldrh r0, [r2]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	cmp r1, #0
	beq _080EE93E
	adds r0, r7, #0
	bl _call_via_r1
_080EE93E:
	adds r0, r7, #0
	bl FUN_080eeee0
	ldr r6, _080EE9D0 @ =0x00000454
	adds r4, r7, r6
	ldr r0, [r4]
	ldrh r2, [r7]
	movs r1, #1
	bl FUN_080d99d4
	str r0, [r4]
	ldrh r2, [r7]
	movs r1, #3
	bl FUN_080d9a9c
	str r0, [r4]
	adds r0, r7, #0
	bl FUN_080ecbe4
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080EE974: .4byte 0x00000469
_080EE978: .4byte 0x0000046A
_080EE97C: .4byte 0x00000484
_080EE980: .4byte 0x0000046C
_080EE984: .4byte FUN_080e48d0
_080EE988: .4byte 0x0000046D
_080EE98C: .4byte 0x00000553
_080EE990: .4byte 0x0000055C
_080EE994: .4byte 0x00000564
_080EE998: .4byte 0x0000056C
_080EE99C: .4byte 0x00000474
_080EE9A0: .4byte 0x00000222
_080EE9A4: .4byte 0x0000046E
_080EE9A8: .4byte 0x0000024E
_080EE9AC: .4byte 0x00000466
_080EE9B0: .4byte 0x000001DD
_080EE9B4: .4byte 0x00000482
_080EE9B8: .4byte 0x0000049C
_080EE9BC: .4byte 0x00000462
_080EE9C0: .4byte 0x08251F68
_080EE9C4: .4byte 0x00000982
_080EE9C8: .4byte 0x00000542
_080EE9CC: .4byte 0x0000054C
_080EE9D0: .4byte 0x00000454
