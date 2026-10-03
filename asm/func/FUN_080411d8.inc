	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r1, #0
	adds r7, r5, #0
	adds r7, #0x5c
	movs r0, #0xd0
	adds r0, r0, r5
	mov r8, r0
	adds r0, r7, #0
	bl Mover_ApplyMove
	movs r1, #0x80
	lsls r1, r1, #3
	ldrh r0, [r5, #0xe]
	ands r0, r1
	cmp r0, #0
	bne _08041282
	adds r6, r5, #0
	adds r6, #0x64
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08041224
	cmp r1, #0
	blt _08041224
	ldr r0, _08041228 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08041224
	ldr r0, _0804122C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08041230
_08041224:
	movs r4, #0
	b _0804123E
	.align 2, 0
_08041228: .4byte 0x030046A8
_0804122C: .4byte 0x030046AC
_08041230:
	ldr r0, _08041250 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0804123E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08041254
	adds r0, #4
	b _08041260
	.align 2, 0
_08041250: .4byte 0x030046A4
_08041254:
	ldr r0, _08041274 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08041260:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08041278
	cmp r2, #2
	beq _0804127C
	b _08041280
	.align 2, 0
_08041274: .4byte 0x030046A4
_08041278:
	ldrb r0, [r6, #4]
	b _0804127E
_0804127C:
	ldrb r0, [r6]
_0804127E:
	subs r1, r1, r0
_08041280:
	strh r1, [r7, #0xa]
_08041282:
	adds r1, r7, #0
	adds r1, #8
	mov r0, r8
	bl FUN_08055ed4
	mov r0, r8
	bl FUN_08055c04
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r3, r5, r1
	ldrh r2, [r3]
	movs r4, #0
	ldrsh r1, [r3, r4]
	cmp r1, #0
	ble _080412EA
	subs r1, r2, #1
	strh r1, [r3]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #3
	bgt _080412EA
	ldrb r1, [r5, #0xa]
	cmp r1, #0
	beq _080412D0
	ldr r1, _080412CC @ =0x030047A4
	ldr r1, [r1]
	movs r2, #0x80
	lsls r2, r2, #2
	ands r1, r2
	cmp r1, #0
	bne _080412D0
	adds r2, #0xca
	adds r1, r5, r2
	ldrh r1, [r1]
	strh r1, [r3]
	b _080412EA
	.align 2, 0
_080412CC: .4byte 0x030047A4
_080412D0:
	movs r4, #0xb2
	lsls r4, r4, #2
	adds r0, r5, r4
	movs r4, #0
	movs r1, #0
	strh r1, [r0]
	adds r0, r5, #0
	movs r1, #8
	movs r2, #0xb4
	movs r3, #0xb4
	bl FUN_080415cc
	strb r4, [r5, #0xa]
_080412EA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
