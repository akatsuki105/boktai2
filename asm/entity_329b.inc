	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0800fc90
FUN_0800fc90: @ 0x0800FC90
	ldr r1, _0800FC98 @ =0x03000048
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0800FC98: .4byte 0x03000048

	thumb_func_start FUN_0800fc9c
FUN_0800fc9c: @ 0x0800FC9C
	push {r4, lr}
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #4
	ldr r0, _0800FCC0 @ =0x03003ED0
	adds r3, r3, r0
	ldr r0, [r3, #0x2c]
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r4, #0x18
	ldrsh r1, [r3, r4]
	lsls r1, r1, #1
	muls r1, r2, r1
	lsls r1, r1, #1
	adds r0, r0, r1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0800FCC0: .4byte 0x03003ED0

	thumb_func_start FUN_0800fcc4
FUN_0800fcc4: @ 0x0800FCC4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov sb, r2
	movs r2, #0
	cmp r1, #9
	ble _0800FCD8
	movs r2, #1
_0800FCD8:
	str r2, [sp]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #1
	subs r0, r1, r0
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #6
	movs r2, #0xb
	bl FUN_0800fc9c
	adds r4, r0, #0
	movs r3, #0
	mov ip, sp
	ldr r0, _0800FD90 @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _0800FD94 @ =0x03003ED0
	mov r8, r1
_0800FCFC:
	lsls r5, r3, #4
	mov r6, ip
	adds r1, r4, #0
	movs r2, #1
_0800FD04:
	ldm r6!, {r0}
	adds r0, #0x20
	adds r0, r5, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0800FD04
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r4, r4, r0
	adds r3, #1
	cmp r3, #1
	ble _0800FCFC
	mov r0, sb
	movs r1, #0xa
	bl Div
	str r0, [sp]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	mov r2, sb
	subs r1, r2, r1
	str r1, [sp, #4]
	movs r0, #0
	movs r1, #0xa
	movs r2, #0xb
	bl FUN_0800fc9c
	adds r4, r0, #0
	movs r3, #0
	mov ip, sp
	ldr r0, _0800FD90 @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _0800FD94 @ =0x03003ED0
	mov r8, r1
_0800FD54:
	adds r6, r3, #1
	lsls r3, r3, #4
	mov r5, ip
	adds r1, r4, #0
	movs r2, #1
_0800FD5E:
	ldm r5!, {r0}
	adds r0, #0x20
	adds r0, r3, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0800FD5E
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r4, r4, r0
	adds r3, r6, #0
	cmp r3, #1
	ble _0800FD54
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800FD90: .4byte 0xFFFFD000
_0800FD94: .4byte 0x03003ED0

	thumb_func_start FUN_0800fd98
FUN_0800fd98: @ 0x0800FD98
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	bl GetHour
	adds r4, r0, #0
	bl GetMinute
	mov sb, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [sp]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	str r4, [sp, #4]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0xb
	bl FUN_0800fc9c
	adds r4, r0, #0
	movs r3, #0
	mov ip, sp
	ldr r0, _0800FE6C @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _0800FE70 @ =0x03003ED0
	mov r8, r1
_0800FDDA:
	lsls r5, r3, #4
	mov r6, ip
	adds r1, r4, #0
	movs r2, #1
_0800FDE2:
	ldm r6!, {r0}
	adds r0, #0x20
	adds r0, r5, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0800FDE2
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r4, r4, r0
	adds r3, #1
	cmp r3, #1
	ble _0800FDDA
	mov r0, sb
	movs r1, #0xa
	bl Div
	str r0, [sp]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	mov r2, sb
	subs r1, r2, r1
	str r1, [sp, #4]
	movs r0, #0
	movs r1, #0x14
	movs r2, #0xb
	bl FUN_0800fc9c
	adds r4, r0, #0
	movs r3, #0
	mov ip, sp
	ldr r0, _0800FE6C @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _0800FE70 @ =0x03003ED0
	mov r8, r1
_0800FE32:
	adds r6, r3, #1
	lsls r3, r3, #4
	mov r5, ip
	adds r1, r4, #0
	movs r2, #1
_0800FE3C:
	ldm r5!, {r0}
	adds r0, #0x20
	adds r0, r3, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0800FE3C
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r4, r4, r0
	adds r3, r6, #0
	cmp r3, #1
	ble _0800FE32
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800FE6C: .4byte 0xFFFFD000
_0800FE70: .4byte 0x03003ED0

	thumb_func_start FUN_0800fe74
FUN_0800fe74: @ 0x0800FE74
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r0, _0800FEB0 @ =gClock
	cmp r0, #0
	bne _0800FE88
	b _0801001E
_0800FE88:
	ldrb r0, [r0, #0xe]
	cmp r0, #0
	beq _0800FE96
	cmp r0, #4
	beq _0800FE96
	cmp r0, #5
	bne _0800FEB4
_0800FE96:
	movs r0, #0
	movs r1, #4
	movs r2, #0xf
	bl FUN_0800fc9c
	adds r5, r0, #0
	ldr r1, _0800FEB0 @ =gClock
	ldrb r1, [r1, #0x12]
	mov r8, r1
	ldr r2, _0800FEB0 @ =gClock
	ldrb r2, [r2, #0x13]
	mov sl, r2
	b _0800FECC
	.align 2, 0
_0800FEB0: .4byte gClock
_0800FEB4:
	movs r0, #0
	movs r1, #4
	movs r2, #0xf
	bl FUN_0800fc9c
	adds r5, r0, #0
	ldr r7, _0800FF24 @ =gClock
	ldrb r7, [r7, #0x10]
	mov r8, r7
	ldr r0, _0800FF24 @ =gClock
	ldrb r0, [r0, #0x11]
	mov sl, r0
_0800FECC:
	movs r4, #0
	ldr r1, _0800FF28 @ =0xFFFFD000
	mov ip, r1
	movs r6, #0x6a
	ldr r2, _0800FF2C @ =0x03003ED0
	mov sb, r2
_0800FED8:
	movs r2, #0
	adds r3, r6, #0
	adds r1, r5, #0
_0800FEDE:
	adds r0, r3, r2
	mov r7, ip
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, #3
	ble _0800FEDE
	mov r1, sb
	movs r2, #0x18
	ldrsh r0, [r1, r2]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r6, #0x10
	adds r4, #1
	cmp r4, #1
	ble _0800FED8
	movs r0, #0
	movs r1, #8
	movs r2, #0xf
	bl FUN_0800fc9c
	adds r5, r0, #0
	ldr r7, _0800FF24 @ =gClock
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _0800FF1C
	cmp r0, #4
	beq _0800FF1C
	cmp r0, #5
	bne _0800FF30
_0800FF1C:
	movs r0, #2
	mov ip, r0
	movs r0, #0x6e
	b _0800FF36
	.align 2, 0
_0800FF24: .4byte gClock
_0800FF28: .4byte 0xFFFFD000
_0800FF2C: .4byte 0x03003ED0
_0800FF30:
	movs r1, #2
	mov ip, r1
	movs r0, #0x4e
_0800FF36:
	movs r4, #0
	ldr r2, _08010030 @ =0x03003ED0
	mov sb, r2
	adds r6, r0, #0
_0800FF3E:
	movs r2, #0
	cmp r2, ip
	bge _0800FF5A
	adds r3, r6, #0
	ldr r0, _08010034 @ =0xFFFFD000
	adds r7, r0, #0
	adds r1, r5, #0
_0800FF4C:
	adds r0, r3, r2
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, ip
	blt _0800FF4C
_0800FF5A:
	mov r1, sb
	movs r2, #0x18
	ldrsh r0, [r1, r2]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r6, #0x10
	adds r4, #1
	cmp r4, #1
	ble _0800FF3E
	mov r0, r8
	movs r1, #0xa
	bl Div
	str r0, [sp]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	mov r7, r8
	subs r1, r7, r1
	str r1, [sp, #4]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0xf
	bl FUN_0800fc9c
	adds r5, r0, #0
	movs r4, #0
	mov ip, sp
	ldr r0, _08010034 @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _08010030 @ =0x03003ED0
	mov r8, r1
_0800FF9A:
	lsls r3, r4, #4
	mov r6, ip
	adds r1, r5, #0
	movs r2, #1
_0800FFA2:
	ldm r6!, {r0}
	adds r0, #0x60
	adds r0, r3, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0800FFA2
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #1
	ble _0800FF9A
	mov r0, sl
	movs r1, #0xa
	bl Div
	str r0, [sp]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	mov r2, sl
	subs r1, r2, r1
	str r1, [sp, #4]
	movs r0, #0
	movs r1, #0x16
	movs r2, #0xf
	bl FUN_0800fc9c
	adds r5, r0, #0
	movs r4, #0
	mov ip, sp
	ldr r0, _08010034 @ =0xFFFFD000
	adds r7, r0, #0
	ldr r1, _08010030 @ =0x03003ED0
	mov r8, r1
_0800FFF2:
	adds r6, r4, #1
	lsls r3, r4, #4
	mov r4, ip
	adds r1, r5, #0
	movs r2, #1
_0800FFFC:
	ldm r4!, {r0}
	adds r0, #0x60
	adds r0, r3, r0
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0800FFFC
	mov r2, r8
	movs r1, #0x18
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r5, r5, r0
	adds r4, r6, #0
	cmp r4, #1
	ble _0800FFF2
_0801001E:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010030: .4byte 0x03003ED0
_08010034: .4byte 0xFFFFD000

	thumb_func_start FUN_08010038
FUN_08010038: @ 0x08010038
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	add r4, sp, #4
	add r5, sp, #8
	bl GetDate
	adds r3, r0, #0
	mov r0, sp
	adds r1, r4, #0
	adds r2, r5, #0
	bl ParseBCDDate
	ldrh r1, [r6, #0x28]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08010066
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	adds r0, r6, #0
	bl FUN_0800fcc4
_08010066:
	ldrh r1, [r6, #0x28]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08010076
	adds r0, r6, #0
	bl FUN_0800fd98
_08010076:
	ldrh r1, [r6, #0x28]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08010086
	adds r0, r6, #0
	bl FUN_0800fe74
_08010086:
	movs r0, #0
	strh r0, [r6, #0x28]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08010094
FUN_08010094: @ 0x08010094
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _080100DC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080100AE
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080100E8
_080100AE:
	movs r0, #4
	str r0, [sp]
	ldr r0, _080100E0 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080100E4 @ =FUN_080104c8
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r0, r5, r1
	strh r4, [r0]
	movs r0, #1
	b _080100EA
	.align 2, 0
_080100DC: .4byte 0x030044E0
_080100E0: .4byte 0x0000FFFF
_080100E4: .4byte FUN_080104c8
_080100E8:
	movs r0, #0
_080100EA:
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080100f4
FUN_080100f4: @ 0x080100F4
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r5, r4, r0
	ldrh r2, [r5]
	cmp r2, #0
	bne _08010138
	subs r0, #0x16
	adds r1, r4, r0
	movs r0, #0xc
	strh r0, [r1]
	movs r0, #0xb1
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0x10
	strh r0, [r1]
	ldr r0, _08010180 @ =0x000002C6
	adds r1, r4, r0
	ldr r0, _08010184 @ =0x00001084
	strh r0, [r1]
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r2, [r0]
	ldr r2, _08010188 @ =0x000002CA
	adds r1, r4, r2
	movs r0, #2
	strh r0, [r1]
	movs r0, #0xb4
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, _0801018C @ =FUN_08010718
	str r0, [r1]
_08010138:
	movs r2, #0xb0
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r0, [r5]
	ldrh r1, [r1]
	cmp r0, r1
	bne _08010166
	movs r1, #0xc1
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	adds r2, #0x1c
	adds r1, r4, r2
	bl Script_ExecById
	adds r0, r4, #0
	bl KillEntity
	ldr r2, _08010190 @ =0x03003E78
	ldr r0, _08010194 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08010166:
	ldrh r1, [r4, #0x28]
	movs r0, #4
	orrs r0, r1
	ldr r1, _08010198 @ =0x0000FFFC
	ands r0, r1
	strh r0, [r4, #0x28]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08010180: .4byte 0x000002C6
_08010184: .4byte 0x00001084
_08010188: .4byte 0x000002CA
_0801018C: .4byte FUN_08010718
_08010190: .4byte 0x03003E78
_08010194: .4byte 0xFFFFFEFF
_08010198: .4byte 0x0000FFFC

	thumb_func_start FUN_0801019c
FUN_0801019c: @ 0x0801019C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r5, r4, r0
	ldrh r6, [r5]
	cmp r6, #0
	bne _080101DA
	movs r0, #0xe3
	bl PlaySound_082406e0
	ldr r2, _08010218 @ =0x000002B2
	adds r1, r4, r2
	movs r0, #0x74
	strh r0, [r1]
	movs r3, #0xad
	lsls r3, r3, #2
	adds r1, r4, r3
	movs r0, #0xa0
	strh r0, [r1]
	ldr r1, _0801021C @ =0x000002AE
	adds r0, r4, r1
	strh r6, [r0]
	subs r2, #2
	adds r1, r4, r2
	movs r0, #4
	strh r0, [r1]
	adds r3, #0x20
	adds r1, r4, r3
	ldr r0, _08010220 @ =FUN_0801084c
	str r0, [r1]
_080101DA:
	ldrh r0, [r5]
	adds r1, r0, #1
	strh r1, [r5]
	ldr r2, _08010224 @ =0x000002BE
	adds r1, r4, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _0801020A
	ldrh r1, [r4, #0x28]
	ldr r0, _08010228 @ =0x0000FFFC
	ands r0, r1
	movs r2, #0
	strh r0, [r4, #0x28]
	ldr r1, _0801022C @ =FUN_080100f4
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r2, [r0]
_0801020A:
	ldrh r1, [r4, #0x28]
	movs r0, #4
	orrs r0, r1
	strh r0, [r4, #0x28]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08010218: .4byte 0x000002B2
_0801021C: .4byte 0x000002AE
_08010220: .4byte FUN_0801084c
_08010224: .4byte 0x000002BE
_08010228: .4byte 0x0000FFFC
_0801022C: .4byte FUN_080100f4

	thumb_func_start FUN_08010230
FUN_08010230: @ 0x08010230
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r6, r4, r0
	ldrh r5, [r6]
	cmp r5, #0
	bne _080102A0
	movs r0, #0xe1
	bl PlaySound_082406e0
	ldr r2, _0801032C @ =0x000002C2
	adds r1, r4, r2
	movs r0, #1
	strh r0, [r1]
	movs r7, #0xb1
	lsls r7, r7, #2
	adds r1, r4, r7
	movs r0, #5
	strh r0, [r1]
	ldr r0, _08010330 @ =0x000002C6
	adds r1, r4, r0
	ldr r0, _08010334 @ =0x00001084
	strh r0, [r1]
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r5, [r0]
	adds r2, #8
	adds r0, r4, r2
	movs r2, #4
	strh r2, [r0]
	adds r7, #0xc
	adds r1, r4, r7
	ldr r0, _08010338 @ =FUN_08010718
	str r0, [r1]
	ldr r1, _0801033C @ =0x000002B2
	adds r0, r4, r1
	strh r5, [r0]
	subs r7, #0x1c
	adds r1, r4, r7
	movs r0, #0x74
	strh r0, [r1]
	ldr r1, _08010340 @ =0x000002AE
	adds r0, r4, r1
	strh r5, [r0]
	movs r5, #0xac
	lsls r5, r5, #2
	adds r0, r4, r5
	strh r2, [r0]
	adds r7, #0x20
	adds r1, r4, r7
	ldr r0, _08010344 @ =FUN_0801084c
	str r0, [r1]
_080102A0:
	ldrh r0, [r6]
	cmp r0, #0x30
	bne _080102E8
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0800fc9c
	adds r1, r0, #0
	movs r3, #0
	ldr r0, _08010348 @ =0x03003ED0
	mov r8, r0
	mov ip, r8
_080102BA:
	movs r2, #0
	mov r5, ip
	movs r6, #0x18
	ldrsh r0, [r5, r6]
	lsls r0, r0, #1
	adds r5, r3, #1
	cmp r2, r0
	bge _080102E2
	movs r7, #0xd0
	lsls r7, r7, #8
	adds r6, r7, #0
	mov r3, r8
_080102D2:
	strh r6, [r1]
	adds r1, #2
	adds r2, #1
	movs r7, #0x18
	ldrsh r0, [r3, r7]
	lsls r0, r0, #1
	cmp r2, r0
	blt _080102D2
_080102E2:
	adds r3, r5, #0
	cmp r3, #0xe
	ble _080102BA
_080102E8:
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	movs r2, #0xaf
	lsls r2, r2, #2
	adds r1, r4, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _08010318
	ldr r1, _0801034C @ =FUN_0801019c
	movs r5, #0xb3
	lsls r5, r5, #2
	adds r0, r4, r5
	str r1, [r0]
	movs r6, #0xb6
	lsls r6, r6, #2
	adds r1, r4, r6
	movs r0, #0
	strh r0, [r1]
_08010318:
	ldrh r1, [r4, #0x28]
	movs r0, #0xf
	orrs r0, r1
	strh r0, [r4, #0x28]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801032C: .4byte 0x000002C2
_08010330: .4byte 0x000002C6
_08010334: .4byte 0x00001084
_08010338: .4byte FUN_08010718
_0801033C: .4byte 0x000002B2
_08010340: .4byte 0x000002AE
_08010344: .4byte FUN_0801084c
_08010348: .4byte 0x03003ED0
_0801034C: .4byte FUN_0801019c

	thumb_func_start FUN_08010350
FUN_08010350: @ 0x08010350
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08010094
	adds r3, r0, #0
	cmp r3, #0
	bne _08010398
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	ldr r2, _080103A0 @ =0x000002BA
	adds r1, r4, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _08010390
	ldr r1, _080103A4 @ =FUN_08010230
	adds r2, #0x12
	adds r0, r4, r2
	str r1, [r0]
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r3, [r0]
	adds r2, #8
	adds r1, r4, r2
	ldr r0, _080103A8 @ =FUN_080109b0
	str r0, [r1]
_08010390:
	ldrh r1, [r4, #0x28]
	movs r0, #0xf
	orrs r0, r1
	strh r0, [r4, #0x28]
_08010398:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080103A0: .4byte 0x000002BA
_080103A4: .4byte FUN_08010230
_080103A8: .4byte FUN_080109b0

	thumb_func_start FUN_080103ac
FUN_080103ac: @ 0x080103AC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl FUN_08010094
	adds r6, r0, #0
	cmp r6, #0
	bne _08010448
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _0801041A
	movs r0, #0xe1
	bl PlaySound_082406e0
	ldr r1, _08010450 @ =0x000002B2
	adds r0, r4, r1
	strh r6, [r0]
	movs r2, #0xad
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r0, #0xa0
	strh r0, [r1]
	ldr r0, _08010454 @ =0x000002AE
	adds r1, r4, r0
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	subs r2, #4
	adds r1, r4, r2
	ldr r0, _08010458 @ =0x0000FFFE
	strh r0, [r1]
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, _0801045C @ =FUN_0801084c
	str r0, [r1]
	adds r2, #0x16
	adds r1, r4, r2
	ldr r0, _08010460 @ =0x00001084
	strh r0, [r1]
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r6, [r0]
	adds r2, #4
	adds r1, r4, r2
	movs r0, #4
	strh r0, [r1]
	movs r0, #0xb4
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, _08010464 @ =FUN_080105ec
	str r0, [r1]
_0801041A:
	ldrh r0, [r5]
	adds r1, r0, #1
	strh r1, [r5]
	movs r2, #0xae
	lsls r2, r2, #2
	adds r1, r4, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _08010440
	ldr r0, _08010468 @ =FUN_0801046c
	adds r2, #0x14
	adds r1, r4, r2
	str r0, [r1]
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r6, [r0]
_08010440:
	ldrh r1, [r4, #0x28]
	movs r0, #0xf
	orrs r0, r1
	strh r0, [r4, #0x28]
_08010448:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08010450: .4byte 0x000002B2
_08010454: .4byte 0x000002AE
_08010458: .4byte 0x0000FFFE
_0801045C: .4byte FUN_0801084c
_08010460: .4byte 0x00001084
_08010464: .4byte FUN_080105ec
_08010468: .4byte FUN_0801046c

	thumb_func_start FUN_0801046c
FUN_0801046c: @ 0x0801046C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08010094
	adds r3, r0, #0
	cmp r3, #0
	bne _080104B6
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	ldr r2, _080104BC @ =0x000002B6
	adds r1, r4, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _080104AE
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, _080104C0 @ =FUN_080109b0
	str r0, [r1]
	ldr r1, _080104C4 @ =FUN_08010350
	adds r2, #0x16
	adds r0, r4, r2
	str r1, [r0]
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r3, [r0]
_080104AE:
	ldrh r1, [r4, #0x28]
	movs r0, #0xf
	orrs r0, r1
	strh r0, [r4, #0x28]
_080104B6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080104BC: .4byte 0x000002B6
_080104C0: .4byte FUN_080109b0
_080104C4: .4byte FUN_08010350

	thumb_func_start FUN_080104c8
FUN_080104c8: @ 0x080104C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r1, [r0]
	movs r0, #0x20
	subs r5, r0, r1
	movs r0, #0
	ldr r2, [r7, #0x20]
	mov sb, r2
	movs r1, #0xf8
	lsls r1, r1, #7
	mov sl, r1
_080104EC:
	movs r6, #0
	lsls r2, r0, #4
	mov ip, r2
	adds r0, #1
	mov r8, r0
_080104F6:
	mov r0, ip
	adds r4, r0, r6
	lsls r4, r4, #1
	add r4, sb
	ldrh r1, [r4]
	movs r0, #0x1f
	ands r0, r1
	adds r2, r0, #0
	muls r2, r5, r2
	movs r0, #0xf8
	lsls r0, r0, #3
	ands r2, r0
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r1
	adds r3, r0, #0
	muls r3, r5, r3
	movs r0, #0xf8
	lsls r0, r0, #8
	ands r3, r0
	mov r0, sl
	ands r0, r1
	adds r1, r0, #0
	muls r1, r5, r1
	movs r0, #0xf8
	lsls r0, r0, #0xd
	ands r1, r0
	orrs r2, r3
	orrs r2, r1
	asrs r2, r2, #6
	strh r2, [r4]
	adds r6, #1
	cmp r6, #0xf
	ble _080104F6
	mov r0, r8
	cmp r0, #1
	ble _080104EC
	movs r2, #0xb6
	lsls r2, r2, #2
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _08010574
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r1, #0xc1
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r0, [r0]
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r1, r7, r2
	bl Script_ExecById
	adds r0, r7, #0
	bl KillEntity
	b _0801057C
_08010574:
	ldrh r0, [r7, #0x28]
	movs r1, #0xf
	orrs r0, r1
	strh r0, [r7, #0x28]
_0801057C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801058c
FUN_0801058c: @ 0x0801058C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r6, #0x80
	lsls r6, r6, #1
	ldr r5, _080105DC @ =0x03003E78
	ldrh r0, [r5]
	bics r0, r6
	strh r0, [r5]
	adds r0, r4, #0
	bl FUN_08010094
	cmp r0, #0
	bne _080105D4
	ldrh r0, [r4, #0x2a]
	ldr r2, _080105E0 @ =0x0000FFFF
	adds r1, r0, r2
	strh r1, [r4, #0x2a]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _080105D4
	ldrh r1, [r5]
	adds r0, r6, #0
	orrs r0, r1
	strh r0, [r5]
	ldr r0, _080105E4 @ =0x03000048
	ldr r2, [r0]
	ldr r1, _080105E8 @ =FUN_080103ac
	movs r4, #0xb3
	lsls r4, r4, #2
	adds r0, r2, r4
	str r1, [r0]
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r0, r2, r1
	strh r3, [r0]
_080105D4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080105DC: .4byte 0x03003E78
_080105E0: .4byte 0x0000FFFF
_080105E4: .4byte 0x03000048
_080105E8: .4byte FUN_080103ac

	thumb_func_start FUN_080105ec
FUN_080105ec: @ 0x080105EC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov r8, r0
	movs r0, #0xb2
	lsls r0, r0, #2
	add r0, r8
	ldrh r7, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r7, r0
	ble _0801060C
	adds r7, r0, #0
_0801060C:
	subs r0, r0, r7
	mov ip, r0
	ldr r0, _0801070C @ =0x000002C6
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r1, r0
	str r1, [sp]
	movs r2, #0xf8
	lsls r2, r2, #2
	ands r2, r0
	str r2, [sp, #4]
	movs r3, #0xf8
	lsls r3, r3, #7
	ands r3, r0
	str r3, [sp, #8]
	movs r1, #0
	movs r0, #0
	ldr r4, _08010710 @ =0x000002C2
	add r4, r8
	str r4, [sp, #0xc]
	movs r2, #0xb1
	lsls r2, r2, #2
	add r2, r8
	str r2, [sp, #0x10]
_0801063E:
	ldr r3, [sp, #0xc]
	ldrh r6, [r3]
	adds r4, r1, #0
	adds r4, #0x10
	str r4, [sp, #0x14]
	adds r0, #1
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x10]
	ldrh r0, [r0]
	cmp r6, r0
	bge _080106CA
	mov r2, r8
	ldr r2, [r2, #0x24]
	mov sl, r2
	mov r3, r8
	ldr r3, [r3, #0x20]
	mov sb, r3
	adds r0, r6, r1
	lsls r5, r0, #1
_08010664:
	mov r4, sl
	adds r0, r4, r5
	mov r1, sb
	adds r1, r1, r5
	str r1, [sp, #0x1c]
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	adds r2, r0, #0
	muls r2, r7, r2
	ldr r3, [sp]
	mov r0, ip
	muls r0, r3, r0
	adds r2, r2, r0
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r2, r0
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r1
	adds r3, r0, #0
	muls r3, r7, r3
	ldr r4, [sp, #4]
	mov r0, ip
	muls r0, r4, r0
	adds r3, r3, r0
	movs r0, #0xf8
	lsls r0, r0, #0xa
	ands r3, r0
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r0, r1
	muls r0, r7, r0
	ldr r4, [sp, #8]
	mov r1, ip
	muls r1, r4, r1
	adds r0, r0, r1
	movs r1, #0xf8
	lsls r1, r1, #0xf
	ands r0, r1
	orrs r2, r3
	orrs r2, r0
	asrs r2, r2, #8
	ldr r0, [sp, #0x1c]
	strh r2, [r0]
	adds r5, #2
	adds r6, #1
	ldr r1, [sp, #0x10]
	ldrh r1, [r1]
	cmp r6, r1
	blt _08010664
_080106CA:
	ldr r1, [sp, #0x14]
	ldr r0, [sp, #0x18]
	cmp r0, #1
	ble _0801063E
	movs r2, #0xb2
	lsls r2, r2, #2
	add r2, r8
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bls _080106EE
	movs r1, #0xb4
	lsls r1, r1, #2
	add r1, r8
	movs r0, #0
	str r0, [r1]
	strh r0, [r2]
_080106EE:
	ldr r0, _08010714 @ =0x000002CA
	add r0, r8
	ldrh r0, [r0]
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801070C: .4byte 0x000002C6
_08010710: .4byte 0x000002C2
_08010714: .4byte 0x000002CA

	thumb_func_start FUN_08010718
FUN_08010718: @ 0x08010718
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	mov r8, r0
	movs r0, #0xb2
	lsls r0, r0, #2
	add r0, r8
	ldrh r0, [r0]
	mov ip, r0
	movs r0, #0x80
	lsls r0, r0, #1
	cmp ip, r0
	ble _0801073A
	mov ip, r0
_0801073A:
	mov r1, ip
	subs r7, r0, r1
	ldr r0, _08010840 @ =0x000002C6
	add r0, r8
	ldrh r0, [r0]
	movs r2, #0x1f
	ands r2, r0
	str r2, [sp]
	movs r1, #0xf8
	lsls r1, r1, #2
	ands r1, r0
	str r1, [sp, #4]
	movs r2, #0xf8
	lsls r2, r2, #7
	ands r2, r0
	str r2, [sp, #8]
	movs r1, #0
	movs r0, #0
	ldr r2, _08010844 @ =0x000002C2
	add r2, r8
	str r2, [sp, #0xc]
	movs r2, #0xb1
	lsls r2, r2, #2
	add r2, r8
	str r2, [sp, #0x1c]
_0801076C:
	ldr r2, [sp, #0xc]
	ldrh r6, [r2]
	adds r2, r1, #0
	adds r2, #0x10
	str r2, [sp, #0x24]
	adds r0, #1
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x1c]
	ldrh r0, [r0]
	cmp r6, r0
	bge _08010800
	ldr r0, [sp]
	mov r2, ip
	muls r2, r0, r2
	str r2, [sp, #0x10]
	ldr r0, [sp, #4]
	mov r2, ip
	muls r2, r0, r2
	str r2, [sp, #0x14]
	ldr r0, [sp, #8]
	mov r2, ip
	muls r2, r0, r2
	str r2, [sp, #0x18]
	mov r2, r8
	ldr r2, [r2, #0x24]
	mov sl, r2
	mov r0, r8
	ldr r0, [r0, #0x20]
	mov sb, r0
	adds r0, r6, r1
	lsls r5, r0, #1
_080107AA:
	mov r1, sl
	adds r0, r1, r5
	mov r2, sb
	adds r4, r2, r5
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	adds r2, r0, #0
	muls r2, r7, r2
	ldr r0, [sp, #0x10]
	adds r2, r0, r2
	movs r0, #0xf8
	lsls r0, r0, #5
	ands r2, r0
	movs r0, #0xf8
	lsls r0, r0, #2
	ands r0, r1
	adds r3, r0, #0
	muls r3, r7, r3
	ldr r0, [sp, #0x14]
	adds r3, r0, r3
	movs r0, #0xf8
	lsls r0, r0, #0xa
	ands r3, r0
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r0, r1
	muls r0, r7, r0
	ldr r1, [sp, #0x18]
	adds r0, r1, r0
	movs r1, #0xf8
	lsls r1, r1, #0xf
	ands r0, r1
	orrs r2, r3
	orrs r2, r0
	asrs r2, r2, #8
	strh r2, [r4]
	adds r5, #2
	adds r6, #1
	ldr r2, [sp, #0x1c]
	ldrh r2, [r2]
	cmp r6, r2
	blt _080107AA
_08010800:
	ldr r1, [sp, #0x24]
	ldr r0, [sp, #0x20]
	cmp r0, #1
	ble _0801076C
	movs r2, #0xb2
	lsls r2, r2, #2
	add r2, r8
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bls _08010824
	movs r1, #0xb4
	lsls r1, r1, #2
	add r1, r8
	movs r0, #0
	str r0, [r1]
	strh r0, [r2]
_08010824:
	ldr r0, _08010848 @ =0x000002CA
	add r0, r8
	ldrh r0, [r0]
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010840: .4byte 0x000002C6
_08010844: .4byte 0x000002C2
_08010848: .4byte 0x000002CA

	thumb_func_start FUN_0801084c
FUN_0801084c: @ 0x0801084C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov ip, r0
	movs r4, #0
	ldr r0, _0801096C @ =0x000002B2
	add r0, ip
	ldrh r1, [r0]
	cmp r4, r1
	bge _0801088C
	movs r6, #0xab
	lsls r6, r6, #2
	add r6, ip
	mov r5, ip
	adds r5, #0x2c
	movs r7, #0
	adds r3, r0, #0
_08010874:
	lsls r2, r4, #1
	ldrh r1, [r6]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r2, r2, r0
	adds r2, r5, r2
	strh r7, [r2]
	adds r4, #1
	ldrh r2, [r3]
	cmp r4, r2
	blt _08010874
_0801088C:
	ldr r0, _0801096C @ =0x000002B2
	add r0, ip
	ldrh r4, [r0]
	movs r0, #0xad
	lsls r0, r0, #2
	mov r8, r0
	mov r0, ip
	add r0, r8
	ldr r1, _08010970 @ =0x000002AE
	add r1, ip
	str r1, [sp]
	movs r2, #0xac
	lsls r2, r2, #2
	add r2, ip
	str r2, [sp, #4]
	ldrh r0, [r0]
	cmp r4, r0
	bge _080108FC
	ldr r0, _08010974 @ =0x0203B400
	mov sl, r0
	ldr r5, _08010978 @ =0x030046B8
	movs r7, #0xab
	lsls r7, r7, #2
	add r7, ip
	ldr r6, _08010970 @ =0x000002AE
	add r6, ip
	ldr r1, _0801097C @ =0x000003FF
	mov sb, r1
_080108C4:
	ldr r0, [r5]
	adds r0, #1
	mov r2, sb
	ands r0, r2
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sl
	ldrh r3, [r0]
	lsls r2, r4, #1
	ldrh r1, [r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r2, r2, r0
	mov r1, ip
	adds r1, #0x2c
	adds r1, r1, r2
	movs r2, #0
	ldrsh r0, [r6, r2]
	muls r0, r3, r0
	asrs r0, r0, #0x12
	strh r0, [r1]
	adds r4, #1
	mov r0, ip
	add r0, r8
	ldrh r0, [r0]
	cmp r4, r0
	blt _080108C4
_080108FC:
	movs r0, #0xad
	lsls r0, r0, #2
	add r0, ip
	ldrh r4, [r0]
	cmp r4, #0x9f
	bgt _0801092A
	movs r5, #0xab
	lsls r5, r5, #2
	add r5, ip
	mov r3, ip
	adds r3, #0x2c
	movs r6, #0
_08010914:
	lsls r2, r4, #1
	ldrh r1, [r5]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r2, r2, r0
	adds r2, r3, r2
	strh r6, [r2]
	adds r4, #1
	cmp r4, #0x9f
	ble _08010914
_0801092A:
	movs r0, #0xab
	lsls r0, r0, #2
	add r0, ip
	ldrh r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r0, #0x2c
	add r0, ip
	ldr r1, _08010980 @ =0x03003518
	str r0, [r1]
	ldr r0, _08010984 @ =0x0400004C
	ldr r2, _08010988 @ =0x03002CA0
	str r0, [r2]
	movs r0, #1
	ldr r1, _0801098C @ =0x03003510
	strh r0, [r1]
	ldr r2, _08010990 @ =0x03003514
	strh r0, [r2]
	ldr r1, [sp]
	ldr r2, [sp, #4]
	ldrh r0, [r2]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _08010994
	movs r0, #0
	strh r0, [r1]
	b _080109A0
	.align 2, 0
_0801096C: .4byte 0x000002B2
_08010970: .4byte 0x000002AE
_08010974: .4byte 0x0203B400
_08010978: .4byte 0x030046B8
_0801097C: .4byte 0x000003FF
_08010980: .4byte 0x03003518
_08010984: .4byte 0x0400004C
_08010988: .4byte 0x03002CA0
_0801098C: .4byte 0x03003510
_08010990: .4byte 0x03003514
_08010994:
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	ble _080109A0
	ldr r0, [sp]
	strh r1, [r0]
_080109A0:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080109b0
FUN_080109b0: @ 0x080109B0
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r4, #0
	str r4, [sp]
	adds r1, r5, #0
	adds r1, #0x2c
	ldr r2, _080109FC @ =0x05000091
	mov r0, sp
	bl CpuSet
	ldr r2, _08010A00 @ =0x03003518
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r0, #0x2c
	adds r0, r5, r0
	str r0, [r2]
	ldr r1, _08010A04 @ =0x03002CA0
	ldr r0, _08010A08 @ =0x0400004C
	str r0, [r1]
	ldr r1, _08010A0C @ =0x03003510
	movs r0, #1
	strh r0, [r1]
	ldr r0, _08010A10 @ =0x03003514
	strh r4, [r0]
	movs r1, #0xb5
	lsls r1, r1, #2
	adds r0, r5, r1
	str r4, [r0]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080109FC: .4byte 0x05000091
_08010A00: .4byte 0x03003518
_08010A04: .4byte 0x03002CA0
_08010A08: .4byte 0x0400004C
_08010A0C: .4byte 0x03003510
_08010A10: .4byte 0x03003514

	thumb_func_start Entity329B_Update
Entity329B_Update: @ 0x08010A14
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08010A2C
	adds r0, r5, #0
	bl _call_via_r1
_08010A2C:
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08010A3E
	adds r0, r5, #0
	bl _call_via_r1
_08010A3E:
	movs r1, #0xb5
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08010A50
	adds r0, r5, #0
	bl _call_via_r1
_08010A50:
	movs r0, #0xab
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	movs r4, #0
	strh r0, [r2]
	adds r0, r5, #0
	bl FUN_08010038
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start Entity329B_Destroy
Entity329B_Destroy: @ 0x08010A7C
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r5, #0
	str r5, [sp]
	adds r1, r4, #0
	adds r1, #0x2c
	ldr r2, _08010AC4 @ =0x05000091
	mov r0, sp
	bl CpuSet
	ldr r3, _08010AC8 @ =0x03003518
	movs r2, #0xab
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r2, [r1]
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #6
	adds r1, #0x2c
	adds r4, r4, r1
	str r4, [r3]
	ldr r2, _08010ACC @ =0x03002CA0
	ldr r1, _08010AD0 @ =0x0400004C
	str r1, [r2]
	ldr r2, _08010AD4 @ =0x03003510
	movs r1, #1
	strh r1, [r2]
	ldr r1, _08010AD8 @ =0x03003514
	strh r5, [r1]
	ldr r1, _08010ADC @ =0x03000048
	str r5, [r1]
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08010AC4: .4byte 0x05000091
_08010AC8: .4byte 0x03003518
_08010ACC: .4byte 0x03002CA0
_08010AD0: .4byte 0x0400004C
_08010AD4: .4byte 0x03003510
_08010AD8: .4byte 0x03003514
_08010ADC: .4byte 0x03000048

	thumb_func_start Entity329B_Init
Entity329B_Init: @ 0x08010AE0
	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r6, r0, #0
	ldr r0, _08010B40 @ =0x03000048
	str r6, [r0]
	ldr r3, _08010B44 @ =0x03003E78
	ldr r0, _08010B48 @ =0xFFFFFEFF
	ldrh r2, [r3]
	ands r0, r2
	strh r0, [r3]
	strh r1, [r6, #0x18]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r6, #0x1a]
	ldr r0, _08010B4C @ =0x0000596F
	strh r0, [r6, #0x1c]
	movs r0, #0x70
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r6, #0x1e]
	ldr r0, _08010B50 @ =0x030043F0
	str r0, [r6, #0x20]
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	movs r2, #0xc1
	lsls r2, r2, #2
	adds r1, r6, r2
	str r0, [r1]
	movs r0, #0x61
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _08010B7E
	movs r3, #0xb8
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r6, r2
	str r0, [r1]
	movs r4, #0
	b _08010B68
	.align 2, 0
_08010B40: .4byte 0x03000048
_08010B44: .4byte 0x03003E78
_08010B48: .4byte 0xFFFFFEFF
_08010B4C: .4byte 0x0000596F
_08010B50: .4byte 0x030043F0
_08010B54:
	bl Script_GetValue
	movs r3, #0xb8
	lsls r3, r3, #2
	adds r1, r6, r3
	ldr r2, [r1]
	lsls r1, r4, #2
	adds r1, r1, r2
	str r0, [r1]
	adds r4, #1
_08010B68:
	cmp r4, #7
	bgt _08010B74
	bl VM_GetPC
	cmp r0, #0
	bne _08010B54
_08010B74:
	movs r1, #0xb7
	lsls r1, r1, #2
	adds r0, r6, r1
	strh r4, [r0]
	b _08010B86
_08010B7E:
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r0, r6, r2
	strh r1, [r0]
_08010B86:
	movs r0, #0x74
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08010BE4
	movs r4, #0
	b _08010BB4
_08010B94:
	bl Script_GetValue
	lsls r2, r4, #1
	ldr r3, _08010BDC @ =0x000002B6
	adds r1, r6, r3
	adds r3, r1, r2
	strh r0, [r3]
	ldr r1, _08010BE0 @ =0x085AA810
	adds r2, r2, r1
	ldrh r2, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r2
	bhs _08010BB2
	strh r2, [r3]
_08010BB2:
	adds r4, #1
_08010BB4:
	cmp r4, #5
	bgt _08010BFA
	bl VM_GetPC
	cmp r0, #0
	bne _08010B94
	ldr r1, _08010BE0 @ =0x085AA810
	lsls r0, r4, #1
	adds r2, r0, r1
	ldr r1, _08010BDC @ =0x000002B6
	adds r0, r0, r1
	adds r1, r0, r6
_08010BCC:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	adds r4, #1
	cmp r4, #5
	ble _08010BCC
	b _08010BFA
	.align 2, 0
_08010BDC: .4byte 0x000002B6
_08010BE0: .4byte 0x085AA810
_08010BE4:
	ldr r2, _08010C20 @ =0x085AA810
	ldr r3, _08010C24 @ =0x000002B6
	adds r1, r6, r3
	movs r4, #5
_08010BEC:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r4, #1
	cmp r4, #0
	bge _08010BEC
_08010BFA:
	movs r0, #0
	strb r0, [r6, #0x1b]
	ldr r0, _08010C28 @ =0x0000C091
	ldrh r1, [r6, #0x1c]
	bl GetFile
	adds r4, r0, #0
	cmp r4, #0
	beq _08010C1A
	ldr r0, _08010C2C @ =0x000092B3
	ldrh r1, [r6, #0x1e]
	bl GetFile
	adds r5, r0, #0
	cmp r5, #0
	bne _08010C30
_08010C1A:
	movs r0, #1
	rsbs r0, r0, #0
	b _08010D0C
	.align 2, 0
_08010C20: .4byte 0x085AA810
_08010C24: .4byte 0x000002B6
_08010C28: .4byte 0x0000C091
_08010C2C: .4byte 0x000092B3
_08010C30:
	ldrb r0, [r4]
	cmp r0, #0x4d
	bne _08010C46
	ldrb r0, [r4, #1]
	cmp r0, #0x50
	bne _08010C46
	ldrb r0, [r6, #0x1b]
	movs r1, #0
	bl SetBGPrioDirect
	b _08010C62
_08010C46:
	movs r0, #0
	bl GetTilemapBuffer
	ldrb r2, [r6, #0x1b]
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r2, #0
	adds r2, r4, #0
	movs r3, #0
	bl FUN_0822bfbc
_08010C62:
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r5, r1
	str r0, [r6, #0x24]
	movs r4, #0
	str r4, [sp, #0x10]
	ldr r1, [r6, #0x20]
	ldr r2, _08010D14 @ =0x05000018
	add r0, sp, #0x10
	bl CpuSet
	ldr r2, _08010D18 @ =0x04000008
	ldrh r0, [r2]
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x77
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r6, #0x2a]
	ldr r1, _08010D1C @ =FUN_0801058c
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r6, r2
	str r1, [r0]
	movs r3, #0xb6
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r4, [r0]
	ldr r1, _08010D20 @ =0x000002C2
	adds r0, r6, r1
	strh r4, [r0]
	subs r2, #8
	adds r1, r6, r2
	movs r0, #0x10
	strh r0, [r1]
	subs r3, #0x12
	adds r1, r6, r3
	ldr r0, _08010D24 @ =0x00001084
	strh r0, [r1]
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r6, r1
	strh r4, [r0]
	adds r2, #6
	adds r0, r6, r2
	movs r5, #1
	strh r5, [r0]
	adds r3, #0xa
	adds r0, r6, r3
	str r4, [r0]
	str r4, [sp, #0x14]
	add r0, sp, #0x14
	adds r1, r6, #0
	adds r1, #0x2c
	ldr r2, _08010D28 @ =0x05000091
	bl CpuSet
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r6, r1
	strh r4, [r0]
	ldr r2, _08010D2C @ =0x000002AE
	adds r1, r6, r2
	movs r0, #0x80
	lsls r0, r0, #3
	strh r0, [r1]
	movs r3, #0xac
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r5, [r0]
	ldr r1, _08010D30 @ =0x000002B2
	adds r0, r6, r1
	strh r4, [r0]
	adds r2, #6
	adds r1, r6, r2
	movs r0, #0xa0
	strh r0, [r1]
	adds r3, #0x24
	adds r0, r6, r3
	str r4, [r0]
	movs r0, #0xf
	strh r0, [r6, #0x28]
	movs r0, #0
_08010D0C:
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08010D14: .4byte 0x05000018
_08010D18: .4byte 0x04000008
_08010D1C: .4byte FUN_0801058c
_08010D20: .4byte 0x000002C2
_08010D24: .4byte 0x00001084
_08010D28: .4byte 0x05000091
_08010D2C: .4byte 0x000002AE
_08010D30: .4byte 0x000002B2

	thumb_func_start Entity329B_Create
Entity329B_Create: @ 0x08010D34
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xc2
	lsls r1, r1, #2
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08010D70
	ldr r1, _08010D68 @ =Entity329B_Update
	ldr r2, _08010D6C @ =Entity329B_Destroy
	bl SetEntityRoutine
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl Entity329B_Init
	cmp r0, #0
	bge _08010D70
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08010D72
	.align 2, 0
_08010D68: .4byte Entity329B_Update
_08010D6C: .4byte Entity329B_Destroy
_08010D70:
	adds r0, r4, #0
_08010D72:
	pop {r4, r5}
	pop {r1}
	bx r1
