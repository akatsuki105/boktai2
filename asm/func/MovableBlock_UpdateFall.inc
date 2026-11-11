	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x2c
	adds r3, r4, #0
	adds r3, #0xbc
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	beq _0800413E
	movs r0, #0
	strb r0, [r4, #0x11]
	ldrh r0, [r4, #0x12]
	lsrs r0, r0, #8
	adds r2, r0, #1
	cmp r2, #0xf
	ble _0800411E
	ldrb r0, [r3]
	movs r1, #0xf0
	ands r1, r0
	movs r0, #0xf
	orrs r1, r0
	strb r1, [r3]
	b _08004128
_0800411E:
	ldrb r1, [r3]
	movs r0, #0xf0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
_08004128:
	movs r1, #8
	ldrb r0, [r4, #1]
	ands r0, r1
	cmp r0, #0
	beq _0800413E
	adds r2, r4, #0
	adds r2, #0xbe
	ldrh r1, [r2]
	movs r0, #0x21
	orrs r0, r1
	strh r0, [r2]
_0800413E:
	ldrh r0, [r4, #0x12]
	ldrh r1, [r5, #0xa]
	subs r0, r0, r1
	strh r0, [r5, #0x12]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	movs r0, #0x10
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0800415C
	ldr r0, _08004158 @ =0x0000FFF0
	b _08004162
	.align 2, 0
_08004158: .4byte 0x0000FFF0
_0800415C:
	cmp r1, #0
	ble _08004164
	movs r0, #0
_08004162:
	strh r0, [r5, #0x12]
_08004164:
	movs r0, #0x12
	ldrsh r3, [r5, r0]
	cmp r3, #0
	bne _080041B4
	movs r1, #8
	ldrb r0, [r4, #1]
	ands r0, r1
	cmp r0, #0
	beq _08004186
	adds r2, r4, #0
	adds r2, #0xbe
	ldrh r1, [r2]
	movs r0, #0x21
	orrs r0, r1
	strh r0, [r2]
	strh r3, [r4, #0x16]
	b _08004198
_08004186:
	adds r2, r4, #0
	adds r2, #0xbe
	ldrh r1, [r2]
	ldr r0, _080041BC @ =0x0000FFDE
	ands r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	bl MovableBlock_OnLanded
_08004198:
	ldr r1, _080041C0 @ =MovableBlock_UpdateIdle
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r0, r4, r2
	str r1, [r0]
	movs r2, #0
	movs r1, #0
	strh r1, [r4, #2]
	movs r0, #1
	strb r0, [r4, #0x11]
	strh r1, [r4, #0xc]
	strh r1, [r4, #0xe]
	strb r2, [r4, #0x10]
	strh r1, [r4, #4]
_080041B4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080041BC: .4byte 0x0000FFDE
_080041C0: .4byte MovableBlock_UpdateIdle
