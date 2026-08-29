	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08013c94
FUN_08013c94: @ 0x08013C94
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r2, #0
	adds r5, r4, #0
	adds r5, #0x38
	adds r0, r5, #0
	bl FUN_0822b16c
	adds r4, #0xc
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0822a4fc
	strh r6, [r4, #0x10]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08013cb8
FUN_08013cb8: @ 0x08013CB8
	push {lr}
	adds r3, r0, #0
	cmp r1, #0
	beq _08013CC8
	ldr r1, [r3, #0xc]
	movs r2, #2
	orrs r1, r2
	b _08013CD0
_08013CC8:
	ldr r1, [r3, #0xc]
	movs r2, #3
	rsbs r2, r2, #0
	ands r1, r2
_08013CD0:
	str r1, [r3, #0xc]
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08013cd8
FUN_08013cd8: @ 0x08013CD8
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	ldr r4, [sp, #0x14]
	ldr r5, [sp, #0x18]
	ldr r6, [sp, #0x1c]
	ldr r7, [sp, #0x20]
	adds r0, #0x54
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strh r5, [r0]
	adds r0, #2
	strh r6, [r0]
	adds r0, #2
	strh r7, [r0]
	adds r0, #2
	mov r1, sp
	ldrh r1, [r1, #0x24]
	strh r1, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08013d10
FUN_08013d10: @ 0x08013D10
	push {lr}
	ldr r0, _08013D24 @ =0x03002B40
	ldr r0, [r0]
	cmp r0, #0
	bne _08013D1E
	bl FUN_08013df0
_08013D1E:
	pop {r1}
	bx r1
	.align 2, 0
_08013D24: .4byte 0x03002B40

	thumb_func_start FUN_08013d28
FUN_08013d28: @ 0x08013D28
	push {lr}
	ldr r2, [r0, #0x18]
	cmp r2, #0
	beq _08013D40
_08013D30:
	ldrh r0, [r2]
	cmp r0, r1
	bne _08013D3A
	adds r0, r2, #0
	b _08013D42
_08013D3A:
	ldr r2, [r2, #0x50]
	cmp r2, #0
	bne _08013D30
_08013D40:
	movs r0, #0
_08013D42:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08013d48
FUN_08013d48: @ 0x08013D48
	push {lr}
	ldrb r2, [r1, #2]
	cmp r2, #0
	beq _08013D56
	movs r0, #1
	rsbs r0, r0, #0
	b _08013D6A
_08013D56:
	str r2, [r1, #0x4c]
	ldr r2, [r0, #0x18]
	str r2, [r1, #0x50]
	cmp r2, #0
	beq _08013D62
	str r1, [r2, #0x4c]
_08013D62:
	str r1, [r0, #0x18]
	movs r0, #1
	strb r0, [r1, #2]
	movs r0, #0
_08013D6A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08013d70
FUN_08013d70: @ 0x08013D70
	push {r4, lr}
	adds r4, r0, #0
	ldr r3, [r1, #0x4c]
	ldr r2, [r1, #0x50]
	ldrb r0, [r1, #2]
	cmp r0, #0
	bne _08013D84
	movs r0, #1
	rsbs r0, r0, #0
	b _08013D98
_08013D84:
	cmp r3, #0
	beq _08013D8C
	str r2, [r3, #0x50]
	b _08013D8E
_08013D8C:
	str r2, [r4, #0x18]
_08013D8E:
	cmp r2, #0
	beq _08013D94
	str r3, [r2, #0x4c]
_08013D94:
	movs r0, #0
	strb r0, [r1, #2]
_08013D98:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08013da0
FUN_08013da0: @ 0x08013DA0
	movs r0, #0
	bx lr

	thumb_func_start FUN_08013da4
FUN_08013da4: @ 0x08013DA4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r5, [r6, #0x18]
	cmp r5, #0
	beq _08013DCC
_08013DAE:
	ldr r4, [r5, #0x50]
	adds r0, r5, #0
	adds r0, #0xc
	bl FUN_080138fc
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_08013d70
	adds r0, r5, #0
	bl Free
	adds r5, r4, #0
	cmp r5, #0
	bne _08013DAE
_08013DCC:
	movs r1, #0
	str r1, [r6, #0x18]
	ldr r0, _08013DDC @ =0x03002B40
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08013DDC: .4byte 0x03002B40

	thumb_func_start FUN_08013de0
FUN_08013de0: @ 0x08013DE0
	ldr r1, _08013DEC @ =0x03002B40
	str r0, [r1]
	movs r1, #0
	str r1, [r0, #0x18]
	movs r0, #0
	bx lr
	.align 2, 0
_08013DEC: .4byte 0x03002B40

	thumb_func_start FUN_08013df0
FUN_08013df0: @ 0x08013DF0
	push {r4, lr}
	ldr r0, _08013E24 @ =0x03002B40
	ldr r0, [r0]
	cmp r0, #0
	bne _08013E32
	movs r0, #9
	movs r1, #0x1c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08013E30
	ldr r1, _08013E28 @ =FUN_08013da0
	ldr r2, _08013E2C @ =FUN_08013da4
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08013de0
	cmp r0, #0
	bge _08013E30
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08013E32
	.align 2, 0
_08013E24: .4byte 0x03002B40
_08013E28: .4byte FUN_08013da0
_08013E2C: .4byte FUN_08013da4
_08013E30:
	adds r0, r4, #0
_08013E32:
	pop {r4}
	pop {r1}
	bx r1

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
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x6d
	movs r1, #1
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x70
	bl prepare_08231510
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
	bl Script_GetKeywordValue
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
	bl Script_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x6d
	movs r1, #1
	bl Script_GetKeywordValue
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
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x70
	bl prepare_08231510
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

	thumb_func_start FUN_08014594
FUN_08014594: @ 0x08014594
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

	thumb_func_start FUN_08014608
FUN_08014608: @ 0x08014608
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

	thumb_func_start FUN_08014664
FUN_08014664: @ 0x08014664
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

	thumb_func_start FUN_080146e0
FUN_080146e0: @ 0x080146E0
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
	ldr r1, _08014720 @ =FUN_08014594
	ldr r2, _08014724 @ =FUN_08014608
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08014664
	cmp r0, #0
	bge _08014728
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801472A
	.align 2, 0
_08014718: .4byte 0x03000058
_0801471C: .4byte 0x00000ABC
_08014720: .4byte FUN_08014594
_08014724: .4byte FUN_08014608
_08014728:
	adds r0, r4, #0
_0801472A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08014730
FUN_08014730: @ 0x08014730
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r0, [sp]
	str r1, [sp, #4]
	mov sl, r2
	mov r8, r3
	ldr r0, _08014760 @ =0x03000058
	ldr r1, [r0]
	cmp r1, #0
	bne _08014764
	movs r0, #0
	movs r1, #0
	bl FUN_080146e0
	adds r1, r0, #0
	cmp r1, #0
	bne _08014764
	movs r0, #1
	rsbs r0, r0, #0
	b _080149CA
	.align 2, 0
_08014760: .4byte 0x03000058
_08014764:
	ldr r0, [sp, #4]
	asrs r3, r0, #8
	movs r0, #0xff
	ldr r2, [sp, #4]
	ands r2, r0
	str r2, [sp, #4]
	ldr r4, [sp]
	cmp r4, #8
	ble _0801477A
	movs r0, #8
	str r0, [sp]
_0801477A:
	ldr r2, [sp, #4]
	cmp r2, #0x14
	bgt _08014786
	ldr r4, [r1, #0x1c]
	str r4, [sp, #8]
	b _0801478A
_08014786:
	ldr r0, [r1, #0x20]
	str r0, [sp, #8]
_0801478A:
	movs r2, #0
	adds r1, #0x24
	str r1, [sp, #0xc]
	adds r7, r1, #0
_08014792:
	ldrb r0, [r7]
	cmp r0, #0
	beq _0801479A
	b _080149B4
_0801479A:
	movs r0, #1
	strb r0, [r7]
	mov r1, sp
	ldrb r1, [r1, #4]
	strb r1, [r7, #2]
	mov r2, sp
	ldrb r2, [r2]
	strb r2, [r7, #1]
	cmp r3, #0
	ble _080147B2
	subs r0, r3, #1
	b _080147B4
_080147B2:
	movs r0, #2
_080147B4:
	strb r0, [r7, #3]
	movs r6, #0
	ldr r4, [sp]
	cmp r6, r4
	blt _080147C0
	b _08014988
_080147C0:
	ldr r5, _08014820 @ =0x030046B8
	ldr r3, _08014824 @ =0x000003FF
	ldr r4, [sp, #0xc]
	adds r4, #4
	ldr r0, [sp, #0xc]
	adds r0, #0x14
	mov sb, r0
	ldr r6, [sp]
_080147D0:
	movs r1, #0
	movs r0, #1
	strb r0, [r4]
	strb r0, [r4, #1]
	strb r1, [r4, #2]
	ldr r0, [r5]
	adds r0, #1
	ands r0, r3
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _08014828 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r2, [sp, #0x3c]
	ands r0, r2
	ldr r1, [sp, #0x38]
	adds r0, r1, r0
	strb r0, [r4, #3]
	mov r2, sl
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, sl
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0801481C
	cmp r1, #0
	blt _0801481C
	ldr r0, _0801482C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0801481C
	ldr r0, _08014830 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08014838
_0801481C:
	ldr r0, _08014834 @ =0x0000FFFF
	b _08014846
	.align 2, 0
_08014820: .4byte 0x030046B8
_08014824: .4byte 0x000003FF
_08014828: .4byte 0x0203B400
_0801482C: .4byte 0x030046A8
_08014830: .4byte 0x030046AC
_08014834: .4byte 0x0000FFFF
_08014838:
	ldr r0, _08014884 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_08014846:
	strh r0, [r4, #4]
	mov r2, sl
	ldrh r0, [r2, #2]
	strh r0, [r4, #6]
	ldr r1, [sp, #0x34]
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _0801488C
	ldr r0, [r5]
	adds r0, #1
	ands r0, r3
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _08014888 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r2, [sp, #0x34]
	movs r1, #0
	ldrsh r2, [r2, r1]
	mov ip, r2
	mov r1, ip
	str r3, [sp, #0x10]
	bl Mod
	mov r2, r8
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r4, #8]
	ldr r3, [sp, #0x10]
	b _08014892
	.align 2, 0
_08014884: .4byte 0x030046A4
_08014888: .4byte 0x0203B400
_0801488C:
	mov r1, r8
	ldrh r0, [r1]
	strh r0, [r4, #8]
_08014892:
	ldr r2, [sp, #0x34]
	movs r1, #2
	ldrsh r0, [r2, r1]
	cmp r0, #0
	beq _080148CC
	ldr r0, [r5]
	adds r0, #1
	ands r0, r3
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _080148C8 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, [sp, #0x34]
	movs r2, #2
	ldrsh r1, [r1, r2]
	mov ip, r1
	str r3, [sp, #0x10]
	bl Mod
	mov r2, r8
	ldrh r1, [r2, #2]
	adds r1, r1, r0
	strh r1, [r4, #0xa]
	ldr r3, [sp, #0x10]
	b _080148D2
	.align 2, 0
_080148C8: .4byte 0x0203B400
_080148CC:
	mov r1, r8
	ldrh r0, [r1, #2]
	strh r0, [r4, #0xa]
_080148D2:
	ldr r2, [sp, #0x34]
	movs r1, #4
	ldrsh r0, [r2, r1]
	cmp r0, #0
	beq _0801490C
	ldr r0, [r5]
	adds r0, #1
	ands r0, r3
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _08014908 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, [sp, #0x34]
	movs r2, #4
	ldrsh r1, [r1, r2]
	mov ip, r1
	str r3, [sp, #0x10]
	bl Mod
	mov r2, r8
	ldrh r1, [r2, #4]
	adds r1, r1, r0
	strh r1, [r4, #0xc]
	ldr r3, [sp, #0x10]
	b _08014912
	.align 2, 0
_08014908: .4byte 0x0203B400
_0801490C:
	mov r1, r8
	ldrh r0, [r1, #4]
	strh r0, [r4, #0xc]
_08014912:
	ldr r0, [r5]
	adds r0, #1
	ands r0, r3
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _08014934 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #7
	bgt _08014938
	ldr r0, [r4, #0x10]
	movs r1, #4
	orrs r0, r1
	b _08014940
	.align 2, 0
_08014934: .4byte 0x0203B400
_08014938:
	ldr r0, [r4, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08014940:
	str r0, [r4, #0x10]
	ldr r0, [r4, #0x10]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x10]
	mov r2, sl
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x28]
	str r1, [r4, #0x2c]
	ldr r1, _080149B0 @ =0x085AA850
	ldr r2, [sp, #4]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r2, [sp, #8]
	ldrh r0, [r2, #4]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrb r0, [r7, #3]
	strb r0, [r4, #0x1f]
	mov r0, sb
	movs r1, #0
	str r3, [sp, #0x10]
	bl FUN_0822da50
	adds r4, #0x38
	movs r0, #0x38
	add sb, r0
	subs r6, #1
	ldr r3, [sp, #0x10]
	cmp r6, #0
	beq _08014986
	b _080147D0
_08014986:
	ldr r6, [sp]
_08014988:
	cmp r6, #7
	bgt _080149C8
	movs r3, #0
	movs r2, #1
	lsls r0, r6, #3
	subs r0, r0, r6
	lsls r0, r0, #3
	adds r0, #4
	ldr r4, [sp, #0xc]
	adds r1, r0, r4
_0801499C:
	strb r3, [r1]
	ldr r0, [r1, #0x10]
	orrs r0, r2
	str r0, [r1, #0x10]
	adds r1, #0x38
	adds r6, #1
	cmp r6, #7
	ble _0801499C
	b _080149C8
	.align 2, 0
_080149B0: .4byte 0x085AA850
_080149B4:
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r7, r7, r0
	ldr r1, [sp, #0xc]
	adds r1, r1, r0
	str r1, [sp, #0xc]
	adds r2, #1
	cmp r2, #5
	bgt _080149C8
	b _08014792
_080149C8:
	movs r0, #0
_080149CA:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080149dc
FUN_080149dc: @ 0x080149DC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	ldr r0, _08014A0C @ =0x03000058
	ldr r1, [r0]
	cmp r1, #0
	bne _08014A10
	movs r0, #0
	movs r1, #0
	bl FUN_080146e0
	adds r1, r0, #0
	cmp r1, #0
	bne _08014A10
	movs r0, #1
	rsbs r0, r0, #0
	b _08014D12
	.align 2, 0
_08014A0C: .4byte 0x03000058
_08014A10:
	ldr r0, [sp, #4]
	asrs r3, r0, #8
	movs r0, #0xff
	ldr r2, [sp, #4]
	ands r2, r0
	str r2, [sp, #4]
	ldr r4, [sp]
	cmp r4, #8
	ble _08014A26
	movs r0, #8
	str r0, [sp]
_08014A26:
	ldr r2, [sp, #4]
	cmp r2, #0x14
	bgt _08014A34
	ldr r4, [r1, #0x1c]
	str r4, [sp, #0x18]
	ldrh r0, [r4, #6]
	b _08014A3C
_08014A34:
	ldr r2, [r1, #0x20]
	str r2, [sp, #0x18]
	ldrh r0, [r2, #6]
	adds r0, #1
_08014A3C:
	str r0, [sp, #0x14]
	ldr r4, [sp, #0x44]
	asrs r4, r4, #1
	str r4, [sp, #0x10]
	movs r2, #0
	ldr r0, [sp, #0xc]
	movs r4, #0xff
	ands r0, r4
	lsls r0, r0, #1
	str r0, [sp, #0x1c]
	adds r1, #0x24
	mov sl, r1
	mov r8, sl
_08014A56:
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08014A60
	b _08014D00
_08014A60:
	movs r0, #1
	strb r0, [r1]
	mov r2, sp
	ldrb r2, [r2, #4]
	strb r2, [r1, #2]
	mov r4, sp
	ldrb r4, [r4]
	strb r4, [r1, #1]
	cmp r3, #0
	ble _08014A78
	subs r0, r3, #1
	b _08014A7C
_08014A78:
	movs r0, #2
	mov r1, r8
_08014A7C:
	strb r0, [r1, #3]
	movs r7, #0
	ldr r2, [sp]
	cmp r7, r2
	blt _08014A88
	b _08014CD6
_08014A88:
	ldr r6, _08014AEC @ =0x030046B8
	movs r3, #0xc
	add r3, sl
	mov sb, r3
	mov r4, sl
	adds r4, #4
	mov r0, sl
	adds r0, #0x14
	str r0, [sp, #0x20]
	adds r7, r2, #0
_08014A9C:
	movs r0, #1
	strb r0, [r4]
	strb r0, [r4, #1]
	movs r1, #0
	strb r1, [r4, #2]
	ldr r0, [r6]
	adds r0, #1
	ldr r2, _08014AF0 @ =0x000003FF
	ands r0, r2
	str r0, [r6]
	lsls r0, r0, #1
	ldr r3, _08014AF4 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #0x5c]
	ands r0, r1
	ldr r2, [sp, #0x58]
	adds r0, r2, r0
	strb r0, [r4, #3]
	ldr r3, [sp, #8]
	ldrh r0, [r3]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08014AE8
	cmp r1, #0
	blt _08014AE8
	ldr r0, _08014AF8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08014AE8
	ldr r0, _08014AFC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08014B04
_08014AE8:
	ldr r0, _08014B00 @ =0x0000FFFF
	b _08014B12
	.align 2, 0
_08014AEC: .4byte 0x030046B8
_08014AF0: .4byte 0x000003FF
_08014AF4: .4byte 0x0203B400
_08014AF8: .4byte 0x030046A8
_08014AFC: .4byte 0x030046AC
_08014B00: .4byte 0x0000FFFF
_08014B04:
	ldr r0, _08014B40 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_08014B12:
	strh r0, [r4, #4]
	ldr r1, [sp, #8]
	ldrh r0, [r1, #2]
	strh r0, [r4, #6]
	ldr r2, [sp, #0x4c]
	cmp r2, #0
	beq _08014B4C
	ldr r0, [r6]
	adds r0, #1
	ldr r3, _08014B44 @ =0x000003FF
	ands r0, r3
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _08014B48 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [sp, #0x4c]
	bl Mod
	ldr r2, [sp, #0x48]
	adds r5, r2, r0
	b _08014B4E
	.align 2, 0
_08014B40: .4byte 0x030046A4
_08014B44: .4byte 0x000003FF
_08014B48: .4byte 0x0203B400
_08014B4C:
	ldr r5, [sp, #0x48]
_08014B4E:
	ldr r3, [sp, #0x44]
	cmp r3, #0
	beq _08014BD2
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _08014B94 @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _08014B98 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, [sp, #0x44]
	bl Mod
	ldr r3, [sp, #0xc]
	ldr r2, [sp, #0x10]
	subs r1, r3, r2
	mov r2, sb
	adds r1, r1, r0
	adds r0, r1, #0
	adds r0, #0x40
	movs r3, #0xff
	ands r0, r3
	lsls r0, r0, #1
	ldr r3, _08014B9C @ =0x085B0A08
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r5, r0
	cmp r0, #0
	blt _08014BA0
	asrs r0, r0, #0xc
	b _08014BA6
	.align 2, 0
_08014B94: .4byte 0x000003FF
_08014B98: .4byte 0x0203B400
_08014B9C: .4byte 0x085B0A08
_08014BA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08014BA6:
	strh r0, [r2]
	movs r0, #0
	strh r0, [r2, #2]
	movs r3, #0xff
	ands r1, r3
	lsls r0, r1, #1
	ldr r1, _08014BC4 @ =0x085B0A08
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r5, r0
	cmp r0, #0
	blt _08014BC8
	asrs r0, r0, #0xc
	b _08014BCE
	.align 2, 0
_08014BC4: .4byte 0x085B0A08
_08014BC8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08014BCE:
	strh r0, [r2, #4]
	b _08014C1E
_08014BD2:
	mov r1, sb
	ldr r0, [sp, #0xc]
	adds r0, #0x40
	movs r2, #0xff
	ands r0, r2
	lsls r0, r0, #1
	ldr r3, _08014BF4 @ =0x085B0A08
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	adds r2, r3, #0
	cmp r0, #0
	blt _08014BF8
	asrs r0, r0, #0xc
	b _08014BFE
	.align 2, 0
_08014BF4: .4byte 0x085B0A08
_08014BF8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08014BFE:
	strh r0, [r1]
	movs r3, #0
	strh r3, [r1, #2]
	ldr r3, [sp, #0x1c]
	adds r0, r3, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08014C16
	asrs r0, r0, #0xc
	b _08014C1C
_08014C16:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08014C1C:
	strh r0, [r1, #4]
_08014C1E:
	ldr r3, [sp, #0x54]
	cmp r3, #0
	beq _08014C4C
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _08014C44 @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _08014C48 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, [sp, #0x54]
	bl Mod
	ldr r3, [sp, #0x50]
	adds r0, r3, r0
	b _08014C50
	.align 2, 0
_08014C44: .4byte 0x000003FF
_08014C48: .4byte 0x0203B400
_08014C4C:
	add r0, sp, #0x50
	ldrh r0, [r0]
_08014C50:
	strh r0, [r4, #0xa]
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _08014C74 @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _08014C78 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #7
	bgt _08014C7C
	ldr r0, [r4, #0x10]
	movs r1, #4
	orrs r0, r1
	b _08014C84
	.align 2, 0
_08014C74: .4byte 0x000003FF
_08014C78: .4byte 0x0203B400
_08014C7C:
	ldr r0, [r4, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08014C84:
	str r0, [r4, #0x10]
	ldr r0, [r4, #0x10]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x10]
	ldr r3, [sp, #8]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r4, #0x28]
	str r1, [r4, #0x2c]
	mov r0, sp
	ldrb r0, [r0, #0x14]
	strb r0, [r4, #0x1e]
	ldr r1, _08014CFC @ =0x085AA850
	ldr r2, [sp, #4]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r3, [sp, #0x18]
	ldrh r0, [r3, #4]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	mov r1, r8
	ldrb r0, [r1, #3]
	strb r0, [r4, #0x1f]
	ldr r0, [sp, #0x20]
	movs r1, #0
	bl FUN_0822da50
	movs r2, #0x38
	add sb, r2
	adds r4, #0x38
	ldr r3, [sp, #0x20]
	adds r3, #0x38
	str r3, [sp, #0x20]
	subs r7, #1
	cmp r7, #0
	beq _08014CD4
	b _08014A9C
_08014CD4:
	ldr r7, [sp]
_08014CD6:
	cmp r7, #7
	bgt _08014D10
	movs r3, #0
	movs r2, #1
	lsls r0, r7, #3
	subs r0, r0, r7
	lsls r0, r0, #3
	adds r0, #4
	mov r4, sl
	adds r1, r0, r4
_08014CEA:
	strb r3, [r1]
	ldr r0, [r1, #0x10]
	orrs r0, r2
	str r0, [r1, #0x10]
	adds r1, #0x38
	adds r7, #1
	cmp r7, #7
	ble _08014CEA
	b _08014D10
	.align 2, 0
_08014CFC: .4byte 0x085AA850
_08014D00:
	movs r0, #0xe2
	lsls r0, r0, #1
	add r8, r0
	add sl, r0
	adds r2, #1
	cmp r2, #5
	bgt _08014D10
	b _08014A56
_08014D10:
	movs r0, #0
_08014D12:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08014d24
FUN_08014d24: @ 0x08014D24
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	ldr r0, _08014D90 @ =0x03000058
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	beq _08014D82
	movs r1, #0
	movs r2, #0
_08014D3C:
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0x24
	mov r3, sb
	adds r6, r3, r0
	ldrb r0, [r6]
	adds r1, #1
	mov r8, r1
	cmp r0, #0
	beq _08014D7C
	adds r4, r6, #4
	adds r5, r6, #0
	adds r5, #0x14
	movs r7, #7
_08014D5E:
	ldrb r0, [r4]
	cmp r0, #0
	beq _08014D70
	adds r0, r5, #0
	str r2, [sp]
	bl FUN_0822dabc
	ldr r2, [sp]
	strb r2, [r4]
_08014D70:
	adds r4, #0x38
	adds r5, #0x38
	subs r7, #1
	cmp r7, #0
	bge _08014D5E
	strb r2, [r6]
_08014D7C:
	mov r1, r8
	cmp r1, #5
	ble _08014D3C
_08014D82:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08014D90: .4byte 0x03000058

	thumb_func_start FUN_08014d94
FUN_08014d94: @ 0x08014D94
	ldr r1, _08014D9C @ =0x0300005C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08014D9C: .4byte 0x0300005C

	thumb_func_start FUN_08014da0
FUN_08014da0: @ 0x08014DA0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	str r0, [sp]
	adds r5, r1, #0
	str r2, [sp, #4]
	str r3, [sp, #8]
	ldr r0, _08014DD0 @ =0x0300005C
	ldr r0, [r0]
	cmp r0, #0
	bne _08014DD4
	movs r0, #0
	movs r1, #0
	bl FUN_08015220
	cmp r0, #0
	bne _08014DD4
_08014DC8:
	movs r0, #1
	rsbs r0, r0, #0
	b _08015062
	.align 2, 0
_08014DD0: .4byte 0x0300005C
_08014DD4:
	ldr r0, _08014E74 @ =0x0300005C
	ldr r0, [r0]
	ldr r1, [sp]
	cmp r1, #6
	ble _08014DE2
	movs r2, #6
	str r2, [sp]
_08014DE2:
	movs r1, #0
	adds r7, r0, #0
	adds r7, #0x20
	movs r2, #0x52
	adds r2, r2, r0
	mov sb, r2
	adds r2, r0, #0
	adds r2, #0x46
	str r2, [sp, #0x14]
	adds r4, r0, #0
	adds r4, #0x24
	mov r8, r7
_08014DFA:
	ldrb r0, [r7]
	cmp r0, #0
	beq _08014E02
	b _08015046
_08014E02:
	strb r5, [r7, #2]
	mov r0, sp
	ldrb r0, [r0]
	strb r0, [r7, #1]
	ldr r1, _08014E78 @ =0x085AA902
	ldrb r0, [r7, #2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl FUN_0822b16c
	str r4, [sp, #0xc]
	cmp r0, #0
	beq _08014DC8
	ldrb r0, [r7, #2]
	cmp r0, #4
	beq _08014E2A
	cmp r0, #8
	bne _08014E34
_08014E2A:
	ldrh r1, [r7, #0xa]
	adds r1, #1
	adds r0, r4, #0
	bl FUN_0822b20c
_08014E34:
	movs r3, #0
	ldr r1, [sp]
	cmp r3, r1
	blt _08014E3E
	b _08015040
_08014E3E:
	ldr r6, _08014E7C @ =0x030046B8
	mov r0, r8
	adds r2, r0, #0
	str r2, [sp, #0x10]
	mov r5, r8
	adds r5, #0x40
	mov sl, sb
	ldr r1, [sp, #0x14]
	mov sb, r1
_08014E50:
	movs r0, #0x2c
	muls r0, r3, r0
	adds r0, #0x70
	mov r2, r8
	adds r4, r2, r0
	mov r0, r8
	adds r0, #0x20
	adds r0, r0, r3
	movs r1, #1
	strb r1, [r0]
	ldr r0, [sp, #0x40]
	cmp r0, #0
	bne _08014E80
	add r1, sp, #0x3c
	ldrb r2, [r1]
	mov r1, sb
	strb r2, [r1]
	b _08014EA4
	.align 2, 0
_08014E74: .4byte 0x0300005C
_08014E78: .4byte 0x085AA902
_08014E7C: .4byte 0x030046B8
_08014E80:
	ldr r0, [r6]
	adds r0, #1
	ldr r2, _08014EB4 @ =0x000003FF
	ands r0, r2
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _08014EB8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [sp, #0x40]
	str r3, [sp, #0x18]
	bl Mod
	ldr r2, [sp, #0x3c]
	adds r0, r2, r0
	mov r1, sb
	strb r0, [r1]
	ldr r3, [sp, #0x18]
_08014EA4:
	ldr r2, [sp, #0x48]
	cmp r2, #0
	bne _08014EBC
	add r0, sp, #0x44
	ldrh r1, [r0]
	mov r0, sl
	strh r1, [r0]
	b _08014EE0
	.align 2, 0
_08014EB4: .4byte 0x000003FF
_08014EB8: .4byte 0x0203B400
_08014EBC:
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _08014EEC @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _08014EF0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, [sp, #0x48]
	str r3, [sp, #0x18]
	bl Mod
	ldr r1, [sp, #0x44]
	adds r0, r1, r0
	mov r2, sl
	strh r0, [r2]
	ldr r3, [sp, #0x18]
_08014EE0:
	ldr r0, [sp, #0x50]
	cmp r0, #0
	bne _08014EF4
	ldr r2, [sp, #0x4c]
	b _08014F14
	.align 2, 0
_08014EEC: .4byte 0x000003FF
_08014EF0: .4byte 0x0203B400
_08014EF4:
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _08014F40 @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _08014F44 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, [sp, #0x50]
	str r3, [sp, #0x18]
	bl Mod
	ldr r1, [sp, #0x4c]
	adds r2, r1, r0
	ldr r3, [sp, #0x18]
_08014F14:
	ldr r0, _08014F48 @ =0x085B0A08
	mov ip, r0
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r5]
	ands r2, r1
	lsls r0, r2, #1
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r5, #4]
	ldr r2, [sp, #0x58]
	cmp r2, #0
	bne _08014F4C
	add r0, sp, #0x54
	ldrh r0, [r0]
	strh r0, [r5, #2]
	b _08014F72
	.align 2, 0
_08014F40: .4byte 0x000003FF
_08014F44: .4byte 0x0203B400
_08014F48: .4byte 0x085B0A08
_08014F4C:
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _08014F98 @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _08014F9C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, [sp, #0x58]
	str r3, [sp, #0x18]
	bl Mod
	ldr r1, [sp, #0x54]
	adds r0, r1, r0
	ldr r1, [sp, #0x10]
	adds r1, #0x42
	strh r0, [r1]
	ldr r3, [sp, #0x18]
_08014F72:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r2, [sp, #4]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	movs r1, #0
	ldrsh r0, [r5, r1]
	ldr r2, [sp, #8]
	muls r0, r2, r0
	cmp r0, #0
	blt _08014FA0
	asrs r1, r0, #0xc
	b _08014FA6
	.align 2, 0
_08014F98: .4byte 0x000003FF
_08014F9C: .4byte 0x0203B400
_08014FA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08014FA6:
	ldrh r0, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	movs r1, #4
	ldrsh r0, [r5, r1]
	ldr r2, [sp, #8]
	muls r0, r2, r0
	cmp r0, #0
	blt _08014FBC
	asrs r1, r0, #0xc
	b _08014FC2
_08014FBC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08014FC2:
	ldrh r0, [r4, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #0x20]
	adds r0, r4, #0
	ldr r1, [sp, #0xc]
	movs r2, #0x80
	lsls r2, r2, #2
	str r3, [sp, #0x18]
	bl FUN_0822a470
	ldr r1, _08015008 @ =0x085AA8F0
	ldrb r0, [r7, #2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r4, #0x10]
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _0801500C @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _08015010 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xff
	ands r0, r1
	ldr r3, [sp, #0x18]
	cmp r0, #0x80
	bgt _08015014
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _0801501C
	.align 2, 0
_08015008: .4byte 0x085AA8F0
_0801500C: .4byte 0x000003FF
_08015010: .4byte 0x0203B400
_08015014:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0801501C:
	str r0, [r4]
	mov r0, r8
	adds r0, #0x2c
	adds r0, r0, r3
	movs r1, #1
	strb r1, [r0]
	ldr r2, [sp, #0x10]
	adds r2, #8
	str r2, [sp, #0x10]
	adds r5, #8
	movs r0, #2
	add sl, r0
	add sb, r1
	adds r3, #1
	ldr r1, [sp]
	cmp r3, r1
	bge _08015040
	b _08014E50
_08015040:
	movs r0, #1
	strb r0, [r7]
	b _08015060
_08015046:
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r7, r7, r2
	add sb, r2
	ldr r0, [sp, #0x14]
	adds r0, r0, r2
	str r0, [sp, #0x14]
	adds r4, r4, r2
	add r8, r2
	adds r1, #1
	cmp r1, #3
	bgt _08015060
	b _08014DFA
_08015060:
	movs r0, #0
_08015062:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08015074
FUN_08015074: @ 0x08015074
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r1, #0
	movs r0, #0
	strb r0, [r4, #1]
	mov r8, r0
	adds r7, r4, #0
	adds r7, #0x2c
	adds r5, r4, #0
	adds r5, #0x42
	mov sl, r0
	movs r0, #0x40
	adds r0, r0, r4
	mov sb, r0
_08015096:
	movs r0, #0x2c
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, #0x70
	adds r3, r4, r0
	ldrb r0, [r7]
	cmp r0, #0
	beq _08015124
	mov r6, sb
	movs r0, #0
	ldrsh r2, [r6, r0]
	adds r1, r4, #0
	adds r1, #0x32
	mov r6, sl
	adds r0, r1, r6
	ldrh r0, [r0]
	muls r0, r2, r0
	adds r6, r1, #0
	cmp r0, #0
	blt _080150C4
	asrs r2, r0, #0xc
	b _080150CA
_080150C4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080150CA:
	ldrh r0, [r3, #0x1c]
	adds r0, r0, r2
	strh r0, [r3, #0x1c]
	ldrh r0, [r5]
	ldrh r1, [r3, #0x1e]
	adds r0, r0, r1
	strh r0, [r3, #0x1e]
	movs r2, #2
	ldrsh r1, [r5, r2]
	mov r2, sl
	adds r0, r6, r2
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080150EC
	asrs r1, r0, #0xc
	b _080150F2
_080150EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080150F2:
	ldrh r0, [r3, #0x20]
	adds r0, r0, r1
	movs r2, #0
	strh r0, [r3, #0x20]
	ldrh r0, [r5]
	subs r0, #2
	strh r0, [r5]
	adds r1, r4, #0
	adds r1, #0x26
	add r1, r8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0801511E
	strb r2, [r7]
	adds r0, r3, #0
	bl FUN_0822a4e0
	b _08015124
_0801511E:
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_08015124:
	adds r7, #1
	adds r5, #8
	movs r6, #2
	add sl, r6
	movs r0, #8
	add sb, r0
	movs r1, #1
	add r8, r1
	mov r2, r8
	cmp r2, #5
	ble _08015096
	ldrb r0, [r4, #1]
	cmp r0, #0
	bne _08015142
	strb r0, [r4]
_08015142:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08015150
FUN_08015150: @ 0x08015150
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x20
	movs r6, #3
_0801515A:
	ldrb r0, [r4]
	cmp r0, #0
	beq _08015168
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08015074
_08015168:
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r4, r4, r0
	subs r6, #1
	cmp r6, #0
	bge _0801515A
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08015184
FUN_08015184: @ 0x08015184
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r1, #0
_0801518E:
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	mov r2, r8
	adds r5, r2, r0
	ldrb r0, [r5]
	adds r7, r1, #1
	cmp r0, #0
	beq _080151C6
	movs r4, #0
	adds r6, r5, #0
	adds r6, #0x2c
_080151AC:
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _080151C0
	movs r0, #0x2c
	muls r0, r4, r0
	adds r0, #0x70
	adds r0, r5, r0
	bl FUN_0822a4e0
_080151C0:
	adds r4, #1
	cmp r4, #5
	ble _080151AC
_080151C6:
	adds r1, r7, #0
	cmp r1, #3
	ble _0801518E
	ldr r1, _080151DC @ =0x0300005C
	movs r0, #0
	str r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080151DC: .4byte 0x0300005C

	thumb_func_start FUN_080151e0
FUN_080151e0: @ 0x080151E0
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r1, #0
	ldr r5, _0801521C @ =0x0300005C
	movs r4, #0
_080151EA:
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	adds r0, r3, r0
	strb r4, [r0]
	adds r2, r1, #1
	movs r1, #5
	adds r0, #0x31
_08015200:
	strb r4, [r0]
	subs r0, #1
	subs r1, #1
	cmp r1, #0
	bge _08015200
	adds r1, r2, #0
	cmp r1, #3
	ble _080151EA
	movs r0, #0
	str r0, [r3, #0x18]
	str r3, [r5]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801521C: .4byte 0x0300005C

	thumb_func_start FUN_08015220
FUN_08015220: @ 0x08015220
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xc0
	lsls r1, r1, #3
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801525C
	ldr r1, _08015254 @ =FUN_08015150
	ldr r2, _08015258 @ =FUN_08015184
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080151e0
	cmp r0, #0
	bge _0801525C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801525E
	.align 2, 0
_08015254: .4byte FUN_08015150
_08015258: .4byte FUN_08015184
_0801525C:
	adds r0, r4, #0
_0801525E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08015264
FUN_08015264: @ 0x08015264
	ldr r1, _0801526C @ =0x03000060
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0801526C: .4byte 0x03000060

	thumb_func_start FUN_08015270
FUN_08015270: @ 0x08015270
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp]
	adds r0, #0x60
	mov sl, r0
	ldr r1, [sp]
	adds r1, #0x24
	mov r8, r1
	mov sb, r8
	movs r2, #0x1f
	str r2, [sp, #4]
_0801528E:
	mov r3, r8
	ldrb r0, [r3]
	cmp r0, #0
	bne _08015298
	b _08015444
_08015298:
	mov r5, sb
	mov r7, sl
	ldrh r0, [r3, #2]
	ldrh r1, [r3, #0xc]
	cmp r0, r1
	blo _080152F0
	movs r2, #6
	ldrsh r1, [r3, r2]
	ldrh r0, [r3, #0xe]
	muls r0, r1, r0
	cmp r0, #0
	blt _080152B4
	asrs r0, r0, #8
	b _080152BA
_080152B4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080152BA:
	strh r0, [r5, #6]
	movs r3, #0x10
	ldrsh r1, [r5, r3]
	movs r2, #6
	ldrsh r0, [r5, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080152CE
	asrs r0, r0, #0xc
	b _080152D4
_080152CE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080152D4:
	strh r0, [r5, #0x18]
	movs r3, #0x14
	ldrsh r1, [r5, r3]
	movs r2, #6
	ldrsh r0, [r5, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080152E8
	asrs r0, r0, #0xc
	b _080152EE
_080152E8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080152EE:
	strh r0, [r5, #0x1c]
_080152F0:
	ldrh r0, [r5, #2]
	ldrh r3, [r5, #8]
	cmp r0, r3
	blo _0801532A
	movs r0, #4
	ldrsh r1, [r5, r0]
	ldrh r0, [r5, #0xa]
	muls r0, r1, r0
	cmp r0, #0
	blt _08015308
	asrs r0, r0, #8
	b _0801530E
_08015308:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801530E:
	strh r0, [r5, #4]
	movs r2, #0x12
	ldrsh r1, [r5, r2]
	movs r3, #4
	ldrsh r0, [r5, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _08015322
	asrs r0, r0, #0xc
	b _08015328
_08015322:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08015328:
	strh r0, [r5, #0x1a]
_0801532A:
	ldrh r0, [r5, #0x18]
	ldrh r1, [r7, #0x1c]
	adds r0, r0, r1
	strh r0, [r7, #0x1c]
	ldrh r0, [r5, #0x1a]
	ldrh r2, [r7, #0x1e]
	adds r0, r0, r2
	strh r0, [r7, #0x1e]
	ldr r0, [r7]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0801534C
	ldrh r0, [r5, #0x1c]
	ldrh r3, [r7, #0x20]
	adds r0, r0, r3
	strh r0, [r7, #0x20]
_0801534C:
	adds r4, r5, #0
	adds r4, #0x68
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x68]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r6]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r2, r0
	beq _0801537C
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _08015384
_0801537C:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08015384:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080153A8
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080153B0
_080153A8:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080153B0:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _080153E8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0801542E
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080153F2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080153EC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08015408
	.align 2, 0
_080153E8: .4byte 0x0000FFFF
_080153EC:
	subs r0, #1
	strh r0, [r4, #8]
	b _08015406
_080153F2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08015406
	strh r1, [r4, #8]
	movs r2, #1
	b _08015408
_08015406:
	movs r2, #0
_08015408:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08015430
	movs r3, #1
	strb r3, [r4, #7]
	b _08015430
_0801542E:
	movs r2, #0
_08015430:
	cmp r2, #0
	beq _0801543E
	movs r0, #0
	strb r0, [r5]
	adds r0, r7, #0
	bl FUN_0822a4e0
_0801543E:
	ldrh r0, [r5, #2]
	adds r0, #1
	strh r0, [r5, #2]
_08015444:
	movs r0, #0x78
	add sl, r0
	add sb, r0
	add r8, r0
	ldr r1, [sp, #4]
	subs r1, #1
	str r1, [sp, #4]
	cmp r1, #0
	blt _08015458
	b _0801528E
_08015458:
	ldr r2, [sp]
	ldr r0, [r2, #0x20]
	adds r0, #1
	str r0, [r2, #0x20]
	movs r0, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08015474
FUN_08015474: @ 0x08015474
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r5, #0x60
	adds r4, r0, #0
	adds r4, #0x24
	movs r6, #0x1f
_08015480:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801548C
	adds r0, r5, #0
	bl FUN_0822a4e0
_0801548C:
	adds r5, #0x78
	adds r4, #0x78
	subs r6, #1
	cmp r6, #0
	bge _08015480
	movs r1, #0
	ldr r0, _080154A4 @ =0x03000060
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080154A4: .4byte 0x03000060

	thumb_func_start FUN_080154a8
FUN_080154a8: @ 0x080154A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sl, r0
	ldr r0, _0801551C @ =0x03000060
	mov r1, sl
	str r1, [r0]
	movs r0, #0
	str r0, [sp, #4]
	ldr r4, _08015520 @ =0x085AA914
	mov r7, sl
	adds r7, #0x18
_080154C6:
	ldrh r1, [r4]
	ldr r0, _08015524 @ =0x0000922E
	bl GetFile
	stm r7!, {r0}
	adds r4, #2
	ldr r1, [sp, #4]
	adds r1, #1
	str r1, [sp, #4]
	cmp r1, #1
	ble _080154C6
	ldr r0, _08015528 @ =0xFFFF0000
	movs r5, #0
	ands r6, r0
	movs r0, #0
	str r0, [sp, #4]
	mov sb, r0
	mov r1, sl
	adds r1, #0x8c
	str r1, [sp, #8]
	movs r0, #0x60
	add r0, sl
	mov r8, r0
	mov r7, sl
	adds r7, #0x44
	mov r4, sl
	adds r4, #0x24
_080154FC:
	mov r1, sb
	strb r1, [r4]
	mov r0, sb
	strh r0, [r4, #4]
	strh r0, [r4, #0x10]
	strh r0, [r4, #0x12]
	strh r0, [r4, #0x14]
	adds r0, r7, #0
	ldr r1, _0801552C @ =0x00004384
	bl FUN_0822b16c
	cmp r0, #0
	bne _08015530
	movs r0, #1
	rsbs r0, r0, #0
	b _08015574
	.align 2, 0
_0801551C: .4byte 0x03000060
_08015520: .4byte 0x085AA914
_08015524: .4byte 0x0000922E
_08015528: .4byte 0xFFFF0000
_0801552C: .4byte 0x00004384
_08015530:
	mov r0, r8
	adds r1, r7, #0
	movs r2, #0
	bl FUN_0822a4b0
	mov r0, sl
	ldr r1, [r0, #0x18]
	mov r0, sb
	str r0, [sp]
	ldr r0, [sp, #8]
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	movs r0, #2
	mov r1, r8
	strb r0, [r1, #7]
	str r5, [r4, #0x58]
	str r6, [r4, #0x5c]
	ldr r0, [sp, #8]
	adds r0, #0x78
	str r0, [sp, #8]
	movs r1, #0x78
	add r8, r1
	adds r7, #0x78
	adds r4, #0x78
	ldr r0, [sp, #4]
	adds r0, #1
	str r0, [sp, #4]
	cmp r0, #0x1f
	ble _080154FC
	movs r0, #0
	mov r1, sl
	str r0, [r1, #0x20]
_08015574:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08015584
FUN_08015584: @ 0x08015584
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _080155B4 @ =0x00000F24
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080155C0
	ldr r1, _080155B8 @ =FUN_08015270
	ldr r2, _080155BC @ =FUN_08015474
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080154a8
	cmp r0, #0
	bge _080155C0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080155C2
	.align 2, 0
_080155B4: .4byte 0x00000F24
_080155B8: .4byte FUN_08015270
_080155BC: .4byte FUN_08015474
_080155C0:
	adds r0, r4, #0
_080155C2:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080155c8
FUN_080155c8: @ 0x080155C8
	push {lr}
	movs r1, #0xf0
	lsls r1, r1, #8
	ands r0, r1
	asrs r0, r0, #0xc
	subs r0, #1
	movs r1, #2
	cmp r0, #3
	bhi _080155DC
	adds r1, r0, #0
_080155DC:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080155e4
FUN_080155e4: @ 0x080155E4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r6, r2, #0
	ldr r0, _0801560C @ =0x03000060
	ldr r0, [r0]
	cmp r0, #0
	bne _08015614
	movs r0, #0
	movs r1, #0
	bl FUN_08015584
	cmp r0, #0
	bne _08015614
	b _08015A7A
	.align 2, 0
_0801560C: .4byte 0x03000060
_08015610:
	movs r0, #0
	b _08015A7E
_08015614:
	movs r0, #0
	str r0, [sp, #0x10]
	movs r1, #0
	str r1, [sp, #0xc]
	ldr r2, _0801565C @ =0x03000060
	mov sl, r2
	ldr r3, _08015660 @ =0x030046B8
	mov sb, r3
_08015624:
	ldr r1, [sp, #0xc]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x24
	mov r2, sl
	ldr r1, [r2]
	adds r5, r1, r0
	movs r3, #0x3c
	adds r3, r3, r5
	mov r8, r3
	ldrb r1, [r5]
	cmp r1, #0
	beq _08015642
	b _08015A6E
_08015642:
	movs r0, #1
	strb r0, [r5]
	ldrh r0, [r6]
	strb r0, [r5, #1]
	strh r1, [r5, #2]
	movs r1, #0xa
	ldrsh r0, [r6, r1]
	cmp r0, #0
	bne _08015664
	ldrh r0, [r6, #8]
	strh r0, [r5, #4]
	b _08015686
	.align 2, 0
_0801565C: .4byte 0x03000060
_08015660: .4byte 0x030046B8
_08015664:
	mov r2, sb
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08015694 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08015698 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r2, #0xa
	ldrsh r1, [r6, r2]
	bl Mod
	ldrh r1, [r6, #8]
	adds r1, r1, r0
	strh r1, [r5, #4]
_08015686:
	movs r3, #0xe
	ldrsh r0, [r6, r3]
	cmp r0, #0
	bne _0801569C
	ldrh r0, [r6, #0xc]
	strh r0, [r5, #6]
	b _080156C0
	.align 2, 0
_08015694: .4byte 0x000003FF
_08015698: .4byte 0x0203B400
_0801569C:
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _080156CC @ =0x000003FF
	ands r0, r1
	mov r2, sb
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080156D0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r2, #0xe
	ldrsh r1, [r6, r2]
	bl Mod
	ldrh r1, [r6, #0xc]
	adds r1, r1, r0
	strh r1, [r5, #6]
_080156C0:
	ldrh r0, [r6, #0x12]
	cmp r0, #0
	bne _080156D4
	ldrh r7, [r6, #0x10]
	b _080156F2
	.align 2, 0
_080156CC: .4byte 0x000003FF
_080156D0: .4byte 0x0203B400
_080156D4:
	mov r3, sb
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _080156FC @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _08015700 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r6, #0x12]
	bl Mod
	ldrh r1, [r6, #0x10]
	adds r7, r1, r0
_080156F2:
	ldrh r0, [r6, #0x16]
	cmp r0, #0
	bne _08015704
	ldrh r4, [r6, #0x14]
	b _08015722
	.align 2, 0
_080156FC: .4byte 0x000003FF
_08015700: .4byte 0x0203B400
_08015704:
	mov r2, sb
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08015730 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08015734 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldrh r1, [r6, #0x16]
	bl Mod
	ldrh r1, [r6, #0x14]
	adds r4, r1, r0
_08015722:
	ldrh r0, [r6, #0x1a]
	cmp r0, #0
	bne _08015738
	ldrh r0, [r6, #0x18]
	strh r0, [r5, #8]
	b _0801575A
	.align 2, 0
_08015730: .4byte 0x000003FF
_08015734: .4byte 0x0203B400
_08015738:
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _08015768 @ =0x000003FF
	ands r0, r1
	mov r2, sb
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0801576C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldrh r1, [r6, #0x1a]
	bl Mod
	ldrh r1, [r6, #0x18]
	adds r1, r1, r0
	strh r1, [r5, #8]
_0801575A:
	ldrh r0, [r6, #0x22]
	cmp r0, #0
	bne _08015770
	ldrh r0, [r6, #0x20]
	strh r0, [r5, #0xc]
	b _08015792
	.align 2, 0
_08015768: .4byte 0x000003FF
_0801576C: .4byte 0x0203B400
_08015770:
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _080157AC @ =0x000003FF
	ands r0, r1
	mov r2, sb
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080157B0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldrh r1, [r6, #0x22]
	bl Mod
	ldrh r1, [r6, #0x20]
	adds r1, r1, r0
	strh r1, [r5, #0xc]
_08015792:
	ldrh r1, [r6, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080157B4
	mov r1, r8
	ldr r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	mov r2, r8
	str r0, [r2]
	b _080157C2
	.align 2, 0
_080157AC: .4byte 0x000003FF
_080157B0: .4byte 0x0203B400
_080157B4:
	mov r3, r8
	ldr r0, [r3]
	ldr r1, _080157DC @ =0xFFFFFDFF
	ands r0, r1
	ldr r1, _080157E0 @ =0xFFFFFBFF
	ands r0, r1
	str r0, [r3]
_080157C2:
	ldrh r1, [r6, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080157E4
	mov r1, r8
	ldr r0, [r1]
	movs r1, #0x10
	orrs r0, r1
	mov r2, r8
	str r0, [r2]
	b _080157F0
	.align 2, 0
_080157DC: .4byte 0xFFFFFDFF
_080157E0: .4byte 0xFFFFFBFF
_080157E4:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_080157F0:
	ldr r2, _08015828 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r5, #0x10]
	ands r7, r1
	lsls r0, r7, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r5, #0x12]
	ands r4, r1
	lsls r0, r4, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r5, #0x14]
	movs r0, #0x10
	ldrsh r1, [r5, r0]
	movs r2, #6
	ldrsh r0, [r5, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _0801582C
	asrs r0, r0, #0xc
	b _08015832
	.align 2, 0
_08015828: .4byte 0x085B0A08
_0801582C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08015832:
	strh r0, [r5, #0x18]
	movs r3, #0x12
	ldrsh r1, [r5, r3]
	movs r2, #4
	ldrsh r0, [r5, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _08015846
	asrs r0, r0, #0xc
	b _0801584C
_08015846:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0801584C:
	strh r0, [r5, #0x1a]
	movs r3, #0x14
	ldrsh r1, [r5, r3]
	movs r2, #6
	ldrsh r0, [r5, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _08015860
	asrs r0, r0, #0xc
	b _08015866
_08015860:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08015866:
	movs r7, #0
	strh r0, [r5, #0x1c]
	ldrb r0, [r5, #1]
	cmp r0, #5
	bne _080158A8
	adds r4, r5, #0
	adds r4, #0x20
	adds r0, r4, #0
	ldr r1, _080158A4 @ =0x000061F9
	bl FUN_0822b16c
	adds r0, r4, #0
	movs r1, #0x89
	lsls r1, r1, #2
	bl FUN_0822b20c
	adds r1, r5, #0
	adds r1, #0x3c
	movs r0, #0x20
	strh r0, [r1, #0x10]
	adds r4, #0x48
	mov r3, sl
	ldr r0, [r3]
	ldr r1, [r0, #0x1c]
	str r7, [sp]
	adds r0, r4, #0
	movs r2, #6
	movs r3, #0
	bl FUN_08236fac
	b _0801594E
	.align 2, 0
_080158A4: .4byte 0x000061F9
_080158A8:
	cmp r0, #6
	bne _080158E4
	adds r4, r5, #0
	adds r4, #0x20
	adds r0, r4, #0
	ldr r1, _080158E0 @ =0x000061F9
	bl FUN_0822b16c
	adds r0, r4, #0
	movs r1, #0x8b
	lsls r1, r1, #2
	bl FUN_0822b20c
	adds r1, r5, #0
	adds r1, #0x3c
	movs r0, #0x20
	strh r0, [r1, #0x10]
	adds r4, #0x48
	mov r1, sl
	ldr r0, [r1]
	ldr r1, [r0, #0x1c]
	str r7, [sp]
	adds r0, r4, #0
	movs r2, #6
	movs r3, #0
	bl FUN_08236fac
	b _0801594E
	.align 2, 0
_080158E0: .4byte 0x000061F9
_080158E4:
	cmp r0, #7
	bne _08015924
	adds r4, r5, #0
	adds r4, #0x20
	adds r0, r4, #0
	ldr r1, _0801591C @ =0x000061F9
	bl FUN_0822b16c
	adds r0, r4, #0
	ldr r1, _08015920 @ =0x0000022B
	bl FUN_0822b20c
	adds r1, r5, #0
	adds r1, #0x3c
	movs r0, #0x2d
	strh r0, [r1, #0x10]
	adds r4, #0x48
	mov r2, sl
	ldr r0, [r2]
	ldr r1, [r0, #0x1c]
	str r7, [sp]
	adds r0, r4, #0
	movs r2, #8
	movs r3, #0
	bl FUN_08236fac
	b _0801594E
	.align 2, 0
_0801591C: .4byte 0x000061F9
_08015920: .4byte 0x0000022B
_08015924:
	adds r4, r5, #0
	adds r4, #0x20
	adds r0, r4, #0
	ldr r1, _08015988 @ =0x00004384
	bl FUN_0822b16c
	ldrb r1, [r5, #1]
	adds r1, #0x7d
	adds r0, r4, #0
	bl FUN_0822b20c
	adds r4, #0x48
	mov r3, sl
	ldr r0, [r3]
	ldr r1, [r0, #0x18]
	str r7, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
_0801594E:
	adds r7, r4, #0
	adds r4, r7, #0
	ldrh r0, [r7, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x68]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	mov r1, r8
	strh r0, [r1, #0x10]
	ldrb r0, [r7, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r3, #1
	ands r0, r3
	cmp r2, r0
	beq _0801598C
	mov r1, r8
	ldr r0, [r1]
	movs r1, #4
	orrs r0, r1
	mov r2, r8
	str r0, [r2]
	b _08015998
	.align 2, 0
_08015988: .4byte 0x00004384
_0801598C:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_08015998:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080159C0
	mov r1, r8
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	mov r2, r8
	str r0, [r2]
	b _080159CC
_080159C0:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_080159CC:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _08015A00 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08015A38
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08015A04
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080159FA
	ldrb r0, [r4, #5]
_080159FA:
	subs r0, #1
	strh r0, [r4, #8]
	b _08015A14
	.align 2, 0
_08015A00: .4byte 0x0000FFFF
_08015A04:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08015A14
	strh r1, [r4, #8]
_08015A14:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08015A38
	movs r3, #1
	strb r3, [r4, #7]
_08015A38:
	ldr r2, [sp, #8]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	mov r3, r8
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	ldrh r0, [r6, #2]
	bl FUN_080155c8
	mov r1, r8
	strb r0, [r1, #7]
	ldrh r1, [r6, #6]
	adds r0, r7, #0
	bl FUN_08237098
	mov r0, r8
	movs r1, #0
	bl FUN_0822a340
	ldr r0, [sp, #0x10]
	adds r2, r0, #0
	adds r2, #1
	str r2, [sp, #0x10]
	ldr r3, [sp, #4]
	cmp r0, r3
	blt _08015A6E
	b _08015610
_08015A6E:
	ldr r0, [sp, #0xc]
	adds r0, #1
	str r0, [sp, #0xc]
	cmp r0, #0x1f
	bgt _08015A7A
	b _08015624
_08015A7A:
	movs r0, #1
	rsbs r0, r0, #0
_08015A7E:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08015a90
FUN_08015a90: @ 0x08015A90
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x28
	mov r8, r0
	adds r7, r1, #0
	ldr r1, [sp, #0x40]
	ldr r5, [sp, #0x44]
	mov r0, sp
	movs r4, #0
	strh r2, [r0]
	strh r3, [r0, #2]
	strh r1, [r0, #6]
	strh r4, [r0, #8]
	strh r4, [r0, #0xa]
	strh r5, [r0, #0xc]
	strh r4, [r0, #0xe]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, #0
	bl Div
	adds r6, r0, #0
	mov r0, sp
	strh r4, [r0, #0x12]
	strh r4, [r0, #0x10]
	add r1, sp, #0x48
	ldrh r1, [r1]
	strh r1, [r0, #0x18]
	strh r4, [r0, #0x1a]
	add r2, sp, #0x4c
	ldrh r2, [r2]
	strh r2, [r0, #0x1c]
	strh r4, [r0, #0x1e]
	add r1, sp, #0x48
	ldrh r1, [r1]
	strh r1, [r0, #0x20]
	strh r4, [r0, #0x22]
	add r2, sp, #0x4c
	ldrh r2, [r2]
	strh r2, [r0, #0x24]
	strh r4, [r0, #0x26]
	mov r1, sp
	movs r0, #0xa
	strh r0, [r1, #0x16]
	mov r0, sp
	strh r4, [r0, #0x14]
	cmp r7, #0
	ble _08015B0C
	mov r5, sp
	adds r4, r7, #0
_08015AF6:
	movs r0, #1
	mov r1, r8
	mov r2, sp
	bl FUN_080155e4
	ldrh r0, [r5, #0x14]
	adds r0, r0, r6
	strh r0, [r5, #0x14]
	subs r4, #1
	cmp r4, #0
	bne _08015AF6
_08015B0C:
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08015b18
FUN_08015b18: @ 0x08015B18
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	mov r8, r0
	str r1, [sp, #0x30]
	ldr r4, [sp, #0x58]
	ldr r5, [sp, #0x5c]
	ldr r6, [sp, #0x60]
	mov r0, sp
	movs r1, #0
	strh r4, [r0]
	strh r5, [r0, #2]
	strh r6, [r0, #6]
	strh r1, [r0, #8]
	strh r1, [r0, #0xa]
	add r4, sp, #0x64
	ldrh r4, [r4]
	strh r4, [r0, #0xc]
	strh r1, [r0, #0xe]
	strh r1, [r0, #0x10]
	strh r1, [r0, #0x12]
	strh r2, [r0, #0x14]
	strh r3, [r0, #0x16]
	add r5, sp, #0x68
	ldrh r5, [r5]
	strh r5, [r0, #0x18]
	strh r1, [r0, #0x1a]
	add r7, sp, #0x6c
	ldrh r7, [r7]
	strh r7, [r0, #0x1c]
	strh r1, [r0, #0x1e]
	add r2, sp, #0x68
	ldrh r2, [r2]
	strh r2, [r0, #0x20]
	strh r1, [r0, #0x22]
	add r3, sp, #0x6c
	ldrh r3, [r3]
	strh r3, [r0, #0x24]
	strh r1, [r0, #0x26]
	ldr r4, [sp, #0x54]
	cmp r4, #0
	ble _08015C04
	ldr r5, _08015C14 @ =0x0203B400
	mov sl, r5
	ldr r6, _08015C18 @ =0x030046B8
	ldr r7, _08015C1C @ =0x000003FF
	mov sb, r7
	adds r5, r4, #0
	add r4, sp, #0x28
_08015B80:
	ldr r2, [r6]
	adds r2, #1
	mov r0, sb
	ands r2, r0
	str r2, [r6]
	lsls r0, r2, #1
	add r0, sl
	ldrh r0, [r0]
	ldr r3, [sp, #0x30]
	ldrh r1, [r3]
	ands r0, r1
	mov r7, r8
	ldrh r7, [r7]
	adds r0, r0, r7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, [sp, #0x28]
	ldr r1, _08015C20 @ =0xFFFF0000
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #0x28]
	adds r2, #1
	mov r7, sb
	ands r2, r7
	str r2, [r6]
	lsls r0, r2, #1
	add r0, sl
	ldrh r1, [r0]
	ldr r7, [sp, #0x30]
	ldrh r0, [r7, #2]
	ands r1, r0
	mov r0, r8
	ldrh r0, [r0, #2]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _08015C24 @ =0x0000FFFF
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x28]
	adds r2, #1
	mov r1, sb
	ands r2, r1
	str r2, [r6]
	lsls r2, r2, #1
	add r2, sl
	ldrh r1, [r2]
	ldrh r0, [r7, #4]
	ands r1, r0
	mov r2, r8
	ldrh r2, [r2, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r4, #4]
	ldr r3, _08015C20 @ =0xFFFF0000
	ands r0, r3
	orrs r0, r1
	str r0, [r4, #4]
	movs r0, #1
	adds r1, r4, #0
	mov r2, sp
	bl FUN_080155e4
	subs r5, #1
	cmp r5, #0
	bne _08015B80
_08015C04:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08015C14: .4byte 0x0203B400
_08015C18: .4byte 0x030046B8
_08015C1C: .4byte 0x000003FF
_08015C20: .4byte 0xFFFF0000
_08015C24: .4byte 0x0000FFFF

	thumb_func_start FUN_08015c28
FUN_08015c28: @ 0x08015C28
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x28
	mov r8, r0
	adds r0, r3, #0
	ldr r5, [sp, #0x40]
	ldr r6, [sp, #0x44]
	ldr r7, [sp, #0x48]
	mov r3, sp
	movs r4, #0
	strh r5, [r3]
	strh r6, [r3, #2]
	strh r7, [r3, #6]
	strh r4, [r3, #8]
	strh r4, [r3, #0xa]
	add r5, sp, #0x4c
	ldrh r5, [r5]
	strh r5, [r3, #0xc]
	strh r4, [r3, #0xe]
	strh r4, [r3, #0x10]
	strh r4, [r3, #0x12]
	strh r1, [r3, #0x14]
	mov r1, sp
	strh r2, [r1, #0x16]
	add r6, sp, #0x50
	ldrh r6, [r6]
	strh r6, [r1, #0x18]
	strh r4, [r1, #0x1a]
	add r2, sp, #0x54
	ldrh r2, [r2]
	strh r2, [r1, #0x1c]
	strh r4, [r1, #0x1e]
	add r3, sp, #0x50
	ldrh r3, [r3]
	strh r3, [r1, #0x20]
	strh r4, [r1, #0x22]
	add r5, sp, #0x54
	ldrh r5, [r5]
	strh r5, [r1, #0x24]
	strh r4, [r1, #0x26]
	mov r1, r8
	mov r2, sp
	bl FUN_080155e4
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08015c90
FUN_08015c90: @ 0x08015C90
	push {r4, r5, r6, lr}
	sub sp, #0x28
	ldr r6, [sp, #0x38]
	mov r4, sp
	movs r5, #0
	strh r1, [r4]
	mov r1, sp
	strh r2, [r1, #2]
	strh r3, [r1, #6]
	movs r2, #0xc
	strh r2, [r1, #8]
	strh r2, [r1, #0xa]
	movs r2, #4
	strh r2, [r1, #0xc]
	strh r2, [r1, #0xe]
	mov r2, sp
	movs r1, #0x3c
	strh r1, [r2, #0x10]
	movs r1, #8
	strh r1, [r2, #0x12]
	mov r1, sp
	strh r5, [r1, #0x14]
	movs r2, #0xff
	strh r2, [r1, #0x16]
	strh r2, [r1, #0x18]
	strh r5, [r1, #0x1a]
	strh r2, [r1, #0x1c]
	strh r5, [r1, #0x1e]
	strh r2, [r1, #0x20]
	strh r5, [r1, #0x22]
	strh r2, [r1, #0x24]
	strh r5, [r1, #0x26]
	adds r1, r6, #0
	mov r2, sp
	bl FUN_080155e4
	add sp, #0x28
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08015ce0
FUN_08015ce0: @ 0x08015CE0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x28
	ldr r6, [sp, #0x4c]
	ldr r7, [sp, #0x50]
	mov r4, sp
	movs r5, #0
	strh r1, [r4]
	mov r1, sp
	strh r2, [r1, #2]
	strh r3, [r1, #6]
	strh r6, [r1, #8]
	strh r7, [r1, #0xa]
	add r2, sp, #0x44
	ldrh r2, [r2]
	strh r2, [r1, #0xc]
	add r3, sp, #0x48
	ldrh r3, [r3]
	strh r3, [r1, #0xe]
	mov r2, sp
	movs r1, #0x3c
	strh r1, [r2, #0x10]
	movs r1, #8
	strh r1, [r2, #0x12]
	mov r1, sp
	ldrh r4, [r1, #0x3c]
	strh r4, [r1, #0x14]
	add r2, sp, #0x40
	ldrh r2, [r2]
	strh r2, [r1, #0x16]
	movs r2, #0xff
	strh r2, [r1, #0x18]
	strh r5, [r1, #0x1a]
	strh r2, [r1, #0x1c]
	strh r5, [r1, #0x1e]
	strh r2, [r1, #0x20]
	strh r5, [r1, #0x22]
	strh r2, [r1, #0x24]
	strh r5, [r1, #0x26]
	ldr r1, [sp, #0x54]
	mov r2, sp
	bl FUN_080155e4
	add sp, #0x28
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08015d3c
FUN_08015d3c: @ 0x08015D3C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x28
	mov r8, r0
	ldr r5, [sp, #0x40]
	ldr r6, [sp, #0x44]
	ldr r7, [sp, #0x48]
	mov r0, sp
	movs r4, #0
	strh r1, [r0]
	strh r2, [r0, #2]
	strh r3, [r0, #6]
	strh r5, [r0, #8]
	strh r6, [r0, #0xa]
	strh r7, [r0, #0xc]
	add r1, sp, #0x4c
	ldrh r1, [r1]
	strh r1, [r0, #0xe]
	mov r1, sp
	movs r0, #0x3c
	strh r0, [r1, #0x10]
	movs r0, #8
	strh r0, [r1, #0x12]
	mov r0, sp
	strh r4, [r0, #0x14]
	movs r1, #0xff
	strh r1, [r0, #0x16]
	strh r1, [r0, #0x18]
	strh r4, [r0, #0x1a]
	strh r1, [r0, #0x1c]
	strh r4, [r0, #0x1e]
	strh r1, [r0, #0x20]
	strh r4, [r0, #0x22]
	strh r1, [r0, #0x24]
	strh r4, [r0, #0x26]
	movs r0, #1
	mov r1, r8
	mov r2, sp
	bl FUN_080155e4
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08015d9c
FUN_08015d9c: @ 0x08015D9C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x28
	mov r8, r0
	ldr r5, [sp, #0x40]
	ldr r6, [sp, #0x44]
	ldr r7, [sp, #0x48]
	mov r0, sp
	movs r4, #0
	strh r1, [r0]
	strh r2, [r0, #2]
	strh r3, [r0, #6]
	strh r5, [r0, #8]
	strh r6, [r0, #0xa]
	strh r7, [r0, #0xc]
	add r1, sp, #0x4c
	ldrh r1, [r1]
	strh r1, [r0, #0xe]
	add r2, sp, #0x50
	ldrh r2, [r2]
	strh r2, [r0, #0x10]
	add r1, sp, #0x54
	ldrh r1, [r1]
	strh r1, [r0, #0x12]
	strh r4, [r0, #0x14]
	movs r1, #0xff
	strh r1, [r0, #0x16]
	strh r1, [r0, #0x18]
	strh r4, [r0, #0x1a]
	strh r1, [r0, #0x1c]
	strh r4, [r0, #0x1e]
	strh r1, [r0, #0x20]
	strh r4, [r0, #0x22]
	strh r1, [r0, #0x24]
	strh r4, [r0, #0x26]
	movs r0, #1
	mov r1, r8
	mov r2, sp
	bl FUN_080155e4
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08015dfc
FUN_08015dfc: @ 0x08015DFC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x30
	adds r7, r0, #0
	ldr r1, [sp, #0x44]
	ldr r5, [sp, #0x4c]
	ldr r6, [sp, #0x50]
	mov r0, sp
	movs r4, #0
	strh r2, [r0]
	strh r3, [r0, #2]
	strh r1, [r0, #6]
	strh r4, [r0, #8]
	strh r4, [r0, #0xa]
	add r1, sp, #0x48
	ldrh r1, [r1]
	strh r1, [r0, #0xc]
	strh r4, [r0, #0xe]
	ldr r2, _08015E74 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08015E78 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08015E7C @ =0x0203B400
	adds r0, r0, r2
	mov r1, sp
	ldrb r0, [r0]
	strh r0, [r1, #0x14]
	mov r0, sp
	strh r4, [r0, #0x16]
	strh r4, [r0, #0x12]
	strh r4, [r0, #0x10]
	strh r5, [r0, #0x18]
	strh r4, [r0, #0x1a]
	strh r6, [r0, #0x1c]
	strh r4, [r0, #0x1e]
	strh r5, [r0, #0x20]
	strh r4, [r0, #0x22]
	strh r6, [r0, #0x24]
	strh r4, [r0, #0x26]
	ldr r2, _08015E80 @ =0x085B0A08
	ldrh r0, [r0, #0x14]
	adds r0, #0xc0
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	ldr r1, [sp, #0x48]
	muls r0, r1, r0
	cmp r0, #0
	blt _08015E84
	asrs r1, r0, #0xc
	b _08015E8A
	.align 2, 0
_08015E74: .4byte 0x030046B8
_08015E78: .4byte 0x000003FF
_08015E7C: .4byte 0x0203B400
_08015E80: .4byte 0x085B0A08
_08015E84:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08015E8A:
	ldrh r0, [r7]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldrh r1, [r7, #2]
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp, #0x28]
	mov r0, sp
	ldrh r0, [r0, #0x14]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	ldr r3, [sp, #0x48]
	muls r0, r3, r0
	cmp r0, #0
	blt _08015EBE
	asrs r0, r0, #0xc
	b _08015EC4
_08015EBE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08015EC4:
	ldrh r2, [r7, #4]
	adds r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r3, _08015EE8 @ =0xFFFF0000
	add r1, sp, #0x28
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	movs r0, #1
	mov r2, sp
	bl FUN_080155e4
	add sp, #0x30
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08015EE8: .4byte 0xFFFF0000

	thumb_func_start FUN_08015eec
FUN_08015eec: @ 0x08015EEC
	push {r4, r5, lr}
	sub sp, #0x30
	movs r0, #0x6e
	movs r1, #1
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08015F44
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08015F3C @ =0xFFFF0000
	ldr r1, [sp, #0x28]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x28]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08015F40 @ =0x0000FFFF
	ldr r1, [sp, #0x28]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x28]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r2, sp, #0x28
	ldr r1, [r2, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r2, #4]
	adds r4, r2, #0
	b _08015F52
	.align 2, 0
_08015F3C: .4byte 0xFFFF0000
_08015F40: .4byte 0x0000FFFF
_08015F44:
	ldr r2, _08015FA4 @ =0xFFFF0000
	str r0, [sp, #0x28]
	add r1, sp, #0x28
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r4, r1, #0
_08015F52:
	movs r0, #0x74
	movs r1, #0
	bl Script_GetKeywordValue
	mov r1, sp
	strh r0, [r1]
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	mov r1, sp
	strh r0, [r1, #2]
	movs r0, #0x61
	movs r1, #0x40
	bl Script_GetKeywordValue
	mov r1, sp
	strh r0, [r1, #6]
	movs r0, #0x73
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _08015FA8
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #8]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0xa]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0xc]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0xe]
	b _08015FB2
	.align 2, 0
_08015FA4: .4byte 0xFFFF0000
_08015FA8:
	mov r0, sp
	strh r1, [r0, #8]
	strh r1, [r0, #0xa]
	strh r1, [r0, #0xc]
	strh r1, [r0, #0xe]
_08015FB2:
	movs r0, #0x64
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _08015FE0
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x10]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x12]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x14]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x16]
	b _08015FEA
_08015FE0:
	mov r0, sp
	strh r1, [r0, #0x10]
	strh r1, [r0, #0x12]
	strh r1, [r0, #0x14]
	strh r1, [r0, #0x16]
_08015FEA:
	movs r0, #0x63
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _08016038
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x18]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x1a]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x1c]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x1e]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x20]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x22]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x24]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x26]
	b _0801604C
_08016038:
	mov r0, sp
	movs r1, #0xff
	strh r1, [r0, #0x18]
	strh r2, [r0, #0x1a]
	strh r1, [r0, #0x1c]
	strh r2, [r0, #0x1e]
	strh r1, [r0, #0x20]
	strh r2, [r0, #0x22]
	strh r1, [r0, #0x24]
	strh r2, [r0, #0x26]
_0801604C:
	adds r0, r5, #0
	adds r1, r4, #0
	mov r2, sp
	bl FUN_080155e4
	add sp, #0x30
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08016060
FUN_08016060: @ 0x08016060
	ldr r1, _08016068 @ =0x03002B44
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08016068: .4byte 0x03002B44

	thumb_func_start FUN_0801606c
FUN_0801606c: @ 0x0801606C
	push {lr}
	ldrh r3, [r1, #0x3e]
	movs r1, #8
	ldr r0, [r0, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _0801607C
	lsls r3, r3, #1
_0801607C:
	ldrh r0, [r2, #0x16]
	subs r0, r0, r3
	strh r0, [r2, #0x16]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0801608C
	movs r0, #0
	strh r0, [r2, #0x16]
_0801608C:
	pop {r0}
	bx r0
_08016090:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_08016094
FUN_08016094: @ 0x08016094
	push {lr}
	adds r2, r0, #0
	movs r0, #0
	str r0, [r1, #0x78]
	ldr r0, [r2, #0x1c]
	str r0, [r1, #0x7c]
	cmp r0, #0
	beq _080160A6
	str r1, [r0, #0x78]
_080160A6:
	str r1, [r2, #0x1c]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080160b0
FUN_080160b0: @ 0x080160B0
	push {lr}
	ldr r2, [r1, #0x78]
	ldr r1, [r1, #0x7c]
	cmp r2, #0
	beq _080160BE
	str r1, [r2, #0x7c]
	b _080160C0
_080160BE:
	str r1, [r0, #0x1c]
_080160C0:
	cmp r1, #0
	beq _080160C6
	str r2, [r1, #0x78]
_080160C6:
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_080160cc
FUN_080160cc: @ 0x080160CC
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x3c
	bl FUN_0822a4e0
	ldr r0, _0801610C @ =0x03002B44
	ldr r0, [r0]
	cmp r0, #0
	beq _080160E4
	adds r1, r4, #0
	bl FUN_080160b0
_080160E4:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _080160F4
	bl FUN_08236424
	ldr r0, [r4, #0x18]
	bl Free
_080160F4:
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _080160FE
	bl Free
_080160FE:
	adds r0, r4, #0
	bl Free
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801610C: .4byte 0x03002B44

	thumb_func_start FUN_08016110
FUN_08016110: @ 0x08016110
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	mov r8, r3
	ldr r0, _0801618C @ =0x03002B44
	ldr r0, [r0]
	cmp r0, #0
	bne _08016136
	ldr r0, _08016190 @ =0x0000C0DB
	movs r1, #0
	bl FUN_08016660
	cmp r0, #0
	bne _08016136
	b _0801630A
_08016136:
	movs r0, #0x80
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	bne _08016144
	b _0801630A
_08016144:
	adds r0, r4, #0
	movs r1, #0x80
	bl ClearMemory
	strb r5, [r4]
	strb r6, [r4, #3]
	strh r7, [r4, #8]
	ldr r0, [sp, #0x34]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #0xc]
	str r1, [r4, #0x10]
	adds r6, r4, #0
	adds r6, #0xc
	ldrh r0, [r4, #0xc]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r7, r6, #0
	cmp r2, #0
	blt _08016186
	cmp r1, #0
	blt _08016186
	ldr r0, _08016194 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08016186
	ldr r0, _08016198 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0801619C
_08016186:
	movs r5, #0
	b _080161AA
	.align 2, 0
_0801618C: .4byte 0x03002B44
_08016190: .4byte 0x0000C0DB
_08016194: .4byte 0x030046A8
_08016198: .4byte 0x030046AC
_0801619C:
	ldr r0, _080161BC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_080161AA:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080161C0
	adds r0, #4
	b _080161CC
	.align 2, 0
_080161BC: .4byte 0x030046A4
_080161C0:
	ldr r0, _080161E0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080161CC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080161E4
	cmp r2, #2
	beq _080161E8
	b _080161EC
	.align 2, 0
_080161E0: .4byte 0x030046A4
_080161E4:
	ldrb r0, [r6, #4]
	b _080161EA
_080161E8:
	ldrb r0, [r6]
_080161EA:
	subs r1, r1, r0
_080161EC:
	strh r1, [r4, #0x14]
	mov r0, r8
	strh r0, [r4, #0x16]
	ldrb r0, [r4, #3]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _0801627C
	movs r0, #0x50
	bl Malloc
	str r0, [r4, #0x18]
	cmp r0, #0
	bne _0801620A
	b _0801630A
_0801620A:
	movs r1, #0x50
	bl ClearMemory
	ldr r2, _0801626C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x5a
	orrs r0, r3
	ldr r1, _08016270 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	ldr r0, [r4, #0x18]
	ldr r2, _08016274 @ =0x00004001
	movs r1, #0x10
	str r1, [sp]
	add r1, sp, #0xc
	str r1, [sp, #4]
	str r3, [sp, #8]
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r0, [r4, #0x18]
	ldr r1, _08016278 @ =FUN_0801606c
	adds r2, r4, #0
	bl FUN_0823651c
	ldr r0, [r4, #0x18]
	bl FUN_08236400
	ldr r0, [r4, #0x18]
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	b _0801627E
	.align 2, 0
_0801626C: .4byte 0xFFFF0000
_08016270: .4byte 0x0000FFFF
_08016274: .4byte 0x00004001
_08016278: .4byte FUN_0801606c
_0801627C:
	str r1, [r4, #0x18]
_0801627E:
	ldrb r0, [r4, #3]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _080162F8
	movs r0, #0x50
	bl Malloc
	str r0, [r4, #0x1c]
	cmp r0, #0
	beq _0801630A
	movs r1, #0x50
	bl ClearMemory
	movs r2, #0
	movs r3, #0x64
	add r0, sp, #0xc
	strh r3, [r0]
	adds r1, r0, #0
	movs r0, #0x78
	strh r0, [r1, #2]
	strh r3, [r1, #4]
	add r3, sp, #0x14
	strh r2, [r3]
	strh r2, [r3, #2]
	strh r2, [r3, #4]
	ldr r0, [r4, #0x1c]
	ldr r2, _080162F0 @ =0x00002001
	movs r1, #0x10
	str r1, [sp]
	add r1, sp, #0xc
	str r1, [sp, #4]
	str r3, [sp, #8]
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r0, [r4, #0x1c]
	ldr r1, _080162F4 @ =0x08016091
	adds r2, r4, #0
	bl FUN_0823651c
	ldr r0, [r4, #0x1c]
	movs r1, #0x32
	movs r2, #0x14
	bl FUN_082364f0
	ldr r0, [r4, #0x1c]
	bl FUN_08236400
	ldr r0, [r4, #0x1c]
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	b _080162FA
	.align 2, 0
_080162F0: .4byte 0x00002001
_080162F4: .4byte 0x08016091
_080162F8:
	str r1, [r4, #0x1c]
_080162FA:
	adds r5, r4, #0
	adds r5, #0x20
	ldr r1, _08016310 @ =0x0000863A
	adds r0, r5, #0
	bl FUN_0822b16c
	cmp r0, #0
	bne _08016314
_0801630A:
	movs r0, #1
	rsbs r0, r0, #0
	b _0801637A
	.align 2, 0
_08016310: .4byte 0x0000863A
_08016314:
	adds r0, r4, #0
	adds r0, #0x3c
	adds r1, r5, #0
	movs r2, #1
	bl FUN_0822a470
	adds r1, r4, #0
	adds r1, #0x43
	movs r6, #0
	movs r0, #2
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x68
	ldr r1, _08016358 @ =0x03002B44
	ldr r1, [r1]
	ldr r1, [r1, #0x18]
	str r6, [sp]
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	ldrb r1, [r4]
	ldr r0, _0801635C @ =0x00000113
	adds r1, r1, r0
	adds r0, r5, #0
	bl FUN_0822b20c
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08016360
	movs r0, #1
	strb r0, [r4, #2]
	strh r6, [r4, #6]
	b _08016366
	.align 2, 0
_08016358: .4byte 0x03002B44
_0801635C: .4byte 0x00000113
_08016360:
	strb r6, [r4, #2]
	strh r6, [r4, #6]
	movs r0, #1
_08016366:
	strb r0, [r4, #1]
	movs r0, #0
	strb r0, [r4, #5]
	str r0, [r4, #0x78]
	str r0, [r4, #0x7c]
	ldr r0, _08016388 @ =0x03002B44
	ldr r0, [r0]
	adds r1, r4, #0
	bl FUN_08016094
_0801637A:
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08016388: .4byte 0x03002B44

	thumb_func_start FUN_0801638c
FUN_0801638c: @ 0x0801638C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	movs r0, #0x74
	movs r1, #0
	bl Script_GetKeywordValue
	mov r8, r0
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x65
	movs r1, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x6c
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08016404
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080163FC @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08016400 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	b _0801640E
	.align 2, 0
_080163FC: .4byte 0xFFFF0000
_08016400: .4byte 0x0000FFFF
_08016404:
	ldr r1, _0801642C @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_0801640E:
	add r0, sp, #4
	str r0, [sp]
	mov r0, r8
	adds r1, r7, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_08016110
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801642C: .4byte 0xFFFF0000

	thumb_func_start FUN_08016430
FUN_08016430: @ 0x08016430
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #6]
	adds r1, r0, #1
	strh r1, [r2, #6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r2, #8]
	cmp r0, r1
	bls _0801644E
	movs r1, #1
	movs r0, #0
	strb r1, [r2, #2]
	strh r0, [r2, #6]
	strb r1, [r2, #1]
_0801644E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08016454
FUN_08016454: @ 0x08016454
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _08016482
	movs r2, #0
	strb r2, [r4, #1]
	ldr r0, [r4, #0x3c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x3c]
	adds r0, r4, #0
	adds r0, #0x68
	ldr r1, _08016498 @ =0x03002B44
	ldr r1, [r1]
	ldr r1, [r1, #0x18]
	str r2, [sp]
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
_08016482:
	movs r1, #0x16
	ldrsh r0, [r4, r1]
	cmp r0, #0
	ble _08016490
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _0801649C
_08016490:
	movs r0, #1
	strb r0, [r4, #5]
	b _080164C8
	.align 2, 0
_08016498: .4byte 0x03002B44
_0801649C:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _080164AC
	adds r1, r4, #0
	adds r1, #0xc
	movs r2, #0
	bl FUN_082364c4
_080164AC:
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _080164C2
	adds r1, r4, #0
	adds r1, #0xc
	movs r2, #0
	bl FUN_082364c4
	ldr r0, [r4, #0x1c]
	bl FUN_08236400
_080164C2:
	ldrh r0, [r4, #6]
	adds r0, #1
	strh r0, [r4, #6]
_080164C8:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080164d0
FUN_080164d0: @ 0x080164D0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r4, [r0, #0x1c]
	cmp r4, #0
	bne _080164E0
	b _08016602
_080164E0:
	movs r0, #1
	mov r8, r0
	movs r1, #2
	mov sb, r1
_080164E8:
	ldr r7, [r4, #0x7c]
	ldrb r0, [r4, #5]
	cmp r0, #0
	beq _080164F8
	adds r0, r4, #0
	bl FUN_080160cc
	b _080165FA
_080164F8:
	adds r6, r4, #0
	adds r6, #0x3c
	adds r3, r4, #0
	adds r3, #0x68
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r4, #0x68]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r3, #4]
	mov r2, r8
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r1, r8
	ands r0, r1
	cmp r2, r0
	beq _0801652C
	ldr r0, [r4, #0x3c]
	movs r1, #4
	orrs r0, r1
	b _08016534
_0801652C:
	ldr r0, [r4, #0x3c]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08016534:
	str r0, [r4, #0x3c]
	ldrb r0, [r3, #4]
	mov r1, sb
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sb
	ands r0, r2
	cmp r1, r0
	beq _08016558
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _08016560
_08016558:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08016560:
	str r0, [r6]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r5, _08016598 @ =0x0000FFFF
	adds r2, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r3, #7]
	cmp r0, r5
	blo _080165DE
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080165A2
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _0801659C
	ldrb r0, [r3, #5]
	subs r0, #1
	strh r0, [r3, #8]
	movs r2, #1
	b _080165B8
	.align 2, 0
_08016598: .4byte 0x0000FFFF
_0801659C:
	subs r0, #1
	strh r0, [r3, #8]
	b _080165B6
_080165A2:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _080165B6
	strh r1, [r3, #8]
	movs r2, #1
	b _080165B8
_080165B6:
	movs r2, #0
_080165B8:
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r3, #6]
	ldrb r1, [r3, #6]
	ldrh r0, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080165E0
	mov r5, r8
	strb r5, [r3, #7]
	b _080165E0
_080165DE:
	movs r2, #0
_080165E0:
	strb r2, [r4, #4]
	ldr r0, [r4, #0xc]
	ldr r1, [r4, #0x10]
	str r0, [r4, #0x58]
	str r1, [r4, #0x5c]
	ldr r1, _08016610 @ =0x085AA918
	ldrb r0, [r4, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080165FA:
	adds r4, r7, #0
	cmp r4, #0
	beq _08016602
	b _080164E8
_08016602:
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08016610: .4byte 0x085AA918

	thumb_func_start FUN_08016614
FUN_08016614: @ 0x08016614
	push {r4, lr}
	ldr r0, [r0, #0x1c]
	cmp r0, #0
	beq _08016628
_0801661C:
	ldr r4, [r0, #0x7c]
	bl FUN_080160cc
	adds r0, r4, #0
	cmp r0, #0
	bne _0801661C
_08016628:
	ldr r1, _08016634 @ =0x03002B44
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08016634: .4byte 0x03002B44

	thumb_func_start FUN_08016638
FUN_08016638: @ 0x08016638
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08016654 @ =0x03002B44
	str r4, [r0]
	ldr r0, _08016658 @ =0x0000922E
	ldr r1, _0801665C @ =0x0000931E
	bl GetFile
	str r0, [r4, #0x18]
	movs r0, #0
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08016654: .4byte 0x03002B44
_08016658: .4byte 0x0000922E
_0801665C: .4byte 0x0000931E

	thumb_func_start FUN_08016660
FUN_08016660: @ 0x08016660
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #8
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08016698
	ldr r1, _08016690 @ =FUN_080164d0
	ldr r2, _08016694 @ =FUN_08016614
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08016638
	cmp r0, #0
	bge _08016698
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801669A
	.align 2, 0
_08016690: .4byte FUN_080164d0
_08016694: .4byte FUN_08016614
_08016698:
	adds r0, r4, #0
_0801669A:
	pop {r4, r5}
	pop {r1}
	bx r1
_080166A0:
	.byte 0x01, 0x49, 0x00, 0x20, 0x08, 0x60, 0x70, 0x47, 0x64, 0x00, 0x00, 0x03

	thumb_func_start FUN_080166ac
FUN_080166ac: @ 0x080166AC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r4, r0, #0
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	ldr r0, _0801672C @ =0x03000064
	ldr r0, [r0]
	cmp r0, #0
	bne _080166D6
	movs r0, #0
	movs r1, #0
	bl FUN_08016ba4
	cmp r0, #0
	bne _080166D6
	b _08016862
_080166D6:
	movs r2, #0
	ldr r3, _0801672C @ =0x03000064
	movs r1, #0x24
_080166DC:
	ldr r0, [r3]
	adds r5, r0, r1
	ldrb r0, [r5]
	cmp r0, #0
	beq _080166E8
	b _08016854
_080166E8:
	movs r0, #1
	strb r0, [r5]
	strb r4, [r5, #1]
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bls _080166FA
	movs r0, #8
	strb r0, [r5, #1]
_080166FA:
	movs r0, #0
	mov sl, r0
	ldrb r1, [r5, #1]
	cmp sl, r1
	blt _08016706
	b _08016846
_08016706:
	ldr r6, _08016730 @ =0x030046B8
	ldr r2, _08016734 @ =0x000003FF
	mov sb, r2
	movs r3, #0x38
	adds r3, r3, r5
	mov r8, r3
	adds r7, r5, #0
	adds r7, #0x10
	adds r4, r5, #4
_08016718:
	movs r0, #1
	strb r0, [r4]
	ldr r0, [sp, #0xc]
	cmp r0, #0
	bne _08016738
	mov r1, sp
	ldrb r1, [r1, #8]
	strb r1, [r4, #1]
	b _08016756
	.align 2, 0
_0801672C: .4byte 0x03000064
_08016730: .4byte 0x030046B8
_08016734: .4byte 0x000003FF
_08016738:
	ldr r0, [r6]
	adds r0, #1
	mov r2, sb
	ands r0, r2
	str r0, [r6]
	lsls r0, r0, #1
	ldr r3, _08016764 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #0xc]
	bl Mod
	ldr r1, [sp, #8]
	adds r0, r1, r0
	strb r0, [r4, #1]
_08016756:
	ldr r2, [sp, #0x34]
	cmp r2, #0
	bne _08016768
	mov r3, sp
	ldrh r3, [r3, #0x30]
	strh r3, [r4, #2]
	b _08016786
	.align 2, 0
_08016764: .4byte 0x0203B400
_08016768:
	ldr r0, [r6]
	adds r0, #1
	mov r1, sb
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _08016790 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, [sp, #0x34]
	bl Mod
	ldr r3, [sp, #0x30]
	adds r0, r3, r0
	strh r0, [r4, #2]
_08016786:
	ldr r0, [sp, #0x3c]
	cmp r0, #0
	bne _08016794
	ldr r2, [sp, #0x38]
	b _080167B0
	.align 2, 0
_08016790: .4byte 0x0203B400
_08016794:
	ldr r0, [r6]
	adds r0, #1
	mov r1, sb
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _080167DC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, [sp, #0x3c]
	bl Mod
	ldr r3, [sp, #0x38]
	adds r2, r3, r0
_080167B0:
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r3, _080167E0 @ =0x085B0A08
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r4, #4]
	ands r2, r1
	lsls r0, r2, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r4, #8]
	ldr r0, [sp, #0x44]
	cmp r0, #0
	bne _080167E4
	add r1, sp, #0x40
	ldrh r1, [r1]
	strh r1, [r4, #6]
	b _08016802
	.align 2, 0
_080167DC: .4byte 0x0203B400
_080167E0: .4byte 0x085B0A08
_080167E4:
	ldr r0, [r6]
	adds r0, #1
	mov r2, sb
	ands r0, r2
	str r0, [r6]
	lsls r0, r0, #1
	ldr r3, _0801684C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #0x44]
	bl Mod
	ldr r1, [sp, #0x40]
	adds r0, r1, r0
	strh r0, [r4, #6]
_08016802:
	ldr r2, [sp, #4]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x24]
	str r1, [r4, #0x28]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_0822da50
	ldr r0, [r4, #0xc]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0xc]
	ldr r0, _08016850 @ =0x03000064
	ldr r0, [r0]
	ldr r1, [r0, #0x20]
	movs r0, #0
	str r0, [sp]
	mov r0, r8
	movs r2, #3
	movs r3, #0
	bl FUN_08236fac
	movs r3, #0x44
	add r8, r3
	adds r7, #0x44
	adds r4, #0x44
	movs r0, #1
	add sl, r0
	ldrb r1, [r5, #1]
	cmp sl, r1
	bge _08016846
	b _08016718
_08016846:
	movs r0, #0
	b _08016866
	.align 2, 0
_0801684C: .4byte 0x0203B400
_08016850: .4byte 0x03000064
_08016854:
	movs r0, #0x89
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r2, #1
	cmp r2, #5
	bgt _08016862
	b _080166DC
_08016862:
	movs r0, #1
	rsbs r0, r0, #0
_08016866:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08016878
FUN_08016878: @ 0x08016878
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	movs r0, #0
	str r0, [sp]
	mov sl, r0
	ldrb r1, [r7, #1]
	cmp sl, r1
	blt _08016894
	b _08016A3E
_08016894:
	adds r2, r7, #5
	mov sb, r2
	movs r3, #0x38
	adds r3, r3, r7
	mov r8, r3
	adds r0, r7, #6
	str r0, [sp, #4]
	adds r4, r7, #0
	adds r4, #8
_080168A6:
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #0
	bne _080168B0
	b _08016A1C
_080168B0:
	ldr r2, [sp]
	adds r2, #1
	str r2, [sp]
	movs r3, #0
	ldrsh r1, [r4, r3]
	ldr r2, [sp, #4]
	movs r3, #0
	ldrsh r0, [r2, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080168CA
	asrs r1, r0, #0xc
	b _080168D0
_080168CA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080168D0:
	ldrh r0, [r4, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #0x20]
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #0x22]
	adds r0, r0, r1
	strh r0, [r4, #0x22]
	movs r2, #4
	ldrsh r1, [r4, r2]
	ldr r3, [sp, #4]
	movs r2, #0
	ldrsh r0, [r3, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080168F2
	asrs r1, r0, #0xc
	b _080168F8
_080168F2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080168F8:
	ldrh r0, [r4, #0x24]
	adds r0, r0, r1
	strh r0, [r4, #0x24]
	ldrh r0, [r4, #2]
	subs r0, #2
	strh r0, [r4, #2]
	mov r0, r8
	movs r1, #0x10
	bl FUN_08237098
	ldr r0, _08016950 @ =0x03000064
	ldr r0, [r0]
	ldr r3, [r0, #0x1c]
	mov r5, r8
	ldrh r0, [r4, #0x38]
	lsls r0, r0, #1
	ldr r1, [r4, #0x30]
	adds r6, r1, r0
	ldrh r2, [r6]
	lsrs r2, r2, #6
	ldrb r1, [r4, #0x12]
	lsrs r1, r1, #3
	ldrb r0, [r4, #0x13]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r4, #0x10]
	ldrb r0, [r5, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r6]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r3, #1
	ands r0, r3
	cmp r2, r0
	beq _08016954
	ldr r0, [r4, #8]
	movs r1, #4
	orrs r0, r1
	b _0801695C
	.align 2, 0
_08016950: .4byte 0x03000064
_08016954:
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0801695C:
	str r0, [r4, #8]
	ldrb r0, [r5, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08016980
	ldr r0, [r4, #8]
	movs r1, #8
	orrs r0, r1
	b _08016988
_08016980:
	ldr r0, [r4, #8]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08016988:
	str r0, [r4, #8]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r5, #0xe]
	ldr r3, _080169C0 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r5, #7]
	cmp r0, r3
	blo _080169EA
	strh r1, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080169C4
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _080169B8
	ldrb r0, [r5, #5]
_080169B8:
	subs r0, #1
	strh r0, [r5, #8]
	b _080169D4
	.align 2, 0
_080169C0: .4byte 0x0000FFFF
_080169C4:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _080169D4
	strh r1, [r5, #8]
_080169D4:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
_080169EA:
	mov r3, sb
	ldrb r0, [r3]
	adds r1, r0, #0
	adds r2, r0, #0
	cmp r1, #8
	bls _080169FE
	ldrh r0, [r4, #0x38]
	cmp r0, #5
	bne _08016A06
	b _08016A02
_080169FE:
	cmp r1, #8
	bne _08016A06
_08016A02:
	movs r0, #0
	strh r0, [r4, #0x38]
_08016A06:
	subs r0, r2, #1
	mov r1, sb
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _08016A24
	ldr r0, [r4, #8]
	movs r2, #1
	orrs r0, r2
	b _08016A22
_08016A1C:
	ldr r0, [r4, #8]
	movs r3, #1
	orrs r0, r3
_08016A22:
	str r0, [r4, #8]
_08016A24:
	movs r0, #0x44
	add sb, r0
	add r8, r0
	ldr r1, [sp, #4]
	adds r1, #0x44
	str r1, [sp, #4]
	adds r4, #0x44
	movs r2, #1
	add sl, r2
	ldrb r3, [r7, #1]
	cmp sl, r3
	bge _08016A3E
	b _080168A6
_08016A3E:
	ldr r0, [sp]
	cmp r0, #0
	bne _08016A6A
	strb r0, [r7]
	movs r2, #0
	mov sl, r2
	ldrb r3, [r7, #1]
	cmp sl, r3
	bge _08016A66
	adds r4, r7, #0
	adds r4, #0x10
_08016A54:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x44
	movs r0, #1
	add sl, r0
	ldrb r1, [r7, #1]
	cmp sl, r1
	blt _08016A54
_08016A66:
	movs r0, #0
	strb r0, [r7, #1]
_08016A6A:
	movs r0, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08016a7c
FUN_08016a7c: @ 0x08016A7C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r7, _08016AB0 @ =0x03000064
	movs r5, #0x24
	movs r4, #5
_08016A86:
	ldr r0, [r7]
	adds r1, r0, r5
	ldrb r0, [r1]
	cmp r0, #0
	beq _08016A96
	adds r0, r1, #0
	bl FUN_08016878
_08016A96:
	movs r0, #0x89
	lsls r0, r0, #2
	adds r5, r5, r0
	subs r4, #1
	cmp r4, #0
	bge _08016A86
	ldr r0, [r6, #0x18]
	adds r0, #1
	str r0, [r6, #0x18]
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08016AB0: .4byte 0x03000064

	thumb_func_start FUN_08016ab4
FUN_08016ab4: @ 0x08016AB4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r1, #0
_08016ABE:
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0x24
	mov r2, r8
	adds r5, r2, r0
	ldrb r0, [r5]
	adds r7, r1, #1
	cmp r0, #0
	beq _08016AF2
	movs r6, #0
	ldrb r0, [r5, #1]
	cmp r6, r0
	bge _08016AF2
	adds r4, r5, #0
	adds r4, #0x10
_08016AE2:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x44
	adds r6, #1
	ldrb r2, [r5, #1]
	cmp r6, r2
	blt _08016AE2
_08016AF2:
	adds r1, r7, #0
	cmp r1, #5
	ble _08016ABE
	movs r1, #0
	ldr r0, _08016B0C @ =0x03000064
	str r1, [r0]
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08016B0C: .4byte 0x03000064

	thumb_func_start FUN_08016b10
FUN_08016b10: @ 0x08016B10
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _08016B94 @ =0x03000064
	str r7, [r0]
	ldr r0, _08016B98 @ =0x00001C1A
	bl GetParticleGroup
	str r0, [r7, #0x1c]
	ldr r0, _08016B9C @ =0x0000922E
	ldr r1, _08016BA0 @ =0x0000D1B8
	bl GetFile
	str r0, [r7, #0x20]
	movs r1, #0
	mov sb, r1
_08016B36:
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0x24
	adds r0, r7, r0
	mov r2, sb
	strb r2, [r0]
	adds r1, #1
	mov r8, r1
	adds r5, r0, #0
	adds r5, #0x38
	adds r4, r0, #0
	adds r4, #0x10
	movs r6, #7
_08016B56:
	ldr r1, [r7, #0x1c]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0822da70
	ldr r1, [r7, #0x20]
	mov r0, sb
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #3
	movs r3, #0
	bl FUN_08236fac
	adds r5, #0x44
	adds r4, #0x44
	subs r6, #1
	cmp r6, #0
	bge _08016B56
	mov r1, r8
	cmp r1, #5
	ble _08016B36
	movs r0, #0
	str r0, [r7, #0x18]
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08016B94: .4byte 0x03000064
_08016B98: .4byte 0x00001C1A
_08016B9C: .4byte 0x0000922E
_08016BA0: .4byte 0x0000D1B8

	thumb_func_start FUN_08016ba4
FUN_08016ba4: @ 0x08016BA4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08016BDC @ =0x03000064
	ldr r0, [r0]
	cmp r0, #0
	bne _08016BEE
	ldr r1, _08016BE0 @ =0x00000CFC
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08016BEC
	ldr r1, _08016BE4 @ =FUN_08016a7c
	ldr r2, _08016BE8 @ =FUN_08016ab4
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08016b10
	cmp r0, #0
	bge _08016BEC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08016BEE
	.align 2, 0
_08016BDC: .4byte 0x03000064
_08016BE0: .4byte 0x00000CFC
_08016BE4: .4byte FUN_08016a7c
_08016BE8: .4byte FUN_08016ab4
_08016BEC:
	adds r0, r4, #0
_08016BEE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08016bf4
FUN_08016bf4: @ 0x08016BF4
	ldr r1, _08016BFC @ =0x03000068
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08016BFC: .4byte 0x03000068

	thumb_func_start FUN_08016c00
FUN_08016c00: @ 0x08016C00
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r0, #0
	mov ip, r0
	movs r6, #0
	movs r1, #1
	mov r8, r1
_08016C12:
	adds r0, r4, #0
	adds r0, #0x2c
	adds r5, r0, r6
	movs r0, #0
	ldrsb r0, [r5, r0]
	lsls r1, r6, #2
	lsls r0, r1
	mov r1, ip
	orrs r1, r0
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	ldrb r0, [r4, #0x1b]
	asrs r0, r6
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _08016C82
	lsls r2, r6, #1
	adds r0, r4, #0
	adds r0, #0x1c
	adds r3, r0, r2
	ldrh r0, [r3]
	adds r0, #1
	movs r7, #0
	strh r0, [r3]
	adds r1, r4, #0
	adds r1, #0x24
	adds r1, r1, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _08016C82
	strh r7, [r3]
	adds r0, r4, #0
	adds r0, #0x30
	adds r0, r0, r6
	ldrb r3, [r5]
	movs r1, #0
	ldrsb r1, [r5, r1]
	ldrb r2, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	blt _08016C7E
	strb r2, [r5]
	mov r1, r8
	lsls r1, r6
	ldrb r0, [r4, #0x1b]
	bics r0, r1
	strb r0, [r4, #0x1b]
	b _08016C82
_08016C7E:
	adds r0, r3, #1
	strb r0, [r5]
_08016C82:
	adds r6, #1
	cmp r6, #3
	ble _08016C12
	ldrb r1, [r4, #0x19]
	ldrb r2, [r4, #0x1a]
	mov r0, ip
	bl FUN_0822ece4
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	bne _08016C9A
	strb r0, [r4, #0x18]
_08016C9A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08016ca4
FUN_08016ca4: @ 0x08016CA4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r0, #0
	mov ip, r0
	movs r6, #0
	movs r1, #1
	mov r8, r1
_08016CB6:
	adds r0, r4, #0
	adds r0, #0x2c
	adds r5, r0, r6
	movs r0, #0
	ldrsb r0, [r5, r0]
	lsls r1, r6, #2
	lsls r0, r1
	mov r1, ip
	orrs r1, r0
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	ldrb r0, [r4, #0x1b]
	asrs r0, r6
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _08016D26
	lsls r2, r6, #1
	adds r0, r4, #0
	adds r0, #0x1c
	adds r3, r0, r2
	ldrh r0, [r3]
	adds r0, #1
	movs r7, #0
	strh r0, [r3]
	adds r1, r4, #0
	adds r1, #0x24
	adds r1, r1, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _08016D26
	strh r7, [r3]
	adds r0, r4, #0
	adds r0, #0x30
	adds r0, r0, r6
	ldrb r3, [r5]
	movs r1, #0
	ldrsb r1, [r5, r1]
	ldrb r2, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bgt _08016D22
	strb r2, [r5]
	mov r1, r8
	lsls r1, r6
	ldrb r0, [r4, #0x1b]
	bics r0, r1
	strb r0, [r4, #0x1b]
	b _08016D26
_08016D22:
	subs r0, r3, #1
	strb r0, [r5]
_08016D26:
	adds r6, #1
	cmp r6, #3
	ble _08016CB6
	ldrb r1, [r4, #0x19]
	ldrb r2, [r4, #0x1a]
	mov r0, ip
	bl FUN_0822ece4
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	bne _08016D3E
	strb r0, [r4, #0x18]
_08016D3E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08016d48
FUN_08016d48: @ 0x08016D48
	push {lr}
	adds r3, r0, #0
	ldr r2, _08016D64 @ =0x085AA920
	ldrb r1, [r3, #0x18]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	cmp r1, #0
	beq _08016D5E
	bl _call_via_r1
_08016D5E:
	pop {r1}
	bx r1
	.align 2, 0
_08016D64: .4byte 0x085AA920

	thumb_func_start FUN_08016d68
FUN_08016d68: @ 0x08016D68
	push {lr}
	bl FUN_0822ed10
	ldr r1, _08016D78 @ =0x03000068
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_08016D78: .4byte 0x03000068

	thumb_func_start FUN_08016d7c
FUN_08016d7c: @ 0x08016D7C
	push {r4, r5, r6, lr}
	adds r1, r0, #0
	ldr r2, _08016DB8 @ =0x03000068
	str r1, [r2]
	movs r2, #0
	strb r2, [r1, #0x18]
	strb r2, [r1, #0x19]
	strb r2, [r1, #0x1a]
	strb r2, [r1, #0x1b]
	movs r4, #0
	movs r6, #0
	movs r5, #0
	adds r3, r1, #0
	adds r3, #0x1c
	adds r2, r1, #0
	adds r2, #0x2c
	adds r1, #0x24
_08016D9E:
	strh r5, [r3]
	strh r5, [r1]
	strb r6, [r2]
	strb r6, [r2, #4]
	adds r3, #2
	adds r2, #1
	adds r1, #2
	adds r4, #1
	cmp r4, #3
	ble _08016D9E
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08016DB8: .4byte 0x03000068

	thumb_func_start FUN_08016dbc
FUN_08016dbc: @ 0x08016DBC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08016DF8 @ =0x03000068
	ldr r0, [r0]
	cmp r0, #0
	bne _08016E06
	movs r0, #9
	movs r1, #0x34
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08016E04
	ldr r1, _08016DFC @ =FUN_08016d48
	ldr r2, _08016E00 @ =FUN_08016d68
	bl SetEntityRoutine
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08016d7c
	cmp r0, #0
	bge _08016E04
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08016E06
	.align 2, 0
_08016DF8: .4byte 0x03000068
_08016DFC: .4byte FUN_08016d48
_08016E00: .4byte FUN_08016d68
_08016E04:
	adds r0, r4, #0
_08016E06:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08016e0c
FUN_08016e0c: @ 0x08016E0C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	mov sl, r3
	ldr r0, _08016E3C @ =0x03000068
	ldr r0, [r0]
	cmp r0, #0
	bne _08016E40
	movs r0, #0
	movs r1, #0
	bl FUN_08016dbc
	adds r1, r0, #0
	cmp r1, #0
	bne _08016E42
	movs r0, #1
	rsbs r0, r0, #0
	b _08016E9E
	.align 2, 0
_08016E3C: .4byte 0x03000068
_08016E40:
	adds r1, r0, #0
_08016E42:
	strb r4, [r1, #0x18]
	strb r5, [r1, #0x19]
	strb r6, [r1, #0x1a]
	movs r0, #0xf
	strb r0, [r1, #0x1b]
	movs r3, #0
	movs r0, #0x24
	adds r0, r0, r1
	mov r8, r0
	movs r0, #0x2c
	adds r0, r0, r1
	mov ip, r0
	adds r7, r1, #0
	adds r7, #0x30
	movs r6, #0xf
	ldr r5, [sp, #0x24]
	adds r4, r1, #0
	adds r4, #0x1c
	mov sb, r3
_08016E68:
	lsls r1, r3, #1
	mov r0, sb
	strh r0, [r4]
	add r1, r8
	ldrh r0, [r5]
	strh r0, [r1]
	mov r1, ip
	adds r2, r1, r3
	mov r1, sl
	adds r0, r1, r3
	ldrb r1, [r0]
	adds r0, r6, #0
	ands r0, r1
	strb r0, [r2]
	adds r2, r7, r3
	ldr r1, [sp, #0x20]
	adds r0, r1, r3
	ldrb r1, [r0]
	adds r0, r6, #0
	ands r0, r1
	strb r0, [r2]
	adds r5, #2
	adds r4, #2
	adds r3, #1
	cmp r3, #3
	ble _08016E68
	movs r0, #0
_08016E9E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08016eac
FUN_08016eac: @ 0x08016EAC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	mov sl, r0
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	mov sb, r0
	movs r0, #0x74
	movs r1, #0
	bl Script_GetKeywordValue
	mov r8, r0
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _08016EFA
	movs r4, #0
	add r6, sp, #0xc
	add r7, sp, #0x10
_08016EE6:
	bl Script_GetValue
	mov r1, sp
	adds r1, r1, r4
	adds r1, #8
	strb r0, [r1]
	adds r4, #1
	cmp r4, #3
	ble _08016EE6
	b _08016F0E
_08016EFA:
	add r6, sp, #0xc
	add r7, sp, #0x10
	movs r1, #0
	mov r0, sp
	adds r0, #0xb
_08016F04:
	strb r1, [r0]
	subs r0, #1
	add r2, sp, #8
	cmp r0, r2
	bge _08016F04
_08016F0E:
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _08016F2A
	movs r4, #0
_08016F1A:
	bl Script_GetValue
	adds r1, r6, r4
	strb r0, [r1]
	adds r4, #1
	cmp r4, #3
	ble _08016F1A
	b _08016F38
_08016F2A:
	adds r1, r6, #0
	movs r2, #0
	adds r0, r6, #3
_08016F30:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _08016F30
_08016F38:
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _08016F56
	adds r5, r7, #0
	movs r4, #3
_08016F46:
	bl Script_GetValue
	strh r0, [r5]
	adds r5, #2
	subs r4, #1
	cmp r4, #0
	bge _08016F46
	b _08016F64
_08016F56:
	adds r1, r7, #0
	movs r2, #0
	adds r0, r7, #6
_08016F5C:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _08016F5C
_08016F64:
	str r6, [sp]
	str r7, [sp, #4]
	mov r0, sl
	mov r1, sb
	mov r2, r8
	add r3, sp, #8
	bl FUN_08016e0c
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08016f84
FUN_08016f84: @ 0x08016F84
	push {r4, r5, r6, r7, lr}
	ldr r0, _08016FD4 @ =0x03000068
	ldr r4, [r0]
	cmp r4, #0
	beq _08016FCC
	bl FUN_0822ed10
	movs r0, #0
	strb r0, [r4, #0x18]
	strb r0, [r4, #0x19]
	strb r0, [r4, #0x1a]
	strb r0, [r4, #0x1b]
	movs r3, #0
	movs r6, #0
	movs r5, #0
	adds r2, r4, #0
	adds r2, #0x1c
	movs r0, #0x2c
	adds r0, r0, r4
	mov ip, r0
	adds r7, r4, #0
	adds r7, #0x30
	adds r1, r4, #0
	adds r1, #0x24
_08016FB4:
	strh r5, [r2]
	strh r5, [r1]
	mov r4, ip
	adds r0, r4, r3
	strb r6, [r0]
	adds r0, r7, r3
	strb r6, [r0]
	adds r2, #2
	adds r1, #2
	adds r3, #1
	cmp r3, #3
	ble _08016FB4
_08016FCC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08016FD4: .4byte 0x03000068

	thumb_func_start FUN_08016fd8
FUN_08016fd8: @ 0x08016FD8
	ldr r1, _08016FE0 @ =0x0300006C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08016FE0: .4byte 0x0300006C

	thumb_func_start FUN_08016fe4
FUN_08016fe4: @ 0x08016FE4
	movs r1, #0
	str r1, [r0]
	movs r2, #1
	strb r2, [r0, #4]
	strb r1, [r0, #5]
	strb r1, [r0, #6]
	str r1, [r0, #0xc]
	ldr r1, [r0, #0x2c]
	orrs r1, r2
	subs r2, #4
	ands r1, r2
	str r1, [r0, #0x2c]
	bx lr
	.align 2, 0

	thumb_func_start FUN_08017000
FUN_08017000: @ 0x08017000
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r6, #0x24
	adds r5, r0, #0
	adds r5, #0x44
	adds r7, r0, #0
	adds r7, #0x18
	ldrh r0, [r0, #0x18]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0801702A
	asrs r0, r0, #8
	b _08017030
_0801702A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08017030:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08017042
	asrs r0, r0, #8
	b _08017048
_08017042:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08017048:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r7, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0801705C
	asrs r0, r0, #8
	b _08017062
_0801705C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08017062:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08017094 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	ldrh r0, [r6, #0x20]
	subs r0, #8
	strh r0, [r6, #0x20]
	ldrh r0, [r6, #0x22]
	subs r0, #8
	strh r0, [r6, #0x22]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08017094: .4byte 0x030047C8

	thumb_func_start FUN_08017098
FUN_08017098: @ 0x08017098
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #5]
	cmp r0, #0
	beq _080170B0
	movs r0, #0
	strb r0, [r4, #5]
	ldr r0, [r4, #0x2c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x2c]
_080170B0:
	ldr r0, [r4, #0xc]
	cmp r0, #2
	bhi _080170BC
	ldrh r0, [r4, #0x1a]
	adds r0, #0x10
	b _080170C0
_080170BC:
	ldrh r0, [r4, #0x1a]
	subs r0, #0x10
_080170C0:
	strh r0, [r4, #0x1a]
	adds r0, r4, #0
	bl FUN_08017000
	ldr r0, [r4, #0xc]
	cmp r0, #3
	bls _080170DA
	movs r0, #1
	movs r1, #0
	strb r0, [r4, #4]
	strb r0, [r4, #5]
	str r1, [r4, #0xc]
	b _080170DE
_080170DA:
	adds r0, #1
	str r0, [r4, #0xc]
_080170DE:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080170e4
FUN_080170e4: @ 0x080170E4
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #5]
	cmp r0, #0
	beq _080170FC
	movs r0, #0
	strb r0, [r4, #5]
	ldr r0, [r4, #0x2c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x2c]
_080170FC:
	adds r0, r4, #0
	bl FUN_08017000
	ldr r0, [r4, #0xc]
	ldrh r1, [r4, #0x10]
	cmp r0, r1
	blo _08017156
	ldrb r2, [r4, #7]
	cmp r2, #0
	bne _08017134
	ldrb r0, [r4, #0x12]
	ldr r1, _08017124 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08017128
	movs r0, #6
	b _0801712A
	.align 2, 0
_08017124: .4byte 0x03002BE0
_08017128:
	movs r0, #5
_0801712A:
	strb r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #5]
	str r2, [r4, #0xc]
	b _0801715A
_08017134:
	cmp r2, #1
	bne _08017144
	movs r0, #2
	movs r1, #0
	strb r0, [r4, #4]
	strb r2, [r4, #5]
	str r1, [r4, #0xc]
	b _0801715A
_08017144:
	cmp r2, #3
	bne _0801715A
	movs r0, #6
	movs r1, #0
	strb r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #5]
	str r1, [r4, #0xc]
	b _0801715A
_08017156:
	adds r0, #1
	str r0, [r4, #0xc]
_0801715A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08017160
FUN_08017160: @ 0x08017160
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r4, r1, #0
	mov r8, r2
	adds r5, r4, #0
	adds r5, #0x24
	ldrb r0, [r4, #5]
	cmp r0, #0
	beq _08017190
	movs r2, #0
	strb r2, [r4, #5]
	ldr r0, [r5, #8]
	movs r1, #2
	orrs r0, r1
	str r0, [r5, #8]
	strh r2, [r5, #0x36]
	adds r0, r4, #0
	adds r0, #0x58
	movs r1, #0x40
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_08017190:
	adds r6, r4, #0
	adds r6, #0x58
	ldrb r0, [r6]
	cmp r0, #8
	bls _0801719E
	subs r0, #8
	strb r0, [r6]
_0801719E:
	ldrb r0, [r6]
	adds r1, r4, #0
	adds r1, #0x59
	strb r0, [r1]
	ldrh r0, [r5, #0x36]
	adds r0, #0x10
	strh r0, [r5, #0x36]
	ldrh r0, [r4, #0x18]
	adds r0, #8
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x1c]
	adds r0, #8
	strh r0, [r4, #0x1c]
	adds r0, r4, #0
	bl FUN_08017000
	ldrb r1, [r6]
	movs r0, #0x40
	subs r0, r0, r1
	asrs r0, r0, #3
	ldrh r1, [r5, #0x20]
	adds r0, r0, r1
	strh r0, [r5, #0x20]
	ldr r0, [r4, #0xc]
	cmp r0, #7
	bls _080171E6
	adds r0, r4, #0
	bl FUN_08016fe4
	movs r1, #1
	mov r0, r8
	lsls r1, r0
	ldr r0, [r7, #0x18]
	bics r0, r1
	str r0, [r7, #0x18]
	b _080171EA
_080171E6:
	adds r0, #1
	str r0, [r4, #0xc]
_080171EA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080171f4
FUN_080171f4: @ 0x080171F4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r1, #0
	ldrb r0, [r7, #5]
	cmp r0, #0
	beq _08017210
	movs r0, #0
	strb r0, [r7, #5]
	ldr r0, [r7, #0x2c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #0x2c]
_08017210:
	ldrb r0, [r7, #7]
	cmp r0, #3
	bne _08017228
	ldr r0, [r7, #0xc]
	cmp r0, #3
	bhi _08017222
	ldrh r0, [r7, #0x1a]
	adds r0, #0x40
	b _08017238
_08017222:
	ldrh r0, [r7, #0x1a]
	subs r0, #4
	b _08017238
_08017228:
	ldr r0, [r7, #0xc]
	cmp r0, #4
	bhi _08017234
	ldrh r0, [r7, #0x1a]
	adds r0, #0x40
	b _08017238
_08017234:
	ldrh r0, [r7, #0x1a]
	subs r0, #8
_08017238:
	strh r0, [r7, #0x1a]
	adds r0, r7, #0
	bl FUN_08017000
	ldrb r0, [r7, #7]
	cmp r0, #3
	bne _080172A8
	ldr r0, [r7, #0xc]
	cmp r0, #3
	bls _0801728C
	ldr r0, _0801729C @ =0x0203B400
	mov r8, r0
	ldr r4, _080172A0 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r6, _080172A4 @ =0x000003FF
	ands r1, r6
	str r1, [r4]
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	adds r3, r7, #0
	adds r3, #0x44
	ldrh r0, [r3]
	subs r0, #1
	movs r5, #3
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r3]
	adds r1, #1
	ands r1, r6
	str r1, [r4]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	adds r2, r7, #0
	adds r2, #0x46
	ldrh r0, [r2]
	subs r0, #1
	ands r1, r5
	adds r0, r0, r1
	strh r0, [r2]
_0801728C:
	ldrb r0, [r7, #7]
	cmp r0, #3
	bne _080172A8
	ldr r0, [r7, #0xc]
	cmp r0, #8
	bls _080172BC
	b _080172AE
	.align 2, 0
_0801729C: .4byte 0x0203B400
_080172A0: .4byte 0x030046B8
_080172A4: .4byte 0x000003FF
_080172A8:
	ldr r0, [r7, #0xc]
	cmp r0, #7
	bls _080172BC
_080172AE:
	movs r0, #4
	movs r1, #0
	strb r0, [r7, #4]
	movs r0, #1
	strb r0, [r7, #5]
	str r1, [r7, #0xc]
	b _080172C0
_080172BC:
	adds r0, #1
	str r0, [r7, #0xc]
_080172C0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080172cc
FUN_080172cc: @ 0x080172CC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r4, r1, #0
	mov r8, r2
	adds r6, r4, #0
	adds r6, #0x24
	ldrb r0, [r4, #5]
	cmp r0, #0
	beq _08017306
	movs r2, #0
	strb r2, [r4, #5]
	ldr r0, [r4, #0x2c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x2c]
	ldr r0, [r6, #8]
	movs r1, #2
	orrs r0, r1
	str r0, [r6, #8]
	strh r2, [r6, #0x36]
	adds r0, r4, #0
	adds r0, #0x58
	movs r1, #0x40
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_08017306:
	adds r5, r4, #0
	adds r5, #0x58
	ldrb r0, [r5]
	cmp r0, #0x10
	bls _08017314
	subs r0, #0x10
	strb r0, [r5]
_08017314:
	ldrh r0, [r4, #0x1a]
	adds r0, #0x40
	strh r0, [r4, #0x1a]
	adds r0, r4, #0
	bl FUN_08017000
	ldrb r1, [r5]
	movs r0, #0x40
	subs r0, r0, r1
	asrs r0, r0, #3
	ldrh r1, [r6, #0x20]
	adds r0, r0, r1
	strh r0, [r6, #0x20]
	ldr r0, [r4, #0xc]
	cmp r0, #3
	bls _08017348
	adds r0, r4, #0
	bl FUN_08016fe4
	movs r1, #1
	mov r0, r8
	lsls r1, r0
	ldr r0, [r7, #0x18]
	bics r0, r1
	str r0, [r7, #0x18]
	b _0801734C
_08017348:
	adds r0, #1
	str r0, [r4, #0xc]
_0801734C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08017358
FUN_08017358: @ 0x08017358
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	str r0, [sp, #0x10]
	adds r5, r1, #0
	str r2, [sp, #0x14]
	movs r0, #0x24
	adds r0, r0, r5
	mov ip, r0
	ldrb r0, [r5, #5]
	cmp r0, #0
	beq _0801739E
	movs r2, #0
	strb r2, [r5, #5]
	ldr r0, [r5, #0x2c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x2c]
	mov r1, ip
	ldr r0, [r1, #8]
	movs r1, #2
	orrs r0, r1
	mov r1, ip
	str r0, [r1, #8]
	strh r2, [r1, #0x36]
	adds r0, r5, #0
	adds r0, #0x58
	movs r1, #0x40
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_0801739E:
	ldr r2, [r5, #0xc]
	mov r8, r2
	movs r0, #0x10
	mov r1, r8
	subs r1, r0, r1
	mov sl, r1
	ldrb r0, [r5, #7]
	cmp r0, #0
	bne _08017410
	ldrb r0, [r5, #0x12]
	ldr r1, _080173DC @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	mov r6, sp
	adds r7, r0, #0
	adds r7, #0x2c
	ldrh r0, [r0, #0x2c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080173E0
	asrs r0, r0, #8
	b _080173E6
	.align 2, 0
_080173DC: .4byte 0x03002BE0
_080173E0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080173E6:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080173F8
	asrs r0, r0, #8
	b _080173FE
_080173F8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080173FE:
	adds r4, r0, #0
	movs r2, #2
	ldrsh r1, [r7, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _0801745E
	b _08017462
_08017410:
	mov r6, sp
	ldr r2, [r5, #0x20]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08017430
	asrs r0, r0, #8
	b _08017436
_08017430:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08017436:
	strh r0, [r6]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08017448
	asrs r0, r0, #8
	b _0801744E
_08017448:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801744E:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08017462
_0801745E:
	asrs r0, r0, #8
	b _08017468
_08017462:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08017468:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _080174AC @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	adds r7, r3, #0
	add r4, sp, #8
	adds r6, r5, #0
	adds r6, #0x18
	ldrh r0, [r5, #0x18]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	mov sb, r4
	cmp r0, #0
	blt _080174B0
	asrs r0, r0, #8
	b _080174B6
	.align 2, 0
_080174AC: .4byte 0x030047C8
_080174B0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080174B6:
	strh r0, [r4]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080174C8
	asrs r0, r0, #8
	b _080174CE
_080174C8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080174CE:
	adds r3, r0, #0
	movs r2, #2
	ldrsh r1, [r6, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080174E2
	asrs r0, r0, #8
	b _080174E8
_080174E2:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080174E8:
	subs r2, r3, r0
	strh r2, [r4, #2]
	adds r3, r3, r0
	strh r3, [r4, #4]
	ldrh r0, [r4]
	ldrh r1, [r7]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r4]
	ldrh r0, [r7, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r4, #2]
	ldrh r0, [r7, #4]
	subs r3, r3, r0
	strh r3, [r4, #4]
	mov r1, sp
	ldrh r0, [r1, #2]
	subs r0, #4
	strh r0, [r1, #2]
	mov r1, sb
	movs r2, #0
	ldrsh r0, [r1, r2]
	mov r1, sl
	muls r1, r0, r1
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	adds r0, r1, r0
	cmp r0, #0
	blt _08017530
	asrs r0, r0, #4
	b _08017536
_08017530:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r0, r0, #0
_08017536:
	mov r1, ip
	strh r0, [r1, #0x20]
	mov r2, sb
	movs r1, #2
	ldrsh r0, [r2, r1]
	mov r1, sl
	muls r1, r0, r1
	mov r0, sp
	movs r2, #2
	ldrsh r0, [r0, r2]
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	adds r0, r1, r0
	cmp r0, #0
	blt _0801755A
	asrs r0, r0, #4
	b _08017560
_0801755A:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r0, r0, #0
_08017560:
	mov r1, ip
	strh r0, [r1, #0x22]
	mov r2, ip
	adds r2, #0x34
	ldrb r0, [r2]
	cmp r0, #0x20
	bls _08017572
	subs r0, #2
	strb r0, [r2]
_08017572:
	ldrb r0, [r2]
	mov r1, ip
	adds r1, #0x35
	strb r0, [r1]
	mov r1, ip
	ldrh r0, [r1, #0x36]
	adds r0, #8
	strh r0, [r1, #0x36]
	ldrh r1, [r1, #0x20]
	subs r1, #8
	ldrb r2, [r2]
	movs r0, #0x40
	subs r0, r0, r2
	asrs r0, r0, #3
	adds r1, r1, r0
	mov r2, ip
	strh r1, [r2, #0x20]
	ldrh r0, [r2, #0x22]
	subs r0, #8
	strh r0, [r2, #0x22]
	ldr r0, [r5, #0xc]
	cmp r0, #0xf
	bls _08017604
	ldrb r0, [r5, #6]
	cmp r0, #0
	bne _080175E0
	ldr r1, [r5, #8]
	adds r0, r1, #0
	subs r0, #0x40
	cmp r0, #3
	bhi _080175BC
	ldr r0, _080175B8 @ =0x00000183
	bl PlaySound_0824078c
	b _080175EA
	.align 2, 0
_080175B8: .4byte 0x00000183
_080175BC:
	adds r0, r1, #0
	bl IsValuable
	cmp r0, #1
	bne _080175D4
	ldr r0, _080175D0 @ =0x00000123
	bl PlaySound_0824078c
	b _080175EA
	.align 2, 0
_080175D0: .4byte 0x00000123
_080175D4:
	ldr r0, _080175DC @ =0x00000111
	bl PlaySound_0824078c
	b _080175EA
	.align 2, 0
_080175DC: .4byte 0x00000111
_080175E0:
	cmp r0, #3
	beq _080175EA
	ldr r0, _08017600 @ =0x00000123
	bl PlaySound_0824078c
_080175EA:
	adds r0, r5, #0
	bl FUN_08016fe4
	movs r1, #1
	ldr r0, [sp, #0x14]
	lsls r1, r0
	ldr r2, [sp, #0x10]
	ldr r0, [r2, #0x18]
	bics r0, r1
	str r0, [r2, #0x18]
	b _08017608
	.align 2, 0
_08017600: .4byte 0x00000123
_08017604:
	adds r0, #1
	str r0, [r5, #0xc]
_08017608:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08017618
FUN_08017618: @ 0x08017618
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r5, #0
	ldr r1, _08017668 @ =0x085AA92C
	mov r8, r1
	adds r4, r7, #0
	adds r4, #0x40
	adds r6, r7, #0
	adds r6, #0x3c
_0801762E:
	movs r2, #1
	lsls r2, r5
	ldr r1, [r7, #0x18]
	ands r1, r2
	cmp r1, #0
	beq _08017652
	ldrb r1, [r4]
	cmp r1, #6
	bhi _08017652
	adds r0, r1, #0
	lsls r0, r0, #2
	add r0, r8
	ldr r3, [r0]
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl _call_via_r3
_08017652:
	adds r4, #0x84
	adds r6, #0x84
	adds r5, #1
	cmp r5, #7
	ble _0801762E
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08017668: .4byte 0x085AA92C

	thumb_func_start FUN_0801766c
FUN_0801766c: @ 0x0801766C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x60
	movs r5, #7
_08017674:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x84
	subs r5, #1
	cmp r5, #0
	bge _08017674
	movs r2, #0
	ldr r1, _08017690 @ =0x0300006C
	str r2, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08017690: .4byte 0x0300006C

	thumb_func_start FUN_08017694
FUN_08017694: @ 0x08017694
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	ldr r0, _080176BC @ =0x0300006C
	str r7, [r0]
	ldr r0, _080176C0 @ =0x0000CB05
	ldr r1, _080176C4 @ =0x00005D04
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _080176C8
	movs r0, #1
	rsbs r0, r0, #0
	b _0801773A
	.align 2, 0
_080176BC: .4byte 0x0300006C
_080176C0: .4byte 0x0000CB05
_080176C4: .4byte 0x00005D04
_080176C8:
	adds r1, r7, #0
	adds r1, #0x1c
	adds r0, r2, #0
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r5, r7, #0
	adds r5, #0x1c
	adds r0, r5, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	movs r0, #0
	str r0, [r7, #0x18]
	add r4, sp, #0x14
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r4, #0
	ldr r2, _0801774C @ =0x05000002
	bl CpuSet
	mov sb, r5
	mov sl, r4
	movs r6, #0
	movs r5, #1
	mov r8, r5
	adds r4, r7, #0
	adds r4, #0x60
	adds r5, r7, #0
	adds r5, #0x3c
	movs r7, #7
_0801770C:
	str r6, [r5]
	mov r0, r8
	strb r0, [r5, #4]
	strb r6, [r5, #6]
	str r6, [r5, #0xc]
	mov r3, r8
	str r3, [sp]
	str r6, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	movs r3, #0x11
	bl FUN_0822f3fc
	adds r4, #0x84
	adds r5, #0x84
	subs r7, #1
	cmp r7, #0
	bge _0801770C
_0801773A:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801774C: .4byte 0x05000002

	thumb_func_start FUN_08017750
FUN_08017750: @ 0x08017750
	push {r4, lr}
	ldr r0, _08017784 @ =0x0300006C
	ldr r0, [r0]
	cmp r0, #0
	bne _08017796
	ldr r1, _08017788 @ =0x0000045C
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08017794
	ldr r1, _0801778C @ =FUN_08017618
	ldr r2, _08017790 @ =FUN_0801766c
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08017694
	cmp r0, #0
	bge _08017794
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08017796
	.align 2, 0
_08017784: .4byte 0x0300006C
_08017788: .4byte 0x0000045C
_0801778C: .4byte FUN_08017618
_08017790: .4byte FUN_0801766c
_08017794:
	adds r0, r4, #0
_08017796:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801779c
FUN_0801779c: @ 0x0801779C
	push {lr}
	ldr r0, _080177B0 @ =0x0300006C
	ldr r0, [r0]
	cmp r0, #0
	bne _080177AA
	bl FUN_08017750
_080177AA:
	pop {r1}
	bx r1
	.align 2, 0
_080177B0: .4byte 0x0300006C

	thumb_func_start FUN_080177b4
FUN_080177b4: @ 0x080177B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp]
	mov r8, r1
	str r2, [sp, #4]
	mov sl, r3
	ldr r7, [sp, #0x38]
	bl FUN_0801779c
	mov sb, r0
	ldr r4, _08017818 @ =0x00FFFFFF
	ands r4, r7
	ldr r1, [sp]
	lsls r0, r1, #0x1c
	orrs r4, r0
	movs r5, #0
	movs r2, #1
	rsbs r2, r2, #0
	str r2, [sp, #8]
	movs r1, #0
	movs r6, #1
	mov r0, sb
	ldr r3, [r0, #0x18]
	mov r2, sb
	adds r2, #0x3c
_080177EE:
	adds r0, r6, #0
	lsls r0, r1
	ands r0, r3
	cmp r0, #0
	bne _08017806
	adds r5, r2, #0
	str r1, [sp, #8]
	cmp r7, #0
	beq _08017806
	ldr r0, [r5]
	cmp r0, r4
	beq _0801781C
_08017806:
	adds r2, #0x84
	adds r1, #1
	cmp r1, #7
	ble _080177EE
_0801780E:
	cmp r5, #0
	bne _08017832
	movs r0, #1
	rsbs r0, r0, #0
	b _08017996
	.align 2, 0
_08017818: .4byte 0x00FFFFFF
_0801781C:
	adds r0, r5, #0
	bl FUN_08016fe4
	adds r1, r6, #0
	mov r2, r8
	lsls r1, r2
	mov r2, sb
	ldr r0, [r2, #0x18]
	bics r0, r1
	str r0, [r2, #0x18]
	b _0801780E
_08017832:
	str r4, [r5]
	movs r2, #0
	mov r0, sl
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0x12]
	ldr r1, _08017864 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _0801784A
	strb r2, [r5, #0x12]
_0801784A:
	ldr r0, [sp, #0x34]
	strh r0, [r5, #0x10]
	mov r1, sp
	ldrb r1, [r1, #4]
	strb r1, [r5, #7]
	ldrb r1, [r5, #7]
	cmp r1, #1
	beq _08017878
	cmp r1, #1
	bgt _08017868
	cmp r1, #0
	beq _08017872
	b _0801788E
	.align 2, 0
_08017864: .4byte 0x03002BE0
_08017868:
	cmp r1, #2
	beq _08017880
	cmp r1, #3
	beq _08017886
	b _0801788E
_08017872:
	movs r0, #3
	strb r0, [r5, #4]
	b _08017888
_08017878:
	movs r0, #0
	strb r0, [r5, #4]
	strb r1, [r5, #5]
	b _0801788C
_08017880:
	movs r0, #3
	strb r0, [r5, #4]
	b _08017888
_08017886:
	strb r1, [r5, #4]
_08017888:
	movs r0, #1
	strb r0, [r5, #5]
_0801788C:
	str r2, [r5, #0xc]
_0801788E:
	mov r2, sp
	ldrb r2, [r2]
	strb r2, [r5, #6]
	mov r0, r8
	str r0, [r5, #8]
	ldrb r0, [r5, #6]
	cmp r0, #1
	beq _080178B8
	cmp r0, #1
	bgt _080178A8
	cmp r0, #0
	beq _080178B2
	b _080178C8
_080178A8:
	cmp r0, #2
	beq _080178BC
	cmp r0, #3
	beq _080178C2
	b _080178C8
_080178B2:
	mov r2, r8
	adds r2, #0x68
	b _080178CA
_080178B8:
	mov r2, r8
	b _080178CA
_080178BC:
	mov r2, r8
	adds r2, #0x43
	b _080178CA
_080178C2:
	mov r2, r8
	adds r2, #0xb6
	b _080178CA
_080178C8:
	movs r2, #0x68
_080178CA:
	adds r0, r5, #0
	adds r0, #0x24
	mov r1, sb
	adds r1, #0x1c
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r5, #0x2c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x2c]
	ldr r2, [sp, #0x2c]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #0x18]
	str r1, [r5, #0x1c]
	ldr r0, [sp, #0x30]
	str r0, [r5, #0x20]
	adds r6, r5, #0
	adds r6, #0x44
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r7, r6, #0
	cmp r0, #0
	blt _08017916
	asrs r0, r0, #8
	b _0801791C
_08017916:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801791C:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0801792E
	asrs r0, r0, #8
	b _08017934
_0801792E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08017934:
	adds r4, r0, #0
	ldr r0, [sp, #0x2c]
	movs r2, #2
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0801794A
	asrs r0, r0, #8
	b _08017950
_0801794A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08017950:
	subs r2, r4, r0
	strh r2, [r6, #2]
	adds r4, r4, r0
	strh r4, [r6, #4]
	ldr r3, _080179A8 @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	ldrh r0, [r7]
	subs r0, #8
	strh r0, [r7]
	adds r1, r5, #0
	adds r1, #0x46
	ldrh r0, [r1]
	subs r0, #8
	strh r0, [r1]
	ldr r0, [sp, #8]
	cmp r0, #0
	blt _08017994
	movs r1, #1
	lsls r1, r0
	mov r2, sb
	ldr r0, [r2, #0x18]
	orrs r0, r1
	str r0, [r2, #0x18]
_08017994:
	movs r0, #0
_08017996:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080179A8: .4byte 0x030047C8

	thumb_func_start FUN_080179ac
FUN_080179ac: @ 0x080179AC
	ldr r1, _080179B4 @ =0x03000070
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080179B4: .4byte 0x03000070

	thumb_func_start EntityE435_Update
EntityE435_Update: @ 0x080179B8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, [r6, #0x28]
	cmp r0, #0
	beq _08017A10
	ldrh r0, [r6, #0x1a]
	ldrh r1, [r6, #0x1c]
	ldrh r3, [r6, #0x2c]
	lsls r2, r3, #3
	adds r2, r2, r3
	lsls r2, r2, #6
	adds r2, #0x2e
	adds r2, r6, r2
	ldr r5, _08017A18 @ =0x03003ED0
	ldr r3, _08017A1C @ =0x030044A0
	ldr r4, [r3]
	lsls r3, r4, #1
	adds r3, r3, r4
	lsls r3, r3, #4
	adds r3, r3, r5
	movs r4, #0x22
	ldrsh r3, [r3, r4]
	ldrh r4, [r6, #0x22]
	adds r3, r3, r4
	movs r4, #0x7f
	ands r3, r4
	lsls r3, r3, #1
	adds r2, r2, r3
	bl FUN_0822ee58
	ldrh r0, [r6, #0x26]
	adds r0, #1
	strh r0, [r6, #0x26]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r6, #0x24]
	cmp r0, r1
	blo _08017A10
	movs r0, #0
	strh r0, [r6, #0x26]
	ldrh r0, [r6, #0x20]
	ldrh r4, [r6, #0x22]
	adds r0, r0, r4
	strh r0, [r6, #0x22]
_08017A10:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08017A18: .4byte 0x03003ED0
_08017A1C: .4byte 0x030044A0

	thumb_func_start EntityE435_Destroy
EntityE435_Destroy: @ 0x08017A20
	push {lr}
	bl FUN_0822f0d8
	ldr r1, _08017A30 @ =0x03000070
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_08017A30: .4byte 0x03000070

	thumb_func_start EntityE435_Init
EntityE435_Init: @ 0x08017A34
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	ldr r0, _08017A70 @ =0x03000070
	str r5, [r0]
	strh r1, [r5, #0x18]
	movs r0, #0x74
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r5, #0x1a]
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r5, #0x1c]
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _08017A74
	bl Script_GetValue
	strb r0, [r5, #0x1e]
	bl Script_GetValue
	b _08017A7A
	.align 2, 0
_08017A70: .4byte 0x03000070
_08017A74:
	movs r0, #0
	strb r0, [r5, #0x1e]
	movs r0, #0xa0
_08017A7A:
	strb r0, [r5, #0x1f]
	movs r0, #0x73
	movs r1, #8
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r4, #0
	strh r4, [r5, #0x26]
	movs r0, #0x6f
	movs r1, #2
	bl Script_GetKeywordValue
	strh r0, [r5, #0x20]
	strh r4, [r5, #0x22]
	movs r0, #0x69
	movs r1, #5
	bl Script_GetKeywordValue
	adds r1, r0, #0
	strh r1, [r5, #0x24]
	strh r4, [r5, #0x2c]
	movs r1, #1
	str r1, [r5, #0x28]
	movs r2, #0
	ldr r1, _08017B00 @ =0x0000011F
	mov sl, r1
	movs r1, #0x7f
	mov sb, r1
	ldr r1, _08017B04 @ =0x085B0A08
	mov r8, r1
	movs r1, #0xff
	mov ip, r1
	adds r6, r5, #0
	adds r6, #0x2e
_08017ABE:
	movs r4, #0
	lsls r1, r2, #3
	adds r5, r2, #1
	adds r1, r1, r2
	lsls r3, r1, #6
_08017AC8:
	adds r1, r4, #0
	mov r2, sb
	ands r1, r2
	mov r2, ip
	ands r1, r2
	lsls r1, r1, #1
	add r1, r8
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r1, r7, r1
	asrs r1, r1, #0xc
	adds r2, r6, r3
	strh r1, [r2]
	adds r3, #2
	adds r4, #1
	cmp r4, sl
	ble _08017AC8
	adds r2, r5, #0
	cmp r2, #0
	ble _08017ABE
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08017B00: .4byte 0x0000011F
_08017B04: .4byte 0x085B0A08

	thumb_func_start EntityE435_Create
EntityE435_Create: @ 0x08017B08
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08017B28 @ =0x03000070
	ldr r0, [r0]
	cmp r0, #0
	bne _08017B6A
	movs r0, #0x61
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _08017B2C
	movs r1, #0x9d
	lsls r1, r1, #2
	movs r0, #0xb
	b _08017B32
	.align 2, 0
_08017B28: .4byte 0x03000070
_08017B2C:
	movs r1, #0x9d
	lsls r1, r1, #2
	movs r0, #9
_08017B32:
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08017B68
	ldr r1, _08017B60 @ =EntityE435_Update
	ldr r2, _08017B64 @ =EntityE435_Destroy
	adds r0, r4, #0
	bl SetEntityRoutine
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl EntityE435_Init
	cmp r0, #0
	bge _08017B68
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08017B6A
	.align 2, 0
_08017B60: .4byte EntityE435_Update
_08017B64: .4byte EntityE435_Destroy
_08017B68:
	adds r0, r4, #0
_08017B6A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08017b70
FUN_08017b70: @ 0x08017B70
	push {lr}
	ldr r0, _08017B80 @ =0x03000084
	ldr r0, [r0]
	cmp r0, #0
	bne _08017B84
	movs r0, #0
	b _08017B86
	.align 2, 0
_08017B80: .4byte 0x03000084
_08017B84:
	movs r0, #1
_08017B86:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08017b8c
FUN_08017b8c: @ 0x08017B8C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	strh r0, [r4, #0x20]
	ldrh r0, [r4, #0x2e]
	cmp r0, #0
	beq _08017BBA
	ldr r2, _08017BCC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08017BD0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08017BD4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r4, #0x2e]
	bl Mod
	ldrh r1, [r4, #0x20]
	adds r1, r1, r0
	strh r1, [r4, #0x20]
_08017BBA:
	ldrh r0, [r4, #0x20]
	cmp r0, #9
	bhi _08017BC4
	movs r0, #0xa
	strh r0, [r4, #0x20]
_08017BC4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08017BCC: .4byte 0x030046B8
_08017BD0: .4byte 0x000003FF
_08017BD4: .4byte 0x0203B400

	thumb_func_start FUN_08017bd8
FUN_08017bd8: @ 0x08017BD8
	movs r2, #0
	strb r1, [r0, #0x19]
	str r2, [r0, #0x1c]
	movs r1, #1
	strb r1, [r0, #0x18]
	bx lr

	thumb_func_start FUN_08017be4
FUN_08017be4: @ 0x08017BE4
	push {r4, lr}
	adds r1, r0, #0
	ldr r0, _08017C00 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08017C04 @ =0x000002B2
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _08017C08
	movs r0, #0x32
	ldrsh r4, [r1, r0]
	b _08017C14
	.align 2, 0
_08017C00: .4byte 0x030046A0
_08017C04: .4byte 0x000002B2
_08017C08:
	movs r2, #0x30
	ldrsh r0, [r1, r2]
	movs r2, #0x32
	ldrsh r1, [r1, r2]
	muls r0, r1, r0
	asrs r4, r0, #6
_08017C14:
	bl FUN_0823e1b0
	adds r1, r0, #0
	subs r0, r1, #4
	cmp r0, #1
	bls _08017C24
	cmp r1, #0
	bne _08017C26
_08017C24:
	asrs r4, r4, #1
_08017C26:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08017c30
FUN_08017c30: @ 0x08017C30
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r3, _08017C8C @ =0x030047C8
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r2, _08017C90 @ =0x03003540
	movs r4, #8
	ldrsh r0, [r2, r4]
	adds r7, r1, r0
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r3, #0xa
	ldrsh r0, [r2, r3]
	adds r1, r1, r0
	mov r8, r1
	ldr r0, [r6, #0x4c]
	cmp r0, #0
	bne _08017CA0
	ldr r5, _08017C94 @ =0x0203B400
	ldr r4, _08017C98 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _08017C9C @ =0x000003FF
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	movs r2, #0x7f
	ands r1, r2
	adds r1, #0x80
	str r1, [r6, #0x4c]
	adds r0, #1
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	subs r0, #1
	str r0, [r6, #0x48]
	b _08017CA4
	.align 2, 0
_08017C8C: .4byte 0x030047C8
_08017C90: .4byte 0x03003540
_08017C94: .4byte 0x0203B400
_08017C98: .4byte 0x030046B8
_08017C9C: .4byte 0x000003FF
_08017CA0:
	subs r0, #1
	str r0, [r6, #0x4c]
_08017CA4:
	ldr r1, [r6, #0x5c]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08017CC2
	ldr r0, [r6, #0x44]
	ldr r2, [r6, #0x48]
	cmp r0, r2
	bge _08017CBA
	adds r0, #1
	b _08017CC0
_08017CBA:
	cmp r0, r2
	ble _08017CC2
	subs r0, #1
_08017CC0:
	str r0, [r6, #0x44]
_08017CC2:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08017CDE
	ldr r0, [r6, #0x34]
	adds r0, #3
	ldr r1, [r6, #0x44]
	adds r0, r0, r1
	str r0, [r6, #0x34]
	ldr r0, [r6, #0x3c]
	subs r0, #8
	subs r0, r0, r1
	str r0, [r6, #0x3c]
	b _08017CF0
_08017CDE:
	ldr r0, [r6, #0x38]
	adds r0, #6
	ldr r1, [r6, #0x44]
	adds r0, r0, r1
	str r0, [r6, #0x38]
	ldr r0, [r6, #0x40]
	subs r0, #0x10
	subs r0, r0, r1
	str r0, [r6, #0x40]
_08017CF0:
	ldr r1, [r6, #0x50]
	lsls r1, r1, #2
	adds r0, r6, #0
	adds r0, #0x34
	adds r0, r0, r1
	ldr r5, [r0]
	adds r5, r7, r5
	movs r2, #0xff
	ands r5, r2
	adds r0, r6, #0
	adds r0, #0x3c
	adds r0, r0, r1
	ldr r4, [r0]
	add r4, r8
	ands r4, r2
	adds r0, r7, #0
	subs r0, #0x80
	movs r1, #8
	bl Div
	adds r6, r0, #0
	mov r0, r8
	subs r0, #0x80
	movs r1, #8
	bl Div
	movs r2, #2
	rsbs r2, r2, #0
	ands r2, r0
	str r4, [sp]
	movs r0, #1
	adds r1, r6, #0
	adds r3, r5, #0
	bl Video_GenerateBGMap
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08017d44
FUN_08017d44: @ 0x08017D44
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	ldr r0, _08017DBC @ =0x00001C1C
	bl GetParticleGroup
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r1, r4, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0x60
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	movs r0, #0xb4
	lsls r0, r0, #1
	adds r5, r4, r0
	mov r8, r1
	adds r6, r4, r2
	movs r7, #0x1f
	movs r2, #4
	rsbs r2, r2, #0
	mov sb, r2
_08017D7A:
	adds r4, r5, #0
	adds r4, #0x14
	mov r0, r8
	strb r0, [r5]
	strb r0, [r5, #1]
	strb r0, [r5, #2]
	ldr r1, [r6]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822da70
	adds r0, r4, #0
	mov r1, sb
	mov r2, sb
	bl FUN_0822dad4
	ldr r1, [r6]
	adds r0, r4, #0
	movs r2, #0x1e
	bl FUN_0822dafc
	subs r7, #1
	adds r5, #0x3c
	cmp r7, #0
	bge _08017D7A
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08017DBC: .4byte 0x00001C1C

	thumb_func_start FUN_08017dc0
FUN_08017dc0: @ 0x08017DC0
	push {r4, r5, lr}
	adds r1, r0, #0
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r4, r1, r2
	movs r5, #0x1f
_08017DCC:
	adds r2, r4, #0
	adds r2, #0x14
	ldrb r1, [r4]
	cmp r1, #0
	beq _08017DE0
	adds r0, r2, #0
	bl FUN_0822dabc
	movs r1, #0
	strb r1, [r4]
_08017DE0:
	subs r5, #1
	adds r4, #0x3c
	cmp r5, #0
	bge _08017DCC
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08017df0
FUN_08017df0: @ 0x08017DF0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xb4
	lsls r1, r1, #1
	adds r4, r6, r1
	movs r7, #0x1f
_08017DFC:
	adds r3, r4, #0
	adds r3, #0x14
	ldrb r1, [r4]
	cmp r1, #0
	beq _08017E5C
	ldrb r1, [r4, #3]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldr r2, [r1, #8]
	ldr r1, [r1, #4]
	str r1, [r4, #0x2c]
	str r2, [r4, #0x30]
	ldrb r2, [r4, #3]
	movs r1, #1
	subs r1, r1, r2
	movs r5, #0
	strb r1, [r4, #3]
	ldrb r1, [r4, #2]
	cmp r1, #0
	beq _08017E2A
	cmp r1, #1
	beq _08017E48
	b _08017E56
_08017E2A:
	ldrb r1, [r4, #1]
	cmp r1, #2
	bls _08017E56
	movs r0, #1
	strb r0, [r4, #2]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r3, #0
	movs r2, #0x1f
	bl FUN_0822dafc
	strb r5, [r4, #1]
	b _08017E56
_08017E48:
	ldrb r1, [r4, #1]
	cmp r1, #2
	bls _08017E56
	adds r0, r3, #0
	bl FUN_0822dabc
	strb r5, [r4]
_08017E56:
	ldrb r1, [r4, #1]
	adds r1, #1
	strb r1, [r4, #1]
_08017E5C:
	subs r7, #1
	adds r4, #0x3c
	cmp r7, #0
	bge _08017DFC
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08017e6c
FUN_08017e6c: @ 0x08017E6C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	ldr r0, _08017E98 @ =0x03002BE0
	ldr r0, [r0]
	mov r8, r0
	ldr r1, [sp]
	adds r1, #0x60
	ldrh r0, [r1]
	cmp r0, #0
	beq _08017E9C
	subs r0, #1
	strh r0, [r1]
	b _080180FA
	.align 2, 0
_08017E98: .4byte 0x03002BE0
_08017E9C:
	movs r0, #0
	str r1, [sp, #0x14]
	ldr r1, [sp, #4]
	cmp r0, r1
	blt _08017EA8
	b _080180CA
_08017EA8:
	ldr r3, _08017F34 @ =0x030046B8
	ldr r2, _08017F38 @ =0x00000FFF
	mov sl, r2
	ldr r4, _08017F3C @ =0xFFFFF800
	mov sb, r4
_08017EB2:
	ldr r1, [sp]
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r7, r1, r2
	movs r1, #0
	adds r0, #1
	str r0, [sp, #0x10]
	adds r6, r7, #0
_08017EC2:
	ldrb r0, [r6]
	cmp r0, #0
	beq _08017ECA
	b _080180B4
_08017ECA:
	strb r0, [r6, #2]
	strb r0, [r6, #1]
	strb r0, [r6, #3]
	ldr r1, [r3]
	adds r1, #1
	ldr r4, _08017F40 @ =0x000003FF
	ands r1, r4
	str r1, [r3]
	lsls r0, r1, #1
	ldr r2, _08017F44 @ =0x0203B400
	adds r0, r0, r2
	ldrh r2, [r0]
	mov r4, sl
	ands r2, r4
	mov r0, r8
	ldrh r0, [r0, #0x2c]
	adds r2, r2, r0
	add r2, sb
	strh r2, [r6, #4]
	adds r1, #1
	ldr r4, _08017F40 @ =0x000003FF
	ands r1, r4
	str r1, [r3]
	lsls r1, r1, #1
	ldr r0, _08017F44 @ =0x0203B400
	adds r1, r1, r0
	ldrh r0, [r1]
	mov r1, sl
	ands r0, r1
	mov r4, r8
	ldrh r4, [r4, #0x30]
	adds r0, r0, r4
	add r0, sb
	strh r0, [r6, #8]
	adds r5, r7, #4
	lsls r2, r2, #0x10
	asrs r2, r2, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08017F30
	cmp r1, #0
	blt _08017F30
	ldr r0, _08017F48 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08017F30
	ldr r0, _08017F4C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08017F50
_08017F30:
	movs r4, #0
	b _08017F5E
	.align 2, 0
_08017F34: .4byte 0x030046B8
_08017F38: .4byte 0x00000FFF
_08017F3C: .4byte 0xFFFFF800
_08017F40: .4byte 0x000003FF
_08017F44: .4byte 0x0203B400
_08017F48: .4byte 0x030046A8
_08017F4C: .4byte 0x030046AC
_08017F50:
	ldr r0, _08017F74 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08017F5E:
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp, #0x18]
	bl FUN_08234224
	ldr r3, [sp, #0x18]
	cmp r0, #0
	beq _08017F78
	adds r0, #4
	b _08017F84
	.align 2, 0
_08017F74: .4byte 0x030046A4
_08017F78:
	ldr r0, _08017F98 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08017F84:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08017F9C
	cmp r2, #2
	beq _08017FA0
	b _08017FA4
	.align 2, 0
_08017F98: .4byte 0x030046A4
_08017F9C:
	ldrb r0, [r5, #4]
	b _08017FA2
_08017FA0:
	ldrb r0, [r5]
_08017FA2:
	subs r1, r1, r0
_08017FA4:
	strh r1, [r6, #6]
	ldr r1, [r3]
	adds r1, #1
	ldr r0, _0801800C @ =0x000003FF
	ands r1, r0
	str r1, [r3]
	lsls r0, r1, #1
	ldr r2, _08018010 @ =0x0203B400
	adds r0, r0, r2
	ldrh r2, [r0]
	mov r4, sl
	ands r2, r4
	mov r0, r8
	ldrh r0, [r0, #0x2c]
	adds r2, r2, r0
	add r2, sb
	strh r2, [r6, #0xc]
	adds r1, #1
	ldr r4, _0801800C @ =0x000003FF
	ands r1, r4
	str r1, [r3]
	lsls r1, r1, #1
	ldr r0, _08018010 @ =0x0203B400
	adds r1, r1, r0
	ldrh r0, [r1]
	mov r1, sl
	ands r0, r1
	mov r4, r8
	ldrh r4, [r4, #0x30]
	adds r0, r0, r4
	add r0, sb
	strh r0, [r6, #0x10]
	adds r5, r7, #0
	adds r5, #0xc
	lsls r2, r2, #0x10
	asrs r2, r2, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08018008
	cmp r1, #0
	blt _08018008
	ldr r0, _08018014 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08018008
	ldr r0, _08018018 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0801801C
_08018008:
	movs r4, #0
	b _0801802A
	.align 2, 0
_0801800C: .4byte 0x000003FF
_08018010: .4byte 0x0203B400
_08018014: .4byte 0x030046A8
_08018018: .4byte 0x030046AC
_0801801C:
	ldr r0, _08018040 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0801802A:
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp, #0x18]
	bl FUN_08234224
	ldr r3, [sp, #0x18]
	cmp r0, #0
	beq _08018044
	adds r0, #4
	b _08018050
	.align 2, 0
_08018040: .4byte 0x030046A4
_08018044:
	ldr r0, _08018064 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08018050:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08018068
	cmp r2, #2
	beq _0801806C
	b _08018070
	.align 2, 0
_08018064: .4byte 0x030046A4
_08018068:
	ldrb r0, [r5, #4]
	b _0801806E
_0801806C:
	ldrb r0, [r5]
_0801806E:
	subs r1, r1, r0
_08018070:
	strh r1, [r6, #0xe]
	adds r5, r7, #0
	adds r5, #0x14
	ldrb r0, [r6, #3]
	lsls r0, r0, #3
	adds r0, r0, r7
	ldr r1, [r0, #8]
	ldr r0, [r0, #4]
	str r0, [r6, #0x2c]
	str r1, [r6, #0x30]
	ldr r1, [sp]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #0x1e
	str r3, [sp, #0x18]
	bl FUN_0822dafc
	movs r4, #1
	strb r4, [r5, #0xf]
	ldr r0, [r6, #0x14]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x14]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0822a398
	strb r4, [r6]
	ldr r3, [sp, #0x18]
	b _080180C0
_080180B4:
	adds r1, #1
	adds r6, #0x3c
	adds r7, #0x3c
	cmp r1, #0x1f
	bgt _080180C0
	b _08017EC2
_080180C0:
	ldr r0, [sp, #0x10]
	ldr r4, [sp, #4]
	cmp r0, r4
	bge _080180CA
	b _08017EB2
_080180CA:
	mov r0, sp
	ldrh r1, [r0, #8]
	ldr r0, [sp, #0x14]
	strh r1, [r0]
	ldr r2, [sp, #0xc]
	cmp r2, #0
	beq _080180FA
	ldr r2, _0801810C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08018110 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _08018114 @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	ldr r1, [sp, #0xc]
	bl Mod
	ldr r2, [sp, #0x14]
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
_080180FA:
	movs r0, #0
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801810C: .4byte 0x030046B8
_08018110: .4byte 0x000003FF
_08018114: .4byte 0x0203B400

	thumb_func_start FUN_08018118
FUN_08018118: @ 0x08018118
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x18]
	cmp r0, #0
	beq _08018146
	movs r0, #0
	strb r0, [r4, #0x18]
	ldr r0, _080181A0 @ =0x030046A0
	ldr r1, [r0]
	ldr r0, _080181A4 @ =0x00000934
	adds r1, r1, r0
	ldr r0, _080181A8 @ =0xFFFFF7FF
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
	movs r0, #0
	bl FUN_080026fc
	ldr r2, _080181AC @ =0x03003E78
	ldr r0, _080181B0 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08018146:
	adds r0, r4, #0
	bl FUN_08017be4
	mov ip, r0
	ldr r6, _080181A0 @ =0x030046A0
	ldr r3, [r6]
	ldr r1, _080181B4 @ =0x00000942
	adds r0, r3, r1
	movs r1, #0
	ldrsh r5, [r0, r1]
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _080181B8 @ =0x030047A4
	ldr r1, _080181BC @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _08018242
	adds r0, r4, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #0
	beq _08018242
	cmp r5, #0
	ble _080181C4
	movs r0, #0xb4
	lsls r0, r0, #2
	adds r2, r3, r0
	asrs r1, r5, #2
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, [r6]
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r2, r0, r1
	ldr r0, _080181C0 @ =0x03000074
	ldr r1, [r2]
	ldr r0, [r0]
	cmp r1, r0
	blt _08018242
	str r0, [r2]
	b _08018242
	.align 2, 0
_080181A0: .4byte 0x030046A0
_080181A4: .4byte 0x00000934
_080181A8: .4byte 0xFFFFF7FF
_080181AC: .4byte 0x03003E78
_080181B0: .4byte 0xFFFFFDFF
_080181B4: .4byte 0x00000942
_080181B8: .4byte 0x030047A4
_080181BC: .4byte 0x030047A0
_080181C0: .4byte 0x03000074
_080181C4:
	movs r0, #0xb4
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	cmp r0, #0
	bne _08018230
	ldr r7, _0801821C @ =0x0203B400
	ldr r3, _08018220 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r5, _08018224 @ =0x000003FF
	ands r0, r5
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	cmp r0, ip
	blt _08018236
	ldr r0, _08018228 @ =0x03000074
	ldr r0, [r0]
	str r0, [r2]
	ldr r0, _0801822C @ =0x03000078
	ldr r1, [r0]
	cmp r1, #0
	ble _08018242
	ldr r0, [r3]
	adds r0, #1
	ands r0, r5
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	bl Mod
	ldr r2, [r6]
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r2, r2, r1
	ldr r1, [r2]
	adds r1, r1, r0
	str r1, [r2]
	b _08018242
	.align 2, 0
_0801821C: .4byte 0x0203B400
_08018220: .4byte 0x030046B8
_08018224: .4byte 0x000003FF
_08018228: .4byte 0x03000074
_0801822C: .4byte 0x03000078
_08018230:
	subs r0, #1
	str r0, [r2]
	b _08018242
_08018236:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08017bd8
	movs r0, #1
	b _0801824A
_08018242:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	movs r0, #0
_0801824A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08018250
FUN_08018250: @ 0x08018250
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x18]
	cmp r0, #0
	beq _08018264
	movs r0, #0
	strb r0, [r4, #0x18]
	movs r0, #1
	bl FUN_080026fc
_08018264:
	ldr r0, [r4, #0x1c]
	cmp r0, #0x63
	bhi _08018272
	adds r0, #1
	str r0, [r4, #0x1c]
	movs r0, #0
	b _0801827C
_08018272:
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08017bd8
	movs r0, #1
_0801827C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08018284
FUN_08018284: @ 0x08018284
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x18]
	cmp r0, #0
	beq _080182B0
	movs r0, #0
	strb r0, [r4, #0x18]
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r0, _080182D0 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080182D4 @ =0x00000934
	adds r0, r0, r1
	ldrh r1, [r0]
	orrs r2, r1
	strh r2, [r0]
	ldr r0, [r4, #0x54]
	cmp r0, #0
	beq _080182B0
	movs r1, #0
	bl Script_ExecById
_080182B0:
	movs r5, #0x80
	lsls r5, r5, #2
	ldr r3, _080182D8 @ =0x03003E78
	ldrh r0, [r3]
	adds r2, r5, #0
	orrs r2, r0
	strh r2, [r3]
	ldr r1, [r4, #0x1c]
	cmp r1, #0xe
	bhi _080182DC
	movs r0, #3
	ands r1, r0
	cmp r1, #2
	bhi _080182F6
	b _080182F2
	.align 2, 0
_080182D0: .4byte 0x030046A0
_080182D4: .4byte 0x00000934
_080182D8: .4byte 0x03003E78
_080182DC:
	cmp r1, #0x1d
	bhi _080182EA
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	bhi _080182F6
	b _080182F2
_080182EA:
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _080182F6
_080182F2:
	bics r2, r5
	strh r2, [r3]
_080182F6:
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0xa
	movs r3, #0xa
	bl FUN_08017e6c
	ldr r1, [r4, #0x1c]
	cmp r1, #0x2c
	bhi _08018314
	movs r0, #0
	str r0, [r4, #0x50]
	adds r0, r1, #1
	str r0, [r4, #0x1c]
	movs r0, #0
	b _0801831E
_08018314:
	adds r0, r4, #0
	movs r1, #3
	bl FUN_08017bd8
	movs r0, #1
_0801831E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08018324
FUN_08018324: @ 0x08018324
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldrb r0, [r4, #0x18]
	cmp r0, #0
	beq _0801838E
	movs r0, #0
	strb r0, [r4, #0x18]
	ldr r5, _080183C0 @ =0x03000080
	ldr r0, [r5]
	cmp r0, #0
	bne _08018366
	ldrh r0, [r4, #0x28]
	str r0, [r5]
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	beq _08018366
	ldr r2, _080183C4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080183C8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080183CC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r4, #0x2a]
	bl Mod
	ldr r1, [r5]
	adds r1, r1, r0
	str r1, [r5]
_08018366:
	movs r0, #0
	strh r0, [r4, #0x24]
	movs r0, #0x80
	lsls r0, r0, #2
	ldr r2, _080183D0 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r0, _080183D4 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080183D8 @ =0x00000934
	adds r0, r0, r1
	ldrh r1, [r0]
	orrs r2, r1
	strh r2, [r0]
	movs r0, #2
	bl FUN_080026fc
_0801838E:
	ldrh r1, [r4, #0x20]
	cmp r1, #0
	bne _080183E8
	ldr r0, _080183DC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080183B6
	ldr r0, _080183E0 @ =0x03002B48
	ldr r0, [r0]
	cmp r0, #0
	ble _080183B6
	ldr r1, _080183E4 @ =0x0300446C
	movs r0, #5
	str r0, [r1]
	movs r0, #0x67
	bl PlaySound_082406e0
_080183B6:
	adds r0, r4, #0
	bl FUN_08017b8c
	b _08018424
	.align 2, 0
_080183C0: .4byte 0x03000080
_080183C4: .4byte 0x030046B8
_080183C8: .4byte 0x000003FF
_080183CC: .4byte 0x0203B400
_080183D0: .4byte 0x03003E78
_080183D4: .4byte 0x030046A0
_080183D8: .4byte 0x00000934
_080183DC: .4byte 0x030047A4
_080183E0: .4byte 0x03002B48
_080183E4: .4byte 0x0300446C
_080183E8:
	ldr r0, _0801840C @ =0x030047E0
	ldrb r0, [r0, #0xe]
	cmp r0, #2
	bls _0801841E
	cmp r1, #5
	bne _08018414
	movs r0, #0x1f
	str r0, [sp]
	ldr r0, _08018410 @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r1, #2
	movs r2, #0x1f
	movs r3, #0x1f
	bl FUN_0823ce68
	b _0801841E
	.align 2, 0
_0801840C: .4byte 0x030047E0
_08018410: .4byte 0x00001FFF
_08018414:
	cmp r1, #3
	bne _0801841E
	ldr r1, _08018468 @ =0x03002B48
	movs r0, #6
	str r0, [r1]
_0801841E:
	ldrh r0, [r4, #0x20]
	subs r0, #1
	strh r0, [r4, #0x20]
_08018424:
	ldr r0, [r4, #0x1c]
	cmp r0, #0x1d
	bls _08018480
	ldr r0, _0801846C @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08018470 @ =0x00000942
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldrh r1, [r4, #0x24]
	adds r0, r0, r1
	strh r0, [r4, #0x24]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bhi _08018458
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _08018474 @ =0x030047A4
	ldr r1, _08018478 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	beq _08018480
_08018458:
	ldr r1, _0801847C @ =0x03000080
	movs r0, #0
	str r0, [r1]
	adds r0, r4, #0
	movs r1, #4
	bl FUN_08017bd8
	b _080184E0
	.align 2, 0
_08018468: .4byte 0x03002B48
_0801846C: .4byte 0x030046A0
_08018470: .4byte 0x00000942
_08018474: .4byte 0x030047A4
_08018478: .4byte 0x030047A0
_0801847C: .4byte 0x03000080
_08018480:
	ldr r5, _080184C4 @ =0x03000080
	ldr r0, [r5]
	cmp r0, #0
	ble _080184D4
	subs r0, #1
	str r0, [r5]
	ldr r2, _080184C8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080184CC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080184D0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #4
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08017e6c
	ldr r1, [r4, #0x50]
	movs r0, #1
	subs r0, r0, r1
	str r0, [r4, #0x50]
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	movs r0, #0
	b _080184E2
	.align 2, 0
_080184C4: .4byte 0x03000080
_080184C8: .4byte 0x030046B8
_080184CC: .4byte 0x000003FF
_080184D0: .4byte 0x0203B400
_080184D4:
	adds r0, r4, #0
	movs r1, #4
	bl FUN_08017bd8
	movs r0, #0
	str r0, [r5]
_080184E0:
	movs r0, #1
_080184E2:
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080184ec
FUN_080184ec: @ 0x080184EC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x18]
	cmp r0, #0
	beq _0801851C
	movs r0, #0
	strb r0, [r4, #0x18]
	movs r0, #3
	bl FUN_080026fc
	ldr r0, _080185AC @ =0x030046A0
	ldr r1, [r0]
	ldr r0, _080185B0 @ =0x00000934
	adds r1, r1, r0
	ldr r0, _080185B4 @ =0xFFFFF7FF
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
	ldr r0, [r4, #0x58]
	cmp r0, #0
	beq _0801851C
	movs r1, #0
	bl Script_ExecById
_0801851C:
	movs r5, #0x80
	lsls r5, r5, #2
	ldr r3, _080185B8 @ =0x03003E78
	ldrh r0, [r3]
	adds r2, r5, #0
	orrs r2, r0
	strh r2, [r3]
	ldr r1, [r4, #0x1c]
	cmp r1, #9
	bhi _0801853C
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _0801853C
	bics r2, r5
	strh r2, [r3]
_0801853C:
	ldr r0, [r4, #0x1c]
	cmp r0, #7
	bhi _0801854E
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0xa
	movs r3, #0xa
	bl FUN_08017e6c
_0801854E:
	ldr r1, [r4, #0x1c]
	cmp r1, #9
	bls _080185D4
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08017bd8
	ldr r2, _080185B8 @ =0x03003E78
	ldr r0, _080185BC @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r4, _080185AC @ =0x030046A0
	ldr r0, [r4]
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, _080185C0 @ =0x03000074
	ldr r1, [r1]
	str r1, [r0]
	ldr r0, _080185C4 @ =0x03000078
	ldr r3, [r0]
	cmp r3, #0
	ble _080185A6
	ldr r2, _080185C8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080185CC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080185D0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r3, #0
	bl Mod
	ldr r2, [r4]
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r2, r2, r1
	ldr r1, [r2]
	adds r1, r1, r0
	str r1, [r2]
_080185A6:
	movs r0, #1
	b _080185DE
	.align 2, 0
_080185AC: .4byte 0x030046A0
_080185B0: .4byte 0x00000934
_080185B4: .4byte 0xFFFFF7FF
_080185B8: .4byte 0x03003E78
_080185BC: .4byte 0xFFFFFDFF
_080185C0: .4byte 0x03000074
_080185C4: .4byte 0x03000078
_080185C8: .4byte 0x030046B8
_080185CC: .4byte 0x000003FF
_080185D0: .4byte 0x0203B400
_080185D4:
	movs r0, #0
	str r0, [r4, #0x50]
	adds r0, r1, #1
	str r0, [r4, #0x1c]
	movs r0, #0
_080185DE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080185e4
FUN_080185e4: @ 0x080185E4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08018624 @ =0x085AA948
	ldrb r0, [r4, #0x19]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _080185FC
	adds r0, r4, #0
	bl _call_via_r1
_080185FC:
	ldrb r0, [r4, #0x19]
	cmp r0, #1
	bls _08018608
	adds r0, r4, #0
	bl FUN_08017c30
_08018608:
	ldrb r0, [r4, #0x19]
	cmp r0, #3
	bne _08018638
	ldr r0, _08018628 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0801862C @ =0x00000946
	adds r0, r0, r1
	ldr r2, _08018630 @ =0x00007FFF
	adds r1, r2, #0
	strh r1, [r0]
	ldr r1, _08018634 @ =0x0300007C
	movs r0, #1
	b _08018652
	.align 2, 0
_08018624: .4byte 0x085AA948
_08018628: .4byte 0x030046A0
_0801862C: .4byte 0x00000946
_08018630: .4byte 0x00007FFF
_08018634: .4byte 0x0300007C
_08018638:
	ldr r0, _08018674 @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _08018678 @ =0x00000946
	adds r1, r0, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _0801864E
	subs r0, r2, #1
	strh r0, [r1]
_0801864E:
	ldr r1, _0801867C @ =0x0300007C
	movs r0, #0
_08018652:
	str r0, [r1]
	ldr r1, _08018680 @ =0x03002B48
	ldr r0, [r1]
	cmp r0, #0
	ble _08018660
	subs r0, #1
	str r0, [r1]
_08018660:
	adds r0, r4, #0
	bl FUN_08017df0
	ldr r0, [r4, #0x5c]
	adds r0, #1
	str r0, [r4, #0x5c]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08018674: .4byte 0x030046A0
_08018678: .4byte 0x00000946
_0801867C: .4byte 0x0300007C
_08018680: .4byte 0x03002B48

	thumb_func_start FUN_08018684
FUN_08018684: @ 0x08018684
	push {lr}
	bl FUN_08017dc0
	ldr r1, _08018694 @ =0x03000084
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_08018694: .4byte 0x03000084

	thumb_func_start FUN_08018698
FUN_08018698: @ 0x08018698
	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r6, r0, #0
	ldr r0, _080186EC @ =0x03000084
	str r6, [r0]
	ldr r0, _080186F0 @ =0x0000EA77
	bl GetTilemapFile
	adds r5, r0, #0
	movs r0, #1
	bl GetTilemapBuffer
	adds r1, r0, #0
	movs r4, #0
	str r4, [r6, #0x34]
	str r4, [r6, #0x3c]
	str r4, [r6, #0x38]
	str r4, [r6, #0x40]
	str r4, [r6, #0x50]
	ldrb r0, [r5]
	cmp r0, #0x4d
	bne _080186F4
	ldrb r0, [r5, #1]
	cmp r0, #0x50
	bne _080186F4
	str r4, [sp, #0x10]
	movs r0, #1
	movs r1, #1
	bl SetBGPrioDirect
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0x10
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #1
	adds r2, r5, #0
	movs r3, #0
	bl FUN_0822c0b8
	b _0801870A
	.align 2, 0
_080186EC: .4byte 0x03000084
_080186F0: .4byte 0x0000EA77
_080186F4:
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #1
	adds r2, r5, #0
	movs r3, #0
	bl FUN_0822bfbc
_0801870A:
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _08018720
	bl Script_GetValue
	strh r0, [r6, #0x30]
	bl Script_GetValue
	b _08018724
_08018720:
	movs r0, #0x40
	strh r0, [r6, #0x30]
_08018724:
	strh r0, [r6, #0x32]
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _0801873C
	bl Script_GetValue
	strh r0, [r6, #0x28]
	bl Script_GetValue
	b _08018746
_0801873C:
	movs r0, #0xe1
	lsls r0, r0, #5
	strh r0, [r6, #0x28]
	movs r0, #0xe1
	lsls r0, r0, #4
_08018746:
	strh r0, [r6, #0x2a]
	ldr r4, _080187AC @ =0x03000080
	ldrh r1, [r6, #0x28]
	ldr r0, [r4]
	cmp r0, r1
	ble _0801877A
	str r1, [r4]
	ldrh r0, [r6, #0x2a]
	cmp r0, #0
	beq _0801877A
	ldr r2, _080187B0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080187B4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080187B8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r6, #0x2a]
	bl Mod
	ldr r1, [r4]
	adds r1, r1, r0
	str r1, [r4]
_0801877A:
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _08018794
	bl Script_GetValue
	ldr r1, _080187BC @ =0x030046A0
	ldr r1, [r1]
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r1, r1, r2
	str r0, [r1]
_08018794:
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _080187C0
	bl Script_GetValue
	strh r0, [r6, #0x2c]
	bl Script_GetValue
	b _080187C6
	.align 2, 0
_080187AC: .4byte 0x03000080
_080187B0: .4byte 0x030046B8
_080187B4: .4byte 0x000003FF
_080187B8: .4byte 0x0203B400
_080187BC: .4byte 0x030046A0
_080187C0:
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r6, #0x2c]
_080187C6:
	strh r0, [r6, #0x2e]
	adds r0, r6, #0
	bl FUN_08017b8c
	movs r0, #0x61
	movs r1, #1
	bl Script_GetKeywordValue
	adds r1, r6, #0
	adds r1, #0x22
	strb r0, [r1]
	ldr r3, _08018828 @ =0x030046A0
	ldr r2, [r3]
	ldr r4, _0801882C @ =0x00000942
	adds r0, r2, r4
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r4, #0xb4
	lsls r4, r4, #2
	adds r2, r2, r4
	asrs r1, r1, #2
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, [r3]
	adds r2, r0, r4
	ldr r0, _08018830 @ =0x03000074
	ldr r1, [r2]
	ldr r0, [r0]
	cmp r1, r0
	blt _08018806
	str r0, [r2]
_08018806:
	movs r5, #0
	ldr r2, [r3]
	ldr r1, _0801882C @ =0x00000942
	adds r0, r2, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _08018864
	ldr r1, _08018834 @ =0x03000080
	ldr r0, [r1]
	cmp r0, #0
	ble _08018838
	cmp r0, #0x63
	bgt _08018862
	movs r0, #0x64
	str r0, [r1]
	b _08018862
	.align 2, 0
_08018828: .4byte 0x030046A0
_0801882C: .4byte 0x00000942
_08018830: .4byte 0x03000074
_08018834: .4byte 0x03000080
_08018838:
	adds r0, r2, r4
	ldr r0, [r0]
	cmp r0, #0
	bne _08018864
	adds r0, r6, #0
	bl FUN_08017be4
	ldr r3, _080188D8 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r2, _080188DC @ =0x000003FF
	ands r1, r2
	str r1, [r3]
	lsls r1, r1, #1
	ldr r2, _080188E0 @ =0x0203B400
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #0x3f
	ands r1, r2
	cmp r1, r0
	bge _08018864
_08018862:
	movs r5, #3
_08018864:
	movs r0, #0x6d
	adds r1, r5, #0
	bl Script_GetKeywordValue
	adds r1, r0, #0
	adds r0, r6, #0
	bl FUN_08017bd8
	movs r0, #0x43
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [r6, #0x54]
	movs r0, #0x4f
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [r6, #0x58]
	ldr r4, _080188E0 @ =0x0203B400
	ldr r5, _080188D8 @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r3, _080188DC @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r2, #0x7f
	ands r0, r2
	adds r0, #0x80
	str r0, [r6, #0x4c]
	adds r1, #1
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r2, #7
	ands r0, r2
	subs r0, #4
	str r0, [r6, #0x44]
	adds r1, #1
	ands r1, r3
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r0, [r1]
	ands r0, r2
	subs r0, #4
	str r0, [r6, #0x48]
	adds r0, r6, #0
	bl FUN_08017d44
	movs r0, #0
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080188D8: .4byte 0x030046B8
_080188DC: .4byte 0x000003FF
_080188E0: .4byte 0x0203B400

	thumb_func_start FUN_080188e4
FUN_080188e4: @ 0x080188E4
	push {r4, lr}
	ldr r0, _08018918 @ =0x03000084
	ldr r0, [r0]
	cmp r0, #0
	bne _0801892A
	ldr r1, _0801891C @ =0x000008E8
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08018928
	ldr r1, _08018920 @ =FUN_080185e4
	ldr r2, _08018924 @ =FUN_08018684
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08018698
	cmp r0, #0
	bge _08018928
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801892A
	.align 2, 0
_08018918: .4byte 0x03000084
_0801891C: .4byte 0x000008E8
_08018920: .4byte FUN_080185e4
_08018924: .4byte FUN_08018684
_08018928:
	adds r0, r4, #0
_0801892A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08018930
FUN_08018930: @ 0x08018930
	push {r4, lr}
	ldr r0, _08018940 @ =0x03000084
	ldr r4, [r0]
	cmp r4, #0
	bne _08018944
	movs r0, #1
	rsbs r0, r0, #0
	b _08018954
	.align 2, 0
_08018940: .4byte 0x03000084
_08018944:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08017bd8
	adds r2, r4, #0
	adds r2, #0x22
	movs r1, #1
	strb r1, [r2]
_08018954:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801895c
FUN_0801895c: @ 0x0801895C
	push {r4, lr}
	ldr r1, _0801896C @ =0x03000084
	ldr r4, [r1]
	cmp r4, #0
	bne _08018970
	movs r0, #1
	rsbs r0, r0, #0
	b _0801898A
	.align 2, 0
_0801896C: .4byte 0x03000084
_08018970:
	ldrb r1, [r4, #0x19]
	cmp r1, #3
	bgt _08018982
	cmp r1, #1
	blt _08018982
	adds r0, r4, #0
	movs r1, #4
	bl FUN_08017bd8
_08018982:
	adds r2, r4, #0
	adds r2, #0x22
	movs r1, #0
	strb r1, [r2]
_0801898A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08018990
FUN_08018990: @ 0x08018990
	push {r4, r5, lr}
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _080189AA
	bl Script_GetValue
	adds r5, r0, #0
	bl Script_GetValue
	adds r4, r0, #0
	b _080189B0
_080189AA:
	movs r4, #0x96
	lsls r4, r4, #3
	adds r5, r4, #0
_080189B0:
	movs r0, #0x69
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080189C2
	bl Script_GetValue
	b _080189E4
_080189C2:
	ldr r1, _080189F4 @ =0x03000078
	ldr r3, [r1]
	cmp r3, #0
	ble _080189E4
	ldr r2, _080189F8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080189FC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08018A00 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r3, #0
	bl Mod
_080189E4:
	ldr r1, _08018A04 @ =0x03000074
	str r5, [r1]
	ldr r1, _080189F4 @ =0x03000078
	str r4, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080189F4: .4byte 0x03000078
_080189F8: .4byte 0x030046B8
_080189FC: .4byte 0x000003FF
_08018A00: .4byte 0x0203B400
_08018A04: .4byte 0x03000074

	thumb_func_start FUN_08018a08
FUN_08018a08: @ 0x08018A08
	ldr r0, _08018A10 @ =0x0300007C
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08018A10: .4byte 0x0300007C

	thumb_func_start FUN_08018a14
FUN_08018a14: @ 0x08018A14
	push {lr}
	bl FUN_08018a08
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08018a20
FUN_08018a20: @ 0x08018A20
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	adds r4, r1, #0
	mov sb, r3
	lsls r3, r4, #1
	ldr r1, _08018A60 @ =0x030042B0
	adds r6, r3, r1
	mov ip, r6
	subs r1, #0x20
	adds r7, r3, r1
	mov r1, sb
	cmp r1, #0x1f
	ble _08018A64
	adds r6, r4, #0
	cmp r6, r2
	bge _08018ACE
	subs r6, r2, r6
_08018A4A:
	mov r2, ip
	ldrh r1, [r2]
	strh r1, [r7]
	movs r3, #2
	add ip, r3
	adds r7, #2
	subs r6, #1
	cmp r6, #0
	bne _08018A4A
	b _08018ACE
	.align 2, 0
_08018A60: .4byte 0x030042B0
_08018A64:
	adds r1, r3, #0
	adds r1, #0x28
	adds r5, r5, r1
	mov r8, r5
	movs r1, #0x20
	mov r6, sb
	subs r6, r1, r6
	mov sl, r6
	adds r6, r4, #0
	cmp r6, r2
	bge _08018ACE
	subs r6, r2, r6
_08018A7C:
	mov r2, r8
	ldrh r1, [r2]
	ldr r4, _08018ADC @ =0x00007C1F
	ands r4, r1
	movs r5, #0xf8
	lsls r5, r5, #2
	ands r5, r1
	mov r3, ip
	ldrh r2, [r3]
	adds r1, r2, #0
	ldr r3, _08018ADC @ =0x00007C1F
	ands r1, r3
	mov r3, sb
	muls r3, r1, r3
	mov r1, sl
	muls r1, r4, r1
	adds r3, r3, r1
	ldr r1, _08018AE0 @ =0x000F83E0
	ands r3, r1
	movs r1, #0xf8
	lsls r1, r1, #2
	ands r2, r1
	mov r1, sb
	muls r1, r2, r1
	adds r2, r1, #0
	mov r1, sl
	muls r1, r5, r1
	adds r2, r2, r1
	movs r1, #0xf8
	lsls r1, r1, #7
	ands r2, r1
	orrs r3, r2
	lsrs r3, r3, #5
	strh r3, [r7]
	movs r2, #2
	add r8, r2
	add ip, r2
	adds r7, #2
	subs r6, #1
	cmp r6, #0
	bne _08018A7C
_08018ACE:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08018ADC: .4byte 0x00007C1F
_08018AE0: .4byte 0x000F83E0

	thumb_func_start FUN_08018ae4
FUN_08018ae4: @ 0x08018AE4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	lsls r3, r1, #1
	adds r2, r3, #0
	adds r2, #0x28
	adds r4, r4, r2
	ldr r2, _08018B14 @ =0x03004290
	adds r3, r3, r2
	adds r2, r1, #0
	cmp r2, r5
	bge _08018B0C
	subs r2, r5, r2
_08018AFE:
	ldrh r1, [r4]
	strh r1, [r3]
	adds r3, #2
	adds r4, #2
	subs r2, #1
	cmp r2, #0
	bne _08018AFE
_08018B0C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08018B14: .4byte 0x03004290

	thumb_func_start FUN_08018b18
FUN_08018b18: @ 0x08018B18
	push {lr}
	adds r1, r0, #0
	ldr r0, _08018B2C @ =0x03004290
	adds r1, #0x28
	ldr r2, _08018B30 @ =0x04000008
	bl CpuSet
	pop {r0}
	bx r0
	.align 2, 0
_08018B2C: .4byte 0x03004290
_08018B30: .4byte 0x04000008

	thumb_func_start FUN_08018b34
FUN_08018b34: @ 0x08018B34
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl FUN_0800271c
	cmp r0, #0
	beq _08018B46
	adds r0, r5, #0
	bl FUN_08018b18
_08018B46:
	ldrb r0, [r5, #0x1c]
	cmp r0, #2
	bne _08018B68
	ldr r2, [r5, #0x24]
	movs r0, #0xf
	ands r2, r0
	cmp r2, #0
	bne _08018BC4
	ldrh r0, [r5, #0x20]
	ldrh r1, [r5, #0x22]
	subs r0, r0, r1
	strh r0, [r5, #0x20]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08018BC4
	strh r2, [r5, #0x20]
	b _08018BC4
_08018B68:
	cmp r0, #1
	bne _08018B8C
	ldr r0, [r5, #0x24]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08018BC4
	ldrh r0, [r5, #0x22]
	ldrh r1, [r5, #0x20]
	adds r0, r0, r1
	strh r0, [r5, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	ble _08018BC4
	movs r0, #0x20
	strh r0, [r5, #0x20]
	b _08018BC4
_08018B8C:
	ldr r0, [r5, #0x24]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08018BC4
	ldrh r1, [r5, #0x22]
	ldrh r2, [r5, #0x20]
	adds r0, r1, r2
	strh r0, [r5, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	ble _08018BB8
	movs r0, #0x20
	strh r0, [r5, #0x20]
	ldr r2, _08018BB4 @ =0x0000FFFF
	adds r0, r2, #0
	orrs r0, r1
	b _08018BC2
	.align 2, 0
_08018BB4: .4byte 0x0000FFFF
_08018BB8:
	cmp r0, #0x10
	bgt _08018BC4
	movs r0, #0x10
	strh r0, [r5, #0x20]
	movs r0, #1
_08018BC2:
	strh r0, [r5, #0x22]
_08018BC4:
	movs r2, #1
	ldrb r0, [r5, #0x1c]
	cmp r0, #1
	beq _08018C14
	cmp r0, #1
	bgt _08018BD6
	cmp r0, #0
	beq _08018BDC
	b _08018CB4
_08018BD6:
	cmp r0, #2
	beq _08018C64
	b _08018CB4
_08018BDC:
	movs r6, #0
_08018BDE:
	movs r1, #1
	lsls r1, r6
	ldrh r0, [r5, #0x18]
	ands r0, r1
	cmp r0, #0
	bne _08018BF8
	adds r4, r2, #3
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r4, #0
	bl FUN_08018ae4
	b _08018C08
_08018BF8:
	adds r4, r2, #3
	movs r0, #0x20
	ldrsh r3, [r5, r0]
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r4, #0
	bl FUN_08018a20
_08018C08:
	adds r1, r4, #0
	adds r2, r1, #0
	adds r6, #1
	cmp r6, #3
	ble _08018BDE
	b _08018CB4
_08018C14:
	movs r6, #0
_08018C16:
	movs r1, #1
	lsls r1, r6
	ldrh r0, [r5, #0x18]
	ands r0, r1
	cmp r0, #0
	bne _08018C4A
	ldrh r0, [r5, #0x1a]
	ands r0, r1
	cmp r0, #0
	bne _08018C38
	adds r4, r2, #3
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r4, #0
	bl FUN_08018ae4
	b _08018C58
_08018C38:
	adds r4, r2, #3
	movs r1, #0x20
	ldrsh r3, [r5, r1]
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r4, #0
	bl FUN_08018a20
	b _08018C58
_08018C4A:
	adds r4, r2, #3
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r4, #0
	movs r3, #0x20
	bl FUN_08018a20
_08018C58:
	adds r1, r4, #0
	adds r2, r1, #0
	adds r6, #1
	cmp r6, #3
	ble _08018C16
	b _08018CB4
_08018C64:
	movs r6, #0
_08018C66:
	movs r1, #1
	lsls r1, r6
	ldrh r0, [r5, #0x18]
	ands r0, r1
	cmp r0, #0
	bne _08018C9A
	ldrh r0, [r5, #0x1a]
	ands r0, r1
	cmp r0, #0
	bne _08018C88
	adds r4, r2, #3
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r4, #0
	bl FUN_08018ae4
	b _08018CAA
_08018C88:
	adds r4, r2, #3
	movs r0, #0x20
	ldrsh r3, [r5, r0]
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r4, #0
	bl FUN_08018a20
	b _08018CAA
_08018C9A:
	adds r4, r2, #3
	movs r1, #0x20
	ldrsh r3, [r5, r1]
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r4, #0
	bl FUN_08018a20
_08018CAA:
	adds r1, r4, #0
	adds r2, r1, #0
	adds r6, #1
	cmp r6, #3
	ble _08018C66
_08018CB4:
	ldr r0, [r5, #0x24]
	adds r0, #1
	str r0, [r5, #0x24]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08018cc4
FUN_08018cc4: @ 0x08018CC4
	ldr r1, _08018CCC @ =0x03000088
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08018CCC: .4byte 0x03000088

	thumb_func_start FUN_08018cd0
FUN_08018cd0: @ 0x08018CD0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08018D10 @ =0x03000088
	str r5, [r0]
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	ldrh r1, [r5, #0x18]
	orrs r4, r1
	strh r4, [r5, #0x18]
	ldrh r1, [r5, #0x1a]
	orrs r0, r1
	strh r0, [r5, #0x1a]
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	strb r0, [r5, #0x1c]
	ldrb r0, [r5, #0x1c]
	cmp r0, #1
	beq _08018D22
	cmp r0, #1
	bgt _08018D14
	cmp r0, #0
	beq _08018D1A
	b _08018D34
	.align 2, 0
_08018D10: .4byte 0x03000088
_08018D14:
	cmp r0, #2
	beq _08018D26
	b _08018D34
_08018D1A:
	movs r0, #0x10
	strh r0, [r5, #0x20]
	movs r0, #1
	b _08018D32
_08018D22:
	movs r0, #0
	b _08018D28
_08018D26:
	movs r0, #0x20
_08018D28:
	strh r0, [r5, #0x20]
	movs r0, #0x61
	movs r1, #2
	bl Script_GetKeywordValue
_08018D32:
	strh r0, [r5, #0x22]
_08018D34:
	adds r0, r5, #0
	bl FUN_08018b18
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08018d44
FUN_08018d44: @ 0x08018D44
	push {r4, lr}
	movs r0, #0xc
	movs r1, #0x48
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08018D78
	ldr r1, _08018D70 @ =FUN_08018b34
	ldr r2, _08018D74 @ =FUN_08018cc4
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08018cd0
	cmp r0, #0
	bge _08018D78
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08018D7A
	.align 2, 0
_08018D70: .4byte FUN_08018b34
_08018D74: .4byte FUN_08018cc4
_08018D78:
	adds r0, r4, #0
_08018D7A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08018d80
FUN_08018d80: @ 0x08018D80
	push {r4, lr}
	ldr r0, _08018DA4 @ =0x03000088
	ldr r4, [r0]
	cmp r4, #0
	beq _08018DCA
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	strb r0, [r4, #0x1c]
	ldrb r0, [r4, #0x1c]
	cmp r0, #1
	beq _08018DB6
	cmp r0, #1
	bgt _08018DA8
	cmp r0, #0
	beq _08018DAE
	b _08018DCA
	.align 2, 0
_08018DA4: .4byte 0x03000088
_08018DA8:
	cmp r0, #2
	beq _08018DC0
	b _08018DCA
_08018DAE:
	movs r0, #0x10
	strh r0, [r4, #0x20]
	movs r0, #1
	b _08018DC8
_08018DB6:
	movs r0, #0
	strh r0, [r4, #0x20]
	movs r0, #0x61
	movs r1, #2
	b _08018DC4
_08018DC0:
	movs r0, #0x61
	movs r1, #1
_08018DC4:
	bl Script_GetKeywordValue
_08018DC8:
	strh r0, [r4, #0x22]
_08018DCA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08018dd0
FUN_08018dd0: @ 0x08018DD0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0800271c
	cmp r0, #0
	beq _08018E68
	ldrb r0, [r4, #0x18]
	cmp r0, #3
	bhi _08018E2C
	movs r3, #0
	ldrb r0, [r4, #0x18]
	cmp r3, r0
	bge _08018DFE
	ldr r2, _08018E24 @ =0x030042AE
	adds r1, r2, #0
	subs r1, #8
_08018DF0:
	ldrh r0, [r2]
	strh r0, [r1]
	subs r1, #2
	adds r3, #1
	ldrb r0, [r4, #0x18]
	cmp r3, r0
	blt _08018DF0
_08018DFE:
	cmp r3, #3
	bgt _08018E68
	ldr r0, _08018E28 @ =0x03004330
	lsls r1, r3, #1
	rsbs r1, r1, #0
	adds r2, r1, #0
	subs r2, #0x8a
	adds r2, r2, r0
	adds r1, #8
	adds r1, r1, r0
_08018E12:
	ldrh r0, [r1]
	strh r0, [r2]
	subs r2, #2
	subs r1, #2
	adds r3, #1
	cmp r3, #3
	ble _08018E12
	b _08018E68
	.align 2, 0
_08018E24: .4byte 0x030042AE
_08018E28: .4byte 0x03004330
_08018E2C:
	movs r3, #0
	ldrb r0, [r4, #0x18]
	subs r0, #4
	cmp r3, r0
	bge _08018E50
	ldr r0, _08018E98 @ =0x03004332
	adds r2, r0, #0
	subs r2, #0x92
	adds r1, r0, #0
_08018E3E:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r2, #2
	adds r1, #2
	adds r3, #1
	ldrb r0, [r4, #0x18]
	subs r0, #4
	cmp r3, r0
	blt _08018E3E
_08018E50:
	cmp r3, #3
	bgt _08018E68
	ldr r2, _08018E9C @ =0x030042AE
	lsls r0, r3, #1
	subs r0, #0xe
	adds r1, r0, r2
_08018E5C:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r1, #2
	adds r3, #1
	cmp r3, #3
	ble _08018E5C
_08018E68:
	ldrb r0, [r4, #0x19]
	adds r0, #1
	strb r0, [r4, #0x19]
	ldr r1, _08018EA0 @ =0x085AA95C
	ldrb r2, [r4, #0x18]
	adds r1, r2, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _08018ECA
	cmp r2, #3
	bhi _08018EA4
	movs r0, #0xb
	subs r1, r0, r2
	ldr r2, _08018E9C @ =0x030042AE
	lsls r0, r1, #1
	adds r1, r2, #0
	subs r1, #0x1e
	adds r0, r0, r1
	ldrh r1, [r2]
	strh r1, [r0]
	b _08018EB6
	.align 2, 0
_08018E98: .4byte 0x03004332
_08018E9C: .4byte 0x030042AE
_08018EA0: .4byte 0x085AA95C
_08018EA4:
	adds r1, r2, #4
	lsls r2, r2, #1
	ldr r0, _08018ED4 @ =0x0300432A
	adds r2, r2, r0
	lsls r1, r1, #1
	subs r0, #0x9a
	adds r1, r1, r0
	ldrh r0, [r2]
	strh r0, [r1]
_08018EB6:
	ldrb r0, [r4, #0x18]
	adds r0, #1
	movs r1, #0
	strb r0, [r4, #0x18]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _08018EC8
	strb r1, [r4, #0x18]
_08018EC8:
	strb r1, [r4, #0x19]
_08018ECA:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08018ED4: .4byte 0x0300432A

	thumb_func_start FUN_08018ed8
FUN_08018ed8: @ 0x08018ED8
	movs r0, #0
	bx lr

	thumb_func_start FUN_08018edc
FUN_08018edc: @ 0x08018EDC
	movs r1, #0
	strb r1, [r0, #0x18]
	strb r1, [r0, #0x19]
	ldr r0, _08018EF0 @ =0x030042AE
	adds r1, r0, #0
	subs r1, #0x1e
	ldrh r0, [r0]
	strh r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_08018EF0: .4byte 0x030042AE

	thumb_func_start FUN_08018ef4
FUN_08018ef4: @ 0x08018EF4
	push {r4, lr}
	movs r0, #0xc
	movs r1, #0x1c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08018F28
	ldr r1, _08018F20 @ =FUN_08018dd0
	ldr r2, _08018F24 @ =FUN_08018ed8
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08018edc
	cmp r0, #0
	bge _08018F28
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08018F2A
	.align 2, 0
_08018F20: .4byte FUN_08018dd0
_08018F24: .4byte FUN_08018ed8
_08018F28:
	adds r0, r4, #0
_08018F2A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08018f30
FUN_08018f30: @ 0x08018F30
	ldrh r0, [r0, #0x18]
	movs r2, #1
	lsls r2, r1
	ands r0, r2
	bx lr
	.align 2, 0

	thumb_func_start FUN_08018f3c
FUN_08018f3c: @ 0x08018F3C
	push {r4, lr}
	ldr r4, _08018F64 @ =0x03004250
	movs r2, #0
	ldr r3, _08018F68 @ =0x085AA964
	adds r1, r0, #0
	adds r1, #0x1c
_08018F48:
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, #8
	ble _08018F48
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08018F64: .4byte 0x03004250
_08018F68: .4byte 0x085AA964

	thumb_func_start FUN_08018f6c
FUN_08018f6c: @ 0x08018F6C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r7, _08018F94 @ =0x03004250
	movs r4, #0
	ldr r5, _08018F98 @ =0x085AA964
_08018F76:
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08018f30
	cmp r0, #0
	beq _08018F9C
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r7
	adds r1, r7, #0
	adds r1, #0xd0
	ldrh r1, [r1]
	strh r1, [r0]
	b _08018FAE
	.align 2, 0
_08018F94: .4byte 0x03004250
_08018F98: .4byte 0x085AA964
_08018F9C:
	ldrb r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r7
	lsls r2, r4, #1
	adds r0, r6, #0
	adds r0, #0x1c
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
_08018FAE:
	adds r5, #1
	adds r4, #1
	cmp r4, #8
	ble _08018F76
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08018fbc
FUN_08018fbc: @ 0x08018FBC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0800271c
	cmp r0, #0
	beq _08018FE4
	bl FUN_0823e1b0
	adds r1, r0, #0
	subs r0, r1, #4
	cmp r0, #1
	bls _08018FD8
	cmp r1, #0
	bne _08018FE4
_08018FD8:
	adds r0, r4, #0
	bl FUN_08018f3c
	adds r0, r4, #0
	bl FUN_08018f6c
_08018FE4:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08018fec
FUN_08018fec: @ 0x08018FEC
	movs r0, #0
	bx lr

	thumb_func_start FUN_08018ff0
FUN_08018ff0: @ 0x08018FF0
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0801900C @ =0x0000FFFF
	movs r0, #0x66
	bl Script_GetKeywordValue
	strh r0, [r4, #0x18]
	adds r0, r4, #0
	bl FUN_08018f3c
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801900C: .4byte 0x0000FFFF

	thumb_func_start FUN_08019010
FUN_08019010: @ 0x08019010
	push {r4, lr}
	movs r0, #0xc
	movs r1, #0x3c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08019044
	ldr r1, _0801903C @ =FUN_08018fbc
	ldr r2, _08019040 @ =FUN_08018fec
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08018ff0
	cmp r0, #0
	bge _08019044
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08019046
	.align 2, 0
_0801903C: .4byte FUN_08018fbc
_08019040: .4byte FUN_08018fec
_08019044:
	adds r0, r4, #0
_08019046:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801904c
FUN_0801904c: @ 0x0801904C
	push {lr}
	adds r1, r0, #0
	ldr r0, _08019060 @ =0x03004250
	adds r1, #0x1c
	ldr r2, _08019064 @ =0x04000080
	bl CpuSet
	pop {r0}
	bx r0
	.align 2, 0
_08019060: .4byte 0x03004250
_08019064: .4byte 0x04000080

	thumb_func_start FUN_08019068
FUN_08019068: @ 0x08019068
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r1, #0
	ldrb r0, [r5, #0xf]
	cmp r0, #0
	bne _080190A4
	ldrb r0, [r5, #0xd]
	ldrb r1, [r5, #0x10]
	cmp r0, r1
	blo _0801909C
	ldrb r1, [r5, #0xe]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r3, r1, #0
	cmp r2, #0
	bne _080190C0
	movs r0, #1
	strb r0, [r5, #0xf]
	strb r2, [r5, #0xd]
	b _080190C8
_0801909C:
	ldr r7, [r5]
	ldr r4, [r5, #4]
	ldrb r1, [r5, #0x10]
	b _080190D6
_080190A4:
	ldrb r0, [r5, #0xd]
	ldrb r2, [r5, #0x11]
	cmp r0, r2
	blo _080190D0
	ldrb r1, [r5, #0xe]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r1, #0
	cmp r0, #0
	bne _080190C8
	strb r0, [r5, #0xf]
	strb r0, [r5, #0xd]
_080190C0:
	ldr r7, [r5]
	ldr r4, [r5, #4]
	ldrb r1, [r5, #0x10]
	b _080190DC
_080190C8:
	ldr r7, [r5, #4]
	ldr r4, [r5]
	ldrb r1, [r5, #0x11]
	b _080190DC
_080190D0:
	ldr r7, [r5, #4]
	ldr r4, [r5]
	ldrb r1, [r5, #0x11]
_080190D6:
	adds r0, #1
	strb r0, [r5, #0xd]
	ldrb r3, [r5, #0xe]
_080190DC:
	movs r0, #1
	ands r0, r3
	cmp r0, #0
	beq _08019170
	cmp r1, #0
	ble _080190F2
	ldrb r0, [r5, #0xd]
	lsls r0, r0, #5
	bl Div
	b _080190F4
_080190F2:
	movs r0, #0
_080190F4:
	mov r8, r0
	movs r0, #0x20
	mov r1, r8
	subs r1, r0, r1
	mov sb, r1
	movs r6, #0
	ldrb r2, [r5, #0xc]
	cmp r6, r2
	bge _0801918C
	movs r0, #0xf8
	lsls r0, r0, #2
	mov sl, r0
	mov ip, r4
_0801910E:
	lsls r1, r6, #1
	str r1, [sp]
	ldrh r1, [r7]
	mov r2, ip
	ldrh r3, [r2]
	adds r0, r1, #0
	ldr r4, _08019168 @ =0x00007C1F
	ands r0, r4
	mov r2, r8
	muls r2, r0, r2
	adds r0, r3, #0
	ands r0, r4
	mov r4, sb
	muls r4, r0, r4
	adds r0, r4, #0
	adds r2, r2, r0
	ldr r0, _0801916C @ =0x000F83E0
	ands r2, r0
	mov r0, sl
	ands r1, r0
	mov r4, r8
	muls r4, r1, r4
	adds r1, r4, #0
	ands r3, r0
	mov r0, sb
	muls r0, r3, r0
	adds r1, r1, r0
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r1, r0
	orrs r2, r1
	lsrs r2, r2, #5
	ldr r0, [r5, #8]
	ldr r1, [sp]
	adds r4, r1, r0
	strh r2, [r4]
	movs r2, #2
	add ip, r2
	adds r7, #2
	adds r6, #1
	ldrb r4, [r5, #0xc]
	cmp r6, r4
	blt _0801910E
	b _0801918C
	.align 2, 0
_08019168: .4byte 0x00007C1F
_0801916C: .4byte 0x000F83E0
_08019170:
	movs r6, #0
	ldrb r0, [r5, #0xc]
	cmp r6, r0
	bge _0801918C
	adds r2, r4, #0
	ldr r1, [r5, #8]
_0801917C:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	adds r6, #1
	ldrb r4, [r5, #0xc]
	cmp r6, r4
	blt _0801917C
_0801918C:
	movs r0, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080191a0
FUN_080191a0: @ 0x080191A0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl FUN_0800271c
	cmp r0, #0
	beq _080191B2
	adds r0, r5, #0
	bl FUN_0801904c
_080191B2:
	movs r6, #0
	ldr r0, [r5, #0x18]
	cmp r6, r0
	bhs _080191D2
	movs r0, #0x87
	lsls r0, r0, #2
	adds r4, r5, r0
_080191C0:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08019068
	adds r4, #0x14
	adds r6, #1
	ldr r0, [r5, #0x18]
	cmp r6, r0
	blo _080191C0
_080191D2:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080191dc
FUN_080191dc: @ 0x080191DC
	ldr r1, _080191E4 @ =0x0300008C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080191E4: .4byte 0x0300008C

	thumb_func_start FUN_080191e8
FUN_080191e8: @ 0x080191E8
	push {lr}
	ldr r1, _080191FC @ =0x0300008C
	str r0, [r1]
	movs r1, #0
	str r1, [r0, #0x18]
	bl FUN_0801904c
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_080191FC: .4byte 0x0300008C

	thumb_func_start FUN_08019200
FUN_08019200: @ 0x08019200
	push {r4, lr}
	ldr r0, _08019238 @ =0x0300008C
	ldr r0, [r0]
	cmp r0, #0
	bne _08019246
	movs r1, #0xd7
	lsls r1, r1, #2
	movs r0, #0xc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08019244
	ldr r1, _0801923C @ =FUN_080191a0
	ldr r2, _08019240 @ =FUN_080191dc
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080191e8
	cmp r0, #0
	bge _08019244
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08019246
	.align 2, 0
_08019238: .4byte 0x0300008C
_0801923C: .4byte FUN_080191a0
_08019240: .4byte FUN_080191dc
_08019244:
	adds r0, r4, #0
_08019246:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801924c
FUN_0801924c: @ 0x0801924C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	bl FUN_08019200
	adds r6, r0, #0
	cmp r6, #0
	beq _08019268
	ldr r1, [r6, #0x18]
	cmp r1, #0xf
	bls _0801926E
_08019268:
	movs r0, #1
	rsbs r0, r0, #0
	b _08019378
_0801926E:
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r0, r1
	adds r5, r6, r0
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _0801929A
	bl Script_GetValue
	adds r7, r0, #0
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	mov sl, r0
	b _080192A0
_0801929A:
	movs r7, #0
	movs r4, #0
	mov sl, r4
_080192A0:
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	beq _080192BE
	bl Script_GetValue
	mov sb, r0
	bl Script_GetValue
	mov r8, r0
	bl Script_GetValue
	str r0, [sp]
	b _080192C8
_080192BE:
	movs r0, #0
	mov sb, r0
	mov r8, r0
	movs r1, #0
	str r1, [sp]
_080192C8:
	movs r0, #0x62
	bl prepare_08231510
	cmp r0, #0
	beq _080192E0
	bl Script_GetValue
	str r0, [sp, #4]
	bl Script_GetValue
	adds r3, r0, #0
	b _080192E6
_080192E0:
	movs r0, #0
	str r0, [sp, #4]
	movs r3, #0
_080192E6:
	mov r1, sl
	cmp r1, #1
	bne _08019300
	lsls r0, r7, #4
	adds r0, r0, r4
	lsls r0, r0, #1
	adds r0, #0x1c
	adds r0, r6, r0
	str r0, [r5]
	ldr r2, _080192FC @ =0x03004250
	b _0801930C
	.align 2, 0
_080192FC: .4byte 0x03004250
_08019300:
	lsls r0, r7, #5
	lsls r1, r4, #1
	ldr r2, _08019324 @ =0x03004250
	adds r1, r1, r2
	adds r0, r0, r1
	str r0, [r5]
_0801930C:
	ldr r4, [sp]
	cmp r4, #1
	bne _08019328
	mov r1, sb
	lsls r0, r1, #4
	add r0, r8
	lsls r0, r0, #1
	adds r0, #0x1c
	adds r0, r6, r0
	str r0, [r5, #4]
	b _08019336
	.align 2, 0
_08019324: .4byte 0x03004250
_08019328:
	mov r4, sb
	lsls r1, r4, #5
	mov r4, r8
	lsls r0, r4, #1
	adds r0, r0, r2
	adds r1, r1, r0
	str r1, [r5, #4]
_08019336:
	ldr r0, [sp, #4]
	lsls r1, r0, #5
	lsls r0, r3, #1
	adds r0, r0, r2
	adds r1, r1, r0
	str r1, [r5, #8]
	movs r0, #0x6e
	movs r1, #1
	bl Script_GetKeywordValue
	movs r4, #0
	strb r0, [r5, #0xc]
	strb r4, [r5, #0xd]
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	strb r0, [r5, #0xe]
	strb r4, [r5, #0xf]
	movs r0, #0x53
	movs r1, #0xa
	bl Script_GetKeywordValue
	strb r0, [r5, #0x10]
	movs r0, #0x44
	movs r1, #0xa
	bl Script_GetKeywordValue
	adds r1, r0, #0
	strb r1, [r5, #0x11]
	ldr r1, [r6, #0x18]
	adds r1, #1
	str r1, [r6, #0x18]
_08019378:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08019388
FUN_08019388: @ 0x08019388
	push {lr}
	movs r2, #0
	ldrh r1, [r0, #0x24]
	cmp r2, r1
	bge _080193AA
	adds r3, r1, #0
	adds r1, r0, #0
	adds r1, #0x34
_08019398:
	ldrb r0, [r1]
	cmp r0, #1
	bne _080193A2
	movs r0, #1
	b _080193AC
_080193A2:
	adds r1, #0x30
	adds r2, #1
	cmp r2, r3
	blt _08019398
_080193AA:
	movs r0, #0
_080193AC:
	pop {r1}
	bx r1

	thumb_func_start FUN_080193b0
FUN_080193b0: @ 0x080193B0
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldrh r0, [r3, #6]
	adds r4, r0, #0
	cmp r4, #0
	bne _08019400
	ldr r1, [r2, #0x1c]
	cmp r1, #0
	blt _080193CA
	ldr r0, [r2, #0x18]
	cmp r0, r1
	bge _08019404
_080193CA:
	movs r0, #1
	strb r0, [r3]
	ldr r2, _080193F4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080193F8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080193FC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	strb r0, [r3, #1]
	strh r4, [r3, #2]
	ldr r0, [r3, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #8]
	b _08019404
	.align 2, 0
_080193F4: .4byte 0x030046B8
_080193F8: .4byte 0x000003FF
_080193FC: .4byte 0x0203B400
_08019400:
	subs r0, #1
	strh r0, [r3, #6]
_08019404:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801940c
FUN_0801940c: @ 0x0801940C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldrh r0, [r6, #0x20]
	ldrh r1, [r5, #2]
	adds r0, r0, r1
	strh r0, [r5, #2]
	ldrh r3, [r5, #6]
	movs r0, #3
	ands r0, r3
	cmp r0, #0
	bne _08019438
	adds r0, r5, #0
	adds r0, #8
	ldr r1, [r6, #0x28]
	ldrh r2, [r6, #0x26]
	lsrs r3, r3, #2
	movs r4, #1
	ands r3, r4
	adds r2, r2, r3
	bl FUN_0822dafc
_08019438:
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	ldrh r0, [r5, #2]
	ldrh r1, [r6, #0x22]
	cmp r0, r1
	blo _0801945E
	movs r0, #0
	strb r0, [r5]
	ldr r0, [r5, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #8]
	ldrh r1, [r6, #0x24]
	movs r0, #8
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, #4
	strh r0, [r5, #6]
_0801945E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08019464
FUN_08019464: @ 0x08019464
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	movs r0, #0
	mov r8, r0
	ldrh r1, [r5, #0x24]
	cmp r8, r1
	bge _0801951A
	movs r2, #0x54
	adds r2, r2, r5
	mov sl, r2
	movs r0, #0x34
	adds r0, r0, r5
	mov sb, r0
	mov r4, sb
_08019488:
	mov r1, sb
	ldrb r0, [r4]
	cmp r0, #0
	bne _08019498
	adds r0, r5, #0
	bl FUN_080193b0
	b _0801949E
_08019498:
	adds r0, r5, #0
	bl FUN_0801940c
_0801949E:
	mov r3, sl
	ldrb r6, [r4, #1]
	ldrh r7, [r4, #4]
	ldr r2, _080194C0 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _080194C4
	asrs r1, r0, #0xc
	b _080194CA
	.align 2, 0
_080194C0: .4byte 0x085B0A08
_080194C4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080194CA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _080194E2
	asrs r0, r0, #0xc
	b _080194E8
_080194E2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080194E8:
	strh r0, [r3, #4]
	ldrh r1, [r4, #2]
	ldrh r0, [r4, #0x22]
	adds r1, r1, r0
	strh r1, [r4, #0x22]
	ldrh r0, [r5, #0x2c]
	ldrh r2, [r4, #0x20]
	adds r0, r0, r2
	strh r0, [r4, #0x20]
	ldrh r0, [r5, #0x2e]
	adds r1, r1, r0
	strh r1, [r4, #0x22]
	ldrh r0, [r5, #0x30]
	ldrh r1, [r4, #0x24]
	adds r0, r0, r1
	strh r0, [r4, #0x24]
	movs r2, #0x30
	add sl, r2
	adds r4, #0x30
	add sb, r2
	movs r0, #1
	add r8, r0
	ldrh r1, [r5, #0x24]
	cmp r8, r1
	blt _08019488
_0801951A:
	ldrh r2, [r5, #0x24]
	mov r8, r2
	cmp r2, #7
	bgt _08019542
	movs r2, #1
	mov r1, r8
	lsls r0, r1, #1
	add r0, r8
	lsls r0, r0, #4
	adds r0, #0x3c
	adds r1, r0, r5
_08019530:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x30
	movs r0, #1
	add r8, r0
	mov r0, r8
	cmp r0, #7
	ble _08019530
_08019542:
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
	ldr r1, [r5, #0x1c]
	cmp r1, #0
	ble _08019562
	cmp r0, r1
	blt _08019562
	adds r0, r5, #0
	bl FUN_08019388
	cmp r0, #0
	bne _08019562
	adds r0, r5, #0
	bl KillEntity
_08019562:
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08019574
FUN_08019574: @ 0x08019574
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x3c
	movs r5, #7
_0801957C:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x30
	subs r5, #1
	cmp r5, #0
	bge _0801957C
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08019594
FUN_08019594: @ 0x08019594
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r1, #0
	str r2, [sp]
	mov r8, r3
	ldr r7, [sp, #0x24]
	ldr r0, [sp, #0x28]
	cmp r0, #8
	bhi _08019654
	lsls r0, r0, #2
	ldr r1, _080195BC @ =_080195C0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080195BC: .4byte _080195C0
_080195C0: @ jump table
	.4byte _08019654 @ case 0
	.4byte _080195E4 @ case 1
	.4byte _08019654 @ case 2
	.4byte _080195F4 @ case 3
	.4byte _08019604 @ case 4
	.4byte _08019614 @ case 5
	.4byte _08019624 @ case 6
	.4byte _08019634 @ case 7
	.4byte _08019644 @ case 8
_080195E4:
	ldr r0, _080195F0 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #0
	b _0801965E
	.align 2, 0
_080195F0: .4byte 0x00001C1E
_080195F4:
	ldr r0, _08019600 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #4
	b _0801965E
	.align 2, 0
_08019600: .4byte 0x00001C1E
_08019604:
	ldr r0, _08019610 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #6
	b _0801965E
	.align 2, 0
_08019610: .4byte 0x00001C1E
_08019614:
	ldr r0, _08019620 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #8
	b _0801965E
	.align 2, 0
_08019620: .4byte 0x00001C1E
_08019624:
	ldr r0, _08019630 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #0xa
	b _0801965E
	.align 2, 0
_08019630: .4byte 0x00001C1E
_08019634:
	ldr r0, _08019640 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #0xc
	b _0801965E
	.align 2, 0
_08019640: .4byte 0x00001C1E
_08019644:
	ldr r0, _08019650 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #0xe
	b _0801965E
	.align 2, 0
_08019650: .4byte 0x00001C1E
_08019654:
	ldr r0, _08019694 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #2
_0801965E:
	strh r0, [r6, #0x26]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r6, #0x2c]
	str r1, [r6, #0x30]
	adds r5, r6, #0
	adds r5, #0x2c
	ldrh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08019690
	cmp r1, #0
	blt _08019690
	ldr r0, _08019698 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08019690
	ldr r0, _0801969C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080196A0
_08019690:
	movs r4, #0
	b _080196AE
	.align 2, 0
_08019694: .4byte 0x00001C1E
_08019698: .4byte 0x030046A8
_0801969C: .4byte 0x030046AC
_080196A0:
	ldr r0, _080196C0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080196AE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080196C4
	adds r0, #4
	b _080196D0
	.align 2, 0
_080196C0: .4byte 0x030046A4
_080196C4:
	ldr r0, _080196E4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080196D0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080196E8
	cmp r2, #2
	beq _080196EC
	b _080196F0
	.align 2, 0
_080196E4: .4byte 0x030046A4
_080196E8:
	ldrb r0, [r5, #4]
	b _080196EE
_080196EC:
	ldrb r0, [r5]
_080196EE:
	subs r1, r1, r0
_080196F0:
	movs r2, #0x2e
	ldrsh r0, [r6, r2]
	cmp r0, r1
	bge _080196FA
	strh r1, [r6, #0x2e]
_080196FA:
	movs r0, #0
	str r0, [r6, #0x18]
	mov r3, r8
	str r3, [r6, #0x1c]
	movs r0, #0x14
	strh r0, [r6, #0x20]
	movs r0, #0xc8
	lsls r0, r0, #1
	strh r0, [r6, #0x22]
	cmp r7, #7
	ble _08019712
	movs r7, #8
_08019712:
	strh r7, [r6, #0x24]
	adds r7, r6, #0
	adds r7, #0x34
	movs r0, #0
	mov r8, r0
	mov sb, r0
	ldr r1, _080197A0 @ =0x085B0A08
	mov sl, r1
	adds r5, r7, #0
_08019724:
	adds r4, r7, #0
	adds r4, #8
	mov r2, sb
	strb r2, [r5]
	ldr r2, _080197A4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080197A8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080197AC @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	subs r0, #0x20
	strb r0, [r5, #1]
	mov r0, sb
	strh r0, [r5, #2]
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r5, #4]
	mov r2, r8
	lsls r0, r2, #2
	strh r0, [r5, #6]
	ldr r1, [r6, #0x28]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	ldr r1, [r6, #0x28]
	ldrh r2, [r6, #0x26]
	adds r0, r4, #0
	bl FUN_0822dafc
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	ldrb r2, [r5, #1]
	ldrh r3, [r5, #4]
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080197B0
	asrs r0, r0, #0xc
	b _080197B6
	.align 2, 0
_080197A0: .4byte 0x085B0A08
_080197A4: .4byte 0x030046B8
_080197A8: .4byte 0x000003FF
_080197AC: .4byte 0x0203B400
_080197B0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080197B6:
	strh r0, [r5, #0x20]
	mov r0, sb
	strh r0, [r5, #0x22]
	lsls r0, r2, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080197CE
	asrs r2, r0, #0xc
	b _080197D4
_080197CE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080197D4:
	strh r2, [r5, #0x24]
	ldrh r1, [r5, #2]
	ldrh r3, [r5, #0x22]
	adds r1, r1, r3
	strh r1, [r5, #0x22]
	ldrh r0, [r6, #0x2c]
	ldrh r3, [r5, #0x20]
	adds r0, r0, r3
	strh r0, [r5, #0x20]
	ldrh r0, [r6, #0x2e]
	adds r1, r1, r0
	strh r1, [r5, #0x22]
	ldrh r0, [r6, #0x30]
	adds r0, r2, r0
	strh r0, [r5, #0x24]
	movs r0, #1
	strb r0, [r5, #0x17]
	add r8, r0
	adds r5, #0x30
	adds r7, #0x30
	mov r0, r8
	cmp r0, #7
	ble _08019724
	movs r0, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08019814
FUN_08019814: @ 0x08019814
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r1, #0xda
	lsls r1, r1, #1
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08019864
	ldr r1, _0801985C @ =FUN_08019464
	ldr r2, _08019860 @ =FUN_08019574
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl FUN_08019594
	cmp r0, #0
	bge _08019864
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08019866
	.align 2, 0
_0801985C: .4byte FUN_08019464
_08019860: .4byte FUN_08019574
_08019864:
	adds r0, r4, #0
_08019866:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08019874
FUN_08019874: @ 0x08019874
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	movs r1, #0xda
	lsls r1, r1, #1
	movs r0, #0xb
	bl CreateEntity
	adds r7, r0, #0
	cmp r7, #0
	beq _08019940
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080198D4
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080198CC @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080198D0 @ =0x0000FFFF
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	b _080198DE
	.align 2, 0
_080198CC: .4byte 0xFFFF0000
_080198D0: .4byte 0x0000FFFF
_080198D4:
	ldr r1, _08019934 @ =0xFFFF0000
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
_080198DE:
	movs r4, #0x80
	lsls r4, r4, #1
	movs r0, #0x64
	adds r1, r4, #0
	bl Script_GetKeywordValue
	mov r8, r0
	movs r0, #0x74
	adds r1, r4, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x6e
	movs r1, #8
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x54
	movs r1, #0
	bl Script_GetKeywordValue
	adds r4, r0, #0
	ldr r1, _08019938 @ =FUN_08019464
	ldr r2, _0801993C @ =FUN_08019574
	adds r0, r7, #0
	bl SetEntityRoutine
	str r5, [sp]
	str r4, [sp, #4]
	adds r0, r7, #0
	add r1, sp, #8
	mov r2, r8
	adds r3, r6, #0
	bl FUN_08019594
	cmp r0, #0
	bge _08019940
	adds r0, r7, #0
	bl KillEntity
	movs r0, #0
	b _08019942
	.align 2, 0
_08019934: .4byte 0xFFFF0000
_08019938: .4byte FUN_08019464
_0801993C: .4byte FUN_08019574
_08019940:
	adds r0, r7, #0
_08019942:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08019950
FUN_08019950: @ 0x08019950
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x18]
	ldrh r1, [r4, #0x20]
	ldrh r2, [r4, #0x22]
	bl FUN_0822ceb4
	movs r1, #0x1b
	ldrsb r1, [r4, r1]
	ldr r0, [r4, #0x24]
	muls r0, r1, r0
	ldr r1, [r4, #0x28]
	bl Div
	movs r1, #0x19
	ldrsb r1, [r4, r1]
	adds r5, r1, r0
	ldrb r0, [r4, #0x18]
	cmp r0, #1
	bne _08019994
	movs r1, #0x1c
	ldrsb r1, [r4, r1]
	ldr r0, [r4, #0x24]
	muls r0, r1, r0
	ldr r1, [r4, #0x28]
	bl Div
	movs r1, #0x1a
	ldrsb r1, [r4, r1]
	adds r1, r1, r0
	adds r0, r5, #0
	bl FUN_0822cec8
	b _0801999A
_08019994:
	adds r0, r5, #0
	bl FUN_0822ced8
_0801999A:
	ldr r1, [r4, #0x24]
	ldr r0, [r4, #0x28]
	cmp r1, r0
	blo _080199A8
	adds r0, r4, #0
	bl KillEntity
_080199A8:
	ldr r0, [r4, #0x24]
	adds r0, #1
	str r0, [r4, #0x24]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080199b8
FUN_080199b8: @ 0x080199B8
	movs r0, #0
	bx lr

	thumb_func_start FUN_080199bc
FUN_080199bc: @ 0x080199BC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r0, #0x6d
	movs r1, #1
	bl Script_GetKeywordValue
	strb r0, [r5, #0x18]
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _080199FC
	adds r7, r5, #0
	adds r7, #0x19
	movs r0, #0x1b
	adds r0, r0, r5
	mov r8, r0
	adds r4, r7, #0
_080199E4:
	bl VM_GetPC
	cmp r0, #0
	beq _080199F0
	bl Script_GetValue
_080199F0:
	strb r0, [r4]
	adds r4, #1
	adds r0, r7, #1
	cmp r4, r0
	ble _080199E4
	b _08019A16
_080199FC:
	adds r7, r5, #0
	adds r7, #0x19
	movs r0, #0x1b
	adds r0, r0, r5
	mov r8, r0
	adds r1, r7, #0
	movs r2, #0
	adds r0, r5, #0
	adds r0, #0x1a
_08019A0E:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _08019A0E
_08019A16:
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _08019A42
	movs r6, #0
	mov r4, r8
_08019A24:
	bl VM_GetPC
	cmp r0, #0
	beq _08019A36
	bl Script_GetValue
	adds r1, r7, r6
	ldrb r1, [r1]
	subs r0, r0, r1
_08019A36:
	strb r0, [r4]
	adds r4, #1
	adds r6, #1
	cmp r6, #1
	ble _08019A24
	b _08019A50
_08019A42:
	mov r1, r8
	movs r2, #0
	adds r0, r1, #1
_08019A48:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _08019A48
_08019A50:
	movs r0, #0x73
	movs r1, #0
	bl Script_GetKeywordValue
	movs r4, #0
	strh r0, [r5, #0x20]
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r5, #0x22]
	movs r0, #0x74
	movs r1, #0x3c
	bl Script_GetKeywordValue
	str r0, [r5, #0x28]
	str r4, [r5, #0x24]
	cmp r0, #0
	bne _08019A7A
	movs r0, #0x3c
	str r0, [r5, #0x28]
_08019A7A:
	ldrb r0, [r5, #0x18]
	ldrh r1, [r5, #0x20]
	ldrh r2, [r5, #0x22]
	bl FUN_0822ceb4
	ldrb r0, [r5, #0x18]
	cmp r0, #1
	bne _08019A98
	movs r0, #0x19
	ldrsb r0, [r5, r0]
	movs r1, #0x1a
	ldrsb r1, [r5, r1]
	bl FUN_0822cec8
	b _08019AA0
_08019A98:
	movs r0, #0x19
	ldrsb r0, [r5, r0]
	bl FUN_0822ced8
_08019AA0:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08019aac
FUN_08019aac: @ 0x08019AAC
	push {r4, lr}
	movs r0, #0xb
	movs r1, #0x2c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08019AE0
	ldr r1, _08019AD8 @ =FUN_08019950
	ldr r2, _08019ADC @ =FUN_080199b8
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080199bc
	cmp r0, #0
	bge _08019AE0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08019AE2
	.align 2, 0
_08019AD8: .4byte FUN_08019950
_08019ADC: .4byte FUN_080199b8
_08019AE0:
	adds r0, r4, #0
_08019AE2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08019ae8
FUN_08019ae8: @ 0x08019AE8
	ldr r1, _08019AF0 @ =0x03000090
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08019AF0: .4byte 0x03000090

	thumb_func_start FUN_08019af4
FUN_08019af4: @ 0x08019AF4
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	mov r8, r0
	adds r4, r1, #0
	movs r6, #0
	strb r6, [r4]
	str r6, [r4, #4]
	movs r0, #1
	mov sb, r0
	mov r0, sb
	strb r0, [r4, #2]
	strb r6, [r4, #1]
	adds r5, r4, #0
	adds r5, #8
	movs r0, #0x80
	lsls r0, r0, #1
	add r8, r0
	mov r0, r8
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #0x13
	bl FUN_0822d9f0
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r5, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	mov r0, r8
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #0x33
	bl FUN_0822dafc
	mov r0, sb
	strb r0, [r4, #0x17]
	strh r6, [r4, #0x30]
	strh r6, [r4, #0x32]
	strh r6, [r4, #0x34]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08019b54
FUN_08019b54: @ 0x08019B54
	push {lr}
	adds r0, r1, #0
	adds r0, #8
	bl FUN_0822dabc
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08019b64
FUN_08019b64: @ 0x08019B64
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #2]
	cmp r0, #0
	beq _08019B76
	movs r0, #0
	strb r0, [r2, #2]
	movs r0, #1
	b _08019B78
_08019B76:
	movs r0, #0
_08019B78:
	cmp r0, #0
	beq _08019B84
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
_08019B84:
	ldr r0, [r2, #4]
	adds r0, #1
	str r0, [r2, #4]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08019b90
FUN_08019b90: @ 0x08019B90
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r6, r1, #0
	ldrb r0, [r6, #2]
	cmp r0, #0
	beq _08019BA2
	movs r0, #0
	strb r0, [r6, #2]
_08019BA2:
	mov r5, sp
	movs r0, #0x30
	adds r0, r0, r6
	mov ip, r0
	ldrh r0, [r6, #0x30]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	mov r1, ip
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08019BC8
	asrs r0, r0, #8
	b _08019BCE
_08019BC8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019BCE:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08019BE0
	asrs r0, r0, #8
	b _08019BE6
_08019BE0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019BE6:
	adds r4, r0, #0
	mov r2, ip
	movs r3, #2
	ldrsh r1, [r2, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08019BFC
	asrs r0, r0, #8
	b _08019C02
_08019BFC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019C02:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08019C80 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	adds r5, r7, #0
	adds r5, #0x18
	mov r4, sp
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0x18
	ldrsh r1, [r7, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r4, r3]
	movs r3, #4
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r6, #1]
	mov r0, sp
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r3, #0x18
	ldrsh r0, [r7, r3]
	subs r2, r2, r0
	movs r1, #4
	ldrsh r0, [r4, r1]
	movs r3, #4
	ldrsh r1, [r5, r3]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	ldr r0, _08019C84 @ =0x00000FFF
	cmp r1, r0
	bls _08019C74
	ldr r0, [r6, #4]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0x10
	bls _08019C88
_08019C74:
	ldr r0, [r6, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r6, #8]
	b _08019CEC
	.align 2, 0
_08019C80: .4byte 0x030047C8
_08019C84: .4byte 0x00000FFF
_08019C88:
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	ldr r2, _08019CB4 @ =0x085B0A08
	ldrb r3, [r6, #1]
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _08019CB8
	asrs r0, r0, #0xc
	b _08019CBE
	.align 2, 0
_08019CB4: .4byte 0x085B0A08
_08019CB8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08019CBE:
	adds r0, #0x78
	strh r0, [r6, #0x20]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _08019CD6
	asrs r0, r0, #0xc
	b _08019CDC
_08019CD6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08019CDC:
	adds r0, #0x50
	movs r1, #0
	strh r0, [r6, #0x22]
	strh r1, [r6, #0x24]
	ldrb r1, [r6, #1]
	movs r0, #0xa0
	subs r0, r0, r1
	strb r0, [r6, #0xf]
_08019CEC:
	ldr r0, [r6, #4]
	cmp r0, #0xb3
	bls _08019CFC
	movs r0, #0
	strb r0, [r6]
	str r0, [r6, #4]
	movs r0, #1
	strb r0, [r6, #2]
_08019CFC:
	ldr r0, [r6, #4]
	adds r0, #1
	str r0, [r6, #4]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08019d0c
FUN_08019d0c: @ 0x08019D0C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	mov r8, r0
	adds r6, r1, #0
	ldrb r0, [r6, #2]
	cmp r0, #0
	beq _08019D26
	movs r0, #0
	strb r0, [r6, #2]
	movs r0, #1
	b _08019D28
_08019D26:
	movs r0, #0
_08019D28:
	cmp r0, #0
	bne _08019D2E
	b _08019E56
_08019D2E:
	mov r5, sp
	adds r7, r6, #0
	adds r7, #0x30
	ldrh r0, [r6, #0x30]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08019D50
	asrs r0, r0, #8
	b _08019D56
_08019D50:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019D56:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08019D68
	asrs r0, r0, #8
	b _08019D6E
_08019D68:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019D6E:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r7, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08019D82
	asrs r0, r0, #8
	b _08019D88
_08019D82:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019D88:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08019E2C @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	mov r5, r8
	adds r5, #0x18
	mov r4, sp
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, r8
	movs r3, #0x18
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r2, #4
	ldrsh r1, [r4, r2]
	movs r3, #4
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r6, #1]
	mov r0, sp
	movs r1, #0
	ldrsh r2, [r0, r1]
	mov r3, r8
	movs r1, #0x18
	ldrsh r0, [r3, r1]
	subs r2, r2, r0
	movs r3, #4
	ldrsh r0, [r4, r3]
	movs r4, #4
	ldrsh r1, [r5, r4]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _08019E30 @ =0x00000FFF
	cmp r1, r0
	bhi _08019DF6
	b _08019F08
_08019DF6:
	ldr r0, [r6, #4]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0x10
	bls _08019E02
	b _08019F08
_08019E02:
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	ldr r2, _08019E34 @ =0x085B0A08
	ldrb r3, [r6, #1]
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _08019E38
	asrs r0, r0, #0xc
	b _08019E3E
	.align 2, 0
_08019E2C: .4byte 0x030047C8
_08019E30: .4byte 0x00000FFF
_08019E34: .4byte 0x085B0A08
_08019E38:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08019E3E:
	adds r0, #0x78
	strh r0, [r6, #0x20]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _08019E54
	b _08019F66
_08019E54:
	b _08019F6A
_08019E56:
	add r5, sp, #8
	adds r7, r6, #0
	adds r7, #0x30
	ldrh r0, [r6, #0x30]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	mov ip, r5
	cmp r0, #0
	blt _08019E7A
	asrs r0, r0, #8
	b _08019E80
_08019E7A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019E80:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08019E92
	asrs r0, r0, #8
	b _08019E98
_08019E92:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019E98:
	adds r4, r0, #0
	movs r3, #2
	ldrsh r1, [r7, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08019EAC
	asrs r0, r0, #8
	b _08019EB2
_08019EAC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019EB2:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08019F14 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	add r0, sp, #8
	movs r4, #0
	ldrsh r2, [r0, r4]
	mov r1, r8
	movs r3, #0x18
	ldrsh r0, [r1, r3]
	subs r2, r2, r0
	mov r4, ip
	movs r1, #4
	ldrsh r0, [r4, r1]
	mov r3, r8
	movs r4, #0x1c
	ldrsh r1, [r3, r4]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _08019F18 @ =0x00000FFF
	cmp r1, r0
	bls _08019F08
	ldr r0, [r6, #4]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0x10
	bls _08019F1C
_08019F08:
	ldr r0, [r6, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r6, #8]
	b _08019F80
	.align 2, 0
_08019F14: .4byte 0x030047C8
_08019F18: .4byte 0x00000FFF
_08019F1C:
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	ldr r2, _08019F48 @ =0x085B0A08
	ldrb r3, [r6, #1]
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _08019F4C
	asrs r0, r0, #0xc
	b _08019F52
	.align 2, 0
_08019F48: .4byte 0x085B0A08
_08019F4C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08019F52:
	adds r0, #0x78
	strh r0, [r6, #0x20]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _08019F6A
_08019F66:
	asrs r0, r0, #0xc
	b _08019F70
_08019F6A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08019F70:
	adds r0, #0x50
	movs r1, #0
	strh r0, [r6, #0x22]
	strh r1, [r6, #0x24]
	ldrb r1, [r6, #1]
	movs r0, #0xa0
	subs r0, r0, r1
	strb r0, [r6, #0xf]
_08019F80:
	ldr r0, [r6, #4]
	cmp r0, #0x3b
	bls _08019F90
	movs r0, #0
	strb r0, [r6]
	str r0, [r6, #4]
	movs r0, #1
	strb r0, [r6, #2]
_08019F90:
	ldr r0, [r6, #4]
	adds r0, #1
	str r0, [r6, #4]
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08019fa4
FUN_08019fa4: @ 0x08019FA4
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	mov r1, sp
	ldr r0, _08019FDC @ =0x08251B58
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	adds r4, r6, #0
	adds r4, #0x20
	movs r5, #3
_08019FB8:
	ldrb r0, [r4]
	lsls r0, r0, #2
	add r0, sp
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
	subs r5, #1
	adds r4, #0x38
	cmp r5, #0
	bge _08019FB8
	movs r0, #0
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08019FDC: .4byte 0x08251B58

	thumb_func_start FUN_08019fe0
FUN_08019fe0: @ 0x08019FE0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x20
	movs r6, #3
_08019FEA:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08019b54
	adds r4, #0x38
	subs r6, #1
	cmp r6, #0
	bge _08019FEA
	movs r1, #0
	ldr r0, _0801A008 @ =0x03000090
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801A008: .4byte 0x03000090

	thumb_func_start FUN_0801a00c
FUN_0801a00c: @ 0x0801A00C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _0801A04C @ =0x03000090
	str r5, [r0]
	ldr r0, _0801A050 @ =0x00001C1A
	bl GetParticleGroup
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r5, r2
	str r0, [r1]
	movs r1, #0
	movs r0, #0x78
	strh r0, [r5, #0x18]
	movs r0, #0x50
	strh r0, [r5, #0x1a]
	strh r1, [r5, #0x1c]
	adds r4, r5, #0
	adds r4, #0x20
	movs r6, #3
_0801A034:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08019af4
	adds r4, #0x38
	subs r6, #1
	cmp r6, #0
	bge _0801A034
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801A04C: .4byte 0x03000090
_0801A050: .4byte 0x00001C1A

	thumb_func_start FUN_0801a054
FUN_0801a054: @ 0x0801A054
	push {r4, lr}
	ldr r0, _0801A08C @ =0x03000090
	ldr r0, [r0]
	cmp r0, #0
	bne _0801A09A
	movs r1, #0x82
	lsls r1, r1, #1
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801A098
	ldr r1, _0801A090 @ =FUN_08019fa4
	ldr r2, _0801A094 @ =FUN_08019fe0
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0801a00c
	cmp r0, #0
	bge _0801A098
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801A09A
	.align 2, 0
_0801A08C: .4byte 0x03000090
_0801A090: .4byte FUN_08019fa4
_0801A094: .4byte FUN_08019fe0
_0801A098:
	adds r0, r4, #0
_0801A09A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801a0a0
FUN_0801a0a0: @ 0x0801A0A0
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	ldr r0, _0801A0C0 @ =0x03000090
	ldr r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	beq _0801A100
	ldr r0, _0801A0C4 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0801A0C8
	movs r0, #1
	rsbs r0, r0, #0
	b _0801A0CC
	.align 2, 0
_0801A0C0: .4byte 0x03000090
_0801A0C4: .4byte 0x03002C68
_0801A0C8:
	movs r1, #0x18
	ldrsh r0, [r0, r1]
_0801A0CC:
	cmp r0, r3
	beq _0801A100
	lsls r4, r3, #3
	subs r4, r4, r3
	lsls r4, r4, #3
	adds r4, #0x20
	ldr r2, [r2]
	adds r4, r2, r4
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r4, #0x30]
	str r1, [r4, #0x34]
	adds r0, r4, #0
	adds r0, #8
	movs r1, #0x80
	lsls r1, r1, #1
	adds r2, r2, r1
	ldr r1, [r2]
	movs r2, #0x33
	bl FUN_0822dafc
	movs r1, #1
	movs r0, #0
	strb r1, [r4]
	str r0, [r4, #4]
	strb r1, [r4, #2]
_0801A100:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801a108
FUN_0801a108: @ 0x0801A108
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	ldr r0, _0801A128 @ =0x03000090
	ldr r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	beq _0801A16A
	ldr r0, _0801A12C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0801A130
	movs r0, #1
	rsbs r0, r0, #0
	b _0801A134
	.align 2, 0
_0801A128: .4byte 0x03000090
_0801A12C: .4byte 0x03002C68
_0801A130:
	movs r1, #0x18
	ldrsh r0, [r0, r1]
_0801A134:
	cmp r0, r3
	beq _0801A16A
	lsls r4, r3, #3
	subs r4, r4, r3
	lsls r4, r4, #3
	adds r4, #0x20
	ldr r2, [r2]
	adds r4, r2, r4
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r4, #0x30]
	str r1, [r4, #0x34]
	adds r0, r4, #0
	adds r0, #8
	movs r1, #0x80
	lsls r1, r1, #1
	adds r2, r2, r1
	ldr r1, [r2]
	movs r2, #0x35
	bl FUN_0822dafc
	movs r0, #2
	movs r1, #0
	strb r0, [r4]
	str r1, [r4, #4]
	movs r0, #1
	strb r0, [r4, #2]
_0801A16A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801a170
FUN_0801a170: @ 0x0801A170
	bx lr
	.align 2, 0

	thumb_func_start FUN_0801a174
FUN_0801a174: @ 0x0801A174
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	adds r7, r1, #0
	movs r1, #0xa
	ldrsh r0, [r7, r1]
	mov r2, r8
	movs r3, #0x1e
	ldrsh r1, [r2, r3]
	ldrb r5, [r7, #5]
	adds r1, r1, r5
	subs r1, r0, r1
	movs r0, #0x96
	lsls r0, r0, #3
	cmp r1, r0
	ble _0801A1B8
	ldrh r0, [r7, #0xa]
	subs r0, #0x18
	strh r0, [r7, #0xa]
	adds r6, r7, #0
	adds r6, #0x18
	movs r1, #1
	movs r4, #2
_0801A1A8:
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	subs r4, #1
	adds r6, #0x28
	cmp r4, #0
	bge _0801A1A8
	b _0801A3A0
_0801A1B8:
	cmp r1, #0x18
	bgt _0801A1BE
	b _0801A2FA
_0801A1BE:
	ldrh r0, [r7, #0xa]
	subs r0, #0x18
	strh r0, [r7, #0xa]
	adds r6, r7, #0
	adds r6, #0x18
	ldr r0, [r7, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	mov sb, r1
	ands r0, r1
	str r0, [r7, #0x18]
	ldrb r0, [r7, #2]
	cmp r0, #0
	bne _0801A2AC
	movs r0, #0x18
	strb r0, [r7, #2]
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r0]
	movs r2, #1
	mov ip, r2
	orrs r1, r2
	str r1, [r0]
	ldrb r0, [r7, #1]
	adds r0, #1
	strb r0, [r7, #1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0801A204
	mov r3, ip
	strb r3, [r7, #1]
_0801A204:
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r6, r0
	ldr r5, _0801A2A0 @ =0x0203B400
	mov sl, r5
	ldr r4, _0801A2A4 @ =0x030046B8
	ldr r2, [r4]
	adds r2, #1
	ldr r3, _0801A2A8 @ =0x000003FF
	ands r2, r3
	lsls r1, r2, #1
	add r1, sl
	ldrh r1, [r1]
	mov r5, ip
	ands r1, r5
	subs r1, #4
	adds r2, #1
	ands r2, r3
	str r2, [r4]
	lsls r2, r2, #1
	add r2, sl
	ldrh r2, [r2]
	ands r2, r5
	subs r2, #4
	bl FUN_0822dad4
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r6, r0
	mov r2, r8
	ldr r1, [r2, #0x28]
	movs r2, #2
	bl FUN_0822dafc
	ldrb r0, [r7, #1]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r3, r8
	ldr r0, [r3, #0x28]
	ldrb r0, [r0, #6]
	adds r0, #1
	strb r0, [r1, #0xe]
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r0]
	mov r5, sb
	ands r1, r5
	str r1, [r0]
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #2
	orrs r1, r2
	str r1, [r0]
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r7, #8]
	ldr r2, [r7, #0xc]
	str r1, [r0, #0x18]
	str r2, [r0, #0x1c]
	b _0801A3A0
	.align 2, 0
_0801A2A0: .4byte 0x0203B400
_0801A2A4: .4byte 0x030046B8
_0801A2A8: .4byte 0x000003FF
_0801A2AC:
	subs r0, #1
	strb r0, [r7, #2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x16
	bne _0801A2E0
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r6, r0
	mov r2, r8
	ldr r1, [r2, #0x28]
	movs r2, #2
	bl FUN_0822dafc
	ldrb r0, [r7, #1]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r3, r8
	ldr r0, [r3, #0x28]
	ldrb r0, [r0, #6]
	adds r0, #1
	strb r0, [r1, #0xe]
_0801A2E0:
	ldrb r0, [r7, #2]
	cmp r0, #0x14
	bne _0801A3A0
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _0801A3A0
_0801A2FA:
	movs r1, #0
	movs r0, #2
	strb r0, [r7]
	strh r1, [r7, #6]
	ldr r2, _0801A3B8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0801A3BC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _0801A3C0 @ =0x0203B400
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	adds r0, #4
	strb r0, [r7, #3]
	adds r6, r7, #0
	adds r6, #0x18
	movs r4, #0
	movs r0, #0x10
	adds r0, r0, r7
	mov sl, r0
	movs r1, #0x13
	adds r1, r1, r7
	mov sb, r1
	adds r5, r2, #0
_0801A332:
	ldr r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r1, r0
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r6]
	mov r2, r8
	ldr r1, [r2, #0x28]
	adds r0, r6, #0
	movs r2, #2
	bl FUN_0822dafc
	mov r3, r8
	ldr r0, [r3, #0x28]
	ldrb r0, [r0, #6]
	adds r0, #1
	strb r0, [r6, #0xe]
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r6, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r6, #0x18]
	str r1, [r6, #0x1c]
	mov r0, sl
	adds r1, r0, r4
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _0801A3BC @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _0801A3C0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	mov r3, sb
	adds r2, r3, r4
	movs r0, #3
	ands r1, r0
	strb r1, [r2]
	adds r4, #1
	adds r6, #0x28
	cmp r4, #2
	ble _0801A332
	ldr r0, _0801A3C4 @ =0x03002BE0
	ldr r0, [r0]
	bl FUN_0807a8e0
_0801A3A0:
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r7, #0x30]
	str r1, [r7, #0x34]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801A3B8: .4byte 0x030046B8
_0801A3BC: .4byte 0x000003FF
_0801A3C0: .4byte 0x0203B400
_0801A3C4: .4byte 0x03002BE0

	thumb_func_start FUN_0801a3c8
FUN_0801a3c8: @ 0x0801A3C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sl, r0
	adds r6, r1, #0
	ldrb r0, [r6, #4]
	mov sb, r0
	adds r4, r6, #0
	adds r4, #0x18
	movs r1, #0
	mov r8, r1
_0801A3E4:
	mov r0, sb
	adds r0, #0x40
	movs r2, #0xff
	ands r0, r2
	lsls r0, r0, #1
	ldr r7, _0801A424 @ =0x085B0A08
	adds r0, r0, r7
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrb r0, [r6, #3]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	ldrh r7, [r4, #0x18]
	adds r0, r0, r7
	strh r0, [r4, #0x18]
	ldrh r0, [r6, #6]
	cmp r0, #0x18
	bhi _0801A43A
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r2, _0801A424 @ =0x085B0A08
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	lsls r0, r0, #6
	cmp r0, #0
	blt _0801A428
	asrs r1, r0, #0xc
	b _0801A42E
	.align 2, 0
_0801A424: .4byte 0x085B0A08
_0801A428:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0801A42E:
	mov r2, sl
	ldrh r0, [r2, #0x1e]
	adds r0, r0, r1
	ldrb r7, [r6, #5]
	adds r0, r0, r7
	b _0801A43E
_0801A43A:
	ldrh r0, [r4, #0x1a]
	subs r0, #0xa
_0801A43E:
	strh r0, [r4, #0x1a]
	mov r1, sb
	lsls r0, r1, #1
	ldr r2, _0801A524 @ =0x085B0A08
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldrb r0, [r6, #3]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	ldrh r1, [r4, #0x1c]
	adds r0, r0, r1
	movs r2, #0
	mov ip, r2
	strh r0, [r4, #0x1c]
	adds r0, r6, #0
	adds r0, #0x13
	mov r7, r8
	adds r5, r0, r7
	ldrb r1, [r5]
	adds r1, #1
	strb r1, [r5]
	movs r2, #0xff
	mov r0, sp
	strb r2, [r0]
	lsls r1, r1, #0x18
	ldr r2, _0801A528 @ =0x085AA970
	adds r0, r6, #0
	adds r0, #0x10
	adds r3, r0, r7
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	lsrs r1, r1, #0x18
	ldrh r0, [r0]
	cmp r1, r0
	blo _0801A4B6
	mov r7, ip
	strb r7, [r5]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	mov r1, sp
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #1
	bls _0801A4A0
	mov r2, ip
	strb r2, [r3]
_0801A4A0:
	mov r7, sl
	ldr r1, [r7, #0x28]
	ldrb r2, [r3]
	adds r2, #2
	adds r0, r4, #0
	bl FUN_0822dafc
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #6]
	adds r0, #1
	strb r0, [r4, #0xe]
_0801A4B6:
	ldr r2, _0801A52C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0801A530 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0801A534 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	adds r1, #0x4c
	mov r2, sb
	lsls r0, r2, #0x18
	asrs r0, r0, #0x18
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	movs r7, #1
	add r8, r7
	adds r4, #0x28
	mov r0, r8
	cmp r0, #2
	bgt _0801A4EC
	b _0801A3E4
_0801A4EC:
	ldrh r0, [r6, #6]
	cmp r0, #0x1f
	bls _0801A514
	adds r4, r6, #0
	adds r4, #0x18
	movs r1, #1
	movs r2, #2
	mov r8, r2
_0801A4FC:
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r7, #1
	rsbs r7, r7, #0
	add r8, r7
	adds r4, #0x28
	mov r0, r8
	cmp r0, #0
	bge _0801A4FC
	movs r0, #0
	strb r0, [r6]
_0801A514:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801A524: .4byte 0x085B0A08
_0801A528: .4byte 0x085AA970
_0801A52C: .4byte 0x030046B8
_0801A530: .4byte 0x000003FF
_0801A534: .4byte 0x0203B400

	thumb_func_start FUN_0801a538
FUN_0801a538: @ 0x0801A538
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	movs r7, #0
	adds r4, r5, #0
	adds r4, #0x2c
	ldr r0, _0801A568 @ =0x085AA974
	mov r8, r0
	movs r6, #2
_0801A55C:
	ldrb r0, [r4]
	cmp r0, #0
	bne _0801A56C
	adds r7, #1
	b _0801A582
	.align 2, 0
_0801A568: .4byte 0x085AA974
_0801A56C:
	ldrb r0, [r4]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	bl _call_via_r2
	ldrh r0, [r4, #6]
	adds r0, #1
	strh r0, [r4, #6]
_0801A582:
	subs r6, #1
	adds r4, #0x90
	cmp r6, #0
	bge _0801A55C
	cmp r7, #3
	bne _0801A5A4
	ldrh r0, [r5, #0x1a]
	cmp r0, #0
	beq _0801A59E
	movs r1, #0
	bl Script_ExecById
	movs r0, #0
	strh r0, [r5, #0x1a]
_0801A59E:
	adds r0, r5, #0
	bl KillEntity
_0801A5A4:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801a5b0
FUN_0801a5b0: @ 0x0801A5B0
	push {r4, r5, r6, r7, lr}
	adds r0, #0x2c
	movs r1, #0
_0801A5B6:
	adds r6, r1, #1
	adds r7, r0, #0
	adds r7, #0x90
	adds r4, r0, #0
	adds r4, #0x18
	movs r5, #2
_0801A5C2:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x28
	subs r5, #1
	cmp r5, #0
	bge _0801A5C2
	adds r1, r6, #0
	adds r0, r7, #0
	cmp r1, #2
	ble _0801A5B6
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801a5e0
FUN_0801a5e0: @ 0x0801A5E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, _0801A604 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xee
	lsls r1, r1, #1
	adds r5, r7, r1
	str r0, [r5]
	cmp r0, #0
	bne _0801A608
	movs r0, #1
	rsbs r0, r0, #0
	b _0801A7FA
	.align 2, 0
_0801A604: .4byte 0x03002BE0
_0801A608:
	movs r0, #0x65
	movs r1, #0
	bl Script_GetKeywordValue
	movs r4, #0
	strh r0, [r7, #0x1a]
	ldr r3, [r5]
	ldr r0, [r3, #0x2c]
	ldr r1, [r3, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, [sp]
	asrs r0, r2, #0x10
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r1, _0801A6E4 @ =0x0000FFFF
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	ldr r0, [r3, #0x2c]
	ldr r1, [r3, #0x30]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	strh r4, [r7, #0x18]
	ldr r0, _0801A6E8 @ =0x00001C1C
	bl GetParticleGroup
	str r0, [r7, #0x24]
	ldr r0, _0801A6EC @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r7, #0x28]
	adds r5, r7, #0
	adds r5, #0x2c
	mov r8, r4
	ldr r2, _0801A6F0 @ =0x030046B8
	mov sl, r2
_0801A656:
	adds r4, r5, #0
	adds r4, #0x18
	movs r0, #1
	strb r0, [r5]
	strb r0, [r5, #1]
	mov r3, sl
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _0801A6F4 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _0801A6F8 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	strb r0, [r5, #2]
	movs r3, #0
	strb r3, [r5, #3]
	mov r1, r8
	lsls r0, r1, #8
	movs r1, #3
	bl Div
	mov r3, sl
	ldr r2, [r3]
	adds r2, #1
	ldr r1, _0801A6F4 @ =0x000003FF
	ands r2, r1
	str r2, [r3]
	lsls r1, r2, #1
	ldr r3, _0801A6F8 @ =0x0203B400
	adds r1, r1, r3
	ldrh r1, [r1]
	movs r3, #0x3f
	ands r1, r3
	adds r0, r0, r1
	strb r0, [r5, #4]
	movs r0, #0
	strh r0, [r5, #6]
	ldrb r1, [r5, #4]
	adds r2, #1
	ldr r3, _0801A6F4 @ =0x000003FF
	ands r2, r3
	mov r0, sl
	str r2, [r0]
	lsls r2, r2, #1
	ldr r3, _0801A6F8 @ =0x0203B400
	adds r2, r2, r3
	ldrh r2, [r2]
	movs r0, #0x3f
	adds r3, r5, #0
	adds r3, #8
	adds r6, r1, #0
	ands r2, r0
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r1, _0801A6FC @ =0x085B0A08
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _0801A700
	asrs r0, r0, #0xc
	b _0801A706
	.align 2, 0
_0801A6E4: .4byte 0x0000FFFF
_0801A6E8: .4byte 0x00001C1C
_0801A6EC: .4byte 0x00001C1E
_0801A6F0: .4byte 0x030046B8
_0801A6F4: .4byte 0x000003FF
_0801A6F8: .4byte 0x0203B400
_0801A6FC: .4byte 0x085B0A08
_0801A700:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0801A706:
	strh r0, [r3]
	movs r0, #0
	strh r0, [r3, #2]
	lsls r0, r6, #1
	ldr r1, _0801A720 @ =0x085B0A08
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _0801A724
	asrs r0, r0, #0xc
	b _0801A72A
	.align 2, 0
_0801A720: .4byte 0x085B0A08
_0801A724:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0801A72A:
	strh r0, [r3, #4]
	mov r2, sl
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _0801A7A8 @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0801A7AC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	subs r0, #0x24
	strb r0, [r5, #5]
	mov r2, sp
	ldrh r0, [r2]
	ldrh r3, [r5, #8]
	adds r0, r0, r3
	strh r0, [r5, #8]
	ldr r1, _0801A7B0 @ =0x085AA980
	mov r2, r8
	lsls r0, r2, #1
	adds r0, r0, r1
	ldr r3, [sp]
	asrs r1, r3, #0x10
	ldrh r0, [r0]
	adds r1, r1, r0
	ldrh r0, [r5, #0xa]
	adds r0, r0, r1
	strh r0, [r5, #0xa]
	mov r1, sp
	ldrh r0, [r1, #4]
	ldrh r2, [r5, #0xc]
	adds r0, r0, r2
	strh r0, [r5, #0xc]
	movs r6, #0
	movs r3, #1
	add r8, r3
	movs r0, #0x90
	adds r0, r0, r5
	mov sb, r0
_0801A77E:
	ldr r1, [r7, #0x24]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	cmp r6, #0
	bne _0801A7B4
	ldr r1, [r7, #0x24]
	adds r0, r4, #0
	movs r2, #0x1c
	bl FUN_0822dafc
	ldr r0, [r7, #0x24]
	ldrh r0, [r0, #6]
	b _0801A7C4
	.align 2, 0
_0801A7A8: .4byte 0x000003FF
_0801A7AC: .4byte 0x0203B400
_0801A7B0: .4byte 0x085AA980
_0801A7B4:
	ldr r1, [r7, #0x28]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_0822dafc
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #6]
	adds r0, #1
_0801A7C4:
	strb r0, [r4, #0xe]
	ldrh r0, [r5, #8]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrh r0, [r5, #0xa]
	ldrh r2, [r4, #0x1a]
	adds r0, r0, r2
	strh r0, [r4, #0x1a]
	ldrh r0, [r5, #0xc]
	ldrh r3, [r4, #0x1c]
	adds r0, r0, r3
	strh r0, [r4, #0x1c]
	adds r6, #1
	adds r4, #0x28
	cmp r6, #2
	ble _0801A77E
	mov r5, sb
	mov r0, r8
	cmp r0, #2
	bgt _0801A7F0
	b _0801A656
_0801A7F0:
	movs r0, #0x9f
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r0, #0
_0801A7FA:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801a80c
FUN_0801a80c: @ 0x0801A80C
	push {r4, lr}
	movs r1, #0xf0
	lsls r1, r1, #1
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801A844
	ldr r1, _0801A83C @ =FUN_0801a538
	ldr r2, _0801A840 @ =FUN_0801a5b0
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0801a5e0
	cmp r0, #0
	bge _0801A844
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801A846
	.align 2, 0
_0801A83C: .4byte FUN_0801a538
_0801A840: .4byte FUN_0801a5b0
_0801A844:
	adds r0, r4, #0
_0801A846:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801a84c
FUN_0801a84c: @ 0x0801A84C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, [r4, #0x18]
	cmp r1, #7
	bhi _0801A868
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	beq _0801A880
	ldr r0, [r4, #0x44]
	movs r1, #1
	orrs r0, r1
	b _0801A888
_0801A868:
	cmp r1, #0xf
	bhi _0801A87C
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	bls _0801A880
	ldr r0, [r4, #0x44]
	movs r1, #1
	orrs r0, r1
	b _0801A888
_0801A87C:
	cmp r1, #0x10
	bne _0801A88A
_0801A880:
	ldr r0, [r4, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_0801A888:
	str r0, [r4, #0x44]
_0801A88A:
	ldr r0, [r4, #0x18]
	cmp r0, #0x1e
	bne _0801A8A4
	adds r0, r4, #0
	adds r0, #0x3c
	adds r1, r4, #0
	adds r1, #0x1c
	movs r2, #0
	str r2, [sp]
	movs r2, #0x19
	movs r3, #1
	bl FUN_082370cc
_0801A8A4:
	ldr r2, [r4, #0x18]
	cmp r2, #0x59
	bls _0801A8E2
	cmp r2, #0x69
	bhi _0801A8C0
	movs r0, #3
	ands r0, r2
	cmp r0, #1
	bhi _0801A8DA
	ldr r0, [r4, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _0801A8E0
_0801A8C0:
	cmp r2, #0x7e
	bhi _0801A8D6
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _0801A8DA
	ldr r0, [r4, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _0801A8E0
_0801A8D6:
	cmp r2, #0x7f
	bne _0801A8E2
_0801A8DA:
	ldr r0, [r4, #0x44]
	movs r1, #1
	orrs r0, r1
_0801A8E0:
	str r0, [r4, #0x44]
_0801A8E2:
	cmp r2, #0xb4
	bne _0801A900
	ldr r0, [r4, #0x44]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x44]
	adds r0, r4, #0
	adds r0, #0x9c
	ldr r0, [r0]
	cmp r0, #0
	beq _0801A912
	movs r1, #0
	bl Script_ExecById
	b _0801A912
_0801A900:
	adds r0, r4, #0
	adds r0, #0x3c
	adds r1, r4, #0
	adds r1, #0x1c
	bl FUN_082372cc
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
_0801A912:
	movs r0, #0
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801a91c
FUN_0801a91c: @ 0x0801A91C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0801A93C @ =FUN_0822db5c
	ldr r2, _0801A940 @ =FUN_0822aaac
	ldr r3, _0801A944 @ =FUN_0822f204
	movs r0, #0
	bl FUN_0822a448
	adds r4, #0x3c
	adds r0, r4, #0
	bl FUN_0822f1c0
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801A93C: .4byte FUN_0822db5c
_0801A940: .4byte FUN_0822aaac
_0801A944: .4byte FUN_0822f204

	thumb_func_start FUN_0801a948
FUN_0801a948: @ 0x0801A948
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x2c
	adds r6, r0, #0
	ldr r0, _0801A968 @ =0x0000CB05
	ldr r1, _0801A96C @ =0x0000D3DA
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _0801A970
	movs r0, #1
	rsbs r0, r0, #0
	b _0801AA84
	.align 2, 0
_0801A968: .4byte 0x0000CB05
_0801A96C: .4byte 0x0000D3DA
_0801A970:
	adds r1, r6, #0
	adds r1, #0x1c
	adds r0, r2, #0
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r6, #0
	adds r4, #0x1c
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	movs r0, #0x70
	bl prepare_08231510
	adds r7, r4, #0
	cmp r0, #0
	beq _0801A9CC
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0801A9C4 @ =0xFFFF0000
	ldr r1, [sp, #0x24]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x24]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0801A9C8 @ =0x0000FFFF
	ldr r1, [sp, #0x24]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x24]
	add r1, sp, #0x24
	ldr r0, [r1, #4]
	ands r0, r4
	b _0801A9E8
	.align 2, 0
_0801A9C4: .4byte 0xFFFF0000
_0801A9C8: .4byte 0x0000FFFF
_0801A9CC:
	ldr r2, _0801AA90 @ =0xFFFF0000
	ldr r0, [sp, #0x24]
	ands r0, r2
	movs r1, #0x78
	orrs r0, r1
	ldr r1, _0801AA94 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x24]
	add r1, sp, #0x24
	ldr r0, [r1, #4]
	ands r0, r2
_0801A9E8:
	str r0, [r1, #4]
	mov r8, r1
	movs r0, #0x65
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r6, #0
	adds r1, #0x9c
	str r0, [r1]
	movs r4, #0
	str r4, [r6, #0x18]
	adds r5, r6, #0
	adds r5, #0x3c
	ldr r3, _0801AA98 @ =0x00002011
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r0, r8
	str r0, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_0822f3fc
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r7, #0
	movs r2, #0x18
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _0801AA9C @ =FUN_0822e424
	ldr r2, _0801AAA0 @ =FUN_0822af38
	ldr r3, _0801AAA4 @ =FUN_0822f264
	movs r0, #0
	bl FUN_0822a448
	movs r0, #2
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	movs r0, #0x1f
	str r0, [sp, #0x18]
	str r0, [sp, #0x1c]
	str r0, [sp, #0x20]
	movs r0, #3
	movs r1, #5
	add r2, sp, #0x10
	bl FUN_08002800
	movs r2, #0
	adds r4, r6, #0
	adds r4, #0xa0
	movs r1, #0x76
	adds r1, r1, r6
	mov ip, r1
	adds r5, #0x48
	adds r6, r4, #0
	ldr r1, _0801AAA8 @ =0x00001084
_0801AA60:
	lsls r0, r2, #5
	adds r3, r2, #1
	movs r2, #0xf
	adds r0, r0, r6
	adds r0, #0x1e
_0801AA6A:
	strh r1, [r0]
	subs r0, #2
	subs r2, #1
	cmp r2, #0
	bge _0801AA6A
	adds r2, r3, #0
	cmp r2, #0xf
	ble _0801AA60
	ldr r0, _0801AAAC @ =0x00006541
	mov r3, ip
	strh r0, [r3]
	str r4, [r5]
	movs r0, #0
_0801AA84:
	add sp, #0x2c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801AA90: .4byte 0xFFFF0000
_0801AA94: .4byte 0x0000FFFF
_0801AA98: .4byte 0x00002011
_0801AA9C: .4byte FUN_0822e424
_0801AAA0: .4byte FUN_0822af38
_0801AAA4: .4byte FUN_0822f264
_0801AAA8: .4byte 0x00001084
_0801AAAC: .4byte 0x00006541

	thumb_func_start FUN_0801aab0
FUN_0801aab0: @ 0x0801AAB0
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xa8
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801AAEC
	ldr r1, _0801AAE4 @ =FUN_0801a84c
	ldr r2, _0801AAE8 @ =FUN_0801a91c
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0801a948
	cmp r0, #0
	bge _0801AAEC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801AAEE
	.align 2, 0
_0801AAE4: .4byte FUN_0801a84c
_0801AAE8: .4byte FUN_0801a91c
_0801AAEC:
	adds r0, r4, #0
_0801AAEE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801aaf4
FUN_0801aaf4: @ 0x0801AAF4
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	movs r0, #8
	adds r0, r0, r1
	mov sb, r0
	ldr r0, [r1, #8]
	movs r3, #2
	rsbs r3, r3, #0
	ands r0, r3
	str r0, [r1, #8]
	movs r0, #0
	mov r8, r0
	movs r6, #1
	movs r0, #1
	strb r0, [r1]
	ldr r5, _0801ABA4 @ =0x0203B400
	ldr r3, _0801ABA8 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r4, _0801ABAC @ =0x000003FF
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r2, r6
	adds r2, #3
	ands r0, r6
	adds r2, r2, r0
	strb r2, [r1, #1]
	ldr r0, [r3]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	adds r0, #5
	ldrb r2, [r1, #1]
	subs r0, r0, r2
	asrs r0, r0, #2
	strb r0, [r1, #2]
	ldr r0, [r3]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #7
	ands r0, r2
	adds r0, #1
	strb r0, [r1, #3]
	mov r2, r8
	strb r2, [r1, #4]
	mov r0, r8
	strh r0, [r1, #6]
	ldr r0, [r3]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrb r1, [r1]
	subs r1, #0x10
	mov r2, sb
	strh r1, [r2, #0x1c]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r0, #0xa0
	strh r0, [r2, #0x1e]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801ABA4: .4byte 0x0203B400
_0801ABA8: .4byte 0x030046B8
_0801ABAC: .4byte 0x000003FF

	thumb_func_start FUN_0801abb0
FUN_0801abb0: @ 0x0801ABB0
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	adds r4, r6, #0
	adds r4, #8
	adds r1, r5, #0
	adds r1, #0x1c
	adds r0, r4, #0
	movs r2, #0x11
	bl FUN_0822a470
	ldr r1, _0801ABF0 @ =0x085AA988
	movs r0, #3
	mov r2, r8
	ands r0, r2
	adds r0, r0, r1
	ldrb r0, [r0]
	strh r0, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #7]
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_0801aaf4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801ABF0: .4byte 0x085AA988

	thumb_func_start FUN_0801abf4
FUN_0801abf4: @ 0x0801ABF4
	push {lr}
	adds r0, r1, #0
	adds r0, #8
	bl FUN_0822a4e0
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801ac04
FUN_0801ac04: @ 0x0801AC04
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0x38
	movs r6, #0
	ldr r0, _0801ACC8 @ =0x030046B8
	mov sl, r0
	ldr r1, _0801ACCC @ =0x085B0A08
	mov sb, r1
	movs r2, #0xff
	mov r8, r2
_0801AC22:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801ACB0
	adds r5, r4, #0
	adds r5, #8
	mov r1, sl
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _0801ACD0 @ =0x000003FF
	ands r0, r1
	mov r2, sl
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0801ACD4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #1
	ands r2, r0
	ldrb r1, [r4, #3]
	adds r1, r1, r2
	ldrb r0, [r4, #4]
	adds r0, r0, r1
	strb r0, [r4, #4]
	movs r3, #4
	ldrsb r3, [r4, r3]
	cmp r3, #0
	bge _0801AC5A
	rsbs r3, r3, #0
_0801AC5A:
	adds r0, r3, #0
	adds r0, #0x40
	mov r2, r8
	ands r0, r2
	lsls r0, r0, #1
	add r0, sb
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #2
	ldrsb r0, [r4, r0]
	adds r2, r1, #0
	muls r2, r0, r2
	mov r0, r8
	ands r3, r0
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrb r1, [r4, #1]
	muls r1, r0, r1
	asrs r1, r1, #0xc
	asrs r2, r2, #0xc
	ldrh r0, [r5, #0x1c]
	adds r2, r2, r0
	strh r2, [r5, #0x1c]
	ldrh r0, [r5, #0x1e]
	subs r0, r0, r1
	strh r0, [r5, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x14
	rsbs r1, r1, #0
	cmp r0, r1
	bgt _0801ACB0
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_0801aaf4
_0801ACB0:
	adds r6, #1
	adds r4, #0x34
	cmp r6, #0x1f
	ble _0801AC22
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801ACC8: .4byte 0x030046B8
_0801ACCC: .4byte 0x085B0A08
_0801ACD0: .4byte 0x000003FF
_0801ACD4: .4byte 0x0203B400

	thumb_func_start FUN_0801acd8
FUN_0801acd8: @ 0x0801ACD8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x38
	movs r4, #0
_0801ACE2:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0801abf4
	adds r4, #1
	adds r5, #0x34
	cmp r4, #0x1f
	ble _0801ACE2
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801acfc
FUN_0801acfc: @ 0x0801ACFC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x38
	adds r0, #0x1c
	ldr r1, _0801AD28 @ =0x00002E7B
	bl FUN_0822b16c
	movs r4, #0
_0801AD0E:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0801abb0
	adds r4, #1
	adds r5, #0x34
	cmp r4, #0x1f
	ble _0801AD0E
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801AD28: .4byte 0x00002E7B

	thumb_func_start FUN_0801ad2c
FUN_0801ad2c: @ 0x0801AD2C
	push {r4, lr}
	movs r1, #0xd7
	lsls r1, r1, #3
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801AD64
	ldr r1, _0801AD5C @ =FUN_0801ac04
	ldr r2, _0801AD60 @ =FUN_0801acd8
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0801acfc
	cmp r0, #0
	bge _0801AD64
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801AD66
	.align 2, 0
_0801AD5C: .4byte FUN_0801ac04
_0801AD60: .4byte FUN_0801acd8
_0801AD64:
	adds r0, r4, #0
_0801AD66:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801ad6c
FUN_0801ad6c: @ 0x0801AD6C
	ldr r1, _0801AD74 @ =0x03000094
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0801AD74: .4byte 0x03000094

	thumb_func_start FUN_0801ad78
FUN_0801ad78: @ 0x0801AD78
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	mov r8, r1
	ldrh r0, [r6, #0x18]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x14
	adds r2, r1, #0
	adds r0, r1, #0
	muls r0, r1, r0
	mov sb, r0
	ldr r3, _0801AE60 @ =0x000002F6
	adds r0, r6, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r3, r0, r1
	cmp r3, #0
	bge _0801ADA6
	movs r3, #0
_0801ADA6:
	adds r7, r0, r1
	cmp r7, #0xb4
	ble _0801ADAE
	movs r7, #0xb4
_0801ADAE:
	subs r0, r2, r0
	mov r0, r8
	lsls r2, r0, #1
	adds r1, r2, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x24
	adds r5, r6, r0
	mov sl, r2
	cmp r3, #0
	ble _0801ADD4
	movs r0, #0
	adds r4, r3, #0
_0801ADCA:
	strh r0, [r5]
	subs r4, #1
	adds r5, #2
	cmp r4, #0
	bne _0801ADCA
_0801ADD4:
	adds r4, r3, #0
	cmp r4, r7
	bge _0801AE28
	movs r3, #0xff
_0801ADDC:
	ldr r1, _0801AE60 @ =0x000002F6
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r0, r0, r4
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	mov r2, sb
	subs r0, r2, r0
	str r3, [sp]
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r2, r1, r0
	adds r1, r1, r0
	ldr r3, [sp]
	cmp r2, #0
	bge _0801AE10
	movs r2, #0
_0801AE10:
	cmp r1, #0xf0
	ble _0801AE16
	movs r1, #0xf0
_0801AE16:
	ands r2, r3
	lsls r0, r2, #8
	ands r1, r3
	orrs r0, r1
	strh r0, [r5]
	adds r4, #1
	adds r5, #2
	cmp r4, r7
	blt _0801ADDC
_0801AE28:
	adds r4, r7, #0
	cmp r4, #0xb3
	bgt _0801AE3A
	movs r0, #0
_0801AE30:
	strh r0, [r5]
	adds r4, #1
	adds r5, #2
	cmp r4, #0xb3
	ble _0801AE30
_0801AE3A:
	mov r1, sl
	add r1, r8
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r6, r3
	adds r1, r1, r0
	movs r0, #0
	strh r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801AE60: .4byte 0x000002F6

	thumb_func_start FUN_0801ae64
FUN_0801ae64: @ 0x0801AE64
	ldr r0, _0801AE7C @ =0x03003518
	movs r1, #0
	str r1, [r0]
	ldr r0, _0801AE80 @ =0x03002CA0
	str r1, [r0]
	ldr r2, _0801AE84 @ =0x03003510
	movs r0, #1
	strh r0, [r2]
	ldr r0, _0801AE88 @ =0x03003514
	strh r1, [r0]
	bx lr
	.align 2, 0
_0801AE7C: .4byte 0x03003518
_0801AE80: .4byte 0x03002CA0
_0801AE84: .4byte 0x03003510
_0801AE88: .4byte 0x03003514

	thumb_func_start FUN_0801ae8c
FUN_0801ae8c: @ 0x0801AE8C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _0801AED8 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0801AF70
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, [sp]
	asrs r1, r2, #0x10
	adds r1, #0xa4
	lsls r1, r1, #0x10
	ldr r0, _0801AEDC @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r6, r5, r0
	mov r7, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0801AEE0
	asrs r0, r0, #8
	b _0801AEE6
	.align 2, 0
_0801AED8: .4byte 0x03002BE0
_0801AEDC: .4byte 0x0000FFFF
_0801AEE0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801AEE6:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0801AEF8
	asrs r0, r0, #8
	b _0801AEFE
_0801AEF8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801AEFE:
	adds r4, r0, #0
	movs r2, #2
	ldrsh r1, [r7, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0801AF12
	asrs r0, r0, #8
	b _0801AF18
_0801AF12:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801AF18:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0801AF48 @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _0801AF4C
	movs r0, #0
	b _0801AF52
	.align 2, 0
_0801AF48: .4byte 0x030047C8
_0801AF4C:
	cmp r0, #0xf0
	ble _0801AF54
	movs r0, #0xf0
_0801AF52:
	strh r0, [r1]
_0801AF54:
	ldr r0, _0801AF64 @ =0x000002F6
	adds r1, r5, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _0801AF68
	movs r0, #0
	b _0801AF80
	.align 2, 0
_0801AF64: .4byte 0x000002F6
_0801AF68:
	cmp r0, #0xb4
	ble _0801AF82
	movs r0, #0xb4
	b _0801AF80
_0801AF70:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #0x78
	strh r0, [r1]
	ldr r2, _0801AFDC @ =0x000002F6
	adds r1, r5, r2
	movs r0, #0x5a
_0801AF80:
	strh r0, [r1]
_0801AF82:
	ldrh r1, [r5, #0x22]
	movs r4, #1
	subs r1, r4, r1
	adds r0, r5, #0
	bl FUN_0801ad78
	ldr r2, _0801AFE0 @ =0x03003518
	ldrh r0, [r5, #0x22]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x24
	adds r0, r5, r0
	str r0, [r2]
	ldr r1, _0801AFE4 @ =0x03002CA0
	ldr r0, _0801AFE8 @ =0x04000040
	str r0, [r1]
	ldr r0, _0801AFEC @ =0x03003510
	strh r4, [r0]
	ldr r0, _0801AFF0 @ =0x03003514
	strh r4, [r0]
	ldrh r0, [r5, #0x1a]
	cmp r0, #0
	beq _0801AFF8
	ldrh r0, [r5, #0x1c]
	ldrh r1, [r5, #0x18]
	adds r0, r0, r1
	strh r0, [r5, #0x18]
	lsls r0, r0, #0x10
	ldr r1, _0801AFF4 @ =0x0F9F0000
	cmp r0, r1
	ble _0801B01A
	movs r0, #0xfa
	lsls r0, r0, #4
	strh r0, [r5, #0x18]
	ldrb r0, [r5, #0x1e]
	cmp r0, #0
	beq _0801B01A
	adds r0, r5, #0
	bl KillEntity
	b _0801B01A
	.align 2, 0
_0801AFDC: .4byte 0x000002F6
_0801AFE0: .4byte 0x03003518
_0801AFE4: .4byte 0x03002CA0
_0801AFE8: .4byte 0x04000040
_0801AFEC: .4byte 0x03003510
_0801AFF0: .4byte 0x03003514
_0801AFF4: .4byte 0x0F9F0000
_0801AFF8:
	ldrh r0, [r5, #0x18]
	ldrh r1, [r5, #0x1c]
	subs r0, r0, r1
	strh r0, [r5, #0x18]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	bgt _0801B01A
	strh r1, [r5, #0x18]
	ldrb r0, [r5, #0x1e]
	cmp r0, #0
	beq _0801B01A
	adds r0, r5, #0
	bl KillEntity
_0801B01A:
	ldrh r0, [r5, #0x22]
	movs r1, #1
	subs r1, r1, r0
	strh r1, [r5, #0x22]
	ldrh r0, [r5, #0x20]
	adds r0, #1
	strh r0, [r5, #0x20]
	movs r0, #0
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801b034
FUN_0801b034: @ 0x0801B034
	push {lr}
	sub sp, #4
	bl FUN_0801ae64
	bl VBlankIntrWait
	movs r0, #0xb4
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0xf0
	bl FUN_0822cdcc
	ldr r1, _0801B05C @ =0x03000094
	movs r0, #0
	str r0, [r1]
	add sp, #4
	pop {r1}
	bx r1
	.align 2, 0
_0801B05C: .4byte 0x03000094

	thumb_func_start FUN_0801b060
FUN_0801b060: @ 0x0801B060
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _0801B0D8 @ =0x03000094
	str r5, [r0]
	movs r0, #0
	strh r0, [r5, #0x20]
	strh r0, [r5, #0x22]
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r5, #0x1a]
	movs r0, #0x72
	movs r1, #0xfa
	bl Script_GetKeywordValue
	lsls r1, r0, #4
	strh r1, [r5, #0x18]
	lsls r0, r0, #0x14
	ldr r1, _0801B0DC @ =0x0F9F0000
	cmp r0, r1
	ble _0801B092
	movs r0, #0xfa
	lsls r0, r0, #4
	strh r0, [r5, #0x18]
_0801B092:
	movs r0, #0x73
	movs r1, #8
	bl Script_GetKeywordValue
	lsls r0, r0, #4
	strh r0, [r5, #0x1c]
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	strb r0, [r5, #0x1e]
	ldr r0, _0801B0E0 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0801B174
	movs r1, #0xbd
	lsls r1, r1, #2
	adds r6, r5, r1
	adds r7, r0, #0
	adds r7, #0x2c
	ldrh r0, [r0, #0x2c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0801B0E4
	asrs r0, r0, #8
	b _0801B0EA
	.align 2, 0
_0801B0D8: .4byte 0x03000094
_0801B0DC: .4byte 0x0F9F0000
_0801B0E0: .4byte 0x03002BE0
_0801B0E4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801B0EA:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0801B0FC
	asrs r0, r0, #8
	b _0801B102
_0801B0FC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801B102:
	adds r4, r0, #0
	movs r2, #2
	ldrsh r1, [r7, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0801B116
	asrs r0, r0, #8
	b _0801B11C
_0801B116:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801B11C:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0801B14C @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _0801B150
	movs r0, #0
	b _0801B156
	.align 2, 0
_0801B14C: .4byte 0x030047C8
_0801B150:
	cmp r0, #0xf0
	ble _0801B158
	movs r0, #0xf0
_0801B156:
	strh r0, [r1]
_0801B158:
	ldr r0, _0801B168 @ =0x000002F6
	adds r1, r5, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _0801B16C
	movs r0, #0
	b _0801B184
	.align 2, 0
_0801B168: .4byte 0x000002F6
_0801B16C:
	cmp r0, #0xb4
	ble _0801B186
	movs r0, #0xb4
	b _0801B184
_0801B174:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #0x78
	strh r0, [r1]
	ldr r2, _0801B19C @ =0x000002F6
	adds r1, r5, r2
	movs r0, #0x5a
_0801B184:
	strh r0, [r1]
_0801B186:
	movs r4, #0
_0801B188:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0801ad78
	adds r4, #1
	cmp r4, #1
	ble _0801B188
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801B19C: .4byte 0x000002F6

	thumb_func_start FUN_0801b1a0
FUN_0801b1a0: @ 0x0801B1A0
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x61
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _0801B1C4 @ =0x03000094
	ldr r0, [r0]
	cmp r0, #0
	bne _0801B206
	cmp r1, #0
	beq _0801B1C8
	movs r1, #0xc0
	lsls r1, r1, #2
	movs r0, #0xb
	b _0801B1CE
	.align 2, 0
_0801B1C4: .4byte 0x03000094
_0801B1C8:
	movs r1, #0xc0
	lsls r1, r1, #2
	movs r0, #9
_0801B1CE:
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801B204
	ldr r1, _0801B1FC @ =FUN_0801ae8c
	ldr r2, _0801B200 @ =FUN_0801b034
	adds r0, r4, #0
	bl SetEntityRoutine
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0801b060
	cmp r0, #0
	bge _0801B204
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801B206
	.align 2, 0
_0801B1FC: .4byte FUN_0801ae8c
_0801B200: .4byte FUN_0801b034
_0801B204:
	adds r0, r4, #0
_0801B206:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801b20c
FUN_0801b20c: @ 0x0801B20C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	cmp r0, #1
	beq _0801B234
	cmp r0, #1
	blo _0801B220
	cmp r0, #2
	beq _0801B24A
	b _0801B268
_0801B220:
	ldr r2, [r4, #0x24]
	ldr r1, [r4, #0x1c]
	cmp r2, r1
	bls _0801B22E
	subs r0, r2, #2
	str r0, [r4, #0x24]
	b _0801B268
_0801B22E:
	str r1, [r4, #0x24]
	adds r0, #1
	b _0801B242
_0801B234:
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
	ldr r1, [r4, #0x20]
	cmp r0, r1
	blo _0801B268
	movs r0, #2
_0801B242:
	str r0, [r4, #0x28]
	movs r0, #0
	str r0, [r4, #0x18]
	b _0801B268
_0801B24A:
	ldr r0, [r4, #0x24]
	cmp r0, #0x3f
	bhi _0801B256
	adds r0, #2
	str r0, [r4, #0x24]
	b _0801B268
_0801B256:
	movs r0, #0x40
	str r0, [r4, #0x24]
	movs r0, #3
	str r0, [r4, #0x28]
	movs r0, #0
	str r0, [r4, #0x18]
	adds r0, r4, #0
	bl KillEntity
_0801B268:
	ldr r0, _0801B294 @ =0x03004460
	ldr r3, [r4, #0x24]
	str r3, [r0]
	ldr r1, _0801B298 @ =0x03004454
	ldr r2, _0801B29C @ =0x00001FFF
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _0801B2A0 @ =0x03004494
	ldr r1, _0801B2A4 @ =0x00001084
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, _0801B2A8 @ =0x0300445C
	str r3, [r0]
	ldr r1, _0801B2AC @ =0x03004490
	movs r0, #0x20
	strh r0, [r1]
	ldr r0, _0801B2B0 @ =0x03004464
	strh r2, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801B294: .4byte 0x03004460
_0801B298: .4byte 0x03004454
_0801B29C: .4byte 0x00001FFF
_0801B2A0: .4byte 0x03004494
_0801B2A4: .4byte 0x00001084
_0801B2A8: .4byte 0x0300445C
_0801B2AC: .4byte 0x03004490
_0801B2B0: .4byte 0x03004464

	thumb_func_start FUN_0801b2b4
FUN_0801b2b4: @ 0x0801B2B4
	ldr r0, _0801B2DC @ =0x03004460
	movs r3, #0x40
	str r3, [r0]
	ldr r1, _0801B2E0 @ =0x03004454
	ldr r2, _0801B2E4 @ =0x00001FFF
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _0801B2E8 @ =0x03004494
	ldr r1, _0801B2EC @ =0x00001084
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, _0801B2F0 @ =0x0300445C
	str r3, [r0]
	ldr r1, _0801B2F4 @ =0x03004490
	movs r0, #0
	strh r0, [r1]
	ldr r0, _0801B2F8 @ =0x03004464
	strh r2, [r0]
	movs r0, #0
	bx lr
	.align 2, 0
_0801B2DC: .4byte 0x03004460
_0801B2E0: .4byte 0x03004454
_0801B2E4: .4byte 0x00001FFF
_0801B2E8: .4byte 0x03004494
_0801B2EC: .4byte 0x00001084
_0801B2F0: .4byte 0x0300445C
_0801B2F4: .4byte 0x03004490
_0801B2F8: .4byte 0x03004464

	thumb_func_start FUN_0801b2fc
FUN_0801b2fc: @ 0x0801B2FC
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x72
	movs r1, #0x20
	bl Script_GetKeywordValue
	str r0, [r4, #0x1c]
	movs r0, #0x65
	movs r1, #0x78
	bl Script_GetKeywordValue
	str r0, [r4, #0x20]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801b31c
FUN_0801b31c: @ 0x0801B31C
	push {r4, lr}
	movs r0, #9
	movs r1, #0x2c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801B350
	ldr r1, _0801B348 @ =FUN_0801b20c
	ldr r2, _0801B34C @ =FUN_0801b2b4
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0801b2fc
	cmp r0, #0
	bge _0801B350
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801B352
	.align 2, 0
_0801B348: .4byte FUN_0801b20c
_0801B34C: .4byte FUN_0801b2b4
_0801B350:
	adds r0, r4, #0
_0801B352:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801b358
FUN_0801b358: @ 0x0801B358
	push {lr}
	sub sp, #0xc
	str r1, [sp]
	ldr r2, _0801B380 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r2
	movs r2, #1
	orrs r1, r2
	str r1, [sp, #4]
	add r1, sp, #4
	mov r2, sp
	str r2, [r1, #4]
	ldr r0, [r0, #0x28]
	cmp r0, #0
	beq _0801B37A
	bl Script_ExecById
_0801B37A:
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_0801B380: .4byte 0xFFFF0000

	thumb_func_start FUN_0801b384
FUN_0801b384: @ 0x0801B384
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x1e]
	adds r0, #1
	movs r5, #0
	strh r0, [r4, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3b
	ble _0801B39C
	strh r5, [r4, #0x1e]
	b _0801B4F0
_0801B39C:
	bl GetHour
	strh r0, [r4, #0x18]
	bl GetMinute
	strh r0, [r4, #0x1a]
	bl GetSecond
	strh r0, [r4, #0x1c]
	movs r1, #0x18
	ldrsh r0, [r4, r1]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, r1, r0
	lsls r1, r1, #4
	movs r3, #0x1a
	ldrsh r2, [r4, r3]
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r2, #0x1c
	ldrsh r0, [r4, r2]
	adds r1, r1, r0
	str r1, [r4, #0x20]
	ldr r0, _0801B408 @ =0x0000A8DE
	ldr r3, _0801B40C @ =0xFFFF5722
	adds r2, r1, r3
	cmp r1, r0
	bge _0801B3DC
	subs r2, r0, r1
_0801B3DC:
	ldr r0, _0801B410 @ =0x0000A8BF
	cmp r2, r0
	ble _0801B3E6
	ldr r0, _0801B414 @ =0xFFFEAE80
	adds r2, r2, r0
_0801B3E6:
	adds r0, r2, #0
	cmp r0, #0
	bge _0801B3EE
	rsbs r0, r0, #0
_0801B3EE:
	cmp r0, #0x1e
	bgt _0801B418
	adds r1, r4, #0
	adds r1, #0x2c
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801B420
	strb r5, [r1]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0801b358
	b _0801B420
	.align 2, 0
_0801B408: .4byte 0x0000A8DE
_0801B40C: .4byte 0xFFFF5722
_0801B410: .4byte 0x0000A8BF
_0801B414: .4byte 0xFFFEAE80
_0801B418:
	adds r1, r4, #0
	adds r1, #0x2c
	movs r0, #1
	strb r0, [r1]
_0801B420:
	ldr r2, _0801B474 @ =0x030047E0
	ldrb r0, [r2, #0xa]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, r1, r0
	lsls r1, r1, #4
	ldrb r2, [r2, #0xb]
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r3, [r4, #0x24]
	ldr r0, [r4, #0x20]
	subs r2, r0, r1
	cmp r0, r1
	bge _0801B444
	subs r2, r1, r0
_0801B444:
	ldr r0, _0801B478 @ =0x0000A8BF
	cmp r2, r0
	ble _0801B44E
	ldr r1, _0801B47C @ =0xFFFEAE80
	adds r2, r2, r1
_0801B44E:
	adds r0, r2, #0
	cmp r0, #0
	bge _0801B456
	rsbs r0, r0, #0
_0801B456:
	cmp r0, r3
	bgt _0801B480
	adds r1, r4, #0
	adds r1, #0x2d
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801B488
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0801b358
	b _0801B488
	.align 2, 0
_0801B474: .4byte 0x030047E0
_0801B478: .4byte 0x0000A8BF
_0801B47C: .4byte 0xFFFEAE80
_0801B480:
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #1
	strb r0, [r1]
_0801B488:
	ldr r2, _0801B4DC @ =0x030047E0
	ldrb r0, [r2, #0xc]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, r1, r0
	lsls r1, r1, #4
	ldrb r2, [r2, #0xd]
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r3, [r4, #0x24]
	ldr r0, [r4, #0x20]
	subs r2, r0, r1
	cmp r0, r1
	bge _0801B4AC
	subs r2, r1, r0
_0801B4AC:
	ldr r0, _0801B4E0 @ =0x0000A8BF
	cmp r2, r0
	ble _0801B4B6
	ldr r0, _0801B4E4 @ =0xFFFEAE80
	adds r2, r2, r0
_0801B4B6:
	adds r0, r2, #0
	cmp r0, #0
	bge _0801B4BE
	rsbs r0, r0, #0
_0801B4BE:
	cmp r0, r3
	bgt _0801B4E8
	adds r1, r4, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801B4F0
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #2
	bl FUN_0801b358
	b _0801B4F0
	.align 2, 0
_0801B4DC: .4byte 0x030047E0
_0801B4E0: .4byte 0x0000A8BF
_0801B4E4: .4byte 0xFFFEAE80
_0801B4E8:
	adds r1, r4, #0
	adds r1, #0x2e
	movs r0, #1
	strb r0, [r1]
_0801B4F0:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
_0801B4F8:
	.byte 0x00, 0x20, 0x70, 0x47

	thumb_func_start FUN_0801b4fc
FUN_0801b4fc: @ 0x0801B4FC
	push {r4, lr}
	adds r4, r0, #0
	bl GetHour
	strh r0, [r4, #0x18]
	bl GetMinute
	strh r0, [r4, #0x1a]
	bl GetSecond
	strh r0, [r4, #0x1c]
	movs r1, #0x18
	ldrsh r0, [r4, r1]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, r1, r0
	lsls r1, r1, #4
	movs r0, #0x1a
	ldrsh r2, [r4, r0]
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r2, #0x1c
	ldrsh r0, [r4, r2]
	adds r1, r1, r0
	str r1, [r4, #0x20]
	movs r0, #0x64
	movs r1, #0x3c
	bl Script_GetKeywordValue
	str r0, [r4, #0x24]
	movs r0, #0x70
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [r4, #0x28]
	movs r2, #1
	movs r1, #3
	adds r0, r4, #0
	adds r0, #0x2f
_0801B550:
	strb r2, [r0]
	subs r0, #1
	subs r1, #1
	cmp r1, #0
	bge _0801B550
	movs r0, #0
	strh r0, [r4, #0x1e]
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801b564
FUN_0801b564: @ 0x0801B564
	push {r4, lr}
	movs r0, #8
	movs r1, #0x30
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801B598
	ldr r1, _0801B590 @ =FUN_0801b384
	ldr r2, _0801B594 @ =0x0801B4F9
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0801b4fc
	cmp r0, #0
	bge _0801B598
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801B59A
	.align 2, 0
_0801B590: .4byte FUN_0801b384
_0801B594: .4byte 0x0801B4F9
_0801B598:
	adds r0, r4, #0
_0801B59A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801b5a0
FUN_0801b5a0: @ 0x0801B5A0
	push {lr}
	adds r1, r0, #0
	ldr r0, _0801B5B4 @ =0x03004250
	adds r1, #0x20
	ldr r2, _0801B5B8 @ =0x04000080
	bl CpuSet
	pop {r0}
	bx r0
	.align 2, 0
_0801B5B4: .4byte 0x03004250
_0801B5B8: .4byte 0x04000080

	thumb_func_start FUN_0801b5bc
FUN_0801b5bc: @ 0x0801B5BC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0800271c
	cmp r0, #0
	beq _0801B5CE
	adds r0, r4, #0
	bl FUN_0801b5a0
_0801B5CE:
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
	cmp r0, #3
	ble _0801B606
	movs r1, #0
	str r1, [r4, #0x18]
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	cmp r0, #6
	ble _0801B5E8
	str r1, [r4, #0x1c]
_0801B5E8:
	movs r1, #0
	adds r3, r4, #0
	adds r3, #0x20
	ldr r2, _0801B610 @ =0x03004250
_0801B5F0:
	ldr r0, [r4, #0x1c]
	lsls r0, r0, #4
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r3, r0
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r1, #1
	cmp r1, #0xf
	ble _0801B5F0
_0801B606:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801B610: .4byte 0x03004250
_0801B614:
	.byte 0x00, 0x20, 0x70, 0x47

	thumb_func_start FUN_0801b618
FUN_0801b618: @ 0x0801B618
	push {lr}
	bl FUN_0801b5a0
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_0801b624
FUN_0801b624: @ 0x0801B624
	push {r4, lr}
	movs r1, #0x88
	lsls r1, r1, #2
	movs r0, #0xc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801B65C
	ldr r1, _0801B654 @ =FUN_0801b5bc
	ldr r2, _0801B658 @ =0x0801B615
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0801b618
	cmp r0, #0
	bge _0801B65C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801B65E
	.align 2, 0
_0801B654: .4byte FUN_0801b5bc
_0801B658: .4byte 0x0801B615
_0801B65C:
	adds r0, r4, #0
_0801B65E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801b664
FUN_0801b664: @ 0x0801B664
	ldr r1, _0801B66C @ =0x03000098
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0801B66C: .4byte 0x03000098

	thumb_func_start FUN_0801b670
FUN_0801b670: @ 0x0801B670
	ldr r1, _0801B680 @ =0x03003584
	ldr r2, _0801B684 @ =0x000002DF
	adds r0, r0, r2
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	adds r0, r1, #0
	bx lr
	.align 2, 0
_0801B680: .4byte 0x03003584
_0801B684: .4byte 0x000002DF

	thumb_func_start FUN_0801b688
FUN_0801b688: @ 0x0801B688
	push {lr}
	adds r3, r0, #0
	adds r0, r1, #0
	adds r0, #0x24
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r3, r3, r2
	ldrb r2, [r1]
	adds r1, r3, #0
	movs r3, #0
	bl Sprite_SetSprite
	pop {r0}
	bx r0

	thumb_func_start FUN_0801b6a4
FUN_0801b6a4: @ 0x0801B6A4
	push {lr}
	bl GetWeaponSkillLevel
	movs r1, #0xa
	bl Div
	adds r0, #6
	cmp r0, #5
	bgt _0801B6BA
	movs r0, #6
	b _0801B6C0
_0801B6BA:
	cmp r0, #0xf
	ble _0801B6C0
	movs r0, #0xf
_0801B6C0:
	pop {r1}
	bx r1

	thumb_func_start weapon_0801b6c4
weapon_0801b6c4: @ 0x0801B6C4
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r7, r1, #0
	ldr r6, _0801B70C @ =0x08DA9E8C
	movs r4, #0
	movs r5, #0
	adds r2, r6, #0
	subs r2, #0x24
	movs r1, #0x41
_0801B6D6:
	ldrb r0, [r2, #1]
	cmp r0, r3
	bne _0801B6F2
	ldrb r0, [r2, #2]
	cmp r0, #4
	beq _0801B6F2
	ldrb r0, [r2, #3]
	cmp r0, r7
	bgt _0801B6F2
	cmp r0, r4
	blt _0801B6F2
	adds r6, r2, #0
	adds r4, r0, #0
	movs r5, #1
_0801B6F2:
	adds r2, #0x24
	subs r1, #1
	cmp r1, #0
	bge _0801B6D6
	cmp r5, #0
	bne _0801B728
	cmp r3, #1
	beq _0801B710
	cmp r3, #1
	ble _0801B720
	cmp r3, #2
	beq _0801B718
	b _0801B720
	.align 2, 0
_0801B70C: .4byte 0x08DA9E8C
_0801B710:
	ldr r0, _0801B714 @ =0x08DAA1C8
	b _0801B72A
	.align 2, 0
_0801B714: .4byte 0x08DAA1C8
_0801B718:
	ldr r0, _0801B71C @ =0x08DAA474
	b _0801B72A
	.align 2, 0
_0801B71C: .4byte 0x08DAA474
_0801B720:
	ldr r0, _0801B724 @ =0x08DA9F1C
	b _0801B72A
	.align 2, 0
_0801B724: .4byte 0x08DA9F1C
_0801B728:
	adds r0, r6, #0
_0801B72A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801b730
FUN_0801b730: @ 0x0801B730
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	ldr r6, _0801B768 @ =0x00000978
	add r6, r8
	ldr r7, _0801B76C @ =0x000009FC
	add r7, r8
	movs r5, #0xa8
	lsls r5, r5, #4
	add r5, r8
	ldrb r1, [r6, #1]
	ldrb r2, [r7, #1]
	cmp r1, r2
	bne _0801B804
	ldrb r1, [r6]
	adds r3, r1, #0
	ldrb r1, [r7]
	cmp r3, r1
	bne _0801B7B0
	ldrb r1, [r6, #3]
	ldrb r2, [r7, #3]
	adds r1, r1, r2
	asrs r4, r1, #1
	cmp r4, #0x63
	ble _0801B770
	movs r4, #0x63
	b _0801B776
	.align 2, 0
_0801B768: .4byte 0x00000978
_0801B76C: .4byte 0x000009FC
_0801B770:
	cmp r4, #0
	bgt _0801B776
	movs r4, #1
_0801B776:
	strb r3, [r5]
	ldrb r1, [r6, #1]
	strb r1, [r5, #1]
	ldrb r1, [r6, #2]
	strb r1, [r5, #2]
	strb r4, [r5, #3]
	ldrb r1, [r6, #4]
	strb r1, [r5, #4]
	ldr r3, _0801B7AC @ =0x08DA9E68
	ldrb r2, [r5]
	lsls r1, r2, #3
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	ldrh r1, [r1, #6]
	movs r4, #0
	strh r1, [r5, #6]
	lsls r1, r2, #3
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	ldrb r1, [r1, #5]
	strb r1, [r5, #5]
	mov r1, r8
	adds r1, #0x43
	strb r4, [r1]
	b _0801B8B2
	.align 2, 0
_0801B7AC: .4byte 0x08DA9E68
_0801B7B0:
	ldrb r0, [r6, #3]
	ldrb r1, [r7, #3]
	adds r0, r0, r1
	asrs r0, r0, #1
	adds r4, r0, #6
	cmp r4, #0x63
	ble _0801B7C2
	movs r4, #0x63
	b _0801B7C8
_0801B7C2:
	cmp r4, #0
	bgt _0801B7C8
	movs r4, #1
_0801B7C8:
	ldrb r0, [r6, #1]
	adds r1, r4, #0
	bl weapon_0801b6c4
	adds r2, r0, #0
	ldrb r1, [r2]
	strb r1, [r5]
	ldrb r1, [r2, #1]
	strb r1, [r5, #1]
	ldrb r1, [r2, #2]
	strb r1, [r5, #2]
	strb r4, [r5, #3]
	ldrb r1, [r2, #4]
	strb r1, [r5, #4]
	ldrh r1, [r2, #6]
	strh r1, [r5, #6]
	ldr r3, _0801B800 @ =0x08DA9E68
	ldrb r2, [r2]
	lsls r1, r2, #3
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	ldrb r1, [r1, #5]
	strb r1, [r5, #5]
	mov r2, r8
	adds r2, #0x43
	movs r1, #1
	b _0801B8B0
	.align 2, 0
_0801B800: .4byte 0x08DA9E68
_0801B804:
	ldr r2, _0801B834 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0801B838 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0801B83C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xd
	bl Mod
	ldrb r1, [r6, #3]
	ldrb r2, [r7, #3]
	adds r1, r1, r2
	asrs r1, r1, #1
	subs r1, #6
	adds r4, r1, r0
	cmp r4, #0x63
	ble _0801B840
	movs r4, #0x63
	b _0801B846
	.align 2, 0
_0801B834: .4byte 0x030046B8
_0801B838: .4byte 0x000003FF
_0801B83C: .4byte 0x0203B400
_0801B840:
	cmp r4, #0
	bgt _0801B846
	movs r4, #1
_0801B846:
	ldrb r0, [r6, #1]
	cmp r0, #0
	bne _0801B858
	ldrb r0, [r7, #1]
	movs r1, #1
	cmp r0, #1
	bne _0801B87A
	movs r1, #2
	b _0801B87A
_0801B858:
	cmp r0, #1
	bne _0801B868
	ldrb r0, [r7, #1]
	movs r1, #0
	cmp r0, #0
	bne _0801B87A
	movs r1, #2
	b _0801B87A
_0801B868:
	cmp r0, #2
	bne _0801B878
	ldrb r0, [r7, #1]
	movs r1, #0
	cmp r0, #0
	bne _0801B87A
	movs r1, #1
	b _0801B87A
_0801B878:
	movs r1, #0
_0801B87A:
	adds r0, r1, #0
	adds r1, r4, #0
	bl weapon_0801b6c4
	adds r2, r0, #0
	ldrb r1, [r2]
	strb r1, [r5]
	ldrb r1, [r2, #1]
	strb r1, [r5, #1]
	ldrb r1, [r2, #2]
	strb r1, [r5, #2]
	strb r4, [r5, #3]
	ldrb r1, [r2, #4]
	strb r1, [r5, #4]
	ldrh r1, [r2, #6]
	strh r1, [r5, #6]
	ldr r3, _0801B8CC @ =0x08DA9E68
	ldrb r2, [r2]
	lsls r1, r2, #3
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	ldrb r1, [r1, #5]
	strb r1, [r5, #5]
	mov r2, r8
	adds r2, #0x43
	movs r1, #2
_0801B8B0:
	strb r1, [r2]
_0801B8B2:
	movs r3, #8
	ldrsh r1, [r6, r3]
	movs r3, #8
	ldrsh r2, [r7, r3]
	adds r1, r1, r2
	asrs r1, r1, #1
	strh r1, [r5, #8]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801B8CC: .4byte 0x08DA9E68

	thumb_func_start FUN_0801b8d0
FUN_0801b8d0: @ 0x0801B8D0
	movs r2, #0
	str r2, [r0, #0x44]
	adds r3, r0, #0
	adds r3, #0x3c
	movs r2, #1
	strb r2, [r3]
	ldr r2, _0801B8E4 @ =0x00001304
	adds r0, r0, r2
	str r1, [r0]
	bx lr
	.align 2, 0
_0801B8E4: .4byte 0x00001304

	thumb_func_start FUN_0801b8e8
FUN_0801b8e8: @ 0x0801B8E8
	push {lr}
	adds r1, r0, #0
	adds r1, #0x3c
	ldrb r0, [r1]
	cmp r0, #0
	bne _0801B8F8
	movs r0, #0
	b _0801B8FE
_0801B8F8:
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
_0801B8FE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801b904
FUN_0801b904: @ 0x0801B904
	push {lr}
	ldrb r0, [r1, #2]
	cmp r0, #1
	beq _0801B924
	cmp r0, #1
	bgt _0801B916
	cmp r0, #0
	beq _0801B920
	b _0801B930
_0801B916:
	cmp r0, #2
	beq _0801B928
	cmp r0, #3
	beq _0801B92C
	b _0801B930
_0801B920:
	movs r0, #0x14
	b _0801B932
_0801B924:
	movs r0, #0x28
	b _0801B932
_0801B928:
	movs r0, #0x3c
	b _0801B932
_0801B92C:
	movs r0, #0x50
	b _0801B932
_0801B930:
	movs r0, #0
_0801B932:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801b938
FUN_0801b938: @ 0x0801B938
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r6, r5, r0
	ldr r0, _0801B96C @ =0x00000978
	adds r1, r5, r0
	adds r0, #0x84
	adds r2, r5, r0
	adds r0, r5, #0
	adds r0, #0xa0
	ldr r0, [r0]
	cmp r0, #0
	beq _0801B95E
	adds r0, r5, #0
	adds r0, #0xb0
	ldr r0, [r0]
	cmp r0, #9
	bls _0801B974
_0801B95E:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0
	str r0, [r1]
	ldr r0, _0801B970 @ =0x08DA9F1C
	b _0801BA52
	.align 2, 0
_0801B96C: .4byte 0x00000978
_0801B970: .4byte 0x08DA9F1C
_0801B974:
	ldrb r1, [r1]
	ldrb r0, [r2]
	cmp r1, #0x11
	bne _0801B980
	cmp r0, #0x12
	beq _0801B988
_0801B980:
	cmp r0, #0x11
	bne _0801B9A4
	cmp r1, #0x12
	bne _0801B9A4
_0801B988:
	adds r0, r5, #0
	adds r0, #0x60
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #9
	ble _0801B9A4
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0xc8
	str r0, [r1]
	ldr r0, _0801B9A0 @ =0x08DAA114
	b _0801BA52
	.align 2, 0
_0801B9A0: .4byte 0x08DAA114
_0801B9A4:
	ldrb r0, [r6, #1]
	bl GetWeaponSkillLevel
	adds r4, r0, #0
	ldr r2, _0801B9E0 @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ldr r0, _0801B9E4 @ =0x000003FF
	ands r1, r0
	str r1, [r2]
	lsls r1, r1, #1
	ldr r0, _0801B9E8 @ =0x0203B400
	adds r1, r1, r0
	ldr r0, _0801B9EC @ =0x03002CF0
	ldr r0, [r0]
	lsrs r0, r0, #2
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r1, #0x64
	bl Mod
	adds r2, r0, #0
	asrs r4, r4, #3
	adds r0, r5, #0
	adds r0, #0xa0
	ldr r1, [r0]
	cmp r1, #0xe
	bhi _0801B9F0
	movs r4, #0
	b _0801B9FC
	.align 2, 0
_0801B9E0: .4byte 0x030046B8
_0801B9E4: .4byte 0x000003FF
_0801B9E8: .4byte 0x0203B400
_0801B9EC: .4byte 0x03002CF0
_0801B9F0:
	adds r0, r5, #0
	adds r0, #0xa8
	ldr r0, [r0]
	cmp r0, r1
	bne _0801B9FC
	lsls r4, r4, #1
_0801B9FC:
	movs r0, #0
	cmp r2, r4
	bgt _0801BA04
	movs r0, #1
_0801BA04:
	cmp r0, #0
	beq _0801BA50
	ldrb r0, [r6, #2]
	cmp r0, #2
	beq _0801BA30
	cmp r0, #2
	bgt _0801BA18
	cmp r0, #1
	beq _0801BA1E
	b _0801BA50
_0801BA18:
	cmp r0, #3
	beq _0801BA40
	b _0801BA50
_0801BA1E:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0x50
	str r0, [r1]
	ldr r0, _0801BA2C @ =0x08DA9FD0
	b _0801BA52
	.align 2, 0
_0801BA2C: .4byte 0x08DA9FD0
_0801BA30:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0x78
	str r0, [r1]
	ldr r0, _0801BA3C @ =0x08DAA084
	b _0801BA52
	.align 2, 0
_0801BA3C: .4byte 0x08DAA084
_0801BA40:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0xa0
	str r0, [r1]
	ldr r0, _0801BA4C @ =0x08DAA0F0
	b _0801BA52
	.align 2, 0
_0801BA4C: .4byte 0x08DAA0F0
_0801BA50:
	movs r0, #0
_0801BA52:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801ba58
FUN_0801ba58: @ 0x0801BA58
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r6, r5, r0
	ldr r0, _0801BA8C @ =0x00000978
	adds r1, r5, r0
	adds r0, #0x84
	adds r2, r5, r0
	adds r0, r5, #0
	adds r0, #0xa0
	ldr r0, [r0]
	cmp r0, #0
	beq _0801BA7E
	adds r0, r5, #0
	adds r0, #0xb0
	ldr r0, [r0]
	cmp r0, #9
	bls _0801BA94
_0801BA7E:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0
	str r0, [r1]
	ldr r0, _0801BA90 @ =0x08DAA1C8
	b _0801BB72
	.align 2, 0
_0801BA8C: .4byte 0x00000978
_0801BA90: .4byte 0x08DAA1C8
_0801BA94:
	ldrb r1, [r1]
	ldrb r0, [r2]
	cmp r1, #0x24
	bne _0801BAA0
	cmp r0, #0x25
	beq _0801BAA8
_0801BAA0:
	cmp r0, #0x24
	bne _0801BAC4
	cmp r1, #0x25
	bne _0801BAC4
_0801BAA8:
	adds r0, r5, #0
	adds r0, #0x60
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #9
	ble _0801BAC4
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0xc8
	str r0, [r1]
	ldr r0, _0801BAC0 @ =0x08DAA3C0
	b _0801BB72
	.align 2, 0
_0801BAC0: .4byte 0x08DAA3C0
_0801BAC4:
	ldrb r0, [r6, #1]
	bl GetWeaponSkillLevel
	adds r4, r0, #0
	ldr r2, _0801BB00 @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ldr r0, _0801BB04 @ =0x000003FF
	ands r1, r0
	str r1, [r2]
	lsls r1, r1, #1
	ldr r0, _0801BB08 @ =0x0203B400
	adds r1, r1, r0
	ldr r0, _0801BB0C @ =0x03002CF0
	ldr r0, [r0]
	lsrs r0, r0, #2
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r1, #0x64
	bl Mod
	adds r2, r0, #0
	asrs r4, r4, #3
	adds r0, r5, #0
	adds r0, #0xa0
	ldr r1, [r0]
	cmp r1, #0xe
	bhi _0801BB10
	movs r4, #0
	b _0801BB1C
	.align 2, 0
_0801BB00: .4byte 0x030046B8
_0801BB04: .4byte 0x000003FF
_0801BB08: .4byte 0x0203B400
_0801BB0C: .4byte 0x03002CF0
_0801BB10:
	adds r0, r5, #0
	adds r0, #0xa8
	ldr r0, [r0]
	cmp r0, r1
	bne _0801BB1C
	lsls r4, r4, #1
_0801BB1C:
	movs r0, #0
	cmp r2, r4
	bgt _0801BB24
	movs r0, #1
_0801BB24:
	cmp r0, #0
	beq _0801BB70
	ldrb r0, [r6, #2]
	cmp r0, #2
	beq _0801BB50
	cmp r0, #2
	bgt _0801BB38
	cmp r0, #1
	beq _0801BB3E
	b _0801BB70
_0801BB38:
	cmp r0, #3
	beq _0801BB60
	b _0801BB70
_0801BB3E:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0x50
	str r0, [r1]
	ldr r0, _0801BB4C @ =0x08DAA27C
	b _0801BB72
	.align 2, 0
_0801BB4C: .4byte 0x08DAA27C
_0801BB50:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0x78
	str r0, [r1]
	ldr r0, _0801BB5C @ =0x08DAA330
	b _0801BB72
	.align 2, 0
_0801BB5C: .4byte 0x08DAA330
_0801BB60:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0xa0
	str r0, [r1]
	ldr r0, _0801BB6C @ =0x08DAA39C
	b _0801BB72
	.align 2, 0
_0801BB6C: .4byte 0x08DAA39C
_0801BB70:
	movs r0, #0
_0801BB72:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801bb78
FUN_0801bb78: @ 0x0801BB78
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r6, r5, r0
	ldr r0, _0801BBAC @ =0x00000978
	adds r1, r5, r0
	adds r0, #0x84
	adds r2, r5, r0
	adds r0, r5, #0
	adds r0, #0xa0
	ldr r0, [r0]
	cmp r0, #0
	beq _0801BB9E
	adds r0, r5, #0
	adds r0, #0xb0
	ldr r0, [r0]
	cmp r0, #9
	bls _0801BBB4
_0801BB9E:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0
	str r0, [r1]
	ldr r0, _0801BBB0 @ =0x08DAA474
	b _0801BC92
	.align 2, 0
_0801BBAC: .4byte 0x00000978
_0801BBB0: .4byte 0x08DAA474
_0801BBB4:
	ldrb r1, [r1]
	ldrb r0, [r2]
	cmp r1, #0x37
	bne _0801BBC0
	cmp r0, #0x38
	beq _0801BBC8
_0801BBC0:
	cmp r0, #0x37
	bne _0801BBE4
	cmp r1, #0x38
	bne _0801BBE4
_0801BBC8:
	adds r0, r5, #0
	adds r0, #0x60
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #9
	ble _0801BBE4
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0xc8
	str r0, [r1]
	ldr r0, _0801BBE0 @ =0x08DAA66C
	b _0801BC92
	.align 2, 0
_0801BBE0: .4byte 0x08DAA66C
_0801BBE4:
	ldrb r0, [r6, #1]
	bl GetWeaponSkillLevel
	adds r4, r0, #0
	ldr r2, _0801BC20 @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ldr r0, _0801BC24 @ =0x000003FF
	ands r1, r0
	str r1, [r2]
	lsls r1, r1, #1
	ldr r0, _0801BC28 @ =0x0203B400
	adds r1, r1, r0
	ldr r0, _0801BC2C @ =0x03002CF0
	ldr r0, [r0]
	lsrs r0, r0, #2
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r1, #0x64
	bl Mod
	adds r2, r0, #0
	asrs r4, r4, #3
	adds r0, r5, #0
	adds r0, #0xa0
	ldr r1, [r0]
	cmp r1, #0xe
	bhi _0801BC30
	movs r4, #0
	b _0801BC3C
	.align 2, 0
_0801BC20: .4byte 0x030046B8
_0801BC24: .4byte 0x000003FF
_0801BC28: .4byte 0x0203B400
_0801BC2C: .4byte 0x03002CF0
_0801BC30:
	adds r0, r5, #0
	adds r0, #0xa8
	ldr r0, [r0]
	cmp r0, r1
	bne _0801BC3C
	lsls r4, r4, #1
_0801BC3C:
	movs r0, #0
	cmp r2, r4
	bgt _0801BC44
	movs r0, #1
_0801BC44:
	cmp r0, #0
	beq _0801BC90
	ldrb r0, [r6, #2]
	cmp r0, #2
	beq _0801BC70
	cmp r0, #2
	bgt _0801BC58
	cmp r0, #1
	beq _0801BC5E
	b _0801BC90
_0801BC58:
	cmp r0, #3
	beq _0801BC80
	b _0801BC90
_0801BC5E:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0x50
	str r0, [r1]
	ldr r0, _0801BC6C @ =0x08DAA528
	b _0801BC92
	.align 2, 0
_0801BC6C: .4byte 0x08DAA528
_0801BC70:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0x78
	str r0, [r1]
	ldr r0, _0801BC7C @ =0x08DAA5DC
	b _0801BC92
	.align 2, 0
_0801BC7C: .4byte 0x08DAA5DC
_0801BC80:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0xa0
	str r0, [r1]
	ldr r0, _0801BC8C @ =0x08DAA648
	b _0801BC92
	.align 2, 0
_0801BC8C: .4byte 0x08DAA648
_0801BC90:
	movs r0, #0
_0801BC92:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801bc98
FUN_0801bc98: @ 0x0801BC98
	push {lr}
	adds r1, r0, #0
	movs r2, #0xa8
	lsls r2, r2, #4
	adds r0, r1, r2
	ldrb r0, [r0, #1]
	cmp r0, #1
	beq _0801BCC0
	cmp r0, #1
	bgt _0801BCB2
	cmp r0, #0
	beq _0801BCB8
	b _0801BCD0
_0801BCB2:
	cmp r0, #2
	beq _0801BCC8
	b _0801BCD0
_0801BCB8:
	adds r0, r1, #0
	bl FUN_0801b938
	b _0801BCD2
_0801BCC0:
	adds r0, r1, #0
	bl FUN_0801ba58
	b _0801BCD2
_0801BCC8:
	adds r0, r1, #0
	bl FUN_0801bb78
	b _0801BCD2
_0801BCD0:
	movs r0, #0
_0801BCD2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801bcd8
FUN_0801bcd8: @ 0x0801BCD8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	adds r7, r0, #0
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r0, r0, r7
	mov sl, r0
	mov r5, sl
	movs r1, #0
	str r1, [sp, #0x48]
	adds r0, r7, #0
	mov r1, sl
	bl FUN_0801b904
	adds r1, r7, #0
	adds r1, #0x98
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_0801bc98
	cmp r0, #0
	beq _0801BD1A
	mov r1, sl
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
_0801BD1A:
	adds r0, r7, #0
	adds r0, #0xa0
	ldr r1, [r0]
	str r0, [sp, #0x4c]
	movs r0, #0x41
	adds r0, r0, r7
	mov sb, r0
	movs r2, #0x42
	adds r2, r2, r7
	mov r8, r2
	cmp r1, #4
	bhi _0801BD34
	b _0801BE80
_0801BD34:
	adds r4, r7, #0
	adds r4, #0xa8
	ldr r0, [r4]
	cmp r0, #0
	bne _0801BD40
	b _0801BE80
_0801BD40:
	mov r3, sl
	ldrb r0, [r3, #1]
	bl GetWeaponSkillLevel
	asrs r0, r0, #2
	ldr r2, [r4]
	lsls r1, r2, #1
	adds r1, r1, r2
	adds r0, r0, r1
	adds r1, r7, #0
	adds r1, #0xb0
	ldr r2, [r1]
	lsls r1, r2, #2
	adds r1, r1, r2
	subs r6, r0, r1
	cmp r6, #0x64
	ble _0801BD66
	movs r6, #0x64
	b _0801BD6C
_0801BD66:
	cmp r6, #0
	bge _0801BD6C
	movs r6, #0
_0801BD6C:
	ldr r2, _0801BDA0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0801BDA4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _0801BDA8 @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x64
	bl Mod
	cmp r0, r6
	bgt _0801BDB0
	ldrb r0, [r5]
	bl FUN_0823d414
	ldrb r1, [r0, #0x18]
	cmp r1, #0
	beq _0801BDAC
	movs r1, #1
	str r1, [sp, #0x48]
	ldr r0, [r0, #0x18]
	str r0, [r5, #0x18]
	b _0801BDB4
	.align 2, 0
_0801BDA0: .4byte 0x030046B8
_0801BDA4: .4byte 0x000003FF
_0801BDA8: .4byte 0x0203B400
_0801BDAC:
	strb r1, [r5, #0x18]
	b _0801BDB4
_0801BDB0:
	movs r0, #0
	strb r0, [r5, #0x18]
_0801BDB4:
	ldr r2, _0801BDF8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0801BDFC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0801BE00 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x64
	bl Mod
	cmp r0, r6
	bgt _0801BE0A
	adds r4, r7, #0
	adds r4, #0x41
	ldrb r0, [r4]
	mov r1, sp
	bl FUN_08242b14
	add r0, sp, #0x18
	ldrb r0, [r0]
	mov sb, r4
	cmp r0, #0
	beq _0801BE04
	ldrb r3, [r5, #0x18]
	cmp r0, r3
	beq _0801BE04
	ldr r0, [sp, #0x18]
	str r0, [r5, #0x1c]
	movs r4, #1
	str r4, [sp, #0x48]
	b _0801BE14
	.align 2, 0
_0801BDF8: .4byte 0x030046B8
_0801BDFC: .4byte 0x000003FF
_0801BE00: .4byte 0x0203B400
_0801BE04:
	movs r0, #0
	strb r0, [r5, #0x1c]
	b _0801BE14
_0801BE0A:
	movs r0, #0
	strb r0, [r5, #0x1c]
	movs r0, #0x41
	adds r0, r0, r7
	mov sb, r0
_0801BE14:
	ldr r2, _0801BE5C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0801BE60 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0801BE64 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x64
	bl Mod
	cmp r0, r6
	bgt _0801BE72
	adds r4, r7, #0
	adds r4, #0x42
	ldrb r0, [r4]
	add r1, sp, #0x24
	bl FUN_08242b14
	add r0, sp, #0x3c
	ldrb r0, [r0]
	mov r8, r4
	cmp r0, #0
	beq _0801BE68
	ldrb r2, [r5, #0x18]
	cmp r0, r2
	beq _0801BE68
	ldrb r3, [r5, #0x1c]
	cmp r0, r3
	beq _0801BE68
	ldr r0, [sp, #0x3c]
	str r0, [r5, #0x20]
	b _0801BF16
	.align 2, 0
_0801BE5C: .4byte 0x030046B8
_0801BE60: .4byte 0x000003FF
_0801BE64: .4byte 0x0203B400
_0801BE68:
	adds r1, r5, #0
	adds r1, #0x20
	movs r0, #0
	strb r0, [r1]
	b _0801BE80
_0801BE72:
	adds r1, r5, #0
	adds r1, #0x20
	movs r0, #0
	strb r0, [r1]
	movs r4, #0x42
	adds r4, r4, r7
	mov r8, r4
_0801BE80:
	ldr r0, [sp, #0x48]
	cmp r0, #0
	bne _0801BF16
	ldr r1, [sp, #0x4c]
	ldr r0, [r1]
	movs r6, #2
	cmp r0, #9
	bls _0801BEAA
	movs r6, #3
	cmp r0, #0xe
	bls _0801BEAA
	movs r6, #8
	cmp r0, #0x13
	bls _0801BEAA
	movs r6, #0xf
	cmp r0, #0x18
	bls _0801BEAA
	movs r6, #0x28
	cmp r0, #0x1d
	bhi _0801BEAA
	movs r6, #0x19
_0801BEAA:
	ldrb r0, [r5, #1]
	bl FUN_0801b6a4
	adds r4, r0, #0
	ldr r2, [sp, #0x4c]
	ldr r1, [r2]
	movs r0, #0x64
	muls r0, r1, r0
	adds r1, r7, #0
	adds r1, #0xa4
	ldr r1, [r1]
	subs r0, r0, r1
	adds r1, r6, #0
	bl Div
	subs r4, r4, r0
	movs r3, #8
	ldrsh r0, [r5, r3]
	adds r4, r4, r0
	asrs r4, r4, #1
	ldr r1, [sp, #0x4c]
	ldr r0, [r1]
	cmp r0, #4
	bhi _0801BEE0
	movs r4, #0xa
	rsbs r4, r4, #0
	b _0801BEEA
_0801BEE0:
	cmp r0, #9
	bhi _0801BEEA
	cmp r4, #0
	ble _0801BEEA
	movs r4, #0
_0801BEEA:
	movs r0, #0xa
	rsbs r0, r0, #0
	cmp r4, r0
	bge _0801BEF6
	strh r0, [r5, #8]
	b _0801BF02
_0801BEF6:
	cmp r4, #0xa
	ble _0801BF00
	movs r0, #0xa
	strh r0, [r5, #8]
	b _0801BF02
_0801BF00:
	strh r4, [r5, #8]
_0801BF02:
	adds r6, r5, #0
	adds r6, #0xc
	movs r1, #0
	adds r0, r5, #0
	adds r0, #8
_0801BF0C:
	strb r1, [r0, #0x18]
	subs r0, #4
	cmp r0, r5
	bge _0801BF0C
	b _0801BF1E
_0801BF16:
	movs r0, #0
	strh r0, [r5, #8]
	adds r6, r5, #0
	adds r6, #0xc
_0801BF1E:
	mov r2, sb
	ldrb r0, [r2]
	bl FUN_08242c08
	mov r3, r8
	ldrb r0, [r3]
	bl FUN_08242c08
	ldr r4, _0801BF80 @ =0x030046A0
	ldr r1, [r4]
	movs r0, #0xf0
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r6, #0
	movs r2, #0xa
	bl FUN_08230ab0
	movs r0, #0
	strb r0, [r5, #0x16]
	adds r0, r5, #0
	bl FUN_08242b88
	ldr r1, [r4]
	movs r2, #0xbf
	lsls r2, r2, #2
	adds r1, r1, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r0, [r4]
	adds r2, r0, r2
	movs r1, #0
	ldrsh r0, [r2, r1]
	ldr r1, _0801BF84 @ =0x0000270F
	cmp r0, r1
	ble _0801BF68
	strh r1, [r2]
_0801BF68:
	adds r0, r7, #0
	mov r1, sl
	bl FUN_0801b688
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801BF80: .4byte 0x030046A0
_0801BF84: .4byte 0x0000270F

	thumb_func_start FUN_0801bf88
FUN_0801bf88: @ 0x0801BF88
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r1, #0
	adds r0, #0x3d
	ldrb r1, [r0]
	lsls r0, r1, #5
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r5, r4, r0
	ldr r3, _0801BFEC @ =0x00001308
	adds r6, r4, r3
	ldr r0, [r6]
	bl FUN_080478f0
	adds r1, r4, #0
	adds r1, #0xbc
	adds r0, r5, #0
	bl FUN_08094d1c
	ldrb r0, [r5]
	cmp r0, #0
	beq _0801BFF4
	ldr r1, [r6]
	adds r0, r5, #0
	bl FUN_08094d48
	adds r0, r5, #0
	bl FUN_08094e70
	adds r2, r0, #0
	ldr r1, _0801BFF0 @ =0x00000DA4
	adds r0, r4, r1
	ldr r1, [r0, #8]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r0, #8]
	movs r3, #0x8c
	lsls r3, r3, #1
	adds r1, r4, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #0
	bl Sprite_SetSprite
	b _0801C010
	.align 2, 0
_0801BFEC: .4byte 0x00001308
_0801BFF0: .4byte 0x00000DA4
_0801BFF4:
	cmp r7, #0
	bne _0801BFFE
	bl FUN_08049e5c
	b _0801C004
_0801BFFE:
	adds r0, r7, #0
	bl FUN_08049e30
_0801C004:
	ldr r1, _0801C018 @ =0x00000DA4
	adds r0, r4, r1
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
_0801C010:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801C018: .4byte 0x00000DA4

	thumb_func_start FUN_0801c01c
FUN_0801c01c: @ 0x0801C01C
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
	bl Script_ExecById
	add sp, #0x30
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801C0D4: .4byte 0xFFFF0000

	thumb_func_start FUN_0801c0d8
FUN_0801c0d8: @ 0x0801C0D8
	push {lr}
	cmp r1, #1
	beq _0801C0F8
	cmp r1, #1
	bgt _0801C0E8
	cmp r1, #0
	beq _0801C0EE
	b _0801C10A
_0801C0E8:
	cmp r1, #2
	beq _0801C104
	b _0801C10A
_0801C0EE:
	movs r0, #0xe5
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _0801C10A
_0801C0F8:
	ldr r0, _0801C100 @ =0x00000395
	bl PlaySound_082406e0
	b _0801C10A
	.align 2, 0
_0801C100: .4byte 0x00000395
_0801C104:
	ldr r0, _0801C110 @ =0x00000396
	bl PlaySound_082406e0
_0801C10A:
	pop {r0}
	bx r0
	.align 2, 0
_0801C110: .4byte 0x00000396

	thumb_func_start FUN_0801c114
FUN_0801c114: @ 0x0801C114
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	str r1, [sp, #0xc]
	ldr r0, _0801C174 @ =0x0000C091
	ldr r1, _0801C178 @ =0x00009F57
	bl GetFile
	adds r2, r0, #0
	str r2, [r5, #0x48]
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0801C17C @ =0x000092B3
	ldr r1, _0801C180 @ =0x0000A41A
	bl GetFile
	adds r1, r0, #0
	adds r0, #0x14
	str r0, [r5, #0x4c]
	movs r2, #0xda
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r1, _0801C184 @ =0x030043F0
	movs r2, #0x30
	bl CpuSet
	movs r0, #0
	add sp, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801C174: .4byte 0x0000C091
_0801C178: .4byte 0x00009F57
_0801C17C: .4byte 0x000092B3
_0801C180: .4byte 0x0000A41A
_0801C184: .4byte 0x030043F0

	thumb_func_start FUN_0801c188
FUN_0801c188: @ 0x0801C188
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _0801C1FC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0801C1C0
	adds r1, r4, #0
	adds r1, #0x40
	ldrb r0, [r1]
	cmp r0, #1
	bne _0801C1C0
	movs r2, #0
	strb r2, [r1]
	ldr r1, _0801C200 @ =0x00000BC4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xf8
	str r2, [sp]
	movs r2, #4
	movs r3, #1
	bl FUN_082370cc
	movs r0, #0xdc
	bl PlaySound_082406e0
_0801C1C0:
	ldr r0, _0801C1FC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0801C1F2
	adds r1, r4, #0
	adds r1, #0x40
	ldrb r2, [r1]
	cmp r2, #0
	bne _0801C1F2
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0801C200 @ =0x00000BC4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xf8
	str r2, [sp]
	movs r2, #5
	movs r3, #1
	bl FUN_082370cc
	movs r0, #0xdc
	bl PlaySound_082406e0
_0801C1F2:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801C1FC: .4byte 0x030044E0
_0801C200: .4byte 0x00000BC4

	thumb_func_start FUN_0801c204
FUN_0801c204: @ 0x0801C204
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r6, r0, #0
	add r4, sp, #0x14
	movs r0, #0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r4, #0
	ldr r2, _0801C258 @ =0x05000002
	bl CpuSet
	mov r8, r4
	movs r7, #0
	ldr r0, _0801C25C @ =0x00000B04
	adds r4, r6, r0
	movs r5, #2
_0801C228:
	str r7, [sp]
	str r7, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r0, r8
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r1, #0xf8
	movs r2, #0x3c
	movs r3, #0x10
	bl FUN_0822f3fc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0801C228
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801C258: .4byte 0x05000002
_0801C25C: .4byte 0x00000B04

	thumb_func_start FUN_0801c260
FUN_0801c260: @ 0x0801C260
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r6, r0, #0
	add r4, sp, #0x14
	movs r0, #0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r4, #0
	ldr r2, _0801C2B4 @ =0x05000002
	bl CpuSet
	mov r8, r4
	movs r7, #0
	ldr r0, _0801C2B8 @ =0x00000C24
	adds r4, r6, r0
	movs r5, #3
_0801C284:
	str r7, [sp]
	str r7, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r0, r8
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r1, #0xf8
	movs r2, #0x41
	movs r3, #0x31
	bl FUN_0822f3fc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0801C284
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801C2B4: .4byte 0x05000002
_0801C2B8: .4byte 0x00000C24

	thumb_func_start FUN_0801c2bc
FUN_0801c2bc: @ 0x0801C2BC
	push {lr}
	sub sp, #0x18
	adds r1, r0, #0
	ldr r2, _0801C2F8 @ =0xFFFF0000
	movs r0, #0x80
	lsls r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	ldr r2, _0801C2FC @ =0x00000DA4
	adds r0, r1, r2
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r1, r1, r2
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	movs r2, #0xd0
	movs r3, #0x11
	bl FUN_0822f3fc
	add sp, #0x18
	pop {r1}
	bx r1
	.align 2, 0
_0801C2F8: .4byte 0xFFFF0000
_0801C2FC: .4byte 0x00000DA4

	thumb_func_start FUN_0801c300
FUN_0801c300: @ 0x0801C300
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _0801C39C @ =0x00000B04
	adds r2, r4, r0
	adds r3, r4, #0
	adds r3, #0x3d
	ldrb r0, [r3]
	movs r1, #3
	ands r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	movs r6, #0
	strh r0, [r2, #0x20]
	ldrb r1, [r3]
	lsrs r1, r1, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r2, #0x22]
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	mov r8, r1
	ands r0, r1
	str r0, [r2, #8]
	adds r5, r4, #0
	adds r5, #0xf8
	str r6, [sp]
	adds r0, r2, #0
	adds r1, r5, #0
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r0, _0801C3A0 @ =0x00000B64
	adds r2, r4, r0
	movs r0, #0x10
	strh r0, [r2, #0x20]
	movs r0, #0x28
	strh r0, [r2, #0x22]
	ldr r0, [r2, #8]
	mov r1, r8
	ands r0, r1
	str r0, [r2, #8]
	adds r0, r2, #0
	adds r1, r5, #0
	movs r2, #0x3c
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, _0801C3A4 @ =0x00000BC4
	adds r2, r4, r0
	strh r6, [r2, #0x20]
	strh r6, [r2, #0x22]
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	str r6, [sp]
	adds r0, r2, #0
	adds r1, r5, #0
	movs r2, #4
	movs r3, #1
	bl FUN_082370cc
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801C39C: .4byte 0x00000B04
_0801C3A0: .4byte 0x00000B64
_0801C3A4: .4byte 0x00000BC4

	thumb_func_start FUN_0801c3a8
FUN_0801c3a8: @ 0x0801C3A8
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	ldr r1, _0801C3EC @ =0x030046A0
	ldr r1, [r1]
	adds r5, r1, #0
	adds r5, #0x60
	movs r7, #0
	movs r6, #3
_0801C3B8:
	ldr r2, _0801C3F0 @ =0x00000C24
	adds r1, r7, r2
	mov r2, ip
	adds r4, r2, r1
	movs r1, #0
	ldrsh r3, [r5, r1]
	cmp r3, #0
	blt _0801C3F4
	movs r2, #3
	ands r2, r3
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r1, #0x90
	strh r1, [r4, #0x20]
	asrs r2, r3, #2
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r1, #0x20
	strh r1, [r4, #0x22]
	ldr r1, [r4, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _0801C3FA
	.align 2, 0
_0801C3EC: .4byte 0x030046A0
_0801C3F0: .4byte 0x00000C24
_0801C3F4:
	ldr r1, [r4, #8]
	movs r2, #1
	orrs r1, r2
_0801C3FA:
	str r1, [r4, #8]
	adds r5, #2
	adds r7, #0x60
	subs r6, #1
	cmp r6, #0
	bge _0801C3B8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801c40c
FUN_0801c40c: @ 0x0801C40C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _0801C430 @ =0x00000B04
	adds r4, r6, r0
	movs r5, #2
_0801C416:
	adds r0, r4, #0
	adds r1, r6, #0
	adds r1, #0xf8
	bl FUN_082372cc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0801C416
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801C430: .4byte 0x00000B04

	thumb_func_start FUN_0801c434
FUN_0801c434: @ 0x0801C434
	push {r4, r5, lr}
	ldr r1, _0801C450 @ =0x00000B04
	adds r4, r0, r1
	movs r5, #2
_0801C43C:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0801C43C
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801C450: .4byte 0x00000B04

	thumb_func_start FUN_0801c454
FUN_0801c454: @ 0x0801C454
	push {r4, r5, lr}
	ldr r1, _0801C470 @ =0x00000C24
	adds r4, r0, r1
	movs r5, #3
_0801C45C:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0801C45C
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801C470: .4byte 0x00000C24

	thumb_func_start FUN_0801c474
FUN_0801c474: @ 0x0801C474
	push {lr}
	ldr r1, _0801C484 @ =0x00000DA4
	adds r0, r0, r1
	bl FUN_0822f1c0
	pop {r1}
	bx r1
	.align 2, 0
_0801C484: .4byte 0x00000DA4

	thumb_func_start FUN_0801c488
FUN_0801c488: @ 0x0801C488
	push {r4, r5, r6, r7, lr}
	adds r4, r1, #0
	adds r5, r3, #0
	ldm r2!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldm r2!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldm r2!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	adds r1, r4, #0
	bl FUN_0801b688
	ldr r1, [r5]
	ldr r2, [r5, #4]
	str r1, [r4, #0x44]
	str r2, [r4, #0x48]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801c4b0
FUN_0801c4b0: @ 0x0801C4B0
	push {lr}
	adds r0, #0x24
	bl FUN_0822f1c0
	pop {r1}
	bx r1

	thumb_func_start FUN_0801c4bc
FUN_0801c4bc: @ 0x0801C4BC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r6, r0, #0
	add r4, sp, #0x14
	movs r0, #0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r4, #0
	ldr r2, _0801C510 @ =0x05000002
	bl CpuSet
	movs r5, #0x12
	mov r8, r4
	movs r7, #0
	ldr r0, _0801C514 @ =0x00000AA4
	adds r4, r6, r0
_0801C4E0:
	str r7, [sp]
	str r7, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r2, r8
	str r2, [sp, #0xc]
	adds r0, r4, #0
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r2, #0
	movs r3, #0x11
	bl FUN_0822f3fc
	subs r4, #0x84
	subs r5, #1
	cmp r5, #0
	bge _0801C4E0
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801C510: .4byte 0x05000002
_0801C514: .4byte 0x00000AA4

	thumb_func_start FUN_0801c518
FUN_0801c518: @ 0x0801C518
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x2c
	mov r8, r0
	movs r5, #0x9c
	lsls r5, r5, #1
	add r5, r8
	movs r6, #0
	add r0, sp, #0x24
	mov sb, r0
	adds r7, r5, #0
	movs r4, #0xb2
	lsls r4, r4, #1
	add r4, r8
_0801C538:
	movs r0, #3
	ands r0, r6
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x13
	movs r2, #0x90
	lsls r2, r2, #0x10
	adds r1, r1, r2
	asrs r2, r6, #2
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #0x13
	movs r2, #0x80
	lsls r2, r2, #0xe
	adds r0, r0, r2
	lsrs r1, r1, #0x10
	orrs r1, r0
	str r1, [sp, #0x24]
	adds r0, r6, #0
	mov r1, sp
	bl FUN_08242b14
	mov r0, r8
	adds r1, r7, #0
	mov r2, sp
	mov r3, sb
	bl FUN_0801c488
	movs r0, #1
	lsls r0, r6
	mov r2, r8
	ldr r1, [r2, #0x50]
	ands r0, r1
	cmp r0, #0
	beq _0801C594
	ldr r0, _0801C590 @ =0x000002DF
	strh r0, [r4, #0x32]
	movs r0, #0
	bl FUN_0801b670
	adds r1, r0, #0
	str r1, [r4, #0x40]
	b _0801C5AA
	.align 2, 0
_0801C590: .4byte 0x000002DF
_0801C594:
	movs r0, #0xb8
	lsls r0, r0, #2
	strh r0, [r4, #0x32]
	movs r0, #1
	bl FUN_0801b670
	adds r1, r0, #0
	str r1, [r4, #0x40]
	ldrb r1, [r5]
	cmp r1, #0
	beq _0801C5B4
_0801C5AA:
	ldr r1, [r4]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r4]
_0801C5B4:
	adds r7, #0x84
	adds r6, #1
	adds r4, #0x84
	adds r5, #0x84
	cmp r6, #0xf
	ble _0801C538
	add sp, #0x2c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801c5d0
FUN_0801c5d0: @ 0x0801C5D0
	push {r4, r5, lr}
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r4, r0, r1
	movs r5, #0x12
_0801C5DA:
	adds r0, r4, #0
	bl FUN_0801c4b0
	adds r4, #0x84
	subs r5, #1
	cmp r5, #0
	bge _0801C5DA
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801c5f0
FUN_0801c5f0: @ 0x0801C5F0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x3e
	ldrb r0, [r0]
	cmp r0, #1
	bhi _0801C60A
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _0801C610 @ =FUN_0801cbc4
	adds r0, r4, #0
	bl FUN_0801b8d0
_0801C60A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801C610: .4byte FUN_0801cbc4

	thumb_func_start FUN_0801c614
FUN_0801c614: @ 0x0801C614
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _0801C668 @ =0x00000B64
	adds r6, r5, r0
	adds r4, r5, #0
	adds r4, #0x3e
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801C6F0
	movs r0, #0xde
	bl PlaySound_082406e0
	ldr r1, _0801C66C @ =0x00000B04
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0xf8
	movs r2, #0
	str r2, [sp]
	movs r3, #1
	bl FUN_082370cc
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	ldrb r1, [r4]
	lsls r0, r1, #5
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r2, _0801C670 @ =0x00000978
	adds r0, r0, r2
	adds r0, r5, r0
	ldr r1, [r0, #0x2c]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #0x2c]
	ldrb r0, [r4]
	cmp r0, #0
	bne _0801C674
	movs r0, #0x10
	b _0801C676
	.align 2, 0
_0801C668: .4byte 0x00000B64
_0801C66C: .4byte 0x00000B04
_0801C670: .4byte 0x00000978
_0801C674:
	movs r0, #0x40
_0801C676:
	strh r0, [r6, #0x20]
	movs r0, #0x28
	strh r0, [r6, #0x22]
	adds r6, r5, #0
	adds r6, #0x3e
	ldrb r0, [r6]
	adds r4, r5, #0
	adds r4, #0x41
	adds r0, r4, r0
	movs r1, #1
	ldrb r0, [r0]
	lsls r1, r0
	ldr r0, [r5, #0x50]
	orrs r0, r1
	str r0, [r5, #0x50]
	ldrb r0, [r6]
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, #5
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r5, r0
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r1, r0, r3
	ldr r0, _0801C6E8 @ =0x000002DF
	strh r0, [r1]
	movs r0, #0
	bl FUN_0801b670
	ldrb r1, [r6]
	adds r4, r4, r1
	ldrb r1, [r4]
	lsls r2, r1, #5
	adds r2, r2, r1
	lsls r2, r2, #2
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r1, r5, r3
	adds r1, r1, r2
	str r0, [r1]
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0801bf88
	ldr r1, _0801C6EC @ =FUN_0801c9e4
	adds r0, r5, #0
	bl FUN_0801b8d0
	b _0801C6FE
	.align 2, 0
_0801C6E8: .4byte 0x000002DF
_0801C6EC: .4byte FUN_0801c9e4
_0801C6F0:
	movs r0, #0xde
	bl PlaySound_082406e0
	ldr r1, _0801C708 @ =FUN_0801cec0
	adds r0, r5, #0
	bl FUN_0801b8d0
_0801C6FE:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801C708: .4byte FUN_0801cec0

	thumb_func_start FUN_0801c70c
FUN_0801c70c: @ 0x0801C70C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _0801C724 @ =0x00000B64
	adds r1, r4, r0
	adds r0, r4, #0
	adds r0, #0x3e
	ldrb r0, [r0]
	cmp r0, #0
	bne _0801C728
	movs r0, #0x40
	b _0801C72A
	.align 2, 0
_0801C724: .4byte 0x00000B64
_0801C728:
	movs r0, #0x68
_0801C72A:
	strh r0, [r1, #0x20]
	movs r0, #0x28
	strh r0, [r1, #0x22]
	adds r1, r4, #0
	adds r1, #0x3e
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0801C74C
	ldr r1, _0801C748 @ =FUN_0801c9e4
	b _0801C79A
	.align 2, 0
_0801C748: .4byte FUN_0801c9e4
_0801C74C:
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r6, r4, r0
	adds r0, r4, #0
	bl FUN_0801b730
	adds r0, r4, #0
	adds r0, #0x3b
	movs r1, #1
	strb r1, [r0]
	ldrb r1, [r6, #2]
	adds r5, r0, #0
	cmp r1, #3
	bne _0801C792
	ldrb r0, [r6, #1]
	cmp r0, #1
	beq _0801C782
	cmp r0, #1
	bgt _0801C778
	cmp r0, #0
	beq _0801C77E
	b _0801C792
_0801C778:
	cmp r0, #2
	beq _0801C786
	b _0801C792
_0801C77E:
	movs r0, #0x33
	b _0801C788
_0801C782:
	movs r0, #0x35
	b _0801C788
_0801C786:
	movs r0, #0x36
_0801C788:
	bl CheckItemOwn
	cmp r0, #0
	bne _0801C792
	strb r0, [r5]
_0801C792:
	ldrb r0, [r5]
	cmp r0, #0
	beq _0801C7A8
	ldr r1, _0801C7A4 @ =FUN_0801ccd4
_0801C79A:
	adds r0, r4, #0
	bl FUN_0801b8d0
	b _0801C7B0
	.align 2, 0
_0801C7A4: .4byte FUN_0801ccd4
_0801C7A8:
	ldr r1, _0801C7B8 @ =FUN_0801cf18
	adds r0, r4, #0
	bl FUN_0801b8d0
_0801C7B0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801C7B8: .4byte FUN_0801cf18

	thumb_func_start FUN_0801c7bc
FUN_0801c7bc: @ 0x0801C7BC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	ldm r3!, {r5, r6, r7}
	stm r4!, {r5, r6, r7}
	ldm r3!, {r5, r6, r7}
	stm r4!, {r5, r6, r7}
	ldm r3!, {r5, r6, r7}
	stm r4!, {r5, r6, r7}
	adds r0, #0x24
	adds r1, #0x24
	bl FUN_0822f588
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801c7dc
FUN_0801c7dc: @ 0x0801C7DC
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x95
	ldrb r0, [r4]
	bl FUN_080b9400
	ldrb r0, [r4]
	bl FUN_080b94cc
	ldr r0, _0801C804 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x40
	movs r1, #0
	ldrsh r3, [r0, r1]
	cmp r3, #0x63
	ble _0801C808
	movs r3, #0x63
	b _0801C80E
	.align 2, 0
_0801C804: .4byte 0x030046A0
_0801C808:
	cmp r3, #0
	bge _0801C80E
	movs r3, #0
_0801C80E:
	movs r0, #0x21
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #0xf
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #4
	movs r2, #9
	bl FUN_0822be3c
	movs r0, #0
	bl GetWeaponSkillLevel
	adds r3, r0, #0
	cmp r3, #0x63
	ble _0801C834
	movs r3, #0x63
	b _0801C83A
_0801C834:
	cmp r3, #0
	bge _0801C83A
	movs r3, #0
_0801C83A:
	movs r0, #0x21
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #0xf
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #3
	movs r2, #0xb
	bl FUN_0822be3c
	movs r0, #1
	bl GetWeaponSkillLevel
	adds r3, r0, #0
	cmp r3, #0x63
	ble _0801C860
	movs r3, #0x63
	b _0801C866
_0801C860:
	cmp r3, #0
	bge _0801C866
	movs r3, #0
_0801C866:
	movs r0, #0x21
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #0xf
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #8
	movs r2, #0xb
	bl FUN_0822be3c
	movs r0, #2
	bl GetWeaponSkillLevel
	adds r3, r0, #0
	cmp r3, #0x63
	ble _0801C88C
	movs r3, #0x63
	b _0801C892
_0801C88C:
	cmp r3, #0
	bge _0801C892
	movs r3, #0
_0801C892:
	movs r0, #0x21
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #0xf
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #3
	movs r2, #0xc
	bl FUN_0822be3c
	movs r0, #3
	bl GetWeaponSkillLevel
	adds r3, r0, #0
	cmp r3, #0x63
	ble _0801C8B8
	movs r3, #0x63
	b _0801C8BE
_0801C8B8:
	cmp r3, #0
	bge _0801C8BE
	movs r3, #0
_0801C8BE:
	movs r0, #0x21
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #0xf
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #8
	movs r2, #0xc
	bl FUN_0822be3c
	movs r0, #4
	bl GetWeaponSkillLevel
	adds r3, r0, #0
	cmp r3, #0x63
	ble _0801C8E4
	movs r3, #0x63
	b _0801C8EA
_0801C8E4:
	cmp r3, #0
	bge _0801C8EA
	movs r3, #0
_0801C8EA:
	movs r0, #0x21
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #0xf
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #3
	movs r2, #0xd
	bl FUN_0822be3c
	adds r0, r5, #0
	bl FUN_0801c40c
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801c910
FUN_0801c910: @ 0x0801C910
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0
	str r0, [r5, #0x50]
	movs r4, #0
_0801C91A:
	adds r0, r4, #0
	bl GetWeaponID
	subs r0, #1
	cmp r0, #0x38
	bhi _0801C93A
	adds r0, r4, #0
	bl GetWeaponKind
	cmp r0, #2
	bgt _0801C93A
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x50]
	orrs r0, r1
	str r0, [r5, #0x50]
_0801C93A:
	adds r4, #1
	cmp r4, #0xf
	ble _0801C91A
	movs r0, #0x3e
	adds r0, r0, r5
	mov ip, r0
	adds r3, r5, #0
	adds r3, #0x95
	ldr r0, _0801C9D4 @ =0x030046A0
	ldr r0, [r0]
	movs r6, #1
	adds r2, r0, #0
	adds r2, #0x60
	movs r4, #3
_0801C956:
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	blt _0801C968
	adds r1, r6, #0
	lsls r1, r0
	ldr r0, [r5, #0x50]
	bics r0, r1
	str r0, [r5, #0x50]
_0801C968:
	adds r2, #2
	subs r4, #1
	cmp r4, #0
	bge _0801C956
	movs r0, #0
	mov r1, ip
	strb r0, [r1]
	strb r0, [r3]
	bl FUN_0822b644
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0801c114
	adds r0, r5, #0
	bl FUN_0801c300
	adds r0, r5, #0
	bl FUN_0801c3a8
	adds r0, r5, #0
	bl FUN_0801c518
	ldr r1, _0801C9D8 @ =0x00001308
	adds r0, r5, r1
	ldr r0, [r0]
	bl FUN_080478f0
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	ldr r0, _0801C9DC @ =0x0000EFDA
	bl FUN_08047dc0
	ldr r1, _0801C9E0 @ =0x0000130C
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	bl Textbox_LookupString
	adds r1, r0, #0
	adds r0, r5, #0
	bl FUN_0801bf88
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801C9D4: .4byte 0x030046A0
_0801C9D8: .4byte 0x00001308
_0801C9DC: .4byte 0x0000EFDA
_0801C9E0: .4byte 0x0000130C

	thumb_func_start FUN_0801c9e4
FUN_0801c9e4: @ 0x0801C9E4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	bl FUN_0801b8e8
	ldr r3, _0801CA28 @ =0x030044E0
	ldrh r6, [r3]
	movs r0, #4
	ands r0, r6
	cmp r0, #0
	beq _0801CA2C
	ldrh r1, [r3, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0801CA08
	b _0801CBAE
_0801CA08:
	adds r1, r5, #0
	adds r1, #0x95
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0801CA1E
	movs r0, #0
	strb r0, [r1]
_0801CA1E:
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _0801CBAE
	.align 2, 0
_0801CA28: .4byte 0x030044E0
_0801CA2C:
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r2, [r1]
	movs r4, #0
	ldrh r3, [r3, #2]
	movs r0, #0x40
	mov ip, r0
	ands r0, r3
	mov r8, r1
	cmp r0, #0
	beq _0801CA46
	movs r4, #1
	b _0801CABE
_0801CA46:
	movs r7, #0x80
	adds r0, r7, #0
	ands r0, r3
	cmp r0, #0
	beq _0801CA54
	movs r4, #2
	b _0801CABE
_0801CA54:
	movs r0, #0x20
	ands r0, r3
	cmp r0, #0
	beq _0801CA60
	movs r4, #4
	b _0801CABE
_0801CA60:
	movs r0, #0x10
	ands r0, r3
	cmp r0, #0
	beq _0801CA6A
	movs r4, #8
_0801CA6A:
	cmp r4, #0
	bne _0801CABE
	adds r3, r5, #0
	adds r3, #0x3f
	ldrb r1, [r3]
	cmp r1, #7
	bls _0801CAB2
	mov r0, ip
	ands r0, r6
	cmp r0, #0
	beq _0801CA84
	movs r4, #1
	b _0801CA8E
_0801CA84:
	adds r0, r7, #0
	ands r0, r6
	cmp r0, #0
	beq _0801CA8E
	movs r4, #2
_0801CA8E:
	ldr r0, _0801CAA0 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0801CAA4
	movs r0, #4
	orrs r4, r0
	b _0801CABE
	.align 2, 0
_0801CAA0: .4byte 0x030044E0
_0801CAA4:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0801CABE
	movs r0, #8
	orrs r4, r0
	b _0801CABE
_0801CAB2:
	movs r0, #0xf0
	ands r0, r6
	cmp r0, #0
	beq _0801CABE
	adds r0, r1, #1
	strb r0, [r3]
_0801CABE:
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	beq _0801CADA
	asrs r0, r2, #2
	cmp r0, #0
	bne _0801CAD6
	movs r0, #3
	ands r0, r2
	adds r2, r0, #0
	adds r2, #0xc
	b _0801CB24
_0801CAD6:
	subs r2, #4
	b _0801CB24
_0801CADA:
	movs r0, #2
	ands r0, r4
	cmp r0, #0
	beq _0801CAF0
	asrs r0, r2, #2
	cmp r0, #3
	bne _0801CAEC
	ands r2, r0
	b _0801CB24
_0801CAEC:
	adds r2, #4
	b _0801CB24
_0801CAF0:
	movs r0, #4
	ands r0, r4
	cmp r0, #0
	beq _0801CB0C
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _0801CB08
	movs r0, #0xfc
	ands r0, r2
	adds r2, r0, #3
	b _0801CB24
_0801CB08:
	subs r2, #1
	b _0801CB24
_0801CB0C:
	movs r0, #8
	ands r4, r0
	cmp r4, #0
	beq _0801CB2C
	movs r0, #3
	ands r0, r2
	cmp r0, #3
	bne _0801CB22
	movs r0, #0xfc
	ands r2, r0
	b _0801CB24
_0801CB22:
	adds r2, #1
_0801CB24:
	adds r1, r5, #0
	adds r1, #0x3f
	movs r0, #0
	strb r0, [r1]
_0801CB2C:
	mov r3, r8
	ldrb r1, [r3]
	cmp r2, r1
	beq _0801CB66
	movs r1, #3
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	ldr r4, _0801CB8C @ =0x00000B24
	adds r1, r5, r4
	strh r0, [r1]
	asrs r1, r2, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	adds r4, #2
	adds r1, r5, r4
	strh r0, [r1]
	strb r2, [r3]
	movs r0, #0xdc
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0801bf88
_0801CB66:
	ldr r0, _0801CB90 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0801CB9E
	adds r0, r2, #0
	mov r1, r8
	ldrb r1, [r1]
	lsls r0, r1
	ldr r1, [r5, #0x50]
	ands r0, r1
	cmp r0, #0
	beq _0801CB94
	adds r0, r5, #0
	bl FUN_0801c5f0
	b _0801CBBA
	.align 2, 0
_0801CB8C: .4byte 0x00000B24
_0801CB90: .4byte 0x030044E0
_0801CB94:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0801CBBA
_0801CB9E:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0801CBAE
	adds r0, r5, #0
	bl FUN_0801c614
	b _0801CBBA
_0801CBAE:
	adds r0, r5, #0
	bl FUN_0801c7dc
	ldr r0, [r5, #0x44]
	adds r0, #1
	str r0, [r5, #0x44]
_0801CBBA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801cbc4
FUN_0801cbc4: @ 0x0801CBC4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x3e
	ldrb r0, [r6]
	lsls r1, r0, #5
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _0801CC74 @ =0x00000978
	adds r1, r1, r0
	adds r1, r1, r5
	mov r8, r1
	adds r0, r5, #0
	bl FUN_0801b8e8
	cmp r0, #0
	beq _0801CC88
	adds r7, r5, #0
	adds r7, #0x3d
	ldrb r0, [r7]
	lsls r1, r0, #5
	adds r1, r1, r0
	lsls r1, r1, #2
	movs r2, #0x9c
	lsls r2, r2, #1
	adds r1, r1, r2
	adds r1, r5, r1
	mov r0, r8
	movs r2, #0xd
	bl FUN_0801c7bc
	mov r3, r8
	ldr r0, [r3, #0x2c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #0x2c]
	ldrb r0, [r6]
	adds r4, r5, #0
	adds r4, #0x41
	adds r0, r4, r0
	ldrb r1, [r7]
	strb r1, [r0]
	ldrb r0, [r6]
	adds r0, r4, r0
	movs r1, #1
	ldrb r0, [r0]
	lsls r1, r0
	ldr r0, [r5, #0x50]
	bics r0, r1
	str r0, [r5, #0x50]
	ldrb r0, [r6]
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, #5
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r5, r0
	movs r2, #0xcb
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r0, #0xb8
	lsls r0, r0, #2
	strh r0, [r1]
	movs r0, #1
	bl FUN_0801b670
	ldrb r1, [r6]
	adds r4, r4, r1
	ldrb r1, [r4]
	lsls r2, r1, #5
	adds r2, r2, r1
	lsls r2, r2, #2
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r1, r5, r3
	adds r1, r1, r2
	str r0, [r1]
	ldrb r0, [r6]
	cmp r0, #0
	bne _0801CC78
	adds r0, r5, #0
	adds r0, #0x54
	movs r1, #0x10
	b _0801CC7E
	.align 2, 0
_0801CC74: .4byte 0x00000978
_0801CC78:
	adds r0, r5, #0
	adds r0, #0x54
	movs r1, #0x40
_0801CC7E:
	strh r1, [r0]
	adds r1, r5, #0
	adds r1, #0x56
	movs r0, #0x28
	strh r0, [r1]
_0801CC88:
	mov r0, r8
	adds r0, #0x44
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r2, [r1]
	lsls r1, r2, #5
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r5
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r1, r1, r2
	adds r2, r5, #0
	adds r2, #0x54
	ldr r3, [r5, #0x44]
	movs r4, #3
	str r4, [sp]
	bl FUN_08237970
	ldr r0, [r5, #0x44]
	cmp r0, #7
	bls _0801CCBC
	adds r0, r5, #0
	bl FUN_0801c70c
	b _0801CCC8
_0801CCBC:
	adds r0, r5, #0
	bl FUN_0801c7dc
	ldr r0, [r5, #0x44]
	adds r0, #1
	str r0, [r5, #0x44]
_0801CCC8:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801ccd4
FUN_0801ccd4: @ 0x0801CCD4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	bl FUN_0801b8e8
	cmp r0, #0
	bne _0801CCEC
	b _0801CE0A
_0801CCEC:
	ldr r0, _0801CD64 @ =0x00000AA4
	adds r6, r7, r0
	ldr r1, _0801CD68 @ =0x00000978
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _0801CD6C @ =0x000009FC
	adds r5, r7, r2
	subs r0, #0x24
	adds r0, r0, r7
	mov sb, r0
	ldr r1, _0801CD70 @ =0x00000B04
	adds r0, r7, r1
	adds r4, r7, #0
	adds r4, #0xf8
	adds r1, r4, #0
	movs r2, #0x39
	movs r3, #0
	bl Sprite_SetSprite
	bl FUN_08049e5c
	adds r0, r7, #0
	mov r1, sb
	bl FUN_0801b688
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	movs r0, #0x68
	strh r0, [r6, #0x20]
	movs r0, #0x28
	strh r0, [r6, #0x22]
	movs r2, #0
	mov sl, r2
	mov r1, r8
	ldrb r0, [r1, #1]
	ldrb r5, [r5, #1]
	cmp r0, r5
	beq _0801CD52
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r1, r7, r2
	adds r0, r6, #0
	movs r2, #0x42
	movs r3, #0
	bl Sprite_SetSprite
	movs r0, #1
	mov sl, r0
_0801CD52:
	adds r0, r7, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801CD78
	ldr r0, _0801CD74 @ =0x000002DF
	strh r0, [r6, #0x3a]
	movs r0, #0
	b _0801CD80
	.align 2, 0
_0801CD64: .4byte 0x00000AA4
_0801CD68: .4byte 0x00000978
_0801CD6C: .4byte 0x000009FC
_0801CD70: .4byte 0x00000B04
_0801CD74: .4byte 0x000002DF
_0801CD78:
	movs r0, #0xb8
	lsls r0, r0, #2
	strh r0, [r6, #0x3a]
	movs r0, #1
_0801CD80:
	bl FUN_0801b670
	str r0, [r6, #0x48]
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0
	strb r1, [r0]
	ldr r2, _0801CDE4 @ =0x00000BC4
	adds r0, r7, r2
	str r1, [sp]
	adds r1, r4, #0
	movs r2, #4
	movs r3, #1
	bl FUN_082370cc
	ldr r0, _0801CDE8 @ =0x00000BCC
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	ldr r1, _0801CDEC @ =0x0000130C
	adds r0, r7, r1
	ldr r0, [r0]
	bl FUN_080478f0
	mov r2, sl
	cmp r2, #0
	bne _0801CDDA
	ldr r0, _0801CDF0 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x40
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, sb
	ldrb r2, [r2, #3]
	cmp r0, r2
	blt _0801CDF4
_0801CDDA:
	movs r0, #1
	bl FUN_08047a28
	b _0801CDFA
	.align 2, 0
_0801CDE4: .4byte 0x00000BC4
_0801CDE8: .4byte 0x00000BCC
_0801CDEC: .4byte 0x0000130C
_0801CDF0: .4byte 0x030046A0
_0801CDF4:
	movs r0, #2
	bl FUN_08047a28
_0801CDFA:
	ldr r1, _0801CE40 @ =0x00000DA4
	adds r0, r7, r1
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
	bl FUN_08049e5c
_0801CE0A:
	ldr r4, _0801CE44 @ =0x030044E0
	ldrh r1, [r4]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0801CE48
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0801CEA4
	adds r1, r7, #0
	adds r1, #0x95
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0801CE36
	movs r0, #0
	strb r0, [r1]
_0801CE36:
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _0801CEA4
	.align 2, 0
_0801CE40: .4byte 0x00000DA4
_0801CE44: .4byte 0x030044E0
_0801CE48:
	adds r0, r7, #0
	bl FUN_0801c188
	ldrh r1, [r4, #2]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0801CE78
	adds r0, r7, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	bne _0801CE80
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _0801CE74 @ =FUN_0801d6c0
	adds r0, r7, #0
	bl FUN_0801b8d0
	b _0801CEB0
	.align 2, 0
_0801CE74: .4byte FUN_0801d6c0
_0801CE78:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0801CEA4
_0801CE80:
	ldr r0, _0801CE9C @ =0x00000AA4
	adds r1, r7, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, _0801CEA0 @ =0x00000BCC
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_0801c614
	b _0801CEB0
	.align 2, 0
_0801CE9C: .4byte 0x00000AA4
_0801CEA0: .4byte 0x00000BCC
_0801CEA4:
	adds r0, r7, #0
	bl FUN_0801c7dc
	ldr r0, [r7, #0x44]
	adds r0, #1
	str r0, [r7, #0x44]
_0801CEB0:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801cec0
FUN_0801cec0: @ 0x0801CEC0
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	bl FUN_0801b8e8
	cmp r0, #0
	beq _0801CEE6
	movs r0, #4
	str r0, [sp]
	ldr r0, _0801CF00 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_0801CEE6:
	ldr r0, [r4, #0x44]
	cmp r0, #0x14
	bne _0801CF04
	adds r1, r4, #0
	adds r1, #0xb8
	ldrh r0, [r1]
	cmp r0, #0
	beq _0801CF10
	movs r1, #0
	bl Script_ExecById
	b _0801CF10
	.align 2, 0
_0801CF00: .4byte 0x0000FFFF
_0801CF04:
	adds r0, r4, #0
	bl FUN_0801c7dc
	ldr r0, [r4, #0x44]
	adds r0, #1
	str r0, [r4, #0x44]
_0801CF10:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801cf18
FUN_0801cf18: @ 0x0801CF18
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl FUN_0801b8e8
	cmp r0, #0
	beq _0801CFB2
	ldr r0, _0801CFCC @ =0x00000AA4
	adds r6, r5, r0
	movs r1, #0xa8
	lsls r1, r1, #4
	adds r4, r5, r1
	ldr r2, _0801CFD0 @ =0x00000B04
	adds r0, r5, r2
	adds r1, r5, #0
	adds r1, #0xf8
	movs r2, #0x39
	movs r3, #0
	bl Sprite_SetSprite
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	ldr r1, _0801CFD4 @ =0x0000130C
	adds r0, r5, r1
	ldr r0, [r0]
	bl FUN_080478f0
	movs r0, #3
	bl FUN_08047a28
	bl FUN_08049e5c
	ldr r0, _0801CFD8 @ =0x00000DA4
	adds r2, r5, r0
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0801b688
	ldr r1, _0801CFDC @ =0x00000978
	adds r0, r5, r1
	ldr r2, _0801CFE0 @ =0x000009FC
	adds r1, r5, r2
	ldrb r0, [r0, #1]
	ldrb r1, [r1, #1]
	cmp r0, r1
	beq _0801CF92
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r1, r5, r0
	adds r0, r6, #0
	movs r2, #0x42
	movs r3, #0
	bl Sprite_SetSprite
_0801CF92:
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	movs r0, #0x68
	strh r0, [r6, #0x20]
	movs r0, #0x28
	strh r0, [r6, #0x22]
	movs r0, #0xb8
	lsls r0, r0, #2
	strh r0, [r6, #0x3a]
	movs r0, #1
	bl FUN_0801b670
	str r0, [r6, #0x48]
_0801CFB2:
	ldr r0, _0801CFE4 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0801CFE8
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0801D014
	.align 2, 0
_0801CFCC: .4byte 0x00000AA4
_0801CFD0: .4byte 0x00000B04
_0801CFD4: .4byte 0x0000130C
_0801CFD8: .4byte 0x00000DA4
_0801CFDC: .4byte 0x00000978
_0801CFE0: .4byte 0x000009FC
_0801CFE4: .4byte 0x030044E0
_0801CFE8:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0801D008
	ldr r0, _0801D004 @ =0x00000AA4
	adds r1, r5, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	adds r0, r5, #0
	bl FUN_0801c614
	b _0801D014
	.align 2, 0
_0801D004: .4byte 0x00000AA4
_0801D008:
	adds r0, r5, #0
	bl FUN_0801c7dc
	ldr r0, [r5, #0x44]
	adds r0, #1
	str r0, [r5, #0x44]
_0801D014:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801d01c
FUN_0801d01c: @ 0x0801D01C
	push {r4, lr}
	adds r3, r0, #0
	movs r4, #1
	movs r0, #0x9c
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r2, #0x12
_0801D02A:
	ldr r0, [r1, #0x2c]
	orrs r0, r4
	str r0, [r1, #0x2c]
	adds r1, #0x84
	subs r2, #1
	cmp r2, #0
	bge _0801D02A
	movs r4, #1
	ldr r0, _0801D078 @ =0x00000B0C
	adds r1, r3, r0
	movs r2, #2
_0801D040:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0801D040
	movs r4, #1
	ldr r0, _0801D07C @ =0x00000C2C
	adds r1, r3, r0
	movs r2, #3
_0801D056:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0801D056
	ldr r1, _0801D080 @ =0x00000DA4
	adds r0, r3, r1
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801D078: .4byte 0x00000B0C
_0801D07C: .4byte 0x00000C2C
_0801D080: .4byte 0x00000DA4

	thumb_func_start FUN_0801d084
FUN_0801d084: @ 0x0801D084
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r6, r0, #0
	add r4, sp, #0x14
	movs r0, #0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r4, #0
	ldr r2, _0801D0D8 @ =0x05000002
	bl CpuSet
	mov r8, r4
	movs r7, #0
	ldr r0, _0801D0DC @ =0x00000E04
	adds r4, r6, r0
	movs r5, #0xc
_0801D0A8:
	str r7, [sp]
	str r7, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r0, r8
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r1, #0xd8
	movs r2, #0
	movs r3, #0x11
	bl FUN_0822f3fc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0801D0A8
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801D0D8: .4byte 0x05000002
_0801D0DC: .4byte 0x00000E04

	thumb_func_start FUN_0801d0e0
FUN_0801d0e0: @ 0x0801D0E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r2, r6, r0
	ldrb r0, [r2, #2]
	cmp r0, #4
	bhi _0801D142
	lsls r0, r0, #2
	ldr r1, _0801D104 @ =_0801D108
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801D104: .4byte _0801D108
_0801D108: @ jump table
	.4byte _0801D11C @ case 0
	.4byte _0801D124 @ case 1
	.4byte _0801D12C @ case 2
	.4byte _0801D132 @ case 3
	.4byte _0801D13A @ case 4
_0801D11C:
	movs r3, #0x28
	movs r1, #8
	str r1, [sp, #4]
	b _0801D148
_0801D124:
	movs r3, #0x1e
	movs r4, #7
	str r4, [sp, #4]
	b _0801D148
_0801D12C:
	movs r3, #0x14
	movs r0, #6
	b _0801D146
_0801D132:
	movs r3, #0xa
	movs r1, #5
	str r1, [sp, #4]
	b _0801D148
_0801D13A:
	movs r3, #0xa
	movs r4, #5
	str r4, [sp, #4]
	b _0801D148
_0801D142:
	movs r3, #0x28
	movs r0, #8
_0801D146:
	str r0, [sp, #4]
_0801D148:
	adds r1, r6, #0
	adds r1, #0xb4
	movs r0, #0xe1
	lsls r0, r0, #3
	str r0, [r1]
	ldrb r0, [r2, #5]
	adds r2, r6, #0
	adds r2, #0x60
	strh r0, [r2]
	subs r0, r0, r3
	subs r1, #0x58
	strh r0, [r1]
	ldrh r0, [r2]
	adds r0, r0, r3
	adds r3, r6, #0
	adds r3, #0x5e
	strh r0, [r3]
	movs r4, #0
	ldrsh r0, [r1, r4]
	str r2, [sp, #0xc]
	mov r8, r1
	mov sb, r3
	cmp r0, #0
	bge _0801D17C
	movs r0, #0
	b _0801D184
_0801D17C:
	cmp r0, #0xb0
	ble _0801D186
	movs r0, #0xb0
	mov r1, r8
_0801D184:
	strh r0, [r1]
_0801D186:
	mov r2, sb
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r0, #0
	bge _0801D196
	movs r0, #0
	strh r0, [r2]
	b _0801D1A0
_0801D196:
	cmp r0, #0xb0
	ble _0801D1A0
	movs r0, #0xb0
	mov r1, sb
	strh r0, [r1]
_0801D1A0:
	adds r2, r6, #0
	adds r2, #0x62
	str r2, [sp, #8]
	movs r4, #0
	strh r4, [r2]
	ldr r0, _0801D318 @ =0x00000E04
	adds r7, r6, r0
	strh r4, [r7, #0x20]
	movs r1, #0xd8
	adds r1, r1, r6
	mov sl, r1
	adds r0, r7, #0
	movs r2, #4
	movs r3, #0
	bl Sprite_SetSprite
	strb r4, [r7, #0x1a]
	ldr r0, [r7, #8]
	movs r2, #1
	orrs r0, r2
	str r0, [r7, #8]
	ldr r0, _0801D31C @ =0x00000E64
	adds r7, r6, r0
	movs r1, #0
	strh r1, [r7, #0x20]
	adds r0, r7, #0
	mov r1, sl
	movs r2, #3
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r7, #8]
	movs r2, #1
	orrs r0, r2
	str r0, [r7, #8]
	strb r4, [r7, #0x1a]
	ldr r4, _0801D320 @ =0x00000EC4
	adds r7, r6, r4
	mov r1, r8
	ldrh r0, [r1]
	strh r0, [r7, #0x20]
	adds r0, r7, #0
	mov r1, sl
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r7, #8]
	movs r2, #1
	orrs r0, r2
	str r0, [r7, #8]
	adds r4, #0x60
	adds r7, r6, r4
	mov r1, sb
	ldrh r0, [r1]
	strh r0, [r7, #0x20]
	adds r0, r7, #0
	mov r1, sl
	movs r2, #2
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r7, #8]
	movs r2, #1
	orrs r0, r2
	str r0, [r7, #8]
	adds r4, #0x60
	adds r7, r6, r4
	ldr r1, [sp, #0xc]
	ldrh r0, [r1]
	strh r0, [r7, #0x20]
	ldr r2, [sp, #4]
	adds r0, r7, #0
	mov r1, sl
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r7, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r7, #8]
	adds r4, #0x60
	adds r7, r6, r4
	ldr r1, [sp, #8]
	ldrh r0, [r1]
	subs r0, #0xb0
	strh r0, [r7, #0x20]
	adds r0, r7, #0
	mov r1, sl
	movs r2, #9
	movs r3, #0
	bl Sprite_SetSprite
	movs r2, #1
	strb r2, [r7, #0x1a]
	ldr r0, [r7, #8]
	movs r4, #2
	rsbs r4, r4, #0
	ands r0, r4
	str r0, [r7, #8]
	ldr r0, _0801D324 @ =0x03003584
	ldr r0, [r0]
	ldr r1, _0801D328 @ =0x000053E0
	adds r0, r0, r1
	ldr r2, _0801D32C @ =0x000012E4
	adds r4, r6, r2
	ldr r2, _0801D330 @ =0x04000008
	adds r1, r4, #0
	bl CpuSet
	movs r0, #0x81
	lsls r0, r0, #8
	strh r0, [r7, #0x3a]
	str r4, [r7, #0x48]
	ldr r4, _0801D334 @ =0x00001044
	adds r7, r6, r4
	movs r0, #0
	strh r0, [r7, #0x20]
	adds r0, r7, #0
	mov r1, sl
	movs r2, #0xa
	movs r3, #0
	bl Sprite_SetSprite
	movs r1, #1
	strb r1, [r7, #0x1a]
	ldr r0, [r7, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r7, #8]
	adds r4, #0x60
	adds r7, r6, r4
	movs r0, #0
	strh r0, [r7, #0x20]
	movs r1, #0
	str r1, [sp]
	adds r0, r7, #0
	mov r1, sl
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r0, [r7, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r7, #8]
	adds r4, #0x60
	adds r7, r6, r4
	movs r5, #0x20
	mov r8, sl
	movs r0, #0
	mov sb, r0
	movs r4, #4
_0801D2D6:
	movs r0, #8
	strh r0, [r7, #0x20]
	strh r5, [r7, #0x22]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0x16
	movs r3, #0
	bl Sprite_SetSprite
	mov r1, sb
	strb r1, [r7, #0x1a]
	ldr r0, [r7, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #8]
	subs r4, #1
	adds r7, #0x60
	adds r5, #8
	cmp r4, #0
	bge _0801D2D6
	ldr r0, [r6, #0x20]
	ldr r1, [r6, #0x24]
	str r0, [r6, #0x18]
	str r1, [r6, #0x1c]
	movs r0, #0
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801D318: .4byte 0x00000E04
_0801D31C: .4byte 0x00000E64
_0801D320: .4byte 0x00000EC4
_0801D324: .4byte 0x03003584
_0801D328: .4byte 0x000053E0
_0801D32C: .4byte 0x000012E4
_0801D330: .4byte 0x04000008
_0801D334: .4byte 0x00001044

	thumb_func_start FUN_0801d338
FUN_0801d338: @ 0x0801D338
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r6, #0x66
	ldrb r1, [r6]
	lsls r5, r1, #2
	adds r5, #0xc4
	adds r5, r0, r5
	lsls r4, r1, #1
	adds r4, r4, r1
	lsls r4, r4, #5
	ldr r1, _0801D390 @ =0x00001104
	adds r4, r4, r1
	adds r4, r0, r4
	adds r1, r0, #0
	adds r1, #0xd8
	adds r0, #0x92
	ldrb r2, [r0]
	adds r2, #0x14
	adds r0, r4, #0
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	movs r1, #0
	movs r0, #1
	strh r0, [r5]
	strh r1, [r5, #2]
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _0801D388
	movs r0, #0
	strb r0, [r6]
_0801D388:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801D390: .4byte 0x00001104

	thumb_func_start FUN_0801d394
FUN_0801d394: @ 0x0801D394
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r2, #0xc4
	ldr r1, _0801D3B8 @ =0x00001104
	adds r3, r0, r1
	movs r6, #0
	movs r5, #4
_0801D3A2:
	ldrh r0, [r2]
	cmp r0, #1
	beq _0801D3BC
	cmp r0, #1
	ble _0801D406
	cmp r0, #2
	beq _0801D3DC
	cmp r0, #3
	beq _0801D3F0
	b _0801D406
	.align 2, 0
_0801D3B8: .4byte 0x00001104
_0801D3BC:
	ldrh r0, [r2, #2]
	movs r1, #8
	subs r1, r1, r0
	lsls r1, r1, #3
	adds r1, #4
	movs r4, #0
	strh r1, [r3, #0x20]
	ldrh r0, [r2, #2]
	cmp r0, #7
	bls _0801D406
	movs r0, #4
	strh r0, [r3, #0x20]
	movs r0, #2
	strh r0, [r2]
	strh r4, [r2, #2]
	b _0801D406
_0801D3DC:
	ldrh r0, [r2, #2]
	cmp r0, #0x3f
	bls _0801D406
	movs r0, #3
	strh r0, [r2]
	strh r6, [r2, #2]
	ldr r0, [r3, #8]
	movs r1, #0x80
	lsls r1, r1, #2
	b _0801D402
_0801D3F0:
	ldrh r0, [r2, #2]
	cmp r0, #7
	bls _0801D406
	strh r6, [r2]
	strh r6, [r2, #2]
	ldr r0, [r3, #8]
	ldr r1, _0801D41C @ =0xFFFFFDFF
	ands r0, r1
	movs r1, #1
_0801D402:
	orrs r0, r1
	str r0, [r3, #8]
_0801D406:
	ldrh r0, [r2, #2]
	adds r0, #1
	strh r0, [r2, #2]
	subs r5, #1
	adds r2, #4
	adds r3, #0x60
	cmp r5, #0
	bge _0801D3A2
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801D41C: .4byte 0xFFFFFDFF

	thumb_func_start FUN_0801d420
FUN_0801d420: @ 0x0801D420
	push {r4, lr}
	adds r3, r0, #0
	adds r0, #0x80
	ldr r0, [r0]
	asrs r4, r0, #5
	ldr r0, _0801D440 @ =0x00000EC4
	adds r2, r3, r0
	adds r0, r4, #0
	subs r0, #0x18
	strh r0, [r2, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _0801D444
	movs r0, #0
	b _0801D44A
	.align 2, 0
_0801D440: .4byte 0x00000EC4
_0801D444:
	cmp r0, #0xb0
	ble _0801D44C
	movs r0, #0xb0
_0801D44A:
	strh r0, [r2, #0x20]
_0801D44C:
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	ldr r0, _0801D46C @ =0x00000F24
	adds r2, r3, r0
	adds r0, r4, #0
	adds r0, #0x18
	strh r0, [r2, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _0801D470
	movs r0, #0
	b _0801D476
	.align 2, 0
_0801D46C: .4byte 0x00000F24
_0801D470:
	cmp r0, #0xb0
	ble _0801D478
	movs r0, #0xb0
_0801D476:
	strh r0, [r2, #0x20]
_0801D478:
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801d488
FUN_0801d488: @ 0x0801D488
	ldr r1, _0801D4A0 @ =0x00000EC4
	adds r3, r0, r1
	ldr r1, [r3, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r3, #8]
	ldr r1, _0801D4A4 @ =0x00000F24
	adds r3, r0, r1
	ldr r0, [r3, #8]
	orrs r0, r2
	str r0, [r3, #8]
	bx lr
	.align 2, 0
_0801D4A0: .4byte 0x00000EC4
_0801D4A4: .4byte 0x00000F24

	thumb_func_start FUN_0801d4a8
FUN_0801d4a8: @ 0x0801D4A8
	ldr r1, _0801D4C0 @ =0x00000E04
	adds r2, r0, r1
	adds r0, #0x93
	ldrb r0, [r0]
	strh r0, [r2, #0x20]
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	bx lr
	.align 2, 0
_0801D4C0: .4byte 0x00000E04

	thumb_func_start FUN_0801d4c4
FUN_0801d4c4: @ 0x0801D4C4
	ldr r1, _0801D4D8 @ =0x00000E04
	adds r2, r0, r1
	adds r0, #0x93
	ldrb r0, [r0]
	strh r0, [r2, #0x20]
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	bx lr
	.align 2, 0
_0801D4D8: .4byte 0x00000E04

	thumb_func_start FUN_0801d4dc
FUN_0801d4dc: @ 0x0801D4DC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r2, #0
	mov ip, r3
	movs r0, #0x99
	lsls r0, r0, #5
	adds r4, r5, r0
	ldr r2, _0801D534 @ =0x0000131C
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r2, #0
	movs r3, #0
	strh r0, [r4]
	ldr r7, _0801D538 @ =0x0000131E
	adds r0, r5, r7
	ldrh r0, [r0]
	strb r0, [r4, #2]
	strb r2, [r4, #3]
	strh r3, [r4, #4]
	strb r1, [r4, #6]
	strb r6, [r4, #7]
	mov r0, ip
	cmp r0, #0
	beq _0801D526
	cmp r6, #0
	ble _0801D526
	mov r3, ip
	ldr r2, _0801D53C @ =0x00001328
	adds r1, r5, r2
	adds r2, r6, #0
_0801D518:
	ldrh r0, [r3]
	strh r0, [r1]
	adds r3, #2
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bne _0801D518
_0801D526:
	adds r0, r4, #0
	bl FUN_080224f0
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801D534: .4byte 0x0000131C
_0801D538: .4byte 0x0000131E
_0801D53C: .4byte 0x00001328

	thumb_func_start FUN_0801d540
FUN_0801d540: @ 0x0801D540
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, _0801D58C @ =0x00000FE4
	adds r2, r7, r0
	adds r1, r7, #0
	adds r1, #0x62
	ldrh r0, [r1]
	subs r0, #0xb0
	movs r3, #0
	strh r0, [r2, #0x20]
	adds r0, r7, #0
	adds r0, #0x5c
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r4, #0
	ldrsh r0, [r0, r4]
	ldr r4, _0801D590 @ =0x000010A4
	adds r2, r7, r4
	cmp r1, r0
	bge _0801D594
	adds r1, r7, #0
	adds r1, #0x64
	ldrb r0, [r1]
	adds r6, r7, #0
	adds r6, #0xd8
	cmp r0, #1
	beq _0801D5E2
	movs r0, #1
	strb r0, [r1]
	str r3, [sp]
	adds r0, r2, #0
	adds r1, r6, #0
	movs r2, #0
	b _0801D5BA
	.align 2, 0
_0801D58C: .4byte 0x00000FE4
_0801D590: .4byte 0x000010A4
_0801D594:
	adds r0, r7, #0
	adds r0, #0x5e
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bge _0801D5C2
	adds r1, r7, #0
	adds r1, #0x64
	ldrb r0, [r1]
	adds r6, r7, #0
	adds r6, #0xd8
	cmp r0, #2
	beq _0801D5E2
	movs r0, #2
	strb r0, [r1]
	str r3, [sp]
	adds r0, r2, #0
	adds r1, r6, #0
	movs r2, #1
_0801D5BA:
	movs r3, #1
	bl FUN_082370cc
	b _0801D5E2
_0801D5C2:
	adds r1, r7, #0
	adds r1, #0x64
	ldrb r0, [r1]
	adds r6, r7, #0
	adds r6, #0xd8
	cmp r0, #3
	beq _0801D5E2
	movs r0, #3
	strb r0, [r1]
	str r3, [sp]
	adds r0, r2, #0
	adds r1, r6, #0
	movs r2, #2
	movs r3, #1
	bl FUN_082370cc
_0801D5E2:
	movs r0, #0xb4
	adds r0, r0, r7
	mov sb, r0
	ldr r1, _0801D604 @ =0x00000E04
	adds r4, r7, r1
	movs r5, #0xc
_0801D5EE:
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_082372cc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0801D5EE
	movs r5, #0
	b _0801D61E
	.align 2, 0
_0801D604: .4byte 0x00000E04
_0801D608:
	adds r1, r5, #6
	movs r0, #0
	str r0, [sp]
	movs r0, #0xd
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #0x10
	movs r3, #5
	bl FUN_0822bcf4
	adds r5, #1
_0801D61E:
	ldr r0, [r7, #0x6c]
	cmp r5, r0
	blo _0801D608
	cmp r5, #9
	bgt _0801D642
	movs r6, #0
	movs r4, #0xd
_0801D62C:
	adds r1, r5, #6
	str r6, [sp]
	str r4, [sp, #4]
	movs r0, #0
	movs r2, #0x10
	movs r3, #6
	bl FUN_0822bcf4
	adds r5, #1
	cmp r5, #9
	ble _0801D62C
_0801D642:
	mov r2, sb
	ldr r0, [r2]
	movs r1, #0x3c
	bl Mod
	movs r1, #0x64
	muls r0, r1, r0
	movs r1, #0x3c
	bl Div
	mov r8, r0
	mov r4, sb
	ldr r0, [r4]
	movs r1, #0x3c
	bl Div
	adds r3, r0, #0
	movs r6, #0x11
	str r6, [sp]
	movs r5, #2
	str r5, [sp, #4]
	movs r4, #0xd
	str r4, [sp, #8]
	movs r0, #0
	movs r1, #0x15
	movs r2, #0x10
	bl FUN_0822be3c
	str r6, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0
	movs r1, #0x18
	movs r2, #0x10
	mov r3, r8
	bl FUN_0822be3c
	adds r0, r7, #0
	bl FUN_0801d394
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801d6a0
FUN_0801d6a0: @ 0x0801D6A0
	push {r4, r5, lr}
	ldr r1, _0801D6BC @ =0x00000E04
	adds r4, r0, r1
	movs r5, #0xc
_0801D6A8:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0801D6A8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801D6BC: .4byte 0x00000E04

	thumb_func_start FUN_0801d6c0
FUN_0801d6c0: @ 0x0801D6C0
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	bl FUN_0801b8e8
	cmp r0, #0
	beq _0801D6E6
	movs r0, #4
	str r0, [sp]
	ldr r0, _0801D700 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_0801D6E6:
	ldr r0, [r4, #0x44]
	cmp r0, #0x1f
	bls _0801D708
	adds r0, r4, #0
	bl FUN_0801d01c
	bl FUN_08049f84
	ldr r1, _0801D704 @ =FUN_0801d71c
	adds r0, r4, #0
	bl FUN_0801b8d0
	b _0801D714
	.align 2, 0
_0801D700: .4byte 0x0000FFFF
_0801D704: .4byte FUN_0801d71c
_0801D708:
	adds r0, r4, #0
	bl FUN_0801c7dc
	ldr r0, [r4, #0x44]
	adds r0, #1
	str r0, [r4, #0x44]
_0801D714:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801d71c
FUN_0801d71c: @ 0x0801D71C
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	bl FUN_0801b8e8
	cmp r0, #0
	beq _0801D758
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0801c114
	adds r0, r4, #0
	bl FUN_0801d0e0
	movs r0, #4
	str r0, [sp]
	ldr r0, _0801D768 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r0, _0801D76C @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0
	bl FUN_0807c7c8
_0801D758:
	ldr r0, [r4, #0x44]
	cmp r0, #0x1f
	bls _0801D774
	ldr r1, _0801D770 @ =FUN_0801d788
	adds r0, r4, #0
	bl FUN_0801b8d0
	b _0801D780
	.align 2, 0
_0801D768: .4byte 0x0000FFFF
_0801D76C: .4byte 0x03002BE0
_0801D770: .4byte FUN_0801d788
_0801D774:
	adds r0, r4, #0
	bl FUN_0801d540
	ldr r0, [r4, #0x44]
	adds r0, #1
	str r0, [r4, #0x44]
_0801D780:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801d788
FUN_0801d788: @ 0x0801D788
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0801b8e8
	cmp r0, #0
	beq _0801D7A0
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0
	movs r3, #0
	bl FUN_0801d4dc
_0801D7A0:
	ldr r0, [r4, #0x44]
	cmp r0, #0xef
	bls _0801D7B4
	ldr r1, _0801D7B0 @ =FUN_0801db1c
	adds r0, r4, #0
	bl FUN_0801b8d0
	b _0801D7D2
	.align 2, 0
_0801D7B0: .4byte FUN_0801db1c
_0801D7B4:
	movs r1, #0x3d
	bl Mod
	cmp r0, #0x3c
	bne _0801D7C6
	movs r0, #0x87
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0801D7C6:
	adds r0, r4, #0
	bl FUN_0801d540
	ldr r0, [r4, #0x44]
	adds r0, #1
	str r0, [r4, #0x44]
_0801D7D2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801d7d8
FUN_0801d7d8: @ 0x0801D7D8
	push {lr}
	ldr r2, _0801D7E8 @ =0x00001310
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	bne _0801D7EC
	movs r0, #0
	b _0801D7F2
	.align 2, 0
_0801D7E8: .4byte 0x00001310
_0801D7EC:
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
_0801D7F2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801d7f8
FUN_0801d7f8: @ 0x0801D7F8
	ldr r3, _0801D810 @ =0x00001318
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _0801D814 @ =0x00001310
	adds r2, r0, r1
	movs r3, #0
	movs r1, #1
	strb r1, [r2]
	ldr r1, _0801D818 @ =0x00001314
	adds r0, r0, r1
	str r3, [r0]
	bx lr
	.align 2, 0
_0801D810: .4byte 0x00001318
_0801D814: .4byte 0x00001310
_0801D818: .4byte 0x00001314

	thumb_func_start FUN_0801d81c
FUN_0801d81c: @ 0x0801D81C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0801d7d8
	cmp r0, #0
	beq _0801D830
	ldr r0, _0801D858 @ =0x00001302
	adds r1, r4, r0
	movs r0, #0x9f
	strh r0, [r1]
_0801D830:
	ldr r1, [r4, #0x6c]
	cmp r1, #0
	beq _0801D860
	adds r2, r4, #0
	adds r2, #0x84
	adds r1, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, [r2]
	adds r1, r1, r0
	str r1, [r2]
	ldr r0, _0801D85C @ =0x000015FF
	adds r3, r2, #0
	cmp r1, r0
	ble _0801D872
	adds r0, #1
	str r0, [r3]
	b _0801D872
	.align 2, 0
_0801D858: .4byte 0x00001302
_0801D85C: .4byte 0x000015FF
_0801D860:
	adds r2, r4, #0
	adds r2, #0x84
	ldr r1, [r2]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #6
	str r0, [r2]
	adds r3, r2, #0
_0801D872:
	ldr r0, _0801D8AC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0801D8B8
	ldr r0, _0801D8B0 @ =0x00000E64
	adds r2, r4, r0
	adds r1, r4, #0
	adds r1, #0x80
	ldr r0, [r3]
	str r0, [r1]
	asrs r0, r0, #5
	strh r0, [r2, #0x20]
	ldr r1, _0801D8B4 @ =FUN_0801d8cc
	adds r0, r4, #0
	bl FUN_0801d7f8
	adds r0, r4, #0
	movs r1, #4
	movs r2, #0
	movs r3, #0
	bl FUN_0801d4dc
	adds r0, r4, #0
	bl FUN_0801d420
	b _0801D8C2
	.align 2, 0
_0801D8AC: .4byte 0x030044E0
_0801D8B0: .4byte 0x00000E64
_0801D8B4: .4byte FUN_0801d8cc
_0801D8B8:
	ldr r0, _0801D8C8 @ =0x00001314
	adds r1, r4, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0801D8C2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801D8C8: .4byte 0x00001314

	thumb_func_start FUN_0801d8cc
FUN_0801d8cc: @ 0x0801D8CC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	bl FUN_0801d7d8
	cmp r0, #0
	beq _0801D904
	adds r1, r5, #0
	adds r1, #0x88
	movs r0, #0
	str r0, [r1]
	str r0, [r5, #0x7c]
	adds r1, #4
	str r0, [r1]
	adds r1, #4
	strb r0, [r1]
	subs r1, #0x2a
	strb r0, [r1]
	adds r1, #0x2c
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	ldr r0, _0801D934 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #1
	bl FUN_0807c7c8
_0801D904:
	ldr r0, [r5, #0x6c]
	movs r1, #3
	cmp r0, #0
	beq _0801D90E
	movs r1, #6
_0801D90E:
	lsrs r0, r0, #1
	adds r1, r1, r0
	adds r2, r5, #0
	adds r2, #0x88
	ldr r0, [r2]
	cmp r0, #0
	beq _0801D93C
	lsls r0, r1, #2
	ldr r1, [r5, #0x7c]
	adds r1, r1, r0
	str r1, [r5, #0x7c]
	ldr r0, _0801D938 @ =0x000002FF
	cmp r1, r0
	ble _0801D950
	adds r0, #1
	str r0, [r5, #0x7c]
	movs r0, #0
	b _0801D94E
	.align 2, 0
_0801D934: .4byte 0x03002BE0
_0801D938: .4byte 0x000002FF
_0801D93C:
	lsls r1, r1, #2
	ldr r0, [r5, #0x7c]
	subs r0, r0, r1
	str r0, [r5, #0x7c]
	ldr r1, _0801D968 @ =0xFFFFFD00
	cmp r0, r1
	bgt _0801D950
	str r1, [r5, #0x7c]
	movs r0, #1
_0801D94E:
	str r0, [r2]
_0801D950:
	adds r2, r5, #0
	adds r2, #0x84
	adds r0, r5, #0
	adds r0, #0x80
	ldr r1, [r0]
	ldr r0, [r5, #0x7c]
	adds r1, r1, r0
	str r1, [r2]
	cmp r1, #0
	bge _0801D96C
	movs r0, #0
	b _0801D974
	.align 2, 0
_0801D968: .4byte 0xFFFFFD00
_0801D96C:
	movs r0, #0xb0
	lsls r0, r0, #5
	cmp r1, r0
	ble _0801D976
_0801D974:
	str r0, [r2]
_0801D976:
	ldr r0, _0801DA34 @ =0x03003584
	ldr r0, [r0]
	ldr r1, _0801DA38 @ =0x000053E0
	adds r4, r0, r1
	ldr r0, _0801DA3C @ =0x00001314
	adds r0, r0, r5
	mov r8, r0
	ldr r0, [r0]
	movs r1, #0x10
	bl Div
	adds r6, r0, #0
	adds r7, r5, #0
	adds r7, #0x8c
	ldr r0, [r7]
	lsls r0, r0, #5
	movs r1, #5
	bl Div
	cmp r6, r0
	bge _0801D9A2
	adds r6, r0, #0
_0801D9A2:
	movs r1, #0x20
	subs r1, r1, r6
	lsls r3, r1, #5
	subs r3, r3, r1
	ldrh r2, [r4, #0x1e]
	movs r4, #0x1f
	movs r0, #0x1f
	ands r0, r2
	muls r0, r6, r0
	adds r3, r3, r0
	asrs r3, r3, #5
	lsls r1, r1, #2
	lsls r2, r2, #0x10
	lsrs r0, r2, #0x15
	ands r0, r4
	muls r0, r6, r0
	adds r1, r1, r0
	asrs r1, r1, #5
	lsrs r2, r2, #0x1a
	ands r2, r4
	adds r0, r2, #0
	muls r0, r6, r0
	asrs r0, r0, #5
	ands r3, r4
	ands r1, r4
	lsls r1, r1, #5
	adds r3, r3, r1
	ands r0, r4
	lsls r0, r0, #0xa
	adds r3, r3, r0
	ldr r1, _0801DA40 @ =0x00001302
	adds r0, r5, r1
	strh r3, [r0]
	adds r2, r5, #0
	adds r2, #0x90
	ldrb r0, [r2]
	cmp r0, #0
	bne _0801DA50
	ldr r0, [r7]
	cmp r0, #4
	bgt _0801DA28
	ldr r0, _0801DA44 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0801DA1E
	adds r1, r5, #0
	adds r1, #0x91
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xd
	strb r0, [r2]
	ldr r0, [r7]
	adds r0, #1
	str r0, [r7]
	adds r0, r5, #0
	movs r1, #6
	movs r2, #0
	movs r3, #0
	bl FUN_0801d4dc
_0801DA1E:
	mov r0, r8
	ldr r1, [r0]
	ldr r0, _0801DA48 @ =0x000001FF
	cmp r1, r0
	bls _0801DA62
_0801DA28:
	ldr r1, _0801DA4C @ =FUN_0801da7c
	adds r0, r5, #0
	bl FUN_0801d7f8
	b _0801DA6C
	.align 2, 0
_0801DA34: .4byte 0x03003584
_0801DA38: .4byte 0x000053E0
_0801DA3C: .4byte 0x00001314
_0801DA40: .4byte 0x00001302
_0801DA44: .4byte 0x030044E0
_0801DA48: .4byte 0x000001FF
_0801DA4C: .4byte FUN_0801da7c
_0801DA50:
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bne _0801DA62
	adds r0, r5, #0
	bl FUN_0801d338
_0801DA62:
	ldr r0, _0801DA78 @ =0x00001314
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0801DA6C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801DA78: .4byte 0x00001314

	thumb_func_start FUN_0801da7c
FUN_0801da7c: @ 0x0801DA7C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0801d7d8
	cmp r0, #0
	beq _0801DAD0
	ldr r0, _0801DAF4 @ =0x00000E64
	adds r3, r4, r0
	ldr r0, _0801DAF8 @ =0x03003584
	ldr r2, [r0]
	ldr r1, _0801DAFC @ =0x000053E0
	adds r2, r2, r1
	ldr r0, [r3, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r3, #8]
	ldrh r2, [r2, #0x1e]
	ldr r1, _0801DB00 @ =0x00001302
	adds r0, r4, r1
	movs r1, #0
	strh r2, [r0]
	adds r0, r4, #0
	adds r0, #0x88
	str r1, [r0]
	str r1, [r4, #0x7c]
	adds r0, r4, #0
	movs r1, #8
	movs r2, #0
	movs r3, #0
	bl FUN_0801d4dc
	adds r0, r4, #0
	bl FUN_0801d488
	adds r0, r4, #0
	bl FUN_0801d4c4
	ldr r0, _0801DB04 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0
	bl FUN_0807c7c8
_0801DAD0:
	adds r2, r4, #0
	adds r2, #0x84
	ldr r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #5
	str r0, [r2]
	ldr r0, _0801DB08 @ =0x00001314
	adds r1, r4, r0
	ldr r0, [r1]
	cmp r0, #0x1f
	bls _0801DB10
	ldr r1, _0801DB0C @ =FUN_0801d81c
	adds r0, r4, #0
	bl FUN_0801d7f8
	b _0801DB14
	.align 2, 0
_0801DAF4: .4byte 0x00000E64
_0801DAF8: .4byte 0x03003584
_0801DAFC: .4byte 0x000053E0
_0801DB00: .4byte 0x00001302
_0801DB04: .4byte 0x03002BE0
_0801DB08: .4byte 0x00001314
_0801DB0C: .4byte FUN_0801d81c
_0801DB10:
	adds r0, #1
	str r0, [r1]
_0801DB14:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801db1c
FUN_0801db1c: @ 0x0801DB1C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	bl FUN_0801b8e8
	cmp r0, #0
	beq _0801DB74
	ldr r1, _0801DB9C @ =FUN_0801d81c
	adds r0, r5, #0
	bl FUN_0801d7f8
	adds r0, r5, #0
	adds r0, #0x84
	movs r1, #0
	str r1, [r0]
	str r1, [r5, #0x7c]
	adds r2, r5, #0
	adds r2, #0x80
	movs r0, #0x20
	str r0, [r2]
	ldr r0, [r5, #0x68]
	asrs r0, r0, #5
	str r0, [r5, #0x6c]
	adds r0, r5, #0
	adds r0, #0x66
	strb r1, [r0]
	adds r0, #0x3e
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0x88
	movs r0, #2
	str r0, [r1]
	ldr r0, [r5, #0x6c]
	cmp r0, #0xa
	bls _0801DB70
	movs r0, #0xa
	str r0, [r5, #0x6c]
_0801DB70:
	ldr r0, [r5, #0x6c]
	str r0, [r5, #0x70]
_0801DB74:
	adds r4, r5, #0
	adds r4, #0x91
	movs r6, #0
	strb r6, [r4]
	ldr r1, _0801DBA0 @ =0x00001318
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	adds r0, #0x84
	ldr r1, [r0]
	movs r2, #0xb0
	lsls r2, r2, #5
	cmp r1, r2
	ble _0801DBA4
	str r2, [r0]
	b _0801DBAA
	.align 2, 0
_0801DB9C: .4byte FUN_0801d81c
_0801DBA0: .4byte 0x00001318
_0801DBA4:
	cmp r1, #0
	bge _0801DBAA
	str r6, [r0]
_0801DBAA:
	ldr r0, [r0]
	asrs r0, r0, #5
	adds r6, r5, #0
	adds r6, #0x62
	movs r7, #0
	adds r2, r0, #0
	strh r0, [r6]
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801DC62
	adds r0, r5, #0
	adds r0, #0x60
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #0
	ldrsh r0, [r6, r3]
	subs r4, r1, r0
	cmp r4, #0
	bge _0801DBD2
	rsbs r4, r4, #0
_0801DBD2:
	adds r0, r5, #0
	adds r0, #0x93
	strb r2, [r0]
	adds r0, r5, #0
	bl FUN_0801d4a8
	adds r1, r5, #0
	adds r1, #0xa0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	adds r0, r5, #0
	adds r0, #0x5c
	movs r2, #0
	ldrsh r1, [r6, r2]
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	blt _0801DC50
	adds r0, r5, #0
	adds r0, #0x5e
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bgt _0801DC50
	cmp r4, #1
	bgt _0801DC28
	adds r1, r5, #0
	adds r1, #0x65
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x43
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	subs r1, #4
	ldr r0, [r1]
	adds r0, #0x64
	str r0, [r1]
	adds r0, r5, #0
	adds r0, #0x92
	strb r7, [r0]
	b _0801DC62
_0801DC28:
	adds r0, r5, #0
	adds r0, #0x65
	strb r7, [r0]
	cmp r4, #0x63
	bgt _0801DC3E
	adds r1, r5, #0
	adds r1, #0xa4
	ldr r0, [r1]
	adds r0, #0x64
	subs r0, r0, r4
	str r0, [r1]
_0801DC3E:
	adds r0, r5, #0
	adds r0, #0xac
	ldr r1, [r0]
	adds r1, #1
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0x92
	movs r0, #1
	b _0801DC60
_0801DC50:
	adds r0, r5, #0
	adds r0, #0xb0
	ldr r1, [r0]
	adds r1, #1
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0x92
	movs r0, #2
_0801DC60:
	strb r0, [r1]
_0801DC62:
	adds r0, r5, #0
	bl FUN_0801d540
	adds r1, r5, #0
	adds r1, #0xb4
	ldr r0, [r1]
	cmp r0, #0
	bne _0801DC80
	ldr r1, _0801DC7C @ =FUN_0801dc90
	adds r0, r5, #0
	bl FUN_0801b8d0
	b _0801DC8A
	.align 2, 0
_0801DC7C: .4byte FUN_0801dc90
_0801DC80:
	subs r0, #1
	str r0, [r1]
	ldr r0, [r5, #0x44]
	adds r0, #1
	str r0, [r5, #0x44]
_0801DC8A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801dc90
FUN_0801dc90: @ 0x0801DC90
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0801b8e8
	cmp r0, #0
	beq _0801DCAE
	adds r0, r4, #0
	movs r1, #9
	movs r2, #0
	movs r3, #0
	bl FUN_0801d4dc
	movs r0, #0xa9
	bl sound_08240264
_0801DCAE:
	adds r0, r4, #0
	bl FUN_0801d540
	adds r0, r4, #0
	adds r0, #0x18
	bl FUN_0823b8ac
	ldr r0, [r4, #0x44]
	cmp r0, #0x1d
	bls _0801DCD0
	ldr r1, _0801DCCC @ =FUN_0801dcdc
	adds r0, r4, #0
	bl FUN_0801b8d0
	b _0801DCD4
	.align 2, 0
_0801DCCC: .4byte FUN_0801dcdc
_0801DCD0:
	adds r0, #1
	str r0, [r4, #0x44]
_0801DCD4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801dcdc
FUN_0801dcdc: @ 0x0801DCDC
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	bl FUN_0801b8e8
	cmp r0, #0
	beq _0801DD0C
	movs r1, #2
	add r0, sp, #4
	strh r1, [r0]
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	add r3, sp, #4
	bl FUN_0801d4dc
	ldr r0, _0801DD68 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #3
	bl FUN_0807c7c8
	ldr r0, _0801DD6C @ =0x000002E1
	bl PlaySound_082406e0
_0801DD0C:
	adds r0, r4, #0
	bl FUN_0801d540
	adds r0, r4, #0
	adds r0, #0x18
	bl FUN_0823b8ac
	ldr r1, [r4, #0x44]
	adds r0, r1, #0
	subs r0, #0x1e
	cmp r0, #0x45
	bhi _0801DD56
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _0801DD56
	ldr r0, _0801DD68 @ =0x03002BE0
	ldr r0, [r0]
	add r3, sp, #8
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldrh r0, [r3]
	adds r0, #0xc8
	strh r0, [r3]
	movs r2, #0x80
	lsls r2, r2, #6
	str r3, [sp]
	movs r0, #2
	movs r1, #0
	movs r3, #0x40
	bl FUN_08015c90
	ldr r0, _0801DD70 @ =0x000001C5
	bl PlaySound_082406e0
_0801DD56:
	ldr r0, [r4, #0x44]
	cmp r0, #0x63
	bls _0801DD78
	ldr r1, _0801DD74 @ =FUN_0801dd84
	adds r0, r4, #0
	bl FUN_0801b8d0
	b _0801DD7C
	.align 2, 0
_0801DD68: .4byte 0x03002BE0
_0801DD6C: .4byte 0x000002E1
_0801DD70: .4byte 0x000001C5
_0801DD74: .4byte FUN_0801dd84
_0801DD78:
	adds r0, #1
	str r0, [r4, #0x44]
_0801DD7C:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801dd84
FUN_0801dd84: @ 0x0801DD84
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x34
	adds r6, r0, #0
	ldr r7, _0801DF18 @ =0x03002BE0
	ldr r4, [r7]
	adds r5, r4, #0
	bl FUN_0801b8e8
	cmp r0, #0
	beq _0801DDC4
	adds r0, r6, #0
	bl FUN_0801bcd8
	ldr r0, [r6, #0x18]
	ldr r1, [r6, #0x1c]
	str r0, [r6, #0x28]
	str r1, [r6, #0x2c]
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r6, #0x30]
	str r1, [r6, #0x34]
	adds r1, r6, #0
	adds r1, #0x94
	movs r0, #4
	strb r0, [r1]
	ldr r0, [r7]
	movs r1, #4
	bl FUN_0807b910
_0801DDC4:
	adds r0, r6, #0
	bl FUN_0801d540
	ldr r3, [r6, #0x44]
	adds r4, r6, #0
	adds r4, #0x18
	cmp r3, #0x20
	bhi _0801DDE6
	adds r1, r6, #0
	adds r1, #0x28
	adds r2, r6, #0
	adds r2, #0x30
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_08237970
_0801DDE6:
	adds r0, r4, #0
	bl FUN_0823b8ac
	ldr r0, [r6, #0x44]
	cmp r0, #0x1e
	bne _0801DE12
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	movs r0, #0
	str r0, [sp]
	add r0, sp, #0x1c
	movs r1, #0x40
	movs r2, #0x3c
	movs r3, #8
	bl FUN_08019814
	movs r0, #0xa7
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0801DE12:
	ldr r0, [r6, #0x44]
	cmp r0, #0x5a
	bne _0801DE68
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r4, r6, r0
	ldr r0, [r7]
	add r2, sp, #0x24
	adds r3, r0, #0
	adds r3, #0x2c
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #0x24]
	str r1, [sp, #0x28]
	ldrh r0, [r2]
	subs r0, #0x20
	strh r0, [r2]
	ldrh r0, [r2, #4]
	adds r0, #0x20
	strh r0, [r2, #4]
	ldrh r0, [r2, #2]
	adds r0, #0x80
	strh r0, [r2, #2]
	ldrb r1, [r4]
	str r2, [sp]
	str r3, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	movs r0, #1
	movs r2, #0
	movs r3, #0
	bl FUN_080177b4
	ldr r0, [r7]
	movs r1, #0
	movs r2, #0
	bl FUN_0807bbb0
	movs r0, #0x88
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0801DE68:
	ldr r0, [r6, #0x44]
	cmp r0, #0x60
	beq _0801DE70
	b _0801DF72
_0801DE70:
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r5, r6, r0
	ldr r4, [r7]
	cmp r4, #0
	beq _0801DF72
	ldrb r0, [r5, #2]
	cmp r0, #4
	bne _0801DF72
	ldrh r0, [r4, #0x2c]
	ldr r3, _0801DF1C @ =0xFFFF0000
	ldr r2, [sp, #0x2c]
	ands r2, r3
	orrs r2, r0
	str r2, [sp, #0x2c]
	movs r0, #0xbd
	lsls r0, r0, #1
	adds r1, r0, #0
	ldrh r0, [r4, #0x2e]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _0801DF20 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x2c]
	ldrh r2, [r4, #0x30]
	add r1, sp, #0x2c
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	ldrb r0, [r5]
	mov sb, r1
	cmp r0, #5
	beq _0801DF72
	cmp r0, #0x18
	beq _0801DF72
	cmp r0, #0x2b
	beq _0801DF72
	cmp r0, #0x13
	beq _0801DECA
	cmp r0, #0x26
	beq _0801DECA
	cmp r0, #0x39
	bne _0801DF28
_0801DECA:
	movs r0, #0x1f
	str r0, [sp]
	ldr r0, _0801DF24 @ =0x00000FFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r1, #3
	movs r2, #0x1f
	movs r3, #0x1f
	bl FUN_0823ce68
	movs r0, #0x58
	mov r8, r0
	movs r4, #8
	movs r7, #0
	movs r5, #2
_0801DEEA:
	mov r0, r8
	str r0, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #1
	str r0, [sp, #0x10]
	movs r0, #0xc
	str r0, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r0, #4
	movs r1, #0x86
	lsls r1, r1, #2
	mov r2, sb
	adds r3, r7, #0
	bl FUN_080149dc
	adds r7, #0x58
	subs r5, #1
	cmp r5, #0
	bge _0801DEEA
	b _0801DF72
	.align 2, 0
_0801DF18: .4byte 0x03002BE0
_0801DF1C: .4byte 0xFFFF0000
_0801DF20: .4byte 0x0000FFFF
_0801DF24: .4byte 0x00000FFF
_0801DF28:
	movs r0, #7
	str r0, [sp]
	ldr r0, _0801DF90 @ =0x00000FFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r1, #3
	movs r2, #0x1f
	movs r3, #0x17
	bl FUN_0823ce68
	movs r0, #0x58
	mov r8, r0
	movs r4, #8
	movs r7, #0
	movs r5, #2
_0801DF48:
	mov r0, r8
	str r0, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #1
	str r0, [sp, #0x10]
	movs r0, #0xc
	str r0, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r0, #4
	movs r1, #0x86
	lsls r1, r1, #2
	mov r2, sb
	adds r3, r7, #0
	bl FUN_080149dc
	adds r7, #0x58
	subs r5, #1
	cmp r5, #0
	bge _0801DF48
_0801DF72:
	ldr r0, [r6, #0x44]
	cmp r0, #0xa3
	bls _0801DF9C
	ldr r1, _0801DF94 @ =FUN_0801dfb0
	adds r0, r6, #0
	bl FUN_0801b8d0
	ldr r0, _0801DF98 @ =0x03002BE0
	ldr r0, [r0]
	adds r1, r6, #0
	adds r1, #0x94
	ldrb r1, [r1]
	bl FUN_0807b910
	b _0801DFA0
	.align 2, 0
_0801DF90: .4byte 0x00000FFF
_0801DF94: .4byte FUN_0801dfb0
_0801DF98: .4byte 0x03002BE0
_0801DF9C:
	adds r0, #1
	str r0, [r6, #0x44]
_0801DFA0:
	add sp, #0x34
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801dfb0
FUN_0801dfb0: @ 0x0801DFB0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x44]
	adds r0, #1
	str r0, [r4, #0x44]
	cmp r0, #0x3c
	bne _0801DFD0
	adds r0, r4, #0
	adds r0, #0xba
	ldrh r0, [r0]
	cmp r0, #0
	beq _0801DFD0
	adds r0, r4, #0
	bl FUN_0801c01c
	b _0801DFDE
_0801DFD0:
	adds r0, r4, #0
	bl FUN_0801d540
	adds r0, r4, #0
	adds r0, #0x18
	bl FUN_0823b8ac
_0801DFDE:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801dfe4
FUN_0801dfe4: @ 0x0801DFE4
	push {lr}
	ldr r0, _0801DFFC @ =0x03000098
	ldr r0, [r0]
	cmp r0, #0
	beq _0801DFF8
	adds r1, r0, #0
	adds r1, #0x65
	ldrb r0, [r1]
	cmp r0, #0
	bne _0801E000
_0801DFF8:
	movs r0, #0
	b _0801E006
	.align 2, 0
_0801DFFC: .4byte 0x03000098
_0801E000:
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
_0801E006:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801e00c
FUN_0801e00c: @ 0x0801E00C
	push {lr}
	ldr r0, _0801E01C @ =0x03000098
	ldr r0, [r0]
	cmp r0, #0
	beq _0801E020
	adds r0, #0x92
	ldrb r0, [r0]
	b _0801E022
	.align 2, 0
_0801E01C: .4byte 0x03000098
_0801E020:
	movs r0, #2
_0801E022:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801e028
FUN_0801e028: @ 0x0801E028
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0824175c
	str r0, [r4, #0x6c]
	ldr r1, _0801E048 @ =0x00001304
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801E048: .4byte 0x00001304

	thumb_func_start FUN_0801e04c
FUN_0801e04c: @ 0x0801E04C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0801c5d0
	adds r0, r4, #0
	bl FUN_0801c434
	adds r0, r4, #0
	bl FUN_0801c454
	adds r0, r4, #0
	bl FUN_0801c474
	adds r0, r4, #0
	bl FUN_0801d6a0
	bl FUN_08049f84
	ldr r1, _0801E07C @ =0x03000098
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801E07C: .4byte 0x03000098

	thumb_func_start FUN_0801e080
FUN_0801e080: @ 0x0801E080
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r0, _0801E13C @ =0x03000098
	str r4, [r0]
	ldr r0, _0801E140 @ =0x0000CB05
	mov r8, r0
	ldr r1, _0801E144 @ =0x0000414C
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	bne _0801E09E
	b _0801E1A6
_0801E09E:
	adds r0, r4, #0
	adds r0, #0xd8
	adds r2, r0, #0
	adds r1, r3, #0
	ldm r1!, {r5, r6, r7}
	stm r2!, {r5, r6, r7}
	ldm r1!, {r5, r6, r7}
	stm r2!, {r5, r6, r7}
	ldm r1!, {r5, r6}
	stm r2!, {r5, r6}
	adds r1, r3, #0
	bl OpenSpriteSetFile
	ldr r1, _0801E148 @ =0x0000B343
	mov r0, r8
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0801E1A6
	adds r0, r4, #0
	adds r0, #0xf8
	adds r2, r0, #0
	adds r1, r3, #0
	ldm r1!, {r5, r6, r7}
	stm r2!, {r5, r6, r7}
	ldm r1!, {r5, r6, r7}
	stm r2!, {r5, r6, r7}
	ldm r1!, {r5, r7}
	stm r2!, {r5, r7}
	adds r1, r3, #0
	bl OpenSpriteSetFile
	ldr r1, _0801E14C @ =0x00005D04
	mov r0, r8
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0801E1A6
	movs r6, #0x8c
	lsls r6, r6, #1
	adds r0, r4, r6
	adds r2, r0, #0
	adds r1, r3, #0
	ldm r1!, {r5, r6, r7}
	stm r2!, {r5, r6, r7}
	ldm r1!, {r5, r6, r7}
	stm r2!, {r5, r6, r7}
	ldm r1!, {r5, r7}
	stm r2!, {r5, r7}
	adds r1, r3, #0
	bl OpenSpriteSetFile
	ldr r1, _0801E150 @ =0x0000B156
	movs r0, #0x6e
	bl Script_GetKeywordValue
	ldr r6, _0801E154 @ =0x0000131C
	adds r1, r4, r6
	strh r0, [r1]
	ldr r7, _0801E158 @ =0x0000131E
	adds r1, r4, r7
	movs r0, #5
	strh r0, [r1]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0801E15C
	bl Script_GetValue
	strh r0, [r4, #0x18]
	bl Script_GetValue
	strh r0, [r4, #0x1a]
	bl Script_GetValue
	b _0801E160
	.align 2, 0
_0801E13C: .4byte 0x03000098
_0801E140: .4byte 0x0000CB05
_0801E144: .4byte 0x0000414C
_0801E148: .4byte 0x0000B343
_0801E14C: .4byte 0x00005D04
_0801E150: .4byte 0x0000B156
_0801E154: .4byte 0x0000131C
_0801E158: .4byte 0x0000131E
_0801E15C:
	strh r0, [r4, #0x18]
	strh r0, [r4, #0x1a]
_0801E160:
	strh r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0x18
	ldr r1, [r4, #0x18]
	ldr r2, [r4, #0x1c]
	str r1, [r4, #0x20]
	str r2, [r4, #0x24]
	bl FUN_0823b8ac
	movs r0, #0x63
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r4, #0
	adds r1, #0xb8
	strh r0, [r1]
	movs r0, #0x65
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r4, #0
	adds r1, #0xba
	strh r0, [r1]
	movs r0, #0x77
	bl prepare_08231510
	cmp r0, #0
	beq _0801E1A6
	bl FUN_0823d340
	ldr r2, _0801E1AC @ =0x00001308
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	bne _0801E1B0
_0801E1A6:
	movs r0, #1
	rsbs r0, r0, #0
	b _0801E206
	.align 2, 0
_0801E1AC: .4byte 0x00001308
_0801E1B0:
	movs r0, #0x6b
	bl prepare_08231510
	cmp r0, #0
	beq _0801E1A6
	bl FUN_0823d340
	ldr r5, _0801E210 @ =0x0000130C
	adds r1, r4, r5
	str r0, [r1]
	cmp r0, #0
	beq _0801E1A6
	adds r0, r4, #0
	bl FUN_0801c260
	adds r0, r4, #0
	bl FUN_0801c4bc
	adds r0, r4, #0
	bl FUN_0801c204
	adds r0, r4, #0
	bl FUN_0801c2bc
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	adds r0, r4, #0
	bl FUN_0801c910
	adds r0, r4, #0
	bl FUN_0801d084
	ldr r1, _0801E214 @ =FUN_0801c9e4
	adds r0, r4, #0
	bl FUN_0801b8d0
	bl FUN_08049f5c
	movs r0, #0
_0801E206:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801E210: .4byte 0x0000130C
_0801E214: .4byte FUN_0801c9e4

	thumb_func_start FUN_0801e218
FUN_0801e218: @ 0x0801E218
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _0801E254 @ =0x03000098
	ldr r0, [r0]
	cmp r0, #0
	bne _0801E266
	ldr r1, _0801E258 @ =0x00001364
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801E264
	ldr r1, _0801E25C @ =FUN_0801e028
	ldr r2, _0801E260 @ =FUN_0801e04c
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0801e080
	cmp r0, #0
	bge _0801E264
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801E266
	.align 2, 0
_0801E254: .4byte 0x03000098
_0801E258: .4byte 0x00001364
_0801E25C: .4byte FUN_0801e028
_0801E260: .4byte FUN_0801e04c
_0801E264:
	adds r0, r4, #0
_0801E266:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801e26c
FUN_0801e26c: @ 0x0801E26C
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #0x18]
	cmp r0, #1
	beq _0801E27A
	movs r0, #0
	b _0801E280
_0801E27A:
	movs r0, #0
	strb r0, [r1, #0x18]
	movs r0, #1
_0801E280:
	pop {r1}
	bx r1

	thumb_func_start FUN_0801e284
FUN_0801e284: @ 0x0801E284
	movs r2, #0
	strb r1, [r0, #0x19]
	str r2, [r0, #0x24]
	movs r1, #1
	strb r1, [r0, #0x18]
	bx lr

	thumb_func_start FUN_0801e290
FUN_0801e290: @ 0x0801E290
	push {lr}
	strb r1, [r0, #0x1c]
	strb r2, [r0, #0x1d]
	ldrb r1, [r0, #0x1e]
	adds r1, #1
	strb r1, [r0, #0x1e]
	movs r1, #0
	bl FUN_0801e284
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801e2a8
FUN_0801e2a8: @ 0x0801E2A8
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	str r1, [sp, #0xc]
	ldr r0, _0801E310 @ =0x0000C091
	ldr r1, _0801E314 @ =0x00009F57
	bl GetFile
	adds r2, r0, #0
	str r2, [r5, #0x28]
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	movs r0, #2
	movs r1, #2
	bl SetBGPrioDirect
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0801E318 @ =0x000092B3
	ldr r1, _0801E31C @ =0x0000A41A
	bl GetFile
	adds r1, r0, #0
	adds r0, #0x14
	str r0, [r5, #0x2c]
	movs r2, #0xda
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r1, _0801E320 @ =0x030043F0
	ldr r2, _0801E324 @ =0x04000018
	bl CpuSet
	movs r0, #0
	add sp, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801E310: .4byte 0x0000C091
_0801E314: .4byte 0x00009F57
_0801E318: .4byte 0x000092B3
_0801E31C: .4byte 0x0000A41A
_0801E320: .4byte 0x030043F0
_0801E324: .4byte 0x04000018

	thumb_func_start FUN_0801e328
FUN_0801e328: @ 0x0801E328
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _0801E370 @ =0x0000C091
	ldr r1, _0801E374 @ =0x0000A413
	bl GetFile
	adds r2, r0, #0
	str r2, [r4, #0x28]
	movs r0, #2
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	movs r0, #0x18
	rsbs r0, r0, #0
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #0
	add sp, #0x10
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801E370: .4byte 0x0000C091
_0801E374: .4byte 0x0000A413

	thumb_func_start FUN_0801e378
FUN_0801e378: @ 0x0801E378
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r6, #0x3a
	ldrb r1, [r6]
	lsls r5, r1, #2
	adds r5, #0x9c
	adds r5, r0, r5
	lsls r4, r1, #1
	adds r4, r4, r1
	lsls r4, r4, #5
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r4, r4, r1
	adds r4, r0, r4
	adds r1, r0, #0
	adds r1, #0xb0
	adds r0, #0x66
	ldrb r2, [r0]
	adds r2, #0x14
	adds r0, r4, #0
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	movs r1, #0
	movs r0, #1
	strh r0, [r5]
	strh r1, [r5, #2]
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _0801E3CA
	movs r0, #0
	strb r0, [r6]
_0801E3CA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801e3d0
FUN_0801e3d0: @ 0x0801E3D0
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r2, #0x9c
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r3, r0, r1
	movs r6, #0
	movs r5, #4
_0801E3E0:
	ldrh r0, [r2]
	cmp r0, #1
	beq _0801E3F4
	cmp r0, #1
	ble _0801E43E
	cmp r0, #2
	beq _0801E414
	cmp r0, #3
	beq _0801E428
	b _0801E43E
_0801E3F4:
	ldrh r0, [r2, #2]
	movs r1, #8
	subs r1, r1, r0
	lsls r1, r1, #3
	adds r1, #4
	movs r4, #0
	strh r1, [r3, #0x20]
	ldrh r0, [r2, #2]
	cmp r0, #7
	bls _0801E43E
	movs r0, #4
	strh r0, [r3, #0x20]
	movs r0, #2
	strh r0, [r2]
	strh r4, [r2, #2]
	b _0801E43E
_0801E414:
	ldrh r0, [r2, #2]
	cmp r0, #0x3f
	bls _0801E43E
	movs r0, #3
	strh r0, [r2]
	strh r6, [r2, #2]
	ldr r0, [r3, #8]
	movs r1, #0x80
	lsls r1, r1, #2
	b _0801E43A
_0801E428:
	ldrh r0, [r2, #2]
	cmp r0, #7
	bls _0801E43E
	strh r6, [r2]
	strh r6, [r2, #2]
	ldr r0, [r3, #8]
	ldr r1, _0801E454 @ =0xFFFFFDFF
	ands r0, r1
	movs r1, #1
_0801E43A:
	orrs r0, r1
	str r0, [r3, #8]
_0801E43E:
	ldrh r0, [r2, #2]
	adds r0, #1
	strh r0, [r2, #2]
	subs r5, #1
	adds r2, #4
	adds r3, #0x60
	cmp r5, #0
	bge _0801E3E0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801E454: .4byte 0xFFFFFDFF

	thumb_func_start FUN_0801e458
FUN_0801e458: @ 0x0801E458
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r6, r0, #0
	add r4, sp, #0x14
	movs r0, #0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r4, #0
	ldr r2, _0801E4AC @ =0x05000002
	bl CpuSet
	mov r8, r4
	movs r7, #0
	movs r0, #0xfc
	lsls r0, r0, #1
	adds r4, r6, r0
	movs r5, #0xc
_0801E47E:
	str r7, [sp]
	str r7, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r0, r8
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r1, #0xb0
	movs r2, #0
	movs r3, #0x11
	bl FUN_0822f3fc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0801E47E
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801E4AC: .4byte 0x05000002

	thumb_func_start FUN_0801e4b0
FUN_0801e4b0: @ 0x0801E4B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sl, r0
	movs r2, #0xea
	lsls r2, r2, #1
	add r2, sl
	mov r1, sl
	adds r1, #0x8c
	movs r0, #0xe1
	lsls r0, r0, #4
	str r0, [r1]
	ldrb r0, [r2, #5]
	mov r1, sl
	strh r0, [r1, #0x34]
	adds r1, r0, #0
	subs r1, #0x14
	mov r2, sl
	strh r1, [r2, #0x30]
	adds r0, #0x14
	strh r0, [r2, #0x32]
	cmp r1, #0
	bge _0801E4EA
	movs r0, #0
	strh r0, [r2, #0x30]
	b _0801E4F4
_0801E4EA:
	cmp r1, #0xb0
	ble _0801E4F4
	movs r0, #0xb0
	mov r1, sl
	strh r0, [r1, #0x30]
_0801E4F4:
	mov r2, sl
	movs r1, #0x32
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bge _0801E502
	movs r0, #0
	b _0801E50A
_0801E502:
	cmp r0, #0xb0
	ble _0801E50C
	movs r0, #0xb0
	mov r2, sl
_0801E50A:
	strh r0, [r2, #0x32]
_0801E50C:
	movs r1, #0
	mov r0, sl
	strh r1, [r0, #0x36]
	movs r7, #0xfc
	lsls r7, r7, #1
	add r7, sl
	strh r1, [r7, #0x20]
	mov r5, sl
	adds r5, #0xb0
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #4
	movs r3, #0
	bl Sprite_SetSprite
	movs r2, #2
	mov r8, r2
	mov r0, r8
	strb r0, [r7, #0x1a]
	ldr r0, [r7, #8]
	movs r4, #1
	orrs r0, r4
	str r0, [r7, #8]
	movs r7, #0x96
	lsls r7, r7, #2
	add r7, sl
	movs r1, #0
	strh r1, [r7, #0x20]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #3
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r7, #8]
	orrs r0, r4
	str r0, [r7, #8]
	mov r2, r8
	strb r2, [r7, #0x1a]
	movs r7, #0xae
	lsls r7, r7, #2
	add r7, sl
	mov r1, sl
	ldrh r0, [r1, #0x30]
	strh r0, [r7, #0x20]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #1
	movs r3, #0
	bl Sprite_SetSprite
	mov r2, r8
	strb r2, [r7, #0x1a]
	ldr r0, [r7, #8]
	orrs r0, r4
	str r0, [r7, #8]
	movs r7, #0xc6
	lsls r7, r7, #2
	add r7, sl
	mov r1, sl
	ldrh r0, [r1, #0x32]
	strh r0, [r7, #0x20]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #2
	movs r3, #0
	bl Sprite_SetSprite
	mov r2, r8
	strb r2, [r7, #0x1a]
	ldr r0, [r7, #8]
	orrs r0, r4
	str r0, [r7, #8]
	movs r7, #0xde
	lsls r7, r7, #2
	add r7, sl
	mov r1, sl
	ldrh r0, [r1, #0x34]
	strh r0, [r7, #0x20]
	movs r2, #6
	adds r0, r7, #0
	adds r1, r5, #0
	movs r3, #0
	bl Sprite_SetSprite
	mov r2, r8
	strb r2, [r7, #0x1a]
	ldr r0, [r7, #8]
	movs r6, #2
	rsbs r6, r6, #0
	ands r0, r6
	str r0, [r7, #8]
	movs r7, #0xf6
	lsls r7, r7, #2
	add r7, sl
	mov r1, sl
	ldrh r0, [r1, #0x36]
	subs r0, #0xb0
	strh r0, [r7, #0x20]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #9
	movs r3, #0
	bl Sprite_SetSprite
	movs r2, #3
	mov sb, r2
	mov r0, sb
	strb r0, [r7, #0x1a]
	ldr r0, [r7, #8]
	ands r0, r6
	str r0, [r7, #8]
	ldr r0, _0801E694 @ =0x03003584
	ldr r0, [r0]
	ldr r1, _0801E698 @ =0x000053E0
	adds r0, r0, r1
	movs r4, #0xe7
	lsls r4, r4, #3
	add r4, sl
	ldr r2, _0801E69C @ =0x04000008
	adds r1, r4, #0
	bl CpuSet
	movs r0, #0x81
	lsls r0, r0, #8
	strh r0, [r7, #0x3a]
	str r4, [r7, #0x48]
	movs r7, #0x87
	lsls r7, r7, #3
	add r7, sl
	movs r2, #0
	strh r2, [r7, #0x20]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #0xa
	movs r3, #0
	bl Sprite_SetSprite
	mov r0, sb
	strb r0, [r7, #0x1a]
	ldr r0, [r7, #8]
	ands r0, r6
	str r0, [r7, #8]
	movs r7, #0x93
	lsls r7, r7, #3
	add r7, sl
	movs r1, #0
	strh r1, [r7, #0x20]
	movs r2, #0
	str r2, [sp]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r3, #1
	bl FUN_082370cc
	mov r0, r8
	strb r0, [r7, #0x1a]
	ldr r0, [r7, #8]
	ands r0, r6
	str r0, [r7, #8]
	movs r7, #0x9f
	lsls r7, r7, #3
	add r7, sl
	movs r6, #0x20
	movs r1, #0
	mov r8, r1
	movs r4, #4
_0801E65A:
	movs r0, #8
	strh r0, [r7, #0x20]
	strh r6, [r7, #0x22]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #0x16
	movs r3, #0
	bl Sprite_SetSprite
	mov r2, r8
	strb r2, [r7, #0x1a]
	ldr r0, [r7, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #8]
	subs r4, #1
	adds r7, #0x60
	adds r6, #8
	cmp r4, #0
	bge _0801E65A
	movs r0, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801E694: .4byte 0x03003584
_0801E698: .4byte 0x000053E0
_0801E69C: .4byte 0x04000008

	thumb_func_start FUN_0801e6a0
FUN_0801e6a0: @ 0x0801E6A0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _0801E6FC @ =0x03003584
	ldr r5, [r0]
	ldr r0, _0801E700 @ =0x000053E0
	adds r5, r5, r0
	ldr r0, [r6, #0x60]
	lsls r0, r0, #5
	movs r1, #5
	bl Div
	movs r2, #0x20
	subs r2, r2, r0
	lsls r4, r2, #5
	subs r4, r4, r2
	ldrh r3, [r5, #0x1e]
	movs r5, #0x1f
	movs r1, #0x1f
	ands r1, r3
	muls r1, r0, r1
	adds r4, r4, r1
	asrs r4, r4, #5
	lsls r2, r2, #2
	lsls r3, r3, #0x10
	lsrs r1, r3, #0x15
	ands r1, r5
	muls r1, r0, r1
	adds r2, r2, r1
	asrs r2, r2, #5
	lsrs r3, r3, #0x1a
	ands r3, r5
	muls r0, r3, r0
	asrs r0, r0, #5
	ands r4, r5
	ands r2, r5
	lsls r2, r2, #5
	adds r4, r4, r2
	ands r0, r5
	lsls r0, r0, #0xa
	adds r4, r4, r0
	ldr r0, _0801E704 @ =0x00000756
	adds r6, r6, r0
	strh r4, [r6]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801E6FC: .4byte 0x03003584
_0801E700: .4byte 0x000053E0
_0801E704: .4byte 0x00000756

	thumb_func_start FUN_0801e708
FUN_0801e708: @ 0x0801E708
	push {lr}
	movs r3, #1
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #0xc
_0801E714:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0801E714
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801e728
FUN_0801e728: @ 0x0801E728
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	movs r0, #0xf6
	lsls r0, r0, #2
	adds r2, r7, r0
	ldrh r0, [r7, #0x36]
	subs r0, #0xb0
	movs r3, #0
	strh r0, [r2, #0x20]
	movs r1, #0x93
	lsls r1, r1, #3
	adds r2, r7, r1
	movs r4, #0x36
	ldrsh r1, [r7, r4]
	movs r4, #0x30
	ldrsh r0, [r7, r4]
	cmp r1, r0
	bge _0801E770
	adds r1, r7, #0
	adds r1, #0x38
	ldrb r0, [r1]
	adds r6, r7, #0
	adds r6, #0xb0
	cmp r0, #1
	beq _0801E7BA
	movs r0, #1
	strb r0, [r1]
	str r3, [sp]
	adds r0, r2, #0
	adds r1, r6, #0
	movs r2, #0
	b _0801E792
_0801E770:
	movs r4, #0x32
	ldrsh r0, [r7, r4]
	cmp r1, r0
	bge _0801E79A
	adds r1, r7, #0
	adds r1, #0x38
	ldrb r0, [r1]
	adds r6, r7, #0
	adds r6, #0xb0
	cmp r0, #2
	beq _0801E7BA
	movs r0, #2
	strb r0, [r1]
	str r3, [sp]
	adds r0, r2, #0
	adds r1, r6, #0
	movs r2, #1
_0801E792:
	movs r3, #1
	bl FUN_082370cc
	b _0801E7BA
_0801E79A:
	adds r1, r7, #0
	adds r1, #0x38
	ldrb r0, [r1]
	adds r6, r7, #0
	adds r6, #0xb0
	cmp r0, #3
	beq _0801E7BA
	movs r0, #3
	strb r0, [r1]
	str r3, [sp]
	adds r0, r2, #0
	adds r1, r6, #0
	movs r2, #2
	movs r3, #1
	bl FUN_082370cc
_0801E7BA:
	movs r0, #0x20
	adds r0, r0, r7
	mov r8, r0
	movs r1, #0xfc
	lsls r1, r1, #1
	adds r4, r7, r1
	movs r5, #0xc
_0801E7C8:
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_082372cc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0801E7C8
	movs r5, #0xd
	mov r0, r8
	ldrb r4, [r0]
	cmp r4, #0
	beq _0801E806
	movs r0, #0
	mov r1, r8
	strb r0, [r1]
	subs r5, #0x10
	movs r6, #0
	movs r4, #0xf
_0801E7EE:
	adds r1, r5, #6
	str r6, [sp]
	str r4, [sp, #4]
	movs r0, #2
	movs r2, #0x10
	movs r3, #1
	bl FUN_0822bcf4
	adds r5, #1
	cmp r5, #0xa
	ble _0801E7EE
	b _0801E888
_0801E806:
	str r4, [sp]
	str r5, [sp, #4]
	movs r0, #2
	movs r1, #3
	movs r2, #0x10
	movs r3, #2
	bl FUN_0822bcf4
	str r4, [sp]
	str r5, [sp, #4]
	movs r0, #2
	movs r1, #4
	movs r2, #0x10
	movs r3, #3
	bl FUN_0822bcf4
	str r4, [sp]
	str r5, [sp, #4]
	movs r0, #2
	movs r1, #5
	movs r2, #0x10
	movs r3, #4
	bl FUN_0822bcf4
	movs r5, #0
	b _0801E850
_0801E83A:
	adds r1, r5, #6
	movs r0, #0
	str r0, [sp]
	movs r0, #0xd
	str r0, [sp, #4]
	movs r0, #2
	movs r2, #0x10
	movs r3, #5
	bl FUN_0822bcf4
	adds r5, #1
_0801E850:
	ldr r0, [r7, #0x40]
	cmp r5, r0
	blo _0801E83A
	cmp r5, #9
	bgt _0801E874
	movs r6, #0
	movs r4, #0xd
_0801E85E:
	adds r1, r5, #6
	str r6, [sp]
	str r4, [sp, #4]
	movs r0, #2
	movs r2, #0x10
	movs r3, #6
	bl FUN_0822bcf4
	adds r5, #1
	cmp r5, #9
	ble _0801E85E
_0801E874:
	movs r0, #0
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x10
	movs r3, #7
	bl FUN_0822bcf4
_0801E888:
	ldrb r4, [r7, #0x1f]
	mov sb, r4
	cmp r4, #0
	beq _0801E8E8
	movs r4, #0
	strb r4, [r7, #0x1f]
	str r4, [sp]
	movs r5, #0xf
	str r5, [sp, #4]
	movs r0, #2
	movs r1, #0x15
	movs r2, #0x10
	movs r3, #1
	bl FUN_0822bcf4
	str r4, [sp]
	str r5, [sp, #4]
	movs r0, #2
	movs r1, #0x16
	movs r2, #0x10
	movs r3, #1
	bl FUN_0822bcf4
	str r4, [sp]
	str r5, [sp, #4]
	movs r0, #2
	movs r1, #0x17
	movs r2, #0x10
	movs r3, #1
	bl FUN_0822bcf4
	str r4, [sp]
	str r5, [sp, #4]
	movs r0, #2
	movs r1, #0x18
	movs r2, #0x10
	movs r3, #1
	bl FUN_0822bcf4
	str r4, [sp]
	str r5, [sp, #4]
	movs r0, #2
	movs r1, #0x19
	movs r2, #0x10
	movs r3, #1
	bl FUN_0822bcf4
	b _0801E944
_0801E8E8:
	adds r4, r7, #0
	adds r4, #0x8c
	ldr r0, [r4]
	movs r1, #0x3c
	bl Mod
	movs r1, #0x64
	muls r0, r1, r0
	movs r1, #0x3c
	bl Div
	mov r8, r0
	ldr r0, [r4]
	movs r1, #0x3c
	bl Div
	adds r3, r0, #0
	movs r6, #0x11
	str r6, [sp]
	movs r5, #2
	str r5, [sp, #4]
	movs r4, #0xd
	str r4, [sp, #8]
	movs r0, #2
	movs r1, #0x15
	movs r2, #0x10
	bl FUN_0822be3c
	mov r0, sb
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #2
	movs r1, #0x17
	movs r2, #0x10
	movs r3, #0x1b
	bl FUN_0822bcf4
	str r6, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	movs r0, #2
	movs r1, #0x18
	movs r2, #0x10
	mov r3, r8
	bl FUN_0822be3c
_0801E944:
	adds r0, r7, #0
	bl FUN_0801e6a0
	adds r0, r7, #0
	bl FUN_0801e3d0
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801e960
FUN_0801e960: @ 0x0801E960
	push {r4, r5, lr}
	movs r1, #0xfc
	lsls r1, r1, #1
	adds r4, r0, r1
	movs r5, #0xc
_0801E96A:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0801E96A
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801e980
FUN_0801e980: @ 0x0801E980
	movs r1, #0xfc
	lsls r1, r1, #1
	adds r2, r0, r1
	adds r0, #0x67
	ldrb r0, [r0]
	strh r0, [r2, #0x20]
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	bx lr

	thumb_func_start FUN_0801e998
FUN_0801e998: @ 0x0801E998
	movs r1, #0xfc
	lsls r1, r1, #1
	adds r2, r0, r1
	adds r0, #0x67
	ldrb r0, [r0]
	strh r0, [r2, #0x20]
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0801e9b0
FUN_0801e9b0: @ 0x0801E9B0
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, [r3, #0x54]
	asrs r4, r0, #5
	movs r0, #0xae
	lsls r0, r0, #2
	adds r2, r3, r0
	adds r0, r4, #0
	subs r0, #0x18
	strh r0, [r2, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _0801E9D0
	movs r0, #0
	b _0801E9D6
_0801E9D0:
	cmp r0, #0xb0
	ble _0801E9D8
	movs r0, #0xb0
_0801E9D6:
	strh r0, [r2, #0x20]
_0801E9D8:
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	movs r0, #0xc6
	lsls r0, r0, #2
	adds r2, r3, r0
	adds r0, r4, #0
	adds r0, #0x18
	strh r0, [r2, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _0801E9FA
	movs r0, #0
	b _0801EA00
_0801E9FA:
	cmp r0, #0xb0
	ble _0801EA02
	movs r0, #0xb0
_0801EA00:
	strh r0, [r2, #0x20]
_0801EA02:
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801ea14
FUN_0801ea14: @ 0x0801EA14
	adds r3, r0, #0
	movs r0, #0xae
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	movs r0, #0xc6
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2, #8]
	orrs r0, r1
	str r0, [r2, #8]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0801ea34
FUN_0801ea34: @ 0x0801EA34
	push {lr}
	adds r2, r0, #0
	movs r3, #0
	ldr r0, [r2, #0x5c]
	cmp r0, #0
	beq _0801EA60
	ldr r0, [r2, #0x40]
	adds r0, #2
	lsls r0, r0, #2
	ldr r1, [r2, #0x50]
	adds r1, r1, r0
	str r1, [r2, #0x50]
	ldr r0, _0801EA5C @ =0x000002FF
	cmp r1, r0
	ble _0801EA78
	adds r0, #1
	str r0, [r2, #0x50]
	str r3, [r2, #0x5c]
	b _0801EA78
	.align 2, 0
_0801EA5C: .4byte 0x000002FF
_0801EA60:
	ldr r0, [r2, #0x40]
	adds r0, #2
	lsls r0, r0, #2
	ldr r1, [r2, #0x50]
	subs r1, r1, r0
	str r1, [r2, #0x50]
	ldr r0, _0801EA88 @ =0xFFFFFD00
	cmp r1, r0
	bgt _0801EA78
	str r0, [r2, #0x50]
	movs r0, #1
	str r0, [r2, #0x5c]
_0801EA78:
	ldr r1, [r2, #0x54]
	ldr r0, [r2, #0x50]
	adds r1, r1, r0
	str r1, [r2, #0x58]
	cmp r1, #0
	bge _0801EA8C
	movs r0, #0
	b _0801EA94
	.align 2, 0
_0801EA88: .4byte 0xFFFFFD00
_0801EA8C:
	movs r0, #0xb0
	lsls r0, r0, #5
	cmp r1, r0
	ble _0801EA96
_0801EA94:
	str r0, [r2, #0x58]
_0801EA96:
	movs r1, #0x34
	ldrsh r0, [r2, r1]
	lsls r0, r0, #5
	ldr r1, [r2, #0x58]
	cmp r1, r0
	bne _0801EAA4
	movs r3, #1
_0801EAA4:
	adds r0, r3, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801eaac
FUN_0801eaac: @ 0x0801EAAC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r1, #0
	movs r0, #0x34
	ldrsh r1, [r4, r0]
	movs r2, #0x36
	ldrsh r0, [r4, r2]
	subs r5, r1, r0
	cmp r5, #0
	bge _0801EAC2
	rsbs r5, r5, #0
_0801EAC2:
	ldrh r0, [r4, #0x36]
	adds r1, r4, #0
	adds r1, #0x67
	movs r6, #0
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_0801e980
	movs r0, #0x36
	ldrsh r1, [r4, r0]
	movs r2, #0x30
	ldrsh r0, [r4, r2]
	cmp r1, r0
	blt _0801EB32
	movs r2, #0x32
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bgt _0801EB32
	cmp r5, #1
	bgt _0801EB0A
	adds r2, r4, #0
	adds r2, #0x39
	movs r0, #1
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x80
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, [r4, #0x7c]
	adds r0, #0x64
	str r0, [r4, #0x7c]
	adds r0, r4, #0
	adds r0, #0x66
	strb r6, [r0]
	b _0801EB48
_0801EB0A:
	adds r0, r4, #0
	adds r0, #0x39
	strb r6, [r0]
	adds r2, r0, #0
	cmp r5, #0x63
	bgt _0801EB1E
	ldr r0, [r4, #0x7c]
	adds r0, #0x64
	subs r0, r0, r5
	str r0, [r4, #0x7c]
_0801EB1E:
	adds r0, r4, #0
	adds r0, #0x84
	ldr r1, [r0]
	adds r1, #1
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0x66
	movs r0, #1
	strb r0, [r1]
	b _0801EB48
_0801EB32:
	adds r0, r4, #0
	adds r0, #0x88
	ldr r1, [r0]
	adds r1, #1
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0x66
	movs r0, #2
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x39
_0801EB48:
	ldrb r0, [r2]
	adds r1, r7, #0
	bl FUN_0801c0d8
	adds r0, r4, #0
	bl FUN_0801e378
	ldr r0, [r4, #0x60]
	adds r0, #1
	str r0, [r4, #0x60]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801eb64
FUN_0801eb64: @ 0x0801EB64
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801EB7E
	ldrb r0, [r4, #0x1e]
	bl FUN_08047a28
	adds r1, r4, #0
	adds r1, #0x22
	movs r0, #0
	strb r0, [r1]
_0801EB7E:
	ldrb r0, [r4, #0x1c]
	cmp r0, #0
	beq _0801EB9C
	ldr r1, [r4, #0x24]
	cmp r1, #0xf
	bhi _0801EB9C
	lsrs r1, r1, #1
	movs r0, #8
	subs r3, r0, r1
	adds r2, r1, #0
	adds r2, #8
	movs r0, #0
	adds r1, r3, #0
	bl FUN_0822f178
_0801EB9C:
	ldr r0, [r4, #0x24]
	adds r5, r4, #0
	adds r5, #0x22
	cmp r0, #0x1f
	bls _0801EBD8
	ldrb r0, [r5]
	cmp r0, #0
	bne _0801EBDE
	ldr r0, _0801EBF8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0801EBD8
	adds r1, r4, #0
	adds r1, #0x21
	movs r0, #0x10
	strb r0, [r1]
	movs r0, #1
	strb r0, [r5]
	ldr r0, _0801EBFC @ =0x00000107
	bl PlaySound_082406e0
	movs r0, #0xdb
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, [r1, #8]
	orrs r0, r6
	str r0, [r1, #8]
_0801EBD8:
	ldrb r0, [r5]
	cmp r0, #0
	beq _0801EC20
_0801EBDE:
	adds r1, r4, #0
	adds r1, #0x21
	ldrb r0, [r1]
	cmp r0, #0
	bne _0801EC00
	ldrb r0, [r4, #0x1b]
	adds r0, #1
	strb r0, [r4, #0x1b]
	ldrb r1, [r4, #0x1b]
	adds r0, r4, #0
	bl FUN_0801e284
	b _0801EC46
	.align 2, 0
_0801EBF8: .4byte 0x030044E0
_0801EBFC: .4byte 0x00000107
_0801EC00:
	subs r0, #1
	strb r0, [r1]
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _0801EC46
	ldrb r0, [r1]
	movs r1, #0x10
	subs r3, r1, r0
	lsrs r0, r0, #1
	adds r2, r0, #0
	adds r2, #8
	movs r0, #0
	adds r1, r3, #0
	bl FUN_0822f178
	b _0801EC46
_0801EC20:
	ldr r0, [r4, #0x24]
	cmp r0, #0x20
	bne _0801EC36
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0, #8]
_0801EC36:
	movs r2, #0xdb
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r2, #0x88
	lsls r2, r2, #1
	adds r1, r4, r2
	bl FUN_082372cc
_0801EC46:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801ec4c
FUN_0801ec4c: @ 0x0801EC4C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0801e26c
	ldr r0, [r4, #0x24]
	cmp r0, #0x3b
	bls _0801EC64
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	bl FUN_0801e290
_0801EC64:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801ec6c
FUN_0801ec6c: @ 0x0801EC6C
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801EC82
	movs r1, #0
	movs r0, #0
	strh r0, [r4, #0x36]
	strb r1, [r4, #0x1a]
	str r0, [r4, #0x6c]
_0801EC82:
	ldrb r5, [r4, #0x1a]
	cmp r5, #0
	beq _0801EC8E
	cmp r5, #1
	beq _0801ECC0
	b _0801ED0C
_0801EC8E:
	ldr r0, [r4, #0x24]
	movs r2, #0x1f
	ands r0, r2
	cmp r0, #0xf
	bhi _0801ECA0
	adds r1, r4, #0
	adds r1, #0x20
	movs r0, #1
	strb r0, [r1]
_0801ECA0:
	ldr r0, [r4, #0x24]
	ands r0, r2
	cmp r0, #0x10
	bne _0801ECB0
	movs r0, #0xac
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0801ECB0:
	ldr r0, [r4, #0x6c]
	cmp r0, #0x59
	bls _0801ED0C
	ldrb r0, [r4, #0x1a]
	adds r0, #1
	strb r0, [r4, #0x1a]
	str r5, [r4, #0x6c]
	b _0801ED0C
_0801ECC0:
	ldr r0, [r4, #0x24]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _0801ECD4
	ldr r0, [r4, #0x40]
	cmp r0, #9
	bhi _0801ECD4
	adds r0, #1
	str r0, [r4, #0x40]
_0801ECD4:
	ldr r0, [r4, #0x40]
	cmp r0, #0
	beq _0801ECF0
	lsls r0, r0, #3
	ldr r1, [r4, #0x58]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, _0801ECEC @ =0x000015FF
	cmp r1, r0
	ble _0801ECFC
	adds r0, #1
	b _0801ECFA
	.align 2, 0
_0801ECEC: .4byte 0x000015FF
_0801ECF0:
	ldr r1, [r4, #0x58]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #6
_0801ECFA:
	str r0, [r4, #0x58]
_0801ECFC:
	ldr r0, [r4, #0x6c]
	cmp r0, #0x8b
	bls _0801ED0C
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	bl FUN_0801e290
_0801ED0C:
	ldr r0, [r4, #0x6c]
	adds r0, #1
	str r0, [r4, #0x6c]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801ed18
FUN_0801ed18: @ 0x0801ED18
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801ED28
	movs r0, #0xb0
	strh r0, [r4, #0x36]
_0801ED28:
	ldr r1, [r4, #0x24]
	movs r0, #7
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	bne _0801ED3E
	ldr r0, [r4, #0x40]
	cmp r0, #0
	beq _0801ED5C
	subs r0, #1
	str r0, [r4, #0x40]
_0801ED3E:
	ldr r0, [r4, #0x40]
	cmp r0, #0
	beq _0801ED5C
	lsls r0, r0, #3
	ldr r1, [r4, #0x58]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, _0801ED58 @ =0x000015FF
	cmp r1, r0
	ble _0801ED68
	adds r0, #1
	b _0801ED66
	.align 2, 0
_0801ED58: .4byte 0x000015FF
_0801ED5C:
	ldr r1, [r4, #0x58]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #6
_0801ED66:
	str r0, [r4, #0x58]
_0801ED68:
	cmp r2, #0x8b
	bls _0801ED76
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	bl FUN_0801e290
_0801ED76:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801ed7c
FUN_0801ed7c: @ 0x0801ED7C
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801ED9A
	movs r0, #0
	strh r0, [r4, #0x36]
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #0x3c
	strb r0, [r1]
	adds r1, #1
	movs r0, #3
	strb r0, [r1]
_0801ED9A:
	ldr r0, [r4, #0x24]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _0801EDAE
	ldr r0, [r4, #0x40]
	cmp r0, #3
	bhi _0801EDAE
	adds r0, #1
	str r0, [r4, #0x40]
_0801EDAE:
	movs r0, #0x36
	ldrsh r1, [r4, r0]
	movs r2, #0x34
	ldrsh r0, [r4, r2]
	subs r0, #0x28
	cmp r1, r0
	bge _0801EDF2
	ldr r0, [r4, #0x40]
	cmp r0, #0
	beq _0801EDE0
	lsls r0, r0, #3
	ldr r1, [r4, #0x58]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, _0801EDDC @ =0x000015FF
	adds r5, r4, #0
	adds r5, #0x6a
	cmp r1, r0
	ble _0801EE4E
	adds r0, #1
	str r0, [r4, #0x58]
	b _0801EE4E
	.align 2, 0
_0801EDDC: .4byte 0x000015FF
_0801EDE0:
	ldr r1, [r4, #0x58]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #6
	str r0, [r4, #0x58]
	adds r5, r4, #0
	adds r5, #0x6a
	b _0801EE4E
_0801EDF2:
	lsls r0, r0, #5
	str r0, [r4, #0x58]
	adds r1, r4, #0
	adds r1, #0x6a
	ldrb r0, [r1]
	adds r5, r1, #0
	cmp r0, #0
	beq _0801EE54
	adds r3, r4, #0
	adds r3, #0x69
	ldrb r0, [r3]
	cmp r0, #0
	beq _0801EE4E
	subs r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xa
	bne _0801EE28
	movs r1, #0xf6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
	b _0801EE4E
_0801EE28:
	cmp r0, #0
	bne _0801EE4E
	movs r0, #0xf6
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	movs r0, #0x1e
	strb r0, [r3]
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	movs r0, #0xac
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0801EE4E:
	ldrb r0, [r5]
	cmp r0, #0
	bne _0801EE64
_0801EE54:
	ldr r0, [r4, #0x24]
	cmp r0, #0xef
	bls _0801EE64
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	bl FUN_0801e290
_0801EE64:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801ee6c
FUN_0801ee6c: @ 0x0801EE6C
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801EE86
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #0x3c
	strb r0, [r1]
	adds r1, #1
	movs r0, #3
	strb r0, [r1]
_0801EE86:
	adds r0, r4, #0
	adds r0, #0x6a
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	beq _0801EEE4
	adds r3, r4, #0
	adds r3, #0x69
	ldrb r0, [r3]
	cmp r0, #0
	beq _0801EEDE
	subs r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xa
	bne _0801EEB8
	movs r1, #0xde
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
	b _0801EEDE
_0801EEB8:
	cmp r0, #0
	bne _0801EEDE
	movs r0, #0xde
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	movs r0, #0x1e
	strb r0, [r3]
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	movs r0, #0xac
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0801EEDE:
	ldrb r0, [r5]
	cmp r0, #0
	bne _0801EEF4
_0801EEE4:
	ldr r0, [r4, #0x24]
	cmp r0, #0xef
	bls _0801EEF4
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	bl FUN_0801e290
_0801EEF4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801eefc
FUN_0801eefc: @ 0x0801EEFC
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r5, r4, r0
	adds r0, r4, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801EF32
	movs r2, #0
	movs r3, #0
	movs r0, #0x81
	strh r0, [r5, #0x18]
	movs r0, #0x78
	strh r0, [r5, #0x1a]
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	strb r2, [r4, #0x1a]
	str r3, [r4, #0x6c]
	adds r1, r4, #0
	adds r1, #0x6a
	movs r0, #3
	strb r0, [r1]
_0801EF32:
	ldrb r0, [r4, #0x1a]
	cmp r0, #3
	bhi _0801EF84
	adds r0, r4, #0
	adds r0, #0x6a
	ldrb r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	beq _0801EF7A
	ldr r0, [r4, #0x24]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0xf
	bhi _0801EF56
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	b _0801EF5E
_0801EF56:
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_0801EF5E:
	str r0, [r5]
	ldr r0, [r4, #0x6c]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0x10
	bne _0801EF84
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	movs r0, #0xac
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _0801EF84
_0801EF7A:
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
_0801EF84:
	ldrb r0, [r4, #0x1a]
	cmp r0, #4
	bhi _0801F048
	lsls r0, r0, #2
	ldr r1, _0801EF94 @ =_0801EF98
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801EF94: .4byte _0801EF98
_0801EF98: @ jump table
	.4byte _0801EFAC @ case 0
	.4byte _0801EFB4 @ case 1
	.4byte _0801EFF8 @ case 2
	.4byte _0801F000 @ case 3
	.4byte _0801F02E @ case 4
_0801EFAC:
	ldr r0, [r4, #0x6c]
	cmp r0, #0x78
	bls _0801F048
	b _0801F03E
_0801EFB4:
	movs r2, #0x36
	ldrsh r1, [r4, r2]
	movs r2, #0x34
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bge _0801EFEE
	ldr r0, [r4, #0x40]
	cmp r0, #0
	beq _0801EFE0
	lsls r0, r0, #3
	ldr r1, [r4, #0x58]
	adds r1, r1, r0
	str r1, [r4, #0x58]
	ldr r0, _0801EFDC @ =0x000015FF
	cmp r1, r0
	ble _0801F048
	adds r0, #1
	str r0, [r4, #0x58]
	b _0801F048
	.align 2, 0
_0801EFDC: .4byte 0x000015FF
_0801EFE0:
	ldr r1, [r4, #0x58]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #6
	str r0, [r4, #0x58]
	b _0801F048
_0801EFEE:
	movs r1, #0x34
	ldrsh r0, [r4, r1]
	lsls r0, r0, #5
	str r0, [r4, #0x58]
	b _0801F03E
_0801EFF8:
	ldr r0, [r4, #0x6c]
	cmp r0, #0x3c
	bls _0801F048
	b _0801F03E
_0801F000:
	ldr r0, [r4, #0x6c]
	cmp r0, #8
	bls _0801F048
	movs r0, #0x96
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r4, #0x1a]
	adds r0, #1
	movs r1, #0
	strb r0, [r4, #0x1a]
	str r1, [r4, #0x6c]
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	ldr r0, [r4, #0x58]
	str r0, [r4, #0x54]
	asrs r0, r0, #5
	strh r0, [r2, #0x20]
	adds r0, r4, #0
	bl FUN_0801e9b0
	b _0801F048
_0801F02E:
	ldr r0, [r4, #0x6c]
	cmp r0, #0x3c
	bls _0801F048
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	bl FUN_0801e290
_0801F03E:
	ldrb r0, [r4, #0x1a]
	adds r0, #1
	movs r1, #0
	strb r0, [r4, #0x1a]
	str r1, [r4, #0x6c]
_0801F048:
	ldr r0, [r4, #0x6c]
	adds r0, #1
	str r0, [r4, #0x6c]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801f054
FUN_0801f054: @ 0x0801F054
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801F076
	movs r1, #0
	str r1, [r4, #0x5c]
	str r1, [r4, #0x50]
	str r1, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x64
	strb r1, [r0]
	subs r0, #0x2a
	strb r1, [r0]
	adds r0, #0x31
	strb r1, [r0]
_0801F076:
	adds r0, r4, #0
	bl FUN_0801ea34
	cmp r0, #0
	beq _0801F09C
	adds r1, r4, #0
	adds r1, #0x6b
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _0801F09C
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	bl FUN_0801e290
_0801F09C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801f0a4
FUN_0801f0a4: @ 0x0801F0A4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801F0B8
	adds r1, r4, #0
	adds r1, #0x6b
	movs r0, #0
	strb r0, [r1]
_0801F0B8:
	adds r0, r4, #0
	bl FUN_0801ea34
	cmp r0, #0
	beq _0801F0DE
	adds r1, r4, #0
	adds r1, #0x6b
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _0801F0DE
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	bl FUN_0801e290
_0801F0DE:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801f0e4
FUN_0801f0e4: @ 0x0801F0E4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801F10E
	adds r2, r4, #0
	adds r2, #0x69
	movs r0, #0
	movs r1, #0x3c
	strb r1, [r2]
	adds r2, #1
	movs r1, #3
	strb r1, [r2]
	adds r1, r4, #0
	adds r1, #0x6b
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0801eaac
_0801F10E:
	ldr r0, [r4, #0x6c]
	cmp r0, #0x3c
	bne _0801F11E
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	bl FUN_0801e290
_0801F11E:
	adds r0, r4, #0
	bl FUN_0801ea34
	ldr r0, [r4, #0x6c]
	adds r0, #1
	str r0, [r4, #0x6c]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801f130
FUN_0801f130: @ 0x0801F130
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801F14A
	movs r0, #0
	strb r0, [r4, #0x1a]
	str r0, [r4, #0x6c]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0801eaac
_0801F14A:
	ldrb r5, [r4, #0x1a]
	cmp r5, #1
	beq _0801F17C
	cmp r5, #1
	bgt _0801F15A
	cmp r5, #0
	beq _0801F164
	b _0801F1C0
_0801F15A:
	cmp r5, #2
	beq _0801F188
	cmp r5, #3
	beq _0801F1A8
	b _0801F1C0
_0801F164:
	ldr r0, [r4, #0x6c]
	cmp r0, #0x28
	bne _0801F1C0
	adds r0, r4, #0
	movs r1, #2
	bl FUN_0801eaac
	ldrb r0, [r4, #0x1a]
	adds r0, #1
	strb r0, [r4, #0x1a]
	str r5, [r4, #0x6c]
	b _0801F1C0
_0801F17C:
	ldr r0, [r4, #0x6c]
	cmp r0, #0x28
	bne _0801F1C0
	adds r0, r4, #0
	movs r1, #1
	b _0801F198
_0801F188:
	movs r0, #0x36
	ldrsh r1, [r4, r0]
	movs r2, #0x34
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _0801F1C0
	adds r0, r4, #0
	movs r1, #0
_0801F198:
	bl FUN_0801eaac
	ldrb r0, [r4, #0x1a]
	adds r0, #1
	movs r1, #0
	strb r0, [r4, #0x1a]
	str r1, [r4, #0x6c]
	b _0801F1C0
_0801F1A8:
	ldr r0, [r4, #0x6c]
	cmp r0, #0x14
	bne _0801F1C0
	movs r0, #4
	movs r1, #0
	strb r0, [r4, #0x1a]
	str r1, [r4, #0x6c]
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	bl FUN_0801e290
_0801F1C0:
	adds r0, r4, #0
	bl FUN_0801ea34
	ldr r0, [r4, #0x6c]
	adds r0, #1
	str r0, [r4, #0x6c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801f1d4
FUN_0801f1d4: @ 0x0801F1D4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801F1EC
	adds r0, r4, #0
	bl FUN_0801ea14
	adds r0, r4, #0
	bl FUN_0801e998
_0801F1EC:
	ldr r0, [r4, #0x58]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	asrs r1, r1, #5
	str r1, [r4, #0x58]
	ldr r0, [r4, #0x6c]
	cmp r0, #0x78
	bne _0801F208
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	bl FUN_0801e290
_0801F208:
	ldr r0, [r4, #0x6c]
	adds r0, #1
	str r0, [r4, #0x6c]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801f214
FUN_0801f214: @ 0x0801F214
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801F228
	movs r0, #0
	strb r0, [r5, #0x1a]
	str r0, [r5, #0x6c]
_0801F228:
	ldrb r0, [r5, #0x1a]
	cmp r0, #0
	beq _0801F234
	cmp r0, #1
	beq _0801F284
	b _0801F2E2
_0801F234:
	ldr r0, [r5, #0x6c]
	cmp r0, #0x59
	bhi _0801F256
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0xf
	bhi _0801F246
	movs r0, #1
	strb r0, [r5, #0x1f]
_0801F246:
	ldr r0, [r5, #0x6c]
	ands r0, r1
	cmp r0, #0x10
	bne _0801F256
	movs r0, #0xac
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0801F256:
	ldr r0, [r5, #0x6c]
	cmp r0, #0x78
	bne _0801F2E2
	ldrb r0, [r5, #0x1a]
	adds r0, #1
	movs r1, #0
	strb r0, [r5, #0x1a]
	str r1, [r5, #0x6c]
	movs r0, #4
	str r0, [sp]
	ldr r0, _0801F280 @ =0x0000FFFF
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	b _0801F2E2
	.align 2, 0
_0801F280: .4byte 0x0000FFFF
_0801F284:
	ldr r0, [r5, #0x6c]
	cmp r0, #0x20
	bne _0801F2E2
	movs r0, #2
	movs r4, #0
	strb r0, [r5, #0x1a]
	str r4, [r5, #0x6c]
	subs r0, #0x62
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r2, _0801F2F0 @ =0x03003E78
	ldr r0, _0801F2F4 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	ldr r1, _0801F2F8 @ =0xFFFFFBFF
	ands r0, r1
	ldr r1, _0801F2FC @ =0xFFFFF7FF
	ands r0, r1
	strh r0, [r2]
	adds r0, r5, #0
	bl FUN_0801e708
	movs r0, #4
	str r0, [sp]
	ldr r0, _0801F300 @ =0x0000FFFF
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #2
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0
	bl FUN_0801e290
	ldr r0, _0801F304 @ =0x000006FA
	adds r1, r5, r0
	movs r0, #0x8c
	strh r0, [r1]
_0801F2E2:
	ldr r0, [r5, #0x6c]
	adds r0, #1
	str r0, [r5, #0x6c]
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801F2F0: .4byte 0x03003E78
_0801F2F4: .4byte 0xFFFFFDFF
_0801F2F8: .4byte 0xFFFFFBFF
_0801F2FC: .4byte 0xFFFFF7FF
_0801F300: .4byte 0x0000FFFF
_0801F304: .4byte 0x000006FA

	thumb_func_start FUN_0801f308
FUN_0801f308: @ 0x0801F308
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0801e26c
	ldr r0, [r4, #0x24]
	cmp r0, #0x3f
	bls _0801F320
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0801e290
_0801F320:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801f328
FUN_0801f328: @ 0x0801F328
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801F354
	movs r0, #4
	str r0, [sp]
	ldr r0, _0801F380 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r0, #5
	bl FUN_082403d0
_0801F354:
	ldr r0, [r4, #0x24]
	cmp r0, #0x1f
	bls _0801F378
	adds r4, #0x90
	ldr r3, [r4]
	cmp r3, #0
	beq _0801F378
	ldr r2, _0801F384 @ =0x03003E78
	ldr r0, _0801F388 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r3, #0
	movs r1, #0
	bl Script_ExecById
	movs r0, #0
	str r0, [r4]
_0801F378:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801F380: .4byte 0x0000FFFF
_0801F384: .4byte 0x03003E78
_0801F388: .4byte 0xFFFFFEFF

	thumb_func_start FUN_0801f38c
FUN_0801f38c: @ 0x0801F38C
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	bl FUN_0801e26c
	cmp r0, #0
	beq _0801F3C6
	movs r0, #0xdb
	lsls r0, r0, #3
	adds r2, r5, r0
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	movs r0, #4
	str r0, [sp]
	ldr r0, _0801F408 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r0, #5
	bl FUN_082403d0
_0801F3C6:
	ldr r0, [r5, #0x24]
	cmp r0, #0x1f
	bls _0801F3FE
	adds r4, r5, #0
	adds r4, #0x90
	ldr r0, [r4]
	cmp r0, #0
	beq _0801F3FE
	ldr r2, _0801F40C @ =0x03003E78
	ldr r0, _0801F410 @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
	ldr r1, _0801F414 @ =0xFFFFFBFF
	ands r0, r1
	ldr r1, _0801F418 @ =0xFFFFFDFF
	ands r0, r1
	ldr r1, _0801F41C @ =0xFFFFFEFF
	ands r0, r1
	strh r0, [r2]
	adds r0, r5, #0
	bl FUN_0801e708
	ldr r0, [r4]
	movs r1, #0
	bl Script_ExecById
	movs r0, #0
	str r0, [r4]
_0801F3FE:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801F408: .4byte 0x0000FFFF
_0801F40C: .4byte 0x03003E78
_0801F410: .4byte 0xFFFFF7FF
_0801F414: .4byte 0xFFFFFBFF
_0801F418: .4byte 0xFFFFFDFF
_0801F41C: .4byte 0xFFFFFEFF

	thumb_func_start FUN_0801f420
FUN_0801f420: @ 0x0801F420
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0801F470 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0801F438
	adds r0, r4, #0
	movs r1, #0xf
	bl FUN_0801e284
_0801F438:
	ldr r1, _0801F474 @ =0x085AA98C
	ldrb r0, [r4, #0x19]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0801F45C
	adds r1, r4, #0
	adds r1, #0x8c
	ldr r0, [r1]
	cmp r0, #0
	beq _0801F45C
	subs r0, #1
	str r0, [r1]
_0801F45C:
	ldr r0, [r4, #0x24]
	adds r0, #1
	str r0, [r4, #0x24]
	ldr r0, [r4, #0x58]
	movs r1, #0xb0
	lsls r1, r1, #5
	cmp r0, r1
	ble _0801F478
	str r1, [r4, #0x58]
	b _0801F480
	.align 2, 0
_0801F470: .4byte 0x030044E0
_0801F474: .4byte 0x085AA98C
_0801F478:
	cmp r0, #0
	bge _0801F480
	movs r0, #0
	str r0, [r4, #0x58]
_0801F480:
	ldr r0, [r4, #0x58]
	asrs r0, r0, #5
	strh r0, [r4, #0x36]
	ldrb r0, [r4, #0x19]
	cmp r0, #0xc
	bhi _0801F492
	adds r0, r4, #0
	bl FUN_0801e728
_0801F492:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801f49c
FUN_0801f49c: @ 0x0801F49C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl FUN_0801e960
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r4, r6, r0
	movs r5, #3
_0801F4AC:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x28
	subs r5, #1
	cmp r5, #0
	bge _0801F4AC
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r0, r6, r1
	bl FUN_0822f1c0
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801f4cc
FUN_0801f4cc: @ 0x0801F4CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r6, r0, #0
	movs r1, #0xea
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, _0801F5C8 @ =0x08DAA084
	movs r2, #0x24
	bl FUN_08230ab0
	ldr r4, _0801F5CC @ =0x0000CB05
	ldr r1, _0801F5D0 @ =0x0000414C
	adds r0, r4, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0801F5C0
	movs r2, #0xb0
	adds r2, r2, r6
	mov r8, r2
	adds r1, r3, #0
	ldm r1!, {r0, r5, r7}
	stm r2!, {r0, r5, r7}
	ldm r1!, {r0, r5, r7}
	stm r2!, {r0, r5, r7}
	ldm r1!, {r5, r7}
	stm r2!, {r5, r7}
	mov r0, r8
	adds r1, r3, #0
	bl OpenSpriteSetFile
	ldr r1, _0801F5D4 @ =0x0000B343
	adds r0, r4, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0801F5C0
	movs r0, #0xd0
	adds r0, r0, r6
	mov r8, r0
	mov r2, r8
	adds r1, r3, #0
	ldm r1!, {r0, r5, r7}
	stm r2!, {r0, r5, r7}
	ldm r1!, {r0, r5, r7}
	stm r2!, {r0, r5, r7}
	ldm r1!, {r5, r7}
	stm r2!, {r5, r7}
	mov r0, r8
	adds r1, r3, #0
	bl OpenSpriteSetFile
	ldr r1, _0801F5D8 @ =0x00005D04
	adds r0, r4, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0801F5C0
	movs r0, #0xf0
	adds r0, r0, r6
	mov r8, r0
	mov r2, r8
	adds r1, r3, #0
	ldm r1!, {r0, r5, r7}
	stm r2!, {r0, r5, r7}
	ldm r1!, {r0, r5, r7}
	stm r2!, {r0, r5, r7}
	ldm r1!, {r5, r7}
	stm r2!, {r5, r7}
	mov r0, r8
	adds r1, r3, #0
	bl OpenSpriteSetFile
	ldr r1, _0801F5DC @ =0x000082F1
	adds r0, r4, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0801F5C0
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r2, r0, #0
	adds r1, r3, #0
	ldm r1!, {r4, r5, r7}
	stm r2!, {r4, r5, r7}
	ldm r1!, {r4, r5, r7}
	stm r2!, {r4, r5, r7}
	ldm r1!, {r4, r5}
	stm r2!, {r4, r5}
	adds r1, r3, #0
	bl OpenSpriteSetFile
	movs r0, #0x65
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r6, #0
	adds r1, #0x90
	str r0, [r1]
	movs r0, #0x45
	bl prepare_08231510
	cmp r0, #0
	beq _0801F5C0
	bl FUN_0823d340
	adds r1, r0, #0
	movs r7, #0xeb
	lsls r7, r7, #3
	adds r0, r6, r7
	str r1, [r0]
	cmp r1, #0
	bne _0801F5E0
_0801F5C0:
	movs r0, #1
	rsbs r0, r0, #0
	b _0801F6FE
	.align 2, 0
_0801F5C8: .4byte 0x08DAA084
_0801F5CC: .4byte 0x0000CB05
_0801F5D0: .4byte 0x0000414C
_0801F5D4: .4byte 0x0000B343
_0801F5D8: .4byte 0x00005D04
_0801F5DC: .4byte 0x000082F1
_0801F5E0:
	adds r0, r1, #0
	bl FUN_080478f0
	movs r0, #1
	movs r1, #1
	movs r2, #0x1e
	movs r3, #6
	bl FUN_08047b8c
	ldr r0, _0801F710 @ =0x0000A41A
	bl FUN_08047dc0
	movs r0, #1
	bl FUN_080477e4
	adds r0, r6, #0
	movs r1, #1
	bl FUN_0801e2a8
	adds r0, r6, #0
	bl FUN_0801e328
	adds r0, r6, #0
	bl FUN_0801e458
	adds r0, r6, #0
	bl FUN_0801e4b0
	ldr r0, _0801F714 @ =0x00001C1A
	bl GetParticleGroup
	movs r2, #0x98
	lsls r2, r2, #1
	adds r1, r6, r2
	str r0, [r1]
	add r4, sp, #0x14
	mov sl, r4
	adds r7, r1, #0
	movs r0, #0xa6
	lsls r0, r0, #1
	adds r5, r6, r0
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r4, r6, r1
	movs r2, #8
	rsbs r2, r2, #0
	mov sb, r2
	movs r0, #3
	mov r8, r0
_0801F642:
	ldr r1, [r7]
	adds r0, r4, #0
	movs r2, #0x11
	bl FUN_0822d9f0
	adds r0, r4, #0
	mov r1, sb
	mov r2, sb
	bl FUN_0822dad4
	ldr r1, [r7]
	adds r0, r4, #0
	movs r2, #0x33
	bl FUN_0822dafc
	movs r1, #1
	strb r1, [r4, #0xf]
	movs r2, #0
	str r2, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _0801F718 @ =0x05000002
	bl CpuSet
	adds r5, #0x28
	adds r4, #0x28
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r1, r8
	cmp r1, #0
	bge _0801F642
	movs r4, #0
	movs r0, #4
	str r0, [sp]
	ldr r5, _0801F71C @ =0x0000FFFF
	str r5, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	adds r0, r6, #0
	movs r1, #0
	bl FUN_0801e284
	strb r4, [r6, #0x1b]
	strb r4, [r6, #0x1e]
	ldr r2, _0801F720 @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0xdf
	orrs r0, r1
	ands r0, r5
	movs r1, #0x88
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x14]
	mov r5, sl
	ldr r0, [r5, #4]
	ands r0, r2
	str r0, [r5, #4]
	movs r7, #0xdb
	lsls r7, r7, #3
	adds r5, r6, r7
	movs r0, #0x88
	lsls r0, r0, #1
	adds r6, r6, r0
	str r4, [sp]
	movs r1, #1
	str r1, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r2, sl
	str r2, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #8
	movs r3, #0x51
	bl FUN_0822f3fc
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	movs r0, #0xaa
	bl sound_08240264
	movs r0, #0
_0801F6FE:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801F710: .4byte 0x0000A41A
_0801F714: .4byte 0x00001C1A
_0801F718: .4byte 0x05000002
_0801F71C: .4byte 0x0000FFFF
_0801F720: .4byte 0xFFFF0000

	thumb_func_start FUN_0801f724
FUN_0801f724: @ 0x0801F724
	push {r4, lr}
	ldr r1, _0801F750 @ =0x0000075C
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801F75C
	ldr r1, _0801F754 @ =FUN_0801f420
	ldr r2, _0801F758 @ =FUN_0801f49c
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0801f4cc
	cmp r0, #0
	bge _0801F75C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801F75E
	.align 2, 0
_0801F750: .4byte 0x0000075C
_0801F754: .4byte FUN_0801f420
_0801F758: .4byte FUN_0801f49c
_0801F75C:
	adds r0, r4, #0
_0801F75E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801f764
FUN_0801f764: @ 0x0801F764
	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r2, _0801F7B0 @ =0x085AA9CC
	movs r0, #0x39
	adds r0, r0, r3
	mov ip, r0
	adds r4, r3, #0
	adds r4, #0x38
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	mov r1, ip
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	strb r0, [r3, #7]
	mov r5, ip
	ldrb r0, [r5]
	cmp r0, #2
	bne _0801F7B4
	adds r0, r3, #0
	adds r0, #0x70
	ldrh r0, [r0]
	subs r0, #0x28
	strh r0, [r3, #0x1c]
	adds r0, r3, #0
	adds r0, #0x72
	ldrh r0, [r0]
	subs r0, #0x5a
	strh r0, [r3, #0x1e]
	adds r0, r3, #0
	adds r0, #0x74
	ldrh r0, [r0]
	subs r0, #0x28
	strh r0, [r3, #0x20]
	b _0801F7EC
	.align 2, 0
_0801F7B0: .4byte 0x085AA9CC
_0801F7B4:
	cmp r0, #0
	bne _0801F7E4
	ldrb r0, [r4]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0801F7E4
	adds r0, r3, #0
	adds r0, #0x70
	ldrh r0, [r0]
	adds r0, #0x50
	strh r0, [r3, #0x1c]
	adds r0, r3, #0
	adds r0, #0x72
	ldrh r0, [r0]
	adds r0, #0xb4
	strh r0, [r3, #0x1e]
	adds r0, r3, #0
	adds r0, #0x74
	ldrh r0, [r0]
	adds r0, #0x50
	strh r0, [r3, #0x20]
	b _0801F7EC
_0801F7E4:
	ldr r0, [r3, #0x70]
	ldr r1, [r3, #0x74]
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
_0801F7EC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801f7f4
FUN_0801f7f4: @ 0x0801F7F4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r3, _0801F830 @ =0x085AA9FC
	movs r0, #0x39
	adds r0, r0, r4
	mov ip, r0
	adds r2, r4, #0
	adds r2, #0x38
	ldrb r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	mov r1, ip
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	strb r0, [r4, #7]
	ldrb r0, [r2]
	cmp r0, #1
	bls _0801F826
	cmp r0, #4
	beq _0801F826
	cmp r0, #5
	bne _0801F834
_0801F826:
	ldr r0, [r4, #0x70]
	ldr r1, [r4, #0x74]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	b _0801F852
	.align 2, 0
_0801F830: .4byte 0x085AA9FC
_0801F834:
	adds r0, r4, #0
	adds r0, #0x70
	ldrh r0, [r0]
	adds r0, #0x28
	strh r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0x72
	ldrh r0, [r0]
	adds r0, #0x5a
	strh r0, [r4, #0x1e]
	adds r0, r4, #0
	adds r0, #0x74
	ldrh r0, [r0]
	adds r0, #0x28
	strh r0, [r4, #0x20]
_0801F852:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801f858
FUN_0801f858: @ 0x0801F858
	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r2, _0801F8A4 @ =0x085AAA5C
	movs r0, #0x39
	adds r0, r0, r3
	mov ip, r0
	adds r4, r3, #0
	adds r4, #0x38
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	mov r1, ip
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	strb r0, [r3, #7]
	mov r5, ip
	ldrb r0, [r5]
	cmp r0, #2
	bne _0801F8A8
	adds r0, r3, #0
	adds r0, #0x70
	ldrh r0, [r0]
	subs r0, #0x28
	strh r0, [r3, #0x1c]
	adds r0, r3, #0
	adds r0, #0x72
	ldrh r0, [r0]
	subs r0, #0x5a
	strh r0, [r3, #0x1e]
	adds r0, r3, #0
	adds r0, #0x74
	ldrh r0, [r0]
	subs r0, #0x28
	strh r0, [r3, #0x20]
	b _0801F8E0
	.align 2, 0
_0801F8A4: .4byte 0x085AAA5C
_0801F8A8:
	cmp r0, #0
	bne _0801F8D8
	ldrb r0, [r4]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0801F8D8
	adds r0, r3, #0
	adds r0, #0x70
	ldrh r0, [r0]
	adds r0, #0x50
	strh r0, [r3, #0x1c]
	adds r0, r3, #0
	adds r0, #0x72
	ldrh r0, [r0]
	adds r0, #0xb4
	strh r0, [r3, #0x1e]
	adds r0, r3, #0
	adds r0, #0x74
	ldrh r0, [r0]
	adds r0, #0x50
	strh r0, [r3, #0x20]
	b _0801F8E0
_0801F8D8:
	ldr r0, [r3, #0x70]
	ldr r1, [r3, #0x74]
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
_0801F8E0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801f8e8
FUN_0801f8e8: @ 0x0801F8E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r2, #0
	str r3, [sp]
	ldr r0, [sp, #0x24]
	ldr r2, [sp, #0x28]
	ldr r3, [sp, #0x2c]
	ldr r4, [sp, #0x44]
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov ip, r0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov sb, r3
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	mov sl, r4
	ldrh r1, [r5, #0x1a]
	ldr r0, [r5, #0x30]
	cmp r1, r0
	bge _0801F9A4
	ldr r0, _0801F9AC @ =0x0000042C
	adds r2, r5, r0
	movs r0, #0x8c
	muls r1, r0, r1
	ldr r0, [r2]
	adds r4, r0, r1
	movs r2, #0
	movs r3, #0
	strh r7, [r4, #0x34]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r4, #0x68]
	str r1, [r4, #0x6c]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r4, #0x78]
	str r1, [r4, #0x7c]
	adds r0, r4, #0
	adds r0, #0x36
	mov r1, ip
	strb r1, [r0]
	adds r0, #1
	mov r1, r8
	strb r1, [r0]
	adds r0, #1
	mov r1, sb
	strb r1, [r0]
	adds r0, #2
	strb r2, [r0]
	adds r7, r4, #0
	adds r7, #0x40
	ldr r0, [sp, #0x30]
	strb r0, [r7]
	adds r1, r4, #0
	adds r1, #0x88
	ldr r0, [sp, #0x34]
	strh r0, [r1]
	ldr r0, [sp, #0x38]
	str r0, [r4, #0x48]
	subs r1, #0x47
	ldr r0, [sp, #0x3c]
	strb r0, [r1]
	ldr r0, [sp]
	str r0, [r4, #0x4c]
	adds r0, r4, #0
	adds r0, #0x80
	strh r3, [r0]
	adds r0, r6, #0
	bl FUN_08241574
	adds r1, r4, #0
	adds r1, #0x42
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x44
	mov r1, sl
	strb r1, [r0]
	movs r0, #0x10
	bl Malloc
	str r0, [r4, #0x2c]
	cmp r0, #0
	bne _0801F9B0
_0801F9A4:
	movs r0, #1
	rsbs r0, r0, #0
	b _0801FA98
	.align 2, 0
_0801F9AC: .4byte 0x0000042C
_0801F9B0:
	movs r1, #0x10
	bl ClearMemory
	ldrb r1, [r7]
	cmp r1, #0x10
	bhi _0801FA76
	lsls r0, r1, #2
	ldr r1, _0801F9C8 @ =_0801F9CC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801F9C8: .4byte _0801F9CC
_0801F9CC: @ jump table
	.4byte _0801FA64 @ case 0
	.4byte _0801FA10 @ case 1
	.4byte _0801FA1A @ case 2
	.4byte _0801FA64 @ case 3
	.4byte _0801FA64 @ case 4
	.4byte _0801FA64 @ case 5
	.4byte _0801FA64 @ case 6
	.4byte _0801FA64 @ case 7
	.4byte _0801FA22 @ case 8
	.4byte _0801FA2A @ case 9
	.4byte _0801FA32 @ case 10
	.4byte _0801FA3A @ case 11
	.4byte _0801FA42 @ case 12
	.4byte _0801FA4A @ case 13
	.4byte _0801FA52 @ case 14
	.4byte _0801FA64 @ case 15
	.4byte _0801FA6E @ case 16
_0801FA10:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080207b0
	b _0801FA76
_0801FA1A:
	adds r1, r4, #0
	adds r1, #0x45
	movs r0, #0
	b _0801FA58
_0801FA22:
	adds r1, r4, #0
	adds r1, #0x45
	movs r0, #1
	b _0801FA58
_0801FA2A:
	adds r1, r4, #0
	adds r1, #0x45
	movs r0, #2
	b _0801FA58
_0801FA32:
	adds r1, r4, #0
	adds r1, #0x45
	movs r0, #3
	b _0801FA58
_0801FA3A:
	adds r1, r4, #0
	adds r1, #0x45
	movs r0, #4
	b _0801FA58
_0801FA42:
	adds r1, r4, #0
	adds r1, #0x45
	movs r0, #5
	b _0801FA58
_0801FA4A:
	adds r1, r4, #0
	adds r1, #0x45
	movs r0, #6
	b _0801FA58
_0801FA52:
	adds r1, r4, #0
	adds r1, #0x45
	movs r0, #7
_0801FA58:
	strb r0, [r1]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08020d44
	b _0801FA76
_0801FA64:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080203a4
	b _0801FA76
_0801FA6E:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08020d44
_0801FA76:
	ldr r1, [r4, #0x48]
	cmp r1, #0
	beq _0801FA90
	ldr r6, [sp, #0x40]
	adds r3, r4, #0
	adds r3, #0x50
	movs r2, #3
_0801FA84:
	ldm r6!, {r1}
	stm r3!, {r1}
	subs r2, #1
	cmp r2, #0
	bge _0801FA84
	b _0801FA92
_0801FA90:
	str r1, [r4, #0x50]
_0801FA92:
	ldrh r1, [r5, #0x1a]
	adds r1, #1
	strh r1, [r5, #0x1a]
_0801FA98:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801faa8
FUN_0801faa8: @ 0x0801FAA8
	push {r4, lr}
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	movs r3, #0
	ldrb r2, [r0, #0x1c]
	cmp r3, r2
	bge _0801FACE
	adds r1, r2, #0
	adds r2, r0, #0
	adds r2, #0x1e
_0801FABC:
	ldrh r0, [r2]
	cmp r0, r4
	bne _0801FAC6
	movs r0, #1
	b _0801FAD0
_0801FAC6:
	adds r2, #2
	adds r3, #1
	cmp r3, r1
	blt _0801FABC
_0801FACE:
	movs r0, #0
_0801FAD0:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801fad8
FUN_0801fad8: @ 0x0801FAD8
	push {r4, lr}
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	movs r3, #0
	ldrb r2, [r0, #0x1d]
	cmp r3, r2
	bge _0801FAFE
	adds r1, r2, #0
	adds r2, r0, #0
	adds r2, #0x26
_0801FAEC:
	ldrh r0, [r2]
	cmp r0, r4
	bne _0801FAF6
	movs r0, #1
	b _0801FB00
_0801FAF6:
	adds r2, #2
	adds r3, #1
	cmp r3, r1
	blt _0801FAEC
_0801FAFE:
	movs r0, #0
_0801FB00:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801fb08
FUN_0801fb08: @ 0x0801FB08
	push {r4, lr}
	movs r3, #0
	ldr r0, _0801FB30 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r4, [r0]
	ldr r2, _0801FB34 @ =0x085AAA8C
	adds r1, #0x38
	ldrb r1, [r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r0, r2
_0801FB26:
	ldr r0, [r1]
	cmp r4, r0
	bne _0801FB38
	movs r0, #0
	b _0801FB42
	.align 2, 0
_0801FB30: .4byte 0x03002BE0
_0801FB34: .4byte 0x085AAA8C
_0801FB38:
	adds r1, #4
	adds r3, #1
	cmp r3, #2
	ble _0801FB26
	movs r0, #1
_0801FB42:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801fb48
FUN_0801fb48: @ 0x0801FB48
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x58
	ldr r0, _0801FB68 @ =0x000085E6
	bl FUN_08230e70
	str r0, [sp, #0x3c]
	cmp r0, #0
	bne _0801FB6C
	movs r0, #1
	rsbs r0, r0, #0
	b _0801FC76
	.align 2, 0
_0801FB68: .4byte 0x000085E6
_0801FB6C:
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x40]
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp, #0x44]
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x48]
	movs r0, #0x73
	movs r1, #0
	bl Script_GetKeywordValue
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x4c]
	movs r0, #0x72
	movs r1, #0
	bl Script_GetKeywordValue
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x50]
	movs r0, #0x76
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp, #0x54]
	movs r1, #0xc8
	lsls r1, r1, #1
	movs r0, #0x68
	bl Script_GetKeywordValue
	mov sl, r0
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	movs r0, #0x6b
	bl prepare_08231510
	cmp r0, #0
	beq _0801FBFC
	bl Script_GetValue
	mov r8, r0
	bl Script_GetValue
	adds r7, r0, #0
	add r6, sp, #0x34
	add r5, sp, #0x24
	movs r4, #3
_0801FBEE:
	bl Script_GetValue
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _0801FBEE
	b _0801FC04
_0801FBFC:
	movs r0, #0
	mov r8, r0
	movs r7, #0
	add r6, sp, #0x34
_0801FC04:
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _0801FC1E
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r6, #0
	bl FUN_08234cf8
	b _0801FC48
_0801FC1E:
	movs r0, #0x70
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _0801FC40
	bl Script_GetValue
	strh r0, [r6]
	bl Script_GetValue
	add r4, sp, #0x34
	strh r0, [r4, #2]
	bl Script_GetValue
	strh r0, [r4, #4]
	b _0801FC48
_0801FC40:
	strh r1, [r6]
	add r0, sp, #0x34
	strh r1, [r0, #2]
	strh r1, [r0, #4]
_0801FC48:
	ldr r0, [sp, #0x48]
	str r0, [sp]
	ldr r0, [sp, #0x4c]
	str r0, [sp, #4]
	ldr r0, [sp, #0x50]
	str r0, [sp, #8]
	ldr r0, [sp, #0x54]
	str r0, [sp, #0xc]
	mov r0, sl
	str r0, [sp, #0x10]
	mov r0, r8
	str r0, [sp, #0x14]
	str r7, [sp, #0x18]
	add r0, sp, #0x24
	str r0, [sp, #0x1c]
	mov r0, sb
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x3c]
	ldr r1, [sp, #0x40]
	adds r2, r6, #0
	ldr r3, [sp, #0x44]
	bl FUN_0801f8e8
_0801FC76:
	add sp, #0x58
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801fc88
FUN_0801fc88: @ 0x0801FC88
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	movs r4, #0
	ldrh r0, [r5, #0x1a]
	cmp r4, r0
	bge _0801FCFC
	ldr r1, _0801FD08 @ =0x0000042C
	adds r6, r5, r1
	movs r3, #2
	mov sb, r3
	ldr r0, _0801FD0C @ =FUN_08020734
	mov r8, r0
_0801FCAA:
	movs r0, #0x8c
	adds r1, r4, #0
	muls r1, r0, r1
	ldr r0, [r6]
	adds r2, r0, r1
	ldrh r0, [r2, #0x34]
	cmp r0, r7
	bne _0801FCF4
	movs r1, #0x37
	adds r1, r1, r2
	mov ip, r1
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801FCCA
	cmp r0, #3
	bne _0801FCF4
_0801FCCA:
	adds r0, r2, #0
	adds r0, #0x36
	ldrb r0, [r0]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	cmp r1, #0
	bne _0801FCF4
	adds r0, r2, #0
	adds r0, #0x41
	strb r3, [r0]
	mov r0, sb
	mov r3, ip
	strb r0, [r3]
	mov r3, r8
	str r3, [r2, #0x30]
	adds r0, r2, #0
	adds r0, #0x39
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_0801FCF4:
	adds r4, #1
	ldrh r0, [r5, #0x1a]
	cmp r4, r0
	blt _0801FCAA
_0801FCFC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FD08: .4byte 0x0000042C
_0801FD0C: .4byte FUN_08020734

	thumb_func_start FUN_0801fd10
FUN_0801fd10: @ 0x0801FD10
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	movs r3, #0
	ldrh r0, [r4, #0x1a]
	cmp r3, r0
	bge _0801FD72
	ldr r1, _0801FD80 @ =0x0000042C
	adds r5, r4, r1
	movs r2, #3
	mov sb, r2
	mov r8, r3
	movs r0, #2
	mov ip, r0
	ldr r7, _0801FD84 @ =FUN_080206b8
_0801FD36:
	movs r0, #0x8c
	adds r1, r3, #0
	muls r1, r0, r1
	ldr r0, [r5]
	adds r1, r0, r1
	ldrh r0, [r1, #0x34]
	cmp r0, r6
	bne _0801FD6A
	adds r2, r1, #0
	adds r2, #0x37
	ldrb r0, [r2]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0801FD6A
	mov r0, sb
	strb r0, [r2]
	str r7, [r1, #0x30]
	adds r0, r1, #0
	adds r0, #0x39
	mov r2, ip
	strb r2, [r0]
	adds r0, #1
	mov r1, r8
	strb r1, [r0]
_0801FD6A:
	adds r3, #1
	ldrh r2, [r4, #0x1a]
	cmp r3, r2
	blt _0801FD36
_0801FD72:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FD80: .4byte 0x0000042C
_0801FD84: .4byte FUN_080206b8

	thumb_func_start FUN_0801fd88
FUN_0801fd88: @ 0x0801FD88
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	movs r3, #0
	ldrh r0, [r4, #0x1a]
	cmp r3, r0
	bge _0801FDDA
	ldr r7, _0801FDE8 @ =0x0000042C
	adds r6, r4, r7
	movs r0, #1
	mov r8, r0
	movs r5, #0
	ldr r7, _0801FDEC @ =0x080206B5
	mov ip, r7
	movs r1, #0
_0801FDB0:
	ldr r0, [r6]
	adds r2, r0, r1
	ldrh r0, [r2, #0x34]
	cmp r0, sb
	bne _0801FDD0
	adds r0, r2, #0
	adds r0, #0x37
	mov r7, r8
	strb r7, [r0]
	mov r0, ip
	str r0, [r2, #0x30]
	adds r0, r2, #0
	adds r0, #0x39
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
_0801FDD0:
	adds r1, #0x8c
	adds r3, #1
	ldrh r7, [r4, #0x1a]
	cmp r3, r7
	blt _0801FDB0
_0801FDDA:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FDE8: .4byte 0x0000042C
_0801FDEC: .4byte 0x080206B5

	thumb_func_start FUN_0801fdf0
FUN_0801fdf0: @ 0x0801FDF0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	movs r3, #0
	ldrh r0, [r4, #0x1a]
	cmp r3, r0
	bge _0801FE42
	ldr r7, _0801FE50 @ =0x0000042C
	adds r6, r4, r7
	movs r5, #0
	ldr r0, _0801FE54 @ =0x080206B1
	mov r8, r0
	movs r7, #2
	mov ip, r7
	movs r1, #0
_0801FE18:
	ldr r0, [r6]
	adds r2, r0, r1
	ldrh r0, [r2, #0x34]
	cmp r0, sb
	bne _0801FE38
	adds r0, r2, #0
	adds r0, #0x37
	strb r5, [r0]
	mov r0, r8
	str r0, [r2, #0x30]
	adds r0, r2, #0
	adds r0, #0x39
	mov r7, ip
	strb r7, [r0]
	adds r0, #1
	strb r5, [r0]
_0801FE38:
	adds r1, #0x8c
	adds r3, #1
	ldrh r0, [r4, #0x1a]
	cmp r3, r0
	blt _0801FE18
_0801FE42:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FE50: .4byte 0x0000042C
_0801FE54: .4byte 0x080206B1

	thumb_func_start FUN_0801fe58
FUN_0801fe58: @ 0x0801FE58
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	movs r2, #0
	ldrh r0, [r4, #0x1a]
	cmp r2, r0
	bge _0801FE8C
	ldr r0, _0801FE94 @ =0x0000042C
	adds r5, r4, r0
	movs r7, #1
	movs r3, #0
_0801FE70:
	ldr r0, [r5]
	adds r1, r0, r3
	ldrh r0, [r1, #0x34]
	cmp r0, r6
	bne _0801FE82
	adds r1, #0x36
	ldrb r0, [r1]
	orrs r0, r7
	strb r0, [r1]
_0801FE82:
	adds r3, #0x8c
	adds r2, #1
	ldrh r0, [r4, #0x1a]
	cmp r2, r0
	blt _0801FE70
_0801FE8C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FE94: .4byte 0x0000042C

	thumb_func_start FUN_0801fe98
FUN_0801fe98: @ 0x0801FE98
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	movs r3, #0
	ldrh r0, [r5, #0x1a]
	cmp r3, r0
	bge _0801FED0
	ldr r0, _0801FED8 @ =0x0000042C
	adds r6, r5, r0
	movs r4, #0
	movs r0, #0xfe
	mov ip, r0
_0801FEB2:
	ldr r0, [r6]
	adds r2, r0, r4
	ldrh r0, [r2, #0x34]
	cmp r0, r7
	bne _0801FEC6
	adds r2, #0x36
	ldrb r1, [r2]
	mov r0, ip
	ands r0, r1
	strb r0, [r2]
_0801FEC6:
	adds r4, #0x8c
	adds r3, #1
	ldrh r0, [r5, #0x1a]
	cmp r3, r0
	blt _0801FEB2
_0801FED0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FED8: .4byte 0x0000042C

	thumb_func_start FUN_0801fedc
FUN_0801fedc: @ 0x0801FEDC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _0801FEF8 @ =0x000085E6
	bl FUN_08230e70
	adds r6, r0, #0
	cmp r6, #0
	bne _0801FEFC
	movs r0, #1
	rsbs r0, r0, #0
	b _0801FF64
	.align 2, 0
_0801FEF8: .4byte 0x000085E6
_0801FEFC:
	movs r7, #0
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	bne _0801FF0C
	movs r0, #0
	b _0801FF64
_0801FF0C:
	bl Script_GetValue
	mov sb, r0
	movs r5, #0
	ldrh r0, [r6, #0x1a]
	cmp r7, r0
	bge _0801FF62
	ldr r2, _0801FF70 @ =0x0000042C
	adds r2, r2, r6
	mov r8, r2
_0801FF20:
	movs r0, #0x8c
	adds r1, r5, #0
	muls r1, r0, r1
	mov r2, r8
	ldr r0, [r2]
	adds r4, r0, r1
	ldrh r0, [r4, #0x34]
	cmp r0, sb
	bne _0801FF5A
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0801FF42
	bl Script_GetValue
	str r0, [r4, #0x60]
_0801FF42:
	adds r1, r4, #0
	adds r1, #0x37
	ldrb r0, [r1]
	cmp r0, #1
	beq _0801FF50
	cmp r0, #3
	bne _0801FF58
_0801FF50:
	movs r0, #2
	strb r0, [r1]
	ldr r0, _0801FF74 @ =FUN_08020af8
	str r0, [r4, #0x30]
_0801FF58:
	movs r7, #1
_0801FF5A:
	adds r5, #1
	ldrh r0, [r6, #0x1a]
	cmp r5, r0
	blt _0801FF20
_0801FF62:
	adds r0, r7, #0
_0801FF64:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801FF70: .4byte 0x0000042C
_0801FF74: .4byte FUN_08020af8

	thumb_func_start FUN_0801ff78
FUN_0801ff78: @ 0x0801FF78
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _0801FFA0 @ =0x000085E6
	bl FUN_08230e70
	adds r6, r0, #0
	cmp r6, #0
	beq _0801FF98
	movs r7, #0
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	bne _0801FFA4
_0801FF98:
	movs r0, #1
	rsbs r0, r0, #0
	b _0801FFFC
	.align 2, 0
_0801FFA0: .4byte 0x000085E6
_0801FFA4:
	bl Script_GetValue
	mov sb, r0
	movs r5, #0
	ldrh r0, [r6, #0x1a]
	cmp r7, r0
	bge _0801FFFA
	ldr r2, _08020008 @ =0x0000042C
	adds r2, r2, r6
	mov r8, r2
_0801FFB8:
	movs r0, #0x8c
	adds r1, r5, #0
	muls r1, r0, r1
	mov r2, r8
	ldr r0, [r2]
	adds r4, r0, r1
	ldrh r0, [r4, #0x34]
	cmp r0, sb
	bne _0801FFF2
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0801FFDA
	bl Script_GetValue
	str r0, [r4, #0x64]
_0801FFDA:
	adds r1, r4, #0
	adds r1, #0x37
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801FFE8
	cmp r0, #2
	bne _0801FFF0
_0801FFE8:
	movs r0, #3
	strb r0, [r1]
	ldr r0, _0802000C @ =FUN_08020b24
	str r0, [r4, #0x30]
_0801FFF0:
	movs r7, #1
_0801FFF2:
	adds r5, #1
	ldrh r0, [r6, #0x1a]
	cmp r5, r0
	blt _0801FFB8
_0801FFFA:
	adds r0, r7, #0
_0801FFFC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08020008: .4byte 0x0000042C
_0802000C: .4byte FUN_08020b24

	thumb_func_start FUN_08020010
FUN_08020010: @ 0x08020010
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _0802002C @ =0x000085E6
	bl FUN_08230e70
	adds r5, r0, #0
	cmp r5, #0
	bne _08020030
	movs r0, #1
	rsbs r0, r0, #0
	b _080200D6
	.align 2, 0
_0802002C: .4byte 0x000085E6
_08020030:
	movs r6, #0
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	bne _08020040
	movs r0, #0
	b _080200D6
_08020040:
	bl Script_GetValue
	mov r8, r0
	movs r4, #0
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	bge _080200D4
	ldr r2, _080200E4 @ =0x0000042C
	adds r2, r2, r5
	mov ip, r2
	movs r7, #0
	ldr r0, _080200E8 @ =0x0000FFFC
	mov sl, r0
	ldr r2, _080200EC @ =FUN_08020cd8
	mov sb, r2
_0802005E:
	movs r0, #0x8c
	adds r1, r4, #0
	muls r1, r0, r1
	mov r2, ip
	ldr r0, [r2]
	adds r3, r0, r1
	ldrh r0, [r3, #0x34]
	cmp r0, r8
	bne _080200CC
	adds r1, r3, #0
	adds r1, #0x82
	movs r0, #0
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x37
	strb r7, [r0]
	mov r0, sb
	str r0, [r3, #0x30]
	adds r0, r3, #0
	adds r0, #0x39
	strb r7, [r0]
	adds r0, #1
	strb r7, [r0]
	ldr r2, [r3, #0x2c]
	ldrh r1, [r2, #6]
	mov r0, sl
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r3, #0x2c]
	ldrh r0, [r2, #6]
	movs r1, #2
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r3, #0x2c]
	ldrb r0, [r2, #4]
	movs r1, #0xf0
	ands r1, r0
	adds r0, r3, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	orrs r1, r0
	strb r1, [r2, #4]
	adds r2, r3, #0
	adds r2, #0x88
	ldrh r1, [r2]
	adds r0, r3, #0
	adds r0, #0x80
	strh r1, [r0]
	adds r1, r3, #0
	adds r1, #0x72
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r3, #0x1e]
	movs r6, #1
_080200CC:
	adds r4, #1
	ldrh r2, [r5, #0x1a]
	cmp r4, r2
	blt _0802005E
_080200D4:
	adds r0, r6, #0
_080200D6:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080200E4: .4byte 0x0000042C
_080200E8: .4byte 0x0000FFFC
_080200EC: .4byte FUN_08020cd8

	thumb_func_start FUN_080200f0
FUN_080200f0: @ 0x080200F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _08020118 @ =0x000085E6
	bl FUN_08230e70
	adds r5, r0, #0
	cmp r5, #0
	beq _08020112
	movs r6, #0
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	bne _0802011C
_08020112:
	movs r0, #1
	rsbs r0, r0, #0
	b _080201AE
	.align 2, 0
_08020118: .4byte 0x000085E6
_0802011C:
	bl Script_GetValue
	mov r8, r0
	movs r4, #0
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	bge _080201AC
	ldr r1, _080201BC @ =0x0000042C
	adds r1, r1, r5
	mov ip, r1
	movs r7, #0
	movs r2, #1
	mov sb, r2
	ldr r0, _080201C0 @ =0x0000FFFD
	mov sl, r0
_0802013A:
	movs r0, #0x8c
	adds r1, r4, #0
	muls r1, r0, r1
	mov r2, ip
	ldr r0, [r2]
	adds r3, r0, r1
	ldrh r0, [r3, #0x34]
	cmp r0, r8
	bne _080201A4
	adds r0, r3, #0
	adds r0, #0x82
	strh r7, [r0]
	subs r0, #0x4b
	mov r1, sb
	strb r1, [r0]
	ldr r2, _080201C4 @ =FUN_08020d10
	str r2, [r3, #0x30]
	adds r0, #0x4d
	ldrb r0, [r0]
	adds r1, r3, #0
	adds r1, #0x39
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x3a
	movs r1, #0
	strb r1, [r0]
	ldr r2, [r3, #0x2c]
	ldrh r1, [r2, #6]
	mov r0, sl
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r3, #0x2c]
	ldrh r0, [r2, #6]
	movs r1, #3
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r3, #0x2c]
	ldrb r0, [r2, #4]
	movs r1, #0xf0
	ands r1, r0
	adds r0, r3, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	adds r0, #1
	orrs r1, r0
	strb r1, [r2, #4]
	adds r0, r3, #0
	adds r0, #0x80
	strh r7, [r0]
	subs r0, #0xe
	ldrh r0, [r0]
	strh r0, [r3, #0x1e]
	movs r6, #1
_080201A4:
	adds r4, #1
	ldrh r2, [r5, #0x1a]
	cmp r4, r2
	blt _0802013A
_080201AC:
	adds r0, r6, #0
_080201AE:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080201BC: .4byte 0x0000042C
_080201C0: .4byte 0x0000FFFD
_080201C4: .4byte FUN_08020d10

	thumb_func_start FUN_080201c8
FUN_080201c8: @ 0x080201C8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _08020254 @ =0x000085E6
	bl FUN_08230e70
	adds r4, r0, #0
	cmp r4, #0
	beq _0802024A
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _0802024A
	bl Script_GetValue
	adds r7, r0, #0
	movs r3, #0
	ldrh r0, [r4, #0x1a]
	cmp r3, r0
	bge _0802024A
	ldr r1, _08020258 @ =0x0000042C
	adds r6, r4, r1
	movs r5, #0
	movs r0, #2
	mov r8, r0
	ldr r1, _0802025C @ =FUN_08020734
	mov ip, r1
_08020200:
	movs r0, #0x8c
	adds r1, r3, #0
	muls r1, r0, r1
	ldr r0, [r6]
	adds r2, r0, r1
	ldrh r0, [r2, #0x34]
	cmp r0, r7
	bne _08020242
	adds r1, r2, #0
	adds r1, #0x41
	movs r0, #1
	strb r0, [r1]
	ldrb r0, [r4, #0x1c]
	lsls r0, r0, #1
	adds r1, r4, #0
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r2, #0x34]
	strh r0, [r1]
	ldrb r0, [r4, #0x1c]
	adds r0, #1
	strb r0, [r4, #0x1c]
	adds r0, r2, #0
	adds r0, #0x37
	mov r1, r8
	strb r1, [r0]
	mov r0, ip
	str r0, [r2, #0x30]
	adds r0, r2, #0
	adds r0, #0x39
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
_08020242:
	adds r3, #1
	ldrh r1, [r4, #0x1a]
	cmp r3, r1
	blt _08020200
_0802024A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08020254: .4byte 0x000085E6
_08020258: .4byte 0x0000042C
_0802025C: .4byte FUN_08020734

	thumb_func_start FUN_08020260
FUN_08020260: @ 0x08020260
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	ldr r0, _0802030C @ =0x000085E6
	bl FUN_08230e70
	adds r5, r0, #0
	cmp r5, #0
	beq _08020302
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _08020302
	bl Script_GetValue
	adds r7, r0, #0
	movs r2, #0
	movs r4, #0
	movs r6, #0
	ldrh r3, [r5, #0x1a]
	cmp r6, r3
	bge _080202A4
	ldr r1, _08020310 @ =0x0000042C
	adds r0, r5, r1
	ldr r1, [r0]
_08020292:
	ldrh r0, [r1, #0x34]
	cmp r0, r7
	bne _0802029C
	adds r4, #1
	adds r6, r2, #0
_0802029C:
	adds r1, #0x8c
	adds r2, #1
	cmp r2, r3
	blt _08020292
_080202A4:
	cmp r4, #0
	beq _08020302
	cmp r4, #1
	bgt _08020302
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08020302
	mov r0, sp
	bl FUN_0823167c
	ldr r0, _08020310 @ =0x0000042C
	adds r5, r5, r0
	ldr r0, [r5]
	movs r1, #0x8c
	adds r4, r6, #0
	muls r4, r1, r4
	adds r0, r4, r0
	movs r1, #0x1c
	ldrsh r2, [r0, r1]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	ldr r0, [r5]
	adds r0, r4, r0
	movs r1, #0x1e
	ldrsh r2, [r0, r1]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	ldr r0, [r5]
	adds r4, r4, r0
	movs r0, #0x20
	ldrsh r2, [r4, r0]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
_08020302:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802030C: .4byte 0x000085E6
_08020310: .4byte 0x0000042C

	thumb_func_start FUN_08020314
FUN_08020314: @ 0x08020314
	push {r4, lr}
	ldr r0, _08020338 @ =0x000085E6
	bl FUN_08230e70
	adds r4, r0, #0
	cmp r4, #0
	beq _08020332
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _08020332
	bl Script_GetValue
	strh r0, [r4, #0x2e]
_08020332:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08020338: .4byte 0x000085E6

	thumb_func_start FUN_0802033c
FUN_0802033c: @ 0x0802033C
	push {lr}
	ldr r0, _08020354 @ =0x000085E6
	bl FUN_08230e70
	adds r1, r0, #0
	cmp r1, #0
	beq _0802034E
	movs r0, #0
	strh r0, [r1, #0x2e]
_0802034E:
	pop {r0}
	bx r0
	.align 2, 0
_08020354: .4byte 0x000085E6

	thumb_func_start FUN_08020358
FUN_08020358: @ 0x08020358
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08020368 @ =0x000085E6
	bl FUN_08230e70
	cmp r0, #0
	bne _08020370
	b _08020396
	.align 2, 0
_08020368: .4byte 0x000085E6
_0802036C:
	movs r0, #1
	b _08020398
_08020370:
	movs r2, #0
	ldrh r3, [r0, #0x1a]
	cmp r2, r3
	bge _08020396
	ldr r1, _080203A0 @ =0x0000042C
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x3c
_08020382:
	ldrb r0, [r1, #4]
	cmp r0, #2
	bne _0802038E
	ldrh r0, [r1]
	cmp r0, r4
	beq _0802036C
_0802038E:
	adds r1, #0x8c
	adds r2, #1
	cmp r2, r3
	blt _08020382
_08020396:
	movs r0, #0
_08020398:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080203A0: .4byte 0x0000042C

	thumb_func_start FUN_080203a4
FUN_080203a4: @ 0x080203A4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r6, r1, #0
	adds r0, r6, #0
	adds r0, #0x68
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080203DA
	cmp r1, #0
	blt _080203DA
	ldr r0, _080203E0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080203DA
	ldr r0, _080203E4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080203E8
_080203DA:
	movs r1, #0
	b _080203F6
	.align 2, 0
_080203E0: .4byte 0x030046A8
_080203E4: .4byte 0x030046AC
_080203E8:
	ldr r0, _0802040C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_080203F6:
	adds r0, r6, #0
	adds r0, #0x38
	ldrb r2, [r0]
	mov sb, r0
	cmp r2, #1
	beq _08020426
	cmp r2, #1
	bgt _08020410
	cmp r2, #0
	beq _0802041A
	b _08020460
	.align 2, 0
_0802040C: .4byte 0x030046A4
_08020410:
	cmp r2, #2
	beq _0802043C
	cmp r2, #3
	beq _08020448
	b _08020460
_0802041A:
	subs r0, r1, #1
	strh r0, [r6, #0x3c]
	strh r1, [r6, #0x3e]
	adds r1, r6, #0
	adds r1, #0x6c
	b _0802045A
_08020426:
	ldr r0, _08020438 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r1, r0
	strh r0, [r6, #0x3c]
	strh r1, [r6, #0x3e]
	b _08020456
	.align 2, 0
_08020438: .4byte 0x030046A4
_0802043C:
	strh r1, [r6, #0x3c]
	subs r0, r1, #1
	strh r0, [r6, #0x3e]
	adds r1, r6, #0
	adds r1, #0x6c
	b _0802045A
_08020448:
	strh r1, [r6, #0x3c]
	ldr r0, _08020474 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r1, r0
	strh r0, [r6, #0x3e]
_08020456:
	adds r1, r6, #0
	adds r1, #0x68
_0802045A:
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
_08020460:
	ldrh r4, [r6, #0x3c]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08020478
	adds r0, #4
	b _08020484
	.align 2, 0
_08020474: .4byte 0x030046A4
_08020478:
	ldr r0, _080204BC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08020484:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	adds r4, r6, #0
	adds r4, #0x3b
	movs r5, #0
	strb r0, [r4]
	ldr r0, [r6, #0x2c]
	ldrh r1, [r6, #0x3c]
	ldrb r3, [r4]
	movs r2, #0xff
	str r2, [sp]
	str r5, [sp, #4]
	movs r2, #0
	bl FUN_08234270
	adds r5, r6, #0
	adds r0, r6, #0
	adds r0, #0x40
	ldrb r0, [r0]
	mov r8, r4
	cmp r0, #0xf
	bhi _0802057E
	lsls r0, r0, #2
	ldr r1, _080204C0 @ =_080204C4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080204BC: .4byte 0x030046A4
_080204C0: .4byte _080204C4
_080204C4: @ jump table
	.4byte _08020504 @ case 0
	.4byte _0802057E @ case 1
	.4byte _0802057E @ case 2
	.4byte _08020504 @ case 3
	.4byte _08020510 @ case 4
	.4byte _08020520 @ case 5
	.4byte _0802054C @ case 6
	.4byte _0802054C @ case 7
	.4byte _0802057E @ case 8
	.4byte _0802057E @ case 9
	.4byte _0802057E @ case 10
	.4byte _0802057E @ case 11
	.4byte _0802057E @ case 12
	.4byte _0802057E @ case 13
	.4byte _0802057E @ case 14
	.4byte _08020566 @ case 15
_08020504:
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, #0x3c
	b _0802055A
_08020510:
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r1, r1, r0
	b _0802055A
_08020520:
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	movs r4, #0x9b
	lsls r4, r4, #2
	adds r1, r1, r4
	adds r1, r7, r1
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822a470
	ldr r1, [r6, #0x4c]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r0, r7, r0
	movs r1, #0x2b
	bl FUN_0822b20c
	b _0802057E
_0802054C:
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	movs r3, #0xbe
	lsls r3, r3, #2
	adds r1, r1, r3
_0802055A:
	adds r1, r7, r1
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822a470
	b _0802057E
_08020566:
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	movs r0, #0xe1
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r1, r7, r1
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822a470
_0802057E:
	ldr r0, [r6, #0x78]
	ldr r1, [r6, #0x7c]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	mov r3, sb
	ldrb r1, [r3]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080205A0
	ldrh r0, [r5, #0x1c]
	subs r0, #0x20
	strh r0, [r5, #0x1c]
	ldrh r0, [r5, #0x20]
	adds r0, #0x20
	strh r0, [r5, #0x20]
	b _080205B4
_080205A0:
	ldrh r0, [r5, #0x1c]
	adds r0, #0x20
	strh r0, [r5, #0x1c]
	ldrh r0, [r5, #0x20]
	subs r0, #0x20
	strh r0, [r5, #0x20]
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	str r0, [r5]
_080205B4:
	ldr r0, [r5, #0x1c]
	ldr r1, [r5, #0x20]
	str r0, [r6, #0x70]
	str r1, [r6, #0x74]
	adds r0, r6, #0
	adds r0, #0x37
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	bne _080205DC
	ldr r0, _080205D8 @ =0x080206B1
	str r0, [r6, #0x30]
	adds r0, r6, #0
	adds r0, #0x39
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	b _0802060C
	.align 2, 0
_080205D8: .4byte 0x080206B1
_080205DC:
	cmp r1, #1
	bne _080205FC
	ldr r0, _080205F8 @ =0x080206B5
	str r0, [r6, #0x30]
	movs r0, #2
	adds r2, r6, #0
	adds r2, #0x39
	movs r1, #0
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0x3a
	strb r1, [r0]
	b _0802060C
	.align 2, 0
_080205F8: .4byte 0x080206B5
_080205FC:
	ldr r0, _0802063C @ =0x080206B1
	str r0, [r6, #0x30]
	adds r1, r6, #0
	adds r1, #0x39
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
_0802060C:
	ldrb r0, [r3]
	cmp r0, #0
	bne _08020644
	ldr r2, [r6, #0x2c]
	ldrh r1, [r2, #6]
	ldr r0, _08020640 @ =0x0000FFFD
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x2c]
	ldrh r1, [r2, #6]
	movs r0, #3
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x2c]
	ldrb r0, [r2, #4]
	movs r1, #0xf0
	ands r1, r0
	mov r3, r8
	ldrb r0, [r3]
	adds r0, #1
	orrs r1, r0
	strb r1, [r2, #4]
	b _0802066C
	.align 2, 0
_0802063C: .4byte 0x080206B1
_08020640: .4byte 0x0000FFFD
_08020644:
	cmp r0, #1
	bne _0802066C
	ldr r2, [r6, #0x2c]
	ldrh r1, [r2, #6]
	ldr r0, _0802067C @ =0x0000FFFC
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x2c]
	ldrh r1, [r2, #6]
	movs r0, #2
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x2c]
	ldrb r1, [r2, #4]
	movs r0, #0xf0
	ands r0, r1
	mov r3, r8
	ldrb r1, [r3]
	orrs r0, r1
	strb r0, [r2, #4]
_0802066C:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802067C: .4byte 0x0000FFFC

	thumb_func_start FUN_08020680
FUN_08020680: @ 0x08020680
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2e]
	cmp r0, #0
	beq _080206AA
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_0801faa8
	cmp r0, #0
	bne _080206AA
	ldrb r0, [r4, #0x1c]
	lsls r0, r0, #1
	adds r1, r4, #0
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r4, #0x2e]
	strh r0, [r1]
	ldrb r0, [r4, #0x1c]
	adds r0, #1
	strb r0, [r4, #0x1c]
_080206AA:
	pop {r4}
	pop {r0}
	bx r0
_080206B0:
	.byte 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080206b8
FUN_080206b8: @ 0x080206B8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x38]
	ldr r1, _0802072C @ =0x00FFFF00
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	bne _080206D0
	movs r0, #0xcf
	bl PlaySound_0824078c
_080206D0:
	adds r2, r4, #0
	adds r2, #0x3a
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _08020726
	adds r1, r4, #0
	adds r1, #0x39
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	movs r0, #0
	strb r0, [r2]
	ldrb r0, [r1]
	cmp r0, #0
	bne _08020726
	subs r1, #2
	strb r0, [r1]
	ldr r2, [r4, #0x2c]
	ldrh r1, [r2, #6]
	movs r0, #2
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r4, #0x2c]
	ldrh r1, [r2, #6]
	movs r0, #3
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r4, #0x2c]
	ldrb r0, [r2, #4]
	movs r1, #0xf0
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	adds r0, #1
	orrs r1, r0
	strb r1, [r2, #4]
	ldr r0, _08020730 @ =0x080206B1
	str r0, [r4, #0x30]
_08020726:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802072C: .4byte 0x00FFFF00
_08020730: .4byte 0x080206B1

	thumb_func_start FUN_08020734
FUN_08020734: @ 0x08020734
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x38]
	ldr r1, _080207A4 @ =0x00FFFF00
	ands r0, r1
	cmp r0, #0
	bne _0802076E
	movs r0, #0xce
	bl PlaySound_0824078c
	ldr r2, [r4, #0x2c]
	ldrh r1, [r2, #6]
	ldr r0, _080207A8 @ =0x0000FFFC
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r4, #0x2c]
	ldrh r1, [r2, #6]
	movs r0, #2
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r4, #0x2c]
	ldrb r1, [r2, #4]
	movs r0, #0xf0
	ands r0, r1
	adds r1, r4, #0
	adds r1, #0x3b
	ldrb r1, [r1]
	orrs r0, r1
	strb r0, [r2, #4]
_0802076E:
	adds r2, r4, #0
	adds r2, #0x3a
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _0802079E
	adds r1, r4, #0
	adds r1, #0x39
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0
	strb r0, [r2]
	ldrb r0, [r1]
	cmp r0, #1
	bls _0802079E
	movs r0, #1
	subs r1, #2
	strb r0, [r1]
	ldr r0, _080207AC @ =0x080206B5
	str r0, [r4, #0x30]
_0802079E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080207A4: .4byte 0x00FFFF00
_080207A8: .4byte 0x0000FFFC
_080207AC: .4byte 0x080206B5

	thumb_func_start FUN_080207b0
FUN_080207b0: @ 0x080207B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp, #8]
	adds r7, r1, #0
	adds r0, r7, #0
	adds r0, #0x68
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080207E8
	cmp r1, #0
	blt _080207E8
	ldr r0, _080207EC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080207E8
	ldr r0, _080207F0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080207F4
_080207E8:
	movs r3, #0
	b _08020802
	.align 2, 0
_080207EC: .4byte 0x030046A8
_080207F0: .4byte 0x030046AC
_080207F4:
	ldr r0, _08020820 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r2
_08020802:
	adds r0, r7, #0
	adds r0, #0x38
	ldrb r1, [r0]
	mov sl, r0
	adds r5, r7, #0
	adds r5, #0x84
	cmp r1, #9
	bls _08020814
	b _08020940
_08020814:
	lsls r0, r1, #2
	ldr r1, _08020824 @ =_08020828
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08020820: .4byte 0x030046A4
_08020824: .4byte _08020828
_08020828: @ jump table
	.4byte _08020850 @ case 0
	.4byte _08020864 @ case 1
	.4byte _08020878 @ case 2
	.4byte _0802088E @ case 3
	.4byte _080208B0 @ case 4
	.4byte _080208BE @ case 5
	.4byte _080208D4 @ case 6
	.4byte _080208E8 @ case 7
	.4byte _08020910 @ case 8
	.4byte _0802091E @ case 9
_08020850:
	subs r0, r3, #1
	strh r0, [r7, #0x3c]
	strh r3, [r7, #0x3e]
	adds r1, r7, #0
	adds r1, #0x6c
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	adds r1, #0x18
	b _08020902
_08020864:
	ldr r0, _08020874 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r3, r0
	strh r0, [r7, #0x3c]
	strh r3, [r7, #0x3e]
	b _080208F6
	.align 2, 0
_08020874: .4byte 0x030046A4
_08020878:
	strh r3, [r7, #0x3c]
	subs r0, r3, #1
	strh r0, [r7, #0x3e]
	adds r1, r7, #0
	adds r1, #0x6c
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	adds r1, #0x18
	movs r0, #2
	b _08020904
_0802088E:
	strh r3, [r7, #0x3c]
	ldr r0, _080208AC @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r3, r0
	strh r0, [r7, #0x3e]
	adds r1, r7, #0
	adds r1, #0x68
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	adds r1, #0x1c
	movs r0, #2
	b _08020904
	.align 2, 0
_080208AC: .4byte 0x030046A4
_080208B0:
	subs r0, r3, #1
	movs r2, #0
	strh r0, [r7, #0x3c]
	strh r3, [r7, #0x3e]
	adds r1, r7, #0
	adds r1, #0x6c
	b _08020932
_080208BE:
	ldr r0, _080208D0 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r3, r0
	movs r2, #0
	strh r0, [r7, #0x3c]
	strh r3, [r7, #0x3e]
	b _0802092E
	.align 2, 0
_080208D0: .4byte 0x030046A4
_080208D4:
	strh r3, [r7, #0x3c]
	subs r0, r3, #1
	strh r0, [r7, #0x3e]
	adds r1, r7, #0
	adds r1, #0x6c
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	adds r1, #0x18
	b _08020902
_080208E8:
	strh r3, [r7, #0x3c]
	ldr r0, _0802090C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r3, r0
	strh r0, [r7, #0x3e]
_080208F6:
	adds r1, r7, #0
	adds r1, #0x68
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	adds r1, #0x1c
_08020902:
	movs r0, #1
_08020904:
	str r0, [r1]
	adds r5, r1, #0
	b _08020940
	.align 2, 0
_0802090C: .4byte 0x030046A4
_08020910:
	movs r2, #0
	strh r3, [r7, #0x3c]
	subs r0, r3, #1
	strh r0, [r7, #0x3e]
	adds r1, r7, #0
	adds r1, #0x6c
	b _08020932
_0802091E:
	movs r2, #0
	strh r3, [r7, #0x3c]
	ldr r0, _08020954 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r3, r0
	strh r0, [r7, #0x3e]
_0802092E:
	adds r1, r7, #0
	adds r1, #0x68
_08020932:
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x84
	str r2, [r0]
	adds r5, r0, #0
_08020940:
	ldrh r4, [r7, #0x3c]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08020958
	adds r0, #4
	b _08020964
	.align 2, 0
_08020954: .4byte 0x030046A4
_08020958:
	ldr r0, _080209D0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08020964:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	adds r4, r7, #0
	adds r4, #0x3b
	movs r1, #0
	mov sb, r1
	strb r0, [r4]
	ldr r0, [r7, #0x2c]
	ldrh r1, [r7, #0x3c]
	ldrb r3, [r4]
	movs r2, #0xff
	str r2, [sp]
	mov r2, sb
	str r2, [sp, #4]
	movs r2, #0
	bl FUN_08234270
	ldrb r0, [r5]
	movs r3, #0x39
	adds r3, r3, r7
	mov r8, r3
	strb r0, [r3]
	adds r6, r7, #0
	adds r6, #0x3a
	mov r0, sb
	strb r0, [r6]
	mov sb, r7
	ldr r0, [r7, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, #0xc8
	ldr r2, [sp, #8]
	adds r1, r2, r1
	adds r0, r7, #0
	movs r2, #0
	bl FUN_0822a470
	ldr r0, [r7, #0x78]
	ldr r1, [r7, #0x7c]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	mov r3, sl
	ldrb r1, [r3]
	movs r0, #1
	ands r0, r1
	mov ip, r4
	cmp r0, #0
	bne _080209D4
	ldrh r0, [r7, #0x20]
	adds r0, #0x80
	strh r0, [r7, #0x20]
	b _080209E2
	.align 2, 0
_080209D0: .4byte 0x030046A4
_080209D4:
	ldrh r0, [r7, #0x1c]
	adds r0, #0x80
	strh r0, [r7, #0x1c]
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	str r0, [r7]
_080209E2:
	mov r4, sb
	ldr r0, [r4, #0x1c]
	ldr r1, [r4, #0x20]
	str r0, [r7, #0x70]
	str r1, [r7, #0x74]
	adds r0, r7, #0
	adds r0, #0x37
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #0
	beq _08020A04
	cmp r1, #1
	bne _08020A04
	ldr r0, _08020A00 @ =FUN_08020cd8
	b _08020A06
	.align 2, 0
_08020A00: .4byte FUN_08020cd8
_08020A04:
	ldr r0, _08020A64 @ =FUN_08020d10
_08020A06:
	str r0, [r7, #0x30]
	adds r2, r4, #0
	ldrb r3, [r2]
	cmp r3, #0
	bne _08020A70
	adds r0, r7, #0
	adds r0, #0x82
	movs r1, #0
	strh r3, [r0]
	movs r0, #1
	strb r0, [r2]
	ldr r0, _08020A64 @ =FUN_08020d10
	str r0, [r7, #0x30]
	ldrb r0, [r5]
	mov r2, r8
	strb r0, [r2]
	strb r1, [r6]
	ldr r2, [r7, #0x2c]
	ldrh r1, [r2, #6]
	ldr r0, _08020A68 @ =0x0000FFFD
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r7, #0x2c]
	ldrh r0, [r2, #6]
	movs r1, #3
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r7, #0x2c]
	ldrh r1, [r2]
	ldr r0, _08020A6C @ =0x0000FFFE
	ands r0, r1
	strh r0, [r2]
	ldr r2, [r7, #0x2c]
	ldrb r0, [r2, #4]
	movs r1, #0xf0
	ands r1, r0
	mov r4, ip
	ldrb r0, [r4]
	adds r0, #1
	orrs r1, r0
	strb r1, [r2, #4]
	adds r0, r7, #0
	adds r0, #0x80
	strh r3, [r0]
	subs r0, #6
	ldrh r0, [r0]
	b _08020ACE
	.align 2, 0
_08020A64: .4byte FUN_08020d10
_08020A68: .4byte 0x0000FFFD
_08020A6C: .4byte 0x0000FFFE
_08020A70:
	cmp r3, #1
	bne _08020AD4
	adds r2, r7, #0
	adds r2, #0x82
	movs r1, #0
	movs r0, #0
	strh r0, [r2]
	strb r1, [r4]
	ldr r0, _08020AF0 @ =FUN_08020cd8
	str r0, [r7, #0x30]
	mov r0, r8
	strb r1, [r0]
	strb r1, [r6]
	ldr r2, [r7, #0x2c]
	ldrh r1, [r2, #6]
	ldr r0, _08020AF4 @ =0x0000FFFC
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r7, #0x2c]
	ldrh r0, [r2, #6]
	movs r1, #2
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r7, #0x2c]
	ldrh r0, [r2]
	movs r1, #1
	orrs r0, r1
	strh r0, [r2]
	ldr r2, [r7, #0x2c]
	ldrb r1, [r2, #4]
	movs r0, #0xf0
	ands r0, r1
	mov r3, ip
	ldrb r1, [r3]
	orrs r0, r1
	strb r0, [r2, #4]
	adds r2, r7, #0
	adds r2, #0x88
	ldrh r1, [r2]
	adds r0, r7, #0
	adds r0, #0x80
	strh r1, [r0]
	adds r1, r7, #0
	adds r1, #0x7a
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
_08020ACE:
	adds r1, r7, #0
	adds r1, #0x72
	strh r0, [r1]
_08020AD4:
	movs r0, #0
	str r0, [r7, #0x60]
	str r0, [r7, #0x64]
	movs r1, #0
	bl FUN_080dbe54
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08020AF0: .4byte FUN_08020cd8
_08020AF4: .4byte 0x0000FFFC

	thumb_func_start FUN_08020af8
FUN_08020af8: @ 0x08020AF8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xa9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r1, r4, #0
	adds r1, #0x39
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	movs r0, #2
	subs r1, #3
	strb r0, [r1]
	ldr r0, _08020B20 @ =FUN_08020b88
	str r0, [r4, #0x30]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08020B20: .4byte FUN_08020b88

	thumb_func_start FUN_08020b24
FUN_08020b24: @ 0x08020B24
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xa9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r1, r4, #0
	adds r1, #0x39
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	ldr r2, [r4, #0x2c]
	ldrh r1, [r2, #6]
	movs r0, #2
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r1, [r4, #0x2c]
	ldrh r0, [r1, #6]
	movs r2, #3
	orrs r0, r2
	strh r0, [r1, #6]
	adds r0, r4, #0
	adds r0, #0x37
	strb r2, [r0]
	ldr r2, [r4, #0x2c]
	ldrb r0, [r2, #4]
	movs r1, #0xf0
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	adds r0, #1
	orrs r1, r0
	strb r1, [r2, #4]
	ldr r2, [r4, #0x2c]
	ldrh r1, [r2]
	ldr r0, _08020B80 @ =0x0000FFFE
	ands r0, r1
	strh r0, [r2]
	ldr r0, _08020B84 @ =FUN_08020c1c
	str r0, [r4, #0x30]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08020B80: .4byte 0x0000FFFE
_08020B84: .4byte FUN_08020c1c

	thumb_func_start FUN_08020b88
FUN_08020b88: @ 0x08020B88
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x80
	ldrh r0, [r5]
	adds r0, #0xf
	strh r0, [r5]
	adds r1, r4, #0
	adds r1, #0x88
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r1, [r1, r3]
	cmp r0, r1
	ble _08020BFC
	strh r2, [r5]
	movs r0, #0xa9
	lsls r0, r0, #1
	bl sound_08240740
	movs r0, #0xaa
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r1, r4, #0
	adds r1, #0x82
	movs r0, #0x1e
	strh r0, [r1]
	subs r1, #0x4b
	movs r0, #0
	strb r0, [r1]
	ldr r2, [r4, #0x2c]
	ldrh r1, [r2, #6]
	ldr r0, _08020C14 @ =0x0000FFFC
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r4, #0x2c]
	ldrh r0, [r2, #6]
	movs r1, #2
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r4, #0x2c]
	ldrb r1, [r2, #4]
	movs r0, #0xf0
	ands r0, r1
	adds r1, r4, #0
	adds r1, #0x3b
	ldrb r1, [r1]
	orrs r0, r1
	strb r0, [r2, #4]
	ldr r2, [r4, #0x2c]
	ldrh r0, [r2]
	movs r1, #1
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _08020C18 @ =FUN_08020cd8
	str r0, [r4, #0x30]
_08020BFC:
	adds r0, r4, #0
	adds r0, #0x7a
	ldrh r0, [r0]
	ldrh r5, [r5]
	adds r0, r0, r5
	adds r1, r4, #0
	adds r1, #0x72
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08020C14: .4byte 0x0000FFFC
_08020C18: .4byte FUN_08020cd8

	thumb_func_start FUN_08020c1c
FUN_08020c1c: @ 0x08020C1C
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x80
	ldrh r0, [r1]
	subs r0, #0xf
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08020CBC
	strh r5, [r1]
	movs r0, #0xa9
	lsls r0, r0, #1
	bl sound_08240740
	ldr r0, _08020C98 @ =0x00000153
	bl PlaySound_082406e0
	adds r1, r4, #0
	adds r1, #0x82
	movs r0, #0x1e
	strh r0, [r1]
	movs r2, #1
	adds r0, r4, #0
	adds r0, #0x37
	strb r2, [r0]
	adds r0, #0x4d
	ldrb r0, [r0]
	subs r1, #0x49
	strb r0, [r1]
	adds r1, #1
	movs r0, #0
	strb r0, [r1]
	ldr r0, _08020C9C @ =FUN_08020d10
	str r0, [r4, #0x30]
	ldr r1, _08020CA0 @ =0xFFFF0000
	add r3, sp, #8
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
	str r5, [sp, #8]
	adds r0, r4, #0
	adds r0, #0x38
	ldrb r0, [r0]
	ands r2, r0
	cmp r2, #0
	beq _08020CA4
	movs r0, #0x80
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r0, #0x70
	movs r1, #2
	str r1, [sp]
	str r5, [sp, #4]
	movs r1, #0
	adds r2, r3, #0
	movs r3, #5
	bl FUN_080dbd08
	b _08020CBC
	.align 2, 0
_08020C98: .4byte 0x00000153
_08020C9C: .4byte FUN_08020d10
_08020CA0: .4byte 0xFFFF0000
_08020CA4:
	movs r0, #0x80
	strh r0, [r3, #4]
	adds r0, r4, #0
	adds r0, #0x70
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #0
	add r2, sp, #8
	movs r3, #5
	bl FUN_080dbd08
_08020CBC:
	adds r0, r4, #0
	adds r0, #0x80
	adds r1, r4, #0
	adds r1, #0x7a
	ldrh r1, [r1]
	ldrh r0, [r0]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x72
	strh r1, [r0]
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08020cd8
FUN_08020cd8: @ 0x08020CD8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x82
	movs r0, #0
	ldrsh r6, [r4, r0]
	cmp r6, #0
	beq _08020CF6
	adds r0, r6, #0
	bl FUN_0823b9cc
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	b _08020D04
_08020CF6:
	ldr r0, [r5, #0x60]
	cmp r0, #0
	beq _08020D04
	movs r1, #0
	bl Script_ExecById
	str r6, [r5, #0x60]
_08020D04:
	movs r0, #2
	strb r0, [r5, #7]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08020d10
FUN_08020d10: @ 0x08020D10
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x82
	movs r0, #0
	ldrsh r6, [r4, r0]
	cmp r6, #0
	beq _08020D2E
	adds r0, r6, #0
	bl FUN_0823b9cc
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	b _08020D3C
_08020D2E:
	ldr r0, [r5, #0x64]
	cmp r0, #0
	beq _08020D3C
	movs r1, #0
	bl Script_ExecById
	str r6, [r5, #0x64]
_08020D3C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08020d44
FUN_08020d44: @ 0x08020D44
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r6, r1, #0
	adds r0, r6, #0
	adds r0, #0x68
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08020D7A
	cmp r1, #0
	blt _08020D7A
	ldr r0, _08020D80 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08020D7A
	ldr r0, _08020D84 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08020D88
_08020D7A:
	movs r1, #0
	b _08020D96
	.align 2, 0
_08020D80: .4byte 0x030046A8
_08020D84: .4byte 0x030046AC
_08020D88:
	ldr r0, _08020DAC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_08020D96:
	adds r0, r6, #0
	adds r0, #0x38
	ldrb r2, [r0]
	mov sb, r0
	cmp r2, #1
	beq _08020DC6
	cmp r2, #1
	bgt _08020DB0
	cmp r2, #0
	beq _08020DBA
	b _08020E00
	.align 2, 0
_08020DAC: .4byte 0x030046A4
_08020DB0:
	cmp r2, #2
	beq _08020DDC
	cmp r2, #3
	beq _08020DE8
	b _08020E00
_08020DBA:
	subs r0, r1, #1
	strh r0, [r6, #0x3c]
	strh r1, [r6, #0x3e]
	adds r1, r6, #0
	adds r1, #0x6c
	b _08020DFA
_08020DC6:
	ldr r0, _08020DD8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r1, r0
	strh r0, [r6, #0x3c]
	strh r1, [r6, #0x3e]
	b _08020DF6
	.align 2, 0
_08020DD8: .4byte 0x030046A4
_08020DDC:
	strh r1, [r6, #0x3c]
	subs r0, r1, #1
	strh r0, [r6, #0x3e]
	adds r1, r6, #0
	adds r1, #0x6c
	b _08020DFA
_08020DE8:
	strh r1, [r6, #0x3c]
	ldr r0, _08020E14 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	ldrh r0, [r0, #4]
	subs r0, r1, r0
	strh r0, [r6, #0x3e]
_08020DF6:
	adds r1, r6, #0
	adds r1, #0x68
_08020DFA:
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
_08020E00:
	ldrh r4, [r6, #0x3c]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08020E18
	adds r0, #4
	b _08020E24
	.align 2, 0
_08020E14: .4byte 0x030046A4
_08020E18:
	ldr r0, _08020E60 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08020E24:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	adds r4, r6, #0
	adds r4, #0x3b
	movs r5, #0
	strb r0, [r4]
	ldr r0, [r6, #0x2c]
	ldrh r1, [r6, #0x3c]
	ldrb r3, [r4]
	movs r2, #0xff
	str r2, [sp]
	str r5, [sp, #4]
	movs r2, #0
	bl FUN_08234270
	adds r5, r6, #0
	ldr r0, [r7, #0x34]
	mov r8, r4
	cmp r0, #0
	bne _08020E9E
	adds r0, r6, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #2
	beq _08020E64
	cmp r0, #0x10
	beq _08020E8A
	b _08020F8A
	.align 2, 0
_08020E60: .4byte 0x030046A4
_08020E64:
	ldr r1, [r6, #0x4c]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	movs r4, #0xaa
	lsls r4, r4, #1
	adds r0, r0, r4
	adds r0, r7, r0
	movs r1, #0xa7
	bl FUN_0822b20c
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	adds r1, r7, r1
	adds r0, r6, #0
	b _08020F4E
_08020E8A:
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r1, r1, r0
	adds r1, r7, r1
	adds r0, r6, #0
	b _08020F4E
_08020E9E:
	adds r0, r6, #0
	adds r0, #0x45
	ldrb r1, [r0]
	adds r2, r0, #0
	cmp r1, #7
	bhi _08020F8A
	lsls r0, r1, #2
	ldr r1, _08020EB4 @ =_08020EB8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08020EB4: .4byte _08020EB8
_08020EB8: @ jump table
	.4byte _08020ED8 @ case 0
	.4byte _08020EFE @ case 1
	.4byte _08020F06 @ case 2
	.4byte _08020F10 @ case 3
	.4byte _08020F18 @ case 4
	.4byte _08020F20 @ case 5
	.4byte _08020F28 @ case 6
	.4byte _08020F5C @ case 7
_08020ED8:
	ldr r1, [r6, #0x4c]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	movs r4, #0xaa
	lsls r4, r4, #1
	adds r0, r0, r4
	adds r0, r7, r0
	ldrb r1, [r2]
	adds r1, #0xa7
	bl FUN_0822b20c
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	adds r1, r7, r1
	b _08020F4C
_08020EFE:
	movs r3, #0x82
	lsls r3, r3, #3
	adds r4, r7, r3
	b _08020F2C
_08020F06:
	ldr r0, _08020F0C @ =0x00000414
	b _08020F2A
	.align 2, 0
_08020F0C: .4byte 0x00000414
_08020F10:
	movs r3, #0x83
	lsls r3, r3, #3
	adds r4, r7, r3
	b _08020F2C
_08020F18:
	ldr r0, _08020F1C @ =0x0000041C
	b _08020F2A
	.align 2, 0
_08020F1C: .4byte 0x0000041C
_08020F20:
	movs r3, #0x84
	lsls r3, r3, #3
	adds r4, r7, r3
	b _08020F2C
_08020F28:
	ldr r0, _08020F58 @ =0x00000424
_08020F2A:
	adds r4, r7, r0
_08020F2C:
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	ldr r0, [r4]
	adds r0, r0, r1
	ldrb r1, [r2]
	adds r1, #0xa7
	bl FUN_0822b20c
	ldr r1, [r6, #0x4c]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [r4]
	adds r1, r1, r0
_08020F4C:
	adds r0, r5, #0
_08020F4E:
	movs r2, #0
	bl FUN_0822a470
	b _08020F8A
	.align 2, 0
_08020F58: .4byte 0x00000424
_08020F5C:
	movs r3, #0x85
	lsls r3, r3, #3
	adds r4, r7, r3
	ldr r0, [r6, #0x4c]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	ldr r0, [r4]
	adds r0, r0, r1
	ldrb r1, [r2]
	adds r1, #0xa7
	bl FUN_0822b20c
	ldr r1, [r6, #0x4c]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [r4]
	adds r1, r1, r0
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822a470
_08020F8A:
	ldr r0, [r6, #0x78]
	ldr r1, [r6, #0x7c]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	mov r0, sb
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08020FAC
	ldrh r0, [r5, #0x1c]
	subs r0, #0x20
	strh r0, [r5, #0x1c]
	ldrh r0, [r5, #0x20]
	adds r0, #0x20
	strh r0, [r5, #0x20]
	b _08020FC0
_08020FAC:
	ldrh r0, [r5, #0x1c]
	adds r0, #0x20
	strh r0, [r5, #0x1c]
	ldrh r0, [r5, #0x20]
	subs r0, #0x20
	strh r0, [r5, #0x20]
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	str r0, [r5]
_08020FC0:
	ldr r0, [r5, #0x1c]
	ldr r1, [r5, #0x20]
	str r0, [r6, #0x70]
	str r1, [r6, #0x74]
	adds r0, r6, #0
	adds r0, #0x37
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	bne _08020FE8
	ldr r0, _08020FE4 @ =0x0802108D
	str r0, [r6, #0x30]
	adds r0, r6, #0
	adds r0, #0x39
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	b _08021018
	.align 2, 0
_08020FE4: .4byte 0x0802108D
_08020FE8:
	cmp r1, #1
	bne _08021008
	ldr r0, _08021004 @ =0x08021091
	str r0, [r6, #0x30]
	movs r0, #2
	adds r2, r6, #0
	adds r2, #0x39
	movs r1, #0
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0x3a
	strb r1, [r0]
	b _08021018
	.align 2, 0
_08021004: .4byte 0x08021091
_08021008:
	ldr r0, _08021048 @ =0x0802108D
	str r0, [r6, #0x30]
	adds r1, r6, #0
	adds r1, #0x39
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
_08021018:
	ldrb r0, [r3]
	cmp r0, #0
	bne _08021050
	ldr r2, [r6, #0x2c]
	ldrh r1, [r2, #6]
	ldr r0, _0802104C @ =0x0000FFFD
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x2c]
	ldrh r1, [r2, #6]
	movs r0, #3
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x2c]
	ldrb r0, [r2, #4]
	movs r1, #0xf0
	ands r1, r0
	mov r3, r8
	ldrb r0, [r3]
	adds r0, #1
	orrs r1, r0
	strb r1, [r2, #4]
	b _08021078
	.align 2, 0
_08021048: .4byte 0x0802108D
_0802104C: .4byte 0x0000FFFD
_08021050:
	cmp r0, #1
	bne _08021078
	ldr r2, [r6, #0x2c]
	ldrh r1, [r2, #6]
	ldr r0, _08021088 @ =0x0000FFFC
	ands r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x2c]
	ldrh r1, [r2, #6]
	movs r0, #2
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, [r6, #0x2c]
	ldrb r1, [r2, #4]
	movs r0, #0xf0
	ands r0, r1
	mov r3, r8
	ldrb r1, [r3]
	orrs r0, r1
	strb r0, [r2, #4]
_08021078:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021088: .4byte 0x0000FFFC
_0802108C:
	.byte 0x70, 0x47, 0x00, 0x00
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_08021094
FUN_08021094: @ 0x08021094
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	mov r8, r0
	ldrh r0, [r0, #0x1a]
	cmp r0, #0
	bne _080210AC
	bl _08021B16
_080210AC:
	movs r0, #0
	mov sl, r0
	mov r2, r8
	adds r2, #0x38
	mov r1, r8
	ldrb r1, [r1, #0x1c]
	cmp sl, r1
	bge _080210D2
	mov r1, r8
	adds r1, #0x1e
_080210C0:
	ldrh r0, [r1]
	strh r0, [r1, #8]
	adds r1, #2
	movs r3, #1
	add sl, r3
	mov r0, r8
	ldrb r0, [r0, #0x1c]
	cmp sl, r0
	blt _080210C0
_080210D2:
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	movs r1, #0
	mov r3, r8
	strb r0, [r3, #0x1d]
	strb r1, [r3, #0x1c]
	ldrh r0, [r3, #0x18]
	adds r1, r2, #0
	bl FUN_08230f94
	adds r4, r0, #0
	mov r0, r8
	ldr r5, [r0, #0x38]
	b _0802115C
_080210EE:
	ldr r0, [r5, #4]
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #5
	bhi _0802115A
	lsls r0, r1, #2
	ldr r1, _08021104 @ =_08021108
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08021104: .4byte _08021108
_08021108: @ jump table
	.4byte _08021120 @ case 0
	.4byte _0802112A @ case 1
	.4byte _08021134 @ case 2
	.4byte _0802113E @ case 3
	.4byte _08021148 @ case 4
	.4byte _08021152 @ case 5
_08021120:
	ldrh r1, [r2, #2]
	mov r0, r8
	bl FUN_0801fc88
	b _0802115A
_0802112A:
	ldrh r1, [r2, #2]
	mov r0, r8
	bl FUN_0801fd10
	b _0802115A
_08021134:
	ldrh r1, [r2, #2]
	mov r0, r8
	bl FUN_0801fd88
	b _0802115A
_0802113E:
	ldrh r1, [r2, #2]
	mov r0, r8
	bl FUN_0801fdf0
	b _0802115A
_08021148:
	ldrh r1, [r2, #2]
	mov r0, r8
	bl FUN_0801fe58
	b _0802115A
_08021152:
	ldrh r1, [r2, #2]
	mov r0, r8
	bl FUN_0801fe98
_0802115A:
	adds r5, #8
_0802115C:
	adds r0, r4, #0
	subs r4, #1
	cmp r0, #0
	bgt _080210EE
	ldr r0, _080211D0 @ =0x030046A0
	ldr r1, [r0]
	ldr r2, _080211D4 @ =0xFFFF0000
	ldrh r0, [r1, #0x30]
	str r0, [sp]
	ldrh r1, [r1, #0x34]
	mov r3, sp
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	movs r1, #0
	mov sl, r1
	mov r2, r8
	ldrh r2, [r2, #0x1a]
	cmp sl, r2
	blt _08021196
	bl _08021A74
_08021196:
	ldr r2, _080211D8 @ =0x0000042C
	add r2, r8
	movs r0, #0x8c
	mov r1, sl
	muls r1, r0, r1
	ldr r0, [r2]
	adds r7, r0, r1
	adds r0, r7, #0
	adds r0, #0x39
	ldrb r0, [r0]
	strh r0, [r7, #0x10]
	adds r0, r7, #0
	adds r0, #0x44
	ldrb r0, [r0]
	cmp r0, #0
	beq _080211F4
	adds r1, r7, #0
	adds r1, #0x42
	ldr r0, _080211D0 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _080211DC
	movs r0, #1
	b _080211DE
	.align 2, 0
_080211D0: .4byte 0x030046A0
_080211D4: .4byte 0xFFFF0000
_080211D8: .4byte 0x0000042C
_080211DC:
	movs r0, #0
_080211DE:
	cmp r0, #0
	beq _080211EC
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _080211F2
_080211EC:
	ldr r0, [r7]
	movs r1, #1
	orrs r0, r1
_080211F2:
	str r0, [r7]
_080211F4:
	adds r0, r7, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0x10
	bls _08021202
	bl _08021A64
_08021202:
	lsls r0, r0, #2
	ldr r1, _0802120C @ =_08021210
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802120C: .4byte _08021210
_08021210: @ jump table
	.4byte _08021254 @ case 0
	.4byte _08021388 @ case 1
	.4byte _08021390 @ case 2
	.4byte _08021816 @ case 3
	.4byte _08021482 @ case 4
	.4byte _080215B4 @ case 5
	.4byte _080216E8 @ case 6
	.4byte _08021816 @ case 7
	.4byte _08021390 @ case 8
	.4byte _08021390 @ case 9
	.4byte _08021390 @ case 10
	.4byte _08021390 @ case 11
	.4byte _08021390 @ case 12
	.4byte _08021390 @ case 13
	.4byte _08021390 @ case 14
	.4byte _08021840 @ case 15
	.4byte _080218E0 @ case 16
_08021254:
	adds r0, r7, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08021266
	bl _08021A64
_08021266:
	adds r0, r7, #0
	bl FUN_0801f764
	ldr r2, [r7, #0x68]
	ldr r3, [r7, #0x6c]
	ldr r0, _08021378 @ =0x030046A0
	ldr r6, [r0]
	ldrh r0, [r6, #0x30]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _0802137C @ =0xFFFF0000
	adds r1, r5, #0
	ands r1, r2
	orrs r1, r0
	asrs r4, r1, #0x10
	ldrh r0, [r6, #0x32]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _08021380 @ =0x0000FFFF
	mov ip, r0
	ands r0, r1
	orrs r0, r4
	mov ip, r0
	mov r2, ip
	ldrh r0, [r6, #0x34]
	subs r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r3
	adds r3, r5, #0
	orrs r3, r0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _08021384 @ =0x00012CC7
	cmp r1, r0
	bgt _080212F0
	mov r3, ip
	asrs r1, r3, #0x10
	cmp r1, #0
	bge _080212CA
	rsbs r1, r1, #0
_080212CA:
	cmp r1, #0xfe
	bgt _080212F0
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _080212F0
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	lsls r0, r0, #1
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r7, #0x34]
	strh r0, [r1]
	mov r2, r8
	ldrb r0, [r2, #0x1c]
	adds r0, #1
	strb r0, [r2, #0x1c]
_080212F0:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08020680
	add r6, sp, #8
	adds r0, r6, #0
	bl FUN_08086a28
	cmp r0, #0
	bne _08021306
	b _08021A64
_08021306:
	ldr r1, [r7, #0x68]
	ldr r2, [r7, #0x6c]
	ldrh r0, [r6]
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _0802137C @ =0xFFFF0000
	adds r3, r5, #0
	ands r3, r1
	orrs r3, r0
	asrs r4, r3, #0x10
	ldrh r0, [r6, #2]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _08021380 @ =0x0000FFFF
	mov ip, r0
	ands r0, r3
	orrs r0, r4
	mov ip, r0
	mov r1, ip
	ldrh r0, [r6, #4]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r2
	adds r2, r5, #0
	orrs r2, r0
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, #0
	muls r3, r0, r3
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r3, r3, r0
	ldr r0, _08021384 @ =0x00012CC7
	cmp r3, r0
	ble _08021358
	b _08021A64
_08021358:
	mov r2, ip
	asrs r1, r2, #0x10
	cmp r1, #0
	bge _08021362
	rsbs r1, r1, #0
_08021362:
	cmp r1, #0xfe
	ble _08021368
	b _08021A64
_08021368:
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	beq _08021376
	b _08021A64
_08021376:
	b _08021A4E
	.align 2, 0
_08021378: .4byte 0x030046A0
_0802137C: .4byte 0xFFFF0000
_08021380: .4byte 0x0000FFFF
_08021384: .4byte 0x00012CC7
_08021388:
	adds r0, r7, #0
	bl FUN_0801f7f4
	b _08021A64
_08021390:
	adds r0, r7, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080213A0
	b _08021A64
_080213A0:
	adds r0, r7, #0
	bl FUN_0801f858
	ldr r2, [r7, #0x68]
	ldr r3, [r7, #0x6c]
	ldr r0, _08021454 @ =0x030046A0
	ldr r5, [r0]
	ldrh r0, [r5, #0x30]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08021458 @ =0xFFFF0000
	mov sb, r1
	ands r1, r2
	orrs r1, r0
	asrs r4, r1, #0x10
	ldrh r0, [r5, #0x32]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r6, _0802145C @ =0x0000FFFF
	ands r6, r1
	orrs r6, r4
	adds r2, r6, #0
	ldrh r1, [r5, #0x34]
	subs r1, r3, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r0, sb
	ands r0, r3
	adds r3, r0, #0
	orrs r3, r1
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _08021460 @ =0x00012CC7
	cmp r1, r0
	bgt _0802147E
	asrs r1, r6, #0x10
	cmp r1, #0
	bge _08021400
	rsbs r1, r1, #0
_08021400:
	cmp r1, #0xfe
	bgt _0802147E
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _0802147E
	adds r0, r7, #0
	adds r0, #0x41
	ldrb r0, [r0]
	cmp r0, #0
	bne _08021468
	ldr r0, _08021464 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0802147E
	mov r0, r8
	adds r1, r7, #0
	bl FUN_0801fb08
	cmp r0, #0
	bne _0802147E
	ldr r0, [r7, #0x48]
	cmp r0, #0
	beq _0802147E
	ldr r0, [sp, #0x10]
	mov r3, sb
	ands r0, r3
	movs r1, #4
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r0, r7, #0
	adds r0, #0x50
	add r1, sp, #0x10
	str r0, [r1, #4]
	ldr r0, [r7, #0x48]
	bl Script_ExecById
	b _0802147E
	.align 2, 0
_08021454: .4byte 0x030046A0
_08021458: .4byte 0xFFFF0000
_0802145C: .4byte 0x0000FFFF
_08021460: .4byte 0x00012CC7
_08021464: .4byte 0x030044E0
_08021468:
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	lsls r0, r0, #1
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r7, #0x34]
	strh r0, [r1]
	mov r2, r8
	ldrb r0, [r2, #0x1c]
	adds r0, #1
	strb r0, [r2, #0x1c]
_0802147E:
	add r6, sp, #0x18
	b _080219D0
_08021482:
	adds r0, r7, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08021492
	b _08021A64
_08021492:
	adds r0, r7, #0
	bl FUN_0801f764
	ldr r2, [r7, #0x68]
	ldr r3, [r7, #0x6c]
	ldr r0, _080215A4 @ =0x030046A0
	ldr r6, [r0]
	ldrh r0, [r6, #0x30]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _080215A8 @ =0xFFFF0000
	adds r1, r5, #0
	ands r1, r2
	orrs r1, r0
	asrs r4, r1, #0x10
	ldrh r0, [r6, #0x32]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _080215AC @ =0x0000FFFF
	mov ip, r0
	ands r0, r1
	orrs r0, r4
	mov ip, r0
	mov r2, ip
	ldrh r0, [r6, #0x34]
	subs r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r3
	adds r3, r5, #0
	orrs r3, r0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _080215B0 @ =0x00012CC7
	cmp r1, r0
	bgt _0802151C
	mov r3, ip
	asrs r1, r3, #0x10
	cmp r1, #0
	bge _080214F6
	rsbs r1, r1, #0
_080214F6:
	cmp r1, #0xfe
	bgt _0802151C
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _0802151C
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	lsls r0, r0, #1
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r7, #0x34]
	strh r0, [r1]
	mov r2, r8
	ldrb r0, [r2, #0x1c]
	adds r0, #1
	strb r0, [r2, #0x1c]
_0802151C:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08020680
	add r6, sp, #0x20
	adds r0, r6, #0
	bl FUN_08086a28
	cmp r0, #0
	bne _08021532
	b _08021A64
_08021532:
	ldr r1, [r7, #0x68]
	ldr r2, [r7, #0x6c]
	ldrh r0, [r6]
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _080215A8 @ =0xFFFF0000
	adds r3, r5, #0
	ands r3, r1
	orrs r3, r0
	asrs r4, r3, #0x10
	ldrh r0, [r6, #2]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _080215AC @ =0x0000FFFF
	mov ip, r0
	ands r0, r3
	orrs r0, r4
	mov ip, r0
	mov r1, ip
	ldrh r0, [r6, #4]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r2
	adds r2, r5, #0
	orrs r2, r0
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, #0
	muls r3, r0, r3
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r3, r3, r0
	ldr r0, _080215B0 @ =0x00012CC7
	cmp r3, r0
	ble _08021584
	b _08021A64
_08021584:
	mov r2, ip
	asrs r1, r2, #0x10
	cmp r1, #0
	bge _0802158E
	rsbs r1, r1, #0
_0802158E:
	cmp r1, #0xfe
	ble _08021594
	b _08021A64
_08021594:
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	beq _080215A2
	b _08021A64
_080215A2:
	b _08021A4E
	.align 2, 0
_080215A4: .4byte 0x030046A0
_080215A8: .4byte 0xFFFF0000
_080215AC: .4byte 0x0000FFFF
_080215B0: .4byte 0x00012CC7
_080215B4:
	adds r0, r7, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080215C4
	b _08021A64
_080215C4:
	adds r0, r7, #0
	bl FUN_0801f764
	ldr r2, [r7, #0x68]
	ldr r3, [r7, #0x6c]
	ldr r0, _080216D8 @ =0x030046A0
	ldr r6, [r0]
	ldrh r0, [r6, #0x30]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _080216DC @ =0xFFFF0000
	adds r1, r5, #0
	ands r1, r2
	orrs r1, r0
	asrs r4, r1, #0x10
	ldrh r0, [r6, #0x32]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _080216E0 @ =0x0000FFFF
	mov ip, r0
	ands r0, r1
	orrs r0, r4
	mov ip, r0
	mov r2, ip
	ldrh r0, [r6, #0x34]
	subs r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r3
	adds r3, r5, #0
	orrs r3, r0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _080216E4 @ =0x00012CC7
	cmp r1, r0
	bgt _0802164E
	mov r3, ip
	asrs r1, r3, #0x10
	cmp r1, #0
	bge _08021628
	rsbs r1, r1, #0
_08021628:
	cmp r1, #0xfe
	bgt _0802164E
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _0802164E
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	lsls r0, r0, #1
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r7, #0x34]
	strh r0, [r1]
	mov r2, r8
	ldrb r0, [r2, #0x1c]
	adds r0, #1
	strb r0, [r2, #0x1c]
_0802164E:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08020680
	add r6, sp, #0x28
	adds r0, r6, #0
	bl FUN_08086a28
	cmp r0, #0
	bne _08021664
	b _08021A64
_08021664:
	ldr r1, [r7, #0x68]
	ldr r2, [r7, #0x6c]
	ldrh r0, [r6]
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _080216DC @ =0xFFFF0000
	adds r3, r5, #0
	ands r3, r1
	orrs r3, r0
	asrs r4, r3, #0x10
	ldrh r0, [r6, #2]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _080216E0 @ =0x0000FFFF
	mov ip, r0
	ands r0, r3
	orrs r0, r4
	mov ip, r0
	mov r1, ip
	ldrh r0, [r6, #4]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r2
	adds r2, r5, #0
	orrs r2, r0
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, #0
	muls r3, r0, r3
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r3, r3, r0
	ldr r0, _080216E4 @ =0x00012CC7
	cmp r3, r0
	ble _080216B6
	b _08021A64
_080216B6:
	mov r2, ip
	asrs r1, r2, #0x10
	cmp r1, #0
	bge _080216C0
	rsbs r1, r1, #0
_080216C0:
	cmp r1, #0xfe
	ble _080216C6
	b _08021A64
_080216C6:
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	beq _080216D4
	b _08021A64
_080216D4:
	b _08021A4E
	.align 2, 0
_080216D8: .4byte 0x030046A0
_080216DC: .4byte 0xFFFF0000
_080216E0: .4byte 0x0000FFFF
_080216E4: .4byte 0x00012CC7
_080216E8:
	adds r0, r7, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080216F8
	b _08021A64
_080216F8:
	adds r0, r7, #0
	bl FUN_0801f764
	ldr r2, [r7, #0x68]
	ldr r3, [r7, #0x6c]
	ldr r0, _08021830 @ =0x030046A0
	ldr r6, [r0]
	ldrh r0, [r6, #0x30]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _08021834 @ =0xFFFF0000
	adds r1, r5, #0
	ands r1, r2
	orrs r1, r0
	asrs r4, r1, #0x10
	ldrh r0, [r6, #0x32]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _08021838 @ =0x0000FFFF
	mov ip, r0
	ands r0, r1
	orrs r0, r4
	mov ip, r0
	mov r2, ip
	ldrh r0, [r6, #0x34]
	subs r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r3
	adds r3, r5, #0
	orrs r3, r0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _0802183C @ =0x00012CC7
	cmp r1, r0
	bgt _08021782
	mov r3, ip
	asrs r1, r3, #0x10
	cmp r1, #0
	bge _0802175C
	rsbs r1, r1, #0
_0802175C:
	cmp r1, #0xfe
	bgt _08021782
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _08021782
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	lsls r0, r0, #1
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r7, #0x34]
	strh r0, [r1]
	mov r2, r8
	ldrb r0, [r2, #0x1c]
	adds r0, #1
	strb r0, [r2, #0x1c]
_08021782:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08020680
	add r6, sp, #0x30
	adds r0, r6, #0
	bl FUN_08086a28
	cmp r0, #0
	beq _08021816
	ldr r1, [r7, #0x68]
	ldr r2, [r7, #0x6c]
	ldrh r0, [r6]
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _08021834 @ =0xFFFF0000
	adds r3, r5, #0
	ands r3, r1
	orrs r3, r0
	asrs r4, r3, #0x10
	ldrh r0, [r6, #2]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _08021838 @ =0x0000FFFF
	mov ip, r0
	ands r0, r3
	orrs r0, r4
	mov ip, r0
	mov r1, ip
	ldrh r0, [r6, #4]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r2
	adds r2, r5, #0
	orrs r2, r0
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, #0
	muls r3, r0, r3
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r3, r3, r0
	ldr r0, _0802183C @ =0x00012CC7
	cmp r3, r0
	bgt _08021816
	mov r2, ip
	asrs r1, r2, #0x10
	cmp r1, #0
	bge _080217F0
	rsbs r1, r1, #0
_080217F0:
	cmp r1, #0xfe
	bgt _08021816
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _08021816
	mov r3, r8
	ldrb r0, [r3, #0x1c]
	lsls r0, r0, #1
	mov r1, r8
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r7, #0x34]
	strh r0, [r1]
	ldrb r0, [r3, #0x1c]
	adds r0, #1
	strb r0, [r3, #0x1c]
_08021816:
	adds r0, r7, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08021826
	b _08021A64
_08021826:
	adds r0, r7, #0
	bl FUN_0801f764
	b _08021A64
	.align 2, 0
_08021830: .4byte 0x030046A0
_08021834: .4byte 0xFFFF0000
_08021838: .4byte 0x0000FFFF
_0802183C: .4byte 0x00012CC7
_08021840:
	adds r0, r7, #0
	bl FUN_0801f764
	ldr r0, _080218CC @ =0x030046A0
	ldr r6, [r0]
	ldr r1, _080218D0 @ =0x00000942
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #2
	bgt _08021858
	b _08021A64
_08021858:
	ldr r1, [r7, #0x68]
	ldr r2, [r7, #0x6c]
	ldrh r0, [r6, #0x30]
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _080218D4 @ =0xFFFF0000
	adds r3, r5, #0
	ands r3, r1
	orrs r3, r0
	asrs r4, r3, #0x10
	ldrh r0, [r6, #0x32]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _080218D8 @ =0x0000FFFF
	mov ip, r0
	ands r0, r3
	orrs r0, r4
	mov ip, r0
	mov r1, ip
	ldrh r0, [r6, #0x34]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r2
	adds r2, r5, #0
	orrs r2, r0
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, #0
	muls r3, r0, r3
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r3, r3, r0
	ldr r0, _080218DC @ =0x00012CC7
	cmp r3, r0
	ble _080218AA
	b _08021A64
_080218AA:
	mov r2, ip
	asrs r1, r2, #0x10
	cmp r1, #0
	bge _080218B4
	rsbs r1, r1, #0
_080218B4:
	cmp r1, #0xfe
	ble _080218BA
	b _08021A64
_080218BA:
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	beq _080218C8
	b _08021A64
_080218C8:
	b _08021A4E
	.align 2, 0
_080218CC: .4byte 0x030046A0
_080218D0: .4byte 0x00000942
_080218D4: .4byte 0xFFFF0000
_080218D8: .4byte 0x0000FFFF
_080218DC: .4byte 0x00012CC7
_080218E0:
	adds r0, r7, #0
	adds r0, #0x36
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080218F0
	b _08021A64
_080218F0:
	adds r0, r7, #0
	bl FUN_0801f858
	ldr r2, [r7, #0x68]
	ldr r3, [r7, #0x6c]
	ldr r0, _080219A4 @ =0x030046A0
	ldr r5, [r0]
	ldrh r0, [r5, #0x30]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080219A8 @ =0xFFFF0000
	mov sb, r1
	ands r1, r2
	orrs r1, r0
	asrs r4, r1, #0x10
	ldrh r0, [r5, #0x32]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r6, _080219AC @ =0x0000FFFF
	ands r6, r1
	orrs r6, r4
	adds r2, r6, #0
	ldrh r1, [r5, #0x34]
	subs r1, r3, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r0, sb
	ands r0, r3
	adds r3, r0, #0
	orrs r3, r1
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _080219B0 @ =0x00012CC7
	cmp r1, r0
	bgt _080219CE
	asrs r1, r6, #0x10
	cmp r1, #0
	bge _08021950
	rsbs r1, r1, #0
_08021950:
	cmp r1, #0xfe
	bgt _080219CE
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _080219CE
	adds r0, r7, #0
	adds r0, #0x41
	ldrb r0, [r0]
	cmp r0, #0
	bne _080219B8
	ldr r0, _080219B4 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080219CE
	mov r0, r8
	adds r1, r7, #0
	bl FUN_0801fb08
	cmp r0, #0
	bne _080219CE
	ldr r0, [r7, #0x48]
	cmp r0, #0
	beq _080219CE
	ldr r0, [sp, #0x38]
	mov r3, sb
	ands r0, r3
	movs r1, #4
	orrs r0, r1
	str r0, [sp, #0x38]
	adds r0, r7, #0
	adds r0, #0x50
	add r1, sp, #0x38
	str r0, [r1, #4]
	ldr r0, [r7, #0x48]
	bl Script_ExecById
	b _080219CE
	.align 2, 0
_080219A4: .4byte 0x030046A0
_080219A8: .4byte 0xFFFF0000
_080219AC: .4byte 0x0000FFFF
_080219B0: .4byte 0x00012CC7
_080219B4: .4byte 0x030044E0
_080219B8:
	mov r1, r8
	ldrb r0, [r1, #0x1c]
	lsls r0, r0, #1
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r7, #0x34]
	strh r0, [r1]
	mov r2, r8
	ldrb r0, [r2, #0x1c]
	adds r0, #1
	strb r0, [r2, #0x1c]
_080219CE:
	add r6, sp, #0x40
_080219D0:
	adds r0, r6, #0
	bl FUN_08086a28
	cmp r0, #0
	beq _08021A64
	ldr r1, [r7, #0x68]
	ldr r2, [r7, #0x6c]
	ldrh r0, [r6]
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _08021AB0 @ =0xFFFF0000
	adds r3, r5, #0
	ands r3, r1
	orrs r3, r0
	asrs r4, r3, #0x10
	ldrh r0, [r6, #2]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	ldr r0, _08021AB4 @ =0x0000FFFF
	mov ip, r0
	ands r0, r3
	orrs r0, r4
	mov ip, r0
	mov r1, ip
	ldrh r0, [r6, #4]
	subs r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r2
	adds r2, r5, #0
	orrs r2, r0
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r3, r0, #0
	muls r3, r0, r3
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r3, r3, r0
	ldr r0, _08021AB8 @ =0x00012CC7
	cmp r3, r0
	bgt _08021A64
	mov r2, ip
	asrs r1, r2, #0x10
	cmp r1, #0
	bge _08021A34
	rsbs r1, r1, #0
_08021A34:
	cmp r1, #0xfe
	bgt _08021A64
	ldrh r1, [r7, #0x34]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _08021A64
	adds r0, r7, #0
	adds r0, #0x41
	ldrb r0, [r0]
	cmp r0, #0
	beq _08021A64
_08021A4E:
	mov r3, r8
	ldrb r0, [r3, #0x1c]
	lsls r0, r0, #1
	mov r1, r8
	adds r1, #0x1e
	adds r1, r1, r0
	ldrh r0, [r7, #0x34]
	strh r0, [r1]
	ldrb r0, [r3, #0x1c]
	adds r0, #1
	strb r0, [r3, #0x1c]
_08021A64:
	movs r0, #1
	add sl, r0
	mov r1, r8
	ldrh r1, [r1, #0x1a]
	cmp sl, r1
	bge _08021A74
	bl _08021196
_08021A74:
	movs r2, #0
	mov sl, r2
	mov r3, r8
	ldrb r3, [r3, #0x1d]
	cmp sl, r3
	bge _08021AAA
_08021A80:
	mov r0, sl
	lsls r1, r0, #1
	mov r0, r8
	adds r0, #0x26
	adds r4, r0, r1
	ldrh r1, [r4]
	mov r0, r8
	bl FUN_0801faa8
	cmp r0, #0
	bne _08021A9E
	ldrh r1, [r4]
	mov r0, r8
	bl FUN_0801fd10
_08021A9E:
	movs r1, #1
	add sl, r1
	mov r2, r8
	ldrb r2, [r2, #0x1d]
	cmp sl, r2
	blt _08021A80
_08021AAA:
	movs r3, #0
	mov sl, r3
	b _08021ADE
	.align 2, 0
_08021AB0: .4byte 0xFFFF0000
_08021AB4: .4byte 0x0000FFFF
_08021AB8: .4byte 0x00012CC7
_08021ABC:
	mov r2, sl
	lsls r1, r2, #1
	mov r0, r8
	adds r0, #0x1e
	adds r4, r0, r1
	ldrh r1, [r4]
	mov r0, r8
	bl FUN_0801fad8
	cmp r0, #0
	bne _08021ADA
	ldrh r1, [r4]
	mov r0, r8
	bl FUN_0801fc88
_08021ADA:
	movs r3, #1
	add sl, r3
_08021ADE:
	mov r0, r8
	ldrb r0, [r0, #0x1c]
	cmp sl, r0
	blt _08021ABC
	movs r1, #0
	mov sl, r1
	mov r2, r8
	ldrh r2, [r2, #0x1a]
	cmp sl, r2
	bge _08021B16
	ldr r4, _08021B28 @ =0x0000042C
	add r4, r8
_08021AF6:
	movs r0, #0x8c
	mov r1, sl
	muls r1, r0, r1
	ldr r0, [r4]
	adds r0, r0, r1
	ldr r1, [r0, #0x30]
	cmp r1, #0
	beq _08021B0A
	bl _call_via_r1
_08021B0A:
	movs r3, #1
	add sl, r3
	mov r0, r8
	ldrh r0, [r0, #0x1a]
	cmp sl, r0
	blt _08021AF6
_08021B16:
	movs r0, #0
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08021B28: .4byte 0x0000042C

	thumb_func_start FUN_08021b2c
FUN_08021b2c: @ 0x08021B2C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r6, #0
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	bge _08021B64
	ldr r1, _08021BD0 @ =0x0000042C
	adds r7, r5, r1
_08021B3C:
	movs r0, #0x8c
	adds r1, r6, #0
	muls r1, r0, r1
	ldr r0, [r7]
	adds r4, r0, r1
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _08021B56
	bl FUN_082342a8
	ldr r0, [r4, #0x2c]
	bl Free
_08021B56:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r6, #1
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	blt _08021B3C
_08021B64:
	ldr r0, [r5, #0x34]
	cmp r0, #0
	beq _08021BB8
	movs r1, #0x82
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl Free
	ldr r1, _08021BD4 @ =0x00000414
	adds r0, r5, r1
	ldr r0, [r0]
	bl Free
	movs r1, #0x83
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl Free
	ldr r1, _08021BD8 @ =0x0000041C
	adds r0, r5, r1
	ldr r0, [r0]
	bl Free
	movs r1, #0x84
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl Free
	ldr r1, _08021BDC @ =0x00000424
	adds r0, r5, r1
	ldr r0, [r0]
	bl Free
	movs r1, #0x85
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	bl Free
_08021BB8:
	ldr r1, _08021BD0 @ =0x0000042C
	adds r0, r5, r1
	ldr r0, [r0]
	bl Free
	ldr r0, _08021BE0 @ =0x000085E6
	bl FUN_08230e58
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08021BD0: .4byte 0x0000042C
_08021BD4: .4byte 0x00000414
_08021BD8: .4byte 0x0000041C
_08021BDC: .4byte 0x00000424
_08021BE0: .4byte 0x000085E6

	thumb_func_start FUN_08021be4
FUN_08021be4: @ 0x08021BE4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0
	strh r1, [r7, #0x18]
	strh r0, [r7, #0x2e]
	strh r0, [r7, #0x1a]
	movs r0, #0x65
	movs r1, #1
	bl Script_GetKeywordValue
	adds r1, r0, #0
	str r1, [r7, #0x34]
	cmp r1, #0
	beq _08021CF0
	movs r0, #0x8c
	bl Malloc
	movs r1, #0x82
	lsls r1, r1, #3
	adds r4, r7, r1
	str r0, [r4]
	movs r0, #0x8c
	bl Malloc
	ldr r2, _08021CAC @ =0x00000414
	adds r2, r2, r7
	mov sb, r2
	str r0, [r2]
	movs r0, #0x8c
	bl Malloc
	movs r1, #0x83
	lsls r1, r1, #3
	adds r1, r1, r7
	mov sl, r1
	str r0, [r1]
	movs r0, #0x8c
	bl Malloc
	ldr r2, _08021CB0 @ =0x0000041C
	adds r2, r2, r7
	mov r8, r2
	str r0, [r2]
	movs r0, #0x8c
	bl Malloc
	movs r1, #0x84
	lsls r1, r1, #3
	adds r6, r7, r1
	str r0, [r6]
	movs r0, #0x8c
	bl Malloc
	ldr r2, _08021CB4 @ =0x00000424
	adds r5, r7, r2
	str r0, [r5]
	movs r0, #0x8c
	bl Malloc
	adds r1, r0, #0
	movs r0, #0x85
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp]
	str r1, [r0]
	ldr r4, [r4]
	cmp r4, #0
	beq _08021C9E
	mov r2, sb
	ldr r0, [r2]
	cmp r0, #0
	beq _08021C9E
	mov r2, sl
	ldr r0, [r2]
	cmp r0, #0
	beq _08021C9E
	mov r2, r8
	ldr r0, [r2]
	cmp r0, #0
	beq _08021C9E
	ldr r0, [r6]
	cmp r0, #0
	beq _08021C9E
	ldr r0, [r5]
	cmp r0, #0
	beq _08021C9E
	cmp r1, #0
	bne _08021CB8
_08021C9E:
	adds r0, r7, #0
	bl KillEntity
_08021CA4:
	movs r0, #1
	rsbs r0, r0, #0
	b _08022058
	.align 2, 0
_08021CAC: .4byte 0x00000414
_08021CB0: .4byte 0x0000041C
_08021CB4: .4byte 0x00000424
_08021CB8:
	adds r0, r4, #0
	movs r1, #0x8c
	bl ClearMemory
	mov r1, sb
	ldr r0, [r1]
	movs r1, #0x8c
	bl ClearMemory
	mov r2, r8
	ldr r0, [r2]
	movs r1, #0x8c
	bl ClearMemory
	ldr r0, [r6]
	movs r1, #0x8c
	bl ClearMemory
	ldr r0, [r5]
	movs r1, #0x8c
	bl ClearMemory
	ldr r1, [sp]
	ldr r0, [r1]
	movs r1, #0x8c
	bl ClearMemory
	b _08021D1C
_08021CF0:
	movs r2, #0x82
	lsls r2, r2, #3
	adds r0, r7, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r7, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r7, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r7, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r7, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r7, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r7, r2
	str r1, [r0]
_08021D1C:
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	beq _08021D58
	movs r5, #0
	adds r4, r7, #0
	adds r4, #0x3c
_08021D2C:
	bl VM_GetPC
	cmp r0, #0
	beq _08021D3E
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b _08021D40
_08021D3E:
	ldr r1, _08021D54 @ =0x00007ACD
_08021D40:
	adds r0, r4, #0
	bl FUN_0822b16c
	cmp r0, #0
	beq _08021CA4
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021D2C
	b _08021D72
	.align 2, 0
_08021D54: .4byte 0x00007ACD
_08021D58:
	movs r5, #0
	adds r4, r7, #0
	adds r4, #0x3c
_08021D5E:
	adds r0, r4, #0
	ldr r1, _08021D9C @ =0x00007ACD
	bl FUN_0822b16c
	cmp r0, #0
	beq _08021CA4
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021D5E
_08021D72:
	movs r0, #0x6b
	bl prepare_08231510
	cmp r0, #0
	beq _08021E40
	movs r5, #0
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r0, r0, r7
	mov r8, r0
	movs r6, #0
_08021D88:
	bl VM_GetPC
	cmp r0, #0
	beq _08021DA0
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _08021DA2
	.align 2, 0
_08021D9C: .4byte 0x00007ACD
_08021DA0:
	ldr r4, _08021E30 @ =0x00007AD3
_08021DA2:
	mov r0, r8
	adds r1, r4, #0
	bl FUN_0822b16c
	cmp r0, #0
	bne _08021DB0
	b _08021CA4
_08021DB0:
	ldr r0, [r7, #0x34]
	cmp r0, #0
	beq _08021E20
	movs r1, #0x82
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	adds r0, r0, r6
	adds r1, r4, #0
	bl FUN_0822b16c
	ldr r2, _08021E34 @ =0x00000414
	adds r0, r7, r2
	ldr r0, [r0]
	adds r0, r0, r6
	adds r1, r4, #0
	bl FUN_0822b16c
	movs r1, #0x83
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	adds r0, r0, r6
	adds r1, r4, #0
	bl FUN_0822b16c
	ldr r2, _08021E38 @ =0x0000041C
	adds r0, r7, r2
	ldr r0, [r0]
	adds r0, r0, r6
	adds r1, r4, #0
	bl FUN_0822b16c
	movs r1, #0x84
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	adds r0, r0, r6
	adds r1, r4, #0
	bl FUN_0822b16c
	ldr r2, _08021E3C @ =0x00000424
	adds r0, r7, r2
	ldr r0, [r0]
	adds r0, r0, r6
	adds r1, r4, #0
	bl FUN_0822b16c
	movs r1, #0x85
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	adds r0, r0, r6
	adds r1, r4, #0
	bl FUN_0822b16c
_08021E20:
	movs r2, #0x1c
	add r8, r2
	adds r6, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021D88
	b _08021E5E
	.align 2, 0
_08021E30: .4byte 0x00007AD3
_08021E34: .4byte 0x00000414
_08021E38: .4byte 0x0000041C
_08021E3C: .4byte 0x00000424
_08021E40:
	movs r5, #0
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r4, r7, r0
_08021E48:
	adds r0, r4, #0
	ldr r1, _08021E7C @ =0x00007AD3
	bl FUN_0822b16c
	cmp r0, #0
	bne _08021E56
	b _08021CA4
_08021E56:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021E48
_08021E5E:
	movs r0, #0x53
	bl prepare_08231510
	cmp r0, #0
	beq _08021EA4
	bl VM_GetPC
	cmp r0, #0
	beq _08021E80
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	b _08021E82
	.align 2, 0
_08021E7C: .4byte 0x00007AD3
_08021E80:
	ldr r6, _08021EA0 @ =0x00007AD2
_08021E82:
	movs r5, #0
	adds r4, r7, #0
	adds r4, #0xc8
_08021E88:
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_0822b16c
	cmp r0, #0
	bne _08021E96
	b _08021CA4
_08021E96:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021E88
	b _08021EC0
	.align 2, 0
_08021EA0: .4byte 0x00007AD2
_08021EA4:
	movs r5, #0
	adds r4, r7, #0
	adds r4, #0xc8
_08021EAA:
	adds r0, r4, #0
	ldr r1, _08021EEC @ =0x00007AD2
	bl FUN_0822b16c
	cmp r0, #0
	bne _08021EB8
	b _08021CA4
_08021EB8:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021EAA
_08021EC0:
	movs r0, #0x62
	bl prepare_08231510
	cmp r0, #0
	beq _08021F20
	movs r5, #0
	movs r1, #0x9b
	lsls r1, r1, #2
	adds r1, r1, r7
	mov r8, r1
	movs r2, #0xf0
	lsls r2, r2, #1
	adds r6, r7, r2
_08021EDA:
	bl VM_GetPC
	cmp r0, #0
	beq _08021EF0
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _08021EF2
	.align 2, 0
_08021EEC: .4byte 0x00007AD2
_08021EF0:
	ldr r4, _08021F1C @ =0x00007AEE
_08021EF2:
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_0822b16c
	cmp r0, #0
	bne _08021F00
	b _08021CA4
_08021F00:
	mov r0, r8
	adds r1, r4, #0
	bl FUN_0822b16c
	cmp r0, #0
	bne _08021F0E
	b _08021CA4
_08021F0E:
	movs r0, #0x1c
	add r8, r0
	adds r6, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021EDA
	b _08021F54
	.align 2, 0
_08021F1C: .4byte 0x00007AEE
_08021F20:
	movs r5, #0
	movs r1, #0x9b
	lsls r1, r1, #2
	adds r6, r7, r1
	movs r2, #0xf0
	lsls r2, r2, #1
	adds r4, r7, r2
_08021F2E:
	adds r0, r4, #0
	ldr r1, _08021F78 @ =0x00007AD3
	bl FUN_0822b16c
	cmp r0, #0
	bne _08021F3C
	b _08021CA4
_08021F3C:
	adds r0, r6, #0
	ldr r1, _08021F78 @ =0x00007AD3
	bl FUN_0822b16c
	cmp r0, #0
	bne _08021F4A
	b _08021CA4
_08021F4A:
	adds r6, #0x1c
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021F2E
_08021F54:
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _08021F98
	movs r5, #0
	movs r0, #0xbe
	lsls r0, r0, #2
	adds r4, r7, r0
_08021F66:
	bl VM_GetPC
	cmp r0, #0
	beq _08021F7C
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b _08021F7E
	.align 2, 0
_08021F78: .4byte 0x00007AD3
_08021F7C:
	ldr r1, _08021F94 @ =0x00007AF3
_08021F7E:
	adds r0, r4, #0
	bl FUN_0822b16c
	cmp r0, #0
	bne _08021F8A
	b _08021CA4
_08021F8A:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021F66
	b _08021FB6
	.align 2, 0
_08021F94: .4byte 0x00007AF3
_08021F98:
	movs r5, #0
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r4, r7, r1
_08021FA0:
	adds r0, r4, #0
	ldr r1, _08021FDC @ =0x00007AF3
	bl FUN_0822b16c
	cmp r0, #0
	bne _08021FAE
	b _08021CA4
_08021FAE:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021FA0
_08021FB6:
	movs r0, #0x75
	bl prepare_08231510
	cmp r0, #0
	beq _08021FFC
	movs r5, #0
	movs r2, #0xe1
	lsls r2, r2, #2
	adds r4, r7, r2
_08021FC8:
	bl VM_GetPC
	cmp r0, #0
	beq _08021FE0
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	b _08021FE2
	.align 2, 0
_08021FDC: .4byte 0x00007AF3
_08021FE0:
	ldr r1, _08021FF8 @ =0x00007AF3
_08021FE2:
	adds r0, r4, #0
	bl FUN_0822b16c
	cmp r0, #0
	bne _08021FEE
	b _08021CA4
_08021FEE:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08021FC8
	b _0802201A
	.align 2, 0
_08021FF8: .4byte 0x00007AF3
_08021FFC:
	movs r5, #0
	movs r0, #0xe1
	lsls r0, r0, #2
	adds r4, r7, r0
_08022004:
	adds r0, r4, #0
	ldr r1, _08022068 @ =0x00007AF3
	bl FUN_0822b16c
	cmp r0, #0
	bne _08022012
	b _08021CA4
_08022012:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #4
	ble _08022004
_0802201A:
	movs r0, #0x6d
	movs r1, #0x10
	bl Script_GetKeywordValue
	str r0, [r7, #0x30]
	movs r4, #0x8c
	muls r0, r4, r0
	bl Malloc
	ldr r2, _0802206C @ =0x0000042C
	adds r1, r7, r2
	str r0, [r1]
	ldr r1, [r7, #0x30]
	muls r1, r4, r1
	bl ClearMemory
	adds r1, r7, #0
	adds r1, #0x1e
	movs r2, #0
	adds r0, r7, #0
	adds r0, #0x24
_08022044:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _08022044
	ldr r0, _08022070 @ =0x000085E6
	adds r1, r7, #0
	movs r2, #0
	bl FUN_08230e30
	movs r0, #0
_08022058:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08022068: .4byte 0x00007AF3
_0802206C: .4byte 0x0000042C
_08022070: .4byte 0x000085E6

	thumb_func_start FUN_08022074
FUN_08022074: @ 0x08022074
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, _080220A8 @ =0x00000434
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080220B4
	ldr r1, _080220AC @ =FUN_08021094
	ldr r2, _080220B0 @ =FUN_08021b2c
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_08021be4
	cmp r0, #0
	bge _080220B4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080220B6
	.align 2, 0
_080220A8: .4byte 0x00000434
_080220AC: .4byte FUN_08021094
_080220B0: .4byte FUN_08021b2c
_080220B4:
	adds r0, r4, #0
_080220B6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080220bc
FUN_080220bc: @ 0x080220BC
	push {r4, lr}
	adds r4, r1, #0
	ldr r3, [r0, #0x74]
	cmp r3, #0
	beq _080220DE
_080220C6:
	ldr r1, [r3, #0x30]
	ldrh r0, [r3]
	cmp r0, r4
	bne _080220D8
	ldrb r0, [r3, #2]
	cmp r0, r2
	bne _080220D8
	adds r0, r3, #0
	b _080220E0
_080220D8:
	adds r3, r1, #0
	cmp r3, #0
	bne _080220C6
_080220DE:
	movs r0, #0
_080220E0:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080220e8
FUN_080220e8: @ 0x080220E8
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x74]
	cmp r0, #0
	beq _080220F4
	str r1, [r0, #0x2c]
_080220F4:
	movs r0, #0
	str r0, [r1, #0x2c]
	ldr r0, [r2, #0x74]
	str r0, [r1, #0x30]
	str r1, [r2, #0x74]
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_08022104
FUN_08022104: @ 0x08022104
	push {lr}
	adds r3, r0, #0
	ldr r2, [r1, #0x2c]
	cmp r2, #0
	beq _08022114
	ldr r0, [r1, #0x30]
	str r0, [r2, #0x30]
	b _08022118
_08022114:
	ldr r0, [r1, #0x30]
	str r0, [r3, #0x74]
_08022118:
	ldr r2, [r1, #0x30]
	cmp r2, #0
	beq _08022122
	ldr r0, [r1, #0x2c]
	str r0, [r2, #0x2c]
_08022122:
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_08022128
FUN_08022128: @ 0x08022128
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldrh r1, [r6]
	ldrb r2, [r6, #2]
	bl FUN_080220bc
	adds r5, r0, #0
	adds r4, #0x24
	ldrb r2, [r4]
	movs r1, #1
	subs r4, r1, r2
	cmp r5, #0
	beq _08022164
	adds r1, r5, #6
	adds r3, r1, r4
	ldrb r1, [r3]
	cmp r1, #3
	bhi _08022164
	adds r2, r1, #0
	lsls r2, r2, #2
	lsls r1, r4, #4
	adds r2, r2, r1
	adds r1, r5, #0
	adds r1, #8
	adds r1, r1, r2
	str r6, [r1]
	ldrb r1, [r3]
	adds r1, #1
	strb r1, [r3]
_08022164:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0802216c
FUN_0802216c: @ 0x0802216C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r1, [r6, #0x74]
	cmp r1, #0
	beq _080221A4
	adds r4, r6, #0
	adds r4, #0x24
	movs r7, #0
_0802217C:
	ldr r5, [r1, #0x30]
	adds r0, r1, #6
	ldrb r2, [r4]
	adds r0, r0, r2
	strb r7, [r0]
	movs r3, #0
	adds r2, r1, #0
	adds r2, #8
_0802218C:
	lsls r1, r3, #2
	ldrb r0, [r4]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r1, r2, r1
	str r7, [r1]
	adds r3, #1
	cmp r3, #3
	ble _0802218C
	adds r1, r5, #0
	cmp r1, #0
	bne _0802217C
_080221A4:
	adds r2, r6, #0
	adds r2, #0x24
	ldrb r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r2]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080221b8
FUN_080221b8: @ 0x080221B8
	push {r4, lr}
	adds r4, r1, #0
	ldrh r0, [r2, #8]
	bl FUN_080224a8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _080221D0
	movs r1, #0
	bl Script_ExecById
_080221D0:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080221e0
FUN_080221e0: @ 0x080221E0
	push {r4, lr}
	adds r3, r1, #0
	movs r4, #8
	ldrsh r1, [r2, r4]
	str r1, [r0, #0x68]
	cmp r1, #0
	bne _080221F6
	adds r0, r3, #0
	movs r1, #1
	bl FUN_08022488
_080221F6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080221fc
FUN_080221fc: @ 0x080221FC
	push {lr}
	movs r2, #1
	str r2, [r0, #0x70]
	adds r0, r1, #0
	movs r1, #1
	bl FUN_08022488
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08022210
FUN_08022210: @ 0x08022210
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x78
	movs r7, #0
	ldr r2, _08022260 @ =0x03002B4C
	ldr r1, [r2]
	adds r1, #0x24
	adds r0, #0x7e
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r7, r0
	bge _080222A0
	mov r8, r2
_08022232:
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r7, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r5, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08022474
	ldrb r0, [r4, #6]
	cmp r0, #1
	beq _08022276
	cmp r0, #1
	bgt _08022264
	cmp r0, #0
	beq _0802226A
	b _0802228C
	.align 2, 0
_08022260: .4byte 0x03002B4C
_08022264:
	cmp r0, #2
	beq _08022282
	b _0802228C
_0802226A:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080221b8
	b _0802228C
_08022276:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080221e0
	b _0802228C
_08022282:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080221fc
_0802228C:
	adds r7, #1
	mov r0, r8
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r5, #6
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r7, r0
	blt _08022232
_080222A0:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity4E69_Update
Entity4E69_Update: @ 0x080222AC
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	adds r0, #0x23
	ldrb r2, [r0]
	cmp r2, #1
	bne _0802232E
	strb r5, [r4, #0x1f]
	ldrb r0, [r4, #0x1e]
	cmp r0, #0
	beq _080222D0
	ldrh r0, [r4, #0x1a]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0x1a]
	strh r5, [r4, #0x1c]
	strb r1, [r4, #0x1e]
	strb r2, [r4, #0x1f]
_080222D0:
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	beq _08022316
	strh r5, [r4, #0x1c]
	b _080222E6
_080222DA:
	adds r0, r4, #0
	bl FUN_08022128
	ldrh r0, [r4, #0x1c]
	adds r0, #1
	strh r0, [r4, #0x1c]
_080222E6:
	movs r1, #0x18
	ldrsh r0, [r4, r1]
	movs r2, #0x1a
	ldrsh r1, [r4, r2]
	ldrh r2, [r4, #0x1c]
	bl FUN_0823a840
	adds r1, r0, #0
	cmp r1, #0
	bne _080222DA
	ldrh r5, [r4, #0x1c]
	cmp r5, #0
	bne _08022314
	ldrh r0, [r4, #0x20]
	cmp r0, #0
	beq _0802230C
	movs r1, #0
	bl Script_ExecById
_0802230C:
	adds r0, r4, #0
	adds r0, #0x23
	strb r5, [r0]
	b _0802233E
_08022314:
	movs r5, #1
_08022316:
	ldr r0, [r4, #0x68]
	cmp r0, #0
	beq _0802232E
	subs r0, #1
	str r0, [r4, #0x68]
	cmp r0, #0
	bne _0802232E
	adds r0, r4, #0
	adds r0, #0x78
	movs r1, #1
	bl FUN_08022488
_0802232E:
	adds r0, r4, #0
	bl FUN_0802216c
	cmp r5, #0
	beq _0802233E
	adds r0, r4, #0
	bl FUN_08022210
_0802233E:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity4E69_Destroy
Entity4E69_Destroy: @ 0x08022348
	.byte 0x00, 0xB5, 0x78, 0x30, 0x00, 0xF0, 0x6C, 0xF8
	.byte 0x02, 0x49, 0x00, 0x20, 0x08, 0x60, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00, 0x4C, 0x2B, 0x00, 0x03

	thumb_func_start Entity4E69_Init
Entity4E69_Init: @ 0x08022360
	push {r4, lr}
	ldr r2, _0802239C @ =0x03002B4C
	str r0, [r2]
	adds r2, r0, #0
	adds r2, #0x23
	movs r3, #0
	strb r3, [r2]
	ldr r2, _080223A0 @ =0x0000FFFF
	strh r2, [r0, #0x18]
	movs r2, #1
	rsbs r2, r2, #0
	strh r2, [r0, #0x1a]
	movs r2, #0
	strh r3, [r0, #0x1c]
	strb r2, [r0, #0x1e]
	strb r2, [r0, #0x1f]
	strh r3, [r0, #0x20]
	movs r4, #0x22
	strb r2, [r4, r0]
	str r3, [r0, #0x6c]
	str r3, [r0, #0x74]
	adds r0, #0x78
	movs r2, #1
	bl FUN_080223f4
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0802239C: .4byte 0x03002B4C
_080223A0: .4byte 0x0000FFFF

	thumb_func_start Entity4E69_Create
Entity4E69_Create: @ 0x080223A4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080223B4 @ =0x03002B4C
	ldr r0, [r0]
	cmp r0, #0
	beq _080223B8
	movs r0, #0
	b _080223EE
	.align 2, 0
_080223B4: .4byte 0x03002B4C
_080223B8:
	movs r0, #2
	movs r1, #0xac
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080223EC
	ldr r1, _080223E4 @ =Entity4E69_Update
	ldr r2, _080223E8 @ =Entity4E69_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity4E69_Init
	cmp r0, #0
	bge _080223EC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080223EE
	.align 2, 0
_080223E4: .4byte Entity4E69_Update
_080223E8: .4byte Entity4E69_Destroy
_080223EC:
	adds r0, r4, #0
_080223EE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080223f4
FUN_080223f4: @ 0x080223F4
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	ldr r0, _08022418 @ =0x03002B4C
	ldr r1, [r0]
	cmp r1, #0
	beq _0802241C
	movs r0, #0
	strh r4, [r3]
	strb r2, [r3, #2]
	strb r0, [r3, #6]
	strb r0, [r3, #7]
	strb r0, [r3, #3]
	adds r0, r1, #0
	adds r1, r3, #0
	bl FUN_080220e8
	b _08022420
	.align 2, 0
_08022418: .4byte 0x03002B4C
_0802241C:
	movs r0, #1
	rsbs r0, r0, #0
_08022420:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08022428
FUN_08022428: @ 0x08022428
	push {lr}
	adds r1, r0, #0
	ldr r0, _0802243C @ =0x03002B4C
	ldr r0, [r0]
	cmp r0, #0
	beq _08022440
	bl FUN_08022104
	b _08022444
	.align 2, 0
_0802243C: .4byte 0x03002B4C
_08022440:
	movs r0, #1
	rsbs r0, r0, #0
_08022444:
	pop {r1}
	bx r1

	thumb_func_start FUN_08022448
FUN_08022448: @ 0x08022448
	push {lr}
	ldr r0, _08022458 @ =0x03002B4C
	ldr r1, [r0]
	cmp r1, #0
	bne _0802245C
	movs r0, #1
	rsbs r0, r0, #0
	b _0802246E
	.align 2, 0
_08022458: .4byte 0x03002B4C
_0802245C:
	ldrb r0, [r1, #0x1e]
	cmp r0, #0
	bne _0802246A
	movs r0, #1
	strb r0, [r1, #0x1e]
	movs r0, #0
	b _0802246E
_0802246A:
	movs r0, #2
	rsbs r0, r0, #0
_0802246E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08022474
FUN_08022474: @ 0x08022474
	push {lr}
	ldrb r1, [r1, #3]
	cmp r1, #0
	bne _08022480
	movs r0, #0
	b _08022484
_08022480:
	strb r1, [r0, #3]
	movs r0, #1
_08022484:
	pop {r1}
	bx r1

	thumb_func_start FUN_08022488
FUN_08022488: @ 0x08022488
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #3]
	cmp r0, r1
	beq _08022496
	movs r0, #0
	b _080224A0
_08022496:
	bl FUN_08022448
	movs r0, #0
	strb r0, [r4, #3]
	movs r0, #1
_080224A0:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080224a8
FUN_080224a8: @ 0x080224A8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _080224B8 @ =0x03002B4C
	ldr r3, [r0]
	cmp r3, #0
	bne _080224C6
	b _080224E8
	.align 2, 0
_080224B8: .4byte 0x03002B4C
_080224BC:
	adds r0, r3, #0
	adds r0, #0x48
	adds r0, r0, r4
	ldrh r0, [r0]
	b _080224EA
_080224C6:
	movs r2, #0
	adds r0, r3, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r2, r0
	bge _080224E8
	adds r5, r0, #0
	adds r1, r3, #0
	adds r1, #0x28
_080224D8:
	lsls r4, r2, #1
	ldrh r0, [r1]
	cmp r0, r6
	beq _080224BC
	adds r1, #2
	adds r2, #1
	cmp r2, r5
	blt _080224D8
_080224E8:
	movs r0, #0
_080224EA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080224f0
FUN_080224f0: @ 0x080224F0
	push {lr}
	adds r1, r0, #0
	ldr r0, _08022504 @ =0x03002B4C
	ldr r0, [r0]
	cmp r0, #0
	beq _08022508
	bl FUN_08022128
	b _0802250C
	.align 2, 0
_08022504: .4byte 0x03002B4C
_08022508:
	movs r0, #1
	rsbs r0, r0, #0
_0802250C:
	pop {r1}
	bx r1

	thumb_func_start FUN_08022510
FUN_08022510: @ 0x08022510
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _08022530 @ =0x03002B4C
	ldr r7, [r0]
	cmp r7, #0
	beq _08022528
	adds r1, r7, #0
	adds r1, #0x23
	ldrb r0, [r1]
	cmp r0, #1
	bne _08022534
_08022528:
	movs r0, #1
	rsbs r0, r0, #0
	b _080225C8
	.align 2, 0
_08022530: .4byte 0x03002B4C
_08022534:
	movs r0, #0
	mov r8, r0
	movs r5, #1
	strb r5, [r1]
	movs r4, #1
	rsbs r4, r4, #0
	movs r0, #0x64
	adds r1, r4, #0
	bl Script_GetKeywordValue
	movs r6, #0
	strh r0, [r7, #0x18]
	movs r0, #0x63
	adds r1, r4, #0
	bl Script_GetKeywordValue
	subs r0, #1
	strh r0, [r7, #0x1a]
	mov r0, r8
	strh r0, [r7, #0x1c]
	strb r5, [r7, #0x1e]
	strb r6, [r7, #0x1f]
	movs r0, #0x65
	movs r1, #0
	bl Script_GetKeywordValue
	strh r0, [r7, #0x20]
	adds r4, r7, #0
	adds r4, #0x22
	strb r6, [r4]
	movs r0, #0x70
	bl prepare_08231510
	adds r6, r7, #0
	adds r6, #0x78
	cmp r0, #0
	beq _080225BE
	movs r5, #0
	b _0802259A
_08022582:
	bl Script_GetValue
	ldrb r2, [r4]
	lsls r2, r2, #1
	adds r1, r7, #0
	adds r1, #0x48
	adds r1, r1, r2
	strh r0, [r1]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r5, #1
_0802259A:
	cmp r5, #0xf
	bgt _080225BE
	bl VM_GetPC
	cmp r0, #0
	beq _080225BE
	bl Script_GetValue
	ldrb r2, [r4]
	lsls r2, r2, #1
	adds r1, r7, #0
	adds r1, #0x28
	adds r1, r1, r2
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	bne _08022582
_080225BE:
	movs r0, #0
	str r0, [r7, #0x6c]
	strb r0, [r6, #6]
	strb r0, [r6, #7]
	strb r0, [r6, #3]
_080225C8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080225d4
FUN_080225d4: @ 0x080225D4
	push {lr}
	ldr r0, _08022608 @ =0x03002B4C
	ldr r2, [r0]
	cmp r2, #0
	beq _08022610
	adds r0, r2, #0
	adds r0, #0x23
	movs r1, #0
	strb r1, [r0]
	ldr r0, _0802260C @ =0x0000FFFF
	strh r0, [r2, #0x18]
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r2, #0x1a]
	movs r0, #0
	strh r1, [r2, #0x1c]
	strb r0, [r2, #0x1e]
	strb r0, [r2, #0x1f]
	strh r1, [r2, #0x20]
	adds r3, r2, #0
	adds r3, #0x22
	strb r0, [r3]
	str r1, [r2, #0x6c]
	movs r0, #0
	b _08022614
	.align 2, 0
_08022608: .4byte 0x03002B4C
_0802260C: .4byte 0x0000FFFF
_08022610:
	movs r0, #1
	rsbs r0, r0, #0
_08022614:
	pop {r1}
	bx r1

	thumb_func_start FUN_08022618
FUN_08022618: @ 0x08022618
	push {lr}
	ldr r0, _08022630 @ =0x03002B4C
	ldr r1, [r0]
	cmp r1, #0
	beq _08022628
	ldr r0, [r1, #0x70]
	cmp r0, #0
	bne _08022634
_08022628:
	movs r0, #1
	rsbs r0, r0, #0
	b _0802263E
	.align 2, 0
_08022630: .4byte 0x03002B4C
_08022634:
	movs r0, #0
	str r0, [r1, #0x70]
	bl FUN_08022448
	movs r0, #0
_0802263E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08022644
FUN_08022644: @ 0x08022644
	push {lr}
	ldr r0, _0802265C @ =0x03002B4C
	ldr r0, [r0]
	cmp r0, #0
	beq _08022656
	adds r0, #0x23
	ldrb r0, [r0]
	cmp r0, #1
	beq _08022660
_08022656:
	movs r0, #0
	b _08022662
	.align 2, 0
_0802265C: .4byte 0x03002B4C
_08022660:
	movs r0, #1
_08022662:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08022668
FUN_08022668: @ 0x08022668
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r3, _080226A4 @ =0xFFFF0000
	ldrh r1, [r2, #0xa]
	lsls r1, r1, #0x10
	ldrh r0, [r2, #8]
	orrs r0, r1
	str r0, [sp, #4]
	ldrh r1, [r2, #0xc]
	ldr r0, [sp, #8]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #8]
	movs r0, #0xe
	ldrsh r1, [r2, r0]
	movs r5, #0x10
	ldrsh r4, [r2, r5]
	movs r0, #0x12
	ldrsh r3, [r2, r0]
	movs r5, #0x14
	ldrsh r0, [r2, r5]
	str r0, [sp]
	add r0, sp, #4
	adds r2, r4, #0
	bl FUN_08019814
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080226A4: .4byte 0xFFFF0000

	thumb_func_start FUN_080226a8
FUN_080226a8: @ 0x080226A8
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r2, #0
	ldrh r0, [r5, #8]
	bl FUN_0823b2d0
	adds r4, r0, #0
	cmp r4, #0
	beq _080226F4
	ldrh r0, [r4, #8]
	ldr r3, _080226FC @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #4]
	ldrh r2, [r4, #0xa]
	lsls r2, r2, #0x10
	ldr r0, _08022700 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #4]
	ldrh r1, [r4, #0xc]
	ldr r0, [sp, #8]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #8]
	movs r0, #0xa
	ldrsh r1, [r5, r0]
	movs r4, #0xc
	ldrsh r2, [r5, r4]
	movs r0, #0xe
	ldrsh r3, [r5, r0]
	movs r4, #0x10
	ldrsh r0, [r5, r4]
	str r0, [sp]
	add r0, sp, #4
	bl FUN_08019814
_080226F4:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080226FC: .4byte 0xFFFF0000
_08022700: .4byte 0x0000FFFF

	thumb_func_start FUN_08022704
FUN_08022704: @ 0x08022704
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r2, #0
	adds r4, #8
	movs r5, #0
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	cmp r0, #0
	beq _08022718
	ldr r5, _0802276C @ =0x00000FFF
_08022718:
	movs r7, #0xc
	ldrsh r0, [r4, r7]
	cmp r0, #0
	beq _08022728
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r1, #0
	orrs r5, r0
_08022728:
	movs r7, #0xe
	ldrsh r0, [r4, r7]
	cmp r0, #0
	beq _08022738
	movs r1, #0xe0
	lsls r1, r1, #8
	adds r0, r1, #0
	orrs r5, r0
_08022738:
	movs r7, #8
	ldrsh r0, [r2, r7]
	movs r6, #3
	cmp r0, #0
	bne _08022744
	movs r6, #2
_08022744:
	movs r0, #2
	ldrsh r1, [r4, r0]
	movs r7, #4
	ldrsh r2, [r4, r7]
	movs r0, #6
	ldrsh r3, [r4, r0]
	movs r7, #8
	ldrsh r0, [r4, r7]
	str r0, [sp]
	str r5, [sp, #4]
	movs r5, #0x10
	ldrsh r0, [r4, r5]
	str r0, [sp, #8]
	adds r0, r6, #0
	bl FUN_0823ce68
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802276C: .4byte 0x00000FFF

	thumb_func_start FUN_08022770
FUN_08022770: @ 0x08022770
	push {r4, r5, lr}
	sub sp, #0x14
	adds r2, #8
	movs r4, #0
	movs r1, #0xa
	ldrsh r0, [r2, r1]
	cmp r0, #0
	beq _08022782
	ldr r4, _080227F0 @ =0x00000FFF
_08022782:
	movs r3, #0xc
	ldrsh r0, [r2, r3]
	cmp r0, #0
	beq _08022792
	movs r5, #0x80
	lsls r5, r5, #5
	adds r0, r5, #0
	orrs r4, r0
_08022792:
	movs r1, #0xe
	ldrsh r0, [r2, r1]
	cmp r0, #0
	beq _080227A2
	movs r3, #0xe0
	lsls r3, r3, #8
	adds r0, r3, #0
	orrs r4, r0
_080227A2:
	movs r5, #2
	ldrsh r0, [r2, r5]
	str r0, [sp]
	movs r1, #4
	ldrsh r0, [r2, r1]
	str r0, [sp, #4]
	movs r3, #6
	ldrsh r1, [r2, r3]
	str r1, [sp, #8]
	movs r5, #8
	ldrsh r3, [r2, r5]
	str r3, [sp, #0xc]
	str r4, [sp, #0x10]
	cmp r0, #0
	bne _080227D0
	cmp r1, #0
	bne _080227D0
	cmp r3, #0
	bne _080227D0
	movs r0, #4
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r0, [sp, #0xc]
_080227D0:
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r1, #3
	cmp r0, #0
	bne _080227DC
	movs r1, #2
_080227DC:
	adds r0, r1, #0
	movs r1, #5
	mov r2, sp
	bl FUN_0800205c
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080227F0: .4byte 0x00000FFF

	thumb_func_start FUN_080227f4
FUN_080227f4: @ 0x080227F4
	push {r4, r5, lr}
	sub sp, #0x14
	adds r2, #8
	movs r1, #2
	ldrsh r0, [r2, r1]
	str r0, [sp]
	movs r5, #4
	ldrsh r1, [r2, r5]
	str r1, [sp, #4]
	movs r0, #6
	ldrsh r3, [r2, r0]
	str r3, [sp, #8]
	movs r5, #8
	ldrsh r4, [r2, r5]
	str r4, [sp, #0xc]
	movs r5, #0x10
	ldrsh r0, [r2, r5]
	str r0, [sp, #0x10]
	cmp r1, #0
	bne _0802282C
	cmp r3, #0
	bne _0802282C
	cmp r4, #0
	bne _0802282C
	movs r0, #4
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r0, [sp, #0xc]
_0802282C:
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r1, #2
	cmp r0, #0
	bne _08022838
	movs r1, #1
_08022838:
	adds r0, r1, #0
	movs r1, #5
	mov r2, sp
	bl FUN_08002800
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0802284c
FUN_0802284c: @ 0x0802284C
	movs r3, #8
	ldrsh r1, [r2, r3]
	str r1, [r0, #0x50]
	movs r3, #0xa
	ldrsh r1, [r2, r3]
	str r1, [r0, #0x54]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0802285c
FUN_0802285c: @ 0x0802285C
	movs r1, #0
	str r1, [r0, #0x50]
	str r1, [r0, #0x54]
	bx lr

	thumb_func_start FUN_08022864
FUN_08022864: @ 0x08022864
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x18
	movs r7, #0
	ldr r0, _0802287C @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r6, #0
	adds r0, #0x1e
	b _08022968
	.align 2, 0
_0802287C: .4byte 0x03002B4C
_08022880:
	ldr r0, _080228B0 @ =0x03002B4C
	ldr r0, [r0]
	lsls r1, r7, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r5, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08022474
	ldrb r0, [r4, #6]
	cmp r0, #7
	bhi _0802295E
	lsls r0, r0, #2
	ldr r1, _080228B4 @ =_080228B8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080228B0: .4byte 0x03002B4C
_080228B4: .4byte _080228B8
_080228B8: @ jump table
	.4byte _080228D8 @ case 0
	.4byte _080228E4 @ case 1
	.4byte _080228F0 @ case 2
	.4byte _080228FC @ case 3
	.4byte _08022908 @ case 4
	.4byte _08022914 @ case 5
	.4byte _08022920 @ case 6
	.4byte _08022934 @ case 7
_080228D8:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08022668
	b _0802292A
_080228E4:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080226a8
	b _0802292A
_080228F0:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08022704
	b _0802292A
_080228FC:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08022770
	b _0802292A
_08022908:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080227f4
	b _0802292A
_08022914:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0802284c
	b _0802292A
_08022920:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0802285c
_0802292A:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08022488
	b _0802295E
_08022934:
	ldrh r0, [r4, #8]
	ldr r3, _0802297C @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r3
	orrs r1, r0
	str r1, [sp]
	ldrh r2, [r4, #0xa]
	lsls r2, r2, #0x10
	ldr r0, _08022980 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	ldrh r1, [r4, #0xc]
	ldr r0, [sp, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	adds r1, r5, #0
	bl FUN_0805f68c
_0802295E:
	adds r7, #1
	ldr r0, _08022984 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r5, #6
_08022968:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r7, r0
	blt _08022880
	movs r0, #0
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0802297C: .4byte 0xFFFF0000
_08022980: .4byte 0x0000FFFF
_08022984: .4byte 0x03002B4C

	thumb_func_start FUN_08022988
FUN_08022988: @ 0x08022988
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08022864
	ldr r0, [r4, #0x50]
	cmp r0, #0
	beq _080229A4
	cmp r0, #0
	ble _0802299E
	subs r0, #1
	str r0, [r4, #0x50]
_0802299E:
	ldr r0, [r4, #0x54]
	bl FUN_0823b9cc
_080229A4:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
_080229AC:
	.byte 0x00, 0xB5, 0x18, 0x30
	.byte 0xFF, 0xF7, 0x3A, 0xFD, 0x00, 0x20, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00

	thumb_func_start FUN_080229bc
FUN_080229bc: @ 0x080229BC
	push {lr}
	adds r0, #0x18
	movs r2, #7
	bl FUN_080223f4
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_080229cc
FUN_080229cc: @ 0x080229CC
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #3
	movs r1, #0x58
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08022A04
	ldr r1, _080229FC @ =FUN_08022988
	ldr r2, _08022A00 @ =0x080229AD
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080229bc
	cmp r0, #0
	bge _08022A04
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08022A06
	.align 2, 0
_080229FC: .4byte FUN_08022988
_08022A00: .4byte 0x080229AD
_08022A04:
	adds r0, r4, #0
_08022A06:
	pop {r4, r5}
	pop {r1}
	bx r1

