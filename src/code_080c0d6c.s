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
_080C0DF4:
	.byte 0x00, 0xB5, 0x02, 0x1C, 0x11, 0x1C, 0x60, 0x31, 0x6E, 0x30, 0x00, 0x88
	.byte 0x0B, 0x88, 0xC0, 0x18, 0x08, 0x80, 0x04, 0x31, 0x10, 0x1C, 0x70, 0x30, 0x00, 0x88, 0x0B, 0x88
	.byte 0xC0, 0x18, 0x08, 0x80, 0x10, 0x6E, 0x51, 0x6E, 0x50, 0x63, 0x91, 0x63, 0x11, 0x1C, 0x76, 0x31
	.byte 0x08, 0x88, 0x01, 0x30, 0x08, 0x80, 0x02, 0x39, 0x00, 0x04, 0x00, 0x0C, 0x09, 0x88, 0x88, 0x42
	.byte 0x03, 0xD3, 0x03, 0x49, 0x10, 0x1C, 0xFF, 0xF7, 0x99, 0xFF, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0x79, 0x0D, 0x0C, 0x08

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
	ldr r1, _080C0E74 @ =0x080C0DF5
	adds r0, r2, #0
	bl FUN_080c0d6c
_080C0E70:
	pop {r0}
	bx r0
	.align 2, 0
_080C0E74: .4byte 0x080C0DF5

	thumb_func_start FUN_080c0e78
FUN_080c0e78: @ 0x080C0E78
	push {lr}
	ldr r1, [r0, #0x78]
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_080C0E88:
	.byte 0x00, 0xB5, 0x18, 0x30, 0x69, 0xF1, 0x28, 0xFB
	.byte 0x00, 0x20, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00

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
	bl Video_GetActorSprite
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
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
	bl FUN_0822b20c
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
	ldr r1, _080C0F9C @ =0x080C0DF5
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
_080C0F9C: .4byte 0x080C0DF5

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
	ldr r2, _080C0FF4 @ =0x080C0E89
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
_080C0FF4: .4byte 0x080C0E89
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
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080C105C
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080C1054 @ =0xFFFF0000
	ldr r1, [sp, #0x10]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x10]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080C1058 @ =0x0000FFFF
	ldr r1, [sp, #0x10]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x10]
	bl Script_GetValue
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
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080C107C
	bl Script_GetValue
	adds r0, #0x2c
	b _080C107E
	.align 2, 0
_080C1078: .4byte 0xFFFF0000
_080C107C:
	movs r0, #0x2c
_080C107E:
	mov r8, r0
	movs r0, #0x45
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080C1092
	bl Script_GetValue
	adds r7, r0, #0
	b _080C1094
_080C1092:
	movs r7, #0
_080C1094:
	movs r0, #0x64
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080C10A6
	bl Script_GetValue
	adds r6, r0, #0
	b _080C10A8
_080C10A6:
	movs r6, #0
_080C10A8:
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080C10BA
	bl Script_GetValue
	adds r5, r0, #0
	b _080C10BC
_080C10BA:
	movs r5, #0x20
_080C10BC:
	movs r0, #0x77
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080C10CE
	bl Script_GetValue
	adds r4, r0, #0
	b _080C10D0
_080C10CE:
	movs r4, #0
_080C10D0:
	movs r0, #0x6c
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080C10E0
	bl Script_GetValue
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
_080C1108:
	.byte 0x70, 0xB5, 0x05, 0x1C, 0x0E, 0x1C, 0x09, 0x20
	.byte 0x7C, 0x21, 0x6F, 0xF1, 0x4D, 0xFD, 0x04, 0x1C, 0x00, 0x2C, 0x13, 0xD0, 0x07, 0x49, 0x08, 0x4A
	.byte 0x6F, 0xF1, 0x6A, 0xFD, 0x20, 0x1C, 0x29, 0x1C, 0x32, 0x1C, 0xFF, 0xF7, 0x6D, 0xFF, 0x00, 0x28
	.byte 0x08, 0xDA, 0x20, 0x1C, 0x6F, 0xF1, 0x9A, 0xFD, 0x00, 0x20, 0x04, 0xE0, 0x79, 0x0E, 0x0C, 0x08
	.byte 0x89, 0x0E, 0x0C, 0x08, 0x20, 0x1C, 0x70, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x70, 0x47, 0x00, 0x00

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
	bl FUN_08022474
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
	bl FUN_08022488
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
	bl FUN_08022428
	adds r4, #0x4c
	adds r0, r4, #0
	bl FUN_0822a4e0
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
	bl FUN_080223f4
	movs r0, #0x70
	bl VM_SeekToKeyword
	adds r2, r0, #0
	cmp r2, #0
	beq _080C12D2
	bl Script_GetValue
	adds r4, r7, #0
	adds r4, #0xa4
	strh r0, [r4]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0xa6
	strh r0, [r1]
	bl Script_GetValue
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
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080C12F4
	bl Script_GetValue
	b _080C12F6
_080C12F4:
	movs r0, #2
_080C12F6:
	mov sb, r0
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080C131A
	bl Script_GetValue
	adds r4, r7, #0
	adds r4, #0x9a
	strh r0, [r4]
	bl Script_GetValue
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
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #2
	bl FUN_0822a470
	adds r0, r4, #0
	movs r1, #0x32
	bl FUN_0822b20c
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
	ldr r0, _080C13A0 @ =0x080C114D
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
_080C13A0: .4byte 0x080C114D

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
_080C1810:
	.byte 0x70, 0xB5, 0x04, 0x1C, 0xA0, 0x69, 0xDF, 0x21, 0x89, 0x00, 0x40, 0x18, 0x05, 0x78, 0x03, 0x2D
	.byte 0x03, 0xD0, 0x20, 0x1C, 0x6F, 0xF1, 0x22, 0xFA, 0x54, 0xE0, 0x20, 0x1C, 0xFF, 0xF7, 0xE4, 0xFD
	.byte 0xA0, 0x69, 0x0B, 0x49, 0x40, 0x18, 0x00, 0x78, 0x05, 0x28, 0x15, 0xD1, 0x20, 0x1C, 0xFF, 0xF7
	.byte 0xD3, 0xFF, 0xE0, 0x69, 0x02, 0x21, 0x49, 0x42, 0x08, 0x40, 0xE0, 0x61, 0x20, 0x1C, 0x6F, 0x30
	.byte 0x00, 0x78, 0xA0, 0x85, 0x03, 0x49, 0x20, 0x1C, 0xFF, 0xF7, 0xC6, 0xFD, 0x3A, 0xE0, 0x00, 0x00
	.byte 0x7D, 0x03, 0x00, 0x00, 0xDD, 0x18, 0x0C, 0x08, 0x20, 0x1C, 0xFF, 0xF7, 0x83, 0xFE, 0xA0, 0x69
	.byte 0x0A, 0x49, 0x40, 0x18, 0x00, 0x78, 0x02, 0x28, 0x12, 0xD1, 0x21, 0x1C, 0x70, 0x31, 0x08, 0x88
	.byte 0x05, 0x40, 0x0E, 0x1C, 0x03, 0x2D, 0x02, 0xD1, 0x20, 0x1C, 0xFF, 0xF7, 0xEB, 0xFE, 0x21, 0x1C
	.byte 0x6F, 0x31, 0x00, 0x20, 0x08, 0x70, 0x0A, 0x1C, 0x0E, 0xE0, 0x00, 0x00, 0x7D, 0x03, 0x00, 0x00
	.byte 0xE0, 0x69, 0x02, 0x21, 0x49, 0x42, 0x08, 0x40, 0xE0, 0x61, 0x21, 0x1C, 0x6F, 0x31, 0x01, 0x20
	.byte 0x08, 0x70, 0x0A, 0x1C, 0x26, 0x1C, 0x70, 0x36, 0x30, 0x88, 0x80, 0x08, 0x01, 0x21, 0x08, 0x40
	.byte 0x00, 0x28, 0x02, 0xD0, 0x10, 0x78, 0x01, 0x30, 0x00, 0xE0, 0x10, 0x78, 0xA0, 0x85, 0x30, 0x88
	.byte 0x01, 0x30, 0x30, 0x80, 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x00, 0xB5, 0x02, 0x1C
	.byte 0x64, 0x30, 0x00, 0x88, 0x11, 0x8F, 0x40, 0x18, 0x10, 0x87, 0x10, 0x1C, 0x68, 0x30, 0x00, 0x88
	.byte 0x91, 0x8F, 0x40, 0x18, 0x90, 0x87, 0x11, 0x1C, 0x70, 0x31, 0x08, 0x88, 0x01, 0x30, 0x08, 0x80
	.byte 0x02, 0x31, 0x00, 0x04, 0x00, 0x0C, 0x09, 0x88, 0x88, 0x42, 0x03, 0xD3, 0x02, 0x49, 0x10, 0x1C
	.byte 0xFF, 0xF7, 0x6A, 0xFD, 0x01, 0xBC, 0x00, 0x47, 0x1D, 0x19, 0x0C, 0x08

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
_080C19A8:
	.byte 0x00, 0xB5, 0x9E, 0x22, 0x52, 0x00, 0x81, 0x18
	.byte 0x09, 0x68, 0x8B, 0xF1, 0x57, 0xFA, 0x00, 0x20, 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_080c19bc
FUN_080c19bc: @ 0x080C19BC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x1c
	bl FUN_0822a4e0
	adds r4, #0x7c
	movs r5, #3
_080C19CA:
	adds r0, r4, #0
	bl FUN_0822dabc
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
	bl Video_GetActorSprite
	adds r4, #0x1c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #1
	bl FUN_0822a470
	movs r0, #0
	strh r0, [r4, #0x10]
	adds r0, r5, #0
	movs r1, #0x2e
	bl FUN_0822b20c
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
	bl FUN_0822d9f0
	adds r0, r4, #0
	mov r1, r8
	mov r2, r8
	bl FUN_0822dad4
	ldr r1, [r5, #0x78]
	adds r0, r4, #0
	movs r2, #0x11
	bl FUN_0822dafc
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
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
	ldr r1, _080C1AB8 @ =0x080C1811
	adds r0, r4, #0
	bl FUN_080c13e8
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080C1AB8: .4byte 0x080C1811

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
	ldr r1, _080C1AF8 @ =0x080C19A9
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
_080C1AF8: .4byte 0x080C19A9
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
	bl FUN_082372cc
	adds r0, r5, #0
	adds r0, #0xf8
	adds r1, r4, #0
	bl FUN_082372cc
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r4, #0
	bl FUN_082372cc
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
	bl Script_ExecById
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
	bl FUN_082370cc
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #1
	movs r3, #1
	bl Sprite_SetSprite
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
	bl FUN_080477e4
	movs r3, #0x89
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r0, [r0]
	bl FUN_08047a28
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
	bl FUN_0822f1c0
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
	bl FUN_0822c0b8
	movs r0, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0822c398
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
	bl OpenSpriteSetFile
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
	bl FUN_0822f3fc
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
	bl FUN_0822f3fc
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
	bl FUN_0822f3fc
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
	bl FUN_0822f3fc
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
	bl FUN_0822f3fc
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
	bl Sprite_SetSprite
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
	bl FUN_082370cc
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
	bl FUN_082370cc
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
	bl FUN_082370cc
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
	bl FUN_082370cc
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
	bl FUN_082370cc
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
	bl FUN_082370cc
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
	bl Sprite_SetSprite
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
	bl FUN_082370cc
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
	bl FUN_082370cc
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
	bl FUN_082370cc
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
	bl FUN_082370cc
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
	bl FUN_082370cc
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
	bl FUN_082370cc
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
	bl FUN_082370cc
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
	bl Sprite_SetSprite
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
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080C25B2
	bl FUN_0823d340
	movs r1, #0x86
	lsls r1, r1, #2
	adds r6, r5, r1
	str r0, [r6]
	movs r0, #0x6d
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080C25B2
	bl Script_GetValue
	movs r2, #0x89
	lsls r2, r2, #2
	adds r4, r5, r2
	strh r0, [r4]
	bl Script_GetValue
	ldrh r1, [r4]
	adds r1, r1, r0
	subs r1, #1
	ldr r2, _080C2594 @ =0x00000226
	adds r0, r5, r2
	strh r1, [r0]
	ldr r0, _080C2598 @ =0x0000EFDA
	bl FUN_08047dc0
	ldr r0, [r6]
	bl FUN_080478f0
	movs r0, #1
	bl FUN_080477e4
	ldrh r0, [r4]
	bl FUN_08047a28
_080C2580:
	movs r0, #0x63
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080C25A0
	bl Script_GetValue
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
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _080C25DC
	bl Script_GetValue
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
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _080C25FE
	bl Script_GetValue
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
	bl FUN_0822b20c
	adds r4, #0x1c
	subs r5, #1
	cmp r5, #0
	bge _080C26B4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C26CC:
	.byte 0xF0, 0xB5, 0x47, 0x46
	.byte 0x80, 0xB4, 0x06, 0x1C, 0xB0, 0x88, 0x00, 0x28, 0x1F, 0xD1, 0x70, 0x78, 0x31, 0x1C, 0x24, 0x31
	.byte 0x0D, 0x30, 0x08, 0x82, 0x02, 0x23, 0x5B, 0x42, 0xAC, 0x20, 0x40, 0x00, 0x32, 0x18, 0x08, 0x68
	.byte 0x18, 0x40, 0x08, 0x60, 0x2C, 0x31, 0x91, 0x42, 0xF9, 0xDD, 0xB0, 0x78, 0x01, 0x28, 0x05, 0xD1
	.byte 0x25, 0x49, 0x30, 0x1C, 0xFF, 0xF7, 0xC6, 0xFF, 0x06, 0x20, 0xF0, 0x70, 0x00, 0x20, 0xB0, 0x83
	.byte 0xF0, 0x83, 0x30, 0x84, 0xB0, 0x88, 0x01, 0x30, 0xB0, 0x80, 0xB2, 0x69, 0x11, 0x68, 0xF0, 0x69
	.byte 0x81, 0x42, 0x05, 0xD1, 0x04, 0x23, 0xD1, 0x5E, 0x20, 0x24, 0x30, 0x5F, 0x81, 0x42, 0x73, 0xD0
	.byte 0x53, 0x68, 0x12, 0x68, 0x10, 0x1C, 0x31, 0x89, 0x40, 0x18, 0x00, 0x04, 0x00, 0x0C, 0x17, 0x4D
	.byte 0x29, 0x1C, 0x11, 0x40, 0x01, 0x43, 0x08, 0x14, 0x74, 0x89, 0x00, 0x19, 0x00, 0x04, 0x14, 0x4C
	.byte 0x0C, 0x40, 0x04, 0x43, 0x22, 0x1C, 0x18, 0x1C, 0xB1, 0x89, 0x40, 0x18, 0x00, 0x04, 0x00, 0x0C
	.byte 0x1D, 0x40, 0x2B, 0x1C, 0x03, 0x43, 0x00, 0x20, 0x84, 0x46, 0x10, 0x04, 0x00, 0x14, 0x80, 0x46
	.byte 0x37, 0x1C, 0x40, 0x37, 0x24, 0x14, 0x18, 0x04, 0x02, 0x14, 0x08, 0x20, 0x61, 0x46, 0x45, 0x1A
	.byte 0x10, 0x23, 0xF0, 0x5E, 0x61, 0x46, 0x41, 0x43, 0x40, 0x46, 0x68, 0x43, 0x08, 0x18, 0x00, 0x28
	.byte 0x08, 0xDB, 0xC0, 0x10, 0x09, 0xE0, 0x00, 0x00, 0x67, 0x01, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF
	.byte 0xFF, 0xFF, 0x00, 0x00, 0x40, 0x42, 0xC0, 0x10, 0x40, 0x42, 0x38, 0x80, 0x12, 0x21, 0x70, 0x5E
	.byte 0x61, 0x46, 0x41, 0x43, 0x20, 0x1C, 0x68, 0x43, 0x08, 0x18, 0x00, 0x28, 0x01, 0xDB, 0xC0, 0x10
	.byte 0x02, 0xE0, 0x40, 0x42, 0xC0, 0x10, 0x40, 0x42, 0x78, 0x80, 0x14, 0x23, 0xF0, 0x5E, 0x61, 0x46
	.byte 0x41, 0x43, 0x10, 0x1C, 0x68, 0x43, 0x08, 0x18, 0x00, 0x28, 0x01, 0xDB, 0xC0, 0x10, 0x02, 0xE0
	.byte 0x40, 0x42, 0xC0, 0x10, 0x40, 0x42, 0xB8, 0x80, 0x2C, 0x37, 0x01, 0x20, 0x84, 0x44, 0x61, 0x46
	.byte 0x07, 0x29, 0xC2, 0xDD, 0xF0, 0x78, 0x00, 0x28, 0x09, 0xD0, 0x01, 0x38, 0xF0, 0x70, 0x00, 0x06
	.byte 0x00, 0x28, 0x04, 0xD1, 0xB3, 0x21, 0x49, 0x00, 0x30, 0x1C, 0xFF, 0xF7, 0x43, 0xFF, 0xB0, 0x69
	.byte 0x41, 0x68, 0x00, 0x68, 0xF0, 0x61, 0x31, 0x62, 0x08, 0xBC, 0x98, 0x46, 0xF0, 0xBC, 0x01, 0xBC
	.byte 0x00, 0x47, 0x00, 0x00, 0xF0, 0xB5, 0x4F, 0x46, 0x46, 0x46, 0xC0, 0xB4, 0x84, 0x46, 0x80, 0x88
	.byte 0x00, 0x28, 0x32, 0xD1, 0x61, 0x46, 0x48, 0x78, 0x88, 0x86, 0x23, 0x4A, 0x91, 0x46, 0x23, 0x4F
	.byte 0xB8, 0x46, 0x23, 0x4E, 0x1F, 0x25, 0x63, 0x46, 0x07, 0x24, 0x40, 0x46, 0x01, 0x68, 0x01, 0x31
	.byte 0x31, 0x40, 0x48, 0x00, 0x48, 0x44, 0x00, 0x88, 0x28, 0x40, 0x10, 0x38, 0x99, 0x27, 0xBF, 0x00
	.byte 0xDA, 0x19, 0x10, 0x80, 0x01, 0x31, 0x31, 0x40, 0x48, 0x00, 0x48, 0x44, 0x00, 0x88, 0x28, 0x40
	.byte 0x18, 0x38, 0x02, 0x37, 0xDA, 0x19, 0x10, 0x80, 0x01, 0x31, 0x31, 0x40, 0x40, 0x46, 0x01, 0x60
	.byte 0x49, 0x00, 0x49, 0x44, 0x08, 0x88, 0x28, 0x40, 0x10, 0x38, 0x9A, 0x22, 0x92, 0x00, 0x99, 0x18
	.byte 0x08, 0x80, 0x08, 0x33, 0x01, 0x3C, 0x00, 0x2C, 0xD7, 0xDA, 0x67, 0x46, 0xB8, 0x88, 0x41, 0x1C
	.byte 0xB9, 0x80, 0x08, 0x04, 0x00, 0x0C, 0x59, 0x28, 0x14, 0xD9, 0x00, 0x20, 0x38, 0x70, 0x01, 0x23
	.byte 0x61, 0x46, 0x24, 0x31, 0xAC, 0x22, 0x52, 0x00, 0x62, 0x44, 0x08, 0x68, 0x18, 0x43, 0x08, 0x60
	.byte 0x2C, 0x31, 0x91, 0x42, 0xF9, 0xDD, 0x51, 0xE0, 0x00, 0xB4, 0x03, 0x02, 0xB8, 0x46, 0x00, 0x03
	.byte 0xFF, 0x03, 0x00, 0x00, 0x00, 0x25, 0x09, 0x04, 0x08, 0x0C, 0x3C, 0x28, 0x02, 0xD9, 0x8D, 0x0C
	.byte 0x01, 0x20, 0x05, 0x40, 0x07, 0x4C, 0x64, 0x44, 0x62, 0x46, 0x40, 0x32, 0x63, 0x46, 0x24, 0x33
	.byte 0xAC, 0x26, 0x76, 0x00, 0x66, 0x44, 0x00, 0x2D, 0x06, 0xD0, 0x18, 0x68, 0x01, 0x21, 0x08, 0x43
	.byte 0x06, 0xE0, 0x00, 0x00, 0x66, 0x02, 0x00, 0x00, 0x18, 0x68, 0x02, 0x21, 0x49, 0x42, 0x08, 0x40
	.byte 0x18, 0x60, 0x99, 0x20, 0x80, 0x00, 0x60, 0x44, 0x00, 0x88, 0x11, 0x88, 0x40, 0x18, 0x10, 0x80
	.byte 0x20, 0x88, 0x57, 0x88, 0xC0, 0x19, 0x50, 0x80, 0x9A, 0x20, 0x80, 0x00, 0x60, 0x44, 0x00, 0x88
	.byte 0x91, 0x88, 0x40, 0x18, 0x90, 0x80, 0x20, 0x88, 0x01, 0x38, 0x20, 0x80, 0x02, 0x27, 0xD0, 0x5F
	.byte 0xFF, 0x28, 0x0C, 0xDC, 0x80, 0x20, 0x40, 0x00, 0x50, 0x80, 0x00, 0x20, 0x21, 0x5E, 0x48, 0x42
	.byte 0x00, 0x28, 0x01, 0xDB, 0x40, 0x10, 0x01, 0xE0, 0x48, 0x10, 0x40, 0x42, 0x20, 0x80, 0x08, 0x34
	.byte 0x08, 0x21, 0x8C, 0x44, 0x2C, 0x32, 0x2C, 0x33, 0xB3, 0x42, 0xC4, 0xDD, 0x18, 0xBC, 0x98, 0x46
	.byte 0xA1, 0x46, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47

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
	ldr r1, _080C2B20 @ =0x080C26CD
	adds r0, r6, #0
	bl FUN_080c2680
_080C2B14:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C2B1C: .4byte 0x00000233
_080C2B20: .4byte 0x080C26CD

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
	bl FUN_0822a4e0
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
	bl Video_GetActorSprite
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_0822a470
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
	bl FUN_0822a4e0
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

	thumb_func_start FUN_080c314c
FUN_080c314c: @ 0x080C314C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	ldr r2, _080C31B8 @ =0x00000DB8
	add r2, sb
	movs r3, #0
	movs r0, #1
	strb r0, [r2]
	ldr r0, _080C31BC @ =0x00000DBA
	add r0, sb
	strb r3, [r0]
	ldr r0, _080C31C0 @ =0x00000DBB
	add r0, sb
	strb r3, [r0]
	ldr r0, _080C31C4 @ =0x00000DBE
	add r0, sb
	strh r1, [r0]
	movs r7, #0
	movs r0, #1
	mov sl, r0
	movs r1, #0
	mov r8, r1
_080C317E:
	movs r0, #0x54
	muls r0, r7, r0
	ldr r1, _080C31C8 @ =0x00000DC4
	adds r0, r0, r1
	mov r1, sb
	adds r4, r1, r0
	adds r6, r4, #0
	adds r5, r4, #0
	adds r5, #0x2c
	ldr r0, _080C31CC @ =0x08251E04
	bl FUN_08230860
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl Video_GetActorSprite
	adds r0, r7, #0
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	beq _080C31D4
	adds r0, r4, #0
	adds r1, r5, #0
	ldr r2, _080C31D0 @ =0x00000201
	bl FUN_0822a470
	b _080C31DE
	.align 2, 0
_080C31B8: .4byte 0x00000DB8
_080C31BC: .4byte 0x00000DBA
_080C31C0: .4byte 0x00000DBB
_080C31C4: .4byte 0x00000DBE
_080C31C8: .4byte 0x00000DC4
_080C31CC: .4byte 0x08251E04
_080C31D0: .4byte 0x00000201
_080C31D4:
	adds r0, r4, #0
	adds r1, r5, #0
	ldr r2, _080C3214 @ =0x00000401
	bl FUN_0822a470
_080C31DE:
	mov r0, r8
	strh r0, [r6, #0x10]
	adds r0, r5, #0
	movs r1, #0xb4
	lsls r1, r1, #1
	bl FUN_0822b20c
	mov r1, sl
	strb r1, [r6, #7]
	adds r0, r4, #0
	adds r0, #0x50
	mov r1, r8
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r7, #1
	cmp r7, #0x1f
	ble _080C317E
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3214: .4byte 0x00000401

	thumb_func_start FUN_080c3218
FUN_080c3218: @ 0x080C3218
	adds r2, r0, #0
	adds r2, #0xb8
	str r1, [r2]
	movs r1, #0
	strh r1, [r0, #8]
	bx lr

	thumb_func_start FUN_080c3224
FUN_080c3224: @ 0x080C3224
	push {r4, lr}
	adds r2, r0, #0
	ldrh r0, [r2, #8]
	adds r0, #1
	strh r0, [r2, #8]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bls _080C3244
	ldr r0, [r2, #0x10]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #0x10]
	movs r0, #0
	strb r0, [r2, #1]
	b _080C3272
_080C3244:
	adds r0, r2, #0
	adds r0, #0xa8
	ldrh r0, [r0]
	ldrh r1, [r2, #0x2c]
	adds r0, r0, r1
	strh r0, [r2, #0x2c]
	adds r0, r2, #0
	adds r0, #0xac
	ldrh r0, [r0]
	ldrh r1, [r2, #0x30]
	adds r0, r0, r1
	strh r0, [r2, #0x30]
	adds r4, r2, #0
	adds r4, #0x58
	adds r1, r2, #0
	adds r1, #0x2c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
_080C3272:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c3278
FUN_080c3278: @ 0x080C3278
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrh r0, [r5, #8]
	adds r1, r0, #1
	strh r1, [r5, #8]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bls _080C3298
	ldr r0, [r5, #0x10]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #0x10]
	movs r0, #0
	strb r0, [r5, #1]
	b _080C33D0
_080C3298:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x18
	bls _080C32AA
	ldrb r0, [r5, #4]
	cmp r0, #0x13
	bhi _080C32AA
	adds r0, #1
	strb r0, [r5, #4]
_080C32AA:
	ldrh r0, [r5, #8]
	cmp r0, #0x17
	bhi _080C32C0
	adds r2, r5, #0
	adds r2, #0xb0
	ldr r0, _080C3308 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
_080C32C0:
	ldrh r1, [r5, #8]
	adds r0, r1, #0
	subs r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x2b
	bhi _080C3322
	adds r0, r5, #0
	adds r0, #0xb0
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0x2c
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	adds r1, r5, #0
	adds r1, #0xb4
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r3, #0x30
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	ldrb r2, [r5, #3]
	subs r0, r0, r2
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r0, r3
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0x80
	ble _080C330C
	adds r0, r2, #0
	adds r0, #0xfd
	b _080C330E
	.align 2, 0
_080C3308: .4byte 0x03002BE0
_080C330C:
	adds r0, r2, #3
_080C330E:
	strb r0, [r5, #3]
	adds r0, r1, #0
	subs r0, #0x18
	cmp r0, #0xd0
	bhi _080C332A
	ldrh r0, [r5, #6]
	cmp r0, #0xf
	bls _080C3334
	subs r0, #1
	b _080C3332
_080C3322:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _080C3334
_080C332A:
	ldrh r0, [r5, #6]
	cmp r0, #0x18
	bhi _080C3334
	adds r0, #1
_080C3332:
	strh r0, [r5, #6]
_080C3334:
	ldrh r3, [r5, #6]
	ldr r2, _080C3354 @ =0x085B0A08
	ldrb r0, [r5, #3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	adds r3, r2, #0
	cmp r0, #0
	blt _080C3358
	asrs r0, r0, #0xc
	b _080C335E
	.align 2, 0
_080C3354: .4byte 0x085B0A08
_080C3358:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C335E:
	adds r2, r5, #0
	adds r2, #0xa8
	strh r0, [r2]
	ldrh r1, [r5, #6]
	ldrb r0, [r5, #3]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	adds r7, r2, #0
	cmp r0, #0
	blt _080C337C
	asrs r0, r0, #0xc
	b _080C3382
_080C337C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C3382:
	adds r2, r5, #0
	adds r2, #0xac
	strh r0, [r2]
	ldrb r1, [r5, #0x16]
	ldrb r0, [r5, #4]
	subs r0, r1, r0
	movs r3, #0x80
	lsls r3, r3, #1
	adds r4, r0, r3
	movs r0, #0xff
	ands r4, r0
	adds r6, r2, #0
	cmp r1, #0x5f
	bls _080C33A8
	cmp r4, #0x5f
	bgt _080C33A8
	adds r0, #0x6a
	bl PlaySound_082406e0
_080C33A8:
	strb r4, [r5, #0x16]
	ldrh r0, [r7]
	ldrh r1, [r5, #0x2c]
	adds r0, r0, r1
	strh r0, [r5, #0x2c]
	ldrh r0, [r6]
	ldrh r2, [r5, #0x30]
	adds r0, r0, r2
	strh r0, [r5, #0x30]
	adds r4, r5, #0
	adds r4, #0x58
	adds r1, r5, #0
	adds r1, #0x2c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
_080C33D0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c33d8
FUN_080c33d8: @ 0x080C33D8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r7, r0, #0
	adds r6, r7, #0
	adds r6, #0x58
	ldr r4, _080C3488 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r4
	movs r3, #0x30
	orrs r0, r3
	ldr r5, _080C348C @ =0x0000FFFF
	ands r0, r5
	movs r2, #0x80
	lsls r2, r2, #0xf
	orrs r0, r2
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r4
	orrs r0, r3
	str r0, [sp, #0x10]
	adds r0, r7, #0
	adds r0, #0xa8
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r2, r2, #0x12
	lsrs r2, r2, #0x10
	ldr r0, [sp, #0x14]
	ands r0, r4
	orrs r0, r2
	ands r0, r5
	str r0, [sp, #0x14]
	adds r0, r7, #0
	adds r0, #0xac
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r2, r2, #0x12
	lsrs r2, r2, #0x10
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r4
	orrs r0, r2
	str r0, [r3, #4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080C3490 @ =0x00002101
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_0823646c
	ldrh r1, [r7, #0xa]
	ldrh r2, [r7, #0xc]
	movs r0, #0xc0
	lsls r0, r0, #0xb
	str r0, [sp]
	ldrh r0, [r7, #0xe]
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_082364f8
	ldrb r0, [r7, #3]
	adds r1, r7, #0
	adds r1, #0x9a
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #0
	adds r2, r7, #0
	bl FUN_0823651c
	adds r1, r7, #0
	adds r1, #0x2c
	adds r0, r6, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r6, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3488: .4byte 0xFFFF0000
_080C348C: .4byte 0x0000FFFF
_080C3490: .4byte 0x00002101

	thumb_func_start FUN_080c3494
FUN_080c3494: @ 0x080C3494
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x58
	ldr r5, _080C351C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r5
	movs r3, #0x80
	orrs r0, r3
	ldr r2, _080C3520 @ =0x0000FFFF
	ands r0, r2
	movs r2, #0x80
	lsls r2, r2, #0xf
	orrs r0, r2
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r5
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r5
	str r0, [r3, #4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080C3524 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_0823646c
	ldrh r1, [r4, #0xa]
	ldrh r2, [r4, #0xc]
	movs r0, #0xc0
	lsls r0, r0, #0xb
	str r0, [sp]
	ldrh r0, [r4, #0xe]
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_082364f8
	adds r0, r6, #0
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823651c
	adds r4, #0x2c
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r6, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C351C: .4byte 0xFFFF0000
_080C3520: .4byte 0x0000FFFF
_080C3524: .4byte 0x00002001

	thumb_func_start FUN_080c3528
FUN_080c3528: @ 0x080C3528
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x24
	adds r6, r0, #0
	movs r0, #0x58
	adds r0, r0, r6
	mov r8, r0
	ldr r5, _080C35DC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r5
	ldr r2, _080C35E0 @ =0x000005AA
	orrs r0, r2
	ldr r4, _080C35E4 @ =0x0000FFFF
	ands r0, r4
	movs r2, #0x80
	lsls r2, r2, #0x11
	orrs r0, r2
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r5
	ldr r2, _080C35E8 @ =0x000003A5
	orrs r0, r2
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r5
	movs r3, #0x80
	orrs r0, r3
	ands r0, r4
	movs r2, #0x80
	lsls r2, r2, #0xf
	orrs r0, r2
	str r0, [sp, #0x14]
	add r4, sp, #0x14
	ldr r0, [r4, #4]
	ands r0, r5
	orrs r0, r3
	str r0, [r4, #4]
	movs r0, #0
	str r0, [sp, #0x1c]
	add r3, sp, #0x1c
	ldr r0, [r3, #4]
	ands r0, r5
	str r0, [r3, #4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080C35EC @ =0x00002101
	movs r0, #0x10
	str r0, [sp]
	str r4, [sp, #4]
	str r3, [sp, #8]
	mov r0, r8
	movs r3, #0
	bl FUN_0823646c
	ldrh r1, [r6, #0xa]
	ldrh r2, [r6, #0xc]
	movs r0, #0xc0
	lsls r0, r0, #0xb
	str r0, [sp]
	ldrh r0, [r6, #0xe]
	str r0, [sp, #4]
	mov r0, r8
	movs r3, #0
	bl FUN_082364f8
	movs r0, #0x40
	adds r1, r6, #0
	adds r1, #0x9a
	strb r0, [r1]
	mov r0, r8
	movs r1, #0
	adds r2, r6, #0
	bl FUN_0823651c
	mov r0, r8
	add r1, sp, #0xc
	movs r2, #0
	bl FUN_082364c4
	mov r0, r8
	bl FUN_08236400
	add sp, #0x24
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C35DC: .4byte 0xFFFF0000
_080C35E0: .4byte 0x000005AA
_080C35E4: .4byte 0x0000FFFF
_080C35E8: .4byte 0x000003A5
_080C35EC: .4byte 0x00002101

	thumb_func_start FUN_080c35f0
FUN_080c35f0: @ 0x080C35F0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080C3650 @ =0x00001844
	adds r4, r5, r0
	strb r1, [r4, #2]
	movs r3, #1
	strb r3, [r4, #1]
	strb r2, [r4, #3]
	ldr r1, _080C3654 @ =0x00001854
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _080C3658 @ =0x00000514
	strh r0, [r2, #0x1c]
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r2, #0x1e]
	movs r0, #0xc0
	lsls r0, r0, #2
	strh r0, [r2, #0x20]
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _080C36B4
	strh r0, [r2, #0x10]
	ldrb r0, [r4, #3]
	adds r0, #0x60
	mvns r0, r0
	strb r0, [r2, #6]
	ldr r2, _080C365C @ =0x085B0A08
	ldrb r0, [r4, #3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080C3660
	asrs r1, r0, #0xc
	b _080C3666
	.align 2, 0
_080C3650: .4byte 0x00001844
_080C3654: .4byte 0x00001854
_080C3658: .4byte 0x00000514
_080C365C: .4byte 0x085B0A08
_080C3660:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C3666:
	adds r0, r4, #0
	adds r0, #0xa8
	strh r1, [r0]
	ldrb r0, [r4, #3]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080C3684
	asrs r2, r0, #0xc
	b _080C368A
_080C3684:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C368A:
	adds r0, r4, #0
	adds r0, #0xac
	strh r2, [r0]
	adds r0, r5, #0
	adds r0, #0x48
	ldrh r1, [r0]
	adds r0, r4, #0
	bl FUN_080c33d8
	ldr r0, _080C36AC @ =0x0000018F
	bl PlaySound_082406e0
	ldr r1, _080C36B0 @ =FUN_080c3224
	adds r0, r4, #0
	bl FUN_080c3218
	b _080C372C
	.align 2, 0
_080C36AC: .4byte 0x0000018F
_080C36B0: .4byte FUN_080c3224
_080C36B4:
	strh r3, [r2, #0x10]
	movs r0, #0x60
	strb r0, [r2, #6]
	movs r3, #0x19
	strh r3, [r4, #6]
	movs r0, #0xa
	strb r0, [r4, #4]
	ldr r2, _080C36E0 @ =0x085B0A08
	ldrb r0, [r4, #3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080C36E4
	asrs r1, r0, #0xc
	b _080C36EA
	.align 2, 0
_080C36E0: .4byte 0x085B0A08
_080C36E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C36EA:
	adds r0, r4, #0
	adds r0, #0xa8
	strh r1, [r0]
	ldrh r1, [r4, #6]
	ldrb r0, [r4, #3]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080C3706
	asrs r1, r0, #0xc
	b _080C370C
_080C3706:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C370C:
	adds r0, r4, #0
	adds r0, #0xac
	strh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x48
	ldrh r1, [r0]
	adds r0, r4, #0
	bl FUN_080c3494
	ldr r0, _080C3734 @ =0x00000169
	bl PlaySound_082406e0
	ldr r1, _080C3738 @ =FUN_080c3278
	adds r0, r4, #0
	bl FUN_080c3218
_080C372C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C3734: .4byte 0x00000169
_080C3738: .4byte FUN_080c3278

	thumb_func_start FUN_080c373c
FUN_080c373c: @ 0x080C373C
	push {lr}
	adds r2, r0, #0
	ldr r1, _080C375C @ =0x00001845
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C3758
	ldr r3, _080C3760 @ =0x000018FC
	adds r1, r2, r3
	subs r3, #0xb8
	adds r0, r2, r3
	ldr r1, [r1]
	bl _call_via_r1
_080C3758:
	pop {r0}
	bx r0
	.align 2, 0
_080C375C: .4byte 0x00001845
_080C3760: .4byte 0x000018FC

	thumb_func_start FUN_080c3764
FUN_080c3764: @ 0x080C3764
	push {lr}
	adds r1, r0, #0
	ldr r2, _080C3780 @ =0x00001844
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C377A
	adds r2, #0x10
	adds r0, r1, r2
	bl FUN_0822a4e0
_080C377A:
	pop {r0}
	bx r0
	.align 2, 0
_080C3780: .4byte 0x00001844

	thumb_func_start FUN_080c3784
FUN_080c3784: @ 0x080C3784
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	mov sb, r1
	mov sl, r2
	adds r7, r3, #0
	ldr r0, _080C37EC @ =0x00001844
	adds r5, r4, r0
	movs r0, #0
	movs r1, #1
	mov r8, r1
	mov r1, r8
	strb r1, [r5]
	strb r0, [r5, #1]
	strh r0, [r5, #8]
	ldr r0, _080C37F0 @ =0x00001854
	adds r6, r4, r0
	movs r1, #0xc4
	lsls r1, r1, #5
	adds r4, r4, r1
	ldr r1, _080C37F4 @ =0x00005291
	adds r0, r4, #0
	bl Video_GetActorSprite
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #3
	bl FUN_0822a470
	mov r0, r8
	strh r0, [r6, #0x10]
	movs r1, #0xab
	lsls r1, r1, #1
	adds r0, r4, #0
	bl FUN_0822b20c
	mov r1, sb
	strh r1, [r5, #0xa]
	mov r0, sl
	strh r0, [r5, #0xc]
	strh r7, [r5, #0xe]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C37EC: .4byte 0x00001844
_080C37F0: .4byte 0x00001854
_080C37F4: .4byte 0x00005291

	thumb_func_start FUN_080c37f8
FUN_080c37f8: @ 0x080C37F8
	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	ldr r0, _080C3818 @ =0x03003584
	ldr r0, [r0]
	ldr r4, _080C381C @ =0x00002BA0
	adds r3, r0, r4
	cmp r1, #0x1f
	ble _080C3828
	ldr r0, _080C3820 @ =0x0000259C
	adds r1, r2, r0
	ldr r2, _080C3824 @ =0x04000008
	adds r0, r3, #0
	bl CpuSet
	b _080C3862
	.align 2, 0
_080C3818: .4byte 0x03003584
_080C381C: .4byte 0x00002BA0
_080C3820: .4byte 0x0000259C
_080C3824: .4byte 0x04000008
_080C3828:
	adds r5, r1, #0
	movs r7, #0x1f
	ldr r0, _080C3868 @ =0x0000259C
	adds r4, r2, r0
	movs r6, #0xf
_080C3832:
	ldrh r0, [r3]
	movs r2, #0x1f
	ands r2, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x15
	ands r1, r7
	lsrs r0, r0, #0x1a
	ands r0, r7
	muls r2, r5, r2
	asrs r2, r2, #5
	muls r1, r5, r1
	asrs r1, r1, #5
	muls r0, r5, r0
	asrs r0, r0, #5
	lsls r0, r0, #0xa
	lsls r1, r1, #5
	orrs r0, r1
	orrs r0, r2
	strh r0, [r4]
	adds r3, #2
	adds r4, #2
	subs r6, #1
	cmp r6, #0
	bge _080C3832
_080C3862:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3868: .4byte 0x0000259C

	thumb_func_start FUN_080c386c
FUN_080c386c: @ 0x080C386C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r2, r1, #0
	ldr r3, _080C3898 @ =0x00001904
	adds r1, r0, r3
	ldr r3, _080C389C @ =0x000025BE
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #6
	ldr r1, [r1]
	adds r5, r1, r0
	cmp r2, #0x1f
	ble _080C38A8
	ldr r1, _080C38A0 @ =0x03004250
	ldr r2, _080C38A4 @ =0x04000010
	adds r0, r5, #0
	bl CpuSet
	b _080C38FC
	.align 2, 0
_080C3898: .4byte 0x00001904
_080C389C: .4byte 0x000025BE
_080C38A0: .4byte 0x03004250
_080C38A4: .4byte 0x04000010
_080C38A8:
	adds r4, r2, #0
	movs r0, #0
	movs r1, #0x1f
	mov r8, r1
	ldr r3, _080C3908 @ =0x03004250
	mov sb, r3
_080C38B4:
	movs r6, #0
	lsls r7, r0, #5
	adds r0, #1
	mov ip, r0
_080C38BC:
	ldrh r0, [r5]
	movs r2, #0x1f
	ands r2, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x15
	mov r3, r8
	ands r1, r3
	lsrs r0, r0, #0x1a
	ands r0, r3
	adds r3, r2, #0
	muls r3, r4, r3
	asrs r3, r3, #5
	adds r2, r1, #0
	muls r2, r4, r2
	asrs r2, r2, #5
	muls r0, r4, r0
	asrs r0, r0, #5
	lsls r1, r6, #1
	adds r1, r1, r7
	add r1, sb
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r3
	strh r0, [r1]
	adds r5, #2
	adds r6, #1
	cmp r6, #0xf
	ble _080C38BC
	mov r0, ip
	cmp r0, #1
	ble _080C38B4
_080C38FC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3908: .4byte 0x03004250

	thumb_func_start FUN_080c390c
FUN_080c390c: @ 0x080C390C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r0, #0
	adds r3, r1, #0
	ldr r1, _080C3958 @ =0x03003584
	ldr r2, _080C395C @ =0x085AD0D8
	ldr r5, _080C3960 @ =0x000025BE
	adds r0, r4, r5
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r0, r1, r0
	str r0, [sp]
	adds r5, #1
	adds r0, r4, r5
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r7, r1, r0
	cmp r3, #0xf
	ble _080C396C
	ldr r0, _080C3964 @ =0x0000259C
	adds r1, r4, r0
	ldr r2, _080C3968 @ =0x04000008
	adds r0, r7, #0
	bl CpuSet
	b _080C39F2
	.align 2, 0
_080C3958: .4byte 0x03003584
_080C395C: .4byte 0x085AD0D8
_080C3960: .4byte 0x000025BE
_080C3964: .4byte 0x0000259C
_080C3968: .4byte 0x04000008
_080C396C:
	movs r0, #0x10
	subs r0, r0, r3
	mov sb, r0
	mov r8, r3
	movs r1, #0x1f
	mov sl, r1
	ldr r2, _080C3A04 @ =0x0000259C
	adds r2, r2, r4
	mov ip, r2
	movs r3, #0xf
	str r3, [sp, #4]
_080C3982:
	ldr r5, [sp]
	ldrh r3, [r5]
	movs r2, #0x1f
	ands r2, r3
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x15
	mov r0, sl
	ands r6, r0
	lsrs r3, r3, #0x1a
	ands r3, r0
	ldrh r1, [r7]
	movs r0, #0x1f
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x15
	mov r5, sl
	ands r4, r5
	lsrs r1, r1, #0x1a
	ands r1, r5
	mov r5, sb
	muls r5, r2, r5
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	adds r5, r5, r0
	asrs r5, r5, #4
	mov r2, sb
	muls r2, r6, r2
	mov r0, r8
	muls r0, r4, r0
	adds r2, r2, r0
	asrs r2, r2, #4
	mov r0, sb
	muls r0, r3, r0
	mov r3, r8
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	asrs r0, r0, #4
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r5
	mov r5, ip
	strh r0, [r5]
	ldr r0, [sp]
	adds r0, #2
	str r0, [sp]
	adds r7, #2
	movs r1, #2
	add ip, r1
	ldr r2, [sp, #4]
	subs r2, #1
	str r2, [sp, #4]
	cmp r2, #0
	bge _080C3982
_080C39F2:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3A04: .4byte 0x0000259C

	thumb_func_start FUN_080c3a08
FUN_080c3a08: @ 0x080C3A08
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r3, r1, #0
	ldr r1, _080C3A44 @ =0x00001904
	adds r2, r0, r1
	ldr r4, _080C3A48 @ =0x000025BE
	adds r1, r0, r4
	ldrb r1, [r1]
	lsls r1, r1, #6
	ldr r2, [r2]
	adds r1, r1, r2
	mov sb, r1
	ldr r5, _080C3A4C @ =0x000025BF
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r2, r2, r0
	mov r8, r2
	cmp r3, #0xf
	ble _080C3A58
	ldr r1, _080C3A50 @ =0x03004250
	ldr r2, _080C3A54 @ =0x04000010
	mov r0, r8
	bl CpuSet
	b _080C3AE0
	.align 2, 0
_080C3A44: .4byte 0x00001904
_080C3A48: .4byte 0x000025BE
_080C3A4C: .4byte 0x000025BF
_080C3A50: .4byte 0x03004250
_080C3A54: .4byte 0x04000010
_080C3A58:
	movs r0, #0x10
	subs r0, r0, r3
	mov ip, r0
	adds r7, r3, #0
	movs r0, #0
_080C3A62:
	movs r1, #0
	mov sl, r1
	lsls r3, r0, #5
	str r3, [sp, #4]
	adds r0, #1
	str r0, [sp]
_080C3A6E:
	mov r4, sb
	ldrh r3, [r4]
	movs r2, #0x1f
	ands r2, r3
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x15
	movs r5, #0x1f
	ands r6, r5
	lsrs r3, r3, #0x1a
	ands r3, r5
	mov r0, r8
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x15
	ands r4, r5
	lsrs r1, r1, #0x1a
	ands r1, r5
	mov r5, ip
	muls r5, r2, r5
	muls r0, r7, r0
	adds r5, r5, r0
	asrs r5, r5, #4
	mov r2, ip
	muls r2, r6, r2
	adds r0, r4, #0
	muls r0, r7, r0
	adds r2, r2, r0
	asrs r2, r2, #4
	mov r0, ip
	muls r0, r3, r0
	muls r1, r7, r1
	adds r0, r0, r1
	asrs r0, r0, #4
	mov r3, sl
	lsls r1, r3, #1
	ldr r4, [sp, #4]
	adds r1, r1, r4
	ldr r3, _080C3AF0 @ =0x03004250
	adds r1, r1, r3
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r5
	strh r0, [r1]
	movs r4, #2
	add sb, r4
	add r8, r4
	movs r5, #1
	add sl, r5
	mov r0, sl
	cmp r0, #0xf
	ble _080C3A6E
	ldr r0, [sp]
	cmp r0, #1
	ble _080C3A62
_080C3AE0:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3AF0: .4byte 0x03004250

	thumb_func_start FUN_080c3af4
FUN_080c3af4: @ 0x080C3AF4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080C3B38 @ =0x000025C5
	adds r3, r5, r0
	ldrb r2, [r3]
	cmp r2, #0
	beq _080C3B44
	ldr r1, _080C3B3C @ =0x000025C6
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C3B22
	ldr r0, _080C3B40 @ =0x000025C7
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _080C3B22
	movs r0, #0
	strb r0, [r3]
_080C3B22:
	ldr r1, _080C3B40 @ =0x000025C7
	adds r4, r5, r1
	ldrb r1, [r4]
	adds r0, r5, #0
	bl FUN_080c37f8
	ldrb r1, [r4]
	adds r0, r5, #0
	bl FUN_080c386c
	b _080C3B74
	.align 2, 0
_080C3B38: .4byte 0x000025C5
_080C3B3C: .4byte 0x000025C6
_080C3B40: .4byte 0x000025C7
_080C3B44:
	movs r0, #0x97
	lsls r0, r0, #6
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C3B74
	ldr r0, _080C3B7C @ =0x000025C1
	adds r4, r5, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bls _080C3B64
	strb r2, [r1]
_080C3B64:
	ldrb r1, [r4]
	adds r0, r5, #0
	bl FUN_080c390c
	ldrb r1, [r4]
	adds r0, r5, #0
	bl FUN_080c3a08
_080C3B74:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C3B7C: .4byte 0x000025C1

	thumb_func_start FUN_080c3b80
FUN_080c3b80: @ 0x080C3B80
	push {lr}
	adds r2, r0, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C3BA0
	ldr r1, _080C3B98 @ =0x000025BE
	adds r0, r2, r1
	movs r1, #2
	strb r1, [r0]
	ldr r3, _080C3B9C @ =0x000025BF
	b _080C3BBC
	.align 2, 0
_080C3B98: .4byte 0x000025BE
_080C3B9C: .4byte 0x000025BF
_080C3BA0:
	ldr r0, _080C3BE0 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080C3BE4 @ =0x00000942
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0
	cmp r0, #0
	bne _080C3BB4
	movs r1, #1
_080C3BB4:
	ldr r3, _080C3BE8 @ =0x000025BE
	adds r0, r2, r3
	strb r1, [r0]
	adds r3, #1
_080C3BBC:
	adds r0, r2, r3
	strb r1, [r0]
	subs r3, #2
	adds r0, r2, r3
	strb r1, [r0]
	ldr r0, _080C3BEC @ =0x000025C1
	adds r1, r2, r0
	movs r0, #0x10
	strb r0, [r1]
	adds r3, #3
	adds r1, r2, r3
	movs r0, #1
	strb r0, [r1]
	adds r0, r2, #0
	bl FUN_080c3af4
	pop {r0}
	bx r0
	.align 2, 0
_080C3BE0: .4byte 0x030046A0
_080C3BE4: .4byte 0x00000942
_080C3BE8: .4byte 0x000025BE
_080C3BEC: .4byte 0x000025C1

	thumb_func_start FUN_080c3bf0
FUN_080c3bf0: @ 0x080C3BF0
	push {lr}
	adds r2, r0, #0
	ldr r0, _080C3C1C @ =0x000025C2
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C3C48
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C3C2C
	ldr r3, _080C3C20 @ =0x00000366
	adds r1, r2, r3
	ldr r0, _080C3C24 @ =0x00000155
	strh r0, [r1]
	movs r0, #0xdd
	lsls r0, r0, #2
	adds r1, r2, r0
	ldr r3, _080C3C28 @ =0x0000259C
	adds r0, r2, r3
	b _080C3C46
	.align 2, 0
_080C3C1C: .4byte 0x000025C2
_080C3C20: .4byte 0x00000366
_080C3C24: .4byte 0x00000155
_080C3C28: .4byte 0x0000259C
_080C3C2C:
	ldr r0, _080C3C70 @ =0x00000366
	adds r1, r2, r0
	movs r0, #0x99
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0xdd
	lsls r3, r3, #2
	adds r1, r2, r3
	ldr r0, _080C3C74 @ =0x03003584
	ldr r0, [r0]
	movs r3, #0x99
	lsls r3, r3, #6
	adds r0, r0, r3
_080C3C46:
	str r0, [r1]
_080C3C48:
	ldr r0, _080C3C78 @ =0x000025C3
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C3CA6
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C3C8C
	ldr r3, _080C3C7C @ =0x0000065E
	adds r1, r2, r3
	ldr r0, _080C3C80 @ =0x00000155
	strh r0, [r1]
	ldr r0, _080C3C84 @ =0x0000066C
	adds r1, r2, r0
	ldr r3, _080C3C88 @ =0x0000259C
	adds r0, r2, r3
	b _080C3CA4
	.align 2, 0
_080C3C70: .4byte 0x00000366
_080C3C74: .4byte 0x03003584
_080C3C78: .4byte 0x000025C3
_080C3C7C: .4byte 0x0000065E
_080C3C80: .4byte 0x00000155
_080C3C84: .4byte 0x0000066C
_080C3C88: .4byte 0x0000259C
_080C3C8C:
	ldr r0, _080C3CD0 @ =0x0000065E
	adds r1, r2, r0
	movs r0, #0x99
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r3, _080C3CD4 @ =0x0000066C
	adds r1, r2, r3
	ldr r0, _080C3CD8 @ =0x03003584
	ldr r0, [r0]
	movs r3, #0x99
	lsls r3, r3, #6
	adds r0, r0, r3
_080C3CA4:
	str r0, [r1]
_080C3CA6:
	ldr r0, _080C3CDC @ =0x000025C4
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C3D08
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C3CEC
	ldr r3, _080C3CE0 @ =0x00000572
	adds r1, r2, r3
	ldr r0, _080C3CE4 @ =0x00000155
	strh r0, [r1]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r1, r2, r0
	ldr r3, _080C3CE8 @ =0x0000259C
	adds r0, r2, r3
	b _080C3D06
	.align 2, 0
_080C3CD0: .4byte 0x0000065E
_080C3CD4: .4byte 0x0000066C
_080C3CD8: .4byte 0x03003584
_080C3CDC: .4byte 0x000025C4
_080C3CE0: .4byte 0x00000572
_080C3CE4: .4byte 0x00000155
_080C3CE8: .4byte 0x0000259C
_080C3CEC:
	ldr r0, _080C3D0C @ =0x00000572
	adds r1, r2, r0
	movs r0, #0x99
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r1, r2, r3
	ldr r0, _080C3D10 @ =0x03003584
	ldr r0, [r0]
	movs r2, #0x99
	lsls r2, r2, #6
	adds r0, r0, r2
_080C3D06:
	str r0, [r1]
_080C3D08:
	pop {r0}
	bx r0
	.align 2, 0
_080C3D0C: .4byte 0x00000572
_080C3D10: .4byte 0x03003584

	thumb_func_start FUN_080c3d14
FUN_080c3d14: @ 0x080C3D14
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	adds r4, r0, #0
	ldr r7, _080C3DA0 @ =0x030046B8
	ldr r0, _080C3DA4 @ =0xFFFF0000
	mov r8, r0
	add r5, sp, #0x10
	movs r6, #4
_080C3D28:
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080C3DA8 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080C3DAC @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	asrs r2, r2, #3
	movs r0, #0xff
	ands r2, r0
	movs r0, #0x9b
	lsls r0, r0, #2
	adds r3, r4, r0
	ldr r1, _080C3DB0 @ =0x0000026E
	adds r0, r4, r1
	ldrh r1, [r0]
	subs r2, #0x80
	adds r1, r2, r1
	lsls r1, r1, #0x10
	ldrh r0, [r3]
	orrs r0, r1
	str r0, [sp, #0x10]
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r1, [r0]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	mov r2, r8
	ands r0, r2
	orrs r0, r1
	str r0, [r5, #4]
	movs r0, #0
	str r0, [sp]
	movs r0, #0x18
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl FUN_080ddcc8
	subs r6, #1
	cmp r6, #0
	bge _080C3D28
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3DA0: .4byte 0x030046B8
_080C3DA4: .4byte 0xFFFF0000
_080C3DA8: .4byte 0x000003FF
_080C3DAC: .4byte 0x0203B400
_080C3DB0: .4byte 0x0000026E

	thumb_func_start FUN_080c3db4
FUN_080c3db4: @ 0x080C3DB4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	mov r8, r3
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	add r0, sp, #0x1c
	ldrh r0, [r0]
	ldrh r1, [r2]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080C3F18 @ =0xFFFF0000
	ldr r3, [sp, #0x1c]
	ands r3, r4
	orrs r3, r0
	asrs r1, r3, #0x10
	ldrh r0, [r2, #2]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _080C3F1C @ =0x0000FFFF
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r0, sp, #0x1c
	ldrh r0, [r0, #4]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x20]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x20]
	ldr r1, _080C3F20 @ =0x030046B8
	mov sl, r1
	ldr r1, [r1]
	adds r1, #1
	ldr r4, _080C3F24 @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	ldr r2, _080C3F28 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	adds r0, #2
	adds r1, #1
	ands r1, r4
	mov r2, sl
	str r1, [r2]
	lsls r1, r1, #1
	ldr r2, _080C3F28 @ =0x0203B400
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #3
	ands r1, r2
	adds r1, #8
	movs r7, #8
	str r7, [sp]
	str r1, [sp, #4]
	movs r6, #4
	str r6, [sp, #8]
	movs r1, #0xa
	str r1, [sp, #0xc]
	str r7, [sp, #0x10]
	movs r2, #5
	str r2, [sp, #0x14]
	str r1, [sp, #0x18]
	adds r1, #0xff
	add r2, sp, #0x1c
	mov r3, r8
	bl FUN_080149dc
	mov r1, sl
	ldr r0, [r1]
	adds r0, #1
	ands r0, r4
	lsls r1, r0, #1
	ldr r2, _080C3F28 @ =0x0203B400
	adds r1, r1, r2
	ldrh r3, [r1]
	movs r1, #7
	mov sb, r1
	ands r3, r1
	add r3, r8
	movs r5, #0xff
	ands r3, r5
	adds r0, #1
	ands r0, r4
	mov r2, sl
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080C3F28 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r2, sb
	ands r0, r2
	adds r0, #6
	str r7, [sp]
	str r0, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0xe
	str r0, [sp, #0xc]
	str r6, [sp, #0x10]
	movs r6, #6
	str r6, [sp, #0x14]
	movs r0, #0xa
	str r0, [sp, #0x18]
	movs r0, #3
	ldr r1, _080C3F2C @ =0x00000109
	add r2, sp, #0x1c
	bl FUN_080149dc
	mov r2, sl
	ldr r1, [r2]
	adds r1, #1
	ands r1, r4
	lsls r0, r1, #1
	ldr r2, _080C3F28 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #0xf
	ands r0, r2
	add r8, r0
	mov r0, r8
	ands r0, r5
	mov r8, r0
	adds r1, #1
	ands r1, r4
	lsls r0, r1, #1
	ldr r2, _080C3F28 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	adds r0, #1
	adds r1, #1
	ands r1, r4
	mov r2, sl
	str r1, [r2]
	lsls r1, r1, #1
	ldr r2, _080C3F28 @ =0x0203B400
	adds r1, r1, r2
	ldrh r1, [r1]
	mov r2, sb
	ands r1, r2
	adds r1, #4
	str r7, [sp]
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r6, [sp, #0xc]
	movs r1, #3
	str r1, [sp, #0x10]
	movs r2, #5
	str r2, [sp, #0x14]
	movs r1, #0xa
	str r1, [sp, #0x18]
	adds r1, #0xff
	add r2, sp, #0x1c
	mov r3, r8
	bl FUN_080149dc
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3F18: .4byte 0xFFFF0000
_080C3F1C: .4byte 0x0000FFFF
_080C3F20: .4byte 0x030046B8
_080C3F24: .4byte 0x000003FF
_080C3F28: .4byte 0x0203B400
_080C3F2C: .4byte 0x00000109

	thumb_func_start FUN_080c3f30
FUN_080c3f30: @ 0x080C3F30
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r0, _080C3F94 @ =0x000023D4
	adds r6, r4, r0
	movs r1, #0
	movs r0, #1
	strb r0, [r6]
	strb r1, [r6, #3]
	ldr r0, _080C3F98 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #4]
	movs r0, #4
	rsbs r0, r0, #0
	mov r8, r0
	ldr r0, _080C3F9C @ =0x000023EC
	adds r5, r4, r0
	subs r0, #0x10
	adds r4, r4, r0
	movs r7, #7
_080C3F5C:
	movs r0, #0
	strb r0, [r4]
	ldr r1, [r6, #4]
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r5, #0
	mov r1, r8
	mov r2, r8
	bl FUN_0822dad4
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0822dadc
	movs r0, #1
	strb r0, [r4, #0x1f]
	adds r5, #0x38
	adds r4, #0x38
	subs r7, #1
	cmp r7, #0
	bge _080C3F5C
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3F94: .4byte 0x000023D4
_080C3F98: .4byte 0x00001C1E
_080C3F9C: .4byte 0x000023EC

	thumb_func_start FUN_080c3fa0
FUN_080c3fa0: @ 0x080C3FA0
	push {r4, r5, lr}
	adds r1, r0, #0
	ldr r2, _080C3FC8 @ =0x000023D4
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C3FC2
	ldr r0, _080C3FCC @ =0x000023EC
	adds r4, r1, r0
	movs r5, #7
_080C3FB4:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x38
	subs r5, #1
	cmp r5, #0
	bge _080C3FB4
_080C3FC2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C3FC8: .4byte 0x000023D4
_080C3FCC: .4byte 0x000023EC

	thumb_func_start FUN_080c3fd0
FUN_080c3fd0: @ 0x080C3FD0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	ldr r7, _080C404C @ =0x000023D4
	add r7, r8
	adds r1, #2
	ldrb r0, [r7, #2]
	adds r1, r1, r0
	strb r1, [r7, #2]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x1d
	bhi _080C3FEE
	b _080C40FC
_080C3FEE:
	ldrb r1, [r7, #1]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, #8
	adds r6, r7, r0
	movs r0, #0
	strb r0, [r6, #1]
	movs r0, #1
	strb r0, [r6]
	ldr r4, _080C4050 @ =0x0203B400
	ldr r1, _080C4054 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _080C4058 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r3, [r1]
	adds r0, #1
	ands r0, r2
	ldr r2, _080C4054 @ =0x030046B8
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	movs r4, #0xa0
	lsls r4, r4, #1
	adds r2, r0, r4
	ldr r1, _080C405C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r2, r0
	ldr r4, _080C4054 @ =0x030046B8
	cmp r0, #0
	blt _080C4060
	asrs r0, r0, #0xc
	b _080C4066
	.align 2, 0
_080C404C: .4byte 0x000023D4
_080C4050: .4byte 0x0203B400
_080C4054: .4byte 0x030046B8
_080C4058: .4byte 0x000003FF
_080C405C: .4byte 0x085B0A08
_080C4060:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C4066:
	strh r0, [r6, #8]
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080C407A
	asrs r0, r0, #0xc
	b _080C4080
_080C407A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C4080:
	strh r0, [r6, #0xc]
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _080C4108 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _080C410C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #0x1c
	strh r0, [r6, #6]
	adds r4, r6, #0
	adds r4, #0x10
	ldr r0, [r6, #0x10]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x10]
	ldr r1, [r7, #4]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_0822dafc
	movs r1, #0xba
	lsls r1, r1, #2
	add r1, r8
	ldrh r0, [r6, #8]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldr r0, _080C4110 @ =0x000002EA
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r4, #0x1a]
	movs r0, #0xbb
	lsls r0, r0, #2
	add r0, r8
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r2, #0
	ldrh r6, [r6, #0xc]
	adds r1, r1, r6
	ldrh r0, [r0]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	ldrb r0, [r7, #1]
	adds r0, #1
	strb r0, [r7, #1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _080C40F2
	movs r0, #0
	strb r0, [r7, #1]
_080C40F2:
	ldrb r0, [r7, #2]
	subs r0, #0x1e
	strb r0, [r7, #2]
	movs r0, #1
	strb r0, [r7, #3]
_080C40FC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C4108: .4byte 0x000003FF
_080C410C: .4byte 0x0203B400
_080C4110: .4byte 0x000002EA

	thumb_func_start FUN_080c4114
FUN_080c4114: @ 0x080C4114
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r2, r0, #0
	ldr r0, _080C418C @ =0x000023D4
	adds r0, r0, r2
	mov sb, r0
	ldrb r0, [r0, #3]
	cmp r0, #0
	bne _080C412E
	b _080C4246
_080C412E:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r5, [r0]
	ldr r6, [r0, #4]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r6, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080C4190 @ =0xFFFF0000
	ands r0, r6
	adds r6, r0, #0
	orrs r6, r1
	movs r3, #0
	ldr r0, _080C4194 @ =0x000023DC
	adds r4, r2, r0
	ldr r1, _080C4198 @ =0x000023EC
	adds r1, r1, r2
	mov r8, r1
	movs r2, #7
	mov sl, r2
_080C415A:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080C4230
	mov r7, r8
	movs r1, #8
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bge _080C416C
	rsbs r0, r0, #0
_080C416C:
	cmp r0, #0x3f
	bgt _080C419C
	movs r2, #0xc
	ldrsh r0, [r4, r2]
	cmp r0, #0
	bge _080C417A
	rsbs r0, r0, #0
_080C417A:
	cmp r0, #0x3f
	bgt _080C419C
	ldr r0, [r4, #0x10]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x10]
	movs r0, #0
	strb r0, [r4]
	b _080C4230
	.align 2, 0
_080C418C: .4byte 0x000023D4
_080C4190: .4byte 0xFFFF0000
_080C4194: .4byte 0x000023DC
_080C4198: .4byte 0x000023EC
_080C419C:
	movs r3, #8
	ldrsh r0, [r4, r3]
	movs r2, #0xc
	ldrsh r1, [r4, r2]
	bl FUN_0823785c
	adds r2, r0, #0
	ldrh r1, [r4, #6]
	adds r0, #0x40
	movs r3, #0xff
	ands r0, r3
	lsls r0, r0, #1
	ldr r3, _080C41C8 @ =0x085B0A08
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080C41CC
	asrs r1, r0, #0xc
	b _080C41D2
	.align 2, 0
_080C41C8: .4byte 0x085B0A08
_080C41CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C41D2:
	ldrh r0, [r4, #8]
	subs r0, r0, r1
	strh r0, [r4, #8]
	ldrh r1, [r4, #6]
	movs r0, #0xff
	ands r2, r0
	lsls r0, r2, #1
	ldr r2, _080C41F4 @ =0x085B0A08
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080C41F8
	asrs r1, r0, #0xc
	b _080C41FE
	.align 2, 0
_080C41F4: .4byte 0x085B0A08
_080C41F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C41FE:
	ldrh r0, [r4, #0xc]
	subs r0, r0, r1
	strh r0, [r4, #0xc]
	adds r0, r5, #0
	ldrh r1, [r4, #8]
	adds r0, r0, r1
	strh r0, [r7, #0x18]
	adds r0, r6, #0
	ldrh r2, [r4, #0xc]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
	movs r3, #0xff
	ands r0, r3
	cmp r0, #4
	bne _080C422E
	mov r0, sb
	ldr r1, [r0, #4]
	adds r0, r7, #0
	movs r2, #3
	bl FUN_0822dafc
_080C422E:
	movs r3, #1
_080C4230:
	adds r4, #0x38
	movs r1, #0x38
	add r8, r1
	movs r2, #1
	rsbs r2, r2, #0
	add sl, r2
	mov r0, sl
	cmp r0, #0
	bge _080C415A
	mov r1, sb
	strb r3, [r1, #3]
_080C4246:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c4254
FUN_080c4254: @ 0x080C4254
	push {r4, r5, r6, lr}
	ldr r1, _080C4288 @ =0x000023D7
	adds r2, r0, r1
	movs r1, #0
	strb r1, [r2]
	movs r6, #1
	adds r2, r0, #0
	ldr r0, _080C428C @ =0x000023EC
	adds r1, r2, r0
	ldr r5, _080C4290 @ =0x000023DC
	movs r4, #0
	movs r3, #7
_080C426C:
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	adds r0, r2, r5
	strb r4, [r0]
	adds r2, #0x38
	adds r1, #0x38
	subs r3, #1
	cmp r3, #0
	bge _080C426C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C4288: .4byte 0x000023D7
_080C428C: .4byte 0x000023EC
_080C4290: .4byte 0x000023DC

	thumb_func_start FUN_080c4294
FUN_080c4294: @ 0x080C4294
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	adds r0, r7, #0
	adds r0, #0x44
	ldrh r0, [r0]
	cmp r0, #0
	beq _080C42A6
	b _080C4512
_080C42A6:
	adds r4, r2, #0
	movs r1, #0x80
	lsls r1, r1, #0xb
	adds r0, r4, #0
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080C42BA
	b _080C4512
_080C42BA:
	movs r0, #0xf
	ldr r1, [r5, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _080C42D8
	ldr r0, _080C42D4 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0x24
	ldrsh r1, [r7, r2]
	movs r3, #0x2c
	ldrsh r0, [r0, r3]
	b _080C42EE
	.align 2, 0
_080C42D4: .4byte 0x03002BE0
_080C42D8:
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _080C42E6
	movs r0, #0x24
	ldrsh r1, [r7, r0]
	b _080C42EA
_080C42E6:
	movs r3, #0x24
	ldrsh r1, [r7, r3]
_080C42EA:
	movs r2, #0x24
	ldrsh r0, [r5, r2]
_080C42EE:
	movs r2, #2
	cmp r1, r0
	ble _080C42F6
	movs r2, #1
_080C42F6:
	cmp r2, #1
	bne _080C43EC
	ldr r3, _080C43C0 @ =0x0000191A
	adds r6, r4, r3
	ldrh r0, [r6]
	cmp r0, #0x77
	bls _080C4306
	b _080C4512
_080C4306:
	ldr r1, _080C43C4 @ =0x000025C8
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080C43AA
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08236524
	ldr r2, _080C43C8 @ =0x00001910
	adds r1, r4, r2
	ldrh r0, [r7, #0x3e]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r7, #0x3e]
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r6]
	ldr r3, _080C43CC @ =0x0000191C
	adds r2, r4, r3
	ldrh r1, [r2]
	movs r0, #2
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _080C43D0 @ =0x000025C2
	adds r1, r4, r0
	movs r0, #6
	strb r0, [r1]
	ldr r1, _080C43D4 @ =0x000025D8
	adds r2, r4, r1
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r4, r3
	str r1, [r2]
	ldrh r0, [r5, #0xc]
	ldrh r1, [r1]
	subs r0, r0, r1
	ldr r3, _080C43D8 @ =0x000025DC
	adds r1, r4, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x64
	ble _080C4364
	movs r0, #0x64
	strh r0, [r1]
_080C4364:
	ldr r1, [r2]
	ldrh r0, [r5, #0xe]
	ldrh r1, [r1, #2]
	subs r0, r0, r1
	ldr r3, _080C43DC @ =0x000025DE
	adds r1, r4, r3
	strh r0, [r1]
	ldr r1, [r2]
	ldrh r0, [r5, #0x10]
	ldrh r1, [r1, #4]
	subs r0, r0, r1
	ldr r1, _080C43E0 @ =0x000025E0
	adds r2, r4, r1
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xaf
	lsls r1, r1, #1
	cmp r0, r1
	ble _080C438E
	strh r1, [r2]
_080C438E:
	ldr r2, _080C43E4 @ =0x000025E4
	adds r1, r4, r2
	movs r0, #0x10
	strh r0, [r1]
	ldr r3, _080C43E8 @ =0x000025CC
	adds r1, r4, r3
	ldrh r0, [r5, #0x3e]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x3e]
	ldr r1, [r5, #0x34]
	subs r2, #0x14
	adds r0, r4, r2
	str r1, [r0]
_080C43AA:
	adds r1, r7, #0
	adds r1, #0x44
	movs r0, #0x14
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _080C44B8
	b _080C44F8
	.align 2, 0
_080C43C0: .4byte 0x0000191A
_080C43C4: .4byte 0x000025C8
_080C43C8: .4byte 0x00001910
_080C43CC: .4byte 0x0000191C
_080C43D0: .4byte 0x000025C2
_080C43D4: .4byte 0x000025D8
_080C43D8: .4byte 0x000025DC
_080C43DC: .4byte 0x000025DE
_080C43E0: .4byte 0x000025E0
_080C43E4: .4byte 0x000025E4
_080C43E8: .4byte 0x000025CC
_080C43EC:
	cmp r2, #2
	beq _080C43F2
	b _080C4512
_080C43F2:
	ldr r0, _080C44C8 @ =0x00001918
	adds r6, r4, r0
	ldrh r0, [r6]
	cmp r0, #0x77
	bls _080C43FE
	b _080C4512
_080C43FE:
	ldr r1, _080C44CC @ =0x000025C8
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080C44A4
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08236524
	ldr r2, _080C44D0 @ =0x0000190E
	adds r1, r4, r2
	ldrh r0, [r7, #0x3e]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r7, #0x3e]
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r6]
	ldr r3, _080C44D4 @ =0x0000191C
	adds r2, r4, r3
	ldrh r1, [r2]
	movs r0, #1
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _080C44D8 @ =0x000025C2
	adds r1, r4, r0
	movs r0, #6
	strb r0, [r1]
	ldr r1, _080C44DC @ =0x000025D8
	adds r2, r4, r1
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r4, r3
	str r1, [r2]
	ldrh r0, [r5, #0xc]
	ldrh r1, [r1]
	subs r0, r0, r1
	ldr r1, _080C44E0 @ =0x000025DC
	adds r3, r4, r1
	strh r0, [r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x64
	rsbs r1, r1, #0
	cmp r0, r1
	bge _080C445E
	strh r1, [r3]
_080C445E:
	ldr r1, [r2]
	ldrh r0, [r5, #0xe]
	ldrh r1, [r1, #2]
	subs r0, r0, r1
	ldr r3, _080C44E4 @ =0x000025DE
	adds r1, r4, r3
	strh r0, [r1]
	ldr r1, [r2]
	ldrh r0, [r5, #0x10]
	ldrh r1, [r1, #4]
	subs r0, r0, r1
	ldr r1, _080C44E8 @ =0x000025E0
	adds r2, r4, r1
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xaf
	lsls r1, r1, #1
	cmp r0, r1
	ble _080C4488
	strh r1, [r2]
_080C4488:
	ldr r2, _080C44EC @ =0x000025E4
	adds r1, r4, r2
	movs r0, #0x10
	strh r0, [r1]
	ldr r3, _080C44F0 @ =0x000025CC
	adds r1, r4, r3
	ldrh r0, [r5, #0x3e]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x3e]
	ldr r1, [r5, #0x34]
	subs r2, #0x14
	adds r0, r4, r2
	str r1, [r0]
_080C44A4:
	adds r1, r7, #0
	adds r1, #0x44
	movs r0, #0x14
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080C44F8
_080C44B8:
	adds r0, r5, #0
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r3, _080C44F4 @ =0x000025D6
	adds r0, r4, r3
	strh r1, [r0]
	b _080C4506
	.align 2, 0
_080C44C8: .4byte 0x00001918
_080C44CC: .4byte 0x000025C8
_080C44D0: .4byte 0x0000190E
_080C44D4: .4byte 0x0000191C
_080C44D8: .4byte 0x000025C2
_080C44DC: .4byte 0x000025D8
_080C44E0: .4byte 0x000025DC
_080C44E4: .4byte 0x000025DE
_080C44E8: .4byte 0x000025E0
_080C44EC: .4byte 0x000025E4
_080C44F0: .4byte 0x000025CC
_080C44F4: .4byte 0x000025D6
_080C44F8:
	adds r0, r5, #0
	adds r0, #0x40
	ldrh r0, [r0]
	asrs r0, r0, #1
	ldr r2, _080C4518 @ =0x000025D6
	adds r1, r4, r2
	strh r0, [r1]
_080C4506:
	adds r0, r5, #0
	adds r0, #0x42
	ldrb r1, [r0]
	ldr r3, _080C451C @ =0x000025D5
	adds r0, r4, r3
	strb r1, [r0]
_080C4512:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C4518: .4byte 0x000025D6
_080C451C: .4byte 0x000025D5

	thumb_func_start FUN_080c4520
FUN_080c4520: @ 0x080C4520
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r5, r1, #0
	movs r0, #0xd4
	lsls r0, r0, #1
	adds r4, r6, r0
	ldr r2, _080C45AC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r1, #0x80
	orrs r0, r1
	ldr r1, _080C45B0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x96
	orrs r0, r1
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	adds r1, #0x6a
	orrs r0, r1
	str r0, [r3, #4]
	adds r0, r6, #0
	adds r0, #0x48
	ldrh r1, [r0]
	ldr r2, _080C45B4 @ =0x00005001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823646c
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #0
	bl FUN_08236514
	ldr r1, _080C45B8 @ =FUN_080c4294
	adds r0, r4, #0
	adds r2, r6, #0
	bl FUN_0823651c
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r6, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C45AC: .4byte 0xFFFF0000
_080C45B0: .4byte 0x0000FFFF
_080C45B4: .4byte 0x00005001
_080C45B8: .4byte FUN_080c4294

	thumb_func_start FUN_080c45bc
FUN_080c45bc: @ 0x080C45BC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	adds r7, r6, #0
	adds r7, #0x44
	ldrh r0, [r7]
	cmp r0, #0
	bne _080C466E
	movs r1, #0x80
	lsls r1, r1, #0xc
	adds r0, r4, #0
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080C466E
	ldr r1, _080C4674 @ =0x000025C8
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080C466A
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08236524
	ldr r2, _080C4678 @ =0x00001914
	adds r1, r4, r2
	ldrh r0, [r6, #0x3e]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r0, _080C467C @ =0x0000191C
	adds r1, r4, r0
	ldrh r0, [r1]
	movs r2, #8
	orrs r0, r2
	strh r0, [r1]
	ldr r1, _080C4680 @ =0x000025C4
	adds r0, r4, r1
	strb r2, [r0]
	ldr r3, _080C4684 @ =0x000025D8
	adds r2, r4, r3
	movs r0, #0xbe
	lsls r0, r0, #2
	adds r1, r4, r0
	str r1, [r2]
	ldrh r0, [r5, #0xc]
	ldrh r1, [r1]
	subs r0, r0, r1
	adds r3, #4
	adds r1, r4, r3
	strh r0, [r1]
	ldr r1, [r2]
	ldrh r0, [r5, #0xe]
	ldrh r1, [r1, #2]
	subs r0, r0, r1
	adds r3, #2
	adds r1, r4, r3
	strh r0, [r1]
	ldr r1, [r2]
	ldrh r0, [r5, #0x10]
	ldrh r1, [r1, #4]
	subs r0, r0, r1
	ldr r2, _080C4688 @ =0x000025E0
	adds r1, r4, r2
	strh r0, [r1]
	adds r3, #6
	adds r1, r4, r3
	movs r0, #0x10
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x42
	ldrb r1, [r0]
	subs r2, #0xb
	adds r0, r4, r2
	strb r1, [r0]
	subs r3, #0x18
	adds r1, r4, r3
	ldrh r0, [r5, #0x3e]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x3e]
	ldr r1, [r5, #0x34]
	subs r2, #5
	adds r0, r4, r2
	str r1, [r0]
_080C466A:
	movs r0, #0xf
	strh r0, [r7]
_080C466E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C4674: .4byte 0x000025C8
_080C4678: .4byte 0x00001914
_080C467C: .4byte 0x0000191C
_080C4680: .4byte 0x000025C4
_080C4684: .4byte 0x000025D8
_080C4688: .4byte 0x000025E0

	thumb_func_start FUN_080c468c
FUN_080c468c: @ 0x080C468C
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r5, r1, #0
	movs r0, #0xfc
	lsls r0, r0, #1
	adds r4, r6, r0
	ldr r2, _080C4714 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _080C4718 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	adds r0, r6, #0
	adds r0, #0x48
	ldrh r1, [r0]
	ldr r2, _080C471C @ =0x00005001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823646c
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #0
	bl FUN_08236514
	ldr r1, _080C4720 @ =FUN_080c45bc
	adds r0, r4, #0
	adds r2, r6, #0
	bl FUN_0823651c
	movs r0, #0xbe
	lsls r0, r0, #2
	adds r1, r6, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C4714: .4byte 0xFFFF0000
_080C4718: .4byte 0x0000FFFF
_080C471C: .4byte 0x00005001
_080C4720: .4byte FUN_080c45bc

	thumb_func_start FUN_080c4724
FUN_080c4724: @ 0x080C4724
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r7, r4, #0
	adds r7, #0x44
	ldrh r0, [r7]
	cmp r0, #0
	bne _080C4784
	adds r0, r6, #0
	bl FUN_08236524
	ldr r0, _080C478C @ =0x00001912
	adds r1, r5, r0
	ldrh r0, [r4, #0x3e]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, _080C4790 @ =0x0000191C
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0xf
	strh r0, [r7]
	ldr r2, _080C4794 @ =0x000025C3
	adds r1, r5, r2
	movs r0, #8
	strb r0, [r1]
	ldr r0, _080C4798 @ =0x000025F9
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080c3d14
	ldr r2, _080C479C @ =0x000025CC
	adds r1, r5, r2
	ldrh r0, [r6, #0x3e]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r6, #0x3e]
	ldr r1, [r6, #0x34]
	adds r2, #4
	adds r0, r5, r2
	str r1, [r0]
_080C4784:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C478C: .4byte 0x00001912
_080C4790: .4byte 0x0000191C
_080C4794: .4byte 0x000025C3
_080C4798: .4byte 0x000025F9
_080C479C: .4byte 0x000025CC

	thumb_func_start FUN_080c47a0
FUN_080c47a0: @ 0x080C47A0
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r5, r1, #0
	movs r0, #0x92
	lsls r0, r0, #2
	adds r4, r6, r0
	ldr r2, _080C4830 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r1, #0x40
	orrs r0, r1
	ldr r1, _080C4834 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x80
	orrs r0, r1
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	movs r1, #0x90
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r3, #4]
	adds r0, r6, #0
	adds r0, #0x48
	ldrh r1, [r0]
	ldr r2, _080C4838 @ =0x00005005
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823646c
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #0
	bl FUN_08236514
	ldr r1, _080C483C @ =FUN_080c4724
	adds r0, r4, #0
	adds r2, r6, #0
	bl FUN_0823651c
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r6, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C4830: .4byte 0xFFFF0000
_080C4834: .4byte 0x0000FFFF
_080C4838: .4byte 0x00005005
_080C483C: .4byte FUN_080c4724

	thumb_func_start FUN_080c4840
FUN_080c4840: @ 0x080C4840
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r7, r0, #0
	adds r6, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r0, #0xac
	lsls r0, r0, #1
	adds r4, r7, r0
	ldr r2, _080C48DC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _080C48E0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	ldr r0, _080C48E4 @ =0xFFE00000
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	movs r1, #0x80
	lsls r1, r1, #1
	orrs r0, r1
	str r0, [r3, #4]
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r0]
	ldr r2, _080C48E8 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823646c
	movs r0, #0
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r4, #0
	adds r1, r6, #0
	mov r2, r8
	movs r3, #0
	bl FUN_082364f8
	adds r0, r4, #0
	movs r1, #0
	adds r2, r7, #0
	bl FUN_0823651c
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r7, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C48DC: .4byte 0xFFFF0000
_080C48E0: .4byte 0x0000FFFF
_080C48E4: .4byte 0xFFE00000
_080C48E8: .4byte 0x00002001

	thumb_func_start FUN_080c48ec
FUN_080c48ec: @ 0x080C48EC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	mov r8, r1
	mov sb, r2
	adds r6, r3, #0
	movs r0, #0xa6
	lsls r0, r0, #2
	adds r4, r7, r0
	ldr r2, _080C4984 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _080C4988 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r5, #0
	str r5, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r0]
	ldr r2, _080C498C @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823646c
	str r5, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0
	bl FUN_082364f8
	adds r0, r4, #0
	movs r1, #0
	adds r2, r7, #0
	bl FUN_0823651c
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r7, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C4984: .4byte 0xFFFF0000
_080C4988: .4byte 0x0000FFFF
_080C498C: .4byte 0x00002001

	thumb_func_start FUN_080c4990
FUN_080c4990: @ 0x080C4990
	push {r4, lr}
	adds r3, r0, #0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r3, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r4, #0xbc
	lsls r4, r4, #2
	adds r0, r3, r4
	movs r4, #0
	ldrsh r2, [r0, r4]
	lsls r0, r1, #3
	subs r0, r0, r1
	adds r0, r0, r2
	cmp r0, #0
	blt _080C49B6
	asrs r1, r0, #3
	b _080C49BC
_080C49B6:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r1, r0, #0
_080C49BC:
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r3, r2
	strh r1, [r0]
	ldr r4, _080C49E4 @ =0x000002EA
	adds r0, r3, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r4, #8
	adds r0, r3, r4
	movs r4, #0
	ldrsh r2, [r0, r4]
	lsls r0, r1, #3
	subs r0, r0, r1
	adds r0, r0, r2
	cmp r0, #0
	blt _080C49E8
	asrs r1, r0, #3
	b _080C49EE
	.align 2, 0
_080C49E4: .4byte 0x000002EA
_080C49E8:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r1, r0, #0
_080C49EE:
	ldr r2, _080C4A14 @ =0x000002EA
	adds r0, r3, r2
	strh r1, [r0]
	movs r4, #0xbb
	lsls r4, r4, #2
	adds r0, r3, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r4, #8
	adds r0, r3, r4
	movs r4, #0
	ldrsh r2, [r0, r4]
	lsls r0, r1, #3
	subs r0, r0, r1
	adds r0, r0, r2
	cmp r0, #0
	blt _080C4A18
	asrs r1, r0, #3
	b _080C4A1E
	.align 2, 0
_080C4A14: .4byte 0x000002EA
_080C4A18:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r1, r0, #0
_080C4A1E:
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r3, r2
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c4a2c
FUN_080c4a2c: @ 0x080C4A2C
	movs r1, #0xba
	lsls r1, r1, #2
	adds r2, r0, r1
	adds r1, #8
	adds r0, r0, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	bx lr

	thumb_func_start FUN_080c4a40
FUN_080c4a40: @ 0x080C4A40
	movs r3, #0x98
	muls r1, r3, r1
	adds r0, r0, r1
	ldr r1, _080C4A50 @ =0x00000397
	adds r0, r0, r1
	strb r2, [r0]
	bx lr
	.align 2, 0
_080C4A50: .4byte 0x00000397

	thumb_func_start FUN_080c4a54
FUN_080c4a54: @ 0x080C4A54
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	movs r4, #0
_080C4A5C:
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_080c4a40
	adds r4, #1
	cmp r4, #4
	ble _080C4A5C
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c4a74
FUN_080c4a74: @ 0x080C4A74
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r5, r0, #0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xbe
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r6, r1, r0
	subs r3, #0xe
	adds r0, r5, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r3, #0x10
	adds r0, r5, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	mov r8, r1
	subs r3, #0xe
	adds r0, r5, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r3, #0x10
	adds r0, r5, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r4, r1, r0
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_0823785c
	adds r7, r0, #0
	cmp r6, #0
	bne _080C4AD0
	cmp r4, #0
	beq _080C4B1C
_080C4AD0:
	adds r1, r6, #0
	cmp r6, #0
	bge _080C4AD8
	rsbs r1, r6, #0
_080C4AD8:
	adds r0, r4, #0
	cmp r4, #0
	bge _080C4AE0
	rsbs r0, r4, #0
_080C4AE0:
	cmp r1, r0
	ble _080C4B00
	lsls r0, r6, #0xc
	ldr r3, _080C4AFC @ =0x085B0A08
	adds r1, r7, #0
	adds r1, #0x40
	movs r2, #0xff
	ands r1, r2
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	b _080C4B10
	.align 2, 0
_080C4AFC: .4byte 0x085B0A08
_080C4B00:
	lsls r0, r4, #0xc
	ldr r2, _080C4B18 @ =0x085B0A08
	movs r1, #0xff
	ands r1, r7
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
_080C4B10:
	bl Div
	adds r2, r0, #0
	b _080C4B20
	.align 2, 0
_080C4B18: .4byte 0x085B0A08
_080C4B1C:
	movs r2, #0xc0
	lsls r2, r2, #2
_080C4B20:
	movs r0, #0xa0
	lsls r0, r0, #2
	cmp r8, r0
	ble _080C4B3A
	ldr r0, _080C4B48 @ =0xFFFFFD80
	add r0, r8
	lsls r0, r0, #1
	adds r2, r2, r0
	movs r0, #0xc0
	lsls r0, r0, #2
	cmp r2, r0
	ble _080C4B3A
	adds r2, r0, #0
_080C4B3A:
	ldr r0, _080C4B4C @ =0x000002FF
	cmp r2, r0
	ble _080C4B50
	movs r3, #0
	str r3, [sp, #0x1c]
	b _080C4B5E
	.align 2, 0
_080C4B48: .4byte 0xFFFFFD80
_080C4B4C: .4byte 0x000002FF
_080C4B50:
	movs r1, #0xc0
	lsls r1, r1, #2
	subs r0, r1, r2
	lsls r0, r0, #8
	bl Div
	str r0, [sp, #0x1c]
_080C4B5E:
	ldr r1, _080C4B90 @ =0x000008F4
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	beq _080C4B9C
	ldr r3, _080C4B94 @ =0x000008F5
	adds r2, r5, r3
	ldrb r0, [r2]
	cmp r0, #7
	bhi _080C4BC0
	ldr r0, _080C4B98 @ =0x000008F6
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _080C4BC0
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	movs r0, #0
	strb r0, [r1]
	b _080C4BC0
	.align 2, 0
_080C4B90: .4byte 0x000008F4
_080C4B94: .4byte 0x000008F5
_080C4B98: .4byte 0x000008F6
_080C4B9C:
	ldr r1, _080C4BEC @ =0x000008F5
	adds r2, r5, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _080C4BC0
	ldr r0, _080C4BF0 @ =0x000008F6
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _080C4BC0
	ldrb r0, [r2]
	subs r0, #1
	strb r0, [r2]
	strb r3, [r1]
_080C4BC0:
	movs r7, #0
	adds r1, r5, #0
	adds r1, #0x98
	str r1, [sp, #0x20]
	add r2, sp, #0x14
	mov r8, r2
	ldr r3, _080C4BF4 @ =0xFFFF0000
	mov sl, r3
	add r0, sp, #0xc
	mov sb, r0
_080C4BD4:
	movs r0, #0x98
	muls r0, r7, r0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r0, r1
	adds r6, r5, r0
	cmp r7, #0
	bne _080C4BF8
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	b _080C4C02
	.align 2, 0
_080C4BEC: .4byte 0x000008F5
_080C4BF0: .4byte 0x000008F6
_080C4BF4: .4byte 0xFFFF0000
_080C4BF8:
	cmp r7, #4
	bne _080C4C0C
	movs r3, #0xbe
	lsls r3, r3, #2
	adds r0, r5, r3
_080C4C02:
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	b _080C4CF0
_080C4C0C:
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r2, r0, #0
	muls r2, r7, r2
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #4
	subs r0, r3, r7
	muls r0, r1, r0
	adds r0, r2, r0
	cmp r0, #0
	blt _080C4C34
	asrs r0, r0, #2
	b _080C4C3A
_080C4C34:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_080C4C3A:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0xc]
	mov r2, sl
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r3, _080C4C6C @ =0x000002FA
	adds r0, r5, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r2, r0, #0
	muls r2, r7, r2
	subs r3, #0x10
	adds r0, r5, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #4
	subs r0, r3, r7
	muls r0, r1, r0
	adds r0, r2, r0
	cmp r0, #0
	blt _080C4C70
	asrs r0, r0, #2
	b _080C4C76
	.align 2, 0
_080C4C6C: .4byte 0x000002FA
_080C4C70:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_080C4C76:
	lsls r2, r0, #0x10
	ldr r1, _080C4CAC @ =0x0000FFFF
	ldr r0, [sp, #0xc]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0xc]
	movs r1, #0xbf
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r2, r0, #0
	muls r2, r7, r2
	movs r3, #0xbb
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #4
	subs r0, r3, r7
	muls r0, r1, r0
	adds r0, r2, r0
	cmp r0, #0
	blt _080C4CB0
	asrs r0, r0, #2
	b _080C4CB6
	.align 2, 0
_080C4CAC: .4byte 0x0000FFFF
_080C4CB0:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_080C4CB6:
	adds r3, r0, #0
	ldr r2, _080C4CD4 @ =0x085B0A08
	lsls r0, r7, #5
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x1c]
	muls r0, r2, r0
	cmp r0, #0
	blt _080C4CD8
	asrs r0, r0, #0xc
	b _080C4CDE
	.align 2, 0
_080C4CD4: .4byte 0x085B0A08
_080C4CD8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C4CDE:
	subs r1, r3, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r3, sb
	ldr r0, [r3, #4]
	mov r2, sl
	ands r0, r2
	orrs r0, r1
	str r0, [r3, #4]
_080C4CF0:
	adds r4, r6, #0
	adds r4, #0x97
	ldrb r0, [r4]
	cmp r0, #0
	beq _080C4D42
	ldr r2, _080C4D70 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C4D74 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080C4D78 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0x14
	bl Mod
	subs r0, #0xa
	mov r1, sb
	ldrh r2, [r1]
	adds r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r1, [sp, #0xc]
	mov r3, sl
	ands r1, r3
	orrs r1, r2
	str r1, [sp, #0xc]
	mov r2, sb
	ldrh r1, [r2, #4]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
_080C4D42:
	movs r3, #0x8f
	lsls r3, r3, #4
	adds r0, r5, r3
	ldrh r0, [r0]
	lsls r0, r0, #2
	lsls r1, r7, #6
	adds r0, r0, r1
	movs r2, #0xff
	adds r3, #5
	adds r1, r5, r3
	ldrb r3, [r1]
	ldr r1, _080C4D7C @ =0x085B0A08
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080C4D80
	asrs r0, r0, #0xc
	b _080C4D86
	.align 2, 0
_080C4D70: .4byte 0x030046B8
_080C4D74: .4byte 0x000003FF
_080C4D78: .4byte 0x0203B400
_080C4D7C: .4byte 0x085B0A08
_080C4D80:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080C4D86:
	mov r2, sb
	ldrh r1, [r2]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0xc]
	mov r3, sl
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r0, #0x8c
	ldr r2, [r0]
	add r4, sp, #0xc
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	str r0, [r2]
	str r1, [r2, #4]
	cmp r7, #1
	ble _080C4E30
	subs r1, r7, #1
	movs r0, #0x98
	muls r1, r0, r1
	movs r2, #0xe3
	lsls r2, r2, #2
	adds r0, r5, r2
	adds r0, r0, r1
	ldr r2, [r0]
	movs r3, #2
	ldrsh r1, [r2, r3]
	movs r3, #2
	ldrsh r0, [r4, r3]
	subs r3, r1, r0
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r4, r2]
	subs r0, r1, r0
	cmp r3, #0
	bne _080C4DDA
	movs r0, #0x40
	b _080C4DE2
_080C4DDA:
	lsls r0, r0, #6
	adds r1, r3, #0
	bl Div
_080C4DE2:
	cmp r0, #0x17
	ble _080C4E0C
	adds r1, r6, #0
	adds r1, #0x95
	ldrb r2, [r1]
	cmp r2, #1
	bne _080C4E30
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	ldrb r1, [r1]
	str r2, [sp]
	str r0, [sp, #4]
	movs r3, #4
	str r3, [sp, #8]
	adds r0, r6, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	b _080C4E30
_080C4E0C:
	adds r1, r6, #0
	adds r1, #0x95
	ldrb r2, [r1]
	cmp r2, #0
	bne _080C4E30
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	ldrb r1, [r1]
	str r0, [sp]
	str r2, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08055b5c
_080C4E30:
	adds r0, r6, #0
	adds r0, #0x94
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C4E40
	adds r0, r6, #0
	bl FUN_08055c04
_080C4E40:
	adds r7, #1
	cmp r7, #4
	bgt _080C4E48
	b _080C4BD4
_080C4E48:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r2, [sp, #0x20]
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080C4E70
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r1, #2
	bl FUN_08055f5c
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #2
	bl FUN_08055f5c
	b _080C4E88
_080C4E70:
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r1, #1
	bl FUN_08055f5c
	movs r3, #0xe6
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r1, #1
	bl FUN_08055f5c
_080C4E88:
	movs r7, #0
	movs r6, #0
_080C4E8C:
	movs r0, #0x98
	muls r0, r7, r0
	movs r1, #0xe5
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r4, r5, r0
	ldr r2, _080C4EC4 @ =0x000004BC
	adds r0, r5, r2
	ldr r0, [r0]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	cmp r7, #2
	bne _080C4EC8
	mov r3, r8
	ldrh r0, [r3]
	adds r0, #8
	add r1, sp, #0x14
	strh r0, [r1]
	ldrh r0, [r3, #2]
	adds r0, #0x10
	strh r0, [r3, #2]
	ldrh r0, [r3, #4]
	adds r0, #8
	strh r0, [r3, #4]
	b _080C4EE0
	.align 2, 0
_080C4EC4: .4byte 0x000004BC
_080C4EC8:
	mov r1, r8
	ldrh r0, [r1]
	subs r0, #8
	add r1, sp, #0x14
	strh r0, [r1]
	mov r2, r8
	ldrh r0, [r2, #2]
	subs r0, #0x10
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	subs r0, #8
	strh r0, [r2, #4]
_080C4EE0:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r2, [r0]
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x18]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r3, _080C4F20 @ =0x000004C5
	adds r0, r5, r3
	ldrb r2, [r0]
	cmp r2, #1
	bne _080C4F24
	adds r1, r4, #0
	adds r1, #0x95
	ldrb r0, [r1]
	cmp r0, #1
	beq _080C4F4E
	strb r2, [r1]
	adds r0, r4, #0
	adds r0, #0x96
	ldrb r1, [r0]
	adds r1, #1
	str r2, [sp]
	str r6, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	b _080C4F4E
	.align 2, 0
_080C4F20: .4byte 0x000004C5
_080C4F24:
	adds r2, r4, #0
	adds r2, #0x95
	ldrb r0, [r2]
	cmp r0, #0
	beq _080C4F4E
	strb r6, [r2]
	adds r0, r4, #0
	adds r0, #0x96
	ldrb r1, [r0]
	ldrb r0, [r2]
	adds r1, r1, r0
	movs r0, #1
	str r0, [sp]
	str r6, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C4F4E:
	ldr r1, _080C4FB4 @ =0x000008F4
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C4F5E
	adds r0, r4, #0
	bl FUN_08055c04
_080C4F5E:
	adds r7, #1
	cmp r7, #2
	ble _080C4E8C
	ldr r2, [sp, #0x20]
	ldr r0, [r2]
	cmp r0, #0
	bge _080C4FC0
	movs r3, #0xd2
	lsls r3, r3, #3
	adds r4, r5, r3
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08055f1c
	ldr r0, _080C4FB8 @ =0x0000071C
	adds r2, r5, r0
	ldr r3, [r2]
	ldr r1, _080C4FBC @ =0x00000554
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r1, [r2]
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	ldr r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r3, #0
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldr r1, [r2]
	ldrh r0, [r1, #4]
	adds r0, #0x80
	strh r0, [r1, #4]
	adds r0, r4, #0
	bl FUN_08055c04
	b _080C4FCC
	.align 2, 0
_080C4FB4: .4byte 0x000008F4
_080C4FB8: .4byte 0x0000071C
_080C4FBC: .4byte 0x00000554
_080C4FC0:
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #1
	bl FUN_08055ef8
_080C4FCC:
	movs r1, #0x80
	lsls r1, r1, #0xe
	ldr r2, [sp, #0x20]
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080C5024
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r4, r5, r3
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08055f1c
	ldr r0, _080C5020 @ =0x00000684
	adds r2, r5, r0
	ldr r3, [r2]
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r1, [r2]
	ldrh r0, [r1]
	adds r0, #0x10
	strh r0, [r1]
	ldr r1, [r2]
	ldrh r0, [r1, #2]
	adds r0, #0x20
	strh r0, [r1, #2]
	ldr r1, [r2]
	ldrh r0, [r1, #4]
	adds r0, #0x10
	strh r0, [r1, #4]
	adds r0, r4, #0
	bl FUN_08055c04
	b _080C5030
	.align 2, 0
_080C5020: .4byte 0x00000684
_080C5024:
	movs r2, #0xbf
	lsls r2, r2, #3
	adds r0, r5, r2
	movs r1, #1
	bl FUN_08055ef8
_080C5030:
	movs r3, #0x8f
	lsls r3, r3, #4
	adds r1, r5, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bls _080C5048
	movs r0, #0
	strh r0, [r1]
_080C5048:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

