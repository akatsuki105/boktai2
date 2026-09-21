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
	bl FUN_08241574
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
	bl FUN_08241574
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

	thumb_func_start FUN_08007890
FUN_08007890: @ 0x08007890
	str r1, [r0, #0x1c]
	movs r1, #0
	str r1, [r0, #0x18]
	movs r1, #1
	strb r1, [r0, #3]
	bx lr

	thumb_func_start FUN_0800789c
FUN_0800789c: @ 0x0800789C
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #3]
	cmp r0, #0
	bne _080078AA
	movs r0, #0
	b _080078B0
_080078AA:
	movs r0, #0
	strb r0, [r1, #3]
	movs r0, #1
_080078B0:
	pop {r1}
	bx r1

	thumb_func_start FUN_080078b4
FUN_080078b4: @ 0x080078B4
	push {r4, r5, r6, lr}
	sub sp, #0x24
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	bl FUN_08236524
	ldrh r0, [r5, #4]
	ldrh r1, [r4, #0x3e]
	subs r0, r0, r1
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _080078E0
	movs r0, #0
	strh r0, [r5, #4]
	ldr r0, _080078DC @ =0x0000014F
	bl PlaySound_082406e0
	b _080078E8
	.align 2, 0
_080078DC: .4byte 0x0000014F
_080078E0:
	movs r0, #0xa7
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080078E8:
	movs r0, #4
	strb r0, [r5, #9]
	adds r0, r5, #0
	adds r0, #0x20
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	ldr r0, [r5, #0x10]
	ldr r1, [r5, #0x14]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	add r0, sp, #0x1c
	ldrh r0, [r0]
	subs r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _08007958 @ =0xFFFF0000
	ldr r2, [sp, #0x1c]
	ands r2, r3
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0x80
	lsls r1, r1, #0x10
	ldr r0, _0800795C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r0, sp, #0x1c
	ldrh r0, [r0, #4]
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x20]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x20]
	adds r0, r6, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r3, r0, #0
	adds r3, #0x80
	ldr r2, _08007960 @ =0x085B0A08
	adds r0, #0xc0
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08007964
	asrs r2, r0, #0xc
	b _0800796A
	.align 2, 0
_08007958: .4byte 0xFFFF0000
_0800795C: .4byte 0x0000FFFF
_08007960: .4byte 0x085B0A08
_08007964:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0800796A:
	add r0, sp, #0x1c
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08007998 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	ldr r1, _0800799C @ =0x085B0A08
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _080079A0
	asrs r2, r0, #0xc
	b _080079A6
	.align 2, 0
_08007998: .4byte 0xFFFF0000
_0800799C: .4byte 0x085B0A08
_080079A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080079A6:
	add r0, sp, #0x1c
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080079EC @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
	movs r0, #0xa4
	str r0, [sp]
	movs r0, #0x10
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r0, #3
	str r0, [sp, #0x10]
	movs r0, #0x1e
	str r0, [sp, #0x14]
	movs r0, #0xf
	str r0, [sp, #0x18]
	movs r0, #4
	movs r1, #3
	add r2, sp, #0x1c
	bl FUN_080149dc
	movs r0, #0xa
	strb r0, [r5, #0xb]
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080079EC: .4byte 0xFFFF0000

	thumb_func_start FUN_080079f0
FUN_080079f0: @ 0x080079F0
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x20
	ldr r1, _08007A20 @ =0x0000F680
	adds r0, r5, #0
	bl Video_GetAuxSprite
	cmp r0, #0
	beq _08007A28
	adds r0, r4, #0
	adds r0, #0x3c
	adds r1, r5, #0
	movs r2, #1
	bl AuxSprite_Add
	ldr r1, _08007A24 @ =FUN_08007a34
	adds r0, r4, #0
	bl FUN_08007890
	movs r0, #0
	strb r0, [r4, #2]
	b _08007A2C
	.align 2, 0
_08007A20: .4byte 0x0000F680
_08007A24: .4byte FUN_08007a34
_08007A28:
	movs r0, #1
	rsbs r0, r0, #0
_08007A2C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08007a34
FUN_08007a34: @ 0x08007A34
	push {lr}
	adds r0, r1, #0
	bl FUN_0800789c
	pop {r0}
	bx r0

	thumb_func_start FUN_08007a40
FUN_08007a40: @ 0x08007A40
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	mov sb, r1
	mov r0, sb
	bl FUN_0800789c
	mov r1, sb
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #0
	ble _08007A60
	b _08007B88
_08007A60:
	ldrh r0, [r1, #0xc]
	cmp r0, #0
	beq _08007A84
	ldrh r0, [r1]
	str r0, [sp, #0x20]
	ldr r1, _08007B7C @ =0xFFFF0000
	ldr r0, [sp, #0x24]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #0x24]
	add r1, sp, #0x24
	add r0, sp, #0x20
	str r0, [r1, #4]
	mov r2, sb
	ldrh r0, [r2, #0xc]
	bl Script_ExecById
_08007A84:
	mov r0, sb
	ldrb r1, [r0, #0xa]
	adds r0, #0x3c
	strh r1, [r0, #0x10]
	mov r2, sb
	adds r2, #0x6e
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08007B80 @ =FUN_08007a34
	mov r0, sb
	bl FUN_08007890
	mov r0, sb
	adds r0, #0x20
	movs r1, #6
	bl Video_SetAuxSpritePltt
	mov r2, sb
	ldr r0, [r2, #0x10]
	ldr r1, [r2, #0x14]
	str r0, [sp, #0x2c]
	str r1, [sp, #0x30]
	add r5, sp, #0x2c
	ldrh r0, [r5]
	subs r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _08007B7C @ =0xFFFF0000
	ldr r1, [sp, #0x2c]
	ands r1, r3
	orrs r1, r0
	lsrs r2, r1, #0x10
	lsls r2, r2, #0x10
	ldr r0, _08007B84 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x2c]
	ldrh r0, [r5, #4]
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r5, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [r5, #4]
	movs r0, #0x80
	lsls r0, r0, #6
	mov sl, r0
	movs r1, #0
	str r1, [sp]
	movs r6, #0x80
	lsls r6, r6, #1
	str r6, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r7, #3
	str r7, [sp, #0xc]
	movs r2, #0xc
	mov sb, r2
	str r2, [sp, #0x10]
	movs r0, #6
	str r0, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #4
	movs r1, #1
	mov r2, sl
	movs r3, #0x40
	bl FUN_08015ce0
	movs r1, #0
	str r1, [sp]
	str r6, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r2, #0xa
	mov r8, r2
	str r2, [sp, #0x10]
	str r4, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #6
	movs r1, #1
	mov r2, sl
	movs r3, #0x40
	bl FUN_08015ce0
	str r6, [sp]
	movs r0, #0x10
	str r0, [sp, #4]
	str r4, [sp, #8]
	mov r0, sb
	str r0, [sp, #0xc]
	str r7, [sp, #0x10]
	movs r0, #0x1e
	str r0, [sp, #0x14]
	movs r0, #0xf
	str r0, [sp, #0x18]
	movs r0, #4
	movs r1, #3
	adds r2, r5, #0
	movs r3, #0
	bl FUN_080149dc
	movs r0, #0x14
	str r0, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	movs r2, #6
	str r2, [sp, #0xc]
	movs r1, #0
	str r1, [sp, #0x10]
	str r6, [sp, #0x14]
	str r0, [sp, #0x18]
	str r4, [sp, #0x1c]
	movs r0, #4
	movs r1, #6
	adds r2, r5, #0
	movs r3, #0
	bl FUN_08014da0
	b _08007C1E
	.align 2, 0
_08007B7C: .4byte 0xFFFF0000
_08007B80: .4byte FUN_08007a34
_08007B84: .4byte 0x0000FFFF
_08007B88:
	mov r2, sb
	ldrb r0, [r2, #9]
	cmp r0, #0
	beq _08007BA4
	subs r0, #1
	strb r0, [r2, #9]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08007BA4
	mov r0, sb
	adds r0, #0x20
	movs r1, #6
	bl Video_SetAuxSpritePltt
_08007BA4:
	mov r1, sb
	ldrb r0, [r1, #0xb]
	cmp r0, #0
	beq _08007C1E
	subs r0, #1
	strb r0, [r1, #0xb]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08007BC8
	mov r2, sb
	adds r2, #0x6e
	ldrh r1, [r2]
	ldr r0, _08007BC4 @ =0x0000FFFB
	ands r0, r1
	b _08007BD2
	.align 2, 0
_08007BC4: .4byte 0x0000FFFB
_08007BC8:
	mov r2, sb
	adds r2, #0x6e
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
_08007BD2:
	strh r0, [r2]
	mov r2, sb
	ldr r0, [r2, #0x10]
	ldr r1, [r2, #0x14]
	str r0, [r2, #0x58]
	str r1, [r2, #0x5c]
	ldr r0, _08007C30 @ =0x0203B400
	mov r8, r0
	ldr r4, _08007C34 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r6, _08007C38 @ =0x000003FF
	ands r1, r6
	str r1, [r4]
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	mov r3, sb
	adds r3, #0x58
	ldrh r0, [r3]
	subs r0, #8
	movs r5, #0xf
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r3]
	adds r1, #1
	ands r1, r6
	str r1, [r4]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	mov r2, sb
	adds r2, #0x5c
	ldrh r0, [r2]
	subs r0, #8
	ands r1, r5
	adds r0, r0, r1
	strh r0, [r2]
_08007C1E:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08007C30: .4byte 0x0203B400
_08007C34: .4byte 0x030046B8
_08007C38: .4byte 0x000003FF

	thumb_func_start FUN_08007c3c
FUN_08007c3c: @ 0x08007C3C
	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x68
	bl FUN_08236424
	adds r4, #0x3c
	adds r0, r4, #0
	bl AuxSprite_Remove
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityED07_Update
EntityED07_Update: @ 0x08007C58
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, [r6, #0x1c]
	cmp r1, #0
	beq _08007C86
	adds r4, r1, #0
	movs r5, #0
	b _08007C80
_08007C68:
	ldrb r0, [r4, #2]
	cmp r0, #0
	beq _08007C7C
	ldr r2, [r4, #0x1c]
	cmp r2, #0
	beq _08007C7C
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
_08007C7C:
	adds r5, #1
	adds r4, #0xb8
_08007C80:
	ldr r0, [r6, #0x18]
	cmp r5, r0
	blt _08007C68
_08007C86:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityED07_Destroy
EntityED07_Destroy: @ 0x08007C90
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x1c]
	cmp r1, #0
	beq _08007CBC
	adds r5, r1, #0
	movs r6, #0
	b _08007CAC
_08007CA0:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08007c3c
	adds r6, #1
	adds r5, #0xb8
_08007CAC:
	ldr r0, [r4, #0x18]
	cmp r6, r0
	blt _08007CA0
	ldr r0, [r4, #0x1c]
	bl Free
	movs r0, #0
	str r0, [r4, #0x1c]
_08007CBC:
	ldr r1, _08007CC8 @ =0x03000030
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08007CC8: .4byte 0x03000030

	thumb_func_start EntityED07_Init
EntityED07_Init: @ 0x08007CCC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08007CF8 @ =0x03000030
	str r5, [r0]
	movs r0, #0x6e
	movs r1, #4
	bl VM_GetKeywordValue
	str r0, [r5, #0x18]
	movs r1, #0xb8
	adds r4, r0, #0
	muls r4, r1, r4
	adds r0, r4, #0
	bl Malloc
	str r0, [r5, #0x1c]
	cmp r0, #0
	bne _08007CFC
	movs r0, #1
	rsbs r0, r0, #0
	bl exit
	.align 2, 0
_08007CF8: .4byte 0x03000030
_08007CFC:
	adds r1, r4, #0
	bl ClearMemory
	ldr r4, [r5, #0x1c]
	movs r6, #0
	b _08007D14
_08007D08:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080079f0
	adds r6, #1
	adds r4, #0xb8
_08007D14:
	ldr r0, [r5, #0x18]
	cmp r6, r0
	blt _08007D08
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityED07_Create
EntityED07_Create: @ 0x08007D24
	push {r4, lr}
	ldr r0, _08007D58 @ =0x03000030
	ldr r0, [r0]
	cmp r0, #0
	bne _08007D66
	movs r0, #8
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08007D64
	ldr r1, _08007D5C @ =EntityED07_Update
	ldr r2, _08007D60 @ =EntityED07_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityED07_Init
	cmp r0, #0
	bge _08007D64
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08007D66
	.align 2, 0
_08007D58: .4byte 0x03000030
_08007D5C: .4byte EntityED07_Update
_08007D60: .4byte EntityED07_Destroy
_08007D64:
	adds r0, r4, #0
_08007D66:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08007d6c
FUN_08007d6c: @ 0x08007D6C
	push {lr}
	ldr r1, [r0, #0x1c]
	movs r2, #0
	ldr r0, [r0, #0x18]
	cmp r2, r0
	bge _08007D8C
	adds r3, r0, #0
_08007D7A:
	ldrb r0, [r1, #2]
	cmp r0, #0
	bne _08007D84
	adds r0, r1, #0
	b _08007D8E
_08007D84:
	adds r2, #1
	adds r1, #0xb8
	cmp r2, r3
	blt _08007D7A
_08007D8C:
	movs r0, #0
_08007D8E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08007d94
FUN_08007d94: @ 0x08007D94
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	ldr r0, _08007E3C @ =0x03000030
	ldr r0, [r0]
	cmp r0, #0
	beq _08007E36
	bl FUN_08007d6c
	adds r6, r0, #0
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	movs r1, #0
	mov sb, r1
	movs r4, #0
	strh r0, [r6]
	mov r0, sb
	strb r0, [r6, #9]
	movs r0, #0x6c
	movs r1, #0xa
	bl VM_GetKeywordValue
	strh r0, [r6, #4]
	strh r4, [r6, #6]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08007DE8
	bl Script_GetValue
	strh r0, [r6, #0x10]
	bl Script_GetValue
	strh r0, [r6, #0x12]
	bl Script_GetValue
	strh r0, [r6, #0x14]
_08007DE8:
	ldr r1, _08007E40 @ =0x0000F680
	movs r0, #0x74
	bl VM_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x50
	movs r1, #0
	bl VM_GetKeywordValue
	mov r8, r0
	movs r0, #0x6b
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r6, #8]
	movs r0, #0x64
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r6, #0xc]
	adds r5, r6, #0
	adds r5, #0x3c
	ldr r0, [r6, #0x3c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x3c]
	ldr r0, [r6, #0x10]
	ldr r1, [r6, #0x14]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	adds r7, r6, #0
	adds r7, #0x20
	adds r0, r7, #0
	adds r1, r4, #0
	bl Video_GetAuxSprite
	cmp r0, #0
	bne _08007E44
_08007E36:
	movs r0, #1
	rsbs r0, r0, #0
	b _08007EDA
	.align 2, 0
_08007E3C: .4byte 0x03000030
_08007E40: .4byte 0x0000F680
_08007E44:
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_0822a4fc
	mov r1, r8
	strh r1, [r5, #0x10]
	movs r0, #2
	strb r0, [r5, #7]
	ldr r1, _08007EE8 @ =FUN_08007a40
	adds r0, r6, #0
	bl FUN_08007890
	mov r0, r8
	adds r0, #1
	strb r0, [r6, #0xa]
	mov r0, sb
	strb r0, [r6, #9]
	adds r5, r6, #0
	adds r5, #0x68
	ldr r2, _08007EEC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r4, #0x80
	orrs r0, r4
	ldr r3, _08007EF0 @ =0x0000FFFF
	ands r0, r3
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r4
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	ldr r1, _08007EF4 @ =0x0000FF80
	orrs r0, r1
	ands r0, r3
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r4
	str r0, [r3, #4]
	ldrh r1, [r6]
	ldr r2, _08007EF8 @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _08007EFC @ =FUN_080078b4
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_0823651c
	adds r1, r6, #0
	adds r1, #0x10
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	movs r1, #1
	strb r1, [r6, #2]
_08007EDA:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08007EE8: .4byte FUN_08007a40
_08007EEC: .4byte 0xFFFF0000
_08007EF0: .4byte 0x0000FFFF
_08007EF4: .4byte 0x0000FF80
_08007EF8: .4byte 0x00004001
_08007EFC: .4byte FUN_080078b4
