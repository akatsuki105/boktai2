	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c0d6c
FUN_080c0d6c: @ 0x080C0D6C
	str r1, [r0, #0x78]
	adds r0, #0x76
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080c0d78
FUN_080c0d78: @ 0x080C0D78
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r0, #0x76
	ldrh r0, [r0]
	cmp r0, #2
	bhi _080C0D90
	adds r0, r2, #0
	adds r0, #0x6a
	ldrh r0, [r0]
	lsrs r0, r0, #1
	adds r0, #4
	b _080C0DD2
_080C0D90:
	adds r1, r2, #0
	adds r1, #0x6c
	ldrh r3, [r1]
	movs r0, #1
	ands r0, r3
	adds r5, r1, #0
	cmp r0, #0
	beq _080C0DA4
	movs r4, #1
	b _080C0DB4
_080C0DA4:
	lsrs r1, r3, #1
	movs r0, #1
	ands r1, r0
	rsbs r0, r1, #0
	orrs r0, r1
	asrs r4, r0, #0x1f
	movs r0, #2
	ands r4, r0
_080C0DB4:
	ldrh r1, [r5]
	movs r3, #0
	cmp r1, #2
	bls _080C0DCA
	movs r3, #8
	cmp r1, #4
	bls _080C0DCA
	movs r3, #4
	cmp r1, #5
	bhi _080C0DCA
	movs r3, #0xc
_080C0DCA:
	ldr r0, [r2, #0x18]
	orrs r0, r3
	str r0, [r2, #0x18]
	adds r0, r4, #6
_080C0DD2:
	strh r0, [r2, #0x28]
	adds r1, r2, #0
	adds r1, #0x76
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _080C0DEC
	adds r0, r2, #0
	bl KillEntity
_080C0DEC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c0df4
FUN_080c0df4: @ 0x080C0DF4
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x60
	adds r0, #0x6e
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	adds r1, #4
	adds r0, r2, #0
	adds r0, #0x70
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r0, [r2, #0x60]
	ldr r1, [r2, #0x64]
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	adds r1, r2, #0
	adds r1, #0x76
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	subs r1, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _080C0E3A
	ldr r1, _080C0E40 @ =FUN_080c0d78
	adds r0, r2, #0
	bl FUN_080c0d6c
_080C0E3A:
	pop {r0}
	bx r0
	.align 2, 0
_080C0E40: .4byte FUN_080c0d78

	thumb_func_start FUN_080c0e44
FUN_080c0e44: @ 0x080C0E44
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x76
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	subs r1, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _080C0E70
	ldr r0, [r2, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #0x18]
	ldr r1, _080C0E74 @ =FUN_080c0df4
	adds r0, r2, #0
	bl FUN_080c0d6c
_080C0E70:
	pop {r0}
	bx r0
	.align 2, 0
_080C0E74: .4byte FUN_080c0df4

	thumb_func_start FUN_080c0e78
FUN_080c0e78: @ 0x080C0E78
	push {lr}
	ldr r1, [r0, #0x78]
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080c0e88
FUN_080c0e88: @ 0x080C0E88
	push {lr}
	adds r0, #0x18
	bl AuxSprite_Remove
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080c0e98
FUN_080c0e98: @ 0x080C0E98
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r5, r1, #0
	mov sb, r2
	mov r8, r3
	adds r6, r7, #0
	adds r6, #0x18
	adds r4, r7, #0
	adds r4, #0x44
	ldr r1, _080C0F18 @ =0x0000210E
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r7, #0x60]
	str r1, [r7, #0x64]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	movs r0, #1
	strb r0, [r6, #7]
	adds r0, r4, #0
	mov r1, sb
	bl Video_SetAuxSpritePltt
	adds r0, r7, #0
	adds r0, #0x6a
	mov r1, r8
	strh r1, [r0]
	ldrh r0, [r0]
	strh r0, [r6, #0x10]
	adds r0, r7, #0
	adds r0, #0x6c
	mov r2, sp
	ldrh r2, [r2, #0x1c]
	strh r2, [r0]
	ldrh r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080C0F1C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x20]
	muls r0, r2, r0
	cmp r0, #0
	blt _080C0F20
	asrs r0, r0, #0xc
	b _080C0F26
	.align 2, 0
_080C0F18: .4byte 0x0000210E
_080C0F1C: .4byte 0x085B0A08
_080C0F20:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C0F26:
	rsbs r0, r0, #0
	adds r1, r7, #0
	adds r1, #0x6e
	strh r0, [r1]
	ldr r1, _080C0F44 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x20]
	muls r0, r2, r0
	cmp r0, #0
	blt _080C0F48
	asrs r0, r0, #0xc
	b _080C0F4E
	.align 2, 0
_080C0F44: .4byte 0x085B0A08
_080C0F48:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C0F4E:
	rsbs r1, r0, #0
	adds r0, r7, #0
	adds r0, #0x70
	strh r1, [r0]
	adds r2, r7, #0
	adds r2, #0x72
	ldr r0, [sp, #0x24]
	strh r0, [r2]
	adds r1, r7, #0
	adds r1, #0x74
	ldr r0, [sp, #0x28]
	strh r0, [r1]
	ldrh r0, [r2]
	cmp r0, #0
	beq _080C0F84
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	ldr r1, _080C0F80 @ =FUN_080c0e44
	adds r0, r7, #0
	bl FUN_080c0d6c
	b _080C0F8C
	.align 2, 0
_080C0F80: .4byte FUN_080c0e44
_080C0F84:
	ldr r1, _080C0F9C @ =FUN_080c0df4
	adds r0, r7, #0
	bl FUN_080c0d6c
_080C0F8C:
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080C0F9C: .4byte FUN_080c0df4

	thumb_func_start FUN_080c0fa0
FUN_080c0fa0: @ 0x080C0FA0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r0, #0xa
	movs r1, #0x7c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080C0FF8
	ldr r1, _080C0FF0 @ =FUN_080c0e78
	ldr r2, _080C0FF4 @ =FUN_080c0e88
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, [sp, #0x28]
	str r0, [sp, #4]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #8]
	ldr r0, [sp, #0x30]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl FUN_080c0e98
	cmp r0, #0
	bge _080C0FF8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080C0FFA
	.align 2, 0
_080C0FF0: .4byte FUN_080c0e78
_080C0FF4: .4byte FUN_080c0e88
_080C0FF8:
	adds r0, r4, #0
_080C0FFA:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080c1008
FUN_080c1008: @ 0x080C1008
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	mov sb, r0
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C105C
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080C1054 @ =0xFFFF0000
	ldr r1, [sp, #0x10]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x10]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080C1058 @ =0x0000FFFF
	ldr r1, [sp, #0x10]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x10]
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x14]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x14]
	b _080C1066
	.align 2, 0
_080C1054: .4byte 0xFFFF0000
_080C1058: .4byte 0x0000FFFF
_080C105C:
	ldr r1, _080C1078 @ =0xFFFF0000
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
_080C1066:
	movs r0, #0x63
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C107C
	bl VM_GetValue
	adds r0, #0x2c
	b _080C107E
	.align 2, 0
_080C1078: .4byte 0xFFFF0000
_080C107C:
	movs r0, #0x2c
_080C107E:
	mov r8, r0
	movs r0, #0x45
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C1092
	bl VM_GetValue
	adds r7, r0, #0
	b _080C1094
_080C1092:
	movs r7, #0
_080C1094:
	movs r0, #0x64
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C10A6
	bl VM_GetValue
	adds r6, r0, #0
	b _080C10A8
_080C10A6:
	movs r6, #0
_080C10A8:
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C10BA
	bl VM_GetValue
	adds r5, r0, #0
	b _080C10BC
_080C10BA:
	movs r5, #0x20
_080C10BC:
	movs r0, #0x77
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C10CE
	bl VM_GetValue
	adds r4, r0, #0
	b _080C10D0
_080C10CE:
	movs r4, #0
_080C10D0:
	movs r0, #0x6c
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C10E0
	bl VM_GetValue
	b _080C10E2
_080C10E0:
	movs r0, #0x5a
_080C10E2:
	str r6, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	str r0, [sp, #0xc]
	mov r0, sb
	add r1, sp, #0x10
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080c0e98
	movs r0, #0
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080c1108
FUN_080c1108: @ 0x080C1108
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #9
	movs r1, #0x7c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080C1144
	ldr r1, _080C113C @ =FUN_080c0e78
	ldr r2, _080C1140 @ =FUN_080c0e88
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080c1008
	cmp r0, #0
	bge _080C1144
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080C1146
	.align 2, 0
_080C113C: .4byte FUN_080c0e78
_080C1140: .4byte FUN_080c0e88
_080C1144:
	adds r0, r4, #0
_080C1146:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080c114c
FUN_080c114c: @ 0x080C114C
	bx lr
	.align 2, 0

	thumb_func_start FUN_080c1150
FUN_080c1150: @ 0x080C1150
	push {lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0x96
	adds r0, #0x98
	ldrh r1, [r3]
	ldrh r0, [r0]
	cmp r1, r0
	bhi _080C116E
	movs r1, #1
	strh r1, [r3]
	adds r0, r2, #0
	adds r0, #0x9e
	strh r1, [r0]
	b _080C1172
_080C116E:
	subs r0, r1, r0
	strh r0, [r3]
_080C1172:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c1178
FUN_080c1178: @ 0x080C1178
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r6, r7, #0
	adds r6, #0x18
	movs r5, #0
	ldr r2, _080C11EC @ =0x03002B4C
	ldr r1, [r2]
	adds r1, #0x24
	adds r0, #0x1e
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r5, r0
	bge _080C11E0
	mov r8, r2
_080C119A:
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r5, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r6, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl EntityMsgBox_BeginWait
	ldrb r0, [r4, #6]
	cmp r0, #6
	bne _080C11CC
	adds r1, r7, #0
	adds r1, #0xac
	ldr r0, _080C11F0 @ =FUN_080c1150
	str r0, [r1]
	ldr r0, _080C11F4 @ =0x0000025D
	bl PlaySound_082406e0
_080C11CC:
	adds r5, #1
	mov r0, r8
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r6, #6
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r5, r0
	blt _080C119A
_080C11E0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C11EC: .4byte 0x03002B4C
_080C11F0: .4byte FUN_080c1150
_080C11F4: .4byte 0x0000025D

	thumb_func_start FUN_080c11f8
FUN_080c11f8: @ 0x080C11F8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080c1178
	adds r0, r4, #0
	adds r0, #0xac
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #1
	bhi _080C121E
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #0
	b _080C1224
_080C121E:
	adds r1, r4, #0
	adds r1, #0x4c
	movs r0, #1
_080C1224:
	strh r0, [r1, #0x10]
	adds r0, r4, #0
	adds r0, #0x96
	ldrh r1, [r0]
	subs r0, #0x41
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x9c
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _080C124A
	movs r0, #0
	strh r0, [r1]
_080C124A:
	adds r0, r4, #0
	adds r0, #0x9e
	ldrh r0, [r0]
	cmp r0, #0
	beq _080C1264
	adds r0, r4, #0
	adds r0, #0x18
	movs r1, #1
	bl EntityMsgBox_EndWait
	adds r0, r4, #0
	bl KillEntity
_080C1264:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080c126c
FUN_080c126c: @ 0x080C126C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	bl EntityMsgBus_Unregister
	adds r4, #0x4c
	adds r0, r4, #0
	bl AuxSprite_Remove
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080c1288
FUN_080c1288: @ 0x080C1288
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	adds r2, r7, #0
	adds r2, #0x94
	strh r1, [r2]
	adds r0, #0x18
	ldrh r1, [r2]
	movs r2, #0xa
	bl EntityMsgBus_Register
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _080C12D2
	bl VM_GetValue
	adds r4, r7, #0
	adds r4, #0xa4
	strh r0, [r4]
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0xa6
	strh r0, [r1]
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0xa8
	strh r0, [r1]
	mov sl, r4
	b _080C12E4
_080C12D2:
	adds r1, r7, #0
	adds r1, #0xa4
	strh r2, [r1]
	adds r0, r7, #0
	adds r0, #0xa6
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	mov sl, r1
_080C12E4:
	movs r0, #0x52
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C12F4
	bl VM_GetValue
	b _080C12F6
_080C12F4:
	movs r0, #2
_080C12F6:
	mov sb, r0
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C131A
	bl VM_GetValue
	adds r4, r7, #0
	adds r4, #0x9a
	strh r0, [r4]
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0x98
	strh r0, [r1]
	adds r2, r4, #0
	b _080C132A
_080C131A:
	adds r2, r7, #0
	adds r2, #0x9a
	movs r0, #0x40
	strh r0, [r2]
	adds r1, r7, #0
	adds r1, #0x98
	movs r0, #2
	strh r0, [r1]
_080C132A:
	ldrh r0, [r2]
	movs r1, #0x96
	adds r1, r1, r7
	mov r8, r1
	movs r6, #0
	strh r0, [r1]
	adds r5, r7, #0
	adds r5, #0x4c
	adds r4, r7, #0
	adds r4, #0x78
	ldr r1, _080C139C @ =0x00003641
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #2
	bl AuxSprite_Add
	adds r0, r4, #0
	movs r1, #0x32
	bl Video_SetAuxSpritePltt
	strh r6, [r5, #0x10]
	mov r2, r8
	ldrh r0, [r2]
	strb r0, [r5, #8]
	strb r0, [r5, #9]
	ldr r0, [r7, #0x4c]
	movs r1, #2
	orrs r0, r1
	str r0, [r7, #0x4c]
	mov r0, sb
	strb r0, [r5, #7]
	mov r2, sl
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	adds r0, r7, #0
	adds r0, #0x9c
	strh r6, [r0]
	adds r0, #2
	strh r6, [r0]
	adds r1, r7, #0
	adds r1, #0xac
	ldr r0, _080C13A0 @ =FUN_080c114c
	str r0, [r1]
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080C139C: .4byte 0x00003641
_080C13A0: .4byte FUN_080c114c

	thumb_func_start FUN_080c13a4
FUN_080c13a4: @ 0x080C13A4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #0xa
	movs r1, #0xb0
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080C13E0
	ldr r1, _080C13D8 @ =FUN_080c11f8
	ldr r2, _080C13DC @ =FUN_080c126c
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080c1288
	cmp r0, #0
	bge _080C13E0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080C13E2
	.align 2, 0
_080C13D8: .4byte FUN_080c11f8
_080C13DC: .4byte FUN_080c126c
_080C13E0:
	adds r0, r4, #0
_080C13E2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080c13e8
FUN_080c13e8: @ 0x080C13E8
	movs r3, #0x9e
	lsls r3, r3, #1
	adds r2, r0, r3
	str r1, [r2]
	adds r0, #0x70
	movs r1, #0
	strh r1, [r0]
	bx lr

	thumb_func_start FUN_080c13f8
FUN_080c13f8: @ 0x080C13F8
	push {r4, r5, r6, lr}
	mov ip, r0
	ldr r3, [r0, #0x18]
	ldr r0, [r3, #0x2c]
	ldr r1, [r3, #0x30]
	mov r2, ip
	str r0, [r2, #0x38]
	str r1, [r2, #0x3c]
	ldrh r0, [r2, #0x3a]
	adds r0, #0xc8
	strh r0, [r2, #0x3a]
	movs r6, #0xba
	lsls r6, r6, #2
	adds r0, r3, r6
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r1, _080C1454 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r2, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r6, #0
	ldrsh r4, [r0, r6]
	adds r0, r5, #0
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r6, #0
	ldrsh r2, [r0, r6]
	ldr r0, _080C1458 @ =0x000002E7
	adds r3, r3, r0
	ldrb r0, [r3]
	adds r6, r1, #0
	cmp r0, #0
	beq _080C14B2
	movs r0, #0xaa
	muls r0, r4, r0
	cmp r0, #0
	blt _080C145C
	asrs r0, r0, #0xc
	b _080C1462
	.align 2, 0
_080C1454: .4byte 0x085B0A08
_080C1458: .4byte 0x000002E7
_080C145C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C1462:
	adds r1, r0, #0
	lsls r0, r2, #3
	cmp r0, #0
	blt _080C146E
	asrs r0, r0, #0xc
	b _080C1474
_080C146E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C1474:
	adds r0, r1, r0
	mov r1, ip
	ldrh r1, [r1, #0x38]
	adds r0, r0, r1
	mov r3, ip
	strh r0, [r3, #0x38]
	movs r0, #0xaa
	muls r0, r2, r0
	cmp r0, #0
	blt _080C148C
	asrs r0, r0, #0xc
	b _080C1492
_080C148C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C1492:
	adds r1, r0, #0
	lsls r0, r4, #3
	cmp r0, #0
	blt _080C149E
	asrs r0, r0, #0xc
	b _080C14A4
_080C149E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C14A4:
	subs r0, r1, r0
	mov r1, ip
	ldrh r1, [r1, #0x3c]
	adds r0, r0, r1
	mov r2, ip
	strh r0, [r2, #0x3c]
	b _080C1512
_080C14B2:
	movs r0, #0xaa
	muls r0, r4, r0
	cmp r0, #0
	blt _080C14BE
	asrs r0, r0, #0xc
	b _080C14C4
_080C14BE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C14C4:
	adds r1, r0, #0
	lsls r0, r2, #3
	cmp r0, #0
	blt _080C14D0
	asrs r0, r0, #0xc
	b _080C14D6
_080C14D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C14D6:
	subs r0, r1, r0
	mov r3, ip
	ldrh r3, [r3, #0x38]
	adds r0, r0, r3
	mov r1, ip
	strh r0, [r1, #0x38]
	movs r0, #0xaa
	muls r0, r2, r0
	cmp r0, #0
	blt _080C14EE
	asrs r0, r0, #0xc
	b _080C14F4
_080C14EE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C14F4:
	adds r1, r0, #0
	lsls r0, r4, #3
	cmp r0, #0
	blt _080C1500
	asrs r0, r0, #0xc
	b _080C1506
_080C1500:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C1506:
	adds r0, r1, r0
	mov r2, ip
	ldrh r2, [r2, #0x3c]
	adds r0, r0, r2
	mov r3, ip
	strh r0, [r3, #0x3c]
_080C1512:
	movs r2, #0xff
	lsrs r0, r5, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	mov r0, ip
	adds r0, #0x6e
	strb r1, [r0]
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r2, [r0, r1]
	mov r1, ip
	adds r1, #0x6c
	ldrh r0, [r1]
	muls r0, r2, r0
	adds r3, r1, #0
	cmp r0, #0
	blt _080C1542
	asrs r2, r0, #0xc
	b _080C1548
_080C1542:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C1548:
	mov r0, ip
	adds r0, #0x64
	strh r2, [r0]
	lsls r0, r5, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrh r0, [r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080C1562
	asrs r1, r0, #0xc
	b _080C1568
_080C1562:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C1568:
	mov r0, ip
	adds r0, #0x68
	strh r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c1574
FUN_080c1574: @ 0x080C1574
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov ip, r0
	adds r0, #0x6e
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	mov sl, r0
	movs r0, #0xff
	mov r8, r0
	ldr r1, _080C15D0 @ =0x085B0A08
	mov sb, r1
	movs r7, #0
	str r7, [sp]
	mov r3, ip
	adds r3, #0x94
	mov r5, ip
	adds r5, #0xa8
	movs r6, #3
_080C15A6:
	ldrb r0, [r3, #0x10]
	cmp r0, #0
	beq _080C1644
	ldrh r0, [r3, #0x14]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0x14]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _080C15D4
	strb r1, [r3, #0x10]
	mov r0, ip
	adds r0, #0x7c
	ldr r1, [sp]
	adds r0, r0, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _080C1644
	.align 2, 0
_080C15D0: .4byte 0x085B0A08
_080C15D4:
	ldrh r2, [r3, #0x12]
	ldrh r1, [r5]
	movs r0, #0x10
	subs r0, r0, r1
	muls r0, r2, r0
	asrs r4, r0, #3
	movs r0, #0x11
	ldrsb r0, [r3, r0]
	movs r7, #0x80
	lsls r7, r7, #1
	adds r0, r0, r7
	mov r1, sl
	adds r2, r1, r0
	mov r7, r8
	ands r2, r7
	mov r7, ip
	ldr r0, [r7, #0x38]
	ldr r1, [r7, #0x3c]
	str r0, [r3]
	str r1, [r3, #4]
	adds r0, r2, #0
	adds r0, #0x40
	mov r1, r8
	ands r0, r1
	lsls r0, r0, #1
	add r0, sb
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r4, r0
	cmp r0, #0
	blt _080C1616
	asrs r1, r0, #0xc
	b _080C161C
_080C1616:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C161C:
	ldrh r0, [r3]
	adds r0, r0, r1
	strh r0, [r3]
	mov r0, r8
	ands r2, r0
	lsls r0, r2, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080C1638
	asrs r1, r0, #0xc
	b _080C163E
_080C1638:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C163E:
	ldrh r0, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
_080C1644:
	ldr r7, [sp]
	adds r7, #0x30
	str r7, [sp]
	adds r3, #0x30
	adds r5, #0x30
	subs r6, #1
	cmp r6, #0
	bge _080C15A6
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c1664
FUN_080c1664: @ 0x080C1664
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r0, #0x77
	adds r0, r0, r7
	mov r8, r0
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0xa4
	movs r3, #0
	movs r1, #1
	strb r1, [r0]
	mov r0, r8
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r1, r7, #0
	adds r1, #0x7c
	adds r1, r1, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	mov r0, r8
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0xa8
	strh r3, [r0]
	ldr r6, _080C1760 @ =0x0203B400
	ldr r5, _080C1764 @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r4, _080C1768 @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	mov r0, r8
	ldrb r3, [r0]
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #4
	adds r0, r7, r0
	asrs r2, r2, #3
	movs r3, #0x7f
	ands r2, r3
	adds r2, #0x40
	adds r0, #0xa6
	strh r2, [r0]
	adds r1, #1
	ands r1, r4
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	movs r1, #0x60
	bl Mod
	mov r1, r8
	ldrb r2, [r1]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #4
	adds r1, r7, r1
	subs r0, #0x30
	adds r1, #0xa5
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x6e
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	mov r1, r8
	ldrb r0, [r1]
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #4
	adds r2, r7, r2
	adds r0, r2, #0
	adds r0, #0xa5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r4, r4, r0
	movs r3, #0xff
	ands r4, r3
	adds r2, #0x94
	ldr r0, [r7, #0x38]
	ldr r1, [r7, #0x3c]
	str r0, [r2]
	str r1, [r2, #4]
	mov r0, r8
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0xa6
	ldrh r2, [r0]
	ldr r1, _080C176C @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080C1770
	asrs r2, r0, #0xc
	b _080C1776
	.align 2, 0
_080C1760: .4byte 0x0203B400
_080C1764: .4byte 0x030046B8
_080C1768: .4byte 0x000003FF
_080C176C: .4byte 0x085B0A08
_080C1770:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C1776:
	adds r3, r7, #0
	adds r3, #0x77
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0x94
	ldrh r1, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0xa6
	ldrh r2, [r0]
	ldr r1, _080C17B0 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080C17B4
	asrs r2, r0, #0xc
	b _080C17BA
	.align 2, 0
_080C17B0: .4byte 0x085B0A08
_080C17B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C17BA:
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0x98
	ldrh r1, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _080C17DE
	movs r0, #0
	strb r0, [r3]
_080C17DE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c17e8
FUN_080c17e8: @ 0x080C17E8
	push {r4, r5, lr}
	movs r5, #0
	movs r4, #1
	adds r2, r0, #0
	adds r2, #0xa4
	adds r1, r0, #0
	movs r3, #3
_080C17F6:
	strb r5, [r2]
	ldr r0, [r1, #0x7c]
	orrs r0, r4
	str r0, [r1, #0x7c]
	adds r2, #0x30
	adds r1, #0x30
	subs r3, #1
	cmp r3, #0
	bge _080C17F6
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c1810
FUN_080c1810: @ 0x080C1810
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x18]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r5, [r0]
	cmp r5, #3
	beq _080C182A
	adds r0, r4, #0
	bl KillEntity
	b _080C18D4
_080C182A:
	adds r0, r4, #0
	bl FUN_080c13f8
	ldr r0, [r4, #0x18]
	ldr r1, _080C1860 @ =0x0000037D
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _080C1868
	adds r0, r4, #0
	bl FUN_080c17e8
	ldr r0, [r4, #0x1c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0x6f
	ldrb r0, [r0]
	strh r0, [r4, #0x2c]
	ldr r1, _080C1864 @ =FUN_080c18dc
	adds r0, r4, #0
	bl FUN_080c13e8
	b _080C18D4
	.align 2, 0
_080C1860: .4byte 0x0000037D
_080C1864: .4byte FUN_080c18dc
_080C1868:
	adds r0, r4, #0
	bl FUN_080c1574
	ldr r0, [r4, #0x18]
	ldr r1, _080C189C @ =0x0000037D
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #2
	bne _080C18A0
	adds r1, r4, #0
	adds r1, #0x70
	ldrh r0, [r1]
	ands r5, r0
	adds r6, r1, #0
	cmp r5, #3
	bne _080C188E
	adds r0, r4, #0
	bl FUN_080c1664
_080C188E:
	adds r1, r4, #0
	adds r1, #0x6f
	movs r0, #0
	strb r0, [r1]
	adds r2, r1, #0
	b _080C18B8
	.align 2, 0
_080C189C: .4byte 0x0000037D
_080C18A0:
	ldr r0, [r4, #0x1c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0x6f
	movs r0, #1
	strb r0, [r1]
	adds r2, r1, #0
	adds r6, r4, #0
	adds r6, #0x70
_080C18B8:
	ldrh r0, [r6]
	lsrs r0, r0, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080C18CA
	ldrb r0, [r2]
	adds r0, #1
	b _080C18CC
_080C18CA:
	ldrb r0, [r2]
_080C18CC:
	strh r0, [r4, #0x2c]
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
_080C18D4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c18dc
FUN_080c18dc: @ 0x080C18DC
	push {lr}
	adds r2, r0, #0
	adds r0, #0x64
	ldrh r0, [r0]
	ldrh r1, [r2, #0x38]
	adds r0, r0, r1
	strh r0, [r2, #0x38]
	adds r0, r2, #0
	adds r0, #0x68
	ldrh r0, [r0]
	ldrh r1, [r2, #0x3c]
	adds r0, r0, r1
	strh r0, [r2, #0x3c]
	adds r1, r2, #0
	adds r1, #0x70
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	adds r1, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _080C1914
	ldr r1, _080C1918 @ =FUN_080c191c
	adds r0, r2, #0
	bl FUN_080c13e8
_080C1914:
	pop {r0}
	bx r0
	.align 2, 0
_080C1918: .4byte FUN_080c191c

	thumb_func_start FUN_080c191c
FUN_080c191c: @ 0x080C191C
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x70
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _080C1938
	movs r0, #4
	strh r0, [r2, #0x2c]
	b _080C19A4
_080C1938:
	cmp r0, #4
	bne _080C199A
	adds r0, r2, #0
	adds r0, #0x6e
	adds r2, #0x1c
	ldrb r1, [r0]
	movs r3, #1
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	beq _080C1952
	movs r0, #7
	b _080C1960
_080C1952:
	asrs r0, r1, #1
	ands r0, r3
	cmp r0, #0
	beq _080C195E
	movs r0, #8
	b _080C1960
_080C195E:
	movs r0, #6
_080C1960:
	strh r0, [r2, #0x10]
	cmp r1, #2
	bgt _080C196E
	ldr r0, [r2]
	movs r1, #0xd
	rsbs r1, r1, #0
	b _080C1994
_080C196E:
	cmp r1, #4
	bgt _080C197E
	ldr r0, [r2]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #8
	b _080C1986
_080C197E:
	cmp r1, #5
	bgt _080C198C
	ldr r0, [r2]
	movs r1, #0xc
_080C1986:
	orrs r0, r1
	str r0, [r2]
	b _080C19A4
_080C198C:
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	subs r1, #0xd
_080C1994:
	ands r0, r1
	str r0, [r2]
	b _080C19A4
_080C199A:
	cmp r0, #6
	bls _080C19A4
	adds r0, r2, #0
	bl KillEntity
_080C19A4:
	pop {r0}
	bx r0

	thumb_func_start FUN_080c19a8
FUN_080c19a8: @ 0x080C19A8
	push {lr}
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r1, [r1]
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_080c19bc
FUN_080c19bc: @ 0x080C19BC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x1c
	bl AuxSprite_Remove
	adds r4, #0x7c
	movs r5, #3
_080C19CA:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x30
	subs r5, #1
	cmp r5, #0
	bge _080C19CA
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080c19e0
FUN_080c19e0: @ 0x080C19E0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x48
	ldr r1, _080C1A10 @ =0x0000210E
	adds r0, r5, #0
	bl Video_GetAuxSprite
	adds r4, #0x1c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #1
	bl AuxSprite_Add
	movs r0, #0
	strh r0, [r4, #0x10]
	adds r0, r5, #0
	movs r1, #0x2e
	bl Video_SetAuxSpritePltt
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C1A10: .4byte 0x0000210E

	thumb_func_start FUN_080c1a14
FUN_080c1a14: @ 0x080C1A14
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x77
	movs r0, #0
	strb r0, [r1]
	ldr r0, _080C1A7C @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r5, #0x78]
	movs r0, #4
	rsbs r0, r0, #0
	mov r8, r0
	adds r6, r5, #0
	adds r6, #0xa4
	adds r4, r5, #0
	adds r4, #0x7c
	movs r7, #3
_080C1A3C:
	ldr r1, [r5, #0x78]
	adds r0, r4, #0
	movs r2, #1
	bl Particle_Add
	adds r0, r4, #0
	mov r1, r8
	mov r2, r8
	bl Particle_SetOffset
	ldr r1, [r5, #0x78]
	adds r0, r4, #0
	movs r2, #0x11
	bl Particle_SetFrame
	adds r0, r4, #0
	movs r1, #1
	bl Particle_SetPltt
	movs r0, #0
	strb r0, [r6]
	adds r6, #0x30
	adds r4, #0x30
	subs r7, #1
	cmp r7, #0
	bge _080C1A3C
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C1A7C: .4byte 0x00001C1E

	thumb_func_start FUN_080c1a80
FUN_080c1a80: @ 0x080C1A80
	push {r4, lr}
	adds r4, r0, #0
	str r1, [r4, #0x18]
	adds r0, #0x6c
	movs r1, #0
	strh r2, [r0]
	adds r0, #6
	strh r3, [r0]
	subs r0, #3
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_080c19e0
	adds r0, r4, #0
	bl FUN_080c13f8
	adds r0, r4, #0
	bl FUN_080c1a14
	ldr r1, _080C1AB8 @ =FUN_080c1810
	adds r0, r4, #0
	bl FUN_080c13e8
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080C1AB8: .4byte FUN_080c1810

	thumb_func_start FUN_080c1abc
FUN_080c1abc: @ 0x080C1ABC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	movs r1, #0xa0
	lsls r1, r1, #1
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080C1B00
	ldr r1, _080C1AF8 @ =FUN_080c19a8
	ldr r2, _080C1AFC @ =FUN_080c19bc
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl FUN_080c1a80
	cmp r0, #0
	bge _080C1B00
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080C1B02
	.align 2, 0
_080C1AF8: .4byte FUN_080c19a8
_080C1AFC: .4byte FUN_080c19bc
_080C1B00:
	adds r0, r4, #0
_080C1B02:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080c1b08
FUN_080c1b08: @ 0x080C1B08
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0x98
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, r4, #0
	bl MainSprite_AdvanceAnim
	adds r0, r5, #0
	adds r0, #0xf8
	adds r1, r4, #0
	bl MainSprite_AdvanceAnim
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r4, #0
	bl MainSprite_AdvanceAnim
	ldr r0, _080C1B40 @ =0x0000021E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C1B40: .4byte 0x0000021E

	thumb_func_start FUN_080c1b44
FUN_080c1b44: @ 0x080C1B44
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r0, _080C1B74 @ =0x0000021E
	adds r6, r7, r0
	ldrh r0, [r6]
	cmp r0, #0x1d
	bhi _080C1B7C
	adds r2, r7, #0
	adds r2, #0xa0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r1, r7, #0
	adds r1, #0xb8
	movs r0, #0x3c
	strh r0, [r1]
	adds r1, #2
	ldr r0, _080C1B78 @ =0x0000FFE2
	b _080C1CDE
	.align 2, 0
_080C1B74: .4byte 0x0000021E
_080C1B78: .4byte 0x0000FFE2
_080C1B7C:
	cmp r0, #0x2c
	bhi _080C1BA4
	adds r2, r7, #0
	adds r2, #0xa0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r1, r7, #0
	adds r1, #0xb8
	movs r0, #0x3c
	strh r0, [r1]
	ldrh r0, [r6]
	lsls r0, r0, #1
	subs r0, #0x5a
	adds r3, r7, #0
	adds r3, #0xba
	strh r0, [r3]
	b _080C1CE0
_080C1BA4:
	cmp r0, #0x31
	bhi _080C1BF4
	ldr r0, _080C1BE8 @ =0x0203B400
	mov r8, r0
	ldr r4, _080C1BEC @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080C1BF0 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	adds r0, #0x3a
	adds r1, r7, #0
	adds r1, #0xb8
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	ldrh r2, [r6]
	movs r1, #0x2d
	subs r1, r1, r2
	b _080C1C34
	.align 2, 0
_080C1BE8: .4byte 0x0203B400
_080C1BEC: .4byte 0x030046B8
_080C1BF0: .4byte 0x000003FF
_080C1BF4:
	cmp r0, #0x36
	bhi _080C1C50
	ldr r0, _080C1C44 @ =0x0203B400
	mov r8, r0
	ldr r4, _080C1C48 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080C1C4C @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	adds r0, #0x3a
	adds r1, r7, #0
	adds r1, #0xb8
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	ldrh r1, [r6]
	subs r1, #0x37
_080C1C34:
	lsls r1, r1, #1
	adds r1, r1, r0
	subs r1, #2
	adds r3, r7, #0
	adds r3, #0xba
	strh r1, [r3]
	b _080C1D56
	.align 2, 0
_080C1C44: .4byte 0x0203B400
_080C1C48: .4byte 0x030046B8
_080C1C4C: .4byte 0x000003FF
_080C1C50:
	cmp r0, #0x3b
	bhi _080C1C9C
	ldr r0, _080C1C90 @ =0x0203B400
	mov r8, r0
	ldr r4, _080C1C94 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080C1C98 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	adds r0, #0x3a
	adds r1, r7, #0
	adds r1, #0xb8
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	subs r0, #2
	b _080C1CDA
	.align 2, 0
_080C1C90: .4byte 0x0203B400
_080C1C94: .4byte 0x030046B8
_080C1C98: .4byte 0x000003FF
_080C1C9C:
	cmp r0, #0x4f
	bhi _080C1CFC
	ldr r0, _080C1CF0 @ =0x0203B400
	mov r8, r0
	ldr r4, _080C1CF4 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080C1CF8 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	adds r0, #0x3b
	adds r1, r7, #0
	adds r1, #0xb8
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	subs r0, #1
_080C1CDA:
	adds r1, r7, #0
	adds r1, #0xba
_080C1CDE:
	strh r0, [r1]
_080C1CE0:
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	b _080C1D56
	.align 2, 0
_080C1CF0: .4byte 0x0203B400
_080C1CF4: .4byte 0x030046B8
_080C1CF8: .4byte 0x000003FF
_080C1CFC:
	cmp r0, #0x59
	bhi _080C1D10
	adds r0, r7, #0
	adds r0, #0xb8
	movs r2, #0
	movs r1, #0x3c
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
	b _080C1D56
_080C1D10:
	ldrh r0, [r6]
	movs r1, #0x2d
	bl Div
	movs r3, #1
	ands r0, r3
	cmp r0, #0
	beq _080C1D3C
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	b _080C1D56
_080C1D3C:
	adds r2, r7, #0
	adds r2, #0xa0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
_080C1D56:
	ldr r0, _080C1D6C @ =0x0000021E
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C1D6C: .4byte 0x0000021E

	thumb_func_start FUN_080c1d70
FUN_080c1d70: @ 0x080C1D70
	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r5, r0, #0
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r1, [r1]
	cmp r1, #0
	beq _080C1D86
	bl _call_via_r1
_080C1D86:
	ldr r3, _080C1DD8 @ =0x0000022E
	adds r6, r5, r3
	ldrh r1, [r6]
	adds r4, r1, #0
	cmp r4, #0
	beq _080C1DE0
	adds r1, #1
	strh r1, [r6]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x10
	bhi _080C1DA0
	b _080C1F2C
_080C1DA0:
	movs r1, #0x8c
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080C1DCE
	ldr r1, _080C1DDC @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #0x10]
	add r1, sp, #0x10
	add r3, sp, #0xc
	str r3, [r1, #4]
	movs r3, #0x8b
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r0, [r0]
	str r0, [sp, #0xc]
	adds r0, r2, #0
	bl VM_ExecByID
_080C1DCE:
	adds r0, r5, #0
	bl KillEntity
	b _080C1F2C
	.align 2, 0
_080C1DD8: .4byte 0x0000022E
_080C1DDC: .4byte 0xFFFF0000
_080C1DE0:
	movs r2, #0x89
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r3, _080C1E2C @ =0x00000226
	adds r2, r5, r3
	ldrh r1, [r1]
	ldrh r2, [r2]
	cmp r1, r2
	bne _080C1E34
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r2, [r1]
	adds r3, #4
	adds r1, r5, r3
	ldrh r1, [r1]
	subs r1, #0x10
	cmp r2, r1
	bne _080C1E34
	movs r0, #4
	str r0, [sp]
	ldr r0, _080C1E30 @ =0x0000FFFF
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #1
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r1, r5, r2
	strh r4, [r1]
	movs r1, #1
	strh r1, [r6]
	b _080C1F14
	.align 2, 0
_080C1E2C: .4byte 0x00000226
_080C1E30: .4byte 0x0000FFFF
_080C1E34:
	movs r3, #0x88
	lsls r3, r3, #2
	adds r1, r5, r3
	ldrh r1, [r1]
	cmp r1, #0x10
	bls _080C1E84
	ldr r1, _080C1E78 @ =0x030044E0
	ldrh r2, [r1, #2]
	movs r1, #9
	ands r1, r2
	cmp r1, #0
	beq _080C1E84
	movs r0, #4
	str r0, [sp]
	ldr r0, _080C1E7C @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #1
	strh r2, [r1]
	ldr r3, _080C1E80 @ =0x0000022E
	adds r1, r5, r3
	strh r2, [r1]
	b _080C1F14
	.align 2, 0
_080C1E78: .4byte 0x030044E0
_080C1E7C: .4byte 0x0000FFFF
_080C1E80: .4byte 0x0000022E
_080C1E84:
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r3, _080C1EE0 @ =0x0000022A
	adds r2, r5, r3
	ldrh r1, [r1]
	ldrh r2, [r2]
	cmp r1, r2
	blo _080C1F14
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r1, #1
	movs r2, #0
	strh r1, [r0]
	subs r3, #0xe
	adds r0, r5, r3
	ldrh r6, [r0]
	cmp r6, #1
	bne _080C1EE4
	adds r0, r5, #0
	adds r0, #0xf8
	adds r4, r5, #0
	adds r4, #0x18
	str r2, [sp]
	adds r1, r4, #0
	movs r2, #4
	movs r3, #1
	bl MainSprite_SetAnim
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #1
	movs r3, #1
	bl MainSprite_SetPose
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	b _080C1EF8
	.align 2, 0
_080C1EE0: .4byte 0x0000022A
_080C1EE4:
	cmp r6, #3
	bne _080C1EF8
	movs r3, #0x8d
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r1, _080C1F34 @ =FUN_080c1b44
	str r1, [r0]
	ldr r1, _080C1F38 @ =0x0000021E
	adds r0, r5, r1
	strh r2, [r0]
_080C1EF8:
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
	movs r0, #1
	bl TextBox_SetInstant
	movs r3, #0x89
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r0, [r0]
	bl TextBox_ShowLine
_080C1F14:
	movs r1, #0x88
	lsls r1, r1, #2
	adds r2, r5, r1
	ldrh r1, [r2]
	adds r1, #1
	strh r1, [r2]
	movs r3, #0x8a
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrh r1, [r2]
	adds r1, #1
	strh r1, [r2]
_080C1F2C:
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080C1F34: .4byte FUN_080c1b44
_080C1F38: .4byte 0x0000021E

	thumb_func_start FUN_080c1f3c
FUN_080c1f3c: @ 0x080C1F3C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x38
	movs r5, #4
_080C1F44:
	adds r0, r4, #0
	bl MainSprite_Remove
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080C1F44
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080c1f5c
FUN_080c1f5c: @ 0x080C1F5C
	push {lr}
	ldr r0, _080C1F80 @ =0x03003ED0
	ldr r1, [r0, #0x2c]
	movs r0, #0
	ldr r2, _080C1F84 @ =0x0000F001
	adds r3, r2, #0
_080C1F68:
	adds r2, r0, #1
	movs r0, #0x1f
_080C1F6C:
	strh r3, [r1]
	adds r1, #2
	subs r0, #1
	cmp r0, #0
	bge _080C1F6C
	adds r0, r2, #0
	cmp r0, #0x1f
	ble _080C1F68
	pop {r0}
	bx r0
	.align 2, 0
_080C1F80: .4byte 0x03003ED0
_080C1F84: .4byte 0x0000F001

	thumb_func_start FUN_080c1f88
FUN_080c1f88: @ 0x080C1F88
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080C1FA8
	ldr r1, _080C1FA0 @ =0x0000CFE1
	ldr r7, _080C1FA4 @ =0x0000ACBD
	movs r6, #0
	b _080C1FAE
	.align 2, 0
_080C1FA0: .4byte 0x0000CFE1
_080C1FA4: .4byte 0x0000ACBD
_080C1FA8:
	ldr r1, _080C2020 @ =0x0000A413
	ldr r7, _080C2024 @ =0x0000EFDA
	movs r6, #0xc
_080C1FAE:
	ldr r0, _080C2028 @ =0x0000C091
	bl GetFile
	adds r5, r0, #0
	movs r4, #0
	str r4, [sp, #0xc]
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	adds r2, r5, #0
	movs r3, #0
	bl Video_SetupBGLayout
	movs r0, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Video_SetBGLayer
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _080C202C @ =0x000092B3
	adds r1, r7, #0
	bl GetFile
	movs r1, #0xda
	lsls r1, r1, #1
	adds r3, r0, r1
	movs r1, #0xd
	ldr r5, _080C2030 @ =0x03004250
_080C1FFA:
	lsls r0, r1, #5
	adds r4, r1, #1
	adds r1, r0, r5
	movs r2, #0xf
_080C2002:
	ldrh r0, [r3]
	strh r0, [r1]
	adds r3, #2
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _080C2002
	adds r1, r4, #0
	cmp r1, #0xf
	ble _080C1FFA
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C2020: .4byte 0x0000A413
_080C2024: .4byte 0x0000EFDA
_080C2028: .4byte 0x0000C091
_080C202C: .4byte 0x000092B3
_080C2030: .4byte 0x03004250

	thumb_func_start FUN_080c2034
FUN_080c2034: @ 0x080C2034
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r7, r0, #0
	ldr r0, _080C20F0 @ =0x0000CB05
	ldr r1, _080C20F4 @ =0x0000DF11
	bl GetFile
	adds r1, r0, #0
	adds r2, r7, #0
	adds r2, #0x18
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r2!, {r3, r4}
	adds r6, r7, #0
	adds r6, #0x18
	adds r0, r6, #0
	bl OpenMainSpriteFile
	ldr r1, _080C20F8 @ =0xFFFF0000
	movs r4, #0
	str r4, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	adds r0, r7, #0
	adds r0, #0x38
	str r4, [sp]
	str r4, [sp, #4]
	movs r5, #0x3c
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0xf
	movs r3, #0x30
	bl MainSprite_Add
	adds r0, r7, #0
	adds r0, #0x98
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0xb
	movs r3, #0x30
	bl MainSprite_Add
	adds r0, r7, #0
	adds r0, #0xf8
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #2
	movs r3, #0x30
	bl MainSprite_Add
	movs r3, #0xdc
	lsls r3, r3, #1
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #5
	movs r3, #0x30
	bl MainSprite_Add
	movs r3, #0xac
	lsls r3, r3, #1
	adds r0, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0
	movs r3, #0x30
	bl MainSprite_Add
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C20F0: .4byte 0x0000CB05
_080C20F4: .4byte 0x0000DF11
_080C20F8: .4byte 0xFFFF0000

	thumb_func_start FUN_080c20fc
FUN_080c20fc: @ 0x080C20FC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	ldr r1, [r7, #0x40]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x40]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0xd
	bhi _080C21DC
	lsls r0, r0, #2
	ldr r1, _080C2124 @ =_080C2128
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080C2124: .4byte _080C2128
_080C2128: @ jump table
	.4byte _080C2160 @ case 0
	.4byte _080C216A @ case 1
	.4byte _080C2176 @ case 2
	.4byte _080C2182 @ case 3
	.4byte _080C2182 @ case 4
	.4byte _080C218E @ case 5
	.4byte _080C219A @ case 6
	.4byte _080C21A6 @ case 7
	.4byte _080C21A6 @ case 8
	.4byte _080C21B2 @ case 9
	.4byte _080C21B2 @ case 10
	.4byte _080C21B2 @ case 11
	.4byte _080C21BE @ case 12
	.4byte _080C21CA @ case 13
_080C2160:
	ldr r0, [r7, #0x40]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #0x40]
	b _080C21E2
_080C216A:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0xf
	b _080C21D4
_080C2176:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x10
	b _080C21D4
_080C2182:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x11
	b _080C21D4
_080C218E:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x12
	b _080C21D4
_080C219A:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x13
	b _080C21D4
_080C21A6:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x14
	b _080C21D4
_080C21B2:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x15
	b _080C21D4
_080C21BE:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x16
	b _080C21D4
_080C21CA:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x17
_080C21D4:
	movs r3, #1
	bl MainSprite_SetPose
	b _080C21E2
_080C21DC:
	movs r0, #1
	orrs r1, r0
	str r1, [r7, #0x40]
_080C21E2:
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0xc
	bls _080C21F0
	b _080C24BC
_080C21F0:
	lsls r0, r0, #2
	ldr r1, _080C21FC @ =_080C2200
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080C21FC: .4byte _080C2200
_080C2200: @ jump table
	.4byte _080C2234 @ case 0
	.4byte _080C22B0 @ case 1
	.4byte _080C23B4 @ case 2
	.4byte _080C2430 @ case 3
	.4byte _080C2338 @ case 4
	.4byte _080C24BC @ case 5
	.4byte _080C24BC @ case 6
	.4byte _080C24BC @ case 7
	.4byte _080C24BC @ case 8
	.4byte _080C23B4 @ case 9
	.4byte _080C24BC @ case 10
	.4byte _080C24BC @ case 11
	.4byte _080C2338 @ case 12
_080C2234:
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r0, [r1]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0x98
	adds r6, r7, #0
	adds r6, #0x18
	movs r4, #0
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetAnim
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xf8
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #2
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r7, r1
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #3
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r0, _080C22AC @ =FUN_080c1b08
	b _080C24F8
	.align 2, 0
_080C22AC: .4byte FUN_080c1b08
_080C22B0:
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r0, [r1]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0x98
	adds r6, r7, #0
	adds r6, #0x18
	movs r4, #0
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xf8
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #2
	movs r3, #1
	bl MainSprite_SetAnim
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r7, r1
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #3
	movs r3, #1
	bl MainSprite_SetAnim
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r7, r1
	adds r1, r6, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetPose
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r0, _080C2334 @ =FUN_080c1b08
	b _080C24F8
	.align 2, 0
_080C2334: .4byte FUN_080c1b08
_080C2338:
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r0, [r1]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0x98
	adds r6, r7, #0
	adds r6, #0x18
	movs r4, #0
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #1
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xf8
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #2
	movs r3, #1
	bl MainSprite_SetAnim
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r7, r1
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #3
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r0, _080C23B0 @ =FUN_080c1b08
	b _080C24F8
	.align 2, 0
_080C23B0: .4byte FUN_080c1b08
_080C23B4:
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r0, [r1]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0x98
	adds r6, r7, #0
	adds r6, #0x18
	movs r4, #0
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xf8
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #2
	movs r3, #1
	bl MainSprite_SetAnim
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r7, r1
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #3
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r0, _080C242C @ =FUN_080c1b08
	b _080C24F8
	.align 2, 0
_080C242C: .4byte FUN_080c1b08
_080C2430:
	adds r2, r7, #0
	adds r2, #0xa0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	adds r0, #0x98
	adds r5, r7, #0
	adds r5, #0x18
	movs r6, #0
	str r6, [sp]
	adds r1, r5, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetAnim
	adds r1, r7, #0
	adds r1, #0xb8
	movs r0, #0x3c
	strh r0, [r1]
	adds r1, #2
	ldr r0, _080C24B4 @ =0x0000FFE2
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	movs r4, #1
	orrs r0, r4
	str r0, [r1]
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r7, r1
	adds r1, r5, #0
	movs r2, #1
	movs r3, #1
	bl MainSprite_SetPose
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, _080C24B8 @ =0x0000FFBF
	strh r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0x28
	strh r0, [r1]
	subs r2, #0x18
	adds r1, r7, r2
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	movs r1, #0x8d
	lsls r1, r1, #2
	adds r0, r7, r1
	str r6, [r0]
	b _080C24FA
	.align 2, 0
_080C24B4: .4byte 0x0000FFE2
_080C24B8: .4byte 0x0000FFBF
_080C24BC:
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	bl FUN_080c1f5c
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #0
_080C24F8:
	str r0, [r1]
_080C24FA:
	movs r0, #0x88
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c250c
FUN_080c250c: @ 0x080C250C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	cmp r1, #0
	bne _080C252C
	movs r2, #0x89
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	b _080C2580
_080C252C:
	movs r0, #0x72
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C25B2
	bl FUN_0823d340
	movs r1, #0x86
	lsls r1, r1, #2
	adds r6, r5, r1
	str r0, [r6]
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C25B2
	bl VM_GetValue
	movs r2, #0x89
	lsls r2, r2, #2
	adds r4, r5, r2
	strh r0, [r4]
	bl VM_GetValue
	ldrh r1, [r4]
	adds r1, r1, r0
	subs r1, #1
	ldr r2, _080C2594 @ =0x00000226
	adds r0, r5, r2
	strh r1, [r0]
	ldr r0, _080C2598 @ =0x0000EFDA
	bl TextBox_SetBgPltt
	ldr r0, [r6]
	bl TextBox_Start
	movs r0, #1
	bl TextBox_SetInstant
	ldrh r0, [r4]
	bl TextBox_ShowLine
_080C2580:
	movs r0, #0x63
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080C25A0
	bl VM_GetValue
	ldr r2, _080C259C @ =0x0000022A
	adds r1, r5, r2
	b _080C25A6
	.align 2, 0
_080C2594: .4byte 0x00000226
_080C2598: .4byte 0x0000EFDA
_080C259C: .4byte 0x0000022A
_080C25A0:
	ldr r0, _080C25B8 @ =0x0000022A
	adds r1, r5, r0
	movs r0, #0x3c
_080C25A6:
	strh r0, [r1]
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
_080C25B2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C25B8: .4byte 0x0000022A

	thumb_func_start FUN_080c25bc
FUN_080c25bc: @ 0x080C25BC
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r0, #0x69
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080C25DC
	bl VM_GetValue
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	b _080C25E4
_080C25DC:
	movs r2, #0x87
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
_080C25E4:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080C25FE
	bl VM_GetValue
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	b _080C2606
_080C25FE:
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
_080C2606:
	adds r0, r4, #0
	bl FUN_080c1f88
	adds r0, r4, #0
	bl FUN_080c2034
	adds r0, r4, #0
	bl FUN_080c20fc
	adds r0, r4, #0
	bl FUN_080c250c
	movs r0, #4
	str r0, [sp]
	ldr r0, _080C263C @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	add sp, #0xc
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080C263C: .4byte 0x0000FFFF

	thumb_func_start FUN_080c2640
FUN_080c2640: @ 0x080C2640
	push {r4, lr}
	movs r1, #0x8e
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080C2678
	ldr r1, _080C2670 @ =FUN_080c1d70
	ldr r2, _080C2674 @ =FUN_080c1f3c
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080c25bc
	cmp r0, #0
	bge _080C2678
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080C267A
	.align 2, 0
_080C2670: .4byte FUN_080c1d70
_080C2674: .4byte FUN_080c1f3c
_080C2678:
	adds r0, r4, #0
_080C267A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080c2680
FUN_080c2680: @ 0x080C2680
	movs r3, #0xa9
	lsls r3, r3, #2
	adds r2, r0, r3
	str r1, [r2]
	movs r1, #0
	strh r1, [r0, #4]
	movs r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080c2694
FUN_080c2694: @ 0x080C2694
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r6, r1, #0
	ldr r0, _080C26A4 @ =0x00000165
	cmp r6, r0
	bne _080C26A8
	movs r0, #0
	b _080C26AA
	.align 2, 0
_080C26A4: .4byte 0x00000165
_080C26A8:
	movs r0, #1
_080C26AA:
	strb r0, [r2, #2]
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r4, r2, r0
	movs r5, #7
_080C26B4:
	adds r0, r4, #0
	adds r1, r6, #0
	bl Video_SetAuxSpritePltt
	adds r4, #0x1c
	subs r5, #1
	cmp r5, #0
	bge _080C26B4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c26cc
FUN_080c26cc: @ 0x080C26CC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldrh r0, [r6, #4]
	cmp r0, #0
	bne _080C271A
	ldrb r0, [r6, #1]
	adds r1, r6, #0
	adds r1, #0x24
	adds r0, #0xd
	strh r0, [r1, #0x10]
	movs r3, #2
	rsbs r3, r3, #0
	movs r0, #0xac
	lsls r0, r0, #1
	adds r2, r6, r0
_080C26EE:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x2c
	cmp r1, r2
	ble _080C26EE
	ldrb r0, [r6, #2]
	cmp r0, #1
	bne _080C270C
	ldr r1, _080C2798 @ =0x00000167
	adds r0, r6, #0
	bl FUN_080c2694
	movs r0, #6
	strb r0, [r6, #3]
_080C270C:
	movs r0, #0
	strh r0, [r6, #0x1c]
	strh r0, [r6, #0x1e]
	strh r0, [r6, #0x20]
	ldrh r0, [r6, #4]
	adds r0, #1
	strh r0, [r6, #4]
_080C271A:
	ldr r2, [r6, #0x18]
	ldr r1, [r2]
	ldr r0, [r6, #0x1c]
	cmp r1, r0
	bne _080C2730
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r4, #0x20
	ldrsh r0, [r6, r4]
	cmp r1, r0
	beq _080C2818
_080C2730:
	ldr r3, [r2, #4]
	ldr r2, [r2]
	adds r0, r2, #0
	ldrh r1, [r6, #8]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _080C279C @ =0xFFFF0000
	adds r1, r5, #0
	ands r1, r2
	orrs r1, r0
	asrs r0, r1, #0x10
	ldrh r4, [r6, #0xa]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	ldr r4, _080C27A0 @ =0x0000FFFF
	ands r4, r1
	orrs r4, r0
	adds r2, r4, #0
	adds r0, r3, #0
	ldrh r1, [r6, #0xc]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r3
	adds r3, r5, #0
	orrs r3, r0
	movs r0, #0
	mov ip, r0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	adds r7, r6, #0
	adds r7, #0x40
	asrs r4, r4, #0x10
	lsls r0, r3, #0x10
	asrs r2, r0, #0x10
_080C277A:
	movs r0, #8
	mov r1, ip
	subs r5, r0, r1
	movs r3, #0x10
	ldrsh r0, [r6, r3]
	mov r1, ip
	muls r1, r0, r1
	mov r0, r8
	muls r0, r5, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080C27A4
	asrs r0, r0, #3
	b _080C27AA
	.align 2, 0
_080C2798: .4byte 0x00000167
_080C279C: .4byte 0xFFFF0000
_080C27A0: .4byte 0x0000FFFF
_080C27A4:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080C27AA:
	strh r0, [r7]
	movs r1, #0x12
	ldrsh r0, [r6, r1]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r4, #0
	muls r0, r5, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080C27C2
	asrs r0, r0, #3
	b _080C27C8
_080C27C2:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080C27C8:
	strh r0, [r7, #2]
	movs r3, #0x14
	ldrsh r0, [r6, r3]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r2, #0
	muls r0, r5, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080C27E0
	asrs r0, r0, #3
	b _080C27E6
_080C27E0:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080C27E6:
	strh r0, [r7, #4]
	adds r7, #0x2c
	movs r0, #1
	add ip, r0
	mov r1, ip
	cmp r1, #7
	ble _080C277A
	ldrb r0, [r6, #3]
	cmp r0, #0
	beq _080C280E
	subs r0, #1
	strb r0, [r6, #3]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C280E
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r6, #0
	bl FUN_080c2694
_080C280E:
	ldr r0, [r6, #0x18]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
_080C2818:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c2824
FUN_080c2824: @ 0x080C2824
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov ip, r0
	ldrh r0, [r0, #4]
	cmp r0, #0
	bne _080C289A
	mov r1, ip
	ldrb r0, [r1, #1]
	strh r0, [r1, #0x34]
	ldr r2, _080C28C8 @ =0x0203B400
	mov sb, r2
	ldr r7, _080C28CC @ =0x030046B8
	mov r8, r7
	ldr r6, _080C28D0 @ =0x000003FF
	movs r5, #0x1f
	mov r3, ip
	movs r4, #7
_080C284A:
	mov r0, r8
	ldr r1, [r0]
	adds r1, #1
	ands r1, r6
	lsls r0, r1, #1
	add r0, sb
	ldrh r0, [r0]
	ands r0, r5
	subs r0, #0x10
	movs r7, #0x99
	lsls r7, r7, #2
	adds r2, r3, r7
	strh r0, [r2]
	adds r1, #1
	ands r1, r6
	lsls r0, r1, #1
	add r0, sb
	ldrh r0, [r0]
	ands r0, r5
	subs r0, #0x18
	adds r7, #2
	adds r2, r3, r7
	strh r0, [r2]
	adds r1, #1
	ands r1, r6
	mov r0, r8
	str r1, [r0]
	lsls r1, r1, #1
	add r1, sb
	ldrh r0, [r1]
	ands r0, r5
	subs r0, #0x10
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r1, r3, r2
	strh r0, [r1]
	adds r3, #8
	subs r4, #1
	cmp r4, #0
	bge _080C284A
_080C289A:
	mov r7, ip
	ldrh r0, [r7, #4]
	adds r1, r0, #1
	strh r1, [r7, #4]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bls _080C28D4
	movs r0, #0
	strb r0, [r7]
	movs r3, #1
	mov r1, ip
	adds r1, #0x24
	movs r2, #0xac
	lsls r2, r2, #1
	add r2, ip
_080C28BA:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x2c
	cmp r1, r2
	ble _080C28BA
	b _080C296C
	.align 2, 0
_080C28C8: .4byte 0x0203B400
_080C28CC: .4byte 0x030046B8
_080C28D0: .4byte 0x000003FF
_080C28D4:
	movs r5, #0
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3c
	bls _080C28E4
	lsrs r5, r1, #0x12
	movs r0, #1
	ands r5, r0
_080C28E4:
	ldr r4, _080C2904 @ =0x00000266
	add r4, ip
	mov r2, ip
	adds r2, #0x40
	mov r3, ip
	adds r3, #0x24
	movs r6, #0xac
	lsls r6, r6, #1
	add r6, ip
_080C28F6:
	cmp r5, #0
	beq _080C2908
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	b _080C2910
	.align 2, 0
_080C2904: .4byte 0x00000266
_080C2908:
	ldr r0, [r3]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_080C2910:
	str r0, [r3]
	movs r0, #0x99
	lsls r0, r0, #2
	add r0, ip
	ldrh r0, [r0]
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r4]
	ldrh r7, [r2, #2]
	adds r0, r0, r7
	strh r0, [r2, #2]
	movs r0, #0x9a
	lsls r0, r0, #2
	add r0, ip
	ldrh r0, [r0]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	movs r7, #2
	ldrsh r0, [r2, r7]
	cmp r0, #0xff
	bgt _080C295E
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r2, #2]
	movs r0, #0
	ldrsh r1, [r4, r0]
	rsbs r0, r1, #0
	cmp r0, #0
	blt _080C2958
	asrs r0, r0, #1
	b _080C295C
_080C2958:
	asrs r0, r1, #1
	rsbs r0, r0, #0
_080C295C:
	strh r0, [r4]
_080C295E:
	adds r4, #8
	movs r1, #8
	add ip, r1
	adds r2, #0x2c
	adds r3, #0x2c
	cmp r3, r6
	ble _080C28F6
_080C296C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c2978
FUN_080c2978: @ 0x080C2978
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldrh r0, [r6, #4]
	cmp r0, #0
	bne _080C29AA
	ldrb r0, [r6, #1]
	adds r1, r6, #0
	adds r1, #0x24
	strh r0, [r1, #0x10]
	movs r3, #2
	rsbs r3, r3, #0
	movs r0, #0xac
	lsls r0, r0, #1
	adds r2, r6, r0
_080C2994:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x2c
	cmp r1, r2
	ble _080C2994
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r6, #0
	bl FUN_080c2694
_080C29AA:
	ldr r0, [r6, #0x18]
	ldr r4, [r0]
	ldr r5, [r0, #4]
	adds r0, r4, #0
	ldrh r1, [r6, #8]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _080C2A00 @ =0xFFFF0000
	adds r1, r3, #0
	ands r1, r4
	orrs r1, r0
	asrs r0, r1, #0x10
	ldrh r2, [r6, #0xa]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	ldr r2, _080C2A04 @ =0x0000FFFF
	ands r1, r2
	adds r4, r1, #0
	orrs r4, r0
	adds r0, r5, #0
	ldrh r1, [r6, #0xc]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r3, r5
	adds r5, r3, #0
	orrs r5, r0
	movs r0, #0x10
	ldrsh r2, [r6, r0]
	ldrh r1, [r6, #4]
	movs r0, #4
	subs r0, r0, r1
	muls r2, r0, r2
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	muls r0, r1, r0
	adds r0, r2, r0
	adds r3, r1, #0
	cmp r0, #0
	blt _080C2A08
	asrs r0, r0, #2
	b _080C2A0E
	.align 2, 0
_080C2A00: .4byte 0xFFFF0000
_080C2A04: .4byte 0x0000FFFF
_080C2A08:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_080C2A0E:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080C2A34 @ =0xFFFF0000
	ands r1, r4
	orrs r1, r0
	adds r4, r1, #0
	movs r0, #0x12
	ldrsh r2, [r6, r0]
	movs r0, #4
	subs r0, r0, r3
	muls r2, r0, r2
	asrs r1, r1, #0x10
	adds r0, r1, #0
	muls r0, r3, r0
	adds r0, r2, r0
	cmp r0, #0
	blt _080C2A38
	asrs r0, r0, #2
	b _080C2A3E
	.align 2, 0
_080C2A34: .4byte 0xFFFF0000
_080C2A38:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_080C2A3E:
	lsls r1, r0, #0x10
	ldr r0, _080C2A64 @ =0x0000FFFF
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	movs r2, #0x14
	ldrsh r1, [r6, r2]
	movs r0, #4
	subs r0, r0, r3
	muls r1, r0, r1
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	muls r0, r3, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080C2A68
	asrs r0, r0, #2
	b _080C2A6E
	.align 2, 0
_080C2A64: .4byte 0x0000FFFF
_080C2A68:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_080C2A6E:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080C2AA8 @ =0xFFFF0000
	ands r0, r5
	adds r5, r0, #0
	orrs r5, r1
	movs r3, #0
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	mov ip, r0
	adds r2, r6, #0
	adds r2, #0x40
	asrs r7, r4, #0x10
	lsls r0, r5, #0x10
	asrs r5, r0, #0x10
_080C2A8C:
	movs r0, #8
	subs r4, r0, r3
	movs r1, #0x10
	ldrsh r0, [r6, r1]
	adds r1, r0, #0
	muls r1, r3, r1
	mov r0, ip
	muls r0, r4, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080C2AAC
	asrs r0, r0, #3
	b _080C2AB2
	.align 2, 0
_080C2AA8: .4byte 0xFFFF0000
_080C2AAC:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080C2AB2:
	strh r0, [r2]
	movs r1, #0x12
	ldrsh r0, [r6, r1]
	adds r1, r0, #0
	muls r1, r3, r1
	adds r0, r7, #0
	muls r0, r4, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080C2ACA
	asrs r0, r0, #3
	b _080C2AD0
_080C2ACA:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080C2AD0:
	strh r0, [r2, #2]
	movs r1, #0x14
	ldrsh r0, [r6, r1]
	adds r1, r0, #0
	muls r1, r3, r1
	adds r0, r5, #0
	muls r0, r4, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080C2AE8
	asrs r0, r0, #3
	b _080C2AEE
_080C2AE8:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080C2AEE:
	strh r0, [r2, #4]
	adds r2, #0x2c
	adds r3, #1
	cmp r3, #7
	ble _080C2A8C
	ldrh r0, [r6, #4]
	adds r0, #1
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _080C2B14
	ldr r0, _080C2B1C @ =0x00000233
	bl PlaySound_082406e0
	ldr r1, _080C2B20 @ =FUN_080c26cc
	adds r0, r6, #0
	bl FUN_080c2680
_080C2B14:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C2B1C: .4byte 0x00000233
_080C2B20: .4byte FUN_080c26cc

	thumb_func_start FUN_080c2b24
FUN_080c2b24: @ 0x080C2B24
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, _080C2B58 @ =0x00001934
	adds r4, r6, r0
	movs r7, #0
	movs r5, #3
_080C2B30:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080C2B44
	ldr r1, _080C2B5C @ =0x00001BD8
	adds r0, r6, r1
	adds r0, r0, r7
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080C2B44:
	movs r0, #0xaa
	lsls r0, r0, #2
	adds r4, r4, r0
	adds r7, r7, r0
	subs r5, #1
	cmp r5, #0
	bge _080C2B30
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C2B58: .4byte 0x00001934
_080C2B5C: .4byte 0x00001BD8

	thumb_func_start FUN_080c2b60
FUN_080c2b60: @ 0x080C2B60
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r1, _080C2BA0 @ =0x00001930
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C2B98
	movs r1, #0
_080C2B70:
	movs r5, #0
	lsls r0, r1, #2
	adds r6, r1, #1
	adds r0, r0, r1
	lsls r1, r0, #4
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r7
	ldr r1, _080C2BA4 @ =0x00001958
	adds r4, r0, r1
_080C2B84:
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r4, #0x2c
	adds r5, #1
	cmp r5, #7
	ble _080C2B84
	adds r1, r6, #0
	cmp r1, #3
	ble _080C2B70
_080C2B98:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C2BA0: .4byte 0x00001930
_080C2BA4: .4byte 0x00001958

	thumb_func_start FUN_080c2ba8
FUN_080c2ba8: @ 0x080C2BA8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp]
	ldr r1, _080C2C08 @ =0x00001930
	adds r1, r0, r1
	str r1, [sp, #4]
	movs r0, #1
	strb r0, [r1]
	movs r2, #0
	mov r8, r2
	movs r3, #0xc0
	mov sl, r3
_080C2BC8:
	mov r1, r8
	lsls r0, r1, #2
	add r0, r8
	lsls r1, r0, #4
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #4
	ldr r2, [sp, #4]
	adds r4, r2, r0
	movs r3, #0
	strb r3, [r4]
	mov r0, r8
	strb r0, [r4, #1]
	strb r3, [r4, #2]
	movs r0, #0xa0
	lsls r0, r0, #3
	strh r0, [r4, #0x10]
	movs r0, #0xe0
	lsls r0, r0, #3
	strh r0, [r4, #0x12]
	movs r0, #0xd1
	lsls r0, r0, #2
	strh r0, [r4, #0x14]
	mov r1, r8
	cmp r1, #1
	beq _080C2C28
	cmp r1, #1
	bgt _080C2C0C
	cmp r1, #0
	beq _080C2C18
	b _080C2C54
	.align 2, 0
_080C2C08: .4byte 0x00001930
_080C2C0C:
	mov r2, r8
	cmp r2, #2
	beq _080C2C38
	cmp r2, #3
	beq _080C2C48
	b _080C2C54
_080C2C18:
	ldr r0, _080C2C24 @ =0x0000FFC8
	strh r0, [r4, #8]
	mov r3, sl
	strh r3, [r4, #0xa]
	subs r0, #0x10
	b _080C2C52
	.align 2, 0
_080C2C24: .4byte 0x0000FFC8
_080C2C28:
	ldr r0, _080C2C34 @ =0x0000FF98
	strh r0, [r4, #8]
	mov r0, sl
	strh r0, [r4, #0xa]
	movs r0, #0x58
	b _080C2C52
	.align 2, 0
_080C2C34: .4byte 0x0000FF98
_080C2C38:
	movs r0, #0x68
	strh r0, [r4, #8]
	mov r1, sl
	strh r1, [r4, #0xa]
	ldr r0, _080C2C44 @ =0x0000FFA0
	b _080C2C52
	.align 2, 0
_080C2C44: .4byte 0x0000FFA0
_080C2C48:
	movs r0, #0x38
	strh r0, [r4, #8]
	mov r2, sl
	strh r2, [r4, #0xa]
	movs r0, #0x48
_080C2C52:
	strh r0, [r4, #0xc]
_080C2C54:
	movs r3, #8
	ldrsh r0, [r4, r3]
	ldrh r1, [r4, #8]
	cmp r0, #0
	ble _080C2C78
	ldrh r2, [r4, #0xc]
	movs r3, #0xc
	ldrsh r0, [r4, r3]
	cmp r0, #0
	ble _080C2C78
	ldrh r0, [r4, #0x10]
	adds r0, #0x60
	adds r0, r1, r0
	strh r0, [r4, #0x10]
	ldrh r0, [r4, #0x14]
	subs r0, #0x60
	adds r0, r2, r0
	b _080C2CAE
_080C2C78:
	lsls r0, r1, #0x10
	cmp r0, #0
	bge _080C2C98
	ldrh r2, [r4, #0xc]
	movs r3, #0xc
	ldrsh r0, [r4, r3]
	cmp r0, #0
	bge _080C2C98
	ldrh r0, [r4, #0x10]
	subs r0, #0x30
	adds r0, r1, r0
	strh r0, [r4, #0x10]
	ldrh r0, [r4, #0x14]
	adds r0, #0x30
	adds r0, r2, r0
	b _080C2CAE
_080C2C98:
	movs r1, #8
	ldrsh r0, [r4, r1]
	lsls r0, r0, #2
	ldrh r2, [r4, #0x10]
	adds r0, r0, r2
	strh r0, [r4, #0x10]
	movs r3, #0xc
	ldrsh r0, [r4, r3]
	lsls r0, r0, #2
	ldrh r1, [r4, #0x14]
	adds r0, r0, r1
_080C2CAE:
	strh r0, [r4, #0x14]
	movs r3, #0
	movs r2, #1
	add r2, r8
	mov sb, r2
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r7, r4, r0
_080C2CBE:
	movs r0, #0x2c
	muls r0, r3, r0
	adds r0, #0x24
	adds r6, r4, r0
	cmp r3, #0
	bne _080C2CD8
	ldr r1, _080C2CD4 @ =0x00008205
	mov r5, r8
	adds r5, #0xd
	b _080C2CDC
	.align 2, 0
_080C2CD4: .4byte 0x00008205
_080C2CD8:
	ldr r1, _080C2D2C @ =0x00008207
	movs r5, #6
_080C2CDC:
	adds r0, r7, #0
	str r3, [sp, #8]
	bl Video_GetAuxSprite
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0
	bl AuxSprite_Add
	strh r5, [r6, #0x10]
	movs r0, #1
	strb r0, [r6, #7]
	adds r7, #0x1c
	ldr r3, [sp, #8]
	adds r3, #1
	cmp r3, #7
	ble _080C2CBE
	adds r0, r4, #0
	ldr r1, _080C2D30 @ =0x00000165
	bl FUN_080c2694
	ldr r1, [sp]
	ldr r2, _080C2D34 @ =0x00000424
	adds r0, r1, r2
	ldr r0, [r0]
	str r0, [r4, #0x18]
	mov r8, sb
	mov r3, r8
	cmp r3, #3
	bgt _080C2D1A
	b _080C2BC8
_080C2D1A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C2D2C: .4byte 0x00008207
_080C2D30: .4byte 0x00000165
_080C2D34: .4byte 0x00000424

	thumb_func_start FUN_080c2d38
FUN_080c2d38: @ 0x080C2D38
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov r8, r0
	ldr r0, _080C2DA8 @ =0x00000DB9
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	bne _080C2D50
	b _080C2E72
_080C2D50:
	movs r7, #0
	ldr r0, _080C2DAC @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r6, r0, #0x1f
	movs r5, #0
_080C2D66:
	movs r0, #0x54
	adds r1, r5, #0
	muls r1, r0, r1
	mov r2, r8
	adds r0, r2, r1
	ldr r3, _080C2DB0 @ =0x00000E14
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C2E64
	ldr r4, _080C2DB4 @ =0x00000DC4
	adds r0, r1, r4
	adds r4, r2, r0
	adds r1, r4, #0
	adds r1, #0x51
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	strb r0, [r1]
	adds r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _080C2DB8
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	adds r0, r4, #0
	adds r0, #0x50
	strb r2, [r0]
	b _080C2E64
	.align 2, 0
_080C2DA8: .4byte 0x00000DB9
_080C2DAC: .4byte 0x03002BE0
_080C2DB0: .4byte 0x00000E14
_080C2DB4: .4byte 0x00000DC4
_080C2DB8:
	movs r7, #1
	adds r0, r4, #0
	adds r0, #0x48
	ldrh r0, [r0]
	ldrh r1, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0x4a
	ldrh r0, [r0]
	ldrh r2, [r4, #0x1e]
	adds r0, r0, r2
	strh r0, [r4, #0x1e]
	adds r0, r4, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	ldrh r3, [r4, #0x20]
	adds r0, r0, r3
	strh r0, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x53
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C2E32
	cmp r6, #0
	bne _080C2E32
	ldr r0, _080C2E44 @ =0x03002BE0
	ldr r2, [r0]
	movs r0, #0x2c
	ldrsh r1, [r2, r0]
	movs r3, #0x1c
	ldrsh r0, [r4, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _080C2E00
	rsbs r1, r1, #0
_080C2E00:
	cmp r1, #0x3f
	bgt _080C2E32
	movs r0, #0x30
	ldrsh r1, [r2, r0]
	movs r3, #0x20
	ldrsh r0, [r4, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _080C2E14
	rsbs r1, r1, #0
_080C2E14:
	cmp r1, #0x3f
	bgt _080C2E32
	ldr r0, _080C2E48 @ =0x00000DBE
	add r0, r8
	ldrh r1, [r0]
	movs r0, #4
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	adds r0, r2, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0807e7fc
	movs r6, #1
_080C2E32:
	adds r1, r4, #0
	adds r1, #0x51
	ldrb r0, [r1]
	cmp r0, #0x2c
	bhi _080C2E4C
	movs r1, #4
	bl Div
	b _080C2E62
	.align 2, 0
_080C2E44: .4byte 0x03002BE0
_080C2E48: .4byte 0x00000DBE
_080C2E4C:
	cmp r0, #0x47
	bne _080C2E54
	movs r0, #0xe
	b _080C2E62
_080C2E54:
	cmp r0, #0x4a
	bne _080C2E5C
	movs r0, #5
	b _080C2E62
_080C2E5C:
	cmp r0, #0x4d
	bne _080C2E64
	movs r0, #2
_080C2E62:
	strh r0, [r4, #0x10]
_080C2E64:
	adds r5, #1
	cmp r5, #0x1f
	bgt _080C2E6C
	b _080C2D66
_080C2E6C:
	ldr r0, _080C2F1C @ =0x00000DB9
	add r0, r8
	strb r7, [r0]
_080C2E72:
	ldr r2, _080C2F20 @ =0x00000DBC
	add r2, r8
	ldrb r0, [r2]
	cmp r0, #0
	bne _080C2E7E
	b _080C30FE
_080C2E7E:
	ldr r1, _080C2F24 @ =0x00000DBB
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080C2E92
	b _080C30F6
_080C2E92:
	ldr r0, _080C2F28 @ =0x00000DBA
	add r0, r8
	ldrb r1, [r0]
	movs r0, #0x54
	muls r0, r1, r0
	ldr r4, _080C2F2C @ =0x00000DC4
	adds r0, r0, r4
	mov r1, r8
	adds r7, r1, r0
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	movs r0, #0
	strh r0, [r7, #0x10]
	ldrb r0, [r2]
	cmp r0, #1
	bne _080C2F90
	ldr r2, _080C2F30 @ =0x0203B400
	mov sb, r2
	ldr r4, _080C2F34 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080C2F38 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #0x30
	bl Mod
	adds r6, r0, #0
	adds r6, #0x28
	ldr r1, [r4]
	adds r1, #1
	ands r1, r5
	lsls r2, r1, #1
	add r2, sb
	ldrh r2, [r2]
	movs r3, #0x7f
	ands r2, r3
	adds r3, #0xc1
	adds r3, r3, r2
	mov ip, r3
	adds r1, #1
	ands r1, r5
	str r1, [r4]
	lsls r1, r1, #1
	add r1, sb
	ldrh r1, [r1]
	movs r2, #3
	ands r1, r2
	adds r5, r1, #3
	ldr r2, _080C2F3C @ =0x085B0A08
	adds r0, #0x68
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r5, r0
	cmp r0, #0
	blt _080C2F40
	asrs r0, r0, #0xc
	b _080C2F46
	.align 2, 0
_080C2F1C: .4byte 0x00000DB9
_080C2F20: .4byte 0x00000DBC
_080C2F24: .4byte 0x00000DBB
_080C2F28: .4byte 0x00000DBA
_080C2F2C: .4byte 0x00000DC4
_080C2F30: .4byte 0x0203B400
_080C2F34: .4byte 0x030046B8
_080C2F38: .4byte 0x000003FF
_080C2F3C: .4byte 0x085B0A08
_080C2F40:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C2F46:
	adds r2, r7, #0
	adds r2, #0x48
	strh r0, [r2]
	adds r1, r7, #0
	adds r1, #0x4a
	movs r0, #3
	strh r0, [r1]
	ldr r1, _080C2F70 @ =0x085B0A08
	movs r0, #0xff
	ands r6, r0
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	adds r5, r2, #0
	cmp r0, #0
	blt _080C2F74
	asrs r2, r0, #0xc
	b _080C2F7A
	.align 2, 0
_080C2F70: .4byte 0x085B0A08
_080C2F74:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C2F7A:
	adds r1, r7, #0
	adds r1, #0x4c
	movs r0, #0
	strh r2, [r1]
	adds r3, r7, #0
	adds r3, #0x53
	strb r0, [r3]
	ldr r3, _080C2F8C @ =0x030046B8
	b _080C3030
	.align 2, 0
_080C2F8C: .4byte 0x030046B8
_080C2F90:
	ldr r5, _080C2FE0 @ =0x0203B400
	ldr r3, _080C2FE4 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r4, _080C2FE8 @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r2, [r0]
	asrs r2, r2, #3
	movs r0, #0x1f
	ands r2, r0
	adds r6, r2, #0
	adds r6, #0x30
	movs r0, #0xc0
	lsls r0, r0, #1
	mov ip, r0
	adds r1, #1
	ands r1, r4
	str r1, [r3]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r1]
	movs r1, #7
	ands r0, r1
	adds r5, r0, #0
	adds r5, #0xa
	ldr r1, _080C2FEC @ =0x085B0A08
	adds r2, #0x70
	lsls r2, r2, #1
	adds r2, r2, r1
	movs r4, #0
	ldrsh r0, [r2, r4]
	muls r0, r5, r0
	adds r2, r1, #0
	cmp r0, #0
	blt _080C2FF0
	asrs r4, r0, #0xc
	b _080C2FF6
	.align 2, 0
_080C2FE0: .4byte 0x0203B400
_080C2FE4: .4byte 0x030046B8
_080C2FE8: .4byte 0x000003FF
_080C2FEC: .4byte 0x085B0A08
_080C2FF0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r4, r0, #0
_080C2FF6:
	adds r1, r7, #0
	adds r1, #0x48
	movs r0, #0
	strh r4, [r1]
	adds r4, r7, #0
	adds r4, #0x4a
	strh r0, [r4]
	movs r0, #0xff
	ands r6, r0
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	adds r5, r1, #0
	cmp r0, #0
	blt _080C301C
	asrs r0, r0, #0xc
	b _080C3022
_080C301C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C3022:
	adds r1, r7, #0
	adds r1, #0x4c
	strh r0, [r1]
	adds r4, r7, #0
	adds r4, #0x53
	movs r0, #1
	strb r0, [r4]
_080C3030:
	adds r4, r1, #0
	movs r0, #0xba
	lsls r0, r0, #2
	add r0, r8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldrh r1, [r5]
	ldrh r0, [r7, #0x20]
	adds r1, r1, r0
	strh r1, [r7, #0x20]
	ldrh r0, [r4]
	add r0, ip
	adds r1, r1, r0
	strh r1, [r7, #0x20]
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _080C3074 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _080C3078 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080C307C
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _080C3084
	.align 2, 0
_080C3074: .4byte 0x000003FF
_080C3078: .4byte 0x0203B400
_080C307C:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080C3084:
	str r0, [r7]
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _080C30AC @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _080C30B0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080C30B4
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080C30BC
	.align 2, 0
_080C30AC: .4byte 0x000003FF
_080C30B0: .4byte 0x0203B400
_080C30B4:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080C30BC:
	str r0, [r7]
	adds r0, r7, #0
	adds r0, #0x51
	movs r2, #0
	strb r2, [r0]
	adds r1, r7, #0
	adds r1, #0x52
	movs r0, #0x50
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x50
	movs r1, #1
	strb r1, [r0]
	ldr r0, _080C310C @ =0x00000DB9
	add r0, r8
	strb r1, [r0]
	ldr r1, _080C3110 @ =0x00000DBA
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _080C30F0
	strb r2, [r1]
_080C30F0:
	ldr r0, _080C3114 @ =0x00000DBB
	add r0, r8
	strb r2, [r0]
_080C30F6:
	ldr r1, _080C3118 @ =0x00000DBC
	add r1, r8
	movs r0, #0
	strb r0, [r1]
_080C30FE:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C310C: .4byte 0x00000DB9
_080C3110: .4byte 0x00000DBA
_080C3114: .4byte 0x00000DBB
_080C3118: .4byte 0x00000DBC

	thumb_func_start FUN_080c311c
FUN_080c311c: @ 0x080C311C
	push {r4, r5, lr}
	adds r1, r0, #0
	ldr r2, _080C3144 @ =0x00000DB8
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C313E
	ldr r0, _080C3148 @ =0x00000DC4
	adds r4, r1, r0
	movs r5, #0x1f
_080C3130:
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r4, #0x54
	subs r5, #1
	cmp r5, #0
	bge _080C3130
_080C313E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C3144: .4byte 0x00000DB8
_080C3148: .4byte 0x00000DC4

