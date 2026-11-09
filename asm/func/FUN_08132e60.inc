	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08132E78 @ =0x0000046D
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _08132E7C
	movs r0, #0
	strb r0, [r2]
	movs r0, #1
	b _08132E7E
	.align 2, 0
_08132E78: .4byte 0x0000046D
_08132E7C:
	movs r0, #0
_08132E7E:
	adds r5, r0, #0
	cmp r5, #0
	beq _08132EB6
	movs r2, #1
	ldr r1, _08132E9C @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08132EA0
	ldr r1, [r4, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _08132EAA
	.align 2, 0
_08132E9C: .4byte 0x0000025D
_08132EA0:
	ldr r1, [r4, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_08132EAA:
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r4, r1
	bl ParticleShadow_Hide
	b _08132EFE
_08132EB6:
	cmp r1, #0x1a
	ble _08132EF8
	adds r0, r4, #0
	movs r1, #9
	bl Enemy_PlayAnim
	ldr r3, _08132EEC @ =FUN_08132f08
	movs r2, #0xd
	ldr r0, _08132EF0 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08132EF4 @ =0x0000046B
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
	b _08132EFE
	.align 2, 0
_08132EEC: .4byte FUN_08132f08
_08132EF0: .4byte 0x0000046D
_08132EF4: .4byte 0x0000046B
_08132EF8:
	ldr r1, _08132F04 @ =0x0000046E
	adds r0, r4, r1
	strb r5, [r0]
_08132EFE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08132F04: .4byte 0x0000046E
