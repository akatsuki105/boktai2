	.include "asm/macros.inc"

	.syntax unified
	
	.text

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

	thumb_func_start Entity08019200_Update
Entity08019200_Update: @ 0x080191A0
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

	thumb_func_start Entity08019200_Destroy
Entity08019200_Destroy: @ 0x080191DC
	ldr r1, _080191E4 @ =0x0300008C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080191E4: .4byte 0x0300008C

	thumb_func_start Entity08019200_Init
Entity08019200_Init: @ 0x080191E8
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

	thumb_func_start Entity08019200_Create
Entity08019200_Create: @ 0x08019200
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
	ldr r1, _0801923C @ =Entity08019200_Update
	ldr r2, _08019240 @ =Entity08019200_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity08019200_Init
	cmp r0, #0
	bge _08019244
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08019246
	.align 2, 0
_08019238: .4byte 0x0300008C
_0801923C: .4byte Entity08019200_Update
_08019240: .4byte Entity08019200_Destroy
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
	bl Entity08019200_Create
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
	bl VM_SeekToKeyword
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
	bl VM_SeekToKeyword
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
	bl VM_SeekToKeyword
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
	bl VM_GetKeywordValue
	movs r4, #0
	strb r0, [r5, #0xc]
	strb r4, [r5, #0xd]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r5, #0xe]
	strb r4, [r5, #0xf]
	movs r0, #0x53
	movs r1, #0xa
	bl VM_GetKeywordValue
	strb r0, [r5, #0x10]
	movs r0, #0x44
	movs r1, #0xa
	bl VM_GetKeywordValue
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
