	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081713DC @ =0x0000046D
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _081713E0
	movs r0, #0
	strb r0, [r2]
	movs r0, #1
	b _081713E2
	.align 2, 0
_081713DC: .4byte 0x0000046D
_081713E0:
	movs r0, #0
_081713E2:
	adds r5, r0, #0
	cmp r5, #0
	beq _0817141A
	movs r2, #1
	ldr r1, _08171400 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08171404
	ldr r1, [r4, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _0817140E
	.align 2, 0
_08171400: .4byte 0x0000025D
_08171404:
	ldr r1, [r4, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_0817140E:
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r4, r1
	bl ParticleShadow_Hide
	b _08171462
_0817141A:
	cmp r1, #0x1a
	ble _0817145C
	adds r0, r4, #0
	movs r1, #9
	bl Enemy_PlayAnim
	ldr r3, _08171450 @ =FUN_0817146c
	movs r2, #0xd
	ldr r0, _08171454 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08171458 @ =0x0000046B
	adds r0, r4, r1
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r4, r1
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r5, [r0]
	b _08171462
	.align 2, 0
_08171450: .4byte FUN_0817146c
_08171454: .4byte 0x0000046D
_08171458: .4byte 0x0000046B
_0817145C:
	ldr r1, _08171468 @ =0x0000046E
	adds r0, r4, r1
	strb r5, [r0]
_08171462:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08171468: .4byte 0x0000046E
