	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, _0809209C @ =0x00003AEB
	adds r5, r6, r0
	ldrb r0, [r5]
	cmp r0, #0xf
	bhi _080920A4
	ldr r1, _080920A0 @ =0x00003F9C
	adds r4, r6, r1
	ldrb r0, [r4]
	ldrb r1, [r5]
	bl GetItemID
	adds r7, r0, #0
	ldrb r0, [r4]
	cmp r0, #0
	bne _080920A8
	ldrb r0, [r5]
	bl item_08092034
	adds r3, r0, #0
	b _080920AA
	.align 2, 0
_0809209C: .4byte 0x00003AEB
_080920A0: .4byte 0x00003F9C
_080920A4:
	movs r7, #1
	rsbs r7, r7, #0
_080920A8:
	movs r3, #0xcf
_080920AA:
	cmp r7, #0
	bge _080920C8
	ldr r1, _080920C4 @ =0x0000204C
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl TextBox_Close
	bl FUN_08049e5c
	b _080921A0
	.align 2, 0
_080920C4: .4byte 0x0000204C
_080920C8:
	ldr r0, _08092124 @ =0x0000204C
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08092128 @ =0x00002044
	adds r0, r6, r1
	adds r1, r6, #0
	adds r1, #0xa0
	lsls r2, r3, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl MainSprite_SetPose
	movs r0, #1
	bl TextBox_SetInstant
	ldr r0, [r6, #0x40]
	bl TextBox_Start
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl TextBox_SetRect
	adds r0, r7, #0
	bl TextBox_ShowLine
	bl FUN_08049f5c
	ldr r0, [r6, #0x40]
	bl VM_ParseStringRef
	adds r2, r0, #0
	cmp r7, #0x32
	bne _08092130
	ldr r0, _0809212C @ =0x00003FA0
	adds r1, r6, r0
	adds r0, r2, #0
	adds r0, #0xeb
	ldrb r1, [r1]
	adds r0, r0, r1
	b _08092168
	.align 2, 0
_08092124: .4byte 0x0000204C
_08092128: .4byte 0x00002044
_0809212C: .4byte 0x00003FA0
_08092130:
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _0809214E
	cmp r7, #1
	bne _0809214E
	adds r0, r2, #0
	adds r0, #0xea
	b _08092168
_0809214E:
	ldr r0, _08092174 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #5
	bne _08092178
	cmp r7, #0xd
	bne _08092178
	adds r0, r2, #0
	adds r0, #0xa9
_08092168:
	bl Textbox_LookupString
	bl FUN_08049e30
	b _080921A0
	.align 2, 0
_08092174: .4byte 0x030046A0
_08092178:
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08092190
	cmp r0, #5
	bne _08092194
_08092190:
	adds r2, #0x4e
	b _08092196
_08092194:
	adds r2, #0x9c
_08092196:
	adds r0, r2, r7
	bl Textbox_LookupString
	bl FUN_08049e30
_080921A0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
