	push {r4, r5, lr}
	sub sp, #0x30
	adds r3, r0, #0
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r1, r3, r0
	ldrb r0, [r1]
	str r0, [sp]
	ldrb r0, [r1, #1]
	str r0, [sp, #4]
	ldrb r0, [r1, #2]
	str r0, [sp, #8]
	ldrb r0, [r1, #3]
	str r0, [sp, #0xc]
	movs r2, #8
	ldrsh r0, [r1, r2]
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	ldr r5, [sp, #0x28]
	add r4, sp, #0x28
	ldr r0, _0801C070 @ =0x00000A98
	adds r1, r3, r0
	movs r2, #2
_0801C04C:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801C058
	ldr r0, [sp, #0x14]
	adds r0, #1
	str r0, [sp, #0x14]
_0801C058:
	adds r1, #4
	subs r2, #1
	cmp r2, #0
	bge _0801C04C
	adds r0, r3, #0
	adds r0, #0xa8
	ldr r0, [r0]
	cmp r0, #0x63
	ble _0801C074
	movs r0, #0x63
	b _0801C07A
	.align 2, 0
_0801C070: .4byte 0x00000A98
_0801C074:
	cmp r0, #0
	bge _0801C07A
	movs r0, #0
_0801C07A:
	str r0, [sp, #0x18]
	adds r0, r3, #0
	adds r0, #0xac
	ldr r0, [r0]
	cmp r0, #0x63
	ble _0801C08A
	movs r0, #0x63
	b _0801C090
_0801C08A:
	cmp r0, #0
	bge _0801C090
	movs r0, #0
_0801C090:
	str r0, [sp, #0x1c]
	adds r0, r3, #0
	adds r0, #0xb0
	ldr r0, [r0]
	cmp r0, #0x63
	ble _0801C0A0
	movs r0, #0x63
	b _0801C0A6
_0801C0A0:
	cmp r0, #0
	bge _0801C0A6
	movs r0, #0
_0801C0A6:
	str r0, [sp, #0x20]
	adds r0, r3, #0
	adds r0, #0x98
	ldr r0, [r0]
	str r0, [sp, #0x24]
	ldr r0, _0801C0D4 @ =0xFFFF0000
	ands r0, r5
	movs r1, #0xa
	orrs r0, r1
	str r0, [sp, #0x28]
	mov r2, sp
	str r2, [r4, #4]
	adds r0, r3, #0
	adds r0, #0xba
	ldrh r0, [r0]
	adds r1, r4, #0
	bl VM_ExecByID
	add sp, #0x30
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801C0D4: .4byte 0xFFFF0000
