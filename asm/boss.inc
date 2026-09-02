	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08022a0c
FUN_08022a0c: @ 0x08022A0C
	ldr r2, _08022A18 @ =0x030000A0
	lsls r1, r1, #2
	adds r1, r1, r2
	str r0, [r1]
	bx lr
	.align 2, 0
_08022A18: .4byte 0x030000A0

	thumb_func_start FUN_08022a1c
FUN_08022a1c: @ 0x08022A1C
	ldr r1, _08022A28 @ =0x030000A0
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
	bx lr
	.align 2, 0
_08022A28: .4byte 0x030000A0

	thumb_func_start FUN_08022a2c
FUN_08022a2c: @ 0x08022A2C
	ldr r1, _08022A38 @ =0x030000A0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08022A38: .4byte 0x030000A0

	thumb_func_start FUN_08022a3c
FUN_08022a3c: @ 0x08022A3C
	push {r4, lr}
	movs r2, #0
	movs r4, #0
	ldr r3, _08022A6C @ =0x030000A0
_08022A44:
	ldr r1, [r3]
	cmp r1, #0
	beq _08022A5A
	adds r0, r1, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	bne _08022A5A
	cmp r2, #0
	bne _08022A62
	adds r2, r1, #0
_08022A5A:
	adds r3, #4
	adds r4, #1
	cmp r4, #7
	ble _08022A44
_08022A62:
	adds r0, r2, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08022A6C: .4byte 0x030000A0

	thumb_func_start Boss_Init_08022a70
Boss_Init_08022a70: @ 0x08022A70
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	mov r8, r1
	adds r5, r3, #0
	ldr r6, [sp, #0x28]
	adds r0, #0x97
	strb r2, [r0]
	adds r4, r7, #0
	adds r4, #0x48
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r3, r6, #0x18
	lsrs r3, r3, #0x18
	movs r0, #5
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823b400
	ldr r1, _08022B00 @ =0xFFFF0000
	movs r0, #0x80
	lsls r0, r0, #0x11
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
	adds r0, r4, #0
	add r1, sp, #8
	bl FUN_0823b47c
	adds r3, r7, #0
	adds r3, #0x4d
	strb r6, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r7, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r7, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r7, r1
	mov r1, r8
	movs r2, #4
	bl FUN_080223f4
	movs r0, #0
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08022B00: .4byte 0xFFFF0000

	thumb_func_start FUN_08022b04
FUN_08022b04: @ 0x08022B04
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08022428
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_0823b284
	adds r0, r4, #0
	adds r0, #0x97
	ldrb r0, [r0]
	bl FUN_08022a1c
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08022b2c
FUN_08022b2c: @ 0x08022B2C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r0, #0x92
	adds r0, r0, r4
	mov ip, r0
	strh r2, [r0]
	adds r2, r4, #0
	adds r2, #0x90
	strh r1, [r2]
	adds r0, r4, #0
	adds r0, #0x94
	strh r3, [r0]
	movs r3, #0
	ldrsh r1, [r2, r3]
	mov r5, ip
	ldrh r3, [r5]
	movs r6, #0
	ldrsh r0, [r5, r6]
	cmp r1, r0
	ble _08022B56
	strh r3, [r2]
_08022B56:
	mov r1, ip
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	beq _08022B74
	movs r5, #0
	ldrsh r0, [r2, r5]
	lsls r0, r0, #7
	movs r6, #0
	ldrsh r1, [r1, r6]
	bl Div
	adds r1, r4, #0
	adds r1, #0xdd
	b _08022B7A
_08022B74:
	adds r1, r4, #0
	adds r1, #0xdd
	movs r0, #0
_08022B7A:
	strb r0, [r1]
	ldr r2, _08022BAC @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0xaf
	lsls r1, r1, #2
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x92
	movs r3, #0
	ldrsh r1, [r1, r3]
	str r1, [r0]
	ldr r0, [r2]
	movs r5, #0xae
	lsls r5, r5, #2
	adds r0, r0, r5
	adds r1, r4, #0
	adds r1, #0x90
	movs r6, #0
	ldrsh r1, [r1, r6]
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08022BAC: .4byte 0x030046A0

	thumb_func_start FUN_08022bb0
FUN_08022bb0: @ 0x08022BB0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r2, r4, #0
	adds r2, #0x90
	strh r1, [r2]
	adds r0, #0x92
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrh r3, [r0]
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r1, r0
	ble _08022BCE
	strh r3, [r2]
	b _08022BD6
_08022BCE:
	cmp r1, #0
	bge _08022BD6
	movs r0, #0
	strh r0, [r2]
_08022BD6:
	adds r2, r4, #0
	adds r2, #0x92
	movs r0, #0
	ldrsh r1, [r2, r0]
	cmp r1, #0
	beq _08022BFE
	adds r0, r4, #0
	adds r0, #0x90
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	movs r3, #0
	ldrsh r1, [r2, r3]
	bl Div
	adds r1, r4, #0
	adds r1, #0xdd
	strb r0, [r1]
	adds r0, r1, #0
	b _08022C04
_08022BFE:
	adds r0, r4, #0
	adds r0, #0xdd
	strb r1, [r0]
_08022C04:
	ldrb r0, [r0]
	cmp r0, #0x3f
	bhi _08022C12
	adds r1, r4, #0
	adds r1, #0x9c
	movs r0, #1
	b _08022C18
_08022C12:
	adds r1, r4, #0
	adds r1, #0x9c
	movs r0, #0
_08022C18:
	strb r0, [r1]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08022c24
FUN_08022c24: @ 0x08022C24
	adds r3, r0, #0
	adds r3, #0xac
	strb r1, [r3]
	adds r0, #0xad
	strb r2, [r0]
	movs r0, #0
	bx lr
	.align 2, 0

	thumb_func_start FUN_08022c34
FUN_08022c34: @ 0x08022C34
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	ldr r3, [sp, #0x18]
	ldr r4, [sp, #0x1c]
	movs r0, #0xae
	adds r0, r0, r5
	mov ip, r0
	movs r0, #0
	mov r7, ip
	strb r0, [r7]
	adds r0, r5, #0
	adds r0, #0xb0
	strh r2, [r0]
	ldrh r2, [r0]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp]
	adds r0, r6, #0
	bl FUN_082370cc
	adds r0, r5, #0
	adds r0, #0xa0
	ldrb r0, [r0]
	cmp r0, #1
	bls _08022C82
	adds r1, r5, #0
	adds r1, #0xaf
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r6, #8]
	movs r1, #4
	orrs r0, r1
	b _08022C92
_08022C82:
	adds r1, r5, #0
	adds r1, #0xaf
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08022C92:
	str r0, [r6, #8]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08022c9c
FUN_08022c9c: @ 0x08022C9C
	push {r4, r5, r6, lr}
	sub sp, #4
	mov ip, r0
	adds r4, r1, #0
	adds r6, r2, #0
	adds r0, #0xa0
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08022CBC
	mov r1, ip
	adds r1, #0xae
	ldr r0, [sp, #0x18]
	b _08022CC2
_08022CBC:
	mov r1, ip
	adds r1, #0xae
	movs r0, #0
_08022CC2:
	strb r0, [r1]
	adds r2, r1, #0
	mov r0, ip
	adds r0, #0xa0
	ldrb r0, [r0]
	cmp r0, #1
	bls _08022CD8
	mov r1, ip
	adds r1, #0xaf
	movs r0, #1
	b _08022CDE
_08022CD8:
	mov r1, ip
	adds r1, #0xaf
	movs r0, #0
_08022CDE:
	strb r0, [r1]
	adds r5, r1, #0
	ldrb r0, [r2]
	adds r0, r0, r3
	mov r1, ip
	adds r1, #0xb0
	strh r0, [r1]
	ldrh r2, [r1]
	ldr r3, [sp, #0x14]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r0, [sp, #0x1c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_082370cc
	ldrb r0, [r5]
	cmp r0, #0
	beq _08022D12
	ldr r0, [r4, #8]
	movs r1, #4
	orrs r0, r1
	b _08022D1A
_08022D12:
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08022D1A:
	str r0, [r4, #8]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08022d24
FUN_08022d24: @ 0x08022D24
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	mov ip, r0
	adds r4, r1, #0
	adds r7, r2, #0
	adds r6, r3, #0
	adds r0, #0xa1
	ldrb r3, [r0]
	subs r0, r3, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _08022D54
	movs r0, #8
	subs r0, r0, r3
	mov r2, ip
	adds r2, #0xae
	strb r0, [r2]
	mov r1, ip
	adds r1, #0xaf
	movs r0, #1
	strb r0, [r1]
	adds r5, r1, #0
	b _08022D64
_08022D54:
	mov r2, ip
	adds r2, #0xae
	movs r1, #0
	strb r3, [r2]
	mov r0, ip
	adds r0, #0xaf
	strb r1, [r0]
	adds r5, r0, #0
_08022D64:
	ldrb r0, [r2]
	adds r0, r0, r6
	mov r1, ip
	adds r1, #0xb0
	strh r0, [r1]
	ldrh r2, [r1]
	ldr r3, [sp, #0x18]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	ldr r0, [sp, #0x20]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r7, #0
	bl FUN_082370cc
	ldrb r0, [r5]
	cmp r0, #0
	beq _08022D94
	ldr r0, [r4, #8]
	movs r1, #4
	orrs r0, r1
	b _08022D9C
_08022D94:
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08022D9C:
	str r0, [r4, #8]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08022da8
FUN_08022da8: @ 0x08022DA8
	push {r4, r5, r6, lr}
	sub sp, #4
	mov ip, r0
	adds r6, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	ldr r3, [sp, #0x14]
	ldr r4, [sp, #0x18]
	mov r5, ip
	adds r5, #0xae
	movs r0, #0
	strb r0, [r5]
	adds r5, #1
	strb r0, [r5]
	mov r0, ip
	adds r0, #0xb0
	strh r2, [r0]
	ldrh r2, [r0]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp]
	adds r0, r6, #0
	bl FUN_082370cc
	ldrb r0, [r5]
	cmp r0, #0
	beq _08022DEA
	ldr r0, [r6, #8]
	movs r1, #4
	orrs r0, r1
	b _08022DF2
_08022DEA:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08022DF2:
	str r0, [r6, #8]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08022dfc
FUN_08022dfc: @ 0x08022DFC
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	adds r1, r2, #0
	bl FUN_082372cc
	adds r1, r4, #0
	adds r1, #0xaa
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xb0
	ldrh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08022e20
FUN_08022e20: @ 0x08022E20
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0xa2
	movs r0, #0
	strb r0, [r1]
	adds r6, r7, #0
	adds r6, #0xdc
	strb r0, [r6]
	subs r1, #0x5a
	adds r0, r7, #0
	adds r0, #0xcc
	movs r2, #0
	ldrsh r5, [r0, r2]
	movs r3, #8
	ldrsh r0, [r1, r3]
	subs r5, r5, r0
	adds r0, r7, #0
	adds r0, #0xd0
	movs r2, #0
	ldrsh r4, [r0, r2]
	movs r3, #0xc
	ldrsh r0, [r1, r3]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	adds r1, r7, #0
	adds r1, #0xd8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [r1]
	adds r2, r7, #0
	adds r2, #0xd4
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
	movs r0, #1
	strb r0, [r6]
	subs r2, #0x42
	movs r0, #0
	ldrsh r1, [r2, r0]
	cmp r1, #0
	beq _08022E9C
	adds r0, r7, #0
	adds r0, #0x90
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	movs r3, #0
	ldrsh r1, [r2, r3]
	bl Div
	adds r1, r7, #0
	adds r1, #0xdd
	strb r0, [r1]
	adds r0, r1, #0
	b _08022EA2
_08022E9C:
	adds r0, r7, #0
	adds r0, #0xdd
	strb r1, [r0]
_08022EA2:
	ldrb r0, [r0]
	cmp r0, #0x3f
	bhi _08022EB0
	adds r1, r7, #0
	adds r1, #0x9c
	movs r0, #1
	b _08022EB6
_08022EB0:
	adds r1, r7, #0
	adds r1, #0x9c
	movs r0, #0
_08022EB6:
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08022ec0
FUN_08022ec0: @ 0x08022EC0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x90
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	ble _08022EE4
	ldr r0, _08022EE0 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0xae
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	b _08022EF0
	.align 2, 0
_08022EE0: .4byte 0x030046A0
_08022EE4:
	ldr r0, _08022F70 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
_08022EF0:
	str r1, [r0]
	adds r4, r5, #0
	adds r4, #0xac
	ldrb r0, [r4]
	cmp r0, #0
	beq _08022F0C
	adds r0, r5, #0
	adds r0, #0xad
	ldrb r0, [r0]
	bl FUN_0823b9cc
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
_08022F0C:
	movs r2, #0xaa
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08022F2C
	adds r0, r5, #0
	adds r0, #0xe0
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _08022F2C
	adds r0, r5, #0
	bl FUN_0802326c
_08022F2C:
	ldr r1, _08022F74 @ =0x00000155
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08022F50
	adds r0, r5, #0
	adds r0, #0xe0
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #1
	bhi _08022F50
	movs r2, #0x10
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08022F50:
	movs r2, #0xab
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08022F68
	movs r2, #0x10
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08022F68:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08022F70: .4byte 0x030046A0
_08022F74: .4byte 0x00000155

	thumb_func_start FUN_08022f78
FUN_08022f78: @ 0x08022F78
	push {r4, lr}
	adds r2, r0, #0
	adds r0, #0x98
	movs r1, #0
	str r1, [r0]
	adds r0, #0xf
	strb r1, [r0]
	adds r1, r2, #0
	adds r1, #0x8c
	ldr r0, [r1]
	adds r4, r0, #0
	adds r0, #1
	str r0, [r1]
	adds r0, r2, #0
	adds r0, #0xf8
	ldr r3, [r0]
	cmp r3, #0
	beq _08022FA4
	adds r0, r2, #0
	adds r1, r4, #0
	bl _call_via_r3
_08022FA4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08022fac
FUN_08022fac: @ 0x08022FAC
	adds r3, r0, #0
	adds r3, #0xe4
	strh r1, [r3]
	adds r0, #0xe6
	strh r2, [r0]
	bx lr

	thumb_func_start FUN_08022fb8
FUN_08022fb8: @ 0x08022FB8
	push {r4, r5, lr}
	sub sp, #0x28
	adds r3, r0, #0
	adds r2, r1, #0
	adds r1, r3, #0
	adds r1, #0xe4
	ldrh r0, [r1]
	cmp r0, #0
	beq _08023014
	adds r5, r0, #0
	movs r1, #4
	ldr r0, _0802301C @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08023014
	movs r1, #0
	ldrsh r0, [r2, r1]
	str r0, [sp]
	movs r1, #2
	ldrsh r0, [r2, r1]
	str r0, [sp, #4]
	movs r1, #4
	ldrsh r0, [r2, r1]
	str r0, [sp, #8]
	add r4, sp, #0x20
	adds r3, #0xe8
	add r2, sp, #0xc
	movs r1, #3
_08022FF2:
	ldm r3!, {r0}
	stm r2!, {r0}
	subs r1, #1
	cmp r1, #0
	bge _08022FF2
	ldr r0, _08023020 @ =0xFFFF0000
	ldr r1, [sp, #0x20]
	ands r1, r0
	movs r0, #7
	orrs r1, r0
	str r1, [sp, #0x20]
	mov r0, sp
	str r0, [r4, #4]
	adds r0, r5, #0
	adds r1, r4, #0
	bl Script_ExecById
_08023014:
	add sp, #0x28
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802301C: .4byte 0x03002BC0
_08023020: .4byte 0xFFFF0000

	thumb_func_start FUN_08023024
FUN_08023024: @ 0x08023024
	push {r4, r5, lr}
	sub sp, #0x28
	adds r3, r0, #0
	adds r2, r1, #0
	adds r1, r3, #0
	adds r1, #0xe6
	ldrh r0, [r1]
	cmp r0, #0
	beq _08023080
	adds r5, r0, #0
	movs r1, #4
	ldr r0, _08023088 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08023080
	movs r1, #0
	ldrsh r0, [r2, r1]
	str r0, [sp]
	movs r1, #2
	ldrsh r0, [r2, r1]
	str r0, [sp, #4]
	movs r1, #4
	ldrsh r0, [r2, r1]
	str r0, [sp, #8]
	add r4, sp, #0x20
	adds r3, #0xe8
	add r2, sp, #0xc
	movs r1, #3
_0802305E:
	ldm r3!, {r0}
	stm r2!, {r0}
	subs r1, #1
	cmp r1, #0
	bge _0802305E
	ldr r0, _0802308C @ =0xFFFF0000
	ldr r1, [sp, #0x20]
	ands r1, r0
	movs r0, #7
	orrs r1, r0
	str r1, [sp, #0x20]
	mov r0, sp
	str r0, [r4, #4]
	adds r0, r5, #0
	adds r1, r4, #0
	bl Script_ExecById
_08023080:
	add sp, #0x28
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08023088: .4byte 0x03002BC0
_0802308C: .4byte 0xFFFF0000

	thumb_func_start FUN_08023090
FUN_08023090: @ 0x08023090
	push {lr}
	adds r0, #0xb4
	ldr r0, [r0]
	bl FUN_0807a840
	pop {r0}
	bx r0
	.align 2, 0
_080230A0:
	.byte 0x10, 0xB5, 0x04, 0x1C, 0xFF, 0xF7, 0xCA, 0xFC, 0x00, 0x28, 0x05, 0xD0, 0x41, 0x6D, 0x00, 0x6D
	.byte 0x20, 0x60, 0x61, 0x60, 0x00, 0x20, 0x01, 0xE0, 0x01, 0x20, 0x40, 0x42, 0x10, 0xBC, 0x02, 0xBC
	.byte 0x08, 0x47, 0x00, 0x00

	thumb_func_start FUN_080230c4
FUN_080230c4: @ 0x080230C4
	push {lr}
	bl FUN_08022a3c
	cmp r0, #0
	beq _080230D2
	adds r0, #0x50
	b _080230D4
_080230D2:
	movs r0, #0
_080230D4:
	pop {r1}
	bx r1

	thumb_func_start FUN_080230d8
FUN_080230d8: @ 0x080230D8
	push {r4, r5, r6, lr}
	sub sp, #0x10
	mov ip, r0
	adds r4, r2, #0
	adds r6, r3, #0
	cmp r1, #8
	bls _080230E8
	b _08023262
_080230E8:
	lsls r0, r1, #2
	ldr r1, _080230F4 @ =_080230F8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080230F4: .4byte _080230F8
_080230F8: @ jump table
	.4byte _0802311C @ case 0
	.4byte _0802316A @ case 1
	.4byte _0802314C @ case 2
	.4byte _08023196 @ case 3
	.4byte _080231C4 @ case 4
	.4byte _080231F4 @ case 5
	.4byte _08023224 @ case 6
	.4byte _08023240 @ case 7
	.4byte _08023262 @ case 8
_0802311C:
	movs r4, #0xa6
	lsls r4, r4, #1
	add r4, ip
	ldr r0, [r4]
	mov r1, ip
	adds r1, #0x48
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #1
	bl FUN_080da9c4
	str r0, [r4]
	ldr r0, _08023148 @ =0x000001B1
	bl PlaySound_082406e0
	b _08023262
	.align 2, 0
_08023148: .4byte 0x000001B1
_0802314C:
	movs r4, #0xa6
	lsls r4, r4, #1
	add r4, ip
	ldr r0, [r4]
	mov r1, ip
	adds r1, #0x48
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #0
	b _08023186
_0802316A:
	movs r4, #0xa6
	lsls r4, r4, #1
	add r4, ip
	ldr r0, [r4]
	mov r1, ip
	adds r1, #0x48
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #3
_08023186:
	bl FUN_080da9c4
	str r0, [r4]
	movs r0, #0xf6
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _08023262
_08023196:
	movs r4, #0xa6
	lsls r4, r4, #1
	add r4, ip
	ldr r0, [r4]
	mov r1, ip
	adds r1, #0x48
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #2
	bl FUN_080da9c4
	str r0, [r4]
	ldr r0, _080231C0 @ =0x000001ED
	bl PlaySound_082406e0
	b _08023262
	.align 2, 0
_080231C0: .4byte 0x000001ED
_080231C4:
	movs r2, #0xa8
	lsls r2, r2, #1
	add r2, ip
	movs r3, #0
	strh r4, [r2]
	movs r5, #0xa9
	lsls r5, r5, #1
	add r5, ip
	strh r6, [r5]
	movs r4, #0xa6
	lsls r4, r4, #1
	add r4, ip
	ldr r0, [r4]
	mov r1, ip
	adds r1, #0x48
	str r2, [sp]
	movs r6, #0
	ldrsh r2, [r5, r6]
	str r2, [sp, #4]
	str r3, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #1
	b _0802325C
_080231F4:
	movs r2, #0xa8
	lsls r2, r2, #1
	add r2, ip
	movs r3, #0
	strh r4, [r2]
	movs r5, #0xa9
	lsls r5, r5, #1
	add r5, ip
	strh r6, [r5]
	movs r4, #0xa6
	lsls r4, r4, #1
	add r4, ip
	ldr r0, [r4]
	mov r1, ip
	adds r1, #0x48
	str r2, [sp]
	movs r6, #0
	ldrsh r2, [r5, r6]
	str r2, [sp, #4]
	str r3, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #3
	b _0802325C
_08023224:
	movs r4, #0xa6
	lsls r4, r4, #1
	add r4, ip
	ldr r0, [r4]
	mov r1, ip
	adds r1, #0x48
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #5
	b _0802325A
_08023240:
	movs r4, #0xa6
	lsls r4, r4, #1
	add r4, ip
	ldr r0, [r4]
	mov r1, ip
	adds r1, #0x48
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #4
_0802325A:
	movs r3, #0
_0802325C:
	bl FUN_080da9c4
	str r0, [r4]
_08023262:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

