	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a4e94
FUN_080a4e94: @ 0x080A4E94
	push {r4, r5, r6, lr}
	ldr r4, _080A4EAC @ =0x03002C48
	ldr r0, [r4]
	cmp r0, #0
	beq _080A4EE0
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	bne _080A4EB8
	b _080A4EE0
	.align 2, 0
_080A4EAC: .4byte 0x03002C48
_080A4EB0:
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r5, r0
	b _080A4EE2
_080A4EB8:
	bl VM_GetValue
	adds r6, r0, #0
	movs r2, #0
	ldr r0, [r4]
	ldrb r1, [r0, #0x19]
	cmp r2, r1
	bge _080A4EE0
	adds r5, r0, #0
	adds r4, r1, #0
	adds r1, r5, #0
	movs r3, #0
_080A4ED0:
	ldrh r0, [r1, #0x1c]
	cmp r0, r6
	beq _080A4EB0
	adds r1, #0xb8
	adds r3, #0xb8
	adds r2, #1
	cmp r2, r4
	blt _080A4ED0
_080A4EE0:
	movs r0, #0
_080A4EE2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a4ee8
FUN_080a4ee8: @ 0x080A4EE8
	push {r4, lr}
	bl FUN_080a4e94
	adds r4, r0, #0
	cmp r4, #0
	beq _080A4F4E
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4F4E
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x78
	strh r0, [r1]
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x7a
	strh r0, [r1]
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x7c
	strh r0, [r1]
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4F4E
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x80
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080A4F4E
	ldrb r1, [r4, #2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #2]
	ldr r0, [r4, #0x44]
	ldr r1, [r4, #0x48]
	str r0, [r4, #0x70]
	str r1, [r4, #0x74]
	adds r1, r4, #0
	adds r1, #0x82
	movs r0, #0
	strh r0, [r1]
_080A4F4E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a4f54
FUN_080a4f54: @ 0x080A4F54
	push {r4, lr}
	bl FUN_080a4e94
	adds r4, r0, #0
	cmp r4, #0
	beq _080A4F70
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4F70
	bl VM_GetValue
	strh r0, [r4, #0x38]
_080A4F70:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a4f78
FUN_080a4f78: @ 0x080A4F78
	push {lr}
	bl FUN_080a4e94
	adds r2, r0, #0
	cmp r2, #0
	beq _080A4F8C
	ldr r0, [r2, #0x28]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #0x28]
_080A4F8C:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a4f90
FUN_080a4f90: @ 0x080A4F90
	push {lr}
	bl FUN_080a4e94
	adds r2, r0, #0
	cmp r2, #0
	beq _080A4FA6
	ldr r0, [r2, #0x28]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #0x28]
_080A4FA6:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a4fac
FUN_080a4fac: @ 0x080A4FAC
	push {r4, lr}
	bl FUN_080a4e94
	adds r4, r0, #0
	cmp r4, #0
	beq _080A4FCC
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4FCC
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x2f
	strb r0, [r1]
_080A4FCC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a4fd4
FUN_080a4fd4: @ 0x080A4FD4
	push {r4, r5, lr}
	bl FUN_080a4e94
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5046
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5046
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x86
	strh r0, [r1]
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5046
	bl VM_GetValue
	adds r5, r4, #0
	adds r5, #0x88
	strh r0, [r5]
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5046
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x8c
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _080A5036
	adds r0, r4, #0
	adds r0, #0x54
	subs r1, #8
	ldrh r1, [r1]
	ldrh r2, [r5]
	adds r1, r1, r2
	bl Video_SetAuxSpritePltt
	b _080A5046
_080A5036:
	adds r1, r4, #0
	adds r1, #0x8a
	movs r0, #0
	strh r0, [r1]
	ldrb r1, [r4, #2]
	movs r0, #2
	orrs r0, r1
	strb r0, [r4, #2]
_080A5046:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a504c
FUN_080a504c: @ 0x080A504C
	push {r4, r5, lr}
	bl FUN_080a4e94
	adds r4, r0, #0
	cmp r4, #0
	beq _080A50D2
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A50D2
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x90
	strh r0, [r1]
	movs r0, #0x65
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A50D2
	bl VM_GetValue
	adds r5, r4, #0
	adds r5, #0x92
	strh r0, [r5]
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A50D2
	bl VM_GetValue
	adds r2, r4, #0
	adds r2, #0x96
	strh r0, [r2]
	ldrh r0, [r5]
	adds r3, r4, #0
	adds r3, #0x30
	strb r0, [r3]
	adds r1, r4, #0
	adds r1, #0x31
	strb r0, [r1]
	ldrh r0, [r2]
	cmp r0, #1
	bhi _080A50BA
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0x40
	beq _080A50D2
	ldr r0, [r4, #0x28]
	movs r1, #2
	orrs r0, r1
	str r0, [r4, #0x28]
	b _080A50D2
_080A50BA:
	ldr r0, [r4, #0x28]
	movs r1, #2
	orrs r0, r1
	str r0, [r4, #0x28]
	adds r1, r4, #0
	adds r1, #0x94
	movs r0, #0
	strh r0, [r1]
	ldrb r0, [r4, #2]
	movs r1, #4
	orrs r0, r1
	strb r0, [r4, #2]
_080A50D2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a50d8
FUN_080a50d8: @ 0x080A50D8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	bl FUN_080a4e94
	adds r5, r0, #0
	cmp r5, #0
	beq _080A51CC
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A51CC
	bl VM_GetValue
	adds r7, r5, #0
	adds r7, #0x98
	strb r0, [r7]
	movs r0, #0x64
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A51CC
	bl VM_GetValue
	adds r6, r5, #0
	adds r6, #0x99
	strb r0, [r6]
	movs r0, #0x72
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A51CC
	bl VM_GetValue
	strb r0, [r5, #3]
	movs r4, #0
	movs r0, #0x45
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5130
	bl VM_GetValue
	adds r4, r0, #0
_080A5130:
	cmp r4, #0
	beq _080A514E
	adds r4, r5, #0
	adds r4, #0x9c
	adds r0, r5, #0
	adds r0, #0xac
	ldr r1, [r0]
	ldrb r2, [r7]
	ldrb r3, [r6]
	ldrb r0, [r5, #3]
	str r0, [sp]
	adds r0, r4, #0
	bl AuxAnim_RestartAnim
	b _080A5166
_080A514E:
	adds r4, r5, #0
	adds r4, #0x9c
	adds r0, r5, #0
	adds r0, #0xac
	ldr r1, [r0]
	ldrb r2, [r7]
	ldrb r3, [r6]
	ldrb r0, [r5, #3]
	str r0, [sp]
	adds r0, r4, #0
	bl AuxAnim_SetAnim
_080A5166:
	movs r0, #0x50
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5180
	bl VM_GetValue
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
_080A5180:
	movs r0, #0x6f
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A519A
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0x9a
	strb r0, [r1]
	adds r0, r1, #0
	b _080A51A0
_080A519A:
	adds r0, r5, #0
	adds r0, #0x9a
	strb r1, [r0]
_080A51A0:
	ldrb r1, [r0]
	cmp r1, #0
	beq _080A51BE
	movs r0, #0x65
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A51BE
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xb0
	str r0, [r1]
	b _080A51C4
_080A51BE:
	adds r0, r5, #0
	adds r0, #0xb0
	str r1, [r0]
_080A51C4:
	ldrb r1, [r5, #2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r5, #2]
_080A51CC:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a51d4
FUN_080a51d4: @ 0x080A51D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldrb r1, [r7, #2]
	cmp r1, #0
	bne _080A51EA
	b _080A5556
_080A51EA:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080A5284
	adds r6, r7, #0
	adds r6, #0x82
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	adds r5, r7, #0
	adds r5, #0x80
	ldrh r1, [r5]
	ldrh r3, [r6]
	subs r4, r1, r3
	adds r0, r7, #0
	adds r0, #0x70
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r2, r0, #0
	muls r2, r4, r2
	mov r8, r2
	adds r2, r7, #0
	adds r2, #0x78
	movs r0, #0
	ldrsh r2, [r2, r0]
	muls r2, r3, r2
	mov r3, r8
	adds r0, r3, r2
	bl Div
	adds r1, r7, #0
	adds r1, #0x44
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x72
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	adds r1, r7, #0
	adds r1, #0x7a
	movs r3, #0
	ldrsh r2, [r1, r3]
	ldrh r1, [r6]
	muls r1, r2, r1
	adds r0, r0, r1
	ldrh r1, [r5]
	bl Div
	adds r1, r7, #0
	adds r1, #0x46
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x74
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	adds r1, r7, #0
	adds r1, #0x7c
	movs r3, #0
	ldrsh r2, [r1, r3]
	ldrh r1, [r6]
	muls r1, r2, r1
	adds r0, r0, r1
	ldrh r1, [r5]
	bl Div
	adds r1, r7, #0
	adds r1, #0x48
	strh r0, [r1]
	ldrh r0, [r6]
	ldrh r5, [r5]
	cmp r0, r5
	blo _080A5284
	ldrb r1, [r7, #2]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #2]
_080A5284:
	ldrb r1, [r7, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080A5290
	b _080A53B6
_080A5290:
	adds r3, r7, #0
	adds r3, #0x8a
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	adds r4, r7, #0
	adds r4, #0x8c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r4]
	cmp r0, r1
	blo _080A52C8
	adds r0, r7, #0
	adds r0, #0x54
	adds r1, r7, #0
	adds r1, #0x84
	ldrh r1, [r1]
	adds r2, r7, #0
	adds r2, #0x88
	ldrh r2, [r2]
	adds r1, r1, r2
	bl Video_SetAuxSpritePltt
	ldrb r1, [r7, #2]
	movs r0, #0xfd
	ands r0, r1
	strb r0, [r7, #2]
	b _080A53B6
_080A52C8:
	ldr r2, _080A5408 @ =0x03003584
	adds r0, r7, #0
	adds r0, #0x84
	ldrh r1, [r0]
	adds r0, #2
	ldrh r0, [r0]
	adds r0, r1, r0
	lsls r0, r0, #5
	ldr r2, [r2]
	adds r0, r2, r0
	str r0, [sp, #4]
	adds r0, r7, #0
	adds r0, #0x88
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r2, r2, r1
	str r2, [sp, #8]
	ldrh r1, [r4]
	ldrh r0, [r3]
	subs r1, r1, r0
	str r1, [sp, #0xc]
	adds r2, r7, #0
	adds r2, #8
	str r2, [sp, #0x14]
	adds r0, r7, #0
	adds r0, #0x5a
	str r0, [sp, #0x18]
	str r3, [sp, #0x10]
	mov sb, r4
	mov sl, r2
	movs r1, #0xf
	str r1, [sp]
_080A530A:
	ldr r2, [sp, #4]
	ldrh r5, [r2]
	movs r0, #0x1f
	ands r0, r5
	lsls r5, r5, #0x10
	lsrs r3, r5, #0x15
	movs r1, #0x1f
	ands r3, r1
	lsrs r5, r5, #0x1a
	ands r5, r1
	ldr r2, [sp, #8]
	ldrh r4, [r2]
	movs r2, #0x1f
	ands r2, r4
	lsls r4, r4, #0x10
	lsrs r6, r4, #0x15
	ands r6, r1
	lsrs r4, r4, #0x1a
	ands r4, r1
	ldr r1, [sp, #0xc]
	muls r0, r1, r0
	ldr r1, [sp, #0x10]
	ldrh r1, [r1]
	mov r8, r1
	mov r1, r8
	muls r1, r2, r1
	adds r0, r0, r1
	mov r2, sb
	ldrh r1, [r2]
	str r3, [sp, #0x1c]
	bl Div
	mov r8, r0
	ldr r3, [sp, #0x1c]
	ldr r1, [sp, #0xc]
	adds r0, r3, #0
	muls r0, r1, r0
	ldr r2, [sp, #0x10]
	ldrh r1, [r2]
	muls r1, r6, r1
	adds r0, r0, r1
	mov r3, sb
	ldrh r1, [r3]
	bl Div
	adds r6, r0, #0
	ldr r1, [sp, #0xc]
	adds r0, r5, #0
	muls r0, r1, r0
	ldr r2, [sp, #0x10]
	ldrh r1, [r2]
	muls r1, r4, r1
	adds r0, r0, r1
	mov r3, sb
	ldrh r1, [r3]
	bl Div
	lsls r0, r0, #0xa
	lsls r6, r6, #5
	orrs r0, r6
	mov r1, r8
	orrs r0, r1
	mov r2, sl
	strh r0, [r2]
	ldr r3, [sp, #4]
	adds r3, #2
	str r3, [sp, #4]
	ldr r0, [sp, #8]
	adds r0, #2
	str r0, [sp, #8]
	movs r1, #2
	add sl, r1
	ldr r2, [sp]
	subs r2, #1
	str r2, [sp]
	cmp r2, #0
	bge _080A530A
	ldr r3, [sp, #0x14]
	str r3, [r7, #0x60]
	movs r1, #0x96
	lsls r1, r1, #2
	adds r0, r1, #0
	ldrh r2, [r7]
	adds r0, r0, r2
	ldr r3, [sp, #0x18]
	strh r0, [r3]
_080A53B6:
	ldrb r1, [r7, #2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080A543A
	adds r3, r7, #0
	adds r3, #0x94
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	adds r4, r7, #0
	adds r4, #0x96
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r4]
	cmp r0, r1
	blo _080A540C
	adds r0, r7, #0
	adds r0, #0x92
	ldrh r0, [r0]
	adds r1, r7, #0
	adds r1, #0x30
	strb r0, [r1]
	adds r2, r7, #0
	adds r2, #0x31
	strb r0, [r2]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x40
	bne _080A53FC
	ldr r0, [r7, #0x28]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #0x28]
_080A53FC:
	ldrb r1, [r7, #2]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #2]
	b _080A543A
	.align 2, 0
_080A5408: .4byte 0x03003584
_080A540C:
	ldr r0, [r7, #0x28]
	movs r1, #2
	orrs r0, r1
	str r0, [r7, #0x28]
	adds r0, r7, #0
	adds r0, #0x90
	ldrh r2, [r0]
	ldrh r1, [r4]
	ldrh r3, [r3]
	subs r0, r1, r3
	muls r0, r2, r0
	adds r2, r7, #0
	adds r2, #0x92
	ldrh r2, [r2]
	muls r2, r3, r2
	adds r0, r0, r2
	bl Div
	adds r1, r7, #0
	adds r1, #0x30
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
_080A543A:
	ldrb r1, [r7, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080A5446
	b _080A5556
_080A5446:
	adds r6, r7, #0
	adds r6, #0x28
	adds r4, r7, #0
	adds r4, #0x9c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080A547A
	ldr r0, [r7, #0x28]
	movs r1, #4
	orrs r0, r1
	b _080A5482
_080A547A:
	ldr r0, [r7, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080A5482:
	str r0, [r7, #0x28]
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
	beq _080A54A6
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _080A54AE
_080A54A6:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080A54AE:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _080A54E8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080A552E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080A54F2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080A54EC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080A5508
	.align 2, 0
_080A54E8: .4byte 0x0000FFFF
_080A54EC:
	subs r0, #1
	strh r0, [r4, #8]
	b _080A5506
_080A54F2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080A5506
	strh r1, [r4, #8]
	movs r2, #1
	b _080A5508
_080A5506:
	movs r2, #0
_080A5508:
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
	bne _080A5530
	movs r0, #1
	strb r0, [r4, #7]
	b _080A5530
_080A552E:
	movs r2, #0
_080A5530:
	cmp r2, #0
	beq _080A5556
	adds r0, r7, #0
	adds r0, #0x9a
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A5556
	ldrb r0, [r7, #2]
	movs r1, #0xf7
	ands r1, r0
	strb r1, [r7, #2]
	adds r0, r7, #0
	adds r0, #0xb0
	ldr r0, [r0]
	cmp r0, #0
	beq _080A5556
	movs r1, #0
	bl VM_ExecByID
_080A5556:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a5568
FUN_080a5568: @ 0x080A5568
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	ldr r0, _080A55D0 @ =0x03002C48
	ldr r4, [r0]
	cmp r4, #0
	bne _080A557C
	b _080A583C
_080A557C:
	ldrb r0, [r4, #0x19]
	ldrb r1, [r4, #0x18]
	cmp r0, r1
	blo _080A5586
	b _080A583C
_080A5586:
	adds r1, r0, #0
	movs r0, #0xb8
	muls r0, r1, r0
	adds r0, #0x1c
	adds r7, r4, r0
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A559E
	bl VM_GetValue
_080A559E:
	strh r0, [r7]
	adds r4, r7, #0
	adds r4, #0x28
	adds r5, r7, #0
	adds r5, #0x54
	movs r0, #0x74
	bl VM_SeekToNamedArg
	mov sb, r4
	cmp r0, #0
	bne _080A55B6
	b _080A583C
_080A55B6:
	bl VM_GetValue
	mov r8, r0
	movs r0, #0x69
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A55D4
	bl VM_GetValue
	adds r6, r0, #0
	b _080A55D6
	.align 2, 0
_080A55D0: .4byte 0x03002C48
_080A55D4:
	movs r6, #0
_080A55D6:
	adds r0, r5, #0
	mov r1, r8
	bl Video_GetAuxSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r2, #0
	strh r6, [r4, #0x10]
	ldrh r1, [r5, #6]
	adds r0, r7, #0
	adds r0, #0x84
	strh r1, [r0]
	strb r2, [r7, #3]
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5606
	bl VM_GetValue
	strb r0, [r7, #3]
_080A5606:
	ldrb r0, [r7, #3]
	cmp r0, #0
	beq _080A5614
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	str r0, [r4]
_080A5614:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5630
	bl VM_GetValue
	strh r0, [r4, #0x1c]
	bl VM_GetValue
	strh r0, [r4, #0x1e]
	bl VM_GetValue
	b _080A5634
_080A5630:
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
_080A5634:
	strh r0, [r4, #0x20]
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5644
	bl VM_GetValue
_080A5644:
	strb r0, [r7, #4]
	movs r0, #0x52
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5656
	bl VM_GetValue
	strb r0, [r4, #7]
_080A5656:
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	bne _080A5664
	b _080A57E6
_080A5664:
	ldr r4, _080A56B0 @ =0x0000922E
	bl VM_GetValue
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl GetFile
	adds r6, r7, #0
	adds r6, #0xac
	str r0, [r6]
	bl VM_GetValue
	adds r5, r7, #0
	adds r5, #0x98
	strb r0, [r5]
	bl VM_GetValue
	adds r4, r7, #0
	adds r4, #0x99
	strb r0, [r4]
	movs r0, #0x6f
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	mov r8, r6
	adds r6, r4, #0
	cmp r1, #0
	beq _080A56B4
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0x9a
	strb r0, [r1]
	adds r0, r1, #0
	b _080A56BA
	.align 2, 0
_080A56B0: .4byte 0x0000922E
_080A56B4:
	adds r0, r7, #0
	adds r0, #0x9a
	strb r1, [r0]
_080A56BA:
	ldrb r1, [r0]
	cmp r1, #0
	beq _080A56D8
	movs r0, #0x65
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A56D8
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0xb0
	str r0, [r1]
	b _080A56DE
_080A56D8:
	adds r0, r7, #0
	adds r0, #0xb0
	str r1, [r0]
_080A56DE:
	adds r4, r7, #0
	adds r4, #0x9c
	mov r2, r8
	ldr r1, [r2]
	ldrb r2, [r5]
	ldrb r3, [r6]
	ldrb r0, [r7, #3]
	str r0, [sp]
	adds r0, r4, #0
	bl AuxAnim_SetAnim
	movs r0, #0x50
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A570E
	bl VM_GetValue
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
_080A570E:
	mov r6, sb
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080A573C
	ldr r0, [r7, #0x28]
	movs r1, #4
	orrs r0, r1
	b _080A5744
_080A573C:
	ldr r0, [r7, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080A5744:
	str r0, [r7, #0x28]
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
	beq _080A5768
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _080A5770
_080A5768:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080A5770:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080A57A8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080A57E0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080A57AC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080A57A0
	ldrb r0, [r4, #5]
_080A57A0:
	subs r0, #1
	strh r0, [r4, #8]
	b _080A57BC
	.align 2, 0
_080A57A8: .4byte 0x0000FFFF
_080A57AC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080A57BC
	strh r1, [r4, #8]
_080A57BC:
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
	bne _080A57E0
	movs r0, #1
	strb r0, [r4, #7]
_080A57E0:
	movs r0, #8
	strb r0, [r7, #2]
	b _080A57F6
_080A57E6:
	adds r0, r7, #0
	adds r0, #0xac
	str r1, [r0]
	subs r0, #0x12
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	strb r1, [r7, #2]
_080A57F6:
	movs r5, #0
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5808
	bl VM_GetValue
	adds r5, r0, #0
_080A5808:
	adds r4, r7, #0
	adds r4, #0xb4
	movs r0, #0
	str r0, [r4]
	cmp r5, #0
	beq _080A5832
	movs r0, #0x40
	bl Malloc
	str r0, [r4]
	cmp r0, #0
	beq _080A5832
	movs r1, #0x40
	bl ClearMemory
	ldr r0, [r4]
	adds r1, r7, #0
	adds r1, #0x44
	movs r2, #0
	bl ParticleShadow_Init
_080A5832:
	ldr r0, _080A584C @ =0x03002C48
	ldr r1, [r0]
	ldrb r0, [r1, #0x19]
	adds r0, #1
	strb r0, [r1, #0x19]
_080A583C:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A584C: .4byte 0x03002C48

	thumb_func_start Entity3117_Update
Entity3117_Update: @ 0x080A5850
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	bge _080A587E
	adds r4, r6, #0
	adds r4, #0x1c
_080A5860:
	ldr r0, _080A5888 @ =0x030044BC
	ldr r0, [r0]
	cmp r0, #0
	beq _080A586E
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _080A5874
_080A586E:
	adds r0, r4, #0
	bl FUN_080a51d4
_080A5874:
	adds r4, #0xb8
	adds r5, #1
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	blt _080A5860
_080A587E:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A5888: .4byte 0x030044BC

	thumb_func_start Entity3117_Destroy
Entity3117_Destroy: @ 0x080A588C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	b _080A58BA
_080A5894:
	movs r0, #0xb8
	adds r4, r6, #0
	muls r4, r0, r4
	adds r0, r4, r5
	adds r0, #0x44
	bl AuxSprite_Remove
	adds r0, r5, #0
	adds r0, #0xd0
	adds r4, r0, r4
	ldr r0, [r4]
	cmp r0, #0
	beq _080A58B8
	bl ParticleShadow_Remove
	ldr r0, [r4]
	bl Free
_080A58B8:
	adds r6, #1
_080A58BA:
	ldrb r0, [r5, #0x19]
	cmp r6, r0
	blt _080A5894
	ldr r1, _080A58CC @ =0x03002C48
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A58CC: .4byte 0x03002C48

	thumb_func_start Entity3117_Init
Entity3117_Init: @ 0x080A58D0
	movs r1, #0
	strb r3, [r0, #0x18]
	strb r1, [r0, #0x19]
	ldr r1, _080A58E0 @ =0x03002C48
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_080A58E0: .4byte 0x03002C48

	thumb_func_start Entity3117_Create
Entity3117_Create: @ 0x080A58E4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r0, _080A5904 @ =0x03002C48
	ldr r0, [r0]
	cmp r0, #0
	bne _080A594A
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5908
	bl VM_GetValue
	adds r5, r0, #0
	b _080A590A
	.align 2, 0
_080A5904: .4byte 0x03002C48
_080A5908:
	movs r5, #1
_080A590A:
	movs r0, #0xb8
	adds r1, r5, #0
	muls r1, r0, r1
	adds r1, #0x1c
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5948
	ldr r1, _080A5940 @ =Entity3117_Update
	ldr r2, _080A5944 @ =Entity3117_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	adds r3, r5, #0
	bl Entity3117_Init
	cmp r0, #0
	bge _080A5948
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A594A
	.align 2, 0
_080A5940: .4byte Entity3117_Update
_080A5944: .4byte Entity3117_Destroy
_080A5948:
	adds r0, r4, #0
_080A594A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
