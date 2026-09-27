	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0809df6c
FUN_0809df6c: @ 0x0809DF6C
	ldr r1, _0809DF74 @ =0x03000140
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0809DF74: .4byte 0x03000140

	thumb_func_start FUN_0809df78
FUN_0809df78: @ 0x0809DF78
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, _0809DF88 @ =0x03000140
	ldr r5, [r0]
	cmp r5, #0
	bne _0809DF90
	b _0809DFE4
	.align 2, 0
_0809DF88: .4byte 0x03000140
_0809DF8C:
	movs r0, #1
	b _0809DFE6
_0809DF90:
	movs r4, #0
	adds r0, r5, #0
	adds r0, #0x26
	ldrb r0, [r0]
	cmp r4, r0
	bge _0809DFE4
	adds r7, r0, #0
_0809DF9E:
	movs r0, #0xa8
	muls r0, r4, r0
	adds r1, r5, r0
	adds r0, r1, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809DFDE
	movs r0, #0
	ldrsh r3, [r6, r0]
	adds r0, r1, #0
	adds r0, #0xcc
	ldrh r0, [r0]
	cmp r3, r0
	blt _0809DFDE
	movs r0, #4
	ldrsh r2, [r6, r0]
	adds r0, r1, #0
	adds r0, #0xce
	ldrh r0, [r0]
	cmp r2, r0
	blt _0809DFDE
	adds r0, r1, #0
	adds r0, #0xd0
	ldrh r0, [r0]
	cmp r3, r0
	bgt _0809DFDE
	adds r0, r1, #0
	adds r0, #0xd2
	ldrh r0, [r0]
	cmp r2, r0
	ble _0809DF8C
_0809DFDE:
	adds r4, #1
	cmp r4, r7
	blt _0809DF9E
_0809DFE4:
	movs r0, #0
_0809DFE6:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809dfec
FUN_0809dfec: @ 0x0809DFEC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0809E004 @ =0x03000140
	ldr r1, [r0]
	cmp r1, #0
	beq _0809E02C
	adds r3, r1, #0
	adds r3, #0x26
	ldrb r0, [r3]
	cmp r0, #0
	bne _0809E00C
	b _0809E02C
	.align 2, 0
_0809E004: .4byte 0x03000140
_0809E008:
	movs r0, #1
	b _0809E02E
_0809E00C:
	movs r2, #0
	ldrb r0, [r3]
	cmp r2, r0
	bge _0809E02C
	adds r3, r0, #0
	adds r1, #0xc6
_0809E018:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0809E024
	ldrh r0, [r1, #4]
	cmp r0, r4
	beq _0809E008
_0809E024:
	adds r1, #0xa8
	adds r2, #1
	cmp r2, r3
	blt _0809E018
_0809E02C:
	movs r0, #0
_0809E02E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809e034
FUN_0809e034: @ 0x0809E034
	push {lr}
	ldr r1, _0809E054 @ =0x030046A0
	ldr r1, [r1]
	ldr r2, _0809E058 @ =0x00000942
	adds r1, r1, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r0, r1, r0
	movs r1, #0xa
	bl Div
	cmp r0, #0
	bgt _0809E050
	movs r0, #1
_0809E050:
	pop {r1}
	bx r1
	.align 2, 0
_0809E054: .4byte 0x030046A0
_0809E058: .4byte 0x00000942

	thumb_func_start FUN_0809e05c
FUN_0809e05c: @ 0x0809E05C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, _0809E06C @ =0x03000140
	ldr r5, [r0]
	cmp r5, #0
	bne _0809E074
	b _0809E0C8
	.align 2, 0
_0809E06C: .4byte 0x03000140
_0809E070:
	adds r0, r4, #0
	b _0809E0CC
_0809E074:
	movs r4, #0
	adds r0, r5, #0
	adds r0, #0x26
	ldrb r0, [r0]
	cmp r4, r0
	bge _0809E0C8
	adds r7, r0, #0
_0809E082:
	movs r0, #0xa8
	muls r0, r4, r0
	adds r1, r5, r0
	adds r0, r1, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809E0C2
	movs r0, #0
	ldrsh r3, [r6, r0]
	adds r0, r1, #0
	adds r0, #0xcc
	ldrh r0, [r0]
	cmp r3, r0
	blt _0809E0C2
	movs r0, #4
	ldrsh r2, [r6, r0]
	adds r0, r1, #0
	adds r0, #0xce
	ldrh r0, [r0]
	cmp r2, r0
	blt _0809E0C2
	adds r0, r1, #0
	adds r0, #0xd0
	ldrh r0, [r0]
	cmp r3, r0
	bgt _0809E0C2
	adds r0, r1, #0
	adds r0, #0xd2
	ldrh r0, [r0]
	cmp r2, r0
	ble _0809E070
_0809E0C2:
	adds r4, #1
	cmp r4, r7
	blt _0809E082
_0809E0C8:
	movs r0, #1
	rsbs r0, r0, #0
_0809E0CC:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0809e0d4
FUN_0809e0d4: @ 0x0809E0D4
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	ldr r0, _0809E0FC @ =0x030046A0
	ldr r2, [r0]
	ldr r1, _0809E100 @ =0x00000942
	adds r0, r2, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	beq _0809E124
	movs r1, #2
	ldr r5, _0809E104 @ =0x00000934
	adds r0, r2, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0809E108
	movs r0, #1
	b _0809E10A
	.align 2, 0
_0809E0FC: .4byte 0x030046A0
_0809E100: .4byte 0x00000942
_0809E104: .4byte 0x00000934
_0809E108:
	movs r0, #0
_0809E10A:
	cmp r0, #0
	bne _0809E12C
	adds r0, r3, #0
	bl FUN_0809e05c
	cmp r0, #0
	bge _0809E12C
	ldr r0, _0809E128 @ =0x03000140
	ldr r0, [r0]
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809E12C
_0809E124:
	movs r0, #0
	b _0809E132
	.align 2, 0
_0809E128: .4byte 0x03000140
_0809E12C:
	adds r0, r4, #0
	bl FUN_0809e034
_0809E132:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809e138
FUN_0809e138: @ 0x0809E138
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _0809E160 @ =0x030046A0
	ldr r2, [r0]
	ldr r1, _0809E164 @ =0x00000942
	adds r0, r2, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	beq _0809E186
	movs r1, #2
	ldr r4, _0809E168 @ =0x00000934
	adds r0, r2, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0809E16C
	movs r0, #1
	b _0809E16E
	.align 2, 0
_0809E160: .4byte 0x030046A0
_0809E164: .4byte 0x00000942
_0809E168: .4byte 0x00000934
_0809E16C:
	movs r0, #0
_0809E16E:
	cmp r0, #0
	bne _0809E190
	ldr r0, _0809E18C @ =0x03000140
	ldr r0, [r0]
	cmp r0, #0
	beq _0809E186
	adds r0, r3, #0
	adds r0, #0x2c
	bl FUN_0809e05c
	cmp r0, #0
	bge _0809E190
_0809E186:
	movs r0, #0
	b _0809E192
	.align 2, 0
_0809E18C: .4byte 0x03000140
_0809E190:
	movs r0, #1
_0809E192:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809e198
FUN_0809e198: @ 0x0809E198
	push {r4, r5, r6, lr}
	mov ip, r0
	adds r6, r2, #0
	cmp r3, #0
	beq _0809E1B8
	ldr r0, _0809E1B0 @ =0x085AD004
	lsls r1, r1, #1
	adds r0, r1, r0
	ldrh r5, [r0]
	ldr r0, _0809E1B4 @ =0x085AD00C
	b _0809E1C2
	.align 2, 0
_0809E1B0: .4byte 0x085AD004
_0809E1B4: .4byte 0x085AD00C
_0809E1B8:
	ldr r0, _0809E1F0 @ =0x085AD00C
	lsls r1, r1, #1
	adds r0, r1, r0
	ldrh r5, [r0]
	ldr r0, _0809E1F4 @ =0x085AD004
_0809E1C2:
	adds r1, r1, r0
	ldrh r4, [r1]
	ldrh r2, [r6]
	subs r1, r2, r5
	mov r0, ip
	adds r0, #0xa0
	strh r1, [r0]
	ldrh r1, [r6, #4]
	subs r0, r1, r4
	mov r3, ip
	adds r3, #0xa2
	strh r0, [r3]
	adds r2, r5, r2
	mov r0, ip
	adds r0, #0xa4
	strh r2, [r0]
	adds r1, r4, r1
	adds r0, #2
	strh r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809E1F0: .4byte 0x085AD00C
_0809E1F4: .4byte 0x085AD004

	thumb_func_start FUN_0809e1f8
FUN_0809e1f8: @ 0x0809E1F8
	push {r4, lr}
	ldr r0, _0809E21C @ =0x03000140
	ldr r4, [r0]
	cmp r4, #0
	beq _0809E226
	movs r0, #0x74
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _0809E220
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x27
	strb r0, [r1]
	b _0809E226
	.align 2, 0
_0809E21C: .4byte 0x03000140
_0809E220:
	adds r0, r4, #0
	adds r0, #0x27
	strb r1, [r0]
_0809E226:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809e22c
FUN_0809e22c: @ 0x0809E22C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	mov sl, r1
	str r2, [sp]
	mov sb, r3
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7]
	str r1, [r7, #4]
	rsbs r4, r3, #0
	orrs r4, r3
	asrs r4, r4, #0x1f
	movs r0, #4
	ands r4, r0
	mov r1, sl
	lsls r0, r1, #2
	movs r2, #0x9c
	adds r2, r2, r7
	mov r8, r2
	strb r0, [r2]
	adds r5, r7, #0
	adds r5, #0x60
	movs r1, #0xd9
	lsls r1, r1, #6
	adds r0, r5, #0
	bl Video_GetAuxSprite
	adds r6, r7, #0
	adds r6, #8
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl AuxSprite_Add
	mov r1, r8
	ldrb r0, [r1]
	strh r0, [r6, #0x10]
	adds r0, r5, #0
	ldr r1, [sp, #0x24]
	bl Video_SetAuxSpritePltt
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r7, #0x24]
	str r1, [r7, #0x28]
	movs r0, #3
	strb r0, [r7, #0xf]
	adds r1, r7, #0
	adds r1, #0x9d
	movs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	mov r1, sl
	ldr r2, [sp]
	mov r3, sb
	bl FUN_0809e198
	adds r0, r7, #0
	bl GetMapAreaAt
	adds r1, r7, #0
	adds r1, #0x9e
	strh r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809e2c4
FUN_0809e2c4: @ 0x0809E2C4
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r0, _0809E2FC @ =0x03000140
	ldr r6, [r0]
	cmp r6, #0
	beq _0809E392
	adds r0, r6, #0
	adds r0, #0x26
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0xf
	bhi _0809E392
	movs r0, #0x6e
	bl VM_SeekToKeyword
	adds r2, r0, #0
	cmp r2, #0
	beq _0809E300
	bl VM_GetValue
	ldrb r2, [r5]
	movs r1, #0xa8
	muls r1, r2, r1
	adds r1, r6, r1
	adds r1, #0xc4
	strh r0, [r1]
	b _0809E30C
	.align 2, 0
_0809E2FC: .4byte 0x03000140
_0809E300:
	ldrb r1, [r5]
	movs r0, #0xa8
	muls r0, r1, r0
	adds r0, r6, r0
	adds r0, #0xc4
	strh r2, [r0]
_0809E30C:
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0809E392
	bl VM_GetValue
	ldrb r1, [r5]
	movs r4, #0xa8
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xcc
	strh r0, [r1]
	bl VM_GetValue
	ldrb r1, [r5]
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xce
	strh r0, [r1]
	bl VM_GetValue
	ldrb r1, [r5]
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xd0
	strh r0, [r1]
	bl VM_GetValue
	ldrb r1, [r5]
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xd2
	strh r0, [r1]
	ldrb r0, [r5]
	muls r0, r4, r0
	adds r0, r6, r0
	adds r0, #0xcc
	ldr r2, _0809E39C @ =0xFFFF0000
	ldrh r0, [r0]
	str r0, [sp]
	ldrb r0, [r5]
	muls r0, r4, r0
	adds r0, r6, r0
	adds r0, #0xce
	ldrh r1, [r0]
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	bl GetMapAreaAt
	ldrb r1, [r5]
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xca
	strh r0, [r1]
	ldrb r0, [r5]
	muls r0, r4, r0
	adds r0, r6, r0
	adds r0, #0xc6
	movs r1, #1
	strb r1, [r0]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
_0809E392:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809E39C: .4byte 0xFFFF0000

	thumb_func_start FUN_0809e3a0
FUN_0809e3a0: @ 0x0809E3A0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	ldr r0, _0809E3E0 @ =0x03000140
	ldr r6, [r0]
	cmp r6, #0
	bne _0809E3B2
	b _0809E53E
_0809E3B2:
	adds r0, r6, #0
	adds r0, #0x26
	ldrb r1, [r0]
	mov r8, r0
	cmp r1, #0xf
	bls _0809E3C0
	b _0809E53E
_0809E3C0:
	movs r0, #0x6e
	bl VM_SeekToKeyword
	adds r2, r0, #0
	cmp r2, #0
	beq _0809E3E4
	bl VM_GetValue
	mov r1, r8
	ldrb r2, [r1]
	movs r1, #0xa8
	muls r1, r2, r1
	adds r1, r6, r1
	adds r1, #0xc4
	strh r0, [r1]
	b _0809E3F2
	.align 2, 0
_0809E3E0: .4byte 0x03000140
_0809E3E4:
	mov r0, r8
	ldrb r1, [r0]
	movs r0, #0xa8
	muls r0, r1, r0
	adds r0, r6, r0
	adds r0, #0xc4
	strh r2, [r0]
_0809E3F2:
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0809E438
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0809E430 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0809E434 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	b _0809E442
	.align 2, 0
_0809E430: .4byte 0xFFFF0000
_0809E434: .4byte 0x0000FFFF
_0809E438:
	ldr r1, _0809E470 @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_0809E442:
	add r5, sp, #4
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0809E46A
	cmp r1, #0
	blt _0809E46A
	ldr r0, _0809E474 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0809E46A
	ldr r0, _0809E478 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0809E47C
_0809E46A:
	movs r4, #0
	b _0809E48A
	.align 2, 0
_0809E470: .4byte 0xFFFF0000
_0809E474: .4byte 0x030046A8
_0809E478: .4byte 0x030046AC
_0809E47C:
	ldr r0, _0809E49C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0809E48A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0809E4A0
	adds r0, #4
	b _0809E4AC
	.align 2, 0
_0809E49C: .4byte 0x030046A4
_0809E4A0:
	ldr r0, _0809E4C0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0809E4AC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0809E4C4
	cmp r2, #2
	beq _0809E4C8
	b _0809E4CC
	.align 2, 0
_0809E4C0: .4byte 0x030046A4
_0809E4C4:
	ldrb r0, [r5, #4]
	b _0809E4CA
_0809E4C8:
	ldrb r0, [r5]
_0809E4CA:
	subs r1, r1, r0
_0809E4CC:
	add r0, sp, #4
	strh r1, [r0, #2]
	movs r0, #0x74
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0809E4E2
	bl VM_GetValue
	adds r7, r0, #0
	b _0809E4E4
_0809E4E2:
	movs r7, #0
_0809E4E4:
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0809E4F6
	bl VM_GetValue
	adds r3, r0, #0
	b _0809E4F8
_0809E4F6:
	movs r3, #0
_0809E4F8:
	mov r4, r8
	ldrb r0, [r4]
	movs r5, #0xa8
	muls r0, r5, r0
	adds r0, #0x2c
	adds r0, r6, r0
	ldrh r1, [r6, #0x24]
	str r1, [sp]
	adds r1, r7, #0
	add r2, sp, #4
	bl FUN_0809e22c
	ldrb r0, [r4]
	muls r0, r5, r0
	adds r0, r6, r0
	adds r0, #0xc6
	movs r2, #1
	strb r2, [r0]
	adds r0, r6, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809E536
	ldrb r0, [r4]
	muls r0, r5, r0
	adds r1, r6, #0
	adds r1, #0x34
	adds r1, r1, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0809E536:
	mov r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0809E53E:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809e54c
FUN_0809e54c: @ 0x0809E54C
	push {r4, r5, r6, r7, lr}
	ldr r0, _0809E570 @ =0x03000140
	ldr r4, [r0]
	cmp r4, #0
	beq _0809E5BE
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0809E5BE
	bl VM_GetValue
	adds r7, r0, #0
	movs r3, #0
	adds r0, r4, #0
	adds r0, #0x26
	adds r6, r0, #0
	b _0809E5B8
	.align 2, 0
_0809E570: .4byte 0x03000140
_0809E574:
	movs r0, #0xa8
	adds r5, r3, #0
	muls r5, r0, r5
	adds r2, r4, r5
	adds r1, r2, #0
	adds r1, #0xc4
	ldrh r0, [r1]
	cmp r0, #0
	beq _0809E5B6
	cmp r0, r7
	bne _0809E5B6
	adds r1, #2
	movs r0, #1
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809E5BE
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809E5BE
	adds r0, r4, #0
	adds r0, #0x34
	adds r0, r0, r5
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	b _0809E5BE
_0809E5B6:
	adds r3, #1
_0809E5B8:
	ldrb r0, [r6]
	cmp r3, r0
	blt _0809E574
_0809E5BE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809e5c4
FUN_0809e5c4: @ 0x0809E5C4
	push {r4, r5, r6, r7, lr}
	ldr r0, _0809E5E8 @ =0x03000140
	ldr r6, [r0]
	cmp r6, #0
	beq _0809E62A
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0809E62A
	bl VM_GetValue
	adds r7, r0, #0
	movs r3, #0
	adds r0, r6, #0
	adds r0, #0x26
	adds r5, r0, #0
	b _0809E624
	.align 2, 0
_0809E5E8: .4byte 0x03000140
_0809E5EC:
	movs r0, #0xa8
	adds r4, r3, #0
	muls r4, r0, r4
	adds r2, r6, r4
	adds r1, r2, #0
	adds r1, #0xc4
	ldrh r0, [r1]
	cmp r0, #0
	beq _0809E622
	cmp r0, r7
	bne _0809E622
	adds r1, #2
	movs r0, #0
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809E62A
	adds r0, r6, #0
	adds r0, #0x34
	adds r0, r0, r4
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _0809E62A
_0809E622:
	adds r3, #1
_0809E624:
	ldrb r0, [r5]
	cmp r3, r0
	blt _0809E5EC
_0809E62A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809e630
FUN_0809e630: @ 0x0809E630
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	ldr r1, _0809E648 @ =0x030047A4
	ldr r2, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r2, r0
	cmp r2, #0
	beq _0809E64C
	movs r0, #0
	b _0809E666
	.align 2, 0
_0809E648: .4byte 0x030047A4
_0809E64C:
	ldr r0, _0809E658 @ =0x030044E0
	ldrh r0, [r0]
	cmp r0, #0
	beq _0809E65C
	strh r2, [r4, #0x20]
	b _0809E668
	.align 2, 0
_0809E658: .4byte 0x030044E0
_0809E65C:
	ldrh r2, [r4, #0x20]
	ldr r0, _0809E6A0 @ =0x00000383
	cmp r2, r0
	bhi _0809E668
	adds r0, r2, #1
_0809E666:
	strh r0, [r4, #0x20]
_0809E668:
	ldr r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	beq _0809E722
	movs r1, #4
	ldr r0, _0809E6A4 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0809E722
	ldr r0, [r4, #0x18]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r5, r0, #0
	cmp r1, #5
	bne _0809E6C0
	cmp r3, #2
	bne _0809E6A8
	ldrh r0, [r4, #0x1e]
	adds r0, #0x28
	b _0809E6FC
	.align 2, 0
_0809E6A0: .4byte 0x00000383
_0809E6A4: .4byte 0x03002BC0
_0809E6A8:
	cmp r3, #0
	bne _0809E6FE
	ldrh r1, [r4, #0x20]
	ldr r0, _0809E6BC @ =0x00000383
	cmp r1, r0
	bhi _0809E6FE
	ldrh r0, [r4, #0x1e]
	adds r0, #5
	b _0809E6FC
	.align 2, 0
_0809E6BC: .4byte 0x00000383
_0809E6C0:
	cmp r3, #2
	bne _0809E6E0
	ldr r0, _0809E6D8 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0809E6DC @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #3
	ldrh r1, [r4, #0x1e]
	adds r0, r0, r1
	b _0809E6FC
	.align 2, 0
_0809E6D8: .4byte 0x030046A0
_0809E6DC: .4byte 0x00000942
_0809E6E0:
	cmp r3, #1
	bne _0809E6FE
	ldrh r1, [r4, #0x20]
	ldr r0, _0809E728 @ =0x00000383
	cmp r1, r0
	bhi _0809E6FE
	ldr r0, _0809E72C @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _0809E730 @ =0x00000942
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldrh r2, [r4, #0x1e]
	adds r0, r0, r2
_0809E6FC:
	strh r0, [r4, #0x1e]
_0809E6FE:
	movs r1, #0
	ldrh r3, [r4, #0x1e]
	cmp r3, #0x77
	bls _0809E718
_0809E706:
	adds r2, r3, #0
	subs r2, #0x78
	adds r1, #1
	adds r3, r2, #0
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bhi _0809E706
	strh r2, [r4, #0x1e]
_0809E718:
	cmp r1, #0
	ble _0809E722
	adds r0, r5, #0
	bl FUN_0807aa30
_0809E722:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809E728: .4byte 0x00000383
_0809E72C: .4byte 0x030046A0
_0809E730: .4byte 0x00000942

	thumb_func_start FUN_0809e734
FUN_0809e734: @ 0x0809E734
	push {lr}
	adds r2, r0, #0
	ldr r1, [r2, #0x18]
	movs r0, #0x20
	ldr r1, [r1, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0809E748
	movs r1, #2
	b _0809E750
_0809E748:
	movs r0, #0x10
	ands r1, r0
	rsbs r0, r1, #0
	lsrs r1, r0, #0x1f
_0809E750:
	adds r0, r2, #0
	bl FUN_0809e630
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809e75c
FUN_0809e75c: @ 0x0809E75C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r1, #0xce
	lsls r1, r1, #1
	ldrh r0, [r6, #0x24]
	cmp r0, r1
	beq _0809E7B6
	strh r1, [r6, #0x24]
	movs r2, #0
	adds r0, r6, #0
	adds r0, #0x26
	mov r8, r0
	ldrb r0, [r0]
	cmp r2, r0
	bge _0809E7B6
	movs r1, #0xa8
	mov sb, r1
_0809E784:
	mov r1, sb
	muls r1, r2, r1
	adds r0, r6, r1
	adds r0, #0xc9
	ldrb r0, [r0]
	adds r7, r2, #1
	cmp r0, #0
	beq _0809E7AC
	adds r0, r1, #0
	adds r0, #0x8c
	adds r4, r6, r0
	movs r5, #1
_0809E79C:
	ldrh r1, [r6, #0x24]
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	adds r4, #0x1c
	subs r5, #1
	cmp r5, #0
	bge _0809E79C
_0809E7AC:
	adds r2, r7, #0
	mov r0, r8
	ldrb r0, [r0]
	cmp r2, r0
	blt _0809E784
_0809E7B6:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809e7c4
FUN_0809e7c4: @ 0x0809E7C4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x28
	ldrb r0, [r1]
	cmp r0, #0
	bne _0809E816
	movs r0, #1
	strb r0, [r1]
	movs r5, #0
	adds r0, r4, #0
	adds r0, #0x26
	adds r6, r0, #0
	ldrb r0, [r6]
	cmp r5, r0
	bge _0809E816
	adds r3, r4, #0
	adds r3, #0xc6
	movs r7, #0
	movs r1, #0x34
	adds r1, r1, r4
	mov ip, r1
_0809E7F0:
	ldrb r0, [r3, #3]
	cmp r0, #0
	beq _0809E80A
	ldrb r0, [r3]
	cmp r0, #0
	beq _0809E80A
	mov r1, ip
	adds r0, r1, r7
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0809E80A:
	adds r3, #0xa8
	adds r7, #0xa8
	adds r5, #1
	ldrb r0, [r6]
	cmp r5, r0
	blt _0809E7F0
_0809E816:
	adds r0, r4, #0
	bl FUN_0809e75c
	ldr r1, [r4, #0x18]
	movs r0, #0x20
	ldr r1, [r1, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0809E82C
	movs r1, #2
	b _0809E834
_0809E82C:
	movs r0, #0x10
	ands r1, r0
	rsbs r0, r1, #0
	lsrs r1, r0, #0x1f
_0809E834:
	adds r0, r4, #0
	bl FUN_0809e630
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809e840
FUN_0809e840: @ 0x0809E840
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x28
	ldrb r0, [r1]
	cmp r0, #1
	bne _0809E880
	movs r0, #0
	strb r0, [r1]
	movs r3, #0
	adds r0, r4, #0
	adds r0, #0x26
	ldrb r1, [r0]
	cmp r3, r1
	bge _0809E880
	movs r6, #1
	adds r2, r4, #0
	adds r2, #0xc9
	adds r1, r4, #0
	adds r5, r0, #0
_0809E868:
	ldrb r0, [r2]
	cmp r0, #0
	beq _0809E874
	ldr r0, [r1, #0x34]
	orrs r0, r6
	str r0, [r1, #0x34]
_0809E874:
	adds r2, #0xa8
	adds r1, #0xa8
	adds r3, #1
	ldrb r0, [r5]
	cmp r3, r0
	blt _0809E868
_0809E880:
	ldr r0, [r4, #0x18]
	movs r2, #0x20
	ldr r1, [r0, #0x20]
	ands r1, r2
	rsbs r1, r1, #0
	asrs r1, r1, #0x1f
	movs r0, #2
	ands r1, r0
	adds r0, r4, #0
	bl FUN_0809e630
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809e89c
FUN_0809e89c: @ 0x0809E89C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x28
	ldrb r0, [r1]
	ldr r7, _0809E9A8 @ =0x030046A0
	cmp r0, #0
	bne _0809E8E2
	movs r0, #1
	strb r0, [r1]
	movs r3, #0
	adds r0, r5, #0
	adds r0, #0x26
	ldrb r1, [r0]
	cmp r3, r1
	bge _0809E8E2
	movs r6, #2
	rsbs r6, r6, #0
	adds r2, r5, #0
	adds r2, #0xc6
	adds r1, r5, #0
	adds r4, r0, #0
_0809E8CA:
	ldrb r0, [r2]
	cmp r0, #0
	beq _0809E8D6
	ldr r0, [r1, #0x34]
	ands r0, r6
	str r0, [r1, #0x34]
_0809E8D6:
	adds r2, #0xa8
	adds r1, #0xa8
	adds r3, #1
	ldrb r0, [r4]
	cmp r3, r0
	blt _0809E8CA
_0809E8E2:
	movs r4, #0
	ldr r0, [r7]
	ldr r1, _0809E9AC @ =0x00000934
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0809E906
	ldr r0, [r5, #0x18]
	adds r0, #0x2c
	bl FUN_0809e05c
	cmp r0, #0
	blt _0809E902
	movs r4, #1
_0809E902:
	cmp r4, #0
	beq _0809E9BE
_0809E906:
	ldr r2, [r5, #0x18]
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrb r1, [r0]
	cmp r1, #7
	bne _0809E9B8
	adds r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #3
	bhi _0809E9B8
	cmp r0, #3
	bne _0809E9C0
	ldrh r0, [r5, #0x22]
	cmp r0, #0x3e
	bhi _0809E9C0
	ands r1, r0
	cmp r1, #0
	bne _0809E99E
	ldr r0, [r2, #0x2c]
	ldr r1, [r2, #0x30]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	add r0, sp, #0xc
	ldrh r0, [r0]
	subs r0, #0x64
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _0809E9B0 @ =0xFFFF0000
	ldr r2, [sp, #0xc]
	ands r2, r3
	orrs r2, r0
	str r2, [sp, #0xc]
	add r0, sp, #0xc
	ldrh r0, [r0, #4]
	subs r0, #0x64
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x10]
	asrs r1, r2, #0x10
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r4, _0809E9B4 @ =0x0000FFFF
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x14]
	ands r0, r3
	movs r2, #0x80
	lsls r2, r2, #1
	orrs r0, r2
	ands r0, r4
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	str r1, [sp]
	movs r0, #0xb4
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #1
	movs r2, #0x19
	add r3, sp, #0xc
	bl Entity0800a89c_Spawn
_0809E99E:
	ldrh r0, [r5, #0x22]
	adds r0, #1
	strh r0, [r5, #0x22]
	b _0809E9C0
	.align 2, 0
_0809E9A8: .4byte 0x030046A0
_0809E9AC: .4byte 0x00000934
_0809E9B0: .4byte 0xFFFF0000
_0809E9B4: .4byte 0x0000FFFF
_0809E9B8:
	movs r0, #0
	strh r0, [r5, #0x22]
	b _0809E9C0
_0809E9BE:
	strh r4, [r5, #0x22]
_0809E9C0:
	adds r0, r5, #0
	bl FUN_0809e75c
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809e9d0
FUN_0809e9d0: @ 0x0809E9D0
	push {lr}
	ldrh r0, [r0, #0x1c]
	cmp r0, #0
	beq _0809E9E6
	bl FUN_0823e1b0
	subs r0, #1
	cmp r0, #2
	bls _0809E9E6
	movs r0, #1
	b _0809E9E8
_0809E9E6:
	movs r0, #0
_0809E9E8:
	pop {r1}
	bx r1

	thumb_func_start Entity0809eb24_Update
Entity0809eb24_Update: @ 0x0809E9EC
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _0809E9FE
	movs r0, #0
	strb r0, [r1]
_0809E9FE:
	ldr r0, _0809EA2C @ =0x03002BE0
	ldr r0, [r0]
	str r0, [r4, #0x18]
	cmp r0, #0
	beq _0809EA7E
	ldr r0, _0809EA30 @ =0x030046A0
	ldr r1, [r0]
	movs r2, #0x94
	lsls r2, r2, #4
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _0809EA3C
	adds r0, r4, #0
	bl FUN_0809e9d0
	cmp r0, #0
	beq _0809EA34
	adds r0, r4, #0
	bl FUN_0809e89c
	b _0809EA5E
	.align 2, 0
_0809EA2C: .4byte 0x03002BE0
_0809EA30: .4byte 0x030046A0
_0809EA34:
	adds r0, r4, #0
	bl FUN_0809e840
	b _0809EA5E
_0809EA3C:
	ldr r2, _0809EA54 @ =0x00000934
	adds r0, r1, r2
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0809EA58
	adds r0, r4, #0
	bl FUN_0809e734
	b _0809EA5E
	.align 2, 0
_0809EA54: .4byte 0x00000934
_0809EA58:
	adds r0, r4, #0
	bl FUN_0809e7c4
_0809EA5E:
	ldr r0, _0809EA88 @ =0x03002B80
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #1
	bne _0809EA6A
	movs r1, #1
_0809EA6A:
	cmp r1, #0
	beq _0809EA7E
	ldr r0, _0809EA8C @ =0x03002BF0
	ldrh r0, [r0]
	cmp r0, #0
	beq _0809EA7E
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
_0809EA7E:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809EA88: .4byte 0x03002B80
_0809EA8C: .4byte 0x03002BF0

	thumb_func_start Entity0809eb24_Destroy
Entity0809eb24_Destroy: @ 0x0809EA90
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	b _0809EAB4
_0809EA98:
	movs r0, #0xa8
	adds r1, r5, #0
	muls r1, r0, r1
	adds r0, r4, r1
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809EAB0
	adds r0, r1, r4
	adds r0, #0x34
	bl AuxSprite_Remove
_0809EAB0:
	adds r5, #1
	adds r0, r4, #0
_0809EAB4:
	adds r0, #0x26
	ldrb r0, [r0]
	cmp r5, r0
	blt _0809EA98
	ldr r1, _0809EAC8 @ =0x03000140
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809EAC8: .4byte 0x03000140

	thumb_func_start FUN_0809eacc
FUN_0809eacc: @ 0x0809EACC
	push {lr}
	ldr r0, _0809EAE8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0809EAE4
	bl FUN_0823e4d4
	cmp r0, #4
	beq _0809EAEC
_0809EAE4:
	movs r0, #0
	b _0809EAEE
	.align 2, 0
_0809EAE8: .4byte 0x030047A4
_0809EAEC:
	movs r0, #1
_0809EAEE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity0809eb24_Init
Entity0809eb24_Init: @ 0x0809EAF4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0809eacc
	movs r1, #0
	strh r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0x26
	strb r1, [r0]
	movs r0, #0xcd
	lsls r0, r0, #1
	strh r0, [r4, #0x24]
	adds r0, r4, #0
	adds r0, #0x28
	strb r1, [r0]
	ldr r0, _0809EB20 @ =0x03000140
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809EB20: .4byte 0x03000140

	thumb_func_start Entity0809eb24_Create
Entity0809eb24_Create: @ 0x0809EB24
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, _0809EB58 @ =0x00000AB4
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0809EB64
	ldr r1, _0809EB5C @ =Entity0809eb24_Update
	ldr r2, _0809EB60 @ =Entity0809eb24_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Entity0809eb24_Init
	cmp r0, #0
	bge _0809EB64
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0809EB66
	.align 2, 0
_0809EB58: .4byte 0x00000AB4
_0809EB5C: .4byte Entity0809eb24_Update
_0809EB60: .4byte Entity0809eb24_Destroy
_0809EB64:
	adds r0, r4, #0
_0809EB66:
	pop {r4, r5, r6}
	pop {r1}
	bx r1


	thumb_func_start FUN_0809eb6c
FUN_0809eb6c: @ 0x0809EB6C
	push {lr}
	adds r1, r0, #0
	ldr r0, _0809EB7C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0809EB80
	movs r0, #0
	b _0809EB84
	.align 2, 0
_0809EB7C: .4byte 0x03002C68
_0809EB80:
	adds r0, #0x66
	ldrh r0, [r0]
_0809EB84:
	adds r2, r0, #0
	muls r2, r1, r2
	adds r0, r2, #0
	movs r1, #0x8c
	bl Div
	pop {r1}
	bx r1

	thumb_func_start FUN_0809eb94
FUN_0809eb94: @ 0x0809EB94
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	ldr r0, _0809EBA8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0809EBAC
	movs r0, #0
	b _0809EBB0
	.align 2, 0
_0809EBA8: .4byte 0x03002C68
_0809EBAC:
	adds r0, #0x66
	ldrh r0, [r0]
_0809EBB0:
	cmp r0, #0
	beq _0809EBE4
	movs r1, #2
	ldr r0, _0809EBCC @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _0809EBD0 @ =0x00000934
	adds r0, r0, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0809EBD4
	movs r0, #1
	b _0809EBD6
	.align 2, 0
_0809EBCC: .4byte 0x030046A0
_0809EBD0: .4byte 0x00000934
_0809EBD4:
	movs r0, #0
_0809EBD6:
	cmp r0, #0
	bne _0809EBE8
	adds r0, r2, #0
	bl FUN_0809e05c
	cmp r0, #0
	bge _0809EBE8
_0809EBE4:
	movs r0, #0
	b _0809EBEE
_0809EBE8:
	adds r0, r4, #0
	bl FUN_0809eb6c
_0809EBEE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809ebf4
FUN_0809ebf4: @ 0x0809EBF4
	push {lr}
	adds r2, r0, #0
	ldr r1, [r2, #0x18]
	ldr r0, _0809EC08 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0809EC0C
	movs r0, #0
	b _0809EC12
	.align 2, 0
_0809EC08: .4byte 0x03002C68
_0809EC0C:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_0809EC12:
	cmp r0, #0
	beq _0809EC4E
	movs r1, #2
	ldr r0, _0809EC2C @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _0809EC30 @ =0x00000934
	adds r0, r0, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0809EC34
	movs r0, #1
	b _0809EC36
	.align 2, 0
_0809EC2C: .4byte 0x030046A0
_0809EC30: .4byte 0x00000934
_0809EC34:
	movs r0, #0
_0809EC36:
	cmp r0, #0
	bne _0809EC58
	ldr r0, _0809EC54 @ =0x03000140
	ldr r0, [r0]
	cmp r0, #0
	beq _0809EC4E
	adds r0, r2, #0
	adds r0, #0x2c
	bl FUN_0809e05c
	cmp r0, #0
	bge _0809EC58
_0809EC4E:
	movs r0, #0
	b _0809EC5A
	.align 2, 0
_0809EC54: .4byte 0x03000140
_0809EC58:
	movs r0, #1
_0809EC5A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0809ec60
FUN_0809ec60: @ 0x0809EC60
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r3, #0
	ldr r7, _0809EC90 @ =0x00000AAC
	add r7, r8
_0809EC6E:
	ldr r1, _0809EC94 @ =0x03002BE0
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r6, [r0]
	adds r5, r3, #1
	cmp r6, #0
	beq _0809ED3E
	ldr r0, [r6, #0x1c]
	cmp r0, #1
	bne _0809ED3E
	movs r0, #0x20
	ldr r1, [r6, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0809EC98
	movs r1, #2
	b _0809ECA0
	.align 2, 0
_0809EC90: .4byte 0x00000AAC
_0809EC94: .4byte 0x03002BE0
_0809EC98:
	movs r0, #0x10
	ands r1, r0
	rsbs r0, r1, #0
	lsrs r1, r0, #0x1f
_0809ECA0:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #5
	bne _0809ECC8
	cmp r1, #2
	bne _0809ECBA
	lsls r2, r3, #1
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #0x28
	b _0809ED0E
_0809ECBA:
	lsls r2, r3, #1
	cmp r1, #0
	bne _0809ED10
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #5
	b _0809ED0E
_0809ECC8:
	cmp r1, #2
	bne _0809ECEA
	ldr r0, _0809ECD8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0809ECDC
	movs r0, #0
	b _0809ECE2
	.align 2, 0
_0809ECD8: .4byte 0x03002C68
_0809ECDC:
	adds r0, #0x60
	adds r0, r0, r3
	ldrb r0, [r0]
_0809ECE2:
	lsls r2, r3, #1
	adds r1, r7, r2
	lsls r0, r0, #3
	b _0809ED0A
_0809ECEA:
	lsls r2, r3, #1
	cmp r1, #1
	bne _0809ED10
	ldr r0, _0809ECFC @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0809ED00
	movs r0, #0
	b _0809ED06
	.align 2, 0
_0809ECFC: .4byte 0x03002C68
_0809ED00:
	adds r0, #0x60
	adds r0, r0, r3
	ldrb r0, [r0]
_0809ED06:
	lsls r2, r3, #1
	adds r1, r7, r2
_0809ED0A:
	ldrh r4, [r1]
	adds r0, r0, r4
_0809ED0E:
	strh r0, [r1]
_0809ED10:
	movs r4, #0
	adds r0, r7, r2
	ldrh r0, [r0]
	adds r5, r3, #1
	cmp r0, #0x77
	bls _0809ED32
	ldr r3, _0809ED50 @ =0x00000AAC
	add r3, r8
_0809ED20:
	adds r1, r3, r2
	ldrh r0, [r1]
	subs r0, #0x78
	strh r0, [r1]
	adds r4, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bhi _0809ED20
_0809ED32:
	cmp r4, #0
	ble _0809ED3E
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_0807aa30
_0809ED3E:
	adds r3, r5, #0
	cmp r3, #3
	ble _0809EC6E
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809ED50: .4byte 0x00000AAC

	thumb_func_start FUN_0809ed54
FUN_0809ed54: @ 0x0809ED54
	bx lr
	.align 2, 0

	thumb_func_start FUN_0809ed58
FUN_0809ed58: @ 0x0809ED58
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	ldr r0, _0809ED6C @ =0x03002C68
	ldr r1, [r0]
	cmp r1, #0
	bne _0809ED70
	movs r1, #1
	rsbs r1, r1, #0
	b _0809ED74
	.align 2, 0
_0809ED6C: .4byte 0x03002C68
_0809ED70:
	movs r2, #0x18
	ldrsh r1, [r1, r2]
_0809ED74:
	ldr r0, [r0]
	cmp r0, #0
	bne _0809ED7E
	movs r0, #0
	b _0809ED84
_0809ED7E:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_0809ED84:
	adds r2, r0, #0
	cmp r2, #0
	beq _0809EDD6
	mov r1, ip
	adds r1, #0x28
	ldrb r0, [r1]
	cmp r0, #0
	bne _0809EE12
	movs r0, #1
	strb r0, [r1]
	movs r4, #0
	mov r0, ip
	adds r0, #0x26
	adds r5, r0, #0
	ldrb r0, [r5]
	cmp r4, r0
	bge _0809EE12
	mov r3, ip
	adds r3, #0xc6
	movs r6, #0
	mov r7, ip
	adds r7, #0x34
_0809EDB0:
	ldrb r0, [r3, #3]
	cmp r0, #0
	beq _0809EDC8
	ldrb r0, [r3]
	cmp r0, #0
	beq _0809EDC8
	adds r0, r7, r6
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0809EDC8:
	adds r3, #0xa8
	adds r6, #0xa8
	adds r4, #1
	ldrb r2, [r5]
	cmp r4, r2
	blt _0809EDB0
	b _0809EE12
_0809EDD6:
	mov r1, ip
	adds r1, #0x28
	ldrb r0, [r1]
	cmp r0, #1
	bne _0809EE12
	strb r2, [r1]
	movs r4, #0
	mov r0, ip
	adds r0, #0x26
	adds r5, r0, #0
	ldrb r0, [r5]
	cmp r4, r0
	bge _0809EE12
	movs r6, #1
	mov r2, ip
	adds r2, #0xc9
	mov r1, ip
	adds r3, r5, #0
_0809EDFA:
	ldrb r0, [r2]
	cmp r0, #0
	beq _0809EE06
	ldr r0, [r1, #0x34]
	orrs r0, r6
	str r0, [r1, #0x34]
_0809EE06:
	adds r2, #0xa8
	adds r1, #0xa8
	adds r4, #1
	ldrb r0, [r3]
	cmp r4, r0
	blt _0809EDFA
_0809EE12:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start Entity0809eeb4_Update
Entity0809eeb4_Update: @ 0x0809EE18
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0809EE38 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0809EE3C @ =0x00000934
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0809EE40
	adds r0, r4, #0
	bl FUN_0809ed54
	b _0809EE46
	.align 2, 0
_0809EE38: .4byte 0x030046A0
_0809EE3C: .4byte 0x00000934
_0809EE40:
	adds r0, r4, #0
	bl FUN_0809ed58
_0809EE46:
	adds r0, r4, #0
	bl FUN_0809ec60
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start Entity0809eeb4_Destroy
Entity0809eeb4_Destroy: @ 0x0809EE54
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	b _0809EE78
_0809EE5C:
	movs r0, #0xa8
	adds r1, r5, #0
	muls r1, r0, r1
	adds r0, r4, r1
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809EE74
	adds r0, r1, r4
	adds r0, #0x34
	bl AuxSprite_Remove
_0809EE74:
	adds r5, #1
	adds r0, r4, #0
_0809EE78:
	adds r0, #0x26
	ldrb r0, [r0]
	cmp r5, r0
	blt _0809EE5C
	ldr r1, _0809EE8C @ =0x03000140
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809EE8C: .4byte 0x03000140

	thumb_func_start Entity0809eeb4_Init
Entity0809eeb4_Init: @ 0x0809EE90
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #0
	strb r1, [r2]
	movs r2, #0
	movs r1, #0xcd
	lsls r1, r1, #1
	strh r1, [r0, #0x24]
	adds r1, r0, #0
	adds r1, #0x28
	strb r2, [r1]
	ldr r1, _0809EEB0 @ =0x03000140
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_0809EEB0: .4byte 0x03000140

	thumb_func_start Entity0809eeb4_Create
Entity0809eeb4_Create: @ 0x0809EEB4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, _0809EEE8 @ =0x00000AB4
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0809EEF4
	ldr r1, _0809EEEC @ =Entity0809eeb4_Update
	ldr r2, _0809EEF0 @ =Entity0809eeb4_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Entity0809eeb4_Init
	cmp r0, #0
	bge _0809EEF4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0809EEF6
	.align 2, 0
_0809EEE8: .4byte 0x00000AB4
_0809EEEC: .4byte Entity0809eeb4_Update
_0809EEF0: .4byte Entity0809eeb4_Destroy
_0809EEF4:
	adds r0, r4, #0
_0809EEF6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start VM_Sub5CCC
VM_Sub5CCC: @ 0x0809EEFC
	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, _0809EF24 @ =0x03000140
	ldr r0, [r0]
	cmp r0, #0
	bne _0809EF34
	ldr r0, _0809EF28 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0809EF2C
	adds r0, r2, #0
	adds r1, r3, #0
	bl Entity0809eb24_Create
	b _0809EF34
	.align 2, 0
_0809EF24: .4byte 0x03000140
_0809EF28: .4byte 0x030047A4
_0809EF2C:
	adds r0, r2, #0
	adds r1, r3, #0
	bl Entity0809eeb4_Create
_0809EF34:
	pop {r1}
	bx r1
