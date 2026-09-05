	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08013e38
FUN_08013e38: @ 0x08013E38
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	mov r8, r1
	adds r7, r2, #0
	bl FUN_08013d10
	adds r5, r0, #0
	cmp r5, #0
	beq _08013EAC
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08013d28
	cmp r0, #0
	bne _08013EAC
	movs r0, #0x54
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _08013EAC
	adds r0, r4, #0
	movs r1, #0x54
	bl ClearMemory
	strh r6, [r4]
	adds r3, r4, #4
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r4, #4]
	str r1, [r4, #8]
	adds r0, r4, #0
	adds r0, #0xc
	movs r2, #0
	mov r1, r8
	cmp r1, #2
	bne _08013E88
	movs r2, #1
_08013E88:
	adds r1, r3, #0
	bl FUN_0801385c
	cmp r0, #0
	blt _08013EA6
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08013d48
	cmp r0, #0
	blt _08013EA6
	mov r0, r8
	strb r0, [r4, #2]
	movs r0, #0
	b _08013EB0
_08013EA6:
	adds r0, r4, #0
	bl Free
_08013EAC:
	movs r0, #1
	rsbs r0, r0, #0
_08013EB0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08013ebc
FUN_08013ebc: @ 0x08013EBC
	push {r4, r5, r6, lr}
	sub sp, #8
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x6d
	movs r1, #1
	bl VM_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	bne _08013EE4
	movs r0, #1
	rsbs r0, r0, #0
	b _08013F20
_08013EE4:
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08013F28 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08013F2C @ =0x0000FFFF
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	adds r0, r6, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08013e38
_08013F20:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08013F28: .4byte 0xFFFF0000
_08013F2C: .4byte 0x0000FFFF

	thumb_func_start FUN_08013f30
FUN_08013f30: @ 0x08013F30
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_08013d10
	adds r5, r0, #0
	cmp r5, #0
	beq _08013F64
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08013d28
	adds r4, r0, #0
	cmp r4, #0
	beq _08013F64
	adds r0, #0xc
	bl FUN_080138fc
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08013d70
	adds r0, r4, #0
	bl Free
	movs r0, #0
	b _08013F68
_08013F64:
	movs r0, #1
	rsbs r0, r0, #0
_08013F68:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08013f70
FUN_08013f70: @ 0x08013F70
	push {lr}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	bl FUN_08013f30
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08013f84
FUN_08013f84: @ 0x08013F84
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl FUN_08013d10
	cmp r0, #0
	beq _08013F9E
	adds r1, r4, #0
	bl FUN_08013d28
	adds r2, r0, #0
	cmp r2, #0
	bne _08013FA4
_08013F9E:
	movs r0, #1
	rsbs r0, r0, #0
	b _08013FC6
_08013FA4:
	strb r5, [r2, #2]
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08013FB8
	adds r0, r2, #0
	adds r0, #0xc
	bl FUN_08013698
	b _08013FC4
_08013FB8:
	cmp r0, #2
	bne _08013FC4
	adds r0, r2, #0
	adds r0, #0xc
	bl FUN_080136b4
_08013FC4:
	movs r0, #0
_08013FC6:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08013fcc
FUN_08013fcc: @ 0x08013FCC
	push {r4, lr}
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x6d
	movs r1, #1
	bl VM_GetKeywordValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08013f84
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08013ff0
FUN_08013ff0: @ 0x08013FF0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl FUN_08013d10
	cmp r0, #0
	beq _08014016
	adds r1, r4, #0
	bl FUN_08013d28
	adds r2, r0, #0
	cmp r2, #0
	beq _08014016
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r2, #4]
	str r1, [r2, #8]
	movs r0, #0
	b _0801401A
_08014016:
	movs r0, #1
	rsbs r0, r0, #0
_0801401A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08014020
FUN_08014020: @ 0x08014020
	push {r4, r5, lr}
	sub sp, #8
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	bne _0801403E
	movs r0, #1
	rsbs r0, r0, #0
	b _08014078
_0801403E:
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08014080 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08014084 @ =0x0000FFFF
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	adds r0, r5, #0
	mov r1, sp
	bl FUN_08013ff0
_08014078:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08014080: .4byte 0xFFFF0000
_08014084: .4byte 0x0000FFFF
_08014088:
	.byte 0x01, 0x49, 0x00, 0x20, 0x08, 0x60, 0x70, 0x47
	.byte 0x58, 0x00, 0x00, 0x03

	thumb_func_start FUN_08014094
FUN_08014094: @ 0x08014094
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r3, r0, #0
	adds r5, r1, #0
	movs r0, #0
	mov sb, r0
	mov r8, r0
	ldrb r1, [r5, #1]
	cmp sb, r1
	bge _08014132
	adds r4, r5, #4
	adds r6, r5, #0
	adds r6, #0x14
_080140B4:
	ldrb r0, [r4]
	cmp r0, #0
	beq _08014124
	ldrb r0, [r5, #2]
	cmp r0, #0x14
	bhi _080140C4
	ldr r2, [r3, #0x1c]
	b _080140C6
_080140C4:
	ldr r2, [r3, #0x20]
_080140C6:
	ldrh r0, [r4, #8]
	ldrh r7, [r4, #0x28]
	adds r0, r0, r7
	movs r1, #0
	mov ip, r1
	strh r0, [r4, #0x28]
	ldrh r0, [r4, #0xc]
	ldrh r7, [r4, #0x2c]
	adds r0, r0, r7
	strh r0, [r4, #0x2c]
	ldrh r0, [r4, #0xa]
	ldrh r7, [r4, #6]
	adds r1, r0, r7
	strh r1, [r4, #6]
	subs r0, #1
	strh r0, [r4, #0xa]
	strh r1, [r4, #0x2a]
	ldr r1, _0801411C @ =0x085AA850
	ldrb r0, [r5, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldrh r0, [r2, #4]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrb r0, [r5, #3]
	strb r0, [r4, #0x1f]
	ldrb r0, [r4, #2]
	adds r1, r0, #1
	strb r1, [r4, #2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r4, #3]
	cmp r0, r1
	blo _08014120
	mov r7, ip
	strb r7, [r4]
	adds r0, r6, #0
	str r3, [sp]
	bl FUN_0822dabc
	ldr r3, [sp]
	b _08014124
	.align 2, 0
_0801411C: .4byte 0x085AA850
_08014120:
	movs r0, #1
	add sb, r0
_08014124:
	adds r4, #0x38
	adds r6, #0x38
	movs r1, #1
	add r8, r1
	ldrb r7, [r5, #1]
	cmp r8, r7
	blt _080140B4
_08014132:
	mov r0, sb
	cmp r0, #0
	bne _0801413A
	strb r0, [r5]
_0801413A:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08014148
FUN_08014148: @ 0x08014148
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r0, [sp]
	adds r7, r1, #0
	ldr r0, _080141B0 @ =0x085AA850
	adds r0, #0x9c
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #8]
	movs r1, #0
	str r1, [sp, #4]
	ldrb r2, [r7, #1]
	cmp r0, r2
	blt _08014170
	b _08014412
_08014170:
	ldr r0, _080141B4 @ =0x030046B8
	mov r8, r0
	adds r4, r7, #4
	movs r1, #0x14
	adds r1, r1, r7
	mov sb, r1
	ldr r2, _080141B8 @ =0xFFFFFF00
	mov sl, r2
_08014180:
	ldrb r0, [r4]
	cmp r0, #0
	bne _08014188
	b _080143FE
_08014188:
	ldrh r0, [r4, #0x28]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #0x2c]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080141AC
	cmp r1, #0
	blt _080141AC
	ldr r0, _080141BC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080141AC
	ldr r0, _080141C0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080141C8
_080141AC:
	ldr r0, _080141C4 @ =0x0000FFFF
	b _080141D6
	.align 2, 0
_080141B0: .4byte 0x085AA850
_080141B4: .4byte 0x030046B8
_080141B8: .4byte 0xFFFFFF00
_080141BC: .4byte 0x030046A8
_080141C0: .4byte 0x030046AC
_080141C4: .4byte 0x0000FFFF
_080141C8:
	ldr r0, _080141E8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080141D6:
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldrb r0, [r7, #2]
	cmp r0, #0x14
	bhi _080141EC
	ldr r0, [sp]
	ldr r3, [r0, #0x1c]
	b _080141F0
	.align 2, 0
_080141E8: .4byte 0x030046A4
_080141EC:
	ldr r1, [sp]
	ldr r3, [r1, #0x20]
_080141F0:
	ldrh r0, [r4, #8]
	ldrh r2, [r4, #0x28]
	adds r0, r0, r2
	strh r0, [r4, #0x28]
	ldrh r0, [r4, #0xc]
	ldrh r1, [r4, #0x2c]
	adds r0, r0, r1
	strh r0, [r4, #0x2c]
	ldrh r1, [r4, #0xa]
	ldrh r2, [r4, #6]
	adds r0, r1, r2
	strh r0, [r4, #6]
	subs r1, #1
	strh r1, [r4, #0xa]
	ldr r0, _08014228 @ =0x0000FFFF
	cmp r5, r0
	bne _08014214
	b _08014390
_08014214:
	adds r0, r5, #0
	movs r1, #1
	str r3, [sp, #0x10]
	bl FUN_08234224
	ldr r3, [sp, #0x10]
	cmp r0, #0
	beq _0801422C
	adds r0, #4
	b _08014238
	.align 2, 0
_08014228: .4byte 0x0000FFFF
_0801422C:
	ldr r0, _0801428C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08014238:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r6, r1, #8
	movs r1, #6
	ldrsh r0, [r4, r1]
	cmp r0, r6
	blt _0801424A
	b _08014366
_0801424A:
	ldrh r2, [r4, #4]
	cmp r5, r2
	beq _08014326
	ldrh r0, [r4, #4]
	subs r0, r5, r0
	cmp r0, #0
	bge _0801425A
	rsbs r0, r0, #0
_0801425A:
	cmp r0, #1
	bne _080142C6
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _08014290 @ =0x000003FF
	ands r0, r1
	mov r2, r8
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08014294 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #8
	ldrsh r2, [r4, r0]
	movs r0, #7
	ands r1, r0
	adds r1, #0x32
	adds r0, r2, #0
	muls r0, r1, r0
	cmp r0, #0
	blt _08014298
	asrs r0, r0, #6
	b _0801429E
	.align 2, 0
_0801428C: .4byte 0x030046A4
_08014290: .4byte 0x000003FF
_08014294: .4byte 0x0203B400
_08014298:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0801429E:
	rsbs r0, r0, #0
	strh r0, [r4, #8]
	ldrh r0, [r4, #4]
	subs r0, r5, r0
	cmp r0, #0
	bge _080142BA
	ldrh r0, [r4, #0x28]
	mov r1, sl
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r0, r2
	strh r0, [r4, #0x28]
	b _08014328
_080142BA:
	ldrh r0, [r4, #0x28]
	mov r1, sl
	ands r0, r1
	subs r0, #1
	strh r0, [r4, #0x28]
	b _08014328
_080142C6:
	mov r2, r8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080142F0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080142F4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xc
	ldrsh r2, [r4, r0]
	movs r0, #7
	ands r1, r0
	adds r1, #0x32
	adds r0, r2, #0
	muls r0, r1, r0
	cmp r0, #0
	blt _080142F8
	asrs r0, r0, #6
	b _080142FE
	.align 2, 0
_080142F0: .4byte 0x000003FF
_080142F4: .4byte 0x0203B400
_080142F8:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_080142FE:
	rsbs r0, r0, #0
	strh r0, [r4, #0xc]
	ldrh r0, [r4, #4]
	subs r0, r5, r0
	cmp r0, #0
	bge _0801431A
	ldrh r0, [r4, #0x2c]
	mov r1, sl
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r0, r2
	strh r0, [r4, #0x2c]
	b _08014328
_0801431A:
	ldrh r0, [r4, #0x2c]
	mov r1, sl
	ands r0, r1
	subs r0, #1
	strh r0, [r4, #0x2c]
	b _08014328
_08014326:
	strh r6, [r4, #6]
_08014328:
	mov r2, r8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08014354 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08014358 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xa
	ldrsh r2, [r4, r0]
	movs r0, #3
	ands r1, r0
	adds r1, #0x37
	adds r0, r2, #0
	muls r0, r1, r0
	cmp r0, #0
	blt _0801435C
	asrs r0, r0, #6
	b _08014362
	.align 2, 0
_08014354: .4byte 0x000003FF
_08014358: .4byte 0x0203B400
_0801435C:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08014362:
	rsbs r0, r0, #0
	strh r0, [r4, #0xa]
_08014366:
	adds r0, r5, #0
	movs r1, #1
	str r3, [sp, #0x10]
	bl FUN_08234224
	ldr r3, [sp, #0x10]
	cmp r0, #0
	beq _0801437A
	adds r0, #4
	b _08014386
_0801437A:
	ldr r0, _080143B8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08014386:
	ldrh r0, [r0, #2]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08014392
_08014390:
	ldr r6, _080143BC @ =0x0000FFFF
_08014392:
	strh r5, [r4, #4]
	ldr r1, [sp]
	ldr r0, [r1, #0x18]
	movs r2, #1
	ands r0, r2
	ldr r1, [sp, #4]
	ands r1, r2
	cmp r0, r1
	bne _080143C0
	ldr r0, _080143BC @ =0x0000FFFF
	cmp r6, r0
	beq _080143C0
	strh r6, [r4, #0x2a]
	ldrh r0, [r3, #4]
	ldr r2, [sp, #0xc]
	adds r0, r0, r2
	strh r0, [r4, #0x18]
	movs r0, #3
	b _080143D6
	.align 2, 0
_080143B8: .4byte 0x030046A4
_080143BC: .4byte 0x0000FFFF
_080143C0:
	ldrh r0, [r4, #6]
	strh r0, [r4, #0x2a]
	ldr r1, _080143F4 @ =0x085AA850
	ldrb r0, [r7, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldrh r0, [r3, #4]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrb r0, [r7, #3]
_080143D6:
	strb r0, [r4, #0x1f]
	ldrb r0, [r4, #2]
	adds r1, r0, #1
	strb r1, [r4, #2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r4, #3]
	cmp r0, r1
	blo _080143F8
	movs r0, #0
	strb r0, [r4]
	mov r0, sb
	bl FUN_0822dabc
	b _080143FE
	.align 2, 0
_080143F4: .4byte 0x085AA850
_080143F8:
	ldr r2, [sp, #8]
	adds r2, #1
	str r2, [sp, #8]
_080143FE:
	adds r4, #0x38
	movs r0, #0x38
	add sb, r0
	ldr r1, [sp, #4]
	adds r1, #1
	str r1, [sp, #4]
	ldrb r2, [r7, #1]
	cmp r1, r2
	bge _08014412
	b _08014180
_08014412:
	ldr r0, [sp, #8]
	cmp r0, #0
	bne _0801441A
	strb r0, [r7]
_0801441A:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801442c
FUN_0801442c: @ 0x0801442C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	adds r6, r1, #0
	ldrb r0, [r6, #2]
	cmp r0, #8
	bhi _0801444C
	ldr r0, _08014448 @ =0x085AA850
	adds r0, #0x9c
	b _08014454
	.align 2, 0
_08014448: .4byte 0x085AA850
_0801444C:
	ldr r1, _0801446C @ =0x085AA850
	ldrb r0, [r6, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
_08014454:
	ldr r0, [r0]
	mov sb, r0
	adds r5, r6, #4
	movs r0, #7
	mov sl, r0
_0801445E:
	ldrb r0, [r6, #2]
	adds r3, r0, #0
	cmp r3, #0x14
	bhi _08014470
	mov r1, r8
	ldr r7, [r1, #0x1c]
	b _08014474
	.align 2, 0
_0801446C: .4byte 0x085AA850
_08014470:
	mov r0, r8
	ldr r7, [r0, #0x20]
_08014474:
	ldr r0, [r5, #0x10]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08014480
	b _08014570
_08014480:
	ldrh r0, [r5, #0x28]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080144A4
	cmp r1, #0
	blt _080144A4
	ldr r0, _080144A8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080144A4
	ldr r0, _080144AC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080144B4
_080144A4:
	ldr r0, _080144B0 @ =0x0000FFFF
	b _080144C2
	.align 2, 0
_080144A8: .4byte 0x030046A8
_080144AC: .4byte 0x030046AC
_080144B0: .4byte 0x0000FFFF
_080144B4:
	ldr r0, _080144DC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080144C2:
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, _080144E0 @ =0x0000FFFF
	cmp r4, r0
	beq _08014534
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080144E4
	adds r0, #4
	b _080144F0
	.align 2, 0
_080144DC: .4byte 0x030046A4
_080144E0: .4byte 0x0000FFFF
_080144E4:
	ldr r0, _08014500 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080144F0:
	ldrh r0, [r0, #2]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08014508
	ldr r2, _08014504 @ =0x0000FFFF
	ldrb r3, [r6, #2]
	b _08014536
	.align 2, 0
_08014500: .4byte 0x030046A4
_08014504: .4byte 0x0000FFFF
_08014508:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08014518
	adds r0, #4
	b _08014524
_08014518:
	ldr r0, _08014530 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08014524:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	ldrb r3, [r6, #2]
	b _08014536
	.align 2, 0
_08014530: .4byte 0x030046A4
_08014534:
	adds r2, r4, #0
_08014536:
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bhi _0801455C
	mov r1, r8
	ldr r0, [r1, #0x18]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0801455C
	ldr r0, _08014558 @ =0x0000FFFF
	cmp r2, r0
	beq _0801455C
	strh r2, [r5, #0x2a]
	ldrh r0, [r7, #4]
	add r0, sb
	b _0801456E
	.align 2, 0
_08014558: .4byte 0x0000FFFF
_0801455C:
	ldrh r0, [r5, #6]
	strh r0, [r5, #0x2a]
	ldrb r0, [r6, #2]
	lsls r0, r0, #2
	ldr r1, _08014590 @ =0x085AA850
	adds r0, r0, r1
	ldr r1, [r0]
	ldrh r0, [r7, #4]
	adds r0, r0, r1
_0801456E:
	strh r0, [r5, #0x18]
_08014570:
	adds r5, #0x38
	movs r0, #1
	rsbs r0, r0, #0
	add sl, r0
	mov r1, sl
	cmp r1, #0
	blt _08014580
	b _0801445E
_08014580:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08014590: .4byte 0x085AA850

	thumb_func_start Entity080146e0_Update
Entity080146e0_Update: @ 0x08014594
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080145C4 @ =0x030044BC
	ldr r0, [r0]
	cmp r0, #0
	beq _080145C8
	adds r4, r5, #0
	adds r4, #0x24
	movs r6, #5
_080145A6:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080145B4
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0801442c
_080145B4:
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r4, r4, r0
	subs r6, #1
	cmp r6, #0
	bge _080145A6
	b _080145F8
	.align 2, 0
_080145C4: .4byte 0x030044BC
_080145C8:
	adds r4, r5, #0
	adds r4, #0x24
	movs r6, #5
_080145CE:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080145EC
	ldrb r0, [r4, #2]
	cmp r0, #8
	bhi _080145E4
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08014148
	b _080145EC
_080145E4:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08014094
_080145EC:
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r4, r4, r0
	subs r6, #1
	cmp r6, #0
	bge _080145CE
_080145F8:
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity080146e0_Destroy
Entity080146e0_Destroy: @ 0x08014608
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r2, #0
_08014612:
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #4
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, #0x24
	mov r3, r8
	adds r1, r3, r0
	ldrb r0, [r1]
	adds r7, r2, #1
	cmp r0, #0
	beq _08014648
	adds r5, r1, #0
	adds r5, #0x14
	adds r4, r1, #4
	movs r6, #7
_08014632:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801463E
	adds r0, r5, #0
	bl FUN_0822dabc
_0801463E:
	adds r5, #0x38
	adds r4, #0x38
	subs r6, #1
	cmp r6, #0
	bge _08014632
_08014648:
	adds r2, r7, #0
	cmp r2, #5
	ble _08014612
	movs r1, #0
	ldr r0, _08014660 @ =0x03000058
	str r1, [r0]
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08014660: .4byte 0x03000058

	thumb_func_start Entity080146e0_Init
Entity080146e0_Init: @ 0x08014664
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r0, _080146D4 @ =0x03000058
	str r6, [r0]
	ldr r0, _080146D8 @ =0x00001C1C
	bl GetParticleGroup
	str r0, [r6, #0x1c]
	ldr r0, _080146DC @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x20]
	movs r3, #0
	movs r0, #4
	rsbs r0, r0, #0
	mov r8, r0
_08014688:
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #4
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r1, r6, r0
	adds r1, #0x24
	movs r2, #0
	strb r2, [r1]
	adds r7, r3, #1
	adds r0, #0x38
	adds r4, r6, r0
	movs r5, #7
_080146A2:
	ldr r1, [r6, #0x1c]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822da70
	adds r0, r4, #0
	mov r1, r8
	mov r2, r8
	bl FUN_0822dad4
	adds r4, #0x38
	subs r5, #1
	cmp r5, #0
	bge _080146A2
	adds r3, r7, #0
	cmp r3, #5
	ble _08014688
	movs r0, #0
	str r0, [r6, #0x18]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080146D4: .4byte 0x03000058
_080146D8: .4byte 0x00001C1C
_080146DC: .4byte 0x00001C1E

	thumb_func_start Entity080146e0_Create
Entity080146e0_Create: @ 0x080146E0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08014718 @ =0x03000058
	ldr r0, [r0]
	cmp r0, #0
	bne _0801472A
	ldr r1, _0801471C @ =0x00000ABC
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08014728
	ldr r1, _08014720 @ =Entity080146e0_Update
	ldr r2, _08014724 @ =Entity080146e0_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity080146e0_Init
	cmp r0, #0
	bge _08014728
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801472A
	.align 2, 0
_08014718: .4byte 0x03000058
_0801471C: .4byte 0x00000ABC
_08014720: .4byte Entity080146e0_Update
_08014724: .4byte Entity080146e0_Destroy
_08014728:
	adds r0, r4, #0
_0801472A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08014730
FUN_08014730: @ 0x08014730
  .include "asm/func/FUN_08014730.inc"

	thumb_func_start FUN_080149dc
FUN_080149dc: @ 0x080149DC
  .include "asm/func/FUN_080149dc.inc"

