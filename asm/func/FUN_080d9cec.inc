	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	str r1, [sp, #0x28]
	str r2, [sp, #0x2c]
	adds r5, r3, #0
	ldr r1, [sp, #0x74]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	ldr r0, _080D9D20 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080D9D24
	bl Entity080da848_Create
	mov r8, r0
	cmp r0, #0
	bne _080D9D26
_080D9D1C:
	movs r0, #0
	b _080D9F3C
	.align 2, 0
_080D9D20: .4byte 0x0300015C
_080D9D24:
	mov r8, r0
_080D9D26:
	ldr r0, [sp, #0x80]
	cmp r0, #0
	beq _080D9D1C
	mov r0, r8
	bl FUN_080d99c4
	adds r7, r0, #0
	cmp r7, #0
	beq _080D9D1C
	movs r1, #0x2c
	adds r1, r1, r7
	mov sl, r1
	strb r4, [r1]
	adds r0, r7, #0
	adds r0, #0x2d
	movs r4, #1
	strb r4, [r0]
	strh r5, [r7, #0x26]
	adds r5, r7, #0
	adds r5, #0x2f
	ldr r0, [sp, #0x6c]
	strb r0, [r5]
	add r2, sp, #0x68
	ldrh r2, [r2]
	strh r2, [r7, #0x28]
	add r3, sp, #0x68
	ldrh r3, [r3]
	strh r3, [r7, #0x2a]
	mov r6, sb
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r1, #5
	bl Div
	strh r0, [r7, #0x3e]
	adds r1, r7, #0
	adds r1, #0x44
	strb r4, [r1]
	movs r2, #0x98
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r3, [sp, #0x80]
	str r3, [r0]
	ldr r6, [sp, #0x70]
	str r6, [r7, #0x48]
	movs r4, #0
	movs r3, #4
	movs r0, #0
	ldrsh r2, [r6, r0]
	movs r6, #0x3e
	ldrsh r0, [r7, r6]
	lsls r0, r0, #2
	mov r6, sl
	str r5, [sp, #0x38]
	str r1, [sp, #0x40]
	movs r1, #0x3b
	adds r1, r1, r7
	mov sl, r1
	movs r1, #0x3a
	adds r1, r1, r7
	mov sb, r1
	adds r1, r7, #0
	adds r1, #0x5c
	str r1, [sp, #0x44]
	movs r1, #0x98
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x3c]
	movs r1, #0x85
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x34]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x30]
	cmp r2, r0
	blt _080D9DC6
	movs r0, #0
	b _080D9DEA
_080D9DC6:
	subs r3, #1
	cmp r3, #0
	ble _080D9DE4
	ldr r0, [r7, #0x48]
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0x3e
	ldrsh r0, [r7, r2]
	muls r0, r3, r0
	cmp r1, r0
	blt _080D9DC6
	movs r0, #4
	subs r0, r0, r3
	strb r0, [r6]
	movs r4, #1
_080D9DE4:
	cmp r4, #0
	bne _080D9DEC
	movs r0, #3
_080D9DEA:
	strb r0, [r6]
_080D9DEC:
	movs r1, #0
	mov r3, sp
	ldrh r3, [r3, #0x2c]
	strh r3, [r7, #0x24]
	movs r0, #1
	mov r2, sl
	strb r0, [r2]
	mov r3, sb
	strb r0, [r3]
	ldr r0, [sp, #0x28]
	str r0, [r7]
	ldr r0, [sp, #0x7c]
	str r0, [r7, #0x58]
	str r1, [sp, #0x24]
	str r1, [sp, #0x20]
	ldr r5, [sp, #0x44]
	ldrb r0, [r3]
	adds r1, r0, #0
	cmp r0, #1
	beq _080D9E2E
	cmp r0, #1
	bgt _080D9E1E
	cmp r0, #0
	beq _080D9E28
	b _080D9E34
_080D9E1E:
	cmp r1, #5
	bgt _080D9E34
	cmp r1, #4
	blt _080D9E34
	b _080D9E2E
_080D9E28:
	mov r1, r8
	adds r1, #0x18
	b _080D9E36
_080D9E2E:
	mov r1, r8
	adds r1, #0x34
	b _080D9E36
_080D9E34:
	movs r1, #0
_080D9E36:
	adds r0, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	ldr r1, [sp, #0x38]
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _080D9E54
	ldr r2, [sp, #0x3c]
	ldr r0, [r2]
	ldr r1, [r0, #0x34]
	ldr r0, [r0, #0x30]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	b _080D9E7C
_080D9E54:
	mov r3, sl
	ldrb r0, [r3]
	ldr r2, [sp, #0x38]
	ldrb r1, [r2]
	ldr r3, [sp, #0x3c]
	ldr r2, [r3]
	ldrb r2, [r2, #5]
	add r3, sp, #0x20
	add r4, sp, #0x24
	str r4, [sp]
	ldr r4, [r7, #0x58]
	str r4, [sp, #4]
	bl FUN_080d8cc0
	ldr r0, [sp, #0x20]
	movs r1, #0
	strh r0, [r7, #0x1c]
	strh r1, [r7, #0x1e]
	ldr r0, [sp, #0x24]
	strh r0, [r7, #0x20]
_080D9E7C:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	strb r1, [r5, #7]
	movs r0, #0xff
	ldr r1, [sp, #0x34]
	strh r0, [r1]
	mov r2, sb
	ldrb r0, [r2]
	cmp r0, #5
	bhi _080D9EC8
	lsls r0, r0, #2
	ldr r1, _080D9EA0 @ =_080D9EA4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D9EA0: .4byte _080D9EA4
_080D9EA4: @ jump table
	.4byte _080D9EBC @ case 0
	.4byte _080D9EC8 @ case 1
	.4byte _080D9EC2 @ case 2
	.4byte _080D9EC2 @ case 3
	.4byte _080D9EC8 @ case 4
	.4byte _080D9EC8 @ case 5
_080D9EBC:
	mov r3, r8
	ldr r1, [r3, #0x50]
	b _080D9ECA
_080D9EC2:
	mov r0, r8
	ldr r1, [r0, #0x54]
	b _080D9ECA
_080D9EC8:
	movs r1, #0
_080D9ECA:
	ldrb r2, [r6]
	movs r0, #0
	str r0, [sp]
	ldr r0, [sp, #0x30]
	movs r3, #0
	bl FUN_08236fac
	ldr r2, [sp, #0x28]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	ldr r3, [sp, #0x44]
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	movs r0, #1
	ldr r6, [sp, #0x40]
	strb r0, [r6]
	ldr r0, _080D9F4C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080D9F3A
	ldr r0, [sp, #0x78]
	cmp r0, #1
	bne _080D9F3A
	ldr r2, _080D9F50 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080D9F54 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080D9F58 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	add r1, sp, #8
	movs r3, #2
_080D9F1C:
	ldr r0, [r7]
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r0, [r7]
	ldrh r0, [r0, #2]
	ldr r2, [sp, #0x68]
	adds r0, r0, r2
	strh r0, [r1, #2]
	ldr r0, [r7]
	ldrh r0, [r0, #4]
	strh r0, [r1, #4]
	adds r1, #8
	subs r3, #1
	cmp r3, #0
	bge _080D9F1C
_080D9F3A:
	adds r0, r7, #0
_080D9F3C:
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080D9F4C: .4byte 0x030047A4
_080D9F50: .4byte 0x030046B8
_080D9F54: .4byte 0x000003FF
_080D9F58: .4byte 0x0203B400
