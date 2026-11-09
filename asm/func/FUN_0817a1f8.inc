	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r7, r6
	ldr r0, _0817A30C @ =0xFFFFFEDF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r0, _0817A310 @ =0x000003DB
	bl PlaySound_082406e0
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, [r7, #0x44]
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0817A300
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0817A300
	ldr r2, _0817A314 @ =0x0000046A
	adds r0, r7, r2
	ldrb r1, [r0]
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0817A258
	adds r0, r1, #0
	cmp r0, #0xc
	beq _0817A258
	cmp r0, #0xf
	bne _0817A300
_0817A258:
	ldr r6, _0817A318 @ =0x00000544
	adds r1, r7, r6
	movs r4, #0
	movs r5, #0
	movs r0, #0xf0
	strh r0, [r1]
	adds r0, #0x8c
	adds r2, r7, r0
	ldr r1, _0817A31C @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #1
	mov ip, r1
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r7, r6
	movs r3, #1
	mvns r0, r3
	ldrh r1, [r2]
	ands r0, r1
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r0, r1
	strh r0, [r2]
	ldr r2, _0817A320 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r6, _0817A324 @ =0x0000046D
	adds r0, r7, r6
	strb r3, [r0]
	subs r6, #2
	adds r0, r7, r6
	strb r4, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	movs r1, #5
	subs r6, #0xeb
	adds r0, r7, r6
	strb r4, [r0]
	ldr r2, _0817A328 @ =0x00000469
	adds r0, r7, r2
	strb r4, [r0]
	adds r6, #2
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0817A32C @ =0x00000484
	adds r0, r7, r1
	str r5, [r0]
	adds r2, #3
	adds r0, r7, r2
	strb r3, [r0]
	movs r6, #0xfe
	lsls r6, r6, #1
	adds r0, r7, r6
	ldrb r0, [r0]
	strb r0, [r7, #5]
	subs r1, #2
	adds r0, r7, r1
	mov r2, ip
	strh r2, [r0]
	movs r0, #0xfb
	lsls r0, r0, #4
	add r0, r8
	strh r5, [r0]
	ldr r2, _0817A330 @ =0x00001008
	add r2, r8
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r6, #0xac
	adds r0, r7, r6
	bl AuxShadow_Hide
_0817A300:
	movs r0, #1
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0817A30C: .4byte 0xFFFFFEDF
_0817A310: .4byte 0x000003DB
_0817A314: .4byte 0x0000046A
_0817A318: .4byte 0x00000544
_0817A31C: .4byte 0xFFEFFFFF
_0817A320: .4byte Enemy_ClearStateBegun
_0817A324: .4byte 0x0000046D
_0817A328: .4byte 0x00000469
_0817A32C: .4byte 0x00000484
_0817A330: .4byte 0x00001008
