	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldrb r1, [r7, #0x1b]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	ldr r1, _08001208 @ =0x03003ED0
	adds r0, r0, r1
	mov r8, r0
	adds r0, r7, #0
	bl Entity08001610_RunCmds
	adds r1, r7, #0
	adds r1, #0x4c
	ldrb r1, [r1]
	cmp r1, #0
	bne _0800120C
	movs r0, #0
	b _08001416
	.align 2, 0
_08001208: .4byte 0x03003ED0
_0800120C:
	adds r4, r7, #0
	adds r4, #0x40
	movs r2, #0
	ldrsh r1, [r4, r2]
	lsls r5, r1, #4
	adds r3, r7, #0
	adds r3, #0x42
	movs r2, #0
	ldrsh r1, [r3, r2]
	lsls r1, r1, #4
	mov ip, r1
	ldrb r2, [r7, #0x1a]
	movs r1, #8
	ands r1, r2
	mov sl, r4
	str r3, [sp]
	cmp r1, #0
	beq _080012DE
	ldr r1, _08001284 @ =0x03002BAC
	ldrh r2, [r1]
	adds r1, r7, #0
	adds r1, #0x4a
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r6, r2, #0
	muls r6, r1, r6
	ldr r1, _08001288 @ =0x03002B90
	ldrh r2, [r1]
	adds r2, #0xa0
	movs r4, #0xff
	ands r2, r4
	ldr r1, _0800128C @ =0x085B0A08
	mov sb, r1
	adds r1, r2, #0
	adds r1, #0x40
	ands r1, r4
	lsls r1, r1, #1
	add r1, sb
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r3, r1, #0
	muls r3, r6, r3
	ldr r1, [r7, #0x30]
	adds r3, r1, r3
	str r3, [r7, #0x30]
	ands r2, r4
	lsls r2, r2, #1
	add r2, sb
	movs r4, #0
	ldrsh r1, [r2, r4]
	adds r2, r1, #0
	muls r2, r6, r2
	ldr r1, [r7, #0x34]
	adds r1, r1, r2
	str r1, [r7, #0x34]
	cmp r3, #0
	blt _08001290
	asrs r1, r3, #0x12
	b _08001296
	.align 2, 0
_08001284: .4byte 0x03002BAC
_08001288: .4byte 0x03002B90
_0800128C: .4byte 0x085B0A08
_08001290:
	rsbs r1, r3, #0
	asrs r1, r1, #0x12
	rsbs r1, r1, #0
_08001296:
	adds r2, r1, #0
	ldr r1, [r7, #0x34]
	cmp r1, #0
	blt _080012A2
	asrs r1, r1, #0x12
	b _080012A8
_080012A2:
	rsbs r1, r1, #0
	asrs r1, r1, #0x12
	rsbs r1, r1, #0
_080012A8:
	adds r3, r1, #0
	cmp r2, r5
	ble _080012B2
	subs r2, r2, r5
	b _080012B8
_080012B2:
	cmn r2, r5
	bge _080012B8
	adds r2, r2, r5
_080012B8:
	cmp r3, ip
	ble _080012C2
	mov r5, ip
	subs r3, r3, r5
	b _080012CA
_080012C2:
	mov r1, ip
	cmn r3, r1
	bge _080012CA
	add r3, ip
_080012CA:
	ldrh r1, [r7, #0x22]
	adds r1, r1, r2
	strh r1, [r7, #0x1e]
	ldrh r2, [r7, #0x24]
	adds r2, r2, r3
	strh r2, [r7, #0x20]
	mov r2, r8
	strh r1, [r2, #0x20]
	ldrh r1, [r7, #0x20]
	b _08001358
_080012DE:
	movs r3, #0x2a
	ldrsh r2, [r7, r3]
	ldr r1, [r7, #0x30]
	adds r1, r1, r2
	str r1, [r7, #0x30]
	cmp r1, r5
	ble _080012F0
	subs r1, r1, r5
	b _080012F6
_080012F0:
	cmn r1, r5
	bge _080012F8
	adds r1, r1, r5
_080012F6:
	str r1, [r7, #0x30]
_080012F8:
	movs r4, #0x2c
	ldrsh r2, [r7, r4]
	ldr r1, [r7, #0x34]
	adds r1, r1, r2
	str r1, [r7, #0x34]
	cmp r1, ip
	ble _0800130C
	mov r5, ip
	subs r1, r1, r5
	b _08001314
_0800130C:
	mov r2, ip
	cmn r1, r2
	bge _08001316
	add r1, ip
_08001314:
	str r1, [r7, #0x34]
_08001316:
	ldr r1, [r7, #0x30]
	ldrh r2, [r7, #0x22]
	adds r1, r1, r2
	strh r1, [r7, #0x1e]
	ldr r1, [r7, #0x34]
	ldrh r2, [r7, #0x24]
	adds r1, r1, r2
	strh r1, [r7, #0x20]
	movs r3, #0x1e
	ldrsh r1, [r7, r3]
	lsls r2, r1, #0x10
	asrs r1, r2, #0x10
	cmp r1, #0
	blt _08001336
	asrs r1, r2, #0x14
	b _0800133C
_08001336:
	rsbs r1, r1, #0
	asrs r1, r1, #4
	rsbs r1, r1, #0
_0800133C:
	mov r4, r8
	strh r1, [r4, #0x20]
	movs r5, #0x20
	ldrsh r1, [r7, r5]
	lsls r2, r1, #0x10
	asrs r1, r2, #0x10
	cmp r1, #0
	blt _08001350
	asrs r1, r2, #0x14
	b _08001356
_08001350:
	rsbs r1, r1, #0
	asrs r1, r1, #4
	rsbs r1, r1, #0
_08001356:
	mov r2, r8
_08001358:
	strh r1, [r2, #0x22]
	ldr r4, _08001390 @ =0x030047C8
	movs r3, #0
	ldrsh r2, [r4, r3]
	ldr r3, _08001394 @ =0x03003540
	movs r5, #8
	ldrsh r1, [r3, r5]
	adds r5, r2, r1
	movs r1, #2
	ldrsh r2, [r4, r1]
	movs r4, #0xa
	ldrsh r1, [r3, r4]
	adds r4, r2, r1
	mov r2, sl
	movs r3, #0
	ldrsh r1, [r2, r3]
	cmp r1, #0
	beq _08001398
	adds r0, r5, #0
	subs r0, #0x78
	bl Mod
	adds r2, r0, #0
	mov r3, r8
	ldrh r1, [r3, #0x20]
	adds r1, r1, r2
	strh r1, [r3, #0x20]
	b _080013A2
	.align 2, 0
_08001390: .4byte 0x030047C8
_08001394: .4byte 0x03003540
_08001398:
	mov r2, r8
	ldrh r1, [r2, #0x20]
	subs r1, #0x78
	adds r1, r1, r5
	strh r1, [r2, #0x20]
_080013A2:
	ldr r3, [sp]
	movs r5, #0
	ldrsh r1, [r3, r5]
	cmp r1, #0
	beq _080013C0
	adds r0, r4, #0
	subs r0, #0x5a
	bl Mod
	adds r2, r0, #0
	mov r3, r8
	ldrh r1, [r3, #0x22]
	adds r1, r1, r2
	strh r1, [r3, #0x22]
	b _080013CA
_080013C0:
	mov r5, r8
	ldrh r1, [r5, #0x22]
	subs r1, #0x5a
	adds r1, r1, r4
	strh r1, [r5, #0x22]
_080013CA:
	adds r4, r7, #0
	adds r4, #0x4e
	ldrh r1, [r4]
	cmp r1, #1
	bne _08001416
	adds r3, r7, #0
	adds r3, #0x52
	adds r0, r7, #0
	adds r0, #0x5e
	ldrh r0, [r0]
	ldrh r1, [r3]
	adds r0, r0, r1
	strh r0, [r3]
	adds r1, r7, #0
	adds r1, #0x54
	adds r0, r7, #0
	adds r0, #0x60
	ldrh r2, [r0]
	ldrh r5, [r1]
	adds r2, r2, r5
	strh r2, [r1]
	ldrb r0, [r7, #0x1b]
	ldrh r1, [r3]
	lsrs r1, r1, #8
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x18
	bl FUN_0822f178
	adds r2, r7, #0
	adds r2, #0x50
	ldrh r1, [r2]
	subs r1, #1
	strh r1, [r2]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0
	bne _08001416
	strh r1, [r4]
_08001416:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
