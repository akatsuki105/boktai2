	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080070a8
FUN_080070a8: @ 0x080070A8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	mov sb, r0
	adds r6, r1, #0
	adds r7, r2, #0
	mov r8, r3
	bl MapItemManager_Ensure
	adds r4, r0, #0
	cmp r4, #0
	beq _08007126
	movs r0, #0xbc
	bl Malloc
	adds r5, r0, #0
	cmp r5, #0
	beq _08007126
	adds r0, r5, #0
	movs r1, #0xbc
	bl ClearMemory
	movs r2, #0
	movs r1, #0
	strh r6, [r5]
	strh r7, [r5, #2]
	movs r0, #0xff
	strb r0, [r5, #4]
	strb r2, [r5, #5]
	strb r2, [r5, #6]
	strb r2, [r5, #7]
	str r1, [r5, #0x18]
	str r1, [r5, #0x1c]
	str r1, [r5, #0x20]
	str r1, [r5, #0x24]
	str r1, [r5, #0x28]
	ldr r0, _0800712C @ =MapItem_UpdateFall
	str r0, [r5, #0x44]
	strb r2, [r5, #0xc]
	ldr r0, [sp, #0x44]
	strb r0, [r5, #0x14]
	mov r0, r8
	str r0, [r5, #0x34]
	ldr r3, [sp, #0x38]
	adds r2, r5, #0
	adds r2, #0x38
	movs r1, #2
_0800710A:
	ldm r3!, {r0}
	stm r2!, {r0}
	subs r1, #1
	cmp r1, #0
	bge _0800710A
	movs r0, #0x28
	bl Malloc
	str r0, [r5, #0x1c]
	cmp r0, #0
	bne _08007130
	adds r0, r5, #0
	bl Free
_08007126:
	movs r0, #1
	rsbs r0, r0, #0
	b _080071FC
	.align 2, 0
_0800712C: .4byte MapItem_UpdateFall
_08007130:
	movs r1, #0x28
	bl ClearMemory
	ldr r0, [r5, #0x1c]
	ldr r1, [r4, #0x18]
	movs r2, #0
	bl FUN_0822d9f0
	ldr r0, [r5, #0x1c]
	movs r1, #8
	rsbs r1, r1, #0
	movs r2, #0xa
	rsbs r2, r2, #0
	bl Particle_SetOffset
	mov r0, sb
	movs r1, #0x80
	bl FUN_082342cc
	cmp r0, #0
	beq _0800717C
	ldr r2, [r5, #0x1c]
	ldr r3, [r4, #0x18]
	ldrb r1, [r2, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r2, #0xb]
	lsrs r0, r0, #3
	muls r1, r0, r1
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	subs r0, r0, r1
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #8]
	ldr r1, [r5, #0x1c]
	movs r0, #1
	b _08007196
_0800717C:
	ldr r2, [r5, #0x1c]
	ldr r3, [r4, #0x18]
	ldrb r1, [r2, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r2, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	lsls r0, r0, #5
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #8]
	ldr r1, [r5, #0x1c]
	movs r0, #2
_08007196:
	strb r0, [r1, #0xf]
	ldr r2, [r5, #0x1c]
	mov r3, sb
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2, #0x18]
	str r1, [r2, #0x1c]
	ldr r1, [r5, #0x1c]
	movs r0, #0x10
	strb r0, [r1, #0x10]
	ldr r0, [r5, #0x1c]
	adds r0, #0x18
	str r0, [r5, #0x2c]
	ldr r1, [sp, #0x3c]
	cmp r1, #0
	beq _080071BE
	bl GetMapAreaAt
	strh r0, [r5, #0x16]
	b _080071C4
_080071BE:
	mov r3, sp
	ldrh r3, [r3, #0x3c]
	strh r3, [r5, #0x16]
_080071C4:
	movs r4, #0
	ldr r0, [sp, #0x40]
	strb r0, [r5, #8]
	adds r0, r5, #0
	adds r0, #0x48
	ldr r1, [r5, #0x1c]
	adds r1, #0x18
	movs r2, #0x28
	str r2, [sp]
	movs r2, #0x20
	str r2, [sp, #4]
	movs r2, #0x80
	lsls r2, r2, #2
	str r2, [sp, #8]
	movs r3, #1
	str r3, [sp, #0xc]
	movs r2, #5
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r2, #0x40
	movs r3, #0x18
	bl AuxShadow_Init
	adds r0, r5, #0
	bl MapItem_Link
	movs r0, #0
_080071FC:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800720c
FUN_0800720c: @ 0x0800720C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08007260
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08007258 @ =0xFFFF0000
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800725C @ =0x0000FFFF
	ldr r1, [sp, #0x1c]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r2, sp, #0x1c
	ldr r1, [r2, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r2, #4]
	b _0800726C
	.align 2, 0
_08007258: .4byte 0xFFFF0000
_0800725C: .4byte 0x0000FFFF
_08007260:
	ldr r2, _08007284 @ =0xFFFF0000
	str r0, [sp, #0x1c]
	add r1, sp, #0x1c
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
_0800726C:
	movs r0, #0x49
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08007288
	bl Script_GetValue
	mov sb, r0
	bl Script_GetValue
	b _0800728C
	.align 2, 0
_08007284: .4byte 0xFFFF0000
_08007288:
	movs r0, #0
	mov sb, r0
_0800728C:
	mov r8, r0
	movs r0, #0x70
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [sp, #0x24]
	movs r0, #0x4d
	movs r1, #0
	bl VM_GetKeywordValue
	mov sl, r0
	movs r0, #0x69
	movs r1, #0
	bl VM_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x4f
	movs r1, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r1, #0
	add r0, sp, #0x18
_080072BA:
	str r1, [r0]
	subs r0, #4
	add r2, sp, #0x10
	cmp r0, r2
	bge _080072BA
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080072E8
	movs r4, #0
	add r5, sp, #0x10
	b _080072DC
_080072D4:
	bl Script_GetValue
	stm r5!, {r0}
	adds r4, #1
_080072DC:
	bl VM_GetPC
	cmp r0, #0
	beq _080072E8
	cmp r4, #2
	ble _080072D4
_080072E8:
	add r0, sp, #0x10
	str r0, [sp]
	mov r2, sl
	str r2, [sp, #4]
	str r7, [sp, #8]
	str r6, [sp, #0xc]
	add r0, sp, #0x1c
	mov r1, sb
	mov r2, r8
	ldr r3, [sp, #0x24]
	bl FUN_080070a8
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08007310
FUN_08007310: @ 0x08007310
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	mov sb, r0
	adds r4, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	bl MapItemManager_Ensure
	mov r8, r0
	cmp r0, #0
	bne _0800732E
	b _08007428
_0800732E:
	movs r0, #0xbc
	bl Malloc
	adds r5, r0, #0
	cmp r5, #0
	beq _08007428
	adds r0, r5, #0
	movs r1, #0xbc
	bl ClearMemory
	movs r2, #0
	movs r1, #0
	strh r4, [r5]
	strh r6, [r5, #2]
	movs r0, #0xff
	strb r0, [r5, #4]
	movs r0, #1
	strb r0, [r5, #5]
	strb r2, [r5, #6]
	strb r7, [r5, #7]
	str r1, [r5, #0x18]
	str r1, [r5, #0x1c]
	str r1, [r5, #0x20]
	str r1, [r5, #0x24]
	str r1, [r5, #0x28]
	ldr r0, [sp, #0x38]
	cmp r0, #0
	beq _0800738C
	ldr r0, _08007380 @ =MapItem_UpdateAppear
	str r0, [r5, #0x44]
	ldr r0, _08007384 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08007390
	ldr r0, _08007388 @ =0x0000026F
	bl PlaySound_082406e0
	b _08007390
	.align 2, 0
_08007380: .4byte MapItem_UpdateAppear
_08007384: .4byte 0x030047A4
_08007388: .4byte 0x0000026F
_0800738C:
	ldr r0, _080073CC @ =MapItem_UpdateIdle
	str r0, [r5, #0x44]
_08007390:
	ldr r0, [sp, #0x3c]
	str r0, [r5, #0x30]
	ldr r0, [sp, #0x40]
	str r0, [r5, #0x34]
	ldr r3, [sp, #0x44]
	adds r2, r5, #0
	adds r2, #0x38
	movs r1, #2
_080073A0:
	ldm r3!, {r0}
	stm r2!, {r0}
	subs r1, #1
	cmp r1, #0
	bge _080073A0
	movs r0, #0x2c
	bl Malloc
	str r0, [r5, #0x20]
	cmp r0, #0
	beq _08007422
	movs r1, #0x2c
	bl ClearMemory
	movs r0, #0x1c
	bl Malloc
	str r0, [r5, #0x24]
	cmp r0, #0
	bne _080073D0
	ldr r0, [r5, #0x20]
	b _0800741A
	.align 2, 0
_080073CC: .4byte MapItem_UpdateIdle
_080073D0:
	movs r1, #0x1c
	bl ClearMemory
	movs r0, #0x10
	bl Malloc
	str r0, [r5, #0x28]
	cmp r0, #0
	bne _080073F0
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq _080073EC
	bl Free
_080073EC:
	ldr r0, [r5, #0x24]
	b _0800741A
_080073F0:
	movs r1, #0x10
	bl ClearMemory
	ldr r0, [r5, #0x24]
	mov r2, r8
	ldrh r1, [r2, #0x20]
	bl Video_GetAuxSprite
	cmp r0, #0
	bne _0800742E
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq _0800740E
	bl Free
_0800740E:
	ldr r0, [r5, #0x24]
	cmp r0, #0
	beq _08007418
	bl Free
_08007418:
	ldr r0, [r5, #0x28]
_0800741A:
	cmp r0, #0
	beq _08007422
	bl Free
_08007422:
	adds r0, r5, #0
	bl Free
_08007428:
	movs r0, #1
	rsbs r0, r0, #0
	b _08007630
_0800742E:
	ldr r0, [r5, #0x20]
	ldr r1, [r5, #0x24]
	movs r2, #0
	bl AuxSprite_Add
	ldr r2, [r5, #0x20]
	mov r3, sb
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r0, [r5, #0x20]
	adds r6, r0, #0
	adds r6, #0x1c
	ldrh r0, [r0, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800746E
	cmp r1, #0
	blt _0800746E
	ldr r0, _08007474 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800746E
	ldr r0, _08007478 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800747C
_0800746E:
	movs r4, #0
	b _0800748A
	.align 2, 0
_08007474: .4byte 0x030046A8
_08007478: .4byte 0x030046AC
_0800747C:
	ldr r0, _0800749C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0800748A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080074A0
	adds r0, #4
	b _080074AC
	.align 2, 0
_0800749C: .4byte 0x030046A4
_080074A0:
	ldr r0, _080074C0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080074AC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080074C4
	cmp r2, #2
	beq _080074C8
	b _080074CC
	.align 2, 0
_080074C0: .4byte 0x030046A4
_080074C4:
	ldrb r0, [r6, #4]
	b _080074CA
_080074C8:
	ldrb r0, [r6]
_080074CA:
	subs r1, r1, r0
_080074CC:
	ldr r0, [r5, #0x20]
	strh r1, [r0, #0x1e]
	ldrb r0, [r5, #7]
	cmp r0, #0
	beq _080074E0
	ldr r0, [r5, #0x20]
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	str r1, [r0]
_080074E0:
	ldr r0, [r5, #0x20]
	adds r0, #0x1c
	str r0, [r5, #0x2c]
	ldr r0, [sp, #0x4c]
	strb r0, [r5, #9]
	add r0, sp, #0x50
	ldrb r0, [r0]
	strb r0, [r5, #0x15]
	ldr r1, [sp, #0x50]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _08007508
	ldr r0, [r5, #0x24]
	ldr r1, _08007504 @ =0x0000028A
	bl Video_SetAuxSpritePltt
	b _08007524
	.align 2, 0
_08007504: .4byte 0x0000028A
_08007508:
	cmp r0, #1
	bne _0800751C
	ldr r0, [r5, #0x24]
	ldr r1, _08007518 @ =0x0000028D
	bl Video_SetAuxSpritePltt
	b _08007524
	.align 2, 0
_08007518: .4byte 0x0000028D
_0800751C:
	ldr r0, [r5, #0x24]
	ldr r1, _08007568 @ =0x0000028E
	bl Video_SetAuxSpritePltt
_08007524:
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _080075CA
	ldr r2, [r5, #0x20]
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r0, _0800756C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08007580
	ldr r0, _08007570 @ =0x03002BE0
	ldr r1, [r0]
	cmp r1, #0
	beq _0800757C
	ldr r2, _08007574 @ =0x00000446
	adds r0, r1, r2
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #0
	beq _08007562
	ldr r3, _08007578 @ =0x00000442
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #4
	bne _08007562
	movs r2, #1
_08007562:
	adds r0, r2, #0
	b _080075B0
	.align 2, 0
_08007568: .4byte 0x0000028E
_0800756C: .4byte 0x030047A4
_08007570: .4byte 0x03002BE0
_08007574: .4byte 0x00000446
_08007578: .4byte 0x00000442
_0800757C:
	movs r0, #0
	b _080075B0
_08007580:
	ldr r0, _080075B8 @ =0x03002B48
	ldr r0, [r0]
	cmp r0, #0
	bgt _080075B4
	ldr r0, _080075BC @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #2
	beq _080075B4
	ldr r0, _080075C0 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080075AE
	ldr r0, _080075C4 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #4
	bne _080075AE
	movs r1, #1
_080075AE:
	adds r0, r1, #0
_080075B0:
	cmp r0, #0
	beq _080075C8
_080075B4:
	movs r0, #0
	b _080075CA
	.align 2, 0
_080075B8: .4byte 0x03002B48
_080075BC: .4byte 0x030046A0
_080075C0: .4byte 0x03002B8C
_080075C4: .4byte 0x03002B60
_080075C8:
	movs r0, #1
_080075CA:
	strb r0, [r5, #0xa]
	ldr r0, [r5, #0x28]
	mov r3, r8
	ldr r1, [r3, #0x1c]
	movs r2, #0
	str r2, [sp]
	movs r3, #0
	bl FUN_08236fac
	ldr r0, [sp, #0x48]
	cmp r0, #0
	beq _080075EE
	ldr r0, [r5, #0x20]
	adds r0, #0x1c
	bl GetMapAreaAt
	strh r0, [r5, #0x16]
	b _080075F4
_080075EE:
	add r1, sp, #0x48
	ldrh r1, [r1]
	strh r1, [r5, #0x16]
_080075F4:
	adds r4, r5, #0
	adds r4, #0x48
	ldr r1, [r5, #0x20]
	adds r1, #0x1c
	movs r0, #0x28
	str r0, [sp]
	movs r0, #0x20
	str r0, [sp, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #8]
	movs r2, #1
	str r2, [sp, #0xc]
	movs r0, #5
	str r0, [sp, #0x10]
	str r2, [sp, #0x14]
	movs r0, #0
	str r0, [sp, #0x18]
	adds r0, r4, #0
	movs r2, #0x40
	movs r3, #0x18
	bl AuxShadow_Init
	adds r0, r4, #0
	bl AuxShadow_Hide
	adds r0, r5, #0
	bl MapItem_Link
	movs r0, #0
_08007630:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08007640
FUN_08007640: @ 0x08007640
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08007694
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800768C @ =0xFFFF0000
	ldr r1, [sp, #0x28]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x28]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08007690 @ =0x0000FFFF
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
	b _080076A0
	.align 2, 0
_0800768C: .4byte 0xFFFF0000
_08007690: .4byte 0x0000FFFF
_08007694:
	ldr r2, _080076B8 @ =0xFFFF0000
	str r0, [sp, #0x28]
	add r1, sp, #0x28
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
_080076A0:
	movs r0, #0x49
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080076BC
	bl Script_GetValue
	str r0, [sp, #0x34]
	bl Script_GetValue
	b _080076C0
	.align 2, 0
_080076B8: .4byte 0xFFFF0000
_080076BC:
	movs r0, #0
	str r0, [sp, #0x34]
_080076C0:
	mov sl, r0
	movs r0, #0x64
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [sp, #0x30]
	movs r0, #0x67
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [sp, #0x38]
	movs r0, #0x70
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [sp, #0x3c]
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	mov r8, r0
	movs r0, #0x4d
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r0
	movs r0, #0x53
	movs r1, #0
	bl VM_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x63
	movs r1, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r1, #0
	add r0, sp, #0x24
_0800770C:
	str r1, [r0]
	subs r0, #4
	add r2, sp, #0x1c
	cmp r0, r2
	bge _0800770C
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0800773A
	movs r4, #0
	add r5, sp, #0x1c
	b _0800772E
_08007726:
	bl Script_GetValue
	stm r5!, {r0}
	adds r4, #1
_0800772E:
	bl VM_GetPC
	cmp r0, #0
	beq _0800773A
	cmp r4, #2
	ble _08007726
_0800773A:
	mov r0, r8
	str r0, [sp]
	ldr r2, [sp, #0x38]
	str r2, [sp, #4]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #8]
	add r2, sp, #0x1c
	str r2, [sp, #0xc]
	mov r0, sb
	str r0, [sp, #0x10]
	str r7, [sp, #0x14]
	str r6, [sp, #0x18]
	add r0, sp, #0x28
	ldr r1, [sp, #0x34]
	mov r2, sl
	ldr r3, [sp, #0x30]
	bl FUN_08007310
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08007770
FUN_08007770: @ 0x08007770
	push {r4, r5, lr}
	adds r5, r0, #0
	bl MapItemManager_Ensure
	adds r1, r0, #0
	cmp r1, #0
	bne _08007784
	movs r0, #1
	rsbs r0, r0, #0
	b _080077A2
_08007784:
	ldr r2, [r1, #0x28]
	cmp r2, #0
	beq _080077A2
_0800778A:
	adds r1, r2, #0
	adds r1, #0xb8
	ldr r4, [r1]
	ldrb r1, [r2, #5]
	cmp r1, r5
	bne _0800779C
	adds r0, r2, #0
	bl MapItem_Free
_0800779C:
	adds r2, r4, #0
	cmp r2, #0
	bne _0800778A
_080077A2:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080077a8
FUN_080077a8: @ 0x080077A8
	push {lr}
	movs r0, #0x74
	movs r1, #0
	bl VM_GetKeywordValue
	bl FUN_08007770
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080077bc
FUN_080077bc: @ 0x080077BC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	bl MapItemManager_Ensure
	adds r1, r0, #0
	cmp r1, #0
	bne _080077D4
	movs r0, #1
	rsbs r0, r0, #0
	b _08007816
_080077D4:
	ldr r2, [r1, #0x28]
	cmp r2, #0
	beq _08007816
	ldr r1, _0800781C @ =MapItem_UpdateExpire
	mov ip, r1
_080077DE:
	adds r1, r2, #0
	adds r1, #0xb8
	ldr r4, [r1]
	ldrb r1, [r2, #5]
	cmp r1, #0
	bne _08007810
	ldrb r1, [r2, #0x14]
	cmp r1, #0
	beq _08007810
	movs r3, #0
	ldrsh r1, [r2, r3]
	cmp r1, r6
	bne _08007810
	movs r3, #2
	ldrsh r1, [r2, r3]
	cmp r1, r5
	bne _08007810
	ldr r1, [r2, #0x44]
	cmp r1, ip
	beq _08007810
	ldr r3, [r2, #0x2c]
	ldr r1, [r7]
	ldr r2, [r7, #4]
	str r1, [r3]
	str r2, [r3, #4]
_08007810:
	adds r2, r4, #0
	cmp r2, #0
	bne _080077DE
_08007816:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800781C: .4byte MapItem_UpdateExpire

	thumb_func_start FUN_08007820
FUN_08007820: @ 0x08007820
	push {r4, r5, r6, lr}
	sub sp, #8
	movs r0, #0x6b
	movs r1, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x69
	movs r1, #0
	bl VM_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08007874
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08007888 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800788C @ =0x0000FFFF
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
_08007874:
	mov r0, sp
	adds r1, r6, #0
	adds r2, r5, #0
	bl FUN_080077bc
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08007888: .4byte 0xFFFF0000
_0800788C: .4byte 0x0000FFFF

