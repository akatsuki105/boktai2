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
	bl MsgQueue_BeginWait
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
	bl MsgQueue_EndWait
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
	bl MsgQueue_Unregister
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
	bl MsgQueue_Register
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
