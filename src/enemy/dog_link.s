	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081c5c94
FUN_081c5c94: @ 0x081C5C94
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	ldr r2, _081C5D20 @ =0x000006C2
	adds r0, r6, r2
	ldrh r1, [r0]
	movs r3, #0xd8
	lsls r3, r3, #3
	adds r0, r6, r3
	movs r7, #0
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r5, [r0]
	ands r5, r1
	cmp r5, #0
	beq _081C5D42
	ldr r3, _081C5D24 @ =0x000001DF
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #2
	beq _081C5CD8
	movs r0, #4
	ldr r1, _081C5D28 @ =0x00000222
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081C5CD8:
	movs r0, #0x80
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r4, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0x93
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r3, #0xce
	adds r0, r4, r3
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _081C5D0C
	adds r0, r4, #0
	bl FUN_081c70c8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081C5D3A
_081C5D0C:
	movs r1, #8
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C5D2C
	movs r0, #1
	b _081C5D2E
	.align 2, 0
_081C5D20: .4byte 0x000006C2
_081C5D24: .4byte 0x000001DF
_081C5D28: .4byte 0x00000222
_081C5D2C:
	movs r0, #0
_081C5D2E:
	cmp r0, #0
	bne _081C5DAA
	adds r0, r4, #0
	bl FUN_081c7228
	b _081C5DAA
_081C5D3A:
	adds r0, r4, #0
	bl FUN_081c6048
	b _081C5D9A
_081C5D42:
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r2, r6, r3
	movs r1, #0xd
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #1
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	strb r7, [r0]
	ldr r2, _081C5DB0 @ =0x00000469
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _081C5DB4 @ =0x0000046A
	adds r0, r4, r3
	strb r7, [r0]
	adds r6, #0x1c
	adds r0, r4, r6
	str r5, [r0]
	adds r2, #3
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _081C5DB8 @ =FUN_080e48d0
	movs r2, #0x10
	subs r6, #0x17
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _081C5DBC @ =0x0000046B
	adds r0, r4, r1
	strb r7, [r0]
	adds r6, #0xe6
	adds r0, r4, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r5, [r0]
_081C5D9A:
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081C5DAA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C5DB0: .4byte 0x00000469
_081C5DB4: .4byte 0x0000046A
_081C5DB8: .4byte FUN_080e48d0
_081C5DBC: .4byte 0x0000046B

	thumb_func_start FUN_081c5dc0
FUN_081c5dc0: @ 0x081C5DC0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r6, r5, r0
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081C5DE0
	b _081C6034
_081C5DE0:
	movs r1, #3
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r7, _081C5EAC @ =0x00000469
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _081C5EB0 @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r4, [r0]
	adds r7, #3
	adds r0, r5, r7
	strb r2, [r0]
	ldr r3, _081C5EB4 @ =FUN_080e6794
	movs r1, #0xe
	adds r7, #1
	adds r0, r5, r7
	strb r2, [r0]
	ldr r2, _081C5EB8 @ =0x0000046B
	adds r0, r5, r2
	strb r4, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r7, #0
	strh r4, [r0]
	movs r3, #0x80
	mov ip, r3
	ldrh r0, [r6]
	ands r0, r3
	cmp r0, #0
	beq _081C5ED0
	ldr r4, _081C5EBC @ =0x00000482
	adds r1, r5, r4
	movs r0, #2
	strh r0, [r1]
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, [r0]
	movs r2, #0xc
	mov r8, r2
	movs r1, #0x14
	adds r4, #0xd6
	adds r2, r5, r4
	subs r4, #4
	adds r0, r5, r4
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r7, [r0]
	ldr r2, _081C5EC0 @ =0x00000551
	adds r0, r5, r2
	strb r7, [r0]
	ldr r3, _081C5EC4 @ =0x00000552
	adds r0, r5, r3
	mov r4, r8
	strb r4, [r0]
	ldrh r0, [r6]
	mov r6, ip
	ands r0, r6
	cmp r0, #0
	beq _081C5E9C
	ldr r7, _081C5EC8 @ =0x0000024E
	adds r2, r5, r7
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r5, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _081C5E9C
	strh r1, [r2]
_081C5E9C:
	movs r0, #4
	ldr r6, _081C5ECC @ =0x00000222
	adds r2, r5, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _081C5F14
	.align 2, 0
_081C5EAC: .4byte 0x00000469
_081C5EB0: .4byte 0x0000046A
_081C5EB4: .4byte FUN_080e6794
_081C5EB8: .4byte 0x0000046B
_081C5EBC: .4byte 0x00000482
_081C5EC0: .4byte 0x00000551
_081C5EC4: .4byte 0x00000552
_081C5EC8: .4byte 0x0000024E
_081C5ECC: .4byte 0x00000222
_081C5ED0:
	movs r2, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, _081C5F50 @ =0x00000482
	adds r1, r5, r2
	movs r0, #2
	strh r0, [r1]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x3c
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r5, r6
	subs r6, #4
	adds r0, r5, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r7, [r0]
	ldr r2, _081C5F54 @ =0x00000551
	adds r0, r5, r2
	strb r7, [r0]
	ldr r3, _081C5F58 @ =0x00000552
	adds r0, r5, r3
	strb r4, [r0]
_081C5F14:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r6, [r0]
	adds r2, r5, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C5F4C
	cmp r1, #0
	blt _081C5F4C
	ldr r0, _081C5F5C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C5F4C
	ldr r0, _081C5F60 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C5F64
_081C5F4C:
	movs r4, #0
	b _081C5F72
	.align 2, 0
_081C5F50: .4byte 0x00000482
_081C5F54: .4byte 0x00000551
_081C5F58: .4byte 0x00000552
_081C5F5C: .4byte 0x030046A8
_081C5F60: .4byte 0x030046AC
_081C5F64:
	ldr r0, _081C5F84 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081C5F72:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C5F88
	adds r0, #4
	b _081C5F94
	.align 2, 0
_081C5F84: .4byte 0x030046A4
_081C5F88:
	ldr r0, _081C5FA8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C5F94:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081C5FAC
	cmp r3, #2
	beq _081C5FB0
	b _081C5FB4
	.align 2, 0
_081C5FA8: .4byte 0x030046A4
_081C5FAC:
	ldrb r0, [r6, #4]
	b _081C5FB2
_081C5FB0:
	ldrb r0, [r6]
_081C5FB2:
	subs r2, r2, r0
_081C5FB4:
	movs r1, #0
	strh r2, [r6, #2]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r0, [r0]
	strh r1, [r0, #6]
	ldr r7, _081C5FF0 @ =0x000004A4
	adds r0, r5, r7
	ldr r6, [r0]
	adds r7, r5, #0
	adds r7, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081C5FF4
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	b _081C601A
	.align 2, 0
_081C5FF0: .4byte 0x000004A4
_081C5FF4:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081C6014
	cmp r0, #2
	beq _081C6010
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C6010:
	movs r0, #1
	b _081C6024
_081C6014:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
_081C601A:
	ldr r1, _081C6040 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081C6024:
	cmp r0, #0
	bne _081C6034
	ldr r4, _081C6044 @ =0x000005C4
	adds r0, r5, r4
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
_081C6034:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C6040: .4byte 0xFFFFFDFF
_081C6044: .4byte 0x000005C4

	thumb_func_start FUN_081c6048
FUN_081c6048: @ 0x081C6048
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	subs r1, #0xcc
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C6068
	b _081C62FE
_081C6068:
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r0, r5, r3
	adds r2, #0x68
	adds r1, r5, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	blo _081C607C
	b _081C62DE
_081C607C:
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	subs r3, #0xc
	adds r0, r5, r3
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	ldrb r1, [r5, #5]
	subs r1, r0, r1
	cmp r1, #0x80
	ble _081C60C8
	ldr r0, _081C60C4 @ =0xFFFFFF00
	adds r1, r1, r0
	b _081C60D6
	.align 2, 0
_081C60C4: .4byte 0xFFFFFF00
_081C60C8:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081C60D6
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081C60D6:
	adds r0, r1, #0
	cmp r0, #0
	bge _081C60DE
	rsbs r0, r0, #0
_081C60DE:
	adds r3, r0, #0
	cmp r3, #0x17
	ble _081C60E6
	b _081C62BC
_081C60E6:
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #1
	bls _081C60F6
	cmp r0, #4
	bne _081C619C
_081C60F6:
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r3, _081C616C @ =0x000006AC
	adds r1, r6, r3
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _081C6188
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne _081C6188
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r4, [r0]
	ldr r3, _081C6170 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _081C6174 @ =0x0000046A
	adds r0, r5, r6
	strb r4, [r0]
	ldr r1, _081C6178 @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #4
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _081C617C @ =FUN_080e48d0
	movs r2, #0x10
	adds r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081C6180 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	ldr r1, _081C6184 @ =0x082522DC
	adds r0, r5, #0
	movs r2, #0x6f
	bl FUN_080e6768
	b _081C62FE
	.align 2, 0
_081C616C: .4byte 0x000006AC
_081C6170: .4byte 0x00000469
_081C6174: .4byte 0x0000046A
_081C6178: .4byte 0x00000484
_081C617C: .4byte FUN_080e48d0
_081C6180: .4byte 0x0000046B
_081C6184: .4byte 0x082522DC
_081C6188:
	movs r1, #8
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C619A
	b _081C62CC
_081C619A:
	b _081C62D0
_081C619C:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, _081C6210 @ =0x000006AC
	adds r1, r6, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _081C622C
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne _081C622C
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r4, [r0]
	ldr r3, _081C6214 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _081C6218 @ =0x0000046A
	adds r0, r5, r6
	strb r4, [r0]
	ldr r1, _081C621C @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #4
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _081C6220 @ =FUN_080e48d0
	movs r2, #0x10
	adds r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081C6224 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	ldr r1, _081C6228 @ =0x082522DC
	adds r0, r5, #0
	movs r2, #0x7c
	bl FUN_080e6768
	b _081C62FE
	.align 2, 0
_081C6210: .4byte 0x000006AC
_081C6214: .4byte 0x00000469
_081C6218: .4byte 0x0000046A
_081C621C: .4byte 0x00000484
_081C6220: .4byte FUN_080e48d0
_081C6224: .4byte 0x0000046B
_081C6228: .4byte 0x082522DC
_081C622C:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r1, r6, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _081C6188
	cmp r3, #5
	bgt _081C6188
	ldr r3, _081C62A4 @ =0x000006CA
	adds r0, r6, r3
	ldrh r4, [r0]
	cmp r4, #0
	bne _081C6188
	movs r2, #2
	movs r1, #1
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r4, [r0]
	ldr r3, _081C62A8 @ =0x00000469
	adds r0, r5, r3
	strb r2, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r1, [r0]
	ldr r2, _081C62AC @ =0x00000484
	adds r0, r5, r2
	str r4, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r3, _081C62B0 @ =FUN_080e48d0
	movs r2, #0x10
	adds r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081C62B4 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	ldr r1, _081C62B8 @ =0x082522DC
	adds r0, r5, #0
	movs r2, #0x81
	bl FUN_080e6768
	b _081C62FE
	.align 2, 0
_081C62A4: .4byte 0x000006CA
_081C62A8: .4byte 0x00000469
_081C62AC: .4byte 0x00000484
_081C62B0: .4byte FUN_080e48d0
_081C62B4: .4byte 0x0000046B
_081C62B8: .4byte 0x082522DC
_081C62BC:
	movs r1, #8
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C62D0
_081C62CC:
	movs r0, #1
	b _081C62D2
_081C62D0:
	movs r0, #0
_081C62D2:
	cmp r0, #0
	bne _081C62FE
	adds r0, r5, #0
	bl FUN_081c7228
	b _081C62FE
_081C62DE:
	movs r1, #8
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C62F2
	movs r0, #1
	b _081C62F4
_081C62F2:
	movs r0, #0
_081C62F4:
	cmp r0, #0
	bne _081C62FE
	adds r0, r5, #0
	bl FUN_081c7228
_081C62FE:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081c6308
FUN_081c6308: @ 0x081C6308
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r7, r1, #0
	ldrb r0, [r3, #5]
	subs r1, r7, r0
	cmp r1, #0x80
	ble _081C6320
	ldr r0, _081C631C @ =0xFFFFFF00
	adds r1, r1, r0
	b _081C632E
	.align 2, 0
_081C631C: .4byte 0xFFFFFF00
_081C6320:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081C632E
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081C632E:
	cmp r1, #0
	bge _081C6334
	rsbs r1, r1, #0
_081C6334:
	ldr r4, _081C634C @ =0x000001FD
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r1, r0
	blt _081C6348
	ldr r5, _081C6350 @ =0x00000553
	adds r0, r3, r5
	ldrb r0, [r0]
	cmp r0, #2
	bne _081C6354
_081C6348:
	movs r0, #0
	b _081C6402
	.align 2, 0
_081C634C: .4byte 0x000001FD
_081C6350: .4byte 0x00000553
_081C6354:
	ldr r2, _081C63B4 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r4, _081C63B8 @ =0x0000046D
	adds r0, r3, r4
	movs r5, #0
	movs r6, #1
	strb r6, [r0]
	subs r4, #2
	adds r0, r3, r4
	strb r5, [r0]
	adds r4, #0xe8
	adds r0, r3, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r3, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r3, r2
	movs r4, #0
	strh r5, [r0]
	movs r1, #0x80
	subs r2, #0x48
	adds r0, r3, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _081C63C4
	movs r1, #0xd
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r3, r2
	strb r4, [r0]
	adds r2, #1
	adds r0, r3, r2
	strb r4, [r0]
	ldr r4, _081C63BC @ =0x0000046A
	adds r0, r3, r4
	strb r1, [r0]
	ldr r1, _081C63C0 @ =0x00000484
	adds r0, r3, r1
	str r5, [r0]
	adds r2, #3
	adds r0, r3, r2
	b _081C63E4
	.align 2, 0
_081C63B4: .4byte FUN_080e48d0
_081C63B8: .4byte 0x0000046D
_081C63BC: .4byte 0x0000046A
_081C63C0: .4byte 0x00000484
_081C63C4:
	movs r1, #6
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r3, r5
	strb r4, [r0]
	adds r5, #1
	adds r0, r3, r5
	strb r4, [r0]
	ldr r4, _081C6408 @ =0x0000046A
	adds r0, r3, r4
	strb r1, [r0]
	adds r5, #0x1b
	adds r0, r3, r5
	str r2, [r0]
	ldr r1, _081C640C @ =0x0000046C
	adds r0, r3, r1
_081C63E4:
	strb r6, [r0]
	lsls r0, r7, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	movs r2, #0xee
	lsls r2, r2, #1
	adds r0, r3, r2
	strb r1, [r0]
	movs r0, #1
_081C6402:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081C6408: .4byte 0x0000046A
_081C640C: .4byte 0x0000046C

	thumb_func_start FUN_081c6410
FUN_081c6410: @ 0x081C6410
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xe
	movs r2, #1
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xb
	movs r2, #2
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #3
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0xd
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #5
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #5
	movs r2, #6
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #7
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #8
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #3
	movs r2, #9
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #6
	movs r2, #0xa
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0xb
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0xc
	movs r3, #0
	bl FUN_080ef84c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081c64b4
FUN_081c64b4: @ 0x081C64B4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r1, r0, r2
	movs r3, #0
	str r3, [r1]
	adds r2, #0x18
	adds r1, r0, r2
	movs r5, #0
	strh r3, [r1]
	movs r1, #0xda
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, _081C653C @ =0x0000FFFF
	strh r1, [r2]
	ldr r2, _081C6540 @ =0x000006D4
	adds r1, r0, r2
	strh r3, [r1]
	adds r2, #2
	adds r1, r0, r2
	strb r5, [r1]
	adds r2, #1
	adds r1, r0, r2
	strb r5, [r1]
	movs r1, #0xe1
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #8
	bl ClearMemory
	adds r0, r4, #0
	bl FUN_080e6204
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r0, [r4, #0x44]
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081C6544
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081C654C
	.align 2, 0
_081C653C: .4byte 0x0000FFFF
_081C6540: .4byte 0x000006D4
_081C6544:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081C654C:
	str r0, [r5]
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
	beq _081C6570
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081C6578
_081C6570:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081C6578:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081C65B0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081C65E8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081C65B4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081C65A8
	ldrb r0, [r4, #5]
_081C65A8:
	subs r0, #1
	strh r0, [r4, #8]
	b _081C65C4
	.align 2, 0
_081C65B0: .4byte 0x0000FFFF
_081C65B4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081C65C4
	strh r1, [r4, #8]
_081C65C4:
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
	bne _081C65E8
	movs r0, #1
	strb r0, [r4, #7]
_081C65E8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081c65f0
FUN_081c65f0: @ 0x081C65F0
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #3
	rsbs r2, r2, #0
	ldr r1, [r0]
	ands r1, r2
	str r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_081c6604
FUN_081c6604: @ 0x081C6604
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x54
	mov ip, r0
	ldr r0, [r0, #0x44]
	adds r0, #0x48
	mov sb, r0
	ldrh r0, [r0, #0xe]
	cmp r0, #0
	beq _081C6620
	b _081C67E8
_081C6620:
	movs r1, #0x80
	movs r0, #0xc0
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	rsbs r0, r0, #0
	lsrs r0, r0, #0x1f
	mov sl, r0
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, #0xfc
	add r1, ip
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x90
	lsls r0, r0, #3
	add r0, ip
	ldrh r0, [r0]
	cmp r0, #2
	beq _081C6652
	b _081C67AE
_081C6652:
	mov r1, sb
	ldrh r0, [r1, #8]
	cmp r0, #7
	beq _081C6664
	cmp r0, #5
	beq _081C6664
	cmp r0, #1
	beq _081C6664
	b _081C67AE
_081C6664:
	ldr r2, _081C66F8 @ =0x0203B400
	mov r8, r2
	ldr r6, _081C66FC @ =0x030046B8
	ldr r2, [r6]
	adds r2, #1
	ldr r3, _081C6700 @ =0x000003FF
	ands r2, r3
	lsls r0, r2, #1
	add r0, r8
	ldrh r1, [r0]
	movs r4, #0x3f
	ands r1, r4
	subs r1, #0x30
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r5, _081C6704 @ =0xFFFF0000
	ldr r0, [sp, #0x3c]
	ands r0, r5
	orrs r0, r1
	str r0, [sp, #0x3c]
	adds r2, #1
	ands r2, r3
	str r2, [r6]
	lsls r2, r2, #1
	add r2, r8
	ldrh r1, [r2]
	ands r1, r4
	subs r1, #0x30
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r2, sp, #0x3c
	ldr r0, [r2, #4]
	ands r0, r5
	orrs r0, r1
	str r0, [r2, #4]
	mov r1, ip
	adds r1, #8
	ldrh r0, [r2]
	mov r3, ip
	ldrh r3, [r3, #8]
	adds r0, r0, r3
	strh r0, [r2]
	ldrh r0, [r2, #2]
	ldrh r4, [r1, #2]
	adds r0, r0, r4
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	mov r1, ip
	ldrb r0, [r1, #5]
	adds r4, r0, #0
	adds r4, #0x80
	movs r1, #0xff
	add r6, sp, #0x44
	ands r4, r1
	movs r5, #0x50
	ldr r3, _081C6708 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	adds r7, r2, #0
	mov r8, r6
	cmp r0, #0
	blt _081C670C
	asrs r1, r0, #0xc
	b _081C6712
	.align 2, 0
_081C66F8: .4byte 0x0203B400
_081C66FC: .4byte 0x030046B8
_081C6700: .4byte 0x000003FF
_081C6704: .4byte 0xFFFF0000
_081C6708: .4byte 0x085B0A08
_081C670C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081C6712:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	lsls r0, r4, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081C672A
	asrs r0, r0, #0xc
	b _081C6730
_081C672A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081C6730:
	movs r5, #0
	strh r0, [r6, #4]
	add r2, sp, #0x44
	add r1, sp, #0x3c
	ldrh r0, [r1]
	ldrh r2, [r2]
	adds r0, r0, r2
	strh r0, [r1]
	ldrh r0, [r7, #4]
	mov r3, r8
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r7, #4]
	mov r4, ip
	ldrh r0, [r4, #0xa]
	strh r0, [r7, #2]
	add r6, sp, #0x4c
	str r5, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r6, #0
	ldr r2, _081C67C8 @ =0x05000002
	bl CpuSet
	ldr r2, _081C67CC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081C67D0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081C67D4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x3f
	ands r1, r0
	adds r1, #0x14
	ldr r2, _081C67D8 @ =0x00001C1A
	ldr r3, _081C67DC @ =0x0000D1B8
	movs r0, #3
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x31
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	movs r4, #1
	str r4, [sp, #0x10]
	str r5, [sp, #0x14]
	str r5, [sp, #0x18]
	str r1, [sp, #0x1c]
	movs r0, #4
	str r0, [sp, #0x20]
	str r4, [sp, #0x24]
	ldr r0, _081C67E0 @ =0x00200004
	str r0, [sp, #0x28]
	movs r0, #0x1e
	str r0, [sp, #0x2c]
	movs r0, #8
	str r0, [sp, #0x30]
	str r0, [sp, #0x34]
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_081f22c0
_081C67AE:
	ldr r2, _081C67E4 @ =0x085AE018
	mov r3, sb
	ldrh r1, [r3, #8]
	movs r0, #7
	ands r0, r1
	lsls r0, r0, #1
	mov r4, sl
	lsls r1, r4, #4
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0]
	b _081C67EA
	.align 2, 0
_081C67C8: .4byte 0x05000002
_081C67CC: .4byte 0x030046B8
_081C67D0: .4byte 0x000003FF
_081C67D4: .4byte 0x0203B400
_081C67D8: .4byte 0x00001C1A
_081C67DC: .4byte 0x0000D1B8
_081C67E0: .4byte 0x00200004
_081C67E4: .4byte 0x085AE018
_081C67E8:
	movs r0, #0
_081C67EA:
	add sp, #0x54
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081c67fc
FUN_081c67fc: @ 0x081C67FC
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xa0
	lsls r1, r1, #2
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C6820
	adds r0, r4, #0
	movs r1, #1
	movs r2, #4
	movs r3, #0
	bl FUN_080ef84c
	b _081C682C
_081C6820:
	adds r0, r4, #0
	movs r1, #1
	movs r2, #3
	movs r3, #0
	bl FUN_080ef84c
_081C682C:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C6846
	ldr r0, _081C684C @ =0x00000482
	adds r1, r4, r0
	movs r0, #2
	strh r0, [r1]
_081C6846:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081C684C: .4byte 0x00000482

	thumb_func_start FUN_081c6850
FUN_081c6850: @ 0x081C6850
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #0x3c
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r4, _081C6924 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r4
	movs r6, #0x40
	orrs r0, r6
	ldr r2, _081C6928 @ =0x0000FFFF
	mov sl, r2
	ands r0, r2
	movs r1, #0x80
	lsls r1, r1, #0x10
	mov r8, r1
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r4
	orrs r0, r6
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r2, sp, #0x14
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _081C692C @ =FUN_081c78ec
	str r5, [sp]
	adds r0, r5, #0
	add r1, sp, #0xc
	bl FUN_080e3834
	ldr r0, [sp, #0x1c]
	ands r0, r4
	orrs r0, r6
	mov r2, sl
	ands r0, r2
	movs r1, #0xf0
	lsls r1, r1, #0xf
	mov sl, r1
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r1, sp, #0x1c
	ldr r0, [r1, #4]
	ands r0, r4
	orrs r0, r6
	str r0, [r1, #4]
	mov r2, r8
	str r2, [sp, #0x24]
	add r2, sp, #0x24
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _081C6930 @ =FUN_081c7584
	movs r0, #0
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r5, #0
	bl FUN_080e3984
	mov r0, sl
	str r0, [sp, #0x2c]
	add r2, sp, #0x2c
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	mov r1, r8
	str r1, [sp, #0x34]
	add r3, sp, #0x34
	ldr r0, [r3, #4]
	ands r0, r4
	str r0, [r3, #4]
	movs r0, #0xcb
	lsls r0, r0, #3
	add sb, r0
	ldr r0, _081C6934 @ =FUN_081c75c4
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	str r5, [sp, #8]
	adds r0, r5, #0
	mov r1, sb
	bl FUN_080e3a14
	movs r0, #0x80
	lsls r0, r0, #1
	mov r2, sb
	ldrh r1, [r2, #6]
	orrs r0, r1
	strh r0, [r2, #6]
	add sp, #0x3c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081C6924: .4byte 0xFFFF0000
_081C6928: .4byte 0x0000FFFF
_081C692C: .4byte FUN_081c78ec
_081C6930: .4byte FUN_081c7584
_081C6934: .4byte FUN_081c75c4

	thumb_func_start FUN_081c6938
FUN_081c6938: @ 0x081C6938
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081C6954
	b _081C6BA0
_081C6954:
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	ldrb r0, [r5, #5]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _081C696E
	asrs r0, r1, #6
	b _081C6974
_081C696E:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081C6974:
	lsls r4, r0, #6
	movs r2, #2
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _081C698C
	movs r0, #1
	b _081C698E
_081C698C:
	movs r0, #0
_081C698E:
	cmp r0, #0
	beq _081C69E8
	ldr r2, _081C69B0 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	adds r3, r2, #0
	cmp r0, #0
	blt _081C69B4
	asrs r2, r0, #0xc
	b _081C69BA
	.align 2, 0
_081C69B0: .4byte 0x085B0A08
_081C69B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081C69BA:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081C69E4 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	cmp r0, #0
	bge _081C6A38
	b _081C6A40
	.align 2, 0
_081C69E4: .4byte 0xFFFF0000
_081C69E8:
	ldr r2, _081C6A08 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	adds r3, r2, #0
	cmp r0, #0
	blt _081C6A0C
	asrs r2, r0, #0xc
	b _081C6A12
	.align 2, 0
_081C6A08: .4byte 0x085B0A08
_081C6A0C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081C6A12:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081C6A3C @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	cmp r0, #0
	blt _081C6A40
_081C6A38:
	asrs r2, r0, #0xc
	b _081C6A46
	.align 2, 0
_081C6A3C: .4byte 0xFFFF0000
_081C6A40:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081C6A46:
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081C6A80 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r6, r1
	mov r1, sp
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _081C6A84 @ =0x0000069A
	adds r0, r6, r1
	strb r4, [r0]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	cmp r4, #0
	blt _081C6A88
	asrs r0, r4, #6
	b _081C6A8E
	.align 2, 0
_081C6A80: .4byte 0xFFFF0000
_081C6A84: .4byte 0x0000069A
_081C6A88:
	rsbs r0, r4, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081C6A8E:
	cmp r0, #1
	beq _081C6AEC
	cmp r0, #1
	bgt _081C6A9C
	cmp r0, #0
	beq _081C6AA6
	b _081C6B30
_081C6A9C:
	cmp r0, #2
	beq _081C6AA6
	cmp r0, #3
	beq _081C6AEC
	b _081C6B30
_081C6AA6:
	movs r1, #2
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081C6AB4
	movs r0, #1
	b _081C6AB6
_081C6AB4:
	movs r0, #0
_081C6AB6:
	cmp r0, #0
	beq _081C6AD2
	ldr r3, _081C6AE8 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r1, #0xf0
	orrs r0, r1
	str r0, [sp, #8]
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x80
	orrs r0, r1
	str r0, [r2, #4]
_081C6AD2:
	ldr r3, _081C6AE8 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r3
	movs r1, #0x78
	orrs r0, r1
	str r0, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x40
	b _081C6B2C
	.align 2, 0
_081C6AE8: .4byte 0xFFFF0000
_081C6AEC:
	movs r1, #2
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081C6AFA
	movs r0, #1
	b _081C6AFC
_081C6AFA:
	movs r0, #0
_081C6AFC:
	cmp r0, #0
	beq _081C6B18
	ldr r3, _081C6B78 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r1, #0x80
	orrs r0, r1
	str r0, [sp, #8]
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0xf0
	orrs r0, r1
	str r0, [r2, #4]
_081C6B18:
	ldr r3, _081C6B78 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r3
	movs r1, #0x40
	orrs r0, r1
	str r0, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x78
_081C6B2C:
	orrs r0, r1
	str r0, [r2, #4]
_081C6B30:
	ldr r1, _081C6B7C @ =0x0000FFFF
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x10]
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [sp, #0x10]
	ldr r2, [sp, #0x14]
	str r1, [r0, #0x1c]
	str r2, [r0, #0x20]
	mov r1, sp
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	adds r0, #0xd8
	ldr r1, [sp, #0x10]
	ldr r2, [sp, #0x14]
	str r1, [r0, #0x1c]
	str r2, [r0, #0x20]
	mov r1, sp
	movs r2, #0
	bl FUN_082364c4
	movs r1, #2
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081C6B80
	movs r0, #1
	b _081C6B82
	.align 2, 0
_081C6B78: .4byte 0xFFFF0000
_081C6B7C: .4byte 0x0000FFFF
_081C6B80:
	movs r0, #0
_081C6B82:
	cmp r0, #0
	beq _081C6B92
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r2, r6, r0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	b _081C6B9C
_081C6B92:
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r2, r6, r1
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
_081C6B9C:
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
_081C6BA0:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081c6ba8
FUN_081c6ba8: @ 0x081C6BA8
	push {lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r2, [r0]
	movs r0, #0xd9
	lsls r0, r0, #3
	adds r1, r2, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081C6BC2
	subs r0, #1
	strh r0, [r1]
_081C6BC2:
	ldr r0, _081C6BD4 @ =0x000006CA
	adds r1, r2, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081C6BD0
	subs r0, #1
	strh r0, [r1]
_081C6BD0:
	pop {r0}
	bx r0
	.align 2, 0
_081C6BD4: .4byte 0x000006CA

	thumb_func_start FUN_081c6bd8
FUN_081c6bd8: @ 0x081C6BD8
	push {lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, _081C6BF4 @ =0x000006C6
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081C6BF0
	subs r0, #1
	strh r0, [r1]
_081C6BF0:
	pop {r0}
	bx r0
	.align 2, 0
_081C6BF4: .4byte 0x000006C6

	thumb_func_start FUN_081c6bf8
FUN_081c6bf8: @ 0x081C6BF8
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081C6CE0
	ldr r0, _081C6C4C @ =0x0000E33F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r2, [r1]
	ands r0, r2
	cmp r0, #0
	bne _081C6CE0
	movs r1, #0x10
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081C6CE0
	ldr r1, _081C6C50 @ =0x00000553
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bhi _081C6CE0
	movs r3, #0xd8
	lsls r3, r3, #3
	adds r1, r5, r3
	ldrh r0, [r1]
	cmp r0, #0
	beq _081C6C54
	subs r0, #1
	strh r0, [r1]
	b _081C6CE0
	.align 2, 0
_081C6C4C: .4byte 0x0000E33F
_081C6C50: .4byte 0x00000553
_081C6C54:
	movs r0, #0x80
	ands r2, r0
	cmp r2, #0
	beq _081C6C68
	ldr r2, _081C6C64 @ =0x000006C4
	adds r0, r5, r2
	b _081C6C6C
	.align 2, 0
_081C6C64: .4byte 0x000006C4
_081C6C68:
	ldr r3, _081C6C98 @ =0x000006C2
	adds r0, r5, r3
_081C6C6C:
	ldrh r0, [r0]
	strh r0, [r1]
	movs r2, #1
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r0, r0, r3
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _081C6C9C
	movs r0, #1
	b _081C6C9E
	.align 2, 0
_081C6C98: .4byte 0x000006C2
_081C6C9C:
	movs r0, #0
_081C6C9E:
	cmp r0, #0
	beq _081C6CE0
	movs r2, #0xf
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081C6CE8 @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _081C6CEC @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r1, r1, r2
	movs r2, #2
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
_081C6CE0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081C6CE8: .4byte 0x00000469
_081C6CEC: .4byte 0x00000484

	thumb_func_start FUN_081c6cf0
FUN_081c6cf0: @ 0x081C6CF0
	push {lr}
	sub sp, #0x30
	adds r2, r0, #0
	movs r1, #0x80
	lsls r1, r1, #0xc
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r0, r2, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081C6DA0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r1, [r0]
	adds r3, #0x1c
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _081C6DA0
	movs r3, #8
	ldrsh r0, [r2, r3]
	str r0, [sp]
	movs r3, #0xa
	ldrsh r0, [r2, r3]
	str r0, [sp, #4]
	movs r3, #0xc
	ldrsh r0, [r2, r3]
	str r0, [sp, #8]
	movs r3, #0xce
	lsls r3, r3, #1
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [sp, #0xc]
	adds r3, #4
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [sp, #0x10]
	adds r3, #4
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r3, #0xda
	lsls r3, r3, #3
	adds r0, r1, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bge _081C6D5C
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #0x18]
	b _081C6D6E
_081C6D5C:
	ldr r3, _081C6DA8 @ =0x000006D2
	adds r0, r1, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp, #0x18]
	ldr r3, _081C6DAC @ =0x000006D4
	adds r0, r1, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
_081C6D6E:
	str r0, [sp, #0x1c]
	ldr r3, _081C6DB0 @ =0x000001DF
	adds r0, r2, r3
	ldrb r0, [r0]
	str r0, [sp, #0x20]
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r2, r1
	ldrh r0, [r0]
	str r0, [sp, #0x24]
	ldr r1, _081C6DB4 @ =0xFFFF0000
	ldr r0, [sp, #0x28]
	ands r0, r1
	movs r1, #0xa
	orrs r0, r1
	str r0, [sp, #0x28]
	add r1, sp, #0x28
	mov r3, sp
	str r3, [r1, #4]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r0, [r0]
	bl Script_ExecById
_081C6DA0:
	add sp, #0x30
	pop {r0}
	bx r0
	.align 2, 0
_081C6DA8: .4byte 0x000006D2
_081C6DAC: .4byte 0x000006D4
_081C6DB0: .4byte 0x000001DF
_081C6DB4: .4byte 0xFFFF0000

	thumb_func_start FUN_081c6db8
FUN_081c6db8: @ 0x081C6DB8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov sb, r0
	str r1, [sp, #8]
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r1, _081C6DFC @ =0x00000256
	add r1, sb
	str r1, [sp, #0x14]
	mov r2, sb
	adds r2, #8
	str r2, [sp, #0x1c]
	str r2, [sp, #0x18]
	ldr r0, _081C6E00 @ =0x030046A4
	mov sl, r0
_081C6DE8:
	ldr r1, [sp, #0x14]
	ldrh r6, [r1]
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C6E04
	adds r0, #4
	b _081C6E10
	.align 2, 0
_081C6DFC: .4byte 0x00000256
_081C6E00: .4byte 0x030046A4
_081C6E04:
	mov r2, sl
	ldr r0, [r2]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081C6E10:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081C6E24
	cmp r3, #2
	beq _081C6E2A
	b _081C6E30
_081C6E24:
	ldr r1, [sp, #0x18]
	ldrb r0, [r1, #4]
	b _081C6E2E
_081C6E2A:
	ldr r1, [sp, #0x18]
	ldrb r0, [r1]
_081C6E2E:
	subs r2, r2, r0
_081C6E30:
	mov r8, r2
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C6E42
	adds r0, #4
	b _081C6E4E
_081C6E42:
	mov r2, sl
	ldr r0, [r2]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081C6E4E:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _081C6E60
	asrs r0, r0, #6
	b _081C6E66
_081C6E60:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081C6E66:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _081C6EA4
	cmp r1, #1
	bgt _081C6E78
	cmp r1, #0
	beq _081C6E82
	b _081C6F58
_081C6E78:
	cmp r1, #2
	beq _081C6EE0
	cmp r1, #3
	beq _081C6F02
	b _081C6F58
_081C6E82:
	adds r4, r6, #1
	movs r5, #0
_081C6E86:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081C6EA0
	adds r4, #1
	adds r5, #1
	cmp r5, #1
	blt _081C6E86
_081C6EA0:
	subs r5, r4, #1
	b _081C6F5C
_081C6EA4:
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r6, r0
	movs r5, #0
_081C6EB2:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081C6F3C
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #1
	blt _081C6EB2
	ldr r2, _081C6EDC @ =0x030046A4
	b _081C6F3E
	.align 2, 0
_081C6EDC: .4byte 0x030046A4
_081C6EE0:
	subs r4, r6, #1
	movs r5, #0
_081C6EE4:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081C6EFE
	subs r4, #1
	adds r5, #1
	cmp r5, #1
	blt _081C6EE4
_081C6EFE:
	adds r5, r4, #1
	b _081C6F5C
_081C6F02:
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r6, r0
	movs r5, #0
_081C6F10:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081C6F4A
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	adds r5, #1
	cmp r5, #1
	blt _081C6F10
	ldr r2, _081C6F38 @ =0x030046A4
	b _081C6F4C
	.align 2, 0
_081C6F38: .4byte 0x030046A4
_081C6F3C:
	mov r2, sl
_081C6F3E:
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r4, r0
	b _081C6F5C
_081C6F4A:
	mov r2, sl
_081C6F4C:
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r5, r4, r0
	b _081C6F5C
_081C6F58:
	ldr r2, [sp, #0x14]
	ldrh r5, [r2]
_081C6F5C:
	ldr r0, [sp, #0x14]
	ldrh r0, [r0]
	cmp r5, r0
	bne _081C6F98
	ldr r1, [sp, #0xc]
	ldr r2, _081C6F80 @ =0x000006D6
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _081C6F84
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x40
	strb r0, [r1, #5]
	b _081C6F8C
	.align 2, 0
_081C6F80: .4byte 0x000006D6
_081C6F84:
	mov r2, sb
	ldrb r0, [r2, #5]
	subs r0, #0x40
	strb r0, [r2, #5]
_081C6F8C:
	ldr r0, [sp, #0x10]
	adds r0, #1
	str r0, [sp, #0x10]
	cmp r0, #3
	bgt _081C6F98
	b _081C6DE8
_081C6F98:
	ldr r2, _081C6FBC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081C6FC0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081C6FC4 @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _081C6FCC
	ldr r2, [sp, #0xc]
	ldr r0, _081C6FC8 @ =0x000006D6
	adds r1, r2, r0
	movs r0, #1
	b _081C6FD4
	.align 2, 0
_081C6FBC: .4byte 0x030046B8
_081C6FC0: .4byte 0x000003FF
_081C6FC4: .4byte 0x0203B400
_081C6FC8: .4byte 0x000006D6
_081C6FCC:
	ldr r2, [sp, #0xc]
	ldr r0, _081C701C @ =0x000006D6
	adds r1, r2, r0
	movs r0, #0
_081C6FD4:
	strb r0, [r1]
	mov r1, sp
	ldrb r2, [r1, #8]
	mov r1, sb
	strb r2, [r1, #5]
	mov r8, sp
	ldr r6, _081C7020 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C7024
	adds r0, #4
	b _081C702E
	.align 2, 0
_081C701C: .4byte 0x000006D6
_081C7020: .4byte 0x030046A4
_081C7024:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081C702E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldr r0, _081C7074 @ =0x000004A4
	add r0, sb
	ldr r4, [r0]
	adds r0, r4, #0
	ldr r1, [sp, #0x1c]
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	beq _081C7078
	adds r0, r4, #0
	ldr r1, [sp, #0x1c]
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081C7078
	cmp r0, #2
	beq _081C7070
	mov r0, sb
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C7070:
	movs r0, #1
	b _081C7088
	.align 2, 0
_081C7074: .4byte 0x000004A4
_081C7078:
	movs r0, #0xc0
	lsls r0, r0, #1
	add r0, sb
	ldr r1, _081C709C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081C7088:
	cmp r0, #0
	beq _081C70A4
	ldr r2, [sp, #0xc]
	ldr r0, _081C70A0 @ =0x000006D7
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #1
	b _081C70B2
	.align 2, 0
_081C709C: .4byte 0xFFFFFDFF
_081C70A0: .4byte 0x000006D7
_081C70A4:
	ldr r0, _081C70C4 @ =0x000005C4
	add r0, sb
	ldr r1, [r0]
	mov r0, sb
	bl _call_via_r1
	movs r0, #0
_081C70B2:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081C70C4: .4byte 0x000005C4

	thumb_func_start FUN_081c70c8
FUN_081c70c8: @ 0x081C70C8
	push {lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r1, [r1]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #1
	bls _081C70E2
	cmp r0, #4
	bne _081C70E8
_081C70E2:
	movs r2, #0xd9
	lsls r2, r2, #3
	b _081C70F6
_081C70E8:
	movs r2, #0xd9
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _081C70FE
	adds r2, #2
_081C70F6:
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _081C7102
_081C70FE:
	movs r0, #1
	b _081C7104
_081C7102:
	movs r0, #0
_081C7104:
	pop {r1}
	bx r1

	thumb_func_start FUN_081c7108
FUN_081c7108: @ 0x081C7108
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0xea
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r0, [r4]
	cmp r0, #0
	ble _081C7204
	adds r0, r5, #0
	bl FUN_080f00ec
	ldr r1, _081C7184 @ =0x00000222
	adds r2, r5, r1
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #0x14
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrh r0, [r4]
	bl FUN_080f8d60
	movs r2, #0xec
	lsls r2, r2, #1
	adds r1, r5, r2
	str r0, [r1]
	ldrh r1, [r0, #8]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C717E
	cmp r1, #0
	blt _081C717E
	ldr r0, _081C7188 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C717E
	ldr r0, _081C718C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C7190
_081C717E:
	movs r1, #0
	b _081C719E
	.align 2, 0
_081C7184: .4byte 0x00000222
_081C7188: .4byte 0x030046A8
_081C718C: .4byte 0x030046AC
_081C7190:
	ldr r0, _081C71FC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081C719E:
	ldr r3, _081C7200 @ =0x0000025E
	adds r0, r5, r3
	strh r1, [r0]
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	strb r0, [r5, #5]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r1, r1, r2
	movs r2, #0xd
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r0, #1
	b _081C721C
	.align 2, 0
_081C71FC: .4byte 0x030046A4
_081C7200: .4byte 0x0000025E
_081C7204:
	movs r0, #8
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r3, [r1]
	ands r0, r3
	cmp r0, #0
	beq _081C721A
	ldr r0, _081C7224 @ =0xF7FFFFFF
	ands r3, r0
	str r3, [r1]
_081C721A:
	movs r0, #0
_081C721C:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081C7224: .4byte 0xF7FFFFFF

	thumb_func_start FUN_081c7228
FUN_081c7228: @ 0x081C7228
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r1, _081C72DC @ =0x082522DC
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r5, #0
	bl FUN_080e6768
	ldr r2, _081C72E0 @ =0x000006D7
	adds r6, r4, r2
	ldrb r0, [r6]
	cmp r0, #3
	bls _081C724C
	b _081C7450
_081C724C:
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r2, #0xd7
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	blo _081C726C
	adds r0, r5, #0
	bl FUN_081c70c8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081C72F4
_081C726C:
	ldrb r0, [r6]
	cmp r0, #3
	bhi _081C72F4
	ldrb r1, [r5, #5]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r0, #0x80
	movs r4, #0
	strb r0, [r5, #5]
	adds r0, r5, #0
	bl FUN_081c6db8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081C7290
	b _081C749C
_081C7290:
	ldr r2, _081C72E4 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r6, _081C72E8 @ =0x0000046D
	adds r0, r5, r6
	movs r3, #1
	strb r3, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r1, #0
	strh r4, [r0]
	movs r2, #0x11
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081C72EC @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _081C72F0 @ =0x00000484
	adds r0, r5, r2
	str r4, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r3, [r0]
	b _081C749C
	.align 2, 0
_081C72DC: .4byte 0x082522DC
_081C72E0: .4byte 0x000006D7
_081C72E4: .4byte FUN_080e48d0
_081C72E8: .4byte 0x0000046D
_081C72EC: .4byte 0x0000046A
_081C72F0: .4byte 0x00000484
_081C72F4:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, _081C733C @ =0x000006BC
	adds r1, r4, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhi _081C7308
	b _081C7450
_081C7308:
	ldr r3, _081C7340 @ =0x00000553
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0x1a
	bne _081C7314
	b _081C749C
_081C7314:
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r0, [r0]
	ldr r1, _081C7344 @ =0x00FFFFFF
	ands r0, r1
	movs r1, #0xc0
	lsls r1, r1, #0xc
	cmp r0, r1
	bne _081C732A
	b _081C749C
_081C732A:
	ldr r0, _081C7348 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C734C
	movs r0, #1
	b _081C734E
	.align 2, 0
_081C733C: .4byte 0x000006BC
_081C7340: .4byte 0x00000553
_081C7344: .4byte 0x00FFFFFF
_081C7348: .4byte 0x030047A4
_081C734C:
	movs r0, #0
_081C734E:
	cmp r0, #0
	beq _081C7362
	adds r0, r5, #0
	bl FUN_080faa98
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081C7360
	b _081C749C
_081C7360:
	b _081C7370
_081C7362:
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, _081C739C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
_081C7370:
	ldr r1, _081C73A0 @ =0x000004A4
	adds r0, r5, r1
	ldr r6, [r0]
	adds r7, r5, #0
	adds r7, #8
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081C73A4
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	b _081C73CA
	.align 2, 0
_081C739C: .4byte 0x03002BE0
_081C73A0: .4byte 0x000004A4
_081C73A4:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081C73C4
	cmp r0, #2
	beq _081C73C0
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C73C0:
	movs r0, #1
	b _081C73D4
_081C73C4:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r5, r6
_081C73CA:
	ldr r1, _081C73E8 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081C73D4:
	cmp r0, #0
	bne _081C73F0
	ldr r1, _081C73EC @ =0x000005C4
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	b _081C749C
	.align 2, 0
_081C73E8: .4byte 0xFFFFFDFF
_081C73EC: .4byte 0x000005C4
_081C73F0:
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _081C7444 @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081C7448 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _081C744C @ =0x00000484
	adds r0, r5, r3
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r4, [r0]
	b _081C749C
	.align 2, 0
_081C7444: .4byte 0x0000046D
_081C7448: .4byte 0x0000046A
_081C744C: .4byte 0x00000484
_081C7450:
	movs r2, #3
	movs r1, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r3, #0
	strb r2, [r0]
	ldr r6, _081C74A4 @ =0x00000469
	adds r0, r5, r6
	strb r1, [r0]
	ldr r2, _081C74A8 @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r3, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	ldr r4, _081C74AC @ =FUN_081ca14c
	movs r2, #0x2a
	subs r6, #0x17
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081C74B0 @ =0x0000046B
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r3, [r0]
_081C749C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C74A4: .4byte 0x00000469
_081C74A8: .4byte 0x0000046A
_081C74AC: .4byte FUN_081ca14c
_081C74B0: .4byte 0x0000046B

	thumb_func_start FUN_081c74b4
FUN_081c74b4: @ 0x081C74B4
	push {lr}
	movs r2, #0xdb
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C74C6
	subs r0, #1
	strb r0, [r1]
_081C74C6:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081c74cc
FUN_081c74cc: @ 0x081C74CC
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	mov ip, r0
	ldr r4, _081C7514 @ =0x0203B400
	ldr r3, _081C7518 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _081C751C @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r7, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r4, [r0]
	movs r0, #0x1f
	add r6, sp, #4
	ands r4, r0
	ldr r1, _081C7520 @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _081C7524
	asrs r2, r0, #0xc
	b _081C752A
	.align 2, 0
_081C7514: .4byte 0x0203B400
_081C7518: .4byte 0x030046B8
_081C751C: .4byte 0x000003FF
_081C7520: .4byte 0x085B0A08
_081C7524:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081C752A:
	movs r0, #0
	strh r2, [r6]
	strh r0, [r6, #2]
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081C7542
	asrs r0, r0, #0xc
	b _081C7548
_081C7542:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081C7548:
	strh r0, [r6, #4]
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _081C757C @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _081C7580 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	subs r0, #0x30
	add r1, sp, #4
	strh r0, [r1, #2]
	movs r0, #3
	str r0, [sp]
	mov r0, ip
	movs r2, #0x3c
	movs r3, #3
	bl FUN_081ee090
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C757C: .4byte 0x000003FF
_081C7580: .4byte 0x0203B400

	thumb_func_start FUN_081c7584
FUN_081c7584: @ 0x081C7584
	push {r4, r5, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081C75B8
	ldrh r1, [r5, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _081C75B8
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r5, #4]
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r1, _081C75C0 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081C75B8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081C75C0: .4byte 0xFEFFFFFF

	thumb_func_start FUN_081c75c4
FUN_081c75c4: @ 0x081C75C4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x28
	mov sb, r0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r6, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081C75EE
	b _081C78DE
_081C75EE:
	mov r2, sb
	ldr r0, [r2, #0x24]
	ldr r1, [r2, #0x28]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldrb r0, [r6, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	cmp r0, #1
	beq _081C7628
	cmp r0, #1
	bgt _081C7610
	cmp r0, #0
	beq _081C761A
	b _081C7670
_081C7610:
	cmp r0, #2
	beq _081C7638
	cmp r0, #3
	beq _081C7658
	b _081C7670
_081C761A:
	add r0, sp, #0x10
	ldrh r1, [r0]
	ldr r3, _081C7624 @ =0xFFFFFF00
	adds r1, r1, r3
	b _081C7642
	.align 2, 0
_081C7624: .4byte 0xFFFFFF00
_081C7628:
	add r0, sp, #0x10
	ldrh r1, [r0, #4]
	ldr r0, _081C7634 @ =0xFFFFFF00
	adds r1, r1, r0
	b _081C7662
	.align 2, 0
_081C7634: .4byte 0xFFFFFF00
_081C7638:
	add r0, sp, #0x10
	ldrh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081C7642:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081C7654 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	b _081C7670
	.align 2, 0
_081C7654: .4byte 0xFFFF0000
_081C7658:
	add r0, sp, #0x10
	ldrh r1, [r0, #4]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r1, r3
_081C7662:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081C76E4 @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
_081C7670:
	add r2, sp, #0x18
	add r4, sp, #0x10
	adds r3, r5, #0
	adds r3, #0x24
	ldrh r0, [r5, #0x24]
	adds r1, r4, #0
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	mov r1, sb
	adds r1, #0x42
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081C76D2
	ldrh r1, [r5, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _081C76D2
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrh r0, [r5, #4]
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r7, r1
	ldr r1, _081C76E8 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081C76D2:
	ldr r0, _081C76EC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C76F0
	movs r0, #1
	b _081C76F2
	.align 2, 0
_081C76E4: .4byte 0xFFFF0000
_081C76E8: .4byte 0xFEFFFFFF
_081C76EC: .4byte 0x030047A4
_081C76F0:
	movs r0, #0
_081C76F2:
	cmp r0, #0
	beq _081C76F8
	b _081C78DE
_081C76F8:
	ldrh r0, [r5, #0xa]
	cmp r0, #1
	beq _081C7700
	b _081C78DE
_081C7700:
	movs r5, #0xda
	lsls r5, r5, #3
	add r5, r8
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmp r0, #0
	blt _081C7710
	b _081C78DE
_081C7710:
	movs r3, #0x90
	lsls r3, r3, #3
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _081C7722
	cmp r0, #4
	beq _081C7722
	b _081C78DE
_081C7722:
	ldr r0, _081C7784 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r2, [sp, #0x20]
	asrs r1, r2, #0x10
	adds r1, #0xc8
	lsls r1, r1, #0x10
	ldr r0, _081C7788 @ =0x0000FFFF
	mov sb, r0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
	ldr r4, _081C778C @ =0x000006D2
	add r4, r8
	ldr r2, _081C7790 @ =0x000006D4
	add r2, r8
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080ec438
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081C7758
	b _081C78DE
_081C7758:
	movs r2, #0
	ldrsh r1, [r4, r2]
	add r0, sp, #0x20
	str r0, [sp]
	adds r0, r6, #0
	adds r0, #8
	str r0, [sp, #4]
	movs r0, #0x18
	str r0, [sp, #8]
	str r7, [sp, #0xc]
	movs r0, #0
	movs r2, #3
	movs r3, #0
	bl FUN_080177b4
	cmp r0, #0
	bge _081C7794
	ldrh r1, [r5]
	mov r0, sb
	orrs r0, r1
	strh r0, [r5]
	b _081C78DE
	.align 2, 0
_081C7784: .4byte 0x03002BE0
_081C7788: .4byte 0x0000FFFF
_081C778C: .4byte 0x000006D2
_081C7790: .4byte 0x000006D4
_081C7794:
	movs r3, #0
	ldrsh r0, [r5, r3]
	bl RemoveItem
	movs r0, #0
	ldrsh r1, [r4, r0]
	cmp r1, #0xb
	beq _081C77B8
	cmp r1, #0xb
	bgt _081C77AE
	cmp r1, #8
	beq _081C77B8
	b _081C78DE
_081C77AE:
	cmp r1, #0xe
	beq _081C77B8
	cmp r1, #0x11
	beq _081C77B8
	b _081C78DE
_081C77B8:
	movs r1, #0x95
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r1, [r0]
	ldr r0, _081C77E8 @ =0x000006D9
	add r0, r8
	ldrb r0, [r0]
	muls r0, r1, r0
	movs r1, #0x64
	bl Div
	adds r1, r0, #0
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r2, r6, r3
	movs r3, #0
	ldrsh r0, [r2, r3]
	subs r0, r0, r1
	cmp r0, #0
	bgt _081C77F0
	ldrh r1, [r2]
	ldr r2, _081C77EC @ =0x0000048A
	adds r0, r6, r2
	b _081C77F4
	.align 2, 0
_081C77E8: .4byte 0x000006D9
_081C77EC: .4byte 0x0000048A
_081C77F0:
	ldr r3, _081C7870 @ =0x0000048A
	adds r0, r6, r3
_081C77F4:
	strh r1, [r0]
	movs r1, #0xda
	lsls r1, r1, #3
	add r1, r8
	ldr r0, _081C7874 @ =0x0000FFFF
	strh r0, [r1]
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r4, _081C7878 @ =0x03002BE0
	ldr r0, [r4]
	adds r0, #0x24
	str r0, [r1]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r3, #1
	str r3, [r0]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	movs r1, #0
	str r1, [r0]
	adds r2, #4
	adds r0, r6, r2
	str r1, [r0]
	subs r2, #4
	adds r0, r6, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r6, r2
	str r1, [r0]
	ldr r1, _081C7870 @ =0x0000048A
	adds r0, r6, r1
	ldrh r0, [r0]
	movs r2, #0x8b
	lsls r2, r2, #1
	adds r1, r6, r2
	strh r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #1
	strh r3, [r0]
	movs r3, #0x8e
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r0, #0x1e
	strh r0, [r1]
	ldr r1, _081C787C @ =0x0000048C
	adds r0, r6, r1
	strb r2, [r0]
	movs r1, #2
	ldr r2, _081C7880 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C7884
	movs r0, #1
	b _081C7886
	.align 2, 0
_081C7870: .4byte 0x0000048A
_081C7874: .4byte 0x0000FFFF
_081C7878: .4byte 0x03002BE0
_081C787C: .4byte 0x0000048C
_081C7880: .4byte 0x00000474
_081C7884:
	movs r0, #0
_081C7886:
	cmp r0, #0
	beq _081C789A
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, [r4]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _081C78A6
_081C789A:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081C78DE
_081C78A6:
	ldr r1, [r0]
	movs r2, #8
	ldrsh r5, [r1, r2]
	movs r3, #8
	ldrsh r0, [r6, r3]
	subs r5, r5, r0
	movs r0, #0xc
	ldrsh r4, [r1, r0]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_081C78DE:
	add sp, #0x28
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081c78ec
FUN_081c78ec: @ 0x081C78EC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	movs r1, #0x80
	lsls r1, r1, #4
	ldrh r0, [r0, #6]
	ands r0, r1
	cmp r0, #0
	beq _081C790C
	b _081C7FA0
_081C790C:
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _081C791C
	b _081C7FA0
_081C791C:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _081C7944
	ldr r3, _081C7940 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C7934
	b _081C7FA0
_081C7934:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _081C7FA0
	.align 2, 0
_081C7940: .4byte 0x0000048C
_081C7944:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _081C7954
	b _081C7FA0
_081C7954:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _081C7964
	b _081C7C70
_081C7964:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _081C7976
	b _081C7FA0
_081C7976:
	ldr r2, _081C7A08 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _081C798A
	b _081C7FA0
_081C798A:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081C7998
	b _081C7FA0
_081C7998:
	movs r0, #0x3c
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0x14
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	bne _081C79B0
	b _081C7AF8
_081C79B0:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _081C7A18
	ands r3, r1
	cmp r3, #0
	beq _081C7A18
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081C79D6
	rsbs r1, r1, #0
_081C79D6:
	cmp r1, #0x20
	bgt _081C7A18
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _081C7A0C @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _081C7A10 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _081C7A14 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _081C7FA0
	.align 2, 0
_081C7A08: .4byte 0x0000A007
_081C7A0C: .4byte 0x000004BE
_081C7A10: .4byte 0x0000048C
_081C7A14: .4byte 0x0000044E
_081C7A18:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _081C7A40 @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081C7A48
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081C7A44 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081C7AB6
	.align 2, 0
_081C7A40: .4byte 0x0000048A
_081C7A44: .4byte 0x03002BE0
_081C7A48:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081C7A64
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081C7A60 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081C7AB6
	.align 2, 0
_081C7A60: .4byte 0x03002BE0
_081C7A64:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081C7A80
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081C7A7C @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081C7AB6
	.align 2, 0
_081C7A7C: .4byte 0x03002BE0
_081C7A80:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081C7A9C
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081C7A98 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081C7AB6
	.align 2, 0
_081C7A98: .4byte 0x03002BE0
_081C7A9C:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081C7AAE
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _081C7AB6
_081C7AAE:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081C7AB8
_081C7AB6:
	movs r3, #1
_081C7AB8:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r5, r8
	ldr r1, [r5, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	ldr r5, _081C7AEC @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _081C7ADA
	b _081C7C30
_081C7ADA:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C7AF0
	movs r0, #1
	b _081C7AF2
	.align 2, 0
_081C7AEC: .4byte 0x0000049C
_081C7AF0:
	movs r0, #0
_081C7AF2:
	cmp r0, #0
	bne _081C7BD6
	b _081C7BEC
_081C7AF8:
	strh r2, [r7, #0x3e]
	ldr r1, _081C7B20 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _081C7B28
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081C7B24 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081C7B96
	.align 2, 0
_081C7B20: .4byte 0x0000048A
_081C7B24: .4byte 0x03002BE0
_081C7B28:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081C7B44
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081C7B40 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081C7B96
	.align 2, 0
_081C7B40: .4byte 0x03002BE0
_081C7B44:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _081C7B60
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081C7B5C @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081C7B96
	.align 2, 0
_081C7B5C: .4byte 0x03002BE0
_081C7B60:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081C7B7C
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081C7B78 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081C7B96
	.align 2, 0
_081C7B78: .4byte 0x03002BE0
_081C7B7C:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081C7B8E
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _081C7B96
_081C7B8E:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081C7B98
_081C7B96:
	movs r3, #1
_081C7B98:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r5, r8
	ldr r1, [r5, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	ldr r5, _081C7BCC @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _081C7C30
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C7BD0
	movs r0, #1
	b _081C7BD2
	.align 2, 0
_081C7BCC: .4byte 0x0000049C
_081C7BD0:
	movs r0, #0
_081C7BD2:
	cmp r0, #0
	beq _081C7BEC
_081C7BD6:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081C7BE8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _081C7BF8
	.align 2, 0
_081C7BE8: .4byte 0x03002BE0
_081C7BEC:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _081C7C30
_081C7BF8:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_081C7C30:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081C7C5C
	ldr r5, _081C7C68 @ =0x0000024E
	adds r2, r6, r5
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _081C7C5C
	strh r1, [r2]
_081C7C5C:
	ldr r5, _081C7C6C @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _081C7FA0
	.align 2, 0
_081C7C68: .4byte 0x0000024E
_081C7C6C: .4byte 0x0000048C
_081C7C70:
	ldr r0, _081C7C84 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C7C88
	movs r0, #1
	b _081C7C8A
	.align 2, 0
_081C7C84: .4byte 0x030047A4
_081C7C88:
	movs r0, #0
_081C7C8A:
	cmp r0, #0
	beq _081C7C98
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236640
	b _081C7CA0
_081C7C98:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236524
_081C7CA0:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _081C7CD8 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _081C7CDC @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _081C7CCE
	cmp r2, #0x17
	bne _081C7CE0
_081C7CCE:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _081C7D02
	.align 2, 0
_081C7CD8: .4byte 0x0000048C
_081C7CDC: .4byte 0x000001DF
_081C7CE0:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _081C7CCE
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _081C7D30 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081C7D02
	movs r1, #0
_081C7D02:
	adds r0, r7, #0
	adds r0, #0x40
	strh r1, [r0]
	mov sb, r0
	movs r2, #6
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _081C7D3E
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _081C7D34
	asrs r0, r0, #1
	b _081C7D3A
	.align 2, 0
_081C7D30: .4byte 0x00000187
_081C7D34:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081C7D3A:
	mov r2, sb
	strh r0, [r2]
_081C7D3E:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081C7D5C
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _081C7D58 @ =0x000001DD
	adds r1, r6, r4
	b _081C7DD0
	.align 2, 0
_081C7D58: .4byte 0x000001DD
_081C7D5C:
	mov r4, sp
	mov r3, r8
	adds r3, #0xc
	adds r2, r7, #0
	adds r2, #0xc
	ldrh r0, [r7, #0xc]
	mov r5, r8
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r4, #4]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _081C7DBC
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _081C7DBC
	ldr r2, _081C7DAC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081C7DB0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081C7DB4 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _081C7DB8 @ =0x000001DD
	adds r1, r6, r4
	b _081C7DD0
	.align 2, 0
_081C7DAC: .4byte 0x030046B8
_081C7DB0: .4byte 0x000003FF
_081C7DB4: .4byte 0x0203B400
_081C7DB8: .4byte 0x000001DD
_081C7DBC:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	ldr r3, _081C7DF0 @ =0x000001DD
	adds r1, r6, r3
_081C7DD0:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081C7DF8
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081C7DF4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081C7E66
	.align 2, 0
_081C7DF0: .4byte 0x000001DD
_081C7DF4: .4byte 0x03002BE0
_081C7DF8:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081C7E14
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081C7E10 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081C7E66
	.align 2, 0
_081C7E10: .4byte 0x03002BE0
_081C7E14:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081C7E30
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081C7E2C @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081C7E66
	.align 2, 0
_081C7E2C: .4byte 0x03002BE0
_081C7E30:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081C7E4C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081C7E48 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081C7E66
	.align 2, 0
_081C7E48: .4byte 0x03002BE0
_081C7E4C:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081C7E5E
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _081C7E66
_081C7E5E:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081C7E68
_081C7E66:
	movs r3, #1
_081C7E68:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	mov r2, r8
	ldr r1, [r2, #0x34]
	ldr r2, [r2, #0x38]
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r6, r4
	str r1, [r0]
	ldr r5, _081C7E9C @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _081C7F04
	movs r1, #2
	ldr r2, _081C7EA0 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C7EA4
	movs r0, #1
	b _081C7EA6
	.align 2, 0
_081C7E9C: .4byte 0x0000049C
_081C7EA0: .4byte 0x00000474
_081C7EA4:
	movs r0, #0
_081C7EA6:
	cmp r0, #0
	beq _081C7EC0
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081C7EBC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _081C7ECC
	.align 2, 0
_081C7EBC: .4byte 0x03002BE0
_081C7EC0:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _081C7F04
_081C7ECC:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_081C7F04:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _081C7F38
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081C7F38
	ldr r0, _081C7F50 @ =0x0000024E
	adds r2, r6, r0
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _081C7F38
	strh r1, [r2]
_081C7F38:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _081C7F54 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _081C7F58 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C7F5C
	movs r0, #1
	b _081C7F5E
	.align 2, 0
_081C7F50: .4byte 0x0000024E
_081C7F54: .4byte 0x030046A0
_081C7F58: .4byte 0x00000934
_081C7F5C:
	movs r0, #0
_081C7F5E:
	ldr r1, _081C7FB0 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _081C7F76
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_081C7F76:
	adds r0, r6, #0
	bl FUN_080e64e4
	ldrh r0, [r7, #0x3e]
	strh r0, [r4]
	movs r4, #0xc4
	lsls r4, r4, #1
	adds r1, r6, r4
	mov r5, r8
	ldrh r0, [r5, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x3e]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081C7FA0:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C7FB0: .4byte 0x0000048A

	thumb_func_start FUN_081c7fb4
FUN_081c7fb4: @ 0x081C7FB4
	push {lr}
	adds r2, r0, #0
	ldr r0, _081C7FD4 @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C7FC6
	movs r0, #0
	strb r0, [r1]
_081C7FC6:
	adds r0, r2, #0
	movs r1, #1
	bl FUN_080ef86c
	pop {r0}
	bx r0
	.align 2, 0
_081C7FD4: .4byte 0x0000046D

	thumb_func_start FUN_081c7fd8
FUN_081c7fd8: @ 0x081C7FD8
	push {lr}
	adds r2, r0, #0
	ldr r0, _081C7FF8 @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C7FEA
	movs r0, #0
	strb r0, [r1]
_081C7FEA:
	adds r0, r2, #0
	movs r1, #0
	bl FUN_080ef86c
	pop {r0}
	bx r0
	.align 2, 0
_081C7FF8: .4byte 0x0000046D

	thumb_func_start FUN_081c7ffc
FUN_081c7ffc: @ 0x081C7FFC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	mov r8, r5
	ldr r0, _081C801C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C8020
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C8022
	.align 2, 0
_081C801C: .4byte 0x0000046D
_081C8020:
	movs r0, #0
_081C8022:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r1, r1, r5
	mov sb, r1
	cmp r0, #0
	bne _081C8030
	b _081C84B6
_081C8030:
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #6
	subs r0, #0x40
	strb r0, [r5, #5]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	adds r2, r0, #1
	ands r2, r1
	ldr r3, _081C8080 @ =0x0000046A
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #6
	beq _081C8084
	movs r1, #0x90
	lsls r1, r1, #3
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	bne _081C8084
	mov r1, r8
	ldr r0, [r1, #0x24]
	ldr r0, [r0, #8]
	ldrh r0, [r0, #4]
	lsrs r1, r0, #0xc
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	b _081C808C
	.align 2, 0
_081C8080: .4byte 0x0000046A
_081C8084:
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
_081C808C:
	cmp r1, #0
	blt _081C8094
	asrs r0, r1, #1
	b _081C809A
_081C8094:
	rsbs r0, r1, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081C809A:
	cmp r2, r0
	bne _081C8126
	ldr r2, _081C810C @ =0x0000046B
	adds r0, r5, r2
	movs r6, #0
	movs r4, #1
	strb r4, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081C811C
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _081C8110 @ =0x00000469
	adds r0, r5, r3
	strb r4, [r0]
	ldr r1, _081C8114 @ =0x0000046A
	adds r0, r5, r1
	strb r6, [r0]
	adds r2, #0x1c
	adds r0, r5, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r4, [r0]
	ldr r1, _081C8118 @ =0x000005BC
	adds r0, r5, r1
	ldr r2, [r0]
	movs r1, #0x1b
	adds r3, #1
	adds r0, r5, r3
	strb r4, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r6, [r0]
	adds r3, #0xe8
	adds r0, r5, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r6, [r0]
	b _081C8680
	.align 2, 0
_081C810C: .4byte 0x0000046B
_081C8110: .4byte 0x00000469
_081C8114: .4byte 0x0000046A
_081C8118: .4byte 0x000005BC
_081C811C:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	b _081C8680
_081C8126:
	cmp r2, #1
	beq _081C81E4
	cmp r2, #1
	bgt _081C8134
	cmp r2, #0
	beq _081C8142
	b _081C84AE
_081C8134:
	cmp r2, #2
	bne _081C813A
	b _081C82BC
_081C813A:
	cmp r2, #3
	bne _081C8140
	b _081C838C
_081C8140:
	b _081C84AE
_081C8142:
	subs r0, r1, #2
	cmp r0, #3
	bhi _081C8194
	movs r2, #0xd
	ldr r3, _081C8168 @ =0x0000025D
	adds r0, r5, r3
	ldrb r3, [r0]
	cmp r3, #0
	bne _081C8170
	ldr r1, _081C816C @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #1
	b _081C83AE
	.align 2, 0
_081C8168: .4byte 0x0000025D
_081C816C: .4byte 0x000004B7
_081C8170:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #0xe
	ldr r3, _081C818C @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081C8190 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xe
	beq _081C818A
	b _081C83EA
_081C818A:
	b _081C83DA
	.align 2, 0
_081C818C: .4byte 0x000004B7
_081C8190: .4byte 0x0000046E
_081C8194:
	movs r2, #0xd
	ldr r1, _081C81B8 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C81C0
	ldr r3, _081C81BC @ =0x000004B7
	adds r0, r5, r3
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #1
	str r2, [sp]
	movs r2, #0xd
	movs r3, #0
	b _081C8446
	.align 2, 0
_081C81B8: .4byte 0x0000025D
_081C81BC: .4byte 0x000004B7
_081C81C0:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	ldr r1, _081C81DC @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081C81E0 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xd
	beq _081C81D8
	b _081C8484
_081C81D8:
	b _081C8474
	.align 2, 0
_081C81DC: .4byte 0x000004B7
_081C81E0: .4byte 0x0000046E
_081C81E4:
	subs r0, r1, #4
	cmp r0, #3
	bhi _081C8238
	movs r2, #0xd
	ldr r3, _081C820C @ =0x0000025D
	adds r0, r5, r3
	ldrb r3, [r0]
	cmp r3, #0
	bne _081C8214
	ldr r1, _081C8210 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #2
	b _081C83AE
	.align 2, 0
_081C820C: .4byte 0x0000025D
_081C8210: .4byte 0x000004B7
_081C8214:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #0xf
	ldr r3, _081C8230 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081C8234 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xf
	beq _081C822E
	b _081C83EA
_081C822E:
	b _081C83DA
	.align 2, 0
_081C8230: .4byte 0x000004B7
_081C8234: .4byte 0x0000046E
_081C8238:
	movs r2, #0xd
	ldr r1, _081C8260 @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _081C826C
	ldr r1, _081C8264 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #3
	bl FUN_08236fac
	ldr r2, _081C8268 @ =0x0000046E
	adds r6, r5, r2
	b _081C849C
	.align 2, 0
_081C8260: .4byte 0x0000025D
_081C8264: .4byte 0x000004B7
_081C8268: .4byte 0x0000046E
_081C826C:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #0x10
	ldr r3, _081C82B4 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081C82B8 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0x10
	bne _081C8296
	ldrb r0, [r6]
	cmp r0, #0
	bne _081C8296
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081C8296
	b _081C84A0
_081C8296:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	b _081C849C
	.align 2, 0
_081C82B4: .4byte 0x000004B7
_081C82B8: .4byte 0x0000046E
_081C82BC:
	subs r0, r1, #1
	cmp r0, #4
	bls _081C833C
	movs r2, #0xd
	ldr r3, _081C82E8 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C82F0
	ldr r1, _081C82EC @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #1
	str r2, [sp]
	movs r2, #0xd
	movs r3, #3
	b _081C83AE
	.align 2, 0
_081C82E8: .4byte 0x0000025D
_081C82EC: .4byte 0x000004B7
_081C82F0:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	movs r2, #0x10
	ldr r3, _081C8334 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081C8338 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0x10
	bne _081C831A
	ldrb r0, [r6]
	cmp r0, #0
	bne _081C831A
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081C831A
	b _081C840A
_081C831A:
	strb r2, [r3]
	movs r4, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r4, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r7, #8]
	orrs r0, r4
	str r0, [r7, #8]
	b _081C8406
	.align 2, 0
_081C8334: .4byte 0x000004B7
_081C8338: .4byte 0x0000046E
_081C833C:
	movs r2, #0xd
	ldr r1, _081C8360 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C8368
	ldr r3, _081C8364 @ =0x000004B7
	adds r0, r5, r3
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #1
	str r2, [sp]
	movs r2, #0xd
	movs r3, #2
	b _081C8446
	.align 2, 0
_081C8360: .4byte 0x0000025D
_081C8364: .4byte 0x000004B7
_081C8368:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	movs r2, #0xf
	ldr r1, _081C8384 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081C8388 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xf
	beq _081C8382
	b _081C8484
_081C8382:
	b _081C8474
	.align 2, 0
_081C8384: .4byte 0x000004B7
_081C8388: .4byte 0x0000046E
_081C838C:
	cmp r1, #3
	bhi _081C8424
	movs r2, #0xd
	ldr r3, _081C83B8 @ =0x0000025D
	adds r0, r5, r3
	ldrb r3, [r0]
	cmp r3, #0
	bne _081C83C4
	ldr r1, _081C83BC @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #0
_081C83AE:
	bl FUN_08236fac
	ldr r2, _081C83C0 @ =0x0000046E
	adds r6, r5, r2
	b _081C8406
	.align 2, 0
_081C83B8: .4byte 0x0000025D
_081C83BC: .4byte 0x000004B7
_081C83C0: .4byte 0x0000046E
_081C83C4:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r3, _081C841C @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081C8420 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xd
	bne _081C83EA
_081C83DA:
	ldrb r0, [r6]
	cmp r0, #0
	bne _081C83EA
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081C840A
_081C83EA:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_081C8406:
	movs r0, #0
	strb r0, [r6]
_081C840A:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081C84AE
	.align 2, 0
_081C841C: .4byte 0x000004B7
_081C8420: .4byte 0x0000046E
_081C8424:
	movs r2, #0xd
	ldr r1, _081C8450 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C845C
	ldr r3, _081C8454 @ =0x000004B7
	adds r0, r5, r3
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #1
	str r2, [sp]
	movs r2, #0xd
	movs r3, #1
_081C8446:
	bl FUN_08236fac
	ldr r0, _081C8458 @ =0x0000046E
	adds r6, r5, r0
	b _081C849C
	.align 2, 0
_081C8450: .4byte 0x0000025D
_081C8454: .4byte 0x000004B7
_081C8458: .4byte 0x0000046E
_081C845C:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	movs r2, #0xe
	ldr r1, _081C84DC @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081C84E0 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xe
	bne _081C8484
_081C8474:
	ldrb r0, [r6]
	cmp r0, #0
	bne _081C8484
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081C84A0
_081C8484:
	strb r2, [r3]
	movs r4, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r4, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r7, #8]
	orrs r0, r4
	str r0, [r7, #8]
_081C849C:
	movs r0, #0
	strb r0, [r6]
_081C84A0:
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r1, _081C84E4 @ =0xFFFEFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081C84AE:
	ldr r2, _081C84E0 @ =0x0000046E
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
_081C84B6:
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	ldrh r0, [r0, #0xe]
	cmp r0, #1
	bne _081C84F0
	movs r1, #0x80
	lsls r1, r1, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C84E8
	mov r1, r8
	ldrb r0, [r1, #5]
	adds r0, #0x20
	strb r0, [r1, #5]
	b _081C84F0
	.align 2, 0
_081C84DC: .4byte 0x000004B7
_081C84E0: .4byte 0x0000046E
_081C84E4: .4byte 0xFFFEFFFF
_081C84E8:
	mov r2, r8
	ldrb r0, [r2, #5]
	subs r0, #0x20
	strb r0, [r2, #5]
_081C84F0:
	ldr r3, _081C8520 @ =0x00000482
	adds r2, r5, r3
	ldrh r6, [r2]
	movs r1, #0x80
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081C8506
	movs r0, #3
	strh r0, [r2]
_081C8506:
	ldr r1, _081C8524 @ =0x0000A02F
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081C8528
	ldr r3, _081C8520 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081C8538
	.align 2, 0
_081C8520: .4byte 0x00000482
_081C8524: .4byte 0x0000A02F
_081C8528:
	ldr r1, _081C855C @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081C8538
	movs r0, #1
	strh r0, [r2]
_081C8538:
	ldr r3, _081C8560 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C8564
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _081C857C
	.align 2, 0
_081C855C: .4byte 0x00000482
_081C8560: .4byte 0x0000025D
_081C8564:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_081C857C:
	ldr r1, _081C8638 @ =0x00000482
	adds r0, r5, r1
	movs r7, #0
	movs r2, #0
	mov r8, r2
	strh r6, [r0]
	ldr r3, _081C863C @ =0x0000046E
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _081C8680
	ldrb r0, [r5, #5]
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r3, #0xee
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrb r1, [r1]
	subs r1, r1, r0
	cmp r1, #0
	bge _081C85B2
	rsbs r1, r1, #0
_081C85B2:
	cmp r1, #0
	bgt _081C8650
	ldr r1, _081C8640 @ =0x0000046B
	adds r0, r5, r1
	movs r4, #1
	strb r4, [r0]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	subs r0, #0x40
	strb r0, [r5, #5]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #0x80
	lsls r1, r1, #3
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081C8680
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r6, [r0]
	adds r1, #0x69
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _081C8644 @ =0x0000046A
	adds r0, r5, r2
	strb r7, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	mov r1, r8
	str r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r4, [r0]
	ldr r3, _081C8648 @ =0x000005BC
	adds r0, r5, r3
	ldr r2, [r0]
	movs r1, #0x1b
	ldr r3, _081C864C @ =0x0000046D
	adds r0, r5, r3
	strb r4, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r7, [r0]
	adds r3, #0xe8
	adds r0, r5, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	mov r3, r8
	strh r3, [r0]
	b _081C8680
	.align 2, 0
_081C8638: .4byte 0x00000482
_081C863C: .4byte 0x0000046E
_081C8640: .4byte 0x0000046B
_081C8644: .4byte 0x0000046A
_081C8648: .4byte 0x000005BC
_081C864C: .4byte 0x0000046D
_081C8650:
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, [r0]
	movs r2, #2
	ldr r0, _081C8690 @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081C8694 @ =0x0000046B
	adds r0, r5, r1
	strb r7, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	mov r1, r8
	strh r1, [r0]
_081C8680:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C8690: .4byte 0x0000046D
_081C8694: .4byte 0x0000046B

	thumb_func_start FUN_081c8698
FUN_081c8698: @ 0x081C8698
	bx lr
	.align 2, 0

	thumb_func_start FUN_081c869c
FUN_081c869c: @ 0x081C869C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _081C86B4 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C86B8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C86BA
	.align 2, 0
_081C86B4: .4byte 0x0000046D
_081C86B8:
	movs r0, #0
_081C86BA:
	cmp r0, #0
	beq _081C86DC
	adds r0, r5, #0
	movs r1, #6
	bl FUN_080ef86c
	movs r0, #2
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	ands r0, r1
	cmp r0, #0
	bne _081C86DC
	movs r0, #1
	orrs r0, r1
	strh r0, [r2]
_081C86DC:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Mod
	cmp r0, #0
	bne _081C86F8
	ldr r2, _081C8744 @ =0x000001DF
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	bl FUN_080e5718
_081C86F8:
	ldr r1, _081C8748 @ =0x00000466
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _081C873E
	movs r1, #0x80
	lsls r1, r1, #5
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r4, [r0]
	ands r4, r1
	cmp r4, #0
	bne _081C873E
	ldr r3, _081C874C @ =FUN_081c8758
	movs r2, #6
	ldr r0, _081C8750 @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081C8754 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
_081C873E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081C8744: .4byte 0x000001DF
_081C8748: .4byte 0x00000466
_081C874C: .4byte FUN_081c8758
_081C8750: .4byte 0x0000046D
_081C8754: .4byte 0x0000046B

	thumb_func_start FUN_081c8758
FUN_081c8758: @ 0x081C8758
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _081C8770 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C8774
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C8776
	.align 2, 0
_081C8770: .4byte 0x0000046D
_081C8774:
	movs r0, #0
_081C8776:
	cmp r0, #0
	beq _081C8792
	adds r0, r4, #0
	movs r1, #7
	bl FUN_080ef86c
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #2
	rsbs r1, r1, #0
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_081C8792:
	cmp r5, #0x28
	bne _081C87A4
	movs r0, #0x10
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081C87A4:
	ldr r1, _081C87C0 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081C87BA
	cmp r5, #0x78
	ble _081C87BA
	ldr r0, _081C87C4 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_081C87BA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081C87C0: .4byte 0x0000046E
_081C87C4: .4byte 0x0000046B

	thumb_func_start FUN_081c87c8
FUN_081c87c8: @ 0x081C87C8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081C87E0 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C87E4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C87E6
	.align 2, 0
_081C87E0: .4byte 0x0000046D
_081C87E4:
	movs r0, #0
_081C87E6:
	cmp r0, #0
	beq _081C87FA
	adds r0, r5, #0
	movs r1, #0xb
	bl FUN_080ef86c
	ldr r0, _081C882C @ =0x0000046E
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
_081C87FA:
	ldr r1, _081C8830 @ =0x00000482
	adds r3, r5, r1
	ldrh r6, [r3]
	movs r1, #0x80
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081C8814
	movs r0, #3
	strh r0, [r3]
_081C8814:
	ldr r1, _081C8834 @ =0x0000A02F
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081C8838
	ldr r0, _081C8830 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081C8848
	.align 2, 0
_081C882C: .4byte 0x0000046E
_081C8830: .4byte 0x00000482
_081C8834: .4byte 0x0000A02F
_081C8838:
	ldr r1, _081C886C @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081C8848
	movs r0, #1
	strh r0, [r2]
_081C8848:
	ldr r1, _081C8870 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C8874
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _081C888C
	.align 2, 0
_081C886C: .4byte 0x00000482
_081C8870: .4byte 0x0000025D
_081C8874:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_081C888C:
	ldr r1, _081C88AC @ =0x00000482
	adds r0, r5, r1
	strh r6, [r0]
	subs r1, #0x14
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081C88A4
	ldr r0, _081C88B0 @ =0x0000046B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_081C88A4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081C88AC: .4byte 0x00000482
_081C88B0: .4byte 0x0000046B

	thumb_func_start FUN_081c88b4
FUN_081c88b4: @ 0x081C88B4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, _081C88CC @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C88D0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C88D2
	.align 2, 0
_081C88CC: .4byte 0x0000046D
_081C88D0:
	movs r0, #0
_081C88D2:
	cmp r0, #0
	beq _081C88E6
	adds r0, r4, #0
	movs r1, #0xb
	bl FUN_080ef86c
	ldr r2, _081C8990 @ =0x0000046E
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_081C88E6:
	ldr r3, _081C8990 @ =0x0000046E
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C88F2
	b _081C8A0A
_081C88F2:
	ldr r6, _081C8994 @ =0x0000046B
	adds r0, r4, r6
	movs r6, #0
	movs r7, #1
	strb r7, [r0]
	movs r1, #0x80
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _081C89AC
	adds r3, #0x36
	adds r0, r4, r3
	ldr r0, [r0]
	movs r2, #0x1c
	ldrsh r1, [r0, r2]
	movs r3, #0x20
	ldrsh r2, [r0, r3]
	adds r0, r4, #0
	bl FUN_080e6304
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r2, [r0]
	movs r1, #0x1a
	ldr r3, _081C8998 @ =0x0000046D
	adds r0, r4, r3
	strb r7, [r0]
	subs r3, #2
	adds r0, r4, r3
	strb r6, [r0]
	adds r3, #0xe8
	adds r0, r4, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r1, #0
	strh r6, [r0]
	movs r2, #0xc
	subs r3, #0xeb
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _081C899C @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _081C89A0 @ =0x00000484
	adds r0, r4, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r4, r3
	strb r7, [r0]
	movs r0, #4
	ldr r6, _081C89A4 @ =0x00000222
	adds r2, r4, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _081C89A8 @ =0x00000482
	adds r1, r4, r0
	movs r0, #2
	strh r0, [r1]
	b _081C8A0A
	.align 2, 0
_081C8990: .4byte 0x0000046E
_081C8994: .4byte 0x0000046B
_081C8998: .4byte 0x0000046D
_081C899C: .4byte 0x0000046A
_081C89A0: .4byte 0x00000484
_081C89A4: .4byte 0x00000222
_081C89A8: .4byte 0x00000482
_081C89AC:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r1, _081C8A10 @ =FUN_080e48d0
	movs r3, #0x10
	ldr r2, _081C8A14 @ =0x0000046D
	adds r0, r4, r2
	strb r7, [r0]
	ldr r6, _081C8A18 @ =0x0000046B
	adds r0, r4, r6
	strb r5, [r0]
	adds r2, #0xe6
	adds r0, r4, r2
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r4, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	strh r5, [r0]
	movs r2, #7
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _081C8A1C @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _081C8A20 @ =0x00000484
	adds r0, r4, r2
	str r5, [r0]
	adds r6, #3
	adds r0, r4, r6
	strb r7, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
_081C8A0A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C8A10: .4byte FUN_080e48d0
_081C8A14: .4byte 0x0000046D
_081C8A18: .4byte 0x0000046B
_081C8A1C: .4byte 0x0000046A
_081C8A20: .4byte 0x00000484

	thumb_func_start FUN_081c8a24
FUN_081c8a24: @ 0x081C8A24
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc0
	adds r7, r0, #0
	ldr r0, _081C8A44 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C8A48
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C8A4A
	.align 2, 0
_081C8A44: .4byte 0x0000046D
_081C8A48:
	movs r0, #0
_081C8A4A:
	cmp r0, #0
	beq _081C8AA8
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _081C8A60
	asrs r1, r0, #2
	b _081C8A66
_081C8A60:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_081C8A66:
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r0, r7, r4
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	blt _081C8A80
	asrs r1, r0, #2
	b _081C8A86
_081C8A80:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_081C8A86:
	movs r6, #0xe2
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r1, [r0]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
	movs r0, #0x20
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	ldr r1, _081C8AD8 @ =0xFFFFFEFF
	ands r0, r1
	strh r0, [r2]
_081C8AA8:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r4, #0x83
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r5, #0
	ldrsh r2, [r0, r5]
	movs r6, #0x85
	lsls r6, r6, #2
	adds r1, r7, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _081C8ADC
	asrs r0, r0, #2
	b _081C8AE2
	.align 2, 0
_081C8AD8: .4byte 0xFFFFFEFF
_081C8ADC:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081C8AE2:
	adds r3, r0, #0
	movs r5, #0x84
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r6, #0
	ldrsh r2, [r0, r6]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	cmp r0, #0
	blt _081C8B02
	asrs r0, r0, #2
	b _081C8B08
_081C8B02:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081C8B08:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _081C8B12
	movs r3, #0xc8
	b _081C8B1C
_081C8B12:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _081C8B1C
	adds r3, r0, #0
_081C8B1C:
	cmp r2, #0xc8
	ble _081C8B24
	movs r2, #0xc8
	b _081C8B2E
_081C8B24:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _081C8B2E
	adds r2, r0, #0
_081C8B2E:
	ldrh r0, [r7, #0x10]
	adds r0, r0, r3
	strh r0, [r7, #0x10]
	ldrh r0, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _081C8B52
	cmp r2, #0
	bne _081C8B52
	movs r0, #1
	b _081C8B54
_081C8B52:
	movs r0, #0
_081C8B54:
	cmp r0, #0
	bne _081C8B5C
	bl FUN_081c9a40
_081C8B5C:
	ldr r6, _081C8BA8 @ =0x0000046E
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _081C8B6A
	bl FUN_081c9a40
_081C8B6A:
	ldr r0, _081C8BAC @ =0x0000046B
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	movs r3, #0x21
	rsbs r3, r3, #0
	ldrh r0, [r2]
	ands r3, r0
	strh r3, [r2]
	ldr r4, _081C8BB0 @ =0x0000049C
	adds r0, r7, r4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xc
	ands r0, r1
	str r2, [sp, #0x9c]
	cmp r0, #0
	beq _081C8BB4
	movs r0, #2
	movs r5, #0xc1
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	bl _081C9A50
	.align 2, 0
_081C8BA8: .4byte 0x0000046E
_081C8BAC: .4byte 0x0000046B
_081C8BB0: .4byte 0x0000049C
_081C8BB4:
	movs r2, #0x80
	adds r0, r3, #0
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _081C8BC4
	b _081C92F4
_081C8BC4:
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, _081C8C20 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r3, r7, r1
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x98]
	str r2, [sp, #0x74]
	cmp r4, #0
	blt _081C8C1A
	cmp r1, #0
	blt _081C8C1A
	ldr r0, _081C8C24 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081C8C1A
	ldr r0, _081C8C28 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C8C2C
_081C8C1A:
	movs r4, #0
	b _081C8C3A
	.align 2, 0
_081C8C20: .4byte 0x03002BE0
_081C8C24: .4byte 0x030046A8
_081C8C28: .4byte 0x030046AC
_081C8C2C:
	ldr r0, _081C8C4C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081C8C3A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C8C50
	adds r0, #4
	b _081C8C5C
	.align 2, 0
_081C8C4C: .4byte 0x030046A4
_081C8C50:
	ldr r0, _081C8C70 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C8C5C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C8C74
	cmp r2, #2
	beq _081C8C78
	b _081C8C7C
	.align 2, 0
_081C8C70: .4byte 0x030046A4
_081C8C74:
	ldrb r0, [r5, #4]
	b _081C8C7A
_081C8C78:
	ldrb r0, [r5]
_081C8C7A:
	subs r1, r1, r0
_081C8C7C:
	strh r1, [r5, #2]
	ldr r0, _081C8C90 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C8C94
	movs r0, #1
	b _081C8C96
	.align 2, 0
_081C8C90: .4byte 0x030047A4
_081C8C94:
	movs r0, #0
_081C8C96:
	cmp r0, #0
	beq _081C8CD4
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _081C8CB6
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081C8CB2
	adds r2, r0, #0
_081C8CB2:
	cmp r2, #0
	bge _081C8CC0
_081C8CB6:
	ldr r3, _081C8CBC @ =0x000005C4
	adds r0, r7, r3
	b _081C91F0
	.align 2, 0
_081C8CBC: .4byte 0x000005C4
_081C8CC0:
	ldr r1, _081C8CD0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081C8D1C
	.align 2, 0
_081C8CD0: .4byte 0x03002BE0
_081C8CD4:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C8D00
	cmp r1, #0
	blt _081C8D00
	ldr r0, _081C8D04 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C8D00
	ldr r0, _081C8D08 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C8D0C
_081C8D00:
	movs r5, #0
	b _081C8D1A
	.align 2, 0
_081C8D04: .4byte 0x030046A8
_081C8D08: .4byte 0x030046AC
_081C8D0C:
	ldr r0, _081C8D54 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081C8D1A:
	movs r2, #0
_081C8D1C:
	ldr r6, _081C8D58 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _081C8D3C
	ldr r1, _081C8D5C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081C8D3C
	b _081C9130
_081C8D3C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0x9c]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
	cmp r0, #0
	beq _081C8D60
	movs r0, #0
	b _081C9206
	.align 2, 0
_081C8D54: .4byte 0x030046A4
_081C8D58: .4byte 0x00000256
_081C8D5C: .4byte 0x03002BE0
_081C8D60:
	ldr r3, _081C8E04 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0x9c]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xac]
	cmp r6, #0
	beq _081C8E1C
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _081C8E08 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x14]
	movs r2, #1
	strb r2, [r6]
	ldr r3, _081C8E0C @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x18]
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x65
	adds r5, r7, r5
	str r5, [sp, #0x1c]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r6, r7
	mov r8, r6
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r5, r7, r0
	mov r1, sp
	ldrh r1, [r1, #0x10]
	strh r1, [r5]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	movs r3, #0
	strb r3, [r4]
	ldr r6, _081C8E10 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081C8E14 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x10]
	str r6, [r1]
	ldr r6, _081C8E18 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x8c]
	ldr r6, [sp, #0x18]
	str r6, [sp, #0x84]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0xb0]
	mov r6, r8
	str r6, [sp, #0xb4]
	str r5, [sp, #0xa0]
	str r4, [sp, #0x78]
	str r3, [sp, #0x7c]
	str r2, [sp, #0x80]
	str r1, [sp, #0x94]
	str r0, [sp, #0x88]
	b _081C8FEE
	.align 2, 0
_081C8E04: .4byte 0x00000222
_081C8E08: .4byte 0x0000046D
_081C8E0C: .4byte 0x0000046B
_081C8E10: .4byte 0x00000469
_081C8E14: .4byte 0x00000484
_081C8E18: .4byte 0x0000046C
_081C8E1C:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081C8EE0 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x20]
	strb r0, [r2]
	ldr r3, _081C8EE4 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x24]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081C8EE8 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x28]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x30]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x34]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _081C8EEC @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _081C8EF0 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _081C8EF4 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x98]
	ldr r0, [r0]
	str r0, [sp, #0x38]
	ldr r1, [sp, #0x74]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x38]
	strh r1, [r6]
	ldr r6, [sp, #0x74]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x38]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x8c]
	ldr r6, [sp, #0x24]
	str r6, [sp, #0x84]
	ldr r0, [sp, #0x28]
	str r0, [sp, #0xb0]
	ldr r6, [sp, #0x2c]
	str r6, [sp, #0xb4]
	ldr r0, [sp, #0x30]
	str r0, [sp, #0xa0]
	ldr r6, [sp, #0x34]
	str r6, [sp, #0x78]
	str r5, [sp, #0x7c]
	str r4, [sp, #0x80]
	str r3, [sp, #0x94]
	str r2, [sp, #0x88]
	mov r0, sl
	cmp r0, #0
	blt _081C8EDA
	cmp r1, #0
	blt _081C8EDA
	ldr r0, _081C8EF8 @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _081C8EDA
	ldr r0, _081C8EFC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C8F00
_081C8EDA:
	movs r4, #0
	b _081C8F10
	.align 2, 0
_081C8EE0: .4byte 0x0000046D
_081C8EE4: .4byte 0x0000046B
_081C8EE8: .4byte 0x00000553
_081C8EEC: .4byte 0x00000469
_081C8EF0: .4byte 0x00000484
_081C8EF4: .4byte 0x0000046C
_081C8EF8: .4byte 0x030046A8
_081C8EFC: .4byte 0x030046AC
_081C8F00:
	ldr r0, _081C8F20 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sl
	adds r4, r0, r1
_081C8F10:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C8F24
	adds r0, #4
	b _081C8F30
	.align 2, 0
_081C8F20: .4byte 0x030046A4
_081C8F24:
	ldr r0, _081C8F44 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C8F30:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C8F48
	cmp r2, #2
	beq _081C8F4E
	b _081C8F54
	.align 2, 0
_081C8F44: .4byte 0x030046A4
_081C8F48:
	ldr r2, [sp, #0x38]
	ldrb r0, [r2, #4]
	b _081C8F52
_081C8F4E:
	ldr r3, [sp, #0x38]
	ldrb r0, [r3]
_081C8F52:
	subs r1, r1, r0
_081C8F54:
	ldr r4, [sp, #0x38]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x98]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C8F80
	cmp r1, #0
	blt _081C8F80
	ldr r0, _081C8F84 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C8F80
	ldr r0, _081C8F88 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C8F8C
_081C8F80:
	movs r4, #0
	b _081C8F9A
	.align 2, 0
_081C8F84: .4byte 0x030046A8
_081C8F88: .4byte 0x030046AC
_081C8F8C:
	ldr r0, _081C8FB0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081C8F9A:
	ldr r6, [sp, #0x98]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C8FB4
	adds r0, #4
	b _081C8FC0
	.align 2, 0
_081C8FB0: .4byte 0x030046A4
_081C8FB4:
	ldr r0, _081C8FD4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C8FC0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081C8FD8
	cmp r3, #2
	beq _081C8FDC
	b _081C8FE0
	.align 2, 0
_081C8FD4: .4byte 0x030046A4
_081C8FD8:
	ldrb r0, [r5, #4]
	b _081C8FDE
_081C8FDC:
	ldrb r0, [r5]
_081C8FDE:
	subs r2, r2, r0
_081C8FE0:
	ldr r1, [sp, #0x98]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x98]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081C8FEE:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x3c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x9c]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _081C9018 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x90]
	cmp r0, #0
	bne _081C90F8
	movs r1, #4
	ldr r6, [sp, #0xac]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081C901C
	movs r0, #1
	b _081C901E
	.align 2, 0
_081C9018: .4byte 0x00000482
_081C901C:
	movs r0, #0
_081C901E:
	ldr r1, _081C9108 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x90]
	cmp r0, #0
	bne _081C90F8
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xbc]
	ldr r0, _081C910C @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _081C9110 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _081C9114 @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa8]
	ldr r0, _081C9118 @ =0x00000541
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _081C911C @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xb8]
	ldr r2, _081C9120 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	ldr r1, _081C9124 @ =0x030046B8
	adds r2, r4, #0
_081C9066:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _081C9128 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _081C912C @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _081C908A
	adds r3, #1
	cmp r3, #3
	ble _081C9066
	adds r0, r4, #0
_081C908A:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0xb4]
	ldr r0, [r1]
	ldr r2, [sp, #0xbc]
	str r0, [r2]
	ldr r4, [sp, #0xb0]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x7c]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x80]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa8]
	strb r0, [r6]
	add r0, sp, #0x3c
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xb8]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x8c]
	strb r1, [r4]
	ldr r5, [sp, #0x84]
	strb r3, [r5]
	ldr r6, [sp, #0xb0]
	strb r0, [r6]
	ldr r0, [sp, #0xb4]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xa0]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x78]
	strb r0, [r5]
	ldr r6, [sp, #0x7c]
	strb r1, [r6]
	ldr r0, [sp, #0x80]
	strb r2, [r0]
	ldr r2, [sp, #0x94]
	str r3, [r2]
	ldr r3, [sp, #0x88]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa4]
	strb r0, [r4]
_081C90F8:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x90]
	strh r0, [r5]
	movs r0, #0
	b _081C9206
	.align 2, 0
_081C9108: .4byte 0x00000482
_081C910C: .4byte 0x0000054F
_081C9110: .4byte 0x0000054C
_081C9114: .4byte 0x0000054E
_081C9118: .4byte 0x00000541
_081C911C: .4byte 0x000005BC
_081C9120: .4byte 0x00000542
_081C9124: .4byte 0x030046B8
_081C9128: .4byte 0x000003FF
_081C912C: .4byte 0x0203B400
_081C9130:
	mov sb, sp
	ldr r6, _081C916C @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C9170
	adds r0, #4
	b _081C917A
	.align 2, 0
_081C916C: .4byte 0x030046A4
_081C9170:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081C917A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _081C91B4 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _081C91BC
	ldr r0, _081C91B8 @ =0xFFFFFDFF
	ldr r2, [sp, #0x9c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081C91E6
	.align 2, 0
_081C91B4: .4byte 0x000004A4
_081C91B8: .4byte 0xFFFFFDFF
_081C91BC:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081C91DC
	cmp r0, #2
	beq _081C91D8
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C91D8:
	movs r0, #1
	b _081C91E8
_081C91DC:
	ldr r0, _081C91FC @ =0xFFFFFDFF
	ldr r3, [sp, #0x9c]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081C91E6:
	movs r0, #0
_081C91E8:
	cmp r0, #0
	bne _081C9204
	ldr r4, _081C9200 @ =0x000005C4
	adds r0, r7, r4
_081C91F0:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081C9206
	.align 2, 0
_081C91FC: .4byte 0xFFFFFDFF
_081C9200: .4byte 0x000005C4
_081C9204:
	movs r0, #1
_081C9206:
	cmp r0, #0
	bne _081C9276
	ldr r5, _081C923C @ =0x000004A4
	adds r0, r7, r5
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081C9244
	ldr r0, _081C9240 @ =0xFFFFFDFF
	ldr r2, [sp, #0x9c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081C926E
	.align 2, 0
_081C923C: .4byte 0x000004A4
_081C9240: .4byte 0xFFFFFDFF
_081C9244:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081C9264
	cmp r0, #2
	beq _081C9260
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C9260:
	movs r0, #1
	b _081C9270
_081C9264:
	ldr r0, _081C92D8 @ =0xFFFFFDFF
	ldr r3, [sp, #0x9c]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081C926E:
	movs r0, #0
_081C9270:
	cmp r0, #0
	bne _081C9276
	b _081C99B8
_081C9276:
	movs r0, #4
	ldr r5, _081C92DC @ =0x00000222
	adds r2, r7, r5
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r2, [r0]
	movs r1, #0x1a
	ldr r4, _081C92E0 @ =0x0000046D
	adds r0, r7, r4
	movs r4, #1
	strb r4, [r0]
	ldr r6, _081C92E4 @ =0x0000046B
	adds r0, r7, r6
	strb r3, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	movs r1, #0xc
	subs r6, #0xeb
	adds r0, r7, r6
	strb r3, [r0]
	ldr r2, _081C92E8 @ =0x00000469
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _081C92EC @ =0x0000046A
	adds r0, r7, r3
	strb r1, [r0]
	adds r6, #0x1c
	adds r0, r7, r6
	str r5, [r0]
	ldr r1, _081C92F0 @ =0x0000046C
	adds r0, r7, r1
	strb r4, [r0]
	b _081C9A50
	.align 2, 0
_081C92D8: .4byte 0xFFFFFDFF
_081C92DC: .4byte 0x00000222
_081C92E0: .4byte 0x0000046D
_081C92E4: .4byte 0x0000046B
_081C92E8: .4byte 0x00000469
_081C92EC: .4byte 0x0000046A
_081C92F0: .4byte 0x0000046C
_081C92F4:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, _081C9358 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r2, #0x10
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r0, [r0]
	strh r3, [r0, #6]
	adds r3, r7, r5
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x98]
	str r2, [sp, #0x74]
	cmp r4, #0
	blt _081C9352
	cmp r1, #0
	blt _081C9352
	ldr r0, _081C935C @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081C9352
	ldr r0, _081C9360 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C9364
_081C9352:
	movs r4, #0
	b _081C9372
	.align 2, 0
_081C9358: .4byte 0x03002BE0
_081C935C: .4byte 0x030046A8
_081C9360: .4byte 0x030046AC
_081C9364:
	ldr r0, _081C9384 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081C9372:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C9388
	adds r0, #4
	b _081C9394
	.align 2, 0
_081C9384: .4byte 0x030046A4
_081C9388:
	ldr r0, _081C93A8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C9394:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C93AC
	cmp r2, #2
	beq _081C93B0
	b _081C93B4
	.align 2, 0
_081C93A8: .4byte 0x030046A4
_081C93AC:
	ldrb r0, [r5, #4]
	b _081C93B2
_081C93B0:
	ldrb r0, [r5]
_081C93B2:
	subs r1, r1, r0
_081C93B4:
	strh r1, [r5, #2]
	ldr r0, _081C93C8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C93CC
	movs r0, #1
	b _081C93CE
	.align 2, 0
_081C93C8: .4byte 0x030047A4
_081C93CC:
	movs r0, #0
_081C93CE:
	cmp r0, #0
	beq _081C940C
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r1, [r0]
	cmp r1, #0
	beq _081C93EE
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081C93EA
	adds r2, r0, #0
_081C93EA:
	cmp r2, #0
	bge _081C93F8
_081C93EE:
	ldr r1, _081C93F4 @ =0x000005C4
	adds r0, r7, r1
	b _081C9934
	.align 2, 0
_081C93F4: .4byte 0x000005C4
_081C93F8:
	ldr r1, _081C9408 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081C9454
	.align 2, 0
_081C9408: .4byte 0x03002BE0
_081C940C:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C9438
	cmp r1, #0
	blt _081C9438
	ldr r0, _081C943C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C9438
	ldr r0, _081C9440 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C9444
_081C9438:
	movs r5, #0
	b _081C9452
	.align 2, 0
_081C943C: .4byte 0x030046A8
_081C9440: .4byte 0x030046AC
_081C9444:
	ldr r0, _081C948C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081C9452:
	movs r2, #0
_081C9454:
	ldr r3, _081C9490 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _081C9474
	ldr r1, _081C9494 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081C9474
	b _081C9870
_081C9474:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x9c]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x40]
	cmp r0, #0
	beq _081C9498
	movs r0, #0
	b _081C994A
	.align 2, 0
_081C948C: .4byte 0x030046A4
_081C9490: .4byte 0x00000256
_081C9494: .4byte 0x03002BE0
_081C9498:
	ldr r5, _081C953C @ =0x00000222
	adds r2, r7, r5
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r6, [sp, #0x9c]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	str r2, [sp, #0xac]
	cmp r0, #0
	beq _081C955C
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _081C9540 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x44]
	movs r3, #1
	strb r3, [r2]
	ldr r4, _081C9544 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x48]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _081C9548 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x4c]
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x50]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	add r2, sp, #0x40
	ldrh r2, [r2]
	strh r2, [r5]
	movs r0, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r6, #0
	strb r6, [r4]
	ldr r1, _081C954C @ =0x00000469
	adds r3, r7, r1
	strb r6, [r3]
	ldr r6, _081C9550 @ =0x0000046A
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081C9554 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x40]
	str r6, [r1]
	ldr r6, _081C9558 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x44]
	str r6, [sp, #0x8c]
	ldr r6, [sp, #0x48]
	str r6, [sp, #0x84]
	ldr r6, [sp, #0x4c]
	str r6, [sp, #0xb0]
	ldr r6, [sp, #0x50]
	str r6, [sp, #0xb4]
	str r5, [sp, #0xa0]
	str r4, [sp, #0x78]
	str r3, [sp, #0x7c]
	str r2, [sp, #0x80]
	str r1, [sp, #0x94]
	str r0, [sp, #0x88]
	b _081C972E
	.align 2, 0
_081C953C: .4byte 0x00000222
_081C9540: .4byte 0x0000046D
_081C9544: .4byte 0x0000046B
_081C9548: .4byte 0x00000553
_081C954C: .4byte 0x00000469
_081C9550: .4byte 0x0000046A
_081C9554: .4byte 0x00000484
_081C9558: .4byte 0x0000046C
_081C955C:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081C9620 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x54]
	strb r0, [r2]
	ldr r3, _081C9624 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x58]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081C9628 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x5c]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x60]
	str r1, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x64]
	mov r2, ip
	strh r2, [r1]
	movs r1, #5
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x68]
	strb r4, [r3]
	ldr r4, _081C962C @ =0x00000469
	adds r5, r7, r4
	movs r6, #0
	strb r6, [r5]
	ldr r2, _081C9630 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r6, _081C9634 @ =0x00000484
	adds r3, r7, r6
	mov r1, ip
	str r1, [r3]
	subs r6, #0x18
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x98]
	ldr r0, [r0]
	str r0, [sp, #0x6c]
	ldr r1, [sp, #0x74]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x6c]
	strh r1, [r6]
	ldr r6, [sp, #0x74]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x6c]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x54]
	str r0, [sp, #0x8c]
	ldr r6, [sp, #0x58]
	str r6, [sp, #0x84]
	ldr r0, [sp, #0x5c]
	str r0, [sp, #0xb0]
	ldr r6, [sp, #0x60]
	str r6, [sp, #0xb4]
	ldr r0, [sp, #0x64]
	str r0, [sp, #0xa0]
	ldr r6, [sp, #0x68]
	str r6, [sp, #0x78]
	str r5, [sp, #0x7c]
	str r4, [sp, #0x80]
	str r3, [sp, #0x94]
	str r2, [sp, #0x88]
	mov r0, sb
	cmp r0, #0
	blt _081C961C
	cmp r1, #0
	blt _081C961C
	ldr r0, _081C9638 @ =0x030046A8
	ldr r0, [r0]
	cmp sb, r0
	bhs _081C961C
	ldr r0, _081C963C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C9640
_081C961C:
	movs r4, #0
	b _081C9650
	.align 2, 0
_081C9620: .4byte 0x0000046D
_081C9624: .4byte 0x0000046B
_081C9628: .4byte 0x00000553
_081C962C: .4byte 0x00000469
_081C9630: .4byte 0x0000046A
_081C9634: .4byte 0x00000484
_081C9638: .4byte 0x030046A8
_081C963C: .4byte 0x030046AC
_081C9640:
	ldr r0, _081C9660 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sb
	adds r4, r0, r1
_081C9650:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C9664
	adds r0, #4
	b _081C9670
	.align 2, 0
_081C9660: .4byte 0x030046A4
_081C9664:
	ldr r0, _081C9684 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C9670:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C9688
	cmp r2, #2
	beq _081C968E
	b _081C9694
	.align 2, 0
_081C9684: .4byte 0x030046A4
_081C9688:
	ldr r2, [sp, #0x6c]
	ldrb r0, [r2, #4]
	b _081C9692
_081C968E:
	ldr r3, [sp, #0x6c]
	ldrb r0, [r3]
_081C9692:
	subs r1, r1, r0
_081C9694:
	ldr r4, [sp, #0x6c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x98]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C96C0
	cmp r1, #0
	blt _081C96C0
	ldr r0, _081C96C4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C96C0
	ldr r0, _081C96C8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C96CC
_081C96C0:
	movs r4, #0
	b _081C96DA
	.align 2, 0
_081C96C4: .4byte 0x030046A8
_081C96C8: .4byte 0x030046AC
_081C96CC:
	ldr r0, _081C96F0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081C96DA:
	ldr r6, [sp, #0x98]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081C96F4
	adds r0, #4
	b _081C9700
	.align 2, 0
_081C96F0: .4byte 0x030046A4
_081C96F4:
	ldr r0, _081C9714 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C9700:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081C9718
	cmp r3, #2
	beq _081C971C
	b _081C9720
	.align 2, 0
_081C9714: .4byte 0x030046A4
_081C9718:
	ldrb r0, [r5, #4]
	b _081C971E
_081C971C:
	ldrb r0, [r5]
_081C971E:
	subs r2, r2, r0
_081C9720:
	ldr r1, [sp, #0x98]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x98]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081C972E:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x70]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x9c]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _081C9758 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x90]
	cmp r0, #0
	bne _081C9838
	movs r1, #4
	ldr r6, [sp, #0xac]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081C975C
	movs r0, #1
	b _081C975E
	.align 2, 0
_081C9758: .4byte 0x00000482
_081C975C:
	movs r0, #0
_081C975E:
	ldr r1, _081C9848 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x90]
	cmp r0, #0
	bne _081C9838
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xbc]
	ldr r0, _081C984C @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _081C9850 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _081C9854 @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa8]
	ldr r0, _081C9858 @ =0x00000541
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _081C985C @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xb8]
	ldr r2, _081C9860 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	ldr r1, _081C9864 @ =0x030046B8
	adds r2, r4, #0
_081C97A6:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _081C9868 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _081C986C @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _081C97CA
	adds r3, #1
	cmp r3, #3
	ble _081C97A6
	adds r0, r4, #0
_081C97CA:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0xb4]
	ldr r0, [r1]
	ldr r2, [sp, #0xbc]
	str r0, [r2]
	ldr r4, [sp, #0xb0]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x7c]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x80]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa8]
	strb r0, [r6]
	add r0, sp, #0x70
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xb8]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x8c]
	strb r1, [r4]
	ldr r5, [sp, #0x84]
	strb r3, [r5]
	ldr r6, [sp, #0xb0]
	strb r0, [r6]
	ldr r0, [sp, #0xb4]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xa0]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x78]
	strb r0, [r5]
	ldr r6, [sp, #0x7c]
	strb r1, [r6]
	ldr r0, [sp, #0x80]
	strb r2, [r0]
	ldr r2, [sp, #0x94]
	str r3, [r2]
	ldr r3, [sp, #0x88]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa4]
	strb r0, [r4]
_081C9838:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x90]
	strh r0, [r5]
	movs r0, #0
	b _081C994A
	.align 2, 0
_081C9848: .4byte 0x00000482
_081C984C: .4byte 0x0000054F
_081C9850: .4byte 0x0000054C
_081C9854: .4byte 0x0000054E
_081C9858: .4byte 0x00000541
_081C985C: .4byte 0x000005BC
_081C9860: .4byte 0x00000542
_081C9864: .4byte 0x030046B8
_081C9868: .4byte 0x000003FF
_081C986C: .4byte 0x0203B400
_081C9870:
	add r6, sp, #8
	ldr r0, _081C98B0 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	mov sl, r6
	cmp r0, #0
	beq _081C98B4
	adds r0, #4
	b _081C98C0
	.align 2, 0
_081C98B0: .4byte 0x030046A4
_081C98B4:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081C98C0:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081C98F8 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _081C9900
	ldr r0, _081C98FC @ =0xFFFFFDFF
	ldr r6, [sp, #0x9c]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081C992A
	.align 2, 0
_081C98F8: .4byte 0x000004A4
_081C98FC: .4byte 0xFFFFFDFF
_081C9900:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _081C9920
	cmp r0, #2
	beq _081C991C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C991C:
	movs r0, #1
	b _081C992C
_081C9920:
	ldr r0, _081C9940 @ =0xFFFFFDFF
	ldr r2, [sp, #0x9c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081C992A:
	movs r0, #0
_081C992C:
	cmp r0, #0
	bne _081C9948
	ldr r3, _081C9944 @ =0x000005C4
	adds r0, r7, r3
_081C9934:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081C994A
	.align 2, 0
_081C9940: .4byte 0xFFFFFDFF
_081C9944: .4byte 0x000005C4
_081C9948:
	movs r0, #1
_081C994A:
	cmp r0, #0
	bne _081C99D0
	ldr r4, _081C9980 @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081C9988
	ldr r0, _081C9984 @ =0xFFFFFDFF
	ldr r2, [sp, #0x9c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081C99B2
	.align 2, 0
_081C9980: .4byte 0x000004A4
_081C9984: .4byte 0xFFFFFDFF
_081C9988:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081C99A8
	cmp r0, #2
	beq _081C99A4
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C99A4:
	movs r0, #1
	b _081C99B4
_081C99A8:
	ldr r0, _081C99C8 @ =0xFFFFFDFF
	ldr r3, [sp, #0x9c]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081C99B2:
	movs r0, #0
_081C99B4:
	cmp r0, #0
	bne _081C99D0
_081C99B8:
	ldr r4, _081C99CC @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081C9A50
	.align 2, 0
_081C99C8: .4byte 0xFFFFFDFF
_081C99CC: .4byte 0x000005C4
_081C99D0:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _081C9A2C @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _081C9A30 @ =0x0000046B
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #0x4d
	adds r0, r7, r5
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _081C9A34 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081C9A38 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _081C9A3C @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #4
	strh r0, [r1]
	b _081C9A50
	.align 2, 0
_081C9A2C: .4byte 0x0000046D
_081C9A30: .4byte 0x0000046B
_081C9A34: .4byte 0x00000469
_081C9A38: .4byte 0x0000046A
_081C9A3C: .4byte 0x00000484

	thumb_func_start FUN_081c9a40
FUN_081c9a40: @ 0x081C9A40
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081C9A50:
	add sp, #0xc0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081c9a60
FUN_081c9a60: @ 0x081C9A60
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _081C9A7C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C9A80
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C9A82
	.align 2, 0
_081C9A7C: .4byte 0x0000046D
_081C9A80:
	movs r0, #0
_081C9A82:
	cmp r0, #0
	beq _081C9A8E
	adds r0, r5, #0
	movs r1, #0x11
	bl FUN_080ef86c
_081C9A8E:
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	movs r1, #0
	strh r1, [r0, #8]
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	strh r1, [r0, #0xe]
	adds r0, r4, #0
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _081C9B16
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r2, r0, #6
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	cmp r2, #1
	beq _081C9ADA
	cmp r2, #1
	bgt _081C9AC8
	cmp r2, #0
	beq _081C9AD2
	b _081C9B10
_081C9AC8:
	cmp r2, #2
	beq _081C9AE2
	cmp r2, #3
	beq _081C9AFC
	b _081C9B10
_081C9AD2:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, #0x80
	b _081C9AE8
_081C9ADA:
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r1, #0x80
	b _081C9B02
_081C9AE2:
	mov r0, sp
	ldrh r1, [r0]
	subs r1, #0xa0
_081C9AE8:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081C9AF8 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	b _081C9B10
	.align 2, 0
_081C9AF8: .4byte 0xFFFF0000
_081C9AFC:
	mov r0, sp
	ldrh r1, [r0, #4]
	subs r1, #0x80
_081C9B02:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081C9B4C @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
_081C9B10:
	mov r0, sp
	bl FUN_081c74cc
_081C9B16:
	cmp r4, #0x1e
	ble _081C9B42
	ldr r4, _081C9B50 @ =FUN_081c9b5c
	movs r3, #0x25
	ldr r0, _081C9B54 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081C9B58 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_081C9B42:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081C9B4C: .4byte 0xFFFF0000
_081C9B50: .4byte FUN_081c9b5c
_081C9B54: .4byte 0x0000046D
_081C9B58: .4byte 0x0000046B

	thumb_func_start FUN_081c9b5c
FUN_081c9b5c: @ 0x081C9B5C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	ldr r0, _081C9B7C @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C9B80
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C9B82
	.align 2, 0
_081C9B7C: .4byte 0x0000046D
_081C9B80:
	movs r0, #0
_081C9B82:
	cmp r0, #0
	beq _081C9BA0
	adds r0, r4, #0
	movs r1, #0x11
	bl FUN_080ef86c
	adds r0, r4, #0
	adds r0, #8
	ldrb r1, [r4, #5]
	movs r2, #0
	bl FUN_081f1498
	ldr r0, _081C9BCC @ =0x000003A5
	bl PlaySound_082406e0
_081C9BA0:
	adds r0, r5, #0
	subs r0, #0xd
	cmp r0, #0xa
	bhi _081C9BB2
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r6, r1
	bl FUN_08236400
_081C9BB2:
	ldr r1, _081C9BD0 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081C9BC4
	ldr r0, _081C9BD4 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_081C9BC4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081C9BCC: .4byte 0x000003A5
_081C9BD0: .4byte 0x0000046E
_081C9BD4: .4byte 0x0000046B

	thumb_func_start FUN_081c9bd8
FUN_081c9bd8: @ 0x081C9BD8
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r0, _081C9BF8 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C9BFC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C9BFE
	.align 2, 0
_081C9BF8: .4byte 0x0000046D
_081C9BFC:
	movs r0, #0
_081C9BFE:
	cmp r0, #0
	beq _081C9C20
	adds r0, r5, #0
	movs r1, #0xf
	bl FUN_080ef86c
	movs r1, #0xe1
	lsls r1, r1, #3
	adds r2, r4, r1
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
	str r0, [r2]
	str r1, [r2, #4]
_081C9C20:
	ldr r1, _081C9C58 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081C9C52
	ldr r4, _081C9C5C @ =FUN_081c9c68
	movs r3, #0x22
	ldr r0, _081C9C60 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081C9C64 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_081C9C52:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081C9C58: .4byte 0x0000046E
_081C9C5C: .4byte FUN_081c9c68
_081C9C60: .4byte 0x0000046D
_081C9C64: .4byte 0x0000046B

	thumb_func_start FUN_081c9c68
FUN_081c9c68: @ 0x081C9C68
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _081C9C88 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C9C8C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C9C8E
	.align 2, 0
_081C9C88: .4byte 0x0000046D
_081C9C8C:
	movs r0, #0
_081C9C8E:
	cmp r0, #0
	bne _081C9C94
	b _081C9E1E
_081C9C94:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	mov r3, sp
	adds r4, r5, #0
	adds r4, #8
	movs r0, #0xe1
	lsls r0, r0, #3
	adds r2, r7, r0
	ldrh r0, [r2]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #4
	ldrsh r1, [r3, r2]
	bl FUN_0823785c
	adds r4, r0, #0
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r2, r0, #6
	subs r1, r4, r2
	cmp r1, #0x80
	ble _081C9CEC
	ldr r0, _081C9CE8 @ =0xFFFFFF00
	b _081C9CF8
	.align 2, 0
_081C9CE8: .4byte 0xFFFFFF00
_081C9CEC:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081C9CFA
	movs r0, #0x80
	lsls r0, r0, #1
_081C9CF8:
	adds r1, r1, r0
_081C9CFA:
	adds r0, r1, #0
	cmp r1, #0
	bge _081C9D02
	rsbs r0, r1, #0
_081C9D02:
	cmp r0, #0xf
	bgt _081C9D58
	mov r3, sp
	movs r6, #0x18
	ldr r2, _081C9D28 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _081C9D2C
	asrs r1, r0, #0xc
	b _081C9D32
	.align 2, 0
_081C9D28: .4byte 0x085B0A08
_081C9D2C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081C9D32:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _081C9D4E
	asrs r0, r0, #0xc
	b _081C9D54
_081C9D4E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081C9D54:
	strh r0, [r3, #4]
	b _081C9DF6
_081C9D58:
	cmp r1, #0
	ble _081C9DA4
	adds r3, r2, #0
	adds r3, #0x10
	movs r1, #0xff
	mov r4, sp
	ands r3, r1
	movs r6, #0x18
	ldr r2, _081C9D84 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _081C9D88
	asrs r1, r0, #0xc
	b _081C9D8E
	.align 2, 0
_081C9D84: .4byte 0x085B0A08
_081C9D88:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081C9D8E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	bge _081C9DEA
	b _081C9DEE
_081C9DA4:
	adds r3, r2, #0
	adds r3, #0xef
	movs r1, #0xff
	mov r4, sp
	ands r3, r1
	movs r6, #0x18
	ldr r2, _081C9DCC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _081C9DD0
	asrs r1, r0, #0xc
	b _081C9DD6
	.align 2, 0
_081C9DCC: .4byte 0x085B0A08
_081C9DD0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081C9DD6:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _081C9DEE
_081C9DEA:
	asrs r0, r0, #0xc
	b _081C9DF4
_081C9DEE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081C9DF4:
	strh r0, [r4, #4]
_081C9DF6:
	mov r0, sp
	ldrh r1, [r0]
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x20
	strh r0, [r1]
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r2, #4
	adds r0, r5, r2
	strh r1, [r0]
	movs r0, #0xe9
	lsls r0, r0, #2
	bl PlaySound_082406e0
_081C9E1E:
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	bl FUN_08236400
	ldr r0, [r5, #0x18]
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081C9E74
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _081C9E46
	asrs r1, r0, #1
	b _081C9E4C
_081C9E46:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081C9E4C:
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	movs r1, #0xe2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _081C9E66
	asrs r1, r0, #1
	b _081C9E6C
_081C9E66:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081C9E6C:
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
_081C9E74:
	adds r0, r5, #0
	movs r1, #5
	bl FUN_080ef86c
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C9EC4
	ldr r4, _081C9ECC @ =FUN_081c9ed8
	movs r3, #0x23
	ldr r0, _081C9ED0 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081C9ED4 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_081C9EC4:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C9ECC: .4byte FUN_081c9ed8
_081C9ED0: .4byte 0x0000046D
_081C9ED4: .4byte 0x0000046B

	thumb_func_start FUN_081c9ed8
FUN_081c9ed8: @ 0x081C9ED8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081C9EF0 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C9EF4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C9EF6
	.align 2, 0
_081C9EF0: .4byte 0x0000046D
_081C9EF4:
	movs r0, #0
_081C9EF6:
	cmp r0, #0
	beq _081C9F02
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_080ef86c
_081C9F02:
	ldr r1, _081C9F1C @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081C9F14
	ldr r0, _081C9F20 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_081C9F14:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081C9F1C: .4byte 0x0000046E
_081C9F20: .4byte 0x0000046B

	thumb_func_start FUN_081c9f24
FUN_081c9f24: @ 0x081C9F24
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081C9F3C @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C9F40
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C9F42
	.align 2, 0
_081C9F3C: .4byte 0x0000046D
_081C9F40:
	movs r0, #0
_081C9F42:
	cmp r0, #0
	beq _081C9F4E
	adds r0, r4, #0
	movs r1, #0xe
	bl FUN_080ef86c
_081C9F4E:
	ldr r1, _081C9F68 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081C9F60
	ldr r0, _081C9F6C @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_081C9F60:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081C9F68: .4byte 0x0000046E
_081C9F6C: .4byte 0x0000046B

	thumb_func_start FUN_081c9f70
FUN_081c9f70: @ 0x081C9F70
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, _081C9F88 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C9F8C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C9F8E
	.align 2, 0
_081C9F88: .4byte 0x0000046D
_081C9F8C:
	movs r0, #0
_081C9F8E:
	cmp r0, #0
	beq _081C9FB2
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r0, #0x80
	lsls r0, r0, #3
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _081CA038 @ =0x00000482
	adds r1, r6, r2
	movs r0, #2
	strh r0, [r1]
_081C9FB2:
	ldr r3, _081CA03C @ =0x00000542
	adds r5, r6, r3
	ldrb r1, [r5]
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	ble _081CA0AC
	cmp r4, #0x14
	bgt _081C9FC6
	b _081CA128
_081C9FC6:
	movs r1, #3
	movs r2, #1
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r6, r4
	movs r3, #0
	strb r1, [r0]
	ldr r7, _081CA040 @ =0x00000469
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _081CA044 @ =0x0000046A
	adds r0, r6, r1
	strb r3, [r0]
	adds r4, #0x1c
	adds r0, r6, r4
	str r3, [r0]
	adds r7, #3
	adds r0, r6, r7
	strb r2, [r0]
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r4, [r0]
	movs r1, #2
	adds r7, #1
	adds r0, r6, r7
	strb r2, [r0]
	ldr r2, _081CA048 @ =0x0000046B
	adds r0, r6, r2
	strb r3, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r3, [r0]
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #1
	bne _081CA050
	ldr r3, _081CA04C @ =0x00000541
	adds r0, r6, r3
	ldrb r0, [r0]
	lsrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r4, #0xee
	lsls r4, r4, #1
	adds r1, r6, r4
	b _081CA08C
	.align 2, 0
_081CA038: .4byte 0x00000482
_081CA03C: .4byte 0x00000542
_081CA040: .4byte 0x00000469
_081CA044: .4byte 0x0000046A
_081CA048: .4byte 0x0000046B
_081CA04C: .4byte 0x00000541
_081CA050:
	movs r1, #0
	ldrb r4, [r6, #5]
	ldr r7, _081CA09C @ =0x0203B400
	mov ip, r7
	ldr r2, _081CA0A0 @ =0x030046B8
	ldr r7, _081CA0A4 @ =0x000003FF
	movs r5, #3
	adds r3, r4, #0
_081CA060:
	ldr r0, [r2]
	adds r0, #1
	ands r0, r7
	str r0, [r2]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	ands r0, r5
	lsls r0, r0, #6
	cmp r0, r3
	bne _081CA07E
	adds r1, #1
	cmp r1, #3
	ble _081CA060
	adds r0, r4, #0
_081CA07E:
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r6, r2
_081CA08C:
	strb r0, [r1]
	ldr r3, _081CA0A8 @ =0x00000542
	adds r1, r6, r3
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	b _081CA128
	.align 2, 0
_081CA09C: .4byte 0x0203B400
_081CA0A0: .4byte 0x030046B8
_081CA0A4: .4byte 0x000003FF
_081CA0A8: .4byte 0x00000542
_081CA0AC:
	movs r0, #0xff
	orrs r0, r1
	strb r0, [r5]
	cmp r4, #6
	ble _081CA128
	ldr r4, _081CA130 @ =0x0000054F
	adds r0, r6, r4
	ldrb r2, [r0]
	movs r7, #0xa9
	lsls r7, r7, #3
	adds r0, r6, r7
	ldr r3, [r0]
	ldr r1, _081CA134 @ =0x0000046D
	adds r0, r6, r1
	movs r1, #0
	movs r5, #1
	strb r5, [r0]
	subs r4, #0xe4
	adds r0, r6, r4
	strb r1, [r0]
	adds r7, #0xb
	adds r0, r6, r7
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r1, [r0]
	adds r4, #0xe1
	adds r0, r6, r4
	ldrb r2, [r0]
	subs r7, #6
	adds r0, r6, r7
	ldrb r3, [r0]
	adds r4, #2
	adds r0, r6, r4
	ldrb r4, [r0]
	subs r7, #0xe5
	adds r0, r6, r7
	strb r2, [r0]
	ldr r2, _081CA138 @ =0x00000469
	adds r0, r6, r2
	strb r3, [r0]
	ldr r3, _081CA13C @ =0x0000046A
	adds r0, r6, r3
	strb r4, [r0]
	ldr r4, _081CA140 @ =0x00000484
	adds r0, r6, r4
	str r1, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, _081CA144 @ =0xFFFFFBFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081CA128:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081CA130: .4byte 0x0000054F
_081CA134: .4byte 0x0000046D
_081CA138: .4byte 0x00000469
_081CA13C: .4byte 0x0000046A
_081CA140: .4byte 0x00000484
_081CA144: .4byte 0xFFFFFBFF

	thumb_func_start FUN_081ca148
FUN_081ca148: @ 0x081CA148
	bx lr
	.align 2, 0

	thumb_func_start FUN_081ca14c
FUN_081ca14c: @ 0x081CA14C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _081CA170 @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081CA174
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081CA176
	.align 2, 0
_081CA170: .4byte 0x0000046D
_081CA174:
	movs r0, #0
_081CA176:
	cmp r0, #0
	bne _081CA24A
	adds r0, r4, #0
	movs r1, #0xb
	bl FUN_080ef86c
	adds r0, r4, #0
	bl FUN_081c70c8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CA24A
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r3, _081CA1C4 @ =0x000004A4
	adds r0, r4, r3
	ldr r6, [r0]
	adds r7, r4, #0
	adds r7, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	adds r5, r0, #0
	adds r5, #8
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081CA1C8
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	b _081CA1EE
	.align 2, 0
_081CA1C4: .4byte 0x000004A4
_081CA1C8:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081CA1E8
	cmp r0, #2
	beq _081CA1E4
	adds r0, r4, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CA1E4:
	movs r0, #1
	b _081CA1F8
_081CA1E8:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r4, r3
_081CA1EE:
	ldr r1, _081CA20C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081CA1F8:
	cmp r0, #0
	bne _081CA214
	ldr r1, _081CA210 @ =0x000005C4
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	b _081CA24A
	.align 2, 0
_081CA20C: .4byte 0xFFFFFDFF
_081CA210: .4byte 0x000005C4
_081CA214:
	movs r2, #0xd5
	lsls r2, r2, #3
	add r2, r8
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r2, #0x11
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _081CA254 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
_081CA24A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081CA254: .4byte 0x00000484

	thumb_func_start FUN_081ca258
FUN_081ca258: @ 0x081CA258
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r3, [r0]
	ldr r2, _081CA278 @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081CA27C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081CA27E
	.align 2, 0
_081CA278: .4byte 0x0000046D
_081CA27C:
	movs r0, #0
_081CA27E:
	cmp r0, #0
	beq _081CA284
	b _081CA3A2
_081CA284:
	movs r2, #4
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _081CA29A
	movs r0, #1
	b _081CA29C
_081CA29A:
	movs r0, #0
_081CA29C:
	cmp r0, #0
	bne _081CA2A2
	b _081CA39A
_081CA2A2:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, _081CA2E8 @ =0x000006BC
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bls _081CA2F0
	movs r2, #0x13
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _081CA2EC @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bge _081CA376
	b _081CA384
	.align 2, 0
_081CA2E8: .4byte 0x000006BC
_081CA2EC: .4byte 0x00000484
_081CA2F0:
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
	ldr r1, _081CA33C @ =0x000006D7
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _081CA344
	ldrb r1, [r4, #5]
	adds r0, r4, #0
	bl FUN_081c6db8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CA3A2
	movs r2, #0x11
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _081CA340 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	b _081CA3A2
	.align 2, 0
_081CA33C: .4byte 0x000006D7
_081CA340: .4byte 0x00000484
_081CA344:
	movs r2, #0x13
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081CA37C @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _081CA380 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	blt _081CA384
_081CA376:
	asrs r0, r0, #5
	b _081CA38A
	.align 2, 0
_081CA37C: .4byte 0x00000469
_081CA380: .4byte 0x00000484
_081CA384:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081CA38A:
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r4, r2
	strb r0, [r1]
	b _081CA3A2
_081CA39A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080ef86c
_081CA3A2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081ca3a8
FUN_081ca3a8: @ 0x081CA3A8
	push {r4, r5, r6, lr}
	sub sp, #0x28
	adds r5, r0, #0
	ldr r0, _081CA3C0 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081CA3C4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081CA3C6
	.align 2, 0
_081CA3C0: .4byte 0x0000046D
_081CA3C4:
	movs r0, #0
_081CA3C6:
	cmp r0, #0
	beq _081CA43A
	adds r0, r5, #0
	movs r1, #0xa
	bl FUN_080ef86c
	ldr r1, _081CA500 @ =0x0000046E
	adds r0, r5, r1
	movs r4, #0
	strb r4, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r5, #0
	movs r1, #3
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r5, #0
	movs r1, #4
	bl FUN_080e64b4
	adds r0, r5, #0
	bl FUN_080e8360
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r2, r5, r6
	ldr r1, _081CA504 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _081CA508 @ =0x0000021E
	adds r0, r5, r1
	strh r4, [r0]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r4, [r0]
	adds r6, #0x8a
	adds r0, r5, r6
	strh r4, [r0]
	adds r2, r5, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_081CA43A:
	adds r0, r5, #0
	bl FUN_080e499c
	adds r0, r5, #0
	bl FUN_080e4b3c
	adds r0, r5, #0
	bl FUN_080e4e20
	ldr r1, _081CA500 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081CA458
	b _081CA600
_081CA458:
	subs r1, #0x6e
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r4, [r0]
	ands r4, r1
	cmp r4, #0
	bne _081CA46A
	b _081CA5D8
_081CA46A:
	ldr r6, _081CA50C @ =0x0000046B
	adds r0, r5, r6
	movs r4, #1
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_081c6cf0
	movs r0, #0xcd
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r2]
	cmp r0, #0
	beq _081CA4D8
	movs r1, #8
	ldrsh r0, [r5, r1]
	str r0, [sp]
	movs r6, #0xa
	ldrsh r0, [r5, r6]
	str r0, [sp, #4]
	movs r1, #0xc
	ldrsh r0, [r5, r1]
	str r0, [sp, #8]
	movs r6, #0xce
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x10]
	adds r6, #8
	adds r0, r5, r6
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldrh r0, [r5]
	str r0, [sp, #0x1c]
	ldr r1, _081CA510 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r6, sp
	str r6, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_081CA4D8:
	ldr r1, _081CA514 @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r5, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _081CA51C
	ldr r0, _081CA518 @ =0x030046A0
	ldr r2, [r0]
	movs r6, #0xe2
	lsls r6, r6, #2
	adds r2, r2, r6
	adds r1, r4, #0
	lsls r1, r3
	b _081CA52E
	.align 2, 0
_081CA500: .4byte 0x0000046E
_081CA504: .4byte 0xFFFEBE3F
_081CA508: .4byte 0x0000021E
_081CA50C: .4byte 0x0000046B
_081CA510: .4byte 0xFFFF0000
_081CA514: .4byte 0x000001DF
_081CA518: .4byte 0x030046A0
_081CA51C:
	ldr r0, _081CA5B8 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_081CA52E:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #7
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _081CA596
	ldr r3, _081CA5BC @ =FUN_080e48d0
	movs r2, #0x10
	ldr r6, _081CA5C0 @ =0x0000046D
	adds r0, r5, r6
	movs r1, #1
	strb r1, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r2, #0
	strh r4, [r0]
	movs r3, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _081CA5C4 @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r4, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
_081CA596:
	movs r6, #0x9a
	lsls r6, r6, #2
	adds r0, r5, r6
	bl FUN_080136b4
	movs r2, #1
	ldr r1, _081CA5C8 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081CA5CC
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081CA600
	.align 2, 0
_081CA5B8: .4byte 0x030046A0
_081CA5BC: .4byte FUN_080e48d0
_081CA5C0: .4byte 0x0000046D
_081CA5C4: .4byte 0x0000046A
_081CA5C8: .4byte 0x0000025D
_081CA5CC:
	ldr r1, [r5, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	b _081CA600
_081CA5D8:
	ldr r3, _081CA608 @ =FUN_081ca614
	movs r2, #0x26
	ldr r6, _081CA60C @ =0x0000046D
	adds r1, r5, r6
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081CA610 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
_081CA600:
	add sp, #0x28
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081CA608: .4byte FUN_081ca614
_081CA60C: .4byte 0x0000046D
_081CA610: .4byte 0x0000046B

	thumb_func_start FUN_081ca614
FUN_081ca614: @ 0x081CA614
	push {r4, r5, r6, lr}
	sub sp, #0x28
	adds r5, r0, #0
	adds r4, r1, #0
	bl FUN_080e499c
	adds r0, r5, #0
	bl FUN_080e4b3c
	adds r0, r5, #0
	bl FUN_080e4e20
	ldr r0, [r5, #0x44]
	adds r1, r4, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_082375c8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CA640
	b _081CA7A4
_081CA640:
	ldr r1, _081CA6D8 @ =0x0000046B
	adds r0, r5, r1
	movs r4, #1
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_081c6cf0
	movs r6, #0xcd
	lsls r6, r6, #1
	adds r2, r5, r6
	ldrh r0, [r2]
	cmp r0, #0
	beq _081CA6AE
	movs r1, #8
	ldrsh r0, [r5, r1]
	str r0, [sp]
	movs r6, #0xa
	ldrsh r0, [r5, r6]
	str r0, [sp, #4]
	movs r1, #0xc
	ldrsh r0, [r5, r1]
	str r0, [sp, #8]
	movs r6, #0xce
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x10]
	adds r6, #8
	adds r0, r5, r6
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldrh r0, [r5]
	str r0, [sp, #0x1c]
	ldr r1, _081CA6DC @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r6, sp
	str r6, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_081CA6AE:
	ldr r1, _081CA6E0 @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r5, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _081CA6E8
	ldr r0, _081CA6E4 @ =0x030046A0
	ldr r2, [r0]
	movs r6, #0xe2
	lsls r6, r6, #2
	adds r2, r2, r6
	adds r1, r4, #0
	lsls r1, r3
	b _081CA6FA
	.align 2, 0
_081CA6D8: .4byte 0x0000046B
_081CA6DC: .4byte 0xFFFF0000
_081CA6E0: .4byte 0x000001DF
_081CA6E4: .4byte 0x030046A0
_081CA6E8:
	ldr r0, _081CA784 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_081CA6FA:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #7
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _081CA762
	ldr r3, _081CA788 @ =FUN_080e48d0
	movs r2, #0x10
	ldr r6, _081CA78C @ =0x0000046D
	adds r0, r5, r6
	movs r1, #1
	strb r1, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r2, #0
	strh r4, [r0]
	movs r3, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _081CA790 @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r4, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
_081CA762:
	movs r6, #0x9a
	lsls r6, r6, #2
	adds r0, r5, r6
	bl FUN_080136b4
	movs r2, #1
	ldr r1, _081CA794 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081CA798
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081CA7EA
	.align 2, 0
_081CA784: .4byte 0x030046A0
_081CA788: .4byte FUN_080e48d0
_081CA78C: .4byte 0x0000046D
_081CA790: .4byte 0x0000046A
_081CA794: .4byte 0x0000025D
_081CA798:
	ldr r1, [r5, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	b _081CA7EA
_081CA7A4:
	movs r1, #1
	ldr r2, _081CA7BC @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081CA7C0
	ldr r0, [r5, #0x44]
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081CA7CA
	b _081CA7CE
	.align 2, 0
_081CA7BC: .4byte 0x0000025D
_081CA7C0:
	ldr r0, [r5, #0x44]
	ldr r0, [r0, #0x28]
	ands r0, r1
	cmp r0, #0
	beq _081CA7CE
_081CA7CA:
	movs r0, #1
	b _081CA7D0
_081CA7CE:
	movs r0, #0
_081CA7D0:
	cmp r0, #0
	beq _081CA7E0
	movs r6, #0x9a
	lsls r6, r6, #2
	adds r0, r5, r6
	bl FUN_080136b4
	b _081CA7EA
_081CA7E0:
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r5, r1
	bl FUN_08013698
_081CA7EA:
	add sp, #0x28
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081ca7f4
FUN_081ca7f4: @ 0x081CA7F4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081CA80C @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081CA810
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081CA812
	.align 2, 0
_081CA80C: .4byte 0x0000046C
_081CA810:
	movs r0, #0
_081CA812:
	cmp r0, #0
	beq _081CA890
	ldr r4, _081CA8A4 @ =FUN_081c87c8
	movs r3, #0xa
	ldr r2, _081CA8A8 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081CA8AC @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	strb r0, [r5, #5]
	adds r1, #0x17
	adds r0, r5, r1
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080e5718
	adds r0, r5, #0
	bl FUN_080e6750
	ldr r2, _081CA8B0 @ =0x000001DF
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _081CA874
	movs r0, #4
	ldr r1, _081CA8B4 @ =0x00000222
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081CA874:
	movs r0, #0x80
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
_081CA890:
	ldr r1, _081CA8AC @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081CA8B8
	adds r0, r5, #0
	bl FUN_081c6048
	b _081CA8C2
	.align 2, 0
_081CA8A4: .4byte FUN_081c87c8
_081CA8A8: .4byte 0x0000046D
_081CA8AC: .4byte 0x0000046B
_081CA8B0: .4byte 0x000001DF
_081CA8B4: .4byte 0x00000222
_081CA8B8:
	ldr r2, _081CA8C8 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081CA8C2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081CA8C8: .4byte 0x00000484

	thumb_func_start FUN_081ca8cc
FUN_081ca8cc: @ 0x081CA8CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x5c
	adds r7, r0, #0
	ldr r0, _081CAA30 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081CA8E8
	movs r0, #0
	strb r0, [r1]
_081CA8E8:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CA900
	bl _081CB128
_081CA900:
	adds r0, r7, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _081CA912
	bl _081CB128
_081CA912:
	ldr r2, _081CAA34 @ =0x00000484
	adds r1, r7, r2
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _081CA920
	bl FUN_081cb124
_081CA920:
	ldr r3, _081CAA38 @ =0x000001DF
	adds r0, r7, r3
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl FUN_080e5718
	movs r0, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #8]
	strb r0, [r4]
	ldr r5, _081CAA3C @ =0x00000469
	adds r5, r7, r5
	str r5, [sp, #0xc]
	movs r0, #1
	strb r0, [r5]
	ldr r1, _081CAA40 @ =0x0000046A
	adds r1, r7, r1
	str r1, [sp, #0x10]
	strb r6, [r1]
	ldr r2, _081CAA34 @ =0x00000484
	adds r2, r2, r7
	mov sl, r2
	str r6, [r2]
	ldr r3, _081CAA30 @ =0x0000046C
	adds r3, r3, r7
	mov ip, r3
	strb r0, [r3]
	ldr r1, _081CAA44 @ =FUN_080e6794
	movs r0, #0xe
	ldr r4, _081CAA48 @ =0x0000046D
	adds r4, r4, r7
	mov sb, r4
	movs r5, #1
	strb r5, [r4]
	ldr r2, _081CAA4C @ =0x0000046B
	adds r2, r2, r7
	mov r8, r2
	strb r6, [r2]
	ldr r3, _081CAA50 @ =0x00000553
	adds r5, r7, r3
	strb r0, [r5]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r4, r7, r0
	str r1, [r4]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r3, r7, r1
	strh r6, [r3]
	movs r0, #0x80
	subs r1, #0x48
	adds r2, r7, r1
	ldrh r1, [r2]
	ands r1, r0
	mov r0, ip
	str r0, [sp, #0x44]
	ldr r0, [sp, #8]
	str r0, [sp, #0x34]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x38]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x3c]
	mov r0, sl
	str r0, [sp, #0x50]
	mov r0, sb
	str r0, [sp, #0x48]
	mov r0, r8
	str r0, [sp, #0x40]
	str r5, [sp, #0x24]
	str r4, [sp, #0x2c]
	str r3, [sp, #0x28]
	mov sl, r2
	cmp r1, #0
	bne _081CA9BE
	b _081CAF58
_081CA9BE:
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r3, [r0]
	movs r4, #0xc
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081CAA54 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	movs r0, #0x95
	lsls r0, r0, #3
	adds r3, r7, r0
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r6, r3, #0
	mov r8, r2
	cmp r4, #0
	blt _081CAA2A
	cmp r1, #0
	blt _081CAA2A
	ldr r0, _081CAA58 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081CAA2A
	ldr r0, _081CAA5C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CAA60
_081CAA2A:
	movs r4, #0
	b _081CAA6E
	.align 2, 0
_081CAA30: .4byte 0x0000046C
_081CAA34: .4byte 0x00000484
_081CAA38: .4byte 0x000001DF
_081CAA3C: .4byte 0x00000469
_081CAA40: .4byte 0x0000046A
_081CAA44: .4byte FUN_080e6794
_081CAA48: .4byte 0x0000046D
_081CAA4C: .4byte 0x0000046B
_081CAA50: .4byte 0x00000553
_081CAA54: .4byte 0x00000551
_081CAA58: .4byte 0x030046A8
_081CAA5C: .4byte 0x030046AC
_081CAA60:
	ldr r0, _081CAA80 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081CAA6E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CAA84
	adds r0, #4
	b _081CAA90
	.align 2, 0
_081CAA80: .4byte 0x030046A4
_081CAA84:
	ldr r0, _081CAAA4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CAA90:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CAAA8
	cmp r2, #2
	beq _081CAAAC
	b _081CAAB0
	.align 2, 0
_081CAAA4: .4byte 0x030046A4
_081CAAA8:
	ldrb r0, [r5, #4]
	b _081CAAAE
_081CAAAC:
	ldrb r0, [r5]
_081CAAAE:
	subs r1, r1, r0
_081CAAB0:
	strh r1, [r5, #2]
	ldr r0, _081CAAC4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081CAAC8
	movs r0, #1
	b _081CAACA
	.align 2, 0
_081CAAC4: .4byte 0x030047A4
_081CAAC8:
	movs r0, #0
_081CAACA:
	cmp r0, #0
	beq _081CAB08
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081CAAEA
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081CAAE6
	adds r2, r0, #0
_081CAAE6:
	cmp r2, #0
	bge _081CAAF4
_081CAAEA:
	ldr r2, _081CAAF0 @ =0x000005C4
	adds r0, r7, r2
	b _081CAF46
	.align 2, 0
_081CAAF0: .4byte 0x000005C4
_081CAAF4:
	ldr r1, _081CAB04 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081CAB50
	.align 2, 0
_081CAB04: .4byte 0x03002BE0
_081CAB08:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081CAB34
	cmp r1, #0
	blt _081CAB34
	ldr r0, _081CAB38 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CAB34
	ldr r0, _081CAB3C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CAB40
_081CAB34:
	movs r5, #0
	b _081CAB4E
	.align 2, 0
_081CAB38: .4byte 0x030046A8
_081CAB3C: .4byte 0x030046AC
_081CAB40:
	ldr r0, _081CABE0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081CAB4E:
	movs r2, #0
_081CAB50:
	ldr r4, _081CABE4 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _081CAB70
	ldr r1, _081CABE8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081CAB70
	b _081CAE84
_081CAB70:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081CAB84
	b _081CB128
_081CAB84:
	ldr r0, _081CABEC @ =0x00000222
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	mov r3, sl
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sb, r2
	cmp r3, #0
	beq _081CABF0
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x48]
	strb r2, [r3]
	ldr r3, [sp, #0x40]
	strb r5, [r3]
	ldr r3, [sp, #0x24]
	strb r0, [r3]
	ldr r0, [sp, #0x2c]
	str r1, [r0]
	ldr r1, [sp, #0x28]
	strh r4, [r1]
	movs r0, #0xc
	ldr r3, [sp, #0x34]
	strb r5, [r3]
	ldr r1, [sp, #0x38]
	strb r5, [r1]
	ldr r3, [sp, #0x3c]
	strb r0, [r3]
	ldr r5, [sp, #0x50]
	str r4, [r5]
	ldr r0, [sp, #0x44]
	strb r2, [r0]
	b _081CAD3E
	.align 2, 0
_081CABE0: .4byte 0x030046A4
_081CABE4: .4byte 0x00000256
_081CABE8: .4byte 0x03002BE0
_081CABEC: .4byte 0x00000222
_081CABF0:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x48]
	strb r0, [r2]
	ldr r4, [sp, #0x40]
	strb r5, [r4]
	ldr r2, [sp, #0x24]
	strb r0, [r2]
	ldr r4, [sp, #0x2c]
	str r1, [r4]
	ldr r1, [sp, #0x28]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x34]
	strb r5, [r2]
	ldr r4, [sp, #0x38]
	strb r5, [r4]
	ldr r5, [sp, #0x3c]
	strb r1, [r5]
	ldr r1, [sp, #0x50]
	str r3, [r1]
	ldr r2, [sp, #0x44]
	strb r0, [r2]
	ldr r5, [r6]
	mov r3, r8
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081CAC54
	cmp r1, #0
	blt _081CAC54
	ldr r0, _081CAC58 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CAC54
	ldr r0, _081CAC5C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CAC60
_081CAC54:
	movs r4, #0
	b _081CAC6E
	.align 2, 0
_081CAC58: .4byte 0x030046A8
_081CAC5C: .4byte 0x030046AC
_081CAC60:
	ldr r0, _081CAC80 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081CAC6E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CAC84
	adds r0, #4
	b _081CAC90
	.align 2, 0
_081CAC80: .4byte 0x030046A4
_081CAC84:
	ldr r0, _081CACA4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CAC90:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CACA8
	cmp r2, #2
	beq _081CACAC
	b _081CACB0
	.align 2, 0
_081CACA4: .4byte 0x030046A4
_081CACA8:
	ldrb r0, [r5, #4]
	b _081CACAE
_081CACAC:
	ldrb r0, [r5]
_081CACAE:
	subs r1, r1, r0
_081CACB0:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081CACD8
	cmp r1, #0
	blt _081CACD8
	ldr r0, _081CACDC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CACD8
	ldr r0, _081CACE0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CACE4
_081CACD8:
	movs r4, #0
	b _081CACF2
	.align 2, 0
_081CACDC: .4byte 0x030046A8
_081CACE0: .4byte 0x030046AC
_081CACE4:
	ldr r0, _081CAD04 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081CACF2:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CAD08
	adds r0, #4
	b _081CAD14
	.align 2, 0
_081CAD04: .4byte 0x030046A4
_081CAD08:
	ldr r0, _081CAD28 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CAD14:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081CAD2C
	cmp r3, #2
	beq _081CAD30
	b _081CAD34
	.align 2, 0
_081CAD28: .4byte 0x030046A4
_081CAD2C:
	ldrb r0, [r5, #4]
	b _081CAD32
_081CAD30:
	ldrb r0, [r5]
_081CAD32:
	subs r2, r2, r0
_081CAD34:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081CAD3E:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x14]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	adds r1, #0x82
	adds r1, r7, r1
	str r1, [sp, #0x4c]
	cmp r0, #0
	bne _081CAE48
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081CAD68
	movs r0, #1
	b _081CAD6A
_081CAD68:
	movs r0, #0
_081CAD6A:
	ldr r3, _081CAE58 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x4c]
	cmp r0, #0
	bne _081CAE48
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r0, _081CAE5C @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _081CAE60 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x18]
	ldr r2, _081CAE64 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x1c]
	ldr r4, _081CAE68 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x20]
	ldr r5, _081CAE6C @ =0x00000541
	adds r5, r7, r5
	str r5, [sp, #0x54]
	ldr r0, _081CAE70 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x30]
	ldr r1, _081CAE74 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x58]
	ldr r6, _081CAE78 @ =0x0203B400
	ldr r1, _081CAE7C @ =0x030046B8
	ldr r5, _081CAE80 @ =0x000003FF
	movs r2, #3
	mov r4, r8
_081CADBA:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r2
	lsls r0, r0, #6
	cmp r0, r4
	bne _081CADD8
	adds r3, #1
	cmp r3, #3
	ble _081CADBA
	mov r0, r8
_081CADD8:
	movs r3, #0
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x2c]
	ldr r0, [r4]
	mov r5, sl
	str r0, [r5]
	ldr r1, [sp, #0x24]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x34]
	ldrb r0, [r4]
	ldr r5, [sp, #0x18]
	strb r0, [r5]
	ldr r1, [sp, #0x38]
	ldrb r0, [r1]
	ldr r2, [sp, #0x1c]
	strb r0, [r2]
	ldr r4, [sp, #0x3c]
	ldrb r0, [r4]
	ldr r5, [sp, #0x20]
	strb r0, [r5]
	mov r0, sp
	ldrb r1, [r0, #0x14]
	ldr r0, [sp, #0x54]
	strb r1, [r0]
	ldr r4, [sp, #0x30]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x48]
	strb r1, [r5]
	ldr r4, [sp, #0x40]
	strb r3, [r4]
	ldr r5, [sp, #0x24]
	strb r0, [r5]
	ldr r0, [sp, #0x2c]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x28]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x34]
	strb r0, [r5]
	ldr r0, [sp, #0x38]
	strb r1, [r0]
	ldr r4, [sp, #0x3c]
	strb r2, [r4]
	ldr r5, [sp, #0x50]
	str r3, [r5]
	ldr r0, [sp, #0x44]
	strb r1, [r0]
	movs r0, #6
	ldr r1, [sp, #0x58]
	strb r0, [r1]
_081CAE48:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r2, [sp, #0x4c]
	strh r0, [r2]
	b _081CB128
	.align 2, 0
_081CAE58: .4byte 0x00000482
_081CAE5C: .4byte 0x0000054F
_081CAE60: .4byte 0x0000054C
_081CAE64: .4byte 0x0000054D
_081CAE68: .4byte 0x0000054E
_081CAE6C: .4byte 0x00000541
_081CAE70: .4byte 0x000005BC
_081CAE74: .4byte 0x00000542
_081CAE78: .4byte 0x0203B400
_081CAE7C: .4byte 0x030046B8
_081CAE80: .4byte 0x000003FF
_081CAE84:
	mov sb, sp
	ldr r6, _081CAEC0 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CAEC4
	adds r0, #4
	b _081CAECE
	.align 2, 0
_081CAEC0: .4byte 0x030046A4
_081CAEC4:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081CAECE:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r3, sb
	strh r0, [r3, #2]
	mov r4, r8
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r3, #4]
	ldr r5, _081CAF08 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _081CAF10
	ldr r0, _081CAF0C @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081CAF3A
	.align 2, 0
_081CAF08: .4byte 0x000004A4
_081CAF0C: .4byte 0xFFFFFDFF
_081CAF10:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081CAF30
	cmp r0, #2
	beq _081CAF2C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CAF2C:
	movs r0, #1
	b _081CAF3C
_081CAF30:
	ldr r0, _081CAF50 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081CAF3A:
	movs r0, #0
_081CAF3C:
	cmp r0, #0
	beq _081CAF42
	b _081CB128
_081CAF42:
	ldr r4, _081CAF54 @ =0x000005C4
	adds r0, r7, r4
_081CAF46:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081CB128
	.align 2, 0
_081CAF50: .4byte 0xFFFFFDFF
_081CAF54: .4byte 0x000005C4
_081CAF58:
	movs r1, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081CAF6A
	b _081CB0E6
_081CAF6A:
	ldr r3, _081CAFD0 @ =FUN_081c7fb4
	movs r4, #7
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r5, _081CAFD4 @ =0x00000554
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081CAFD8 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	subs r1, #0xa8
	adds r0, r7, r1
	ldr r5, [r0]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081CAFCA
	cmp r1, #0
	blt _081CAFCA
	ldr r0, _081CAFDC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CAFCA
	ldr r0, _081CAFE0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CAFE4
_081CAFCA:
	movs r4, #0
	b _081CAFF2
	.align 2, 0
_081CAFD0: .4byte FUN_081c7fb4
_081CAFD4: .4byte 0x00000554
_081CAFD8: .4byte 0x00000551
_081CAFDC: .4byte 0x030046A8
_081CAFE0: .4byte 0x030046AC
_081CAFE4:
	ldr r0, _081CB004 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081CAFF2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CB008
	adds r0, #4
	b _081CB014
	.align 2, 0
_081CB004: .4byte 0x030046A4
_081CB008:
	ldr r0, _081CB028 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CB014:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CB02C
	cmp r2, #2
	beq _081CB030
	b _081CB034
	.align 2, 0
_081CB028: .4byte 0x030046A4
_081CB02C:
	ldrb r0, [r5, #4]
	b _081CB032
_081CB030:
	ldrb r0, [r5]
_081CB032:
	subs r1, r1, r0
_081CB034:
	strh r1, [r5, #2]
	ldr r2, _081CB064 @ =0x000004A4
	adds r0, r7, r2
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081CB06C
	ldr r0, _081CB068 @ =0xFFFFFDFF
	mov r4, sl
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	b _081CB096
	.align 2, 0
_081CB064: .4byte 0x000004A4
_081CB068: .4byte 0xFFFFFDFF
_081CB06C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081CB08C
	cmp r0, #2
	beq _081CB088
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CB088:
	movs r0, #1
	b _081CB098
_081CB08C:
	ldr r0, _081CB0D0 @ =0xFFFFFDFF
	mov r5, sl
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
_081CB096:
	movs r0, #0
_081CB098:
	adds r3, r0, #0
	cmp r3, #0
	bne _081CB0D8
	ldr r0, _081CB0D4 @ =FUN_080e48d0
	movs r2, #1
	ldr r1, [sp, #0x48]
	strb r2, [r1]
	ldr r4, [sp, #0x40]
	strb r3, [r4]
	ldr r5, [sp, #0x24]
	strb r3, [r5]
	ldr r1, [sp, #0x2c]
	str r0, [r1]
	movs r1, #0
	ldr r4, [sp, #0x28]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x34]
	strb r0, [r5]
	ldr r0, [sp, #0x38]
	strb r1, [r0]
	ldr r4, [sp, #0x3c]
	strb r1, [r4]
	ldr r5, [sp, #0x50]
	str r3, [r5]
	ldr r0, [sp, #0x44]
	strb r2, [r0]
	b _081CB128
	.align 2, 0
_081CB0D0: .4byte 0xFFFFFDFF
_081CB0D4: .4byte FUN_080e48d0
_081CB0D8:
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	b _081CB128
_081CB0E6:
	ldr r3, _081CB11C @ =FUN_081c7fb4
	movs r4, #2
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081CB120 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	subs r1, #0xce
	adds r0, r7, r1
	movs r2, #1
	strh r2, [r0]
	b _081CB128
	.align 2, 0
_081CB11C: .4byte FUN_081c7fb4
_081CB120: .4byte 0x00000551

	thumb_func_start FUN_081cb124
FUN_081cb124: @ 0x081CB124
	adds r0, #1
	str r0, [r1]
_081CB128:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081cb138
FUN_081cb138: @ 0x081CB138
	movs r1, #0xc7
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, _081CB144 @ =0x085AE038
	str r1, [r0]
	bx lr
	.align 2, 0
_081CB144: .4byte 0x085AE038

	thumb_func_start FUN_081cb148
FUN_081cb148: @ 0x081CB148
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _081CB168 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081CB16C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081CB16E
	.align 2, 0
_081CB168: .4byte 0x0000046C
_081CB16C:
	movs r0, #0
_081CB16E:
	cmp r0, #0
	beq _081CB212
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r2, r7, r3
	movs r1, #9
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r6, r4
	ldrh r1, [r2]
	movs r5, #0
	movs r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r3, _081CB240 @ =FUN_081c9bd8
	movs r2, #0x21
	ldr r0, _081CB244 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081CB248 @ =0x0000046B
	adds r0, r6, r1
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r4, [r0]
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r1, r1, r0
	movs r2, #3
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r2, _081CB24C @ =0x00000226
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r3, #0x66
	adds r2, r6, r3
	ldrh r2, [r2]
	adds r4, #0x74
	adds r3, r6, r4
	ldr r3, [r3]
	str r3, [sp]
	subs r4, #0xa
	adds r3, r6, r4
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_082364f8
	ldr r1, _081CB250 @ =0x000006D7
	adds r0, r7, r1
	strb r5, [r0]
	ldr r2, _081CB254 @ =0x000006CC
	adds r0, r7, r2
	ldrh r1, [r0]
	movs r3, #0xd9
	lsls r3, r3, #3
	adds r0, r7, r3
	strh r1, [r0]
_081CB212:
	ldr r4, _081CB248 @ =0x0000046B
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _081CB25C
	ldr r1, _081CB254 @ =0x000006CC
	adds r0, r7, r1
	ldrh r1, [r0]
	movs r2, #0xd9
	lsls r2, r2, #3
	adds r0, r7, r2
	strh r1, [r0]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
	ldr r0, _081CB258 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r6, #0
	bl FUN_081c7228
	b _081CB266
	.align 2, 0
_081CB240: .4byte FUN_081c9bd8
_081CB244: .4byte 0x0000046D
_081CB248: .4byte 0x0000046B
_081CB24C: .4byte 0x00000226
_081CB250: .4byte 0x000006D7
_081CB254: .4byte 0x000006CC
_081CB258: .4byte 0xFFFFFEFF
_081CB25C:
	ldr r4, _081CB270 @ =0x00000484
	adds r1, r6, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081CB266:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081CB270: .4byte 0x00000484

	thumb_func_start FUN_081cb274
FUN_081cb274: @ 0x081CB274
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _081CB294 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081CB298
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081CB29A
	.align 2, 0
_081CB294: .4byte 0x0000046C
_081CB298:
	movs r0, #0
_081CB29A:
	cmp r0, #0
	beq _081CB330
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r2, r7, r3
	movs r1, #9
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r6, r4
	ldrh r1, [r2]
	movs r5, #0
	movs r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r3, _081CB35C @ =FUN_081c9a60
	movs r2, #0x24
	ldr r0, _081CB360 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081CB364 @ =0x0000046B
	adds r0, r6, r1
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r4, [r0]
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	movs r2, #2
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r1, r1, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r3, #0x68
	adds r2, r6, r3
	ldrh r2, [r2]
	adds r4, #0x78
	adds r3, r6, r4
	ldr r3, [r3]
	str r3, [sp]
	subs r4, #0xc
	adds r3, r6, r4
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_082364f8
	ldr r1, _081CB368 @ =0x000006D7
	adds r0, r7, r1
	strb r5, [r0]
_081CB330:
	ldr r2, _081CB364 @ =0x0000046B
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _081CB378
	ldr r3, _081CB36C @ =0x000006CE
	adds r0, r7, r3
	ldrh r1, [r0]
	ldr r4, _081CB370 @ =0x000006CA
	adds r0, r7, r4
	strh r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, _081CB374 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r6, #0
	bl FUN_081c7228
	b _081CB382
	.align 2, 0
_081CB35C: .4byte FUN_081c9a60
_081CB360: .4byte 0x0000046D
_081CB364: .4byte 0x0000046B
_081CB368: .4byte 0x000006D7
_081CB36C: .4byte 0x000006CE
_081CB370: .4byte 0x000006CA
_081CB374: .4byte 0xFFFFFEFF
_081CB378:
	ldr r2, _081CB38C @ =0x00000484
	adds r1, r6, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081CB382:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081CB38C: .4byte 0x00000484

	thumb_func_start FUN_081cb390
FUN_081cb390: @ 0x081CB390
	ldr r1, _081CB39C @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _081CB3A0 @ =0x085AE040
	str r1, [r0]
	bx lr
	.align 2, 0
_081CB39C: .4byte 0x0000063C
_081CB3A0: .4byte 0x085AE040

	thumb_func_start FUN_081cb3a4
FUN_081cb3a4: @ 0x081CB3A4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081c67fc
	adds r0, r4, #0
	bl FUN_081c6bf8
	adds r0, r4, #0
	bl FUN_080fa77c
	ldr r1, _081CB3D8 @ =0x0000214A
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081CB3D0
	adds r0, r4, #0
	bl FUN_080f9f20
	lsls r0, r0, #0x18
_081CB3D0:
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081CB3D8: .4byte 0x0000214A

	thumb_func_start FUN_081cb3dc
FUN_081cb3dc: @ 0x081CB3DC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081c6938
	adds r0, r4, #0
	bl FUN_081c6ba8
	adds r0, r4, #0
	bl FUN_081c6bd8
	adds r0, r4, #0
	bl FUN_081c74b4
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081cb400
FUN_081cb400: @ 0x081CB400
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #8]
	ldr r2, _081CB42C @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081CB430
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081CB432
	.align 2, 0
_081CB42C: .4byte 0x0000046C
_081CB430:
	movs r0, #0
_081CB432:
	cmp r0, #0
	beq _081CB460
	ldr r4, _081CB5B4 @ =FUN_081c9f24
	movs r3, #0x27
	ldr r6, _081CB5B8 @ =0x0000046D
	adds r1, r5, r6
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081CB5BC @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
_081CB460:
	movs r6, #0xc1
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CB476
	b _081CB7D2
_081CB476:
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	ldrh r1, [r0, #8]
	cmp r1, #6
	beq _081CB48E
	cmp r1, #0xc
	beq _081CB48E
	cmp r1, #0x13
	beq _081CB48E
	cmp r1, #0x19
	beq _081CB48E
	b _081CB5E8
_081CB48E:
	ldrh r1, [r0, #0xe]
	ldrb r0, [r0, #7]
	subs r0, #1
	cmp r1, r0
	beq _081CB49A
	b _081CB5E8
_081CB49A:
	ldr r0, _081CB5C0 @ =0x03002C68
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	mov r8, r1
	cmp r0, #0
	beq _081CB4AC
	ldrh r0, [r0, #0x1a]
	mov r8, r0
_081CB4AC:
	movs r2, #1
	rsbs r2, r2, #0
	mov sl, r2
	ldr r3, _081CB5C4 @ =0x7FFFFFFF
	mov ip, r3
	movs r4, #0
	cmp r4, r8
	bge _081CB52A
	mov r3, sp
	adds r6, r5, #0
	adds r6, #8
	ldr r0, [sp, #8]
	ldr r1, _081CB5C8 @ =0x000006B4
	adds r0, r0, r1
	mov sb, r0
	ldr r7, _081CB5CC @ =0x03002BE0
_081CB4CC:
	lsls r0, r4, #2
	ldr r1, [r7]
	cmp r1, #0
	beq _081CB522
	ldr r2, _081CB5D0 @ =0x03002BC0
	adds r0, r0, r2
	ldr r0, [r0]
	movs r2, #8
	ands r0, r2
	cmp r0, #0
	bne _081CB522
	adds r2, r1, #0
	adds r2, #0x2c
	ldrh r0, [r1, #0x2c]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldrh r1, [r6, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r6, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	mov r2, sb
	ldr r0, [r2]
	cmp r1, r0
	bhs _081CB522
	cmp r1, ip
	bhs _081CB522
	mov ip, r1
	mov sl, r4
_081CB522:
	adds r7, #4
	adds r4, #1
	cmp r4, r8
	blt _081CB4CC
_081CB52A:
	mov r3, sl
	cmp r3, #0
	blt _081CB5E8
	ldr r6, _081CB5D4 @ =0x000001DF
	adds r0, r5, r6
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #1
	bl FUN_080e5718
	movs r2, #0x10
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081CB5D8 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _081CB5DC @ =0x0000046A
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _081CB5E0 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	ldr r6, [sp, #8]
	movs r0, #0xe1
	lsls r0, r0, #3
	adds r2, r6, r0
	ldr r1, _081CB5CC @ =0x03002BE0
	mov r3, sl
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x80
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r5, r6
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081CB592
	b _081CB7D2
_081CB592:
	ldr r0, _081CB5E4 @ =0x0000024E
	adds r3, r5, r0
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r2, [r3]
	adds r0, r0, r2
	strh r0, [r3]
	adds r6, #0xcc
	adds r1, r5, r6
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bhi _081CB5B0
	b _081CB7D2
_081CB5B0:
	strh r1, [r3]
	b _081CB7D2
	.align 2, 0
_081CB5B4: .4byte FUN_081c9f24
_081CB5B8: .4byte 0x0000046D
_081CB5BC: .4byte 0x0000046B
_081CB5C0: .4byte 0x03002C68
_081CB5C4: .4byte 0x7FFFFFFF
_081CB5C8: .4byte 0x000006B4
_081CB5CC: .4byte 0x03002BE0
_081CB5D0: .4byte 0x03002BC0
_081CB5D4: .4byte 0x000001DF
_081CB5D8: .4byte 0x00000469
_081CB5DC: .4byte 0x0000046A
_081CB5E0: .4byte 0x00000484
_081CB5E4: .4byte 0x0000024E
_081CB5E8:
	ldr r1, _081CB668 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081CB5F4
	b _081CB7C8
_081CB5F4:
	movs r2, #0x80
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _081CB67C
	movs r2, #0xc
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081CB66C @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _081CB670 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r0, r5, r3
	movs r2, #1
	strb r2, [r0]
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r4, [r0]
	movs r3, #0x1a
	ldr r6, _081CB674 @ =0x0000046D
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _081CB668 @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	movs r0, #4
	ldr r6, _081CB678 @ =0x00000222
	adds r2, r5, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _081CB7D2
	.align 2, 0
_081CB668: .4byte 0x0000046B
_081CB66C: .4byte 0x00000469
_081CB670: .4byte 0x00000484
_081CB674: .4byte 0x0000046D
_081CB678: .4byte 0x00000222
_081CB67C:
	mov r6, sp
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r2, [r0, #8]
	ldrh r1, [r2]
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r2, #2]
	strh r1, [r6, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _081CB6B0
	cmp r1, #0
	blt _081CB6B0
	ldr r0, _081CB6B4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CB6B0
	ldr r0, _081CB6B8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CB6BC
_081CB6B0:
	movs r4, #0
	b _081CB6CA
	.align 2, 0
_081CB6B4: .4byte 0x030046A8
_081CB6B8: .4byte 0x030046AC
_081CB6BC:
	ldr r0, _081CB6DC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081CB6CA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CB6E0
	adds r0, #4
	b _081CB6EC
	.align 2, 0
_081CB6DC: .4byte 0x030046A4
_081CB6E0:
	ldr r0, _081CB700 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CB6EC:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081CB704
	cmp r3, #2
	beq _081CB708
	b _081CB70C
	.align 2, 0
_081CB700: .4byte 0x030046A4
_081CB704:
	ldrb r0, [r6, #4]
	b _081CB70A
_081CB708:
	ldrb r0, [r6]
_081CB70A:
	subs r2, r2, r0
_081CB70C:
	movs r1, #0
	movs r4, #0
	strh r2, [r6, #2]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r3, [r0]
	movs r2, #1
	ldr r6, _081CB798 @ =0x0000046D
	adds r0, r5, r6
	strb r2, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0x25
	adds r0, r5, r6
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r4, [r0]
	movs r3, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081CB79C @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _081CB7A0 @ =0x00000484
	adds r0, r5, r3
	str r4, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r2, [r0]
	adds r1, #0x3a
	adds r0, r5, r1
	ldr r4, [r0]
	adds r6, r5, #0
	adds r6, #8
	adds r0, r4, #0
	adds r1, r6, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	beq _081CB7A4
	adds r0, r4, #0
	adds r1, r6, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081CB7A4
	cmp r0, #2
	beq _081CB792
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CB792:
	movs r0, #1
	b _081CB7AE
	.align 2, 0
_081CB798: .4byte 0x0000046D
_081CB79C: .4byte 0x0000046A
_081CB7A0: .4byte 0x00000484
_081CB7A4:
	ldr r0, _081CB7C0 @ =0xFFFFFDFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r0, #0
_081CB7AE:
	cmp r0, #0
	bne _081CB7D2
	ldr r2, _081CB7C4 @ =0x000005C4
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	b _081CB7D2
	.align 2, 0
_081CB7C0: .4byte 0xFFFFFDFF
_081CB7C4: .4byte 0x000005C4
_081CB7C8:
	ldr r3, _081CB7E4 @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081CB7D2:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081CB7E4: .4byte 0x00000484

	thumb_func_start FUN_081cb7e8
FUN_081cb7e8: @ 0x081CB7E8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _081CB80C @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081CB810
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081CB812
	.align 2, 0
_081CB80C: .4byte 0x0000046C
_081CB810:
	movs r0, #0
_081CB812:
	cmp r0, #0
	beq _081CB840
	ldr r4, _081CB888 @ =FUN_081c87c8
	movs r3, #0xa
	ldr r6, _081CB88C @ =0x0000046D
	adds r1, r5, r6
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r7, _081CB890 @ =0x0000046B
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _081CB894 @ =0x00000553
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r2, [r0]
_081CB840:
	movs r7, #0xc1
	lsls r7, r7, #3
	adds r0, r5, r7
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CB856
	b _081CBA9A
_081CB856:
	ldr r1, _081CB890 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081CB862
	b _081CBA90
_081CB862:
	ldr r2, _081CB898 @ =0x000004A4
	adds r0, r5, r2
	ldr r6, [r0]
	adds r7, r5, #0
	adds r7, #8
	movs r4, #0xe1
	lsls r4, r4, #3
	add r4, r8
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081CB89C
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	b _081CB8C2
	.align 2, 0
_081CB888: .4byte FUN_081c87c8
_081CB88C: .4byte 0x0000046D
_081CB890: .4byte 0x0000046B
_081CB894: .4byte 0x00000553
_081CB898: .4byte 0x000004A4
_081CB89C:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081CB8BC
	cmp r0, #2
	beq _081CB8B8
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CB8B8:
	movs r0, #1
	b _081CB8CC
_081CB8BC:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r5, r6
_081CB8C2:
	ldr r1, _081CB8E0 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081CB8CC:
	cmp r0, #0
	bne _081CB8E8
	ldr r7, _081CB8E4 @ =0x000005C4
	adds r0, r5, r7
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	b _081CBA9A
	.align 2, 0
_081CB8E0: .4byte 0xFFFFFDFF
_081CB8E4: .4byte 0x000005C4
_081CB8E8:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r2]
	movs r4, #0
	movs r6, #0
	orrs r1, r0
	strh r1, [r2]
	movs r0, #0x80
	ands r1, r0
	cmp r1, #0
	beq _081CB978
	movs r1, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r4, [r0]
	ldr r3, _081CB964 @ =0x00000469
	adds r0, r5, r3
	strb r4, [r0]
	ldr r7, _081CB968 @ =0x0000046A
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _081CB96C @ =0x00000484
	adds r0, r5, r1
	str r6, [r0]
	adds r2, #4
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r2, #0x1a
	adds r7, #3
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _081CB970 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r6, [r0]
	movs r0, #4
	ldr r3, _081CB974 @ =0x00000222
	adds r2, r5, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _081CBA9A
	.align 2, 0
_081CB964: .4byte 0x00000469
_081CB968: .4byte 0x0000046A
_081CB96C: .4byte 0x00000484
_081CB970: .4byte 0x0000046B
_081CB974: .4byte 0x00000222
_081CB978:
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r6, [r0]
	adds r2, r5, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081CB9B0
	cmp r1, #0
	blt _081CB9B0
	ldr r0, _081CB9B4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CB9B0
	ldr r0, _081CB9B8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CB9BC
_081CB9B0:
	movs r4, #0
	b _081CB9CA
	.align 2, 0
_081CB9B4: .4byte 0x030046A8
_081CB9B8: .4byte 0x030046AC
_081CB9BC:
	ldr r0, _081CB9DC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081CB9CA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CB9E0
	adds r0, #4
	b _081CB9EC
	.align 2, 0
_081CB9DC: .4byte 0x030046A4
_081CB9E0:
	ldr r0, _081CBA00 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CB9EC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CBA04
	cmp r2, #2
	beq _081CBA08
	b _081CBA0C
	.align 2, 0
_081CBA00: .4byte 0x030046A4
_081CBA04:
	ldrb r0, [r6, #4]
	b _081CBA0A
_081CBA08:
	ldrb r0, [r6]
_081CBA0A:
	subs r1, r1, r0
_081CBA0C:
	movs r3, #0
	movs r4, #0
	strh r1, [r6, #2]
	movs r7, #0x95
	lsls r7, r7, #3
	adds r0, r5, r7
	ldr r0, [r0]
	strh r4, [r0, #6]
	movs r2, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r2, [r0]
	movs r1, #1
	ldr r6, _081CBA80 @ =0x0000046D
	adds r0, r5, r6
	strb r1, [r0]
	subs r7, #0x3d
	adds r0, r5, r7
	strb r3, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r5, r7
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	movs r2, #7
	subs r6, #0xeb
	adds r0, r5, r6
	strb r3, [r0]
	ldr r7, _081CBA84 @ =0x00000469
	adds r0, r5, r7
	strb r3, [r0]
	ldr r3, _081CBA88 @ =0x0000046A
	adds r0, r5, r3
	strb r2, [r0]
	adds r6, #0x1c
	adds r0, r5, r6
	str r4, [r0]
	adds r7, #3
	adds r0, r5, r7
	strb r1, [r0]
	ldr r0, _081CBA8C @ =0x00000482
	adds r1, r5, r0
	movs r0, #2
	strh r0, [r1]
	b _081CBA9A
	.align 2, 0
_081CBA80: .4byte 0x0000046D
_081CBA84: .4byte 0x00000469
_081CBA88: .4byte 0x0000046A
_081CBA8C: .4byte 0x00000482
_081CBA90:
	ldr r2, _081CBAA4 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081CBA9A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081CBAA4: .4byte 0x00000484

	thumb_func_start FUN_081cbaa8
FUN_081cbaa8: @ 0x081CBAA8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x70
	adds r7, r0, #0
	ldr r0, _081CBAC8 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081CBACC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081CBACE
	.align 2, 0
_081CBAC8: .4byte 0x0000046C
_081CBACC:
	movs r0, #0
_081CBACE:
	cmp r0, #0
	beq _081CBB1C
	ldr r1, _081CBC54 @ =0x000005A4
	adds r0, r7, r1
	ldr r3, [r0]
	movs r2, #0
	ldr r4, _081CBC58 @ =0x0000046D
	adds r1, r7, r4
	movs r0, #1
	strb r0, [r1]
	ldr r5, _081CBC5C @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _081CBC60 @ =0x00000553
	adds r0, r7, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r2, [r0]
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r2, r7, r4
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r0, _081CBC64 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081CBB1C:
	movs r6, #0xc1
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #0
	beq _081CBB36
	b _081CC194
_081CBB36:
	ldr r0, _081CBC68 @ =0x00000484
	adds r1, r7, r0
	ldr r0, [r1]
	cmp r0, #0x14
	bgt _081CBB42
	b _081CC190
_081CBB42:
	ldr r1, _081CBC6C @ =0x00000222
	adds r1, r7, r1
	str r1, [sp, #8]
	movs r0, #7
	rsbs r0, r0, #0
	ldrh r1, [r1]
	ands r0, r1
	movs r4, #0
	ldr r2, [sp, #8]
	strh r0, [r2]
	ldr r1, _081CBC70 @ =FUN_080e6794
	movs r0, #0xe
	ldr r3, _081CBC58 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0xc]
	movs r5, #1
	strb r5, [r3]
	ldr r6, _081CBC5C @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x10]
	strb r4, [r6]
	ldr r2, _081CBC60 @ =0x00000553
	adds r2, r7, r2
	str r2, [sp, #0x14]
	strb r0, [r2]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x18]
	str r1, [r3]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x1c]
	mov r0, r8
	strh r0, [r6]
	ldr r1, _081CBC74 @ =0x00000543
	adds r0, r7, r1
	ldrb r3, [r0]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r2, [r0]
	movs r6, #0xc
	mov sb, r6
	movs r0, #0xab
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r6, _081CBC78 @ =0x00000554
	adds r0, r7, r6
	str r3, [r0]
	str r2, [r1]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _081CBC7C @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _081CBC80 @ =0x00000552
	adds r0, r7, r3
	mov r6, sb
	strb r6, [r0]
	movs r0, #3
	subs r1, #0xe8
	adds r1, r1, r7
	mov ip, r1
	strb r0, [r1]
	subs r2, #0xe8
	adds r2, r2, r7
	mov sl, r2
	strb r5, [r2]
	subs r3, #0xe8
	adds r3, r3, r7
	mov sb, r3
	strb r4, [r3]
	ldr r4, _081CBC68 @ =0x00000484
	adds r6, r7, r4
	mov r0, r8
	str r0, [r6]
	ldr r1, _081CBC84 @ =0x0000046C
	adds r3, r7, r1
	strb r5, [r3]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r4, r7, r2
	ldr r5, [r4]
	str r5, [sp, #0x20]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x5c]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x60]
	ldr r3, [sp, #0x10]
	str r3, [sp, #0x58]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0x40]
	ldr r3, [sp, #0x18]
	str r3, [sp, #0x44]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0x6c]
	ldr r3, [sp, #8]
	str r3, [sp, #0x28]
	mov r0, ip
	str r0, [sp, #0x4c]
	mov r3, sl
	str r3, [sp, #0x50]
	mov r0, sb
	str r0, [sp, #0x54]
	str r6, [sp, #0x68]
	adds r6, r4, #0
	mov r8, r2
	cmp r5, #0
	blt _081CBC4E
	cmp r1, #0
	blt _081CBC4E
	ldr r0, _081CBC88 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _081CBC4E
	ldr r0, _081CBC8C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CBC90
_081CBC4E:
	movs r5, #0
	b _081CBC9E
	.align 2, 0
_081CBC54: .4byte 0x000005A4
_081CBC58: .4byte 0x0000046D
_081CBC5C: .4byte 0x0000046B
_081CBC60: .4byte 0x00000553
_081CBC64: .4byte 0xFFFFFDFF
_081CBC68: .4byte 0x00000484
_081CBC6C: .4byte 0x00000222
_081CBC70: .4byte FUN_080e6794
_081CBC74: .4byte 0x00000543
_081CBC78: .4byte 0x00000554
_081CBC7C: .4byte 0x00000551
_081CBC80: .4byte 0x00000552
_081CBC84: .4byte 0x0000046C
_081CBC88: .4byte 0x030046A8
_081CBC8C: .4byte 0x030046AC
_081CBC90:
	ldr r0, _081CBCB0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r5
_081CBC9E:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CBCB4
	adds r0, #4
	b _081CBCC0
	.align 2, 0
_081CBCB0: .4byte 0x030046A4
_081CBCB4:
	ldr r0, _081CBCD4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CBCC0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CBCD8
	cmp r2, #2
	beq _081CBCDE
	b _081CBCE4
	.align 2, 0
_081CBCD4: .4byte 0x030046A4
_081CBCD8:
	ldr r2, [sp, #0x20]
	ldrb r0, [r2, #4]
	b _081CBCE2
_081CBCDE:
	ldr r3, [sp, #0x20]
	ldrb r0, [r3]
_081CBCE2:
	subs r1, r1, r0
_081CBCE4:
	ldr r4, [sp, #0x20]
	strh r1, [r4, #2]
	ldr r0, _081CBCFC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081CBD00
	movs r0, #1
	b _081CBD02
	.align 2, 0
_081CBCFC: .4byte 0x030047A4
_081CBD00:
	movs r0, #0
_081CBD02:
	cmp r0, #0
	beq _081CBD40
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	cmp r1, #0
	beq _081CBD22
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081CBD1E
	adds r2, r0, #0
_081CBD1E:
	cmp r2, #0
	bge _081CBD2C
_081CBD22:
	ldr r6, _081CBD28 @ =0x000005C4
	adds r0, r7, r6
	b _081CC17C
	.align 2, 0
_081CBD28: .4byte 0x000005C4
_081CBD2C:
	ldr r1, _081CBD3C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081CBD88
	.align 2, 0
_081CBD3C: .4byte 0x03002BE0
_081CBD40:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081CBD6C
	cmp r1, #0
	blt _081CBD6C
	ldr r0, _081CBD70 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CBD6C
	ldr r0, _081CBD74 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CBD78
_081CBD6C:
	movs r5, #0
	b _081CBD86
	.align 2, 0
_081CBD70: .4byte 0x030046A8
_081CBD74: .4byte 0x030046AC
_081CBD78:
	ldr r0, _081CBE1C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081CBD86:
	movs r2, #0
_081CBD88:
	ldr r3, _081CBE20 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _081CBDA8
	ldr r1, _081CBE24 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081CBDA8
	b _081CC0C0
_081CBDA8:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	mov sb, r2
	cmp r3, #0
	beq _081CBDC2
	b _081CC194
_081CBDC2:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r5, [sp, #0x28]
	ldrh r1, [r5]
	ands r0, r1
	movs r5, #0
	ldr r1, [sp, #0x28]
	strh r0, [r1]
	movs r1, #0x80
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _081CBE28
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r6, [sp, #0x60]
	strb r2, [r6]
	ldr r4, [sp, #0x58]
	strb r5, [r4]
	ldr r6, [sp, #0x40]
	strb r0, [r6]
	ldr r0, [sp, #0x44]
	str r1, [r0]
	ldr r1, [sp, #0x6c]
	strh r3, [r1]
	movs r0, #0xc
	ldr r4, [sp, #0x4c]
	strb r5, [r4]
	ldr r6, [sp, #0x50]
	strb r5, [r6]
	ldr r1, [sp, #0x54]
	strb r0, [r1]
	ldr r4, [sp, #0x68]
	str r3, [r4]
	ldr r5, [sp, #0x5c]
	strb r2, [r5]
	b _081CBF76
	.align 2, 0
_081CBE1C: .4byte 0x030046A4
_081CBE20: .4byte 0x00000256
_081CBE24: .4byte 0x03002BE0
_081CBE28:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, [sp, #0x60]
	strb r0, [r3]
	ldr r4, [sp, #0x58]
	strb r5, [r4]
	ldr r3, [sp, #0x40]
	strb r0, [r3]
	ldr r4, [sp, #0x44]
	str r1, [r4]
	ldr r1, [sp, #0x6c]
	strh r2, [r1]
	movs r1, #5
	ldr r3, [sp, #0x4c]
	strb r5, [r3]
	ldr r4, [sp, #0x50]
	strb r5, [r4]
	ldr r5, [sp, #0x54]
	strb r1, [r5]
	ldr r1, [sp, #0x68]
	str r2, [r1]
	ldr r2, [sp, #0x5c]
	strb r0, [r2]
	ldr r4, [r6]
	mov r3, r8
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r4]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r4, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081CBE8C
	cmp r1, #0
	blt _081CBE8C
	ldr r0, _081CBE90 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CBE8C
	ldr r0, _081CBE94 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CBE98
_081CBE8C:
	movs r5, #0
	b _081CBEA6
	.align 2, 0
_081CBE90: .4byte 0x030046A8
_081CBE94: .4byte 0x030046AC
_081CBE98:
	ldr r0, _081CBEB8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081CBEA6:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CBEBC
	adds r0, #4
	b _081CBEC8
	.align 2, 0
_081CBEB8: .4byte 0x030046A4
_081CBEBC:
	ldr r0, _081CBEDC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CBEC8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CBEE0
	cmp r2, #2
	beq _081CBEE4
	b _081CBEE8
	.align 2, 0
_081CBEDC: .4byte 0x030046A4
_081CBEE0:
	ldrb r0, [r4, #4]
	b _081CBEE6
_081CBEE4:
	ldrb r0, [r4]
_081CBEE6:
	subs r1, r1, r0
_081CBEE8:
	strh r1, [r4, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081CBF10
	cmp r1, #0
	blt _081CBF10
	ldr r0, _081CBF14 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CBF10
	ldr r0, _081CBF18 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CBF1C
_081CBF10:
	movs r5, #0
	b _081CBF2A
	.align 2, 0
_081CBF14: .4byte 0x030046A8
_081CBF18: .4byte 0x030046AC
_081CBF1C:
	ldr r0, _081CBF3C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081CBF2A:
	ldr r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CBF40
	adds r0, #4
	b _081CBF4C
	.align 2, 0
_081CBF3C: .4byte 0x030046A4
_081CBF40:
	ldr r0, _081CBF60 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CBF4C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081CBF64
	cmp r3, #2
	beq _081CBF68
	b _081CBF6C
	.align 2, 0
_081CBF60: .4byte 0x030046A4
_081CBF64:
	ldrb r0, [r4, #4]
	b _081CBF6A
_081CBF68:
	ldrb r0, [r4]
_081CBF6A:
	subs r2, r2, r0
_081CBF6C:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081CBF76:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x24]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sb
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	ldr r6, _081CBFA0 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x64]
	cmp r0, #0
	bne _081CC084
	movs r1, #4
	ldr r2, [sp, #0x28]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081CBFA4
	movs r0, #1
	b _081CBFA6
	.align 2, 0
_081CBFA0: .4byte 0x00000482
_081CBFA4:
	movs r0, #0
_081CBFA6:
	ldr r3, _081CC094 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x64]
	cmp r0, #0
	bne _081CC084
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r6, _081CC098 @ =0x0000054F
	adds r6, r6, r7
	mov ip, r6
	ldr r0, _081CC09C @ =0x0000054C
	adds r0, r7, r0
	str r0, [sp, #0x34]
	ldr r1, _081CC0A0 @ =0x0000054D
	adds r1, r7, r1
	str r1, [sp, #0x38]
	ldr r2, _081CC0A4 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0x3c]
	ldr r4, _081CC0A8 @ =0x00000541
	adds r4, r7, r4
	str r4, [sp, #0x2c]
	ldr r5, _081CC0AC @ =0x000005BC
	adds r5, r7, r5
	str r5, [sp, #0x48]
	ldr r6, _081CC0B0 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0x30]
	ldr r6, _081CC0B4 @ =0x0203B400
	ldr r1, _081CC0B8 @ =0x030046B8
	ldr r2, _081CC0BC @ =0x000003FF
	movs r5, #3
	mov r4, r8
_081CBFF6:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r5
	lsls r0, r0, #6
	cmp r0, r4
	bne _081CC014
	adds r3, #1
	cmp r3, #3
	ble _081CBFF6
	mov r0, r8
_081CC014:
	movs r3, #0
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x44]
	ldr r0, [r2]
	mov r4, sl
	str r0, [r4]
	ldr r5, [sp, #0x40]
	ldrb r0, [r5]
	mov r6, ip
	strb r0, [r6]
	ldr r1, [sp, #0x4c]
	ldrb r0, [r1]
	ldr r2, [sp, #0x34]
	strb r0, [r2]
	ldr r4, [sp, #0x50]
	ldrb r0, [r4]
	ldr r5, [sp, #0x38]
	strb r0, [r5]
	ldr r6, [sp, #0x54]
	ldrb r0, [r6]
	ldr r1, [sp, #0x3c]
	strb r0, [r1]
	add r2, sp, #0x24
	ldrb r4, [r2]
	ldr r2, [sp, #0x2c]
	strb r4, [r2]
	ldr r4, [sp, #0x48]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x60]
	strb r1, [r5]
	ldr r6, [sp, #0x58]
	strb r3, [r6]
	ldr r4, [sp, #0x40]
	strb r0, [r4]
	ldr r5, [sp, #0x44]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x6c]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x4c]
	strb r0, [r4]
	ldr r5, [sp, #0x50]
	strb r1, [r5]
	ldr r6, [sp, #0x54]
	strb r2, [r6]
	ldr r0, [sp, #0x68]
	str r3, [r0]
	ldr r2, [sp, #0x5c]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x30]
	strb r0, [r3]
_081CC084:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x64]
	strh r0, [r4]
	b _081CC194
	.align 2, 0
_081CC094: .4byte 0x00000482
_081CC098: .4byte 0x0000054F
_081CC09C: .4byte 0x0000054C
_081CC0A0: .4byte 0x0000054D
_081CC0A4: .4byte 0x0000054E
_081CC0A8: .4byte 0x00000541
_081CC0AC: .4byte 0x000005BC
_081CC0B0: .4byte 0x00000542
_081CC0B4: .4byte 0x0203B400
_081CC0B8: .4byte 0x030046B8
_081CC0BC: .4byte 0x000003FF
_081CC0C0:
	mov sb, sp
	ldr r6, _081CC0FC @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CC100
	adds r0, #4
	b _081CC10A
	.align 2, 0
_081CC0FC: .4byte 0x030046A4
_081CC100:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081CC10A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _081CC140 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _081CC144
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _081CC16A
	.align 2, 0
_081CC140: .4byte 0x000004A4
_081CC144:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081CC164
	cmp r0, #2
	beq _081CC160
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CC160:
	movs r0, #1
	b _081CC174
_081CC164:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_081CC16A:
	ldr r1, _081CC188 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081CC174:
	cmp r0, #0
	bne _081CC194
	ldr r3, _081CC18C @ =0x000005C4
	adds r0, r7, r3
_081CC17C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081CC194
	.align 2, 0
_081CC188: .4byte 0xFFFFFDFF
_081CC18C: .4byte 0x000005C4
_081CC190:
	adds r0, #1
	str r0, [r1]
_081CC194:
	add sp, #0x70
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081cc1a4
FUN_081cc1a4: @ 0x081CC1A4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _081CC1CC @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081CC1D0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081CC1D2
	.align 2, 0
_081CC1CC: .4byte 0x0000046C
_081CC1D0:
	movs r0, #0
_081CC1D2:
	cmp r0, #0
	beq _081CC20E
	ldr r4, _081CC240 @ =FUN_081ca258
	movs r3, #0x29
	ldr r0, _081CC244 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081CC248 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #8
	movs r1, #0xd5
	lsls r1, r1, #3
	add r1, r8
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081CC20E:
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r7, r0, #0
	ldr r3, _081CC24C @ =0x00000482
	adds r1, r5, r3
	movs r0, #2
	strh r0, [r1]
	ldr r1, _081CC250 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081CC254
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081CC264
	.align 2, 0
_081CC240: .4byte FUN_081ca258
_081CC244: .4byte 0x0000046D
_081CC248: .4byte 0x0000046B
_081CC24C: .4byte 0x00000482
_081CC250: .4byte 0x0000A02F
_081CC254:
	ldr r3, _081CC288 @ =0x00000482
	adds r0, r5, r3
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081CC264
	movs r0, #1
	strh r0, [r2]
_081CC264:
	ldr r1, _081CC28C @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081CC290
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _081CC2A8
	.align 2, 0
_081CC288: .4byte 0x00000482
_081CC28C: .4byte 0x0000025D
_081CC290:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_081CC2A8:
	ldr r2, _081CC300 @ =0x000004A4
	adds r4, r5, r2
	ldr r0, [r4]
	bl FUN_08235fd8
	adds r6, r0, #0
	cmp r6, #0
	bne _081CC308
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e5ed4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CC342
	movs r1, #3
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _081CC304 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r6, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r6, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	movs r2, #4
	movs r1, #0xd5
	lsls r1, r1, #3
	add r1, r8
	ldr r0, [r1]
	orrs r0, r2
	b _081CC36A
	.align 2, 0
_081CC300: .4byte 0x000004A4
_081CC304: .4byte 0x00000469
_081CC308:
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CC342
	movs r2, #0x12
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081CC378 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _081CC37C @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
_081CC342:
	adds r0, r5, #0
	bl FUN_081c70c8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CC362
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CC36C
_081CC362:
	ldr r2, _081CC37C @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
_081CC36A:
	str r0, [r1]
_081CC36C:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081CC378: .4byte 0x00000469
_081CC37C: .4byte 0x00000484

	thumb_func_start FUN_081cc380
FUN_081cc380: @ 0x081CC380
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081CC398 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081CC39C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081CC39E
	.align 2, 0
_081CC398: .4byte 0x0000046C
_081CC39C:
	movs r0, #0
_081CC39E:
	cmp r0, #0
	beq _081CC3D2
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _081CC424 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081CC428 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_081CC3D2:
	adds r0, r5, #0
	bl FUN_081c70c8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CC3F2
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CC43A
_081CC3F2:
	ldr r3, _081CC428 @ =0x0000046B
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _081CC430
	movs r2, #0x11
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _081CC42C @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _081CC43A
	.align 2, 0
_081CC424: .4byte 0x0000046D
_081CC428: .4byte 0x0000046B
_081CC42C: .4byte 0x00000484
_081CC430:
	ldr r0, _081CC440 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081CC43A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081CC440: .4byte 0x00000484

	thumb_func_start FUN_081cc444
FUN_081cc444: @ 0x081CC444
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081CC45C @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081CC460
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081CC462
	.align 2, 0
_081CC45C: .4byte 0x0000046C
_081CC460:
	movs r0, #0
_081CC462:
	cmp r0, #0
	beq _081CC496
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _081CC510 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _081CC514 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _081CC518 @ =0x00000553
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r2, [r0]
_081CC496:
	adds r0, r5, #0
	bl FUN_081c70c8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CC4B6
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CC532
_081CC4B6:
	ldr r2, _081CC514 @ =0x0000046B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _081CC528
	movs r2, #3
	movs r1, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r3, #0
	strb r2, [r0]
	ldr r6, _081CC51C @ =0x00000469
	adds r0, r5, r6
	strb r1, [r0]
	ldr r2, _081CC520 @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r3, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	ldr r4, _081CC524 @ =FUN_081ca14c
	movs r2, #0x2a
	subs r6, #0x17
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081CC514 @ =0x0000046B
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r3, [r0]
	b _081CC532
	.align 2, 0
_081CC510: .4byte 0x0000046D
_081CC514: .4byte 0x0000046B
_081CC518: .4byte 0x00000553
_081CC51C: .4byte 0x00000469
_081CC520: .4byte 0x0000046A
_081CC524: .4byte FUN_081ca14c
_081CC528:
	ldr r3, _081CC538 @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081CC532:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081CC538: .4byte 0x00000484

	thumb_func_start FUN_081cc53c
FUN_081cc53c: @ 0x081CC53C
	ldr r1, _081CC548 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _081CC54C @ =0x085AE048
	str r1, [r0]
	bx lr
	.align 2, 0
_081CC548: .4byte 0x00000634
_081CC54C: .4byte 0x085AE048


	thumb_func_start FUN_081cc550
FUN_081cc550: @ 0x081CC550
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xbc
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r6, [r0]
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r4, _081CC58C @ =0x00008002
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r3, r7, r2
	ldrh r2, [r3]
	ands r4, r2
	cmp r4, #0
	beq _081CC590
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	strh r0, [r3]
_081CC586:
	movs r0, #0
	bl FUN_081cd5f6
	.align 2, 0
_081CC58C: .4byte 0x00008002
_081CC590:
	ldr r5, _081CC610 @ =0x0000049C
	adds r0, r7, r5
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	beq _081CC628
	ldr r1, _081CC614 @ =0x000005CC
	adds r0, r7, r1
	ldr r2, [r0]
	movs r1, #0x12
	ldr r3, _081CC618 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	subs r5, #0x31
	adds r0, r7, r5
	strb r4, [r0]
	adds r5, #0xe8
	adds r0, r7, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _081CC61C @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	adds r5, #2
	adds r0, r7, r5
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r7, r1
	str r4, [r0]
	ldr r2, _081CC620 @ =0x0000046C
	adds r0, r7, r2
	strb r3, [r0]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r1, _081CC624 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r4, #0xd5
	lsls r4, r4, #3
	adds r2, r6, r4
	movs r1, #9
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	bl _081CD5F4
	.align 2, 0
_081CC610: .4byte 0x0000049C
_081CC614: .4byte 0x000005CC
_081CC618: .4byte 0x0000046D
_081CC61C: .4byte 0x00000469
_081CC620: .4byte 0x0000046C
_081CC624: .4byte 0xFEFFFFFF
_081CC628:
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r2
	strh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne _081CC586
	ldr r5, _081CC6F8 @ =0x000004BE
	adds r0, r7, r5
	ldrh r0, [r0]
	cmp r0, #0
	bne _081CC586
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _081CC650
	bl FUN_081cce88
_081CC650:
	ldr r0, _081CC6FC @ =0x0000048D
	adds r2, r7, r0
	ldrb r0, [r2]
	cmp r0, #0
	bne _081CC67C
	ldr r1, _081CC700 @ =0x0000048C
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081CC67C
	ldr r3, _081CC6F8 @ =0x000004BE
	adds r0, r7, r3
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
_081CC67C:
	movs r2, #0x80
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #4
	ldr r5, _081CC704 @ =0x00000222
	adds r4, r7, r5
	ldrh r1, [r4]
	movs r5, #0
	orrs r0, r1
	strh r0, [r4]
	adds r0, r7, #0
	bl FUN_080faa98
	lsls r0, r0, #0x18
	str r4, [sp, #0xb0]
	cmp r0, #0
	bne _081CC6A8
	b _081CC586
_081CC6A8:
	adds r0, r7, #0
	bl FUN_081c70c8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CC6B6
	b _081CCDBC
_081CC6B6:
	movs r6, #0x95
	lsls r6, r6, #3
	adds r3, r7, r6
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x94]
	str r2, [sp, #0x70]
	cmp r4, #0
	blt _081CC6F2
	cmp r1, #0
	blt _081CC6F2
	ldr r0, _081CC708 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081CC6F2
	ldr r0, _081CC70C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CC710
_081CC6F2:
	movs r4, #0
	b _081CC71E
	.align 2, 0
_081CC6F8: .4byte 0x000004BE
_081CC6FC: .4byte 0x0000048D
_081CC700: .4byte 0x0000048C
_081CC704: .4byte 0x00000222
_081CC708: .4byte 0x030046A8
_081CC70C: .4byte 0x030046AC
_081CC710:
	ldr r0, _081CC730 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081CC71E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CC734
	adds r0, #4
	b _081CC740
	.align 2, 0
_081CC730: .4byte 0x030046A4
_081CC734:
	ldr r0, _081CC754 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CC740:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CC758
	cmp r2, #2
	beq _081CC75C
	b _081CC760
	.align 2, 0
_081CC754: .4byte 0x030046A4
_081CC758:
	ldrb r0, [r5, #4]
	b _081CC75E
_081CC75C:
	ldrb r0, [r5]
_081CC75E:
	subs r1, r1, r0
_081CC760:
	strh r1, [r5, #2]
	ldr r0, _081CC774 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081CC778
	movs r0, #1
	b _081CC77A
	.align 2, 0
_081CC774: .4byte 0x030047A4
_081CC778:
	movs r0, #0
_081CC77A:
	cmp r0, #0
	beq _081CC7B8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081CC79A
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081CC796
	adds r2, r0, #0
_081CC796:
	cmp r2, #0
	bge _081CC7A4
_081CC79A:
	ldr r2, _081CC7A0 @ =0x000005C4
	adds r0, r7, r2
	b _081CCCC4
	.align 2, 0
_081CC7A0: .4byte 0x000005C4
_081CC7A4:
	ldr r1, _081CC7B4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081CC800
	.align 2, 0
_081CC7B4: .4byte 0x03002BE0
_081CC7B8:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081CC7E4
	cmp r1, #0
	blt _081CC7E4
	ldr r0, _081CC7E8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CC7E4
	ldr r0, _081CC7EC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CC7F0
_081CC7E4:
	movs r5, #0
	b _081CC7FE
	.align 2, 0
_081CC7E8: .4byte 0x030046A8
_081CC7EC: .4byte 0x030046AC
_081CC7F0:
	ldr r0, _081CC840 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081CC7FE:
	movs r2, #0
_081CC800:
	ldr r4, _081CC844 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _081CC820
	ldr r1, _081CC848 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081CC820
	b _081CCC08
_081CC820:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	str r2, [sp, #0x98]
	cmp r1, #0
	beq _081CC84C
	movs r0, #0
	b _081CCCDA
	.align 2, 0
_081CC840: .4byte 0x030046A4
_081CC844: .4byte 0x00000256
_081CC848: .4byte 0x03002BE0
_081CC84C:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r6, [sp, #0xb0]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	movs r1, #0x80
	ldr r2, [sp, #0x98]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _081CC8F8
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r4, _081CC8E8 @ =0x0000046D
	adds r4, r7, r4
	str r4, [sp, #0x10]
	movs r5, #1
	strb r5, [r4]
	ldr r6, _081CC8EC @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x14]
	movs r2, #0
	strb r2, [r6]
	subs r3, #0x65
	adds r3, r7, r3
	str r3, [sp, #0x18]
	strb r0, [r3]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	str r1, [r4]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	mov r0, sb
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r2, [r4]
	ldr r2, _081CC8F0 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _081CC8F4 @ =0x00000484
	adds r1, r7, r6
	mov r0, sb
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x10]
	str r6, [sp, #0x88]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x80]
	ldr r6, [sp, #0x18]
	str r6, [sp, #0xac]
	mov r6, r8
	str r6, [sp, #0xb4]
	str r5, [sp, #0x9c]
	str r4, [sp, #0x74]
	str r3, [sp, #0x78]
	str r2, [sp, #0x7c]
	str r1, [sp, #0x90]
	str r0, [sp, #0x84]
	b _081CCAC6
	.align 2, 0
_081CC8E8: .4byte 0x0000046D
_081CC8EC: .4byte 0x0000046B
_081CC8F0: .4byte 0x00000469
_081CC8F4: .4byte 0x00000484
_081CC8F8:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, _081CC9B8 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0x1c]
	strb r0, [r3]
	ldr r4, _081CC9BC @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x20]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _081CC9C0 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x24]
	strb r0, [r6]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x28]
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x2c]
	strh r2, [r4]
	movs r1, #5
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x30]
	movs r6, #0
	strb r6, [r5]
	ldr r3, _081CC9C4 @ =0x00000469
	adds r5, r7, r3
	strb r6, [r5]
	ldr r6, _081CC9C8 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _081CC9CC @ =0x00000484
	adds r3, r7, r1
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x94]
	ldr r0, [r0]
	str r0, [sp, #0x34]
	ldr r1, [sp, #0x70]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x34]
	strh r1, [r6]
	ldr r6, [sp, #0x70]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x34]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0x88]
	ldr r6, [sp, #0x20]
	str r6, [sp, #0x80]
	ldr r0, [sp, #0x24]
	str r0, [sp, #0xac]
	ldr r6, [sp, #0x28]
	str r6, [sp, #0xb4]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0x9c]
	ldr r6, [sp, #0x30]
	str r6, [sp, #0x74]
	str r5, [sp, #0x78]
	str r4, [sp, #0x7c]
	str r3, [sp, #0x90]
	str r2, [sp, #0x84]
	mov r0, ip
	cmp r0, #0
	blt _081CC9B4
	cmp r1, #0
	blt _081CC9B4
	ldr r0, _081CC9D0 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _081CC9B4
	ldr r0, _081CC9D4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CC9D8
_081CC9B4:
	movs r4, #0
	b _081CC9E8
	.align 2, 0
_081CC9B8: .4byte 0x0000046D
_081CC9BC: .4byte 0x0000046B
_081CC9C0: .4byte 0x00000553
_081CC9C4: .4byte 0x00000469
_081CC9C8: .4byte 0x0000046A
_081CC9CC: .4byte 0x00000484
_081CC9D0: .4byte 0x030046A8
_081CC9D4: .4byte 0x030046AC
_081CC9D8:
	ldr r0, _081CC9F8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_081CC9E8:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CC9FC
	adds r0, #4
	b _081CCA08
	.align 2, 0
_081CC9F8: .4byte 0x030046A4
_081CC9FC:
	ldr r0, _081CCA1C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CCA08:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CCA20
	cmp r2, #2
	beq _081CCA26
	b _081CCA2C
	.align 2, 0
_081CCA1C: .4byte 0x030046A4
_081CCA20:
	ldr r2, [sp, #0x34]
	ldrb r0, [r2, #4]
	b _081CCA2A
_081CCA26:
	ldr r3, [sp, #0x34]
	ldrb r0, [r3]
_081CCA2A:
	subs r1, r1, r0
_081CCA2C:
	ldr r4, [sp, #0x34]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x94]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081CCA58
	cmp r1, #0
	blt _081CCA58
	ldr r0, _081CCA5C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CCA58
	ldr r0, _081CCA60 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CCA64
_081CCA58:
	movs r4, #0
	b _081CCA72
	.align 2, 0
_081CCA5C: .4byte 0x030046A8
_081CCA60: .4byte 0x030046AC
_081CCA64:
	ldr r0, _081CCA88 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081CCA72:
	ldr r6, [sp, #0x94]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CCA8C
	adds r0, #4
	b _081CCA98
	.align 2, 0
_081CCA88: .4byte 0x030046A4
_081CCA8C:
	ldr r0, _081CCAAC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CCA98:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081CCAB0
	cmp r3, #2
	beq _081CCAB4
	b _081CCAB8
	.align 2, 0
_081CCAAC: .4byte 0x030046A4
_081CCAB0:
	ldrb r0, [r5, #4]
	b _081CCAB6
_081CCAB4:
	ldrb r0, [r5]
_081CCAB6:
	subs r2, r2, r0
_081CCAB8:
	ldr r1, [sp, #0x94]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x94]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081CCAC6:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x38]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _081CCAF0 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x8c]
	cmp r0, #0
	bne _081CCBD0
	movs r1, #4
	ldr r6, [sp, #0xb0]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081CCAF4
	movs r0, #1
	b _081CCAF6
	.align 2, 0
_081CCAF0: .4byte 0x00000482
_081CCAF4:
	movs r0, #0
_081CCAF6:
	ldr r1, _081CCBE0 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	cmp r0, #0
	bne _081CCBD0
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xb8]
	ldr r0, _081CCBE4 @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _081CCBE8 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _081CCBEC @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa8]
	ldr r0, _081CCBF0 @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xa0]
	ldr r1, _081CCBF4 @ =0x000005BC
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _081CCBF8 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	ldr r1, _081CCBFC @ =0x030046B8
	adds r2, r4, #0
_081CCB3E:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _081CCC00 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _081CCC04 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _081CCB62
	adds r3, #1
	cmp r3, #3
	ble _081CCB3E
	adds r0, r4, #0
_081CCB62:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0xb4]
	ldr r0, [r1]
	ldr r2, [sp, #0xb8]
	str r0, [r2]
	ldr r4, [sp, #0xac]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x74]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x78]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x7c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa8]
	strb r0, [r6]
	add r0, sp, #0x38
	ldrb r1, [r0]
	ldr r0, [sp, #0xa0]
	strb r1, [r0]
	mov r1, ip
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x88]
	strb r1, [r4]
	ldr r5, [sp, #0x80]
	strb r3, [r5]
	ldr r6, [sp, #0xac]
	strb r0, [r6]
	ldr r0, [sp, #0xb4]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x9c]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x74]
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	strb r1, [r6]
	ldr r0, [sp, #0x7c]
	strb r2, [r0]
	ldr r2, [sp, #0x90]
	str r3, [r2]
	ldr r3, [sp, #0x84]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa4]
	strb r0, [r4]
_081CCBD0:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x8c]
	strh r0, [r5]
	movs r0, #0
	b _081CCCDA
	.align 2, 0
_081CCBE0: .4byte 0x00000482
_081CCBE4: .4byte 0x0000054F
_081CCBE8: .4byte 0x0000054C
_081CCBEC: .4byte 0x0000054E
_081CCBF0: .4byte 0x00000541
_081CCBF4: .4byte 0x000005BC
_081CCBF8: .4byte 0x00000542
_081CCBFC: .4byte 0x030046B8
_081CCC00: .4byte 0x000003FF
_081CCC04: .4byte 0x0203B400
_081CCC08:
	mov sb, sp
	ldr r6, _081CCC44 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CCC48
	adds r0, #4
	b _081CCC52
	.align 2, 0
_081CCC44: .4byte 0x030046A4
_081CCC48:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081CCC52:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _081CCC88 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _081CCC8C
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _081CCCB2
	.align 2, 0
_081CCC88: .4byte 0x000004A4
_081CCC8C:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081CCCAC
	cmp r0, #2
	beq _081CCCA8
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CCCA8:
	movs r0, #1
	b _081CCCBC
_081CCCAC:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_081CCCB2:
	ldr r1, _081CCCD0 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081CCCBC:
	cmp r0, #0
	bne _081CCCD8
	ldr r3, _081CCCD4 @ =0x000005C4
	adds r0, r7, r3
_081CCCC4:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081CCCDA
	.align 2, 0
_081CCCD0: .4byte 0xFFFFFDFF
_081CCCD4: .4byte 0x000005C4
_081CCCD8:
	movs r0, #1
_081CCCDA:
	cmp r0, #0
	bne _081CCD54
	ldr r4, _081CCD0C @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081CCD10
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	b _081CCD36
	.align 2, 0
_081CCD0C: .4byte 0x000004A4
_081CCD10:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081CCD30
	cmp r0, #2
	beq _081CCD2C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CCD2C:
	movs r0, #1
	b _081CCD40
_081CCD30:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
_081CCD36:
	ldr r1, _081CCD4C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081CCD40:
	cmp r0, #0
	bne _081CCD54
	ldr r4, _081CCD50 @ =0x000005C4
	adds r0, r7, r4
	bl FUN_081cd588
	.align 2, 0
_081CCD4C: .4byte 0xFFFFFDFF
_081CCD50: .4byte 0x000005C4
_081CCD54:
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _081CCDAC @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _081CCDB0 @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081CCDB4 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _081CCDB8 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	bl _081CD5F4
	.align 2, 0
_081CCDAC: .4byte 0x0000046D
_081CCDB0: .4byte 0x0000046B
_081CCDB4: .4byte 0x0000046A
_081CCDB8: .4byte 0x00000484
_081CCDBC:
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r4, [r0]
	cmp r4, #0
	beq _081CCDCC
	bl _081CD5F4
_081CCDCC:
	ldr r2, _081CCE34 @ =FUN_080e48d0
	mov r8, r2
	movs r1, #0x10
	ldr r3, _081CCE38 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r2, _081CCE3C @ =0x0000046B
	adds r0, r7, r2
	strb r5, [r0]
	adds r2, #0xe8
	adds r0, r7, r2
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r2, r8
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	movs r1, #0x12
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r7, r2
	strb r5, [r0]
	ldr r5, _081CCE40 @ =0x0000046A
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _081CCE44 @ =0x00000484
	adds r0, r7, r1
	str r4, [r0]
	adds r2, #3
	adds r0, r7, r2
	strb r3, [r0]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrb r0, [r0]
	adds r1, r0, #0
	adds r1, #0xa0
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _081CCE48
	asrs r0, r1, #5
	b _081CCE4E
	.align 2, 0
_081CCE34: .4byte FUN_080e48d0
_081CCE38: .4byte 0x0000046D
_081CCE3C: .4byte 0x0000046B
_081CCE40: .4byte 0x0000046A
_081CCE44: .4byte 0x00000484
_081CCE48:
	rsbs r0, r1, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081CCE4E:
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r4, #0xee
	lsls r4, r4, #1
	adds r1, r7, r4
	strb r0, [r1]
	ldrb r1, [r7, #5]
	adds r0, r1, #0
	adds r0, #0xa0
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	lsls r0, r0, #6
	strb r0, [r7, #5]
	movs r5, #0xdb
	lsls r5, r5, #3
	adds r2, r6, r5
	movs r0, #0x5a
	strb r0, [r2]
	adds r0, r7, #0
	bl FUN_081c6db8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CCE84
	b _081CD5F4
_081CCE84:
	bl _081CC586

	thumb_func_start FUN_081cce88
FUN_081cce88: @ 0x081CCE88
	ldr r6, _081CCF1C @ =0x0000048D
	adds r2, r7, r6
	ldrb r0, [r2]
	cmp r0, #0
	bne _081CCEB4
	ldr r1, _081CCF20 @ =0x0000048C
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081CCEB4
	ldr r3, _081CCF24 @ =0x000004BE
	adds r0, r7, r3
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
_081CCEB4:
	adds r0, r7, #0
	bl FUN_080faa98
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CCEC4
	bl _081CC586
_081CCEC4:
	movs r2, #0x10
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #6]
	adds r3, r7, r5
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x94]
	str r2, [sp, #0x70]
	cmp r4, #0
	blt _081CCF16
	cmp r1, #0
	blt _081CCF16
	ldr r0, _081CCF28 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081CCF16
	ldr r0, _081CCF2C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CCF30
_081CCF16:
	movs r4, #0
	b _081CCF3E
	.align 2, 0
_081CCF1C: .4byte 0x0000048D
_081CCF20: .4byte 0x0000048C
_081CCF24: .4byte 0x000004BE
_081CCF28: .4byte 0x030046A8
_081CCF2C: .4byte 0x030046AC
_081CCF30:
	ldr r0, _081CCF50 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081CCF3E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CCF54
	adds r0, #4
	b _081CCF60
	.align 2, 0
_081CCF50: .4byte 0x030046A4
_081CCF54:
	ldr r0, _081CCF74 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CCF60:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CCF78
	cmp r2, #2
	beq _081CCF7C
	b _081CCF80
	.align 2, 0
_081CCF74: .4byte 0x030046A4
_081CCF78:
	ldrb r0, [r5, #4]
	b _081CCF7E
_081CCF7C:
	ldrb r0, [r5]
_081CCF7E:
	subs r1, r1, r0
_081CCF80:
	strh r1, [r5, #2]
	ldr r0, _081CCF94 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081CCF98
	movs r0, #1
	b _081CCF9A
	.align 2, 0
_081CCF94: .4byte 0x030047A4
_081CCF98:
	movs r0, #0
_081CCF9A:
	cmp r0, #0
	beq _081CCFD8
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r1, [r0]
	cmp r1, #0
	beq _081CCFBA
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081CCFB6
	adds r2, r0, #0
_081CCFB6:
	cmp r2, #0
	bge _081CCFC4
_081CCFBA:
	ldr r1, _081CCFC0 @ =0x000005C4
	adds r0, r7, r1
	b _081CD504
	.align 2, 0
_081CCFC0: .4byte 0x000005C4
_081CCFC4:
	ldr r1, _081CCFD4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081CD020
	.align 2, 0
_081CCFD4: .4byte 0x03002BE0
_081CCFD8:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081CD004
	cmp r1, #0
	blt _081CD004
	ldr r0, _081CD008 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CD004
	ldr r0, _081CD00C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CD010
_081CD004:
	movs r5, #0
	b _081CD01E
	.align 2, 0
_081CD008: .4byte 0x030046A8
_081CD00C: .4byte 0x030046AC
_081CD010:
	ldr r0, _081CD060 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081CD01E:
	movs r2, #0
_081CD020:
	ldr r3, _081CD064 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _081CD040
	ldr r1, _081CD068 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081CD040
	b _081CD444
_081CD040:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x3c]
	str r2, [sp, #0x98]
	cmp r1, #0
	beq _081CD06C
	movs r0, #0
	b _081CD51A
	.align 2, 0
_081CD060: .4byte 0x030046A4
_081CD064: .4byte 0x00000256
_081CD068: .4byte 0x03002BE0
_081CD06C:
	ldr r5, _081CD110 @ =0x00000222
	adds r2, r7, r5
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r6, [sp, #0x98]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xb0]
	cmp r6, #0
	beq _081CD130
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _081CD114 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x40]
	movs r3, #1
	strb r3, [r2]
	ldr r4, _081CD118 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x44]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _081CD11C @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x48]
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x4c]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	mov r2, sp
	ldrh r2, [r2, #0x3c]
	strh r2, [r5]
	movs r0, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r6, #0
	strb r6, [r4]
	ldr r1, _081CD120 @ =0x00000469
	adds r3, r7, r1
	strb r6, [r3]
	ldr r6, _081CD124 @ =0x0000046A
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081CD128 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x3c]
	str r6, [r1]
	ldr r6, _081CD12C @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x40]
	str r6, [sp, #0x88]
	ldr r6, [sp, #0x44]
	str r6, [sp, #0x80]
	ldr r6, [sp, #0x48]
	str r6, [sp, #0xac]
	ldr r6, [sp, #0x4c]
	str r6, [sp, #0xb4]
	str r5, [sp, #0x9c]
	str r4, [sp, #0x74]
	str r3, [sp, #0x78]
	str r2, [sp, #0x7c]
	str r1, [sp, #0x90]
	str r0, [sp, #0x84]
	b _081CD302
	.align 2, 0
_081CD110: .4byte 0x00000222
_081CD114: .4byte 0x0000046D
_081CD118: .4byte 0x0000046B
_081CD11C: .4byte 0x00000553
_081CD120: .4byte 0x00000469
_081CD124: .4byte 0x0000046A
_081CD128: .4byte 0x00000484
_081CD12C: .4byte 0x0000046C
_081CD130:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081CD1F4 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x50]
	strb r0, [r2]
	ldr r3, _081CD1F8 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x54]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081CD1FC @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x58]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x5c]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x60]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x64]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _081CD200 @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _081CD204 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _081CD208 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x94]
	ldr r0, [r0]
	str r0, [sp, #0x68]
	ldr r1, [sp, #0x70]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x68]
	strh r1, [r6]
	ldr r6, [sp, #0x70]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x68]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x50]
	str r0, [sp, #0x88]
	ldr r6, [sp, #0x54]
	str r6, [sp, #0x80]
	ldr r0, [sp, #0x58]
	str r0, [sp, #0xac]
	ldr r6, [sp, #0x5c]
	str r6, [sp, #0xb4]
	ldr r0, [sp, #0x60]
	str r0, [sp, #0x9c]
	ldr r6, [sp, #0x64]
	str r6, [sp, #0x74]
	str r5, [sp, #0x78]
	str r4, [sp, #0x7c]
	str r3, [sp, #0x90]
	str r2, [sp, #0x84]
	mov r0, sl
	cmp r0, #0
	blt _081CD1EE
	cmp r1, #0
	blt _081CD1EE
	ldr r0, _081CD20C @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _081CD1EE
	ldr r0, _081CD210 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CD214
_081CD1EE:
	movs r4, #0
	b _081CD224
	.align 2, 0
_081CD1F4: .4byte 0x0000046D
_081CD1F8: .4byte 0x0000046B
_081CD1FC: .4byte 0x00000553
_081CD200: .4byte 0x00000469
_081CD204: .4byte 0x00000484
_081CD208: .4byte 0x0000046C
_081CD20C: .4byte 0x030046A8
_081CD210: .4byte 0x030046AC
_081CD214:
	ldr r0, _081CD234 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sl
	adds r4, r0, r1
_081CD224:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CD238
	adds r0, #4
	b _081CD244
	.align 2, 0
_081CD234: .4byte 0x030046A4
_081CD238:
	ldr r0, _081CD258 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CD244:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CD25C
	cmp r2, #2
	beq _081CD262
	b _081CD268
	.align 2, 0
_081CD258: .4byte 0x030046A4
_081CD25C:
	ldr r2, [sp, #0x68]
	ldrb r0, [r2, #4]
	b _081CD266
_081CD262:
	ldr r3, [sp, #0x68]
	ldrb r0, [r3]
_081CD266:
	subs r1, r1, r0
_081CD268:
	ldr r4, [sp, #0x68]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x94]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081CD294
	cmp r1, #0
	blt _081CD294
	ldr r0, _081CD298 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CD294
	ldr r0, _081CD29C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CD2A0
_081CD294:
	movs r4, #0
	b _081CD2AE
	.align 2, 0
_081CD298: .4byte 0x030046A8
_081CD29C: .4byte 0x030046AC
_081CD2A0:
	ldr r0, _081CD2C4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081CD2AE:
	ldr r6, [sp, #0x94]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CD2C8
	adds r0, #4
	b _081CD2D4
	.align 2, 0
_081CD2C4: .4byte 0x030046A4
_081CD2C8:
	ldr r0, _081CD2E8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CD2D4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081CD2EC
	cmp r3, #2
	beq _081CD2F0
	b _081CD2F4
	.align 2, 0
_081CD2E8: .4byte 0x030046A4
_081CD2EC:
	ldrb r0, [r5, #4]
	b _081CD2F2
_081CD2F0:
	ldrb r0, [r5]
_081CD2F2:
	subs r2, r2, r0
_081CD2F4:
	ldr r1, [sp, #0x94]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x94]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081CD302:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x6c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _081CD32C @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x8c]
	cmp r0, #0
	bne _081CD40C
	movs r1, #4
	ldr r6, [sp, #0xb0]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081CD330
	movs r0, #1
	b _081CD332
	.align 2, 0
_081CD32C: .4byte 0x00000482
_081CD330:
	movs r0, #0
_081CD332:
	ldr r1, _081CD41C @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	cmp r0, #0
	bne _081CD40C
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xb8]
	ldr r0, _081CD420 @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _081CD424 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _081CD428 @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa8]
	ldr r0, _081CD42C @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xa0]
	ldr r1, _081CD430 @ =0x000005BC
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _081CD434 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	ldr r1, _081CD438 @ =0x030046B8
	adds r2, r4, #0
_081CD37A:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _081CD43C @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _081CD440 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _081CD39E
	adds r3, #1
	cmp r3, #3
	ble _081CD37A
	adds r0, r4, #0
_081CD39E:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0xb4]
	ldr r0, [r1]
	ldr r2, [sp, #0xb8]
	str r0, [r2]
	ldr r4, [sp, #0xac]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x74]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x78]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x7c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa8]
	strb r0, [r6]
	add r0, sp, #0x6c
	ldrb r1, [r0]
	ldr r0, [sp, #0xa0]
	strb r1, [r0]
	mov r1, ip
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x88]
	strb r1, [r4]
	ldr r5, [sp, #0x80]
	strb r3, [r5]
	ldr r6, [sp, #0xac]
	strb r0, [r6]
	ldr r0, [sp, #0xb4]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x9c]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x74]
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	strb r1, [r6]
	ldr r0, [sp, #0x7c]
	strb r2, [r0]
	ldr r2, [sp, #0x90]
	str r3, [r2]
	ldr r3, [sp, #0x84]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa4]
	strb r0, [r4]
_081CD40C:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x8c]
	strh r0, [r5]
	movs r0, #0
	b _081CD51A
	.align 2, 0
_081CD41C: .4byte 0x00000482
_081CD420: .4byte 0x0000054F
_081CD424: .4byte 0x0000054C
_081CD428: .4byte 0x0000054E
_081CD42C: .4byte 0x00000541
_081CD430: .4byte 0x000005BC
_081CD434: .4byte 0x00000542
_081CD438: .4byte 0x030046B8
_081CD43C: .4byte 0x000003FF
_081CD440: .4byte 0x0203B400
_081CD444:
	add r6, sp, #8
	ldr r0, _081CD484 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	mov sl, r6
	cmp r0, #0
	beq _081CD488
	adds r0, #4
	b _081CD494
	.align 2, 0
_081CD484: .4byte 0x030046A4
_081CD488:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081CD494:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081CD4C8 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _081CD4CC
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
	b _081CD4F2
	.align 2, 0
_081CD4C8: .4byte 0x000004A4
_081CD4CC:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _081CD4EC
	cmp r0, #2
	beq _081CD4E8
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CD4E8:
	movs r0, #1
	b _081CD4FC
_081CD4EC:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
_081CD4F2:
	ldr r1, _081CD510 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081CD4FC:
	cmp r0, #0
	bne _081CD518
	ldr r2, _081CD514 @ =0x000005C4
	adds r0, r7, r2
_081CD504:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081CD51A
	.align 2, 0
_081CD510: .4byte 0xFFFFFDFF
_081CD514: .4byte 0x000005C4
_081CD518:
	movs r0, #1
_081CD51A:
	cmp r0, #0
	bne _081CD59C
	ldr r3, _081CD54C @ =0x000004A4
	adds r0, r7, r3
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081CD550
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r7, r5
	b _081CD576
	.align 2, 0
_081CD54C: .4byte 0x000004A4
_081CD550:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081CD570
	cmp r0, #2
	beq _081CD56C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CD56C:
	movs r0, #1
	b _081CD580
_081CD570:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
_081CD576:
	ldr r1, _081CD594 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081CD580:
	cmp r0, #0
	bne _081CD59C
	ldr r1, _081CD598 @ =0x000005C4
	adds r0, r7, r1
FUN_081cd588:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	bl _081CC586
	.align 2, 0
_081CD594: .4byte 0xFFFFFDFF
_081CD598: .4byte 0x000005C4
_081CD59C:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	movs r3, #1
	ldr r4, _081CD608 @ =0x0000046D
	adds r0, r7, r4
	movs r2, #0
	strb r3, [r0]
	ldr r5, _081CD60C @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _081CD610 @ =0x00000553
	adds r0, r7, r6
	strb r3, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r7, r4
	str r1, [r0]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r0, r7, r5
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r6, #0xeb
	adds r0, r7, r6
	strb r1, [r0]
	ldr r5, _081CD614 @ =0x00000469
	adds r0, r7, r5
	strb r1, [r0]
	adds r6, #2
	adds r0, r7, r6
	strb r4, [r0]
	ldr r1, _081CD618 @ =0x00000484
	adds r0, r7, r1
	str r2, [r0]
	ldr r2, _081CD61C @ =0x0000046C
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _081CD620 @ =0x00000482
	adds r1, r7, r3
	movs r0, #4
	strh r0, [r1]
_081CD5F4:
	movs r0, #1
FUN_081cd5f6:
	add sp, #0xbc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081CD608: .4byte 0x0000046D
_081CD60C: .4byte 0x0000046B
_081CD610: .4byte 0x00000553
_081CD614: .4byte 0x00000469
_081CD618: .4byte 0x00000484
_081CD61C: .4byte 0x0000046C
_081CD620: .4byte 0x00000482

	thumb_func_start FUN_081cd624
FUN_081cd624: @ 0x081CD624
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc0
	adds r7, r0, #0
	ldr r0, _081CD644 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081CD648
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081CD64A
	.align 2, 0
_081CD644: .4byte 0x0000046D
_081CD648:
	movs r0, #0
_081CD64A:
	cmp r0, #0
	beq _081CD6A8
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _081CD660
	asrs r1, r0, #2
	b _081CD666
_081CD660:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_081CD666:
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r0, r7, r4
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	blt _081CD680
	asrs r1, r0, #2
	b _081CD686
_081CD680:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_081CD686:
	movs r6, #0xe2
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r1, [r0]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
	movs r0, #0x20
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	ldr r1, _081CD6D8 @ =0xFFFFFEFF
	ands r0, r1
	strh r0, [r2]
_081CD6A8:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r4, #0x83
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r5, #0
	ldrsh r2, [r0, r5]
	movs r6, #0x85
	lsls r6, r6, #2
	adds r1, r7, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _081CD6DC
	asrs r0, r0, #2
	b _081CD6E2
	.align 2, 0
_081CD6D8: .4byte 0xFFFFFEFF
_081CD6DC:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081CD6E2:
	adds r3, r0, #0
	movs r5, #0x84
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r6, #0
	ldrsh r2, [r0, r6]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	cmp r0, #0
	blt _081CD702
	asrs r0, r0, #2
	b _081CD708
_081CD702:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081CD708:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _081CD712
	movs r3, #0xc8
	b _081CD71C
_081CD712:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _081CD71C
	adds r3, r0, #0
_081CD71C:
	cmp r2, #0xc8
	ble _081CD724
	movs r2, #0xc8
	b _081CD72E
_081CD724:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _081CD72E
	adds r2, r0, #0
_081CD72E:
	ldrh r0, [r7, #0x10]
	adds r0, r0, r3
	strh r0, [r7, #0x10]
	ldrh r0, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _081CD752
	cmp r2, #0
	bne _081CD752
	movs r0, #1
	b _081CD754
_081CD752:
	movs r0, #0
_081CD754:
	cmp r0, #0
	bne _081CD75C
	bl FUN_081ce634
_081CD75C:
	ldr r6, _081CD7A8 @ =0x0000046E
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _081CD76A
	bl FUN_081ce634
_081CD76A:
	ldr r0, _081CD7AC @ =0x0000046B
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	movs r3, #0x21
	rsbs r3, r3, #0
	ldrh r0, [r2]
	ands r3, r0
	strh r3, [r2]
	ldr r4, _081CD7B0 @ =0x0000049C
	adds r0, r7, r4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xc
	ands r0, r1
	str r2, [sp, #0x9c]
	cmp r0, #0
	beq _081CD7B4
	movs r0, #2
	movs r5, #0xc1
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	bl _081CE644
	.align 2, 0
_081CD7A8: .4byte 0x0000046E
_081CD7AC: .4byte 0x0000046B
_081CD7B0: .4byte 0x0000049C
_081CD7B4:
	movs r2, #0x80
	adds r0, r3, #0
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _081CD7C4
	b _081CDEEC
_081CD7C4:
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r1, [r0]
	orrs r1, r2
	str r1, [r0]
	adds r0, r7, #0
	bl FUN_080faa98
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CD7E0
	bl _081CE644
_081CD7E0:
	movs r0, #0x95
	lsls r0, r0, #3
	adds r3, r7, r0
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x98]
	str r2, [sp, #0x74]
	cmp r4, #0
	blt _081CD81C
	cmp r1, #0
	blt _081CD81C
	ldr r0, _081CD820 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081CD81C
	ldr r0, _081CD824 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CD828
_081CD81C:
	movs r4, #0
	b _081CD836
	.align 2, 0
_081CD820: .4byte 0x030046A8
_081CD824: .4byte 0x030046AC
_081CD828:
	ldr r0, _081CD848 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081CD836:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CD84C
	adds r0, #4
	b _081CD858
	.align 2, 0
_081CD848: .4byte 0x030046A4
_081CD84C:
	ldr r0, _081CD86C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CD858:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CD870
	cmp r2, #2
	beq _081CD874
	b _081CD878
	.align 2, 0
_081CD86C: .4byte 0x030046A4
_081CD870:
	ldrb r0, [r5, #4]
	b _081CD876
_081CD874:
	ldrb r0, [r5]
_081CD876:
	subs r1, r1, r0
_081CD878:
	strh r1, [r5, #2]
	ldr r0, _081CD88C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081CD890
	movs r0, #1
	b _081CD892
	.align 2, 0
_081CD88C: .4byte 0x030047A4
_081CD890:
	movs r0, #0
_081CD892:
	cmp r0, #0
	beq _081CD8D0
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081CD8B2
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081CD8AE
	adds r2, r0, #0
_081CD8AE:
	cmp r2, #0
	bge _081CD8BC
_081CD8B2:
	ldr r2, _081CD8B8 @ =0x000005C4
	adds r0, r7, r2
	b _081CDDE8
	.align 2, 0
_081CD8B8: .4byte 0x000005C4
_081CD8BC:
	ldr r1, _081CD8CC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081CD918
	.align 2, 0
_081CD8CC: .4byte 0x03002BE0
_081CD8D0:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081CD8FC
	cmp r1, #0
	blt _081CD8FC
	ldr r0, _081CD900 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CD8FC
	ldr r0, _081CD904 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CD908
_081CD8FC:
	movs r5, #0
	b _081CD916
	.align 2, 0
_081CD900: .4byte 0x030046A8
_081CD904: .4byte 0x030046AC
_081CD908:
	ldr r0, _081CD950 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081CD916:
	movs r2, #0
_081CD918:
	ldr r4, _081CD954 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _081CD938
	ldr r1, _081CD958 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081CD938
	b _081CDD28
_081CD938:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x9c]
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
	cmp r0, #0
	beq _081CD95C
	movs r0, #0
	b _081CDDFE
	.align 2, 0
_081CD950: .4byte 0x030046A4
_081CD954: .4byte 0x00000256
_081CD958: .4byte 0x03002BE0
_081CD95C:
	ldr r6, _081CDA00 @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x9c]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xac]
	cmp r6, #0
	beq _081CDA14
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _081CDA04 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x14]
	movs r6, #1
	strb r6, [r5]
	ldr r2, _081CDA08 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x18]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0x1c]
	strb r0, [r4]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r5, r7
	mov r8, r5
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	mov r0, sp
	ldrh r0, [r0, #0x10]
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r3, [r4]
	ldr r2, _081CDA0C @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _081CDA10 @ =0x00000484
	adds r1, r7, r6
	ldr r0, [sp, #0x10]
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x8c]
	ldr r6, [sp, #0x18]
	str r6, [sp, #0x84]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0xb0]
	mov r6, r8
	str r6, [sp, #0xb4]
	str r5, [sp, #0xa0]
	str r4, [sp, #0x78]
	str r3, [sp, #0x7c]
	str r2, [sp, #0x80]
	str r1, [sp, #0x94]
	str r0, [sp, #0x88]
	b _081CDBE6
	.align 2, 0
_081CDA00: .4byte 0x00000222
_081CDA04: .4byte 0x0000046D
_081CDA08: .4byte 0x0000046B
_081CDA0C: .4byte 0x00000469
_081CDA10: .4byte 0x00000484
_081CDA14:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081CDAD8 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x20]
	strb r0, [r2]
	ldr r3, _081CDADC @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x24]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081CDAE0 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x28]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x30]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x34]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _081CDAE4 @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _081CDAE8 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _081CDAEC @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x98]
	ldr r0, [r0]
	str r0, [sp, #0x38]
	ldr r1, [sp, #0x74]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x38]
	strh r1, [r6]
	ldr r6, [sp, #0x74]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x38]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x8c]
	ldr r6, [sp, #0x24]
	str r6, [sp, #0x84]
	ldr r0, [sp, #0x28]
	str r0, [sp, #0xb0]
	ldr r6, [sp, #0x2c]
	str r6, [sp, #0xb4]
	ldr r0, [sp, #0x30]
	str r0, [sp, #0xa0]
	ldr r6, [sp, #0x34]
	str r6, [sp, #0x78]
	str r5, [sp, #0x7c]
	str r4, [sp, #0x80]
	str r3, [sp, #0x94]
	str r2, [sp, #0x88]
	mov r0, sl
	cmp r0, #0
	blt _081CDAD2
	cmp r1, #0
	blt _081CDAD2
	ldr r0, _081CDAF0 @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _081CDAD2
	ldr r0, _081CDAF4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CDAF8
_081CDAD2:
	movs r4, #0
	b _081CDB08
	.align 2, 0
_081CDAD8: .4byte 0x0000046D
_081CDADC: .4byte 0x0000046B
_081CDAE0: .4byte 0x00000553
_081CDAE4: .4byte 0x00000469
_081CDAE8: .4byte 0x00000484
_081CDAEC: .4byte 0x0000046C
_081CDAF0: .4byte 0x030046A8
_081CDAF4: .4byte 0x030046AC
_081CDAF8:
	ldr r0, _081CDB18 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sl
	adds r4, r0, r1
_081CDB08:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CDB1C
	adds r0, #4
	b _081CDB28
	.align 2, 0
_081CDB18: .4byte 0x030046A4
_081CDB1C:
	ldr r0, _081CDB3C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CDB28:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CDB40
	cmp r2, #2
	beq _081CDB46
	b _081CDB4C
	.align 2, 0
_081CDB3C: .4byte 0x030046A4
_081CDB40:
	ldr r2, [sp, #0x38]
	ldrb r0, [r2, #4]
	b _081CDB4A
_081CDB46:
	ldr r3, [sp, #0x38]
	ldrb r0, [r3]
_081CDB4A:
	subs r1, r1, r0
_081CDB4C:
	ldr r4, [sp, #0x38]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x98]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081CDB78
	cmp r1, #0
	blt _081CDB78
	ldr r0, _081CDB7C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CDB78
	ldr r0, _081CDB80 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CDB84
_081CDB78:
	movs r4, #0
	b _081CDB92
	.align 2, 0
_081CDB7C: .4byte 0x030046A8
_081CDB80: .4byte 0x030046AC
_081CDB84:
	ldr r0, _081CDBA8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081CDB92:
	ldr r6, [sp, #0x98]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CDBAC
	adds r0, #4
	b _081CDBB8
	.align 2, 0
_081CDBA8: .4byte 0x030046A4
_081CDBAC:
	ldr r0, _081CDBCC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CDBB8:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081CDBD0
	cmp r3, #2
	beq _081CDBD4
	b _081CDBD8
	.align 2, 0
_081CDBCC: .4byte 0x030046A4
_081CDBD0:
	ldrb r0, [r5, #4]
	b _081CDBD6
_081CDBD4:
	ldrb r0, [r5]
_081CDBD6:
	subs r2, r2, r0
_081CDBD8:
	ldr r1, [sp, #0x98]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x98]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081CDBE6:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x3c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x9c]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _081CDC10 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x90]
	cmp r0, #0
	bne _081CDCF0
	movs r1, #4
	ldr r6, [sp, #0xac]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081CDC14
	movs r0, #1
	b _081CDC16
	.align 2, 0
_081CDC10: .4byte 0x00000482
_081CDC14:
	movs r0, #0
_081CDC16:
	ldr r1, _081CDD00 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x90]
	cmp r0, #0
	bne _081CDCF0
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xbc]
	ldr r0, _081CDD04 @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _081CDD08 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _081CDD0C @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa8]
	ldr r0, _081CDD10 @ =0x00000541
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _081CDD14 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xb8]
	ldr r2, _081CDD18 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	ldr r1, _081CDD1C @ =0x030046B8
	adds r2, r4, #0
_081CDC5E:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _081CDD20 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _081CDD24 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _081CDC82
	adds r3, #1
	cmp r3, #3
	ble _081CDC5E
	adds r0, r4, #0
_081CDC82:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0xb4]
	ldr r0, [r1]
	ldr r2, [sp, #0xbc]
	str r0, [r2]
	ldr r4, [sp, #0xb0]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x7c]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x80]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa8]
	strb r0, [r6]
	add r0, sp, #0x3c
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xb8]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x8c]
	strb r1, [r4]
	ldr r5, [sp, #0x84]
	strb r3, [r5]
	ldr r6, [sp, #0xb0]
	strb r0, [r6]
	ldr r0, [sp, #0xb4]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xa0]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x78]
	strb r0, [r5]
	ldr r6, [sp, #0x7c]
	strb r1, [r6]
	ldr r0, [sp, #0x80]
	strb r2, [r0]
	ldr r2, [sp, #0x94]
	str r3, [r2]
	ldr r3, [sp, #0x88]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa4]
	strb r0, [r4]
_081CDCF0:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x90]
	strh r0, [r5]
	movs r0, #0
	b _081CDDFE
	.align 2, 0
_081CDD00: .4byte 0x00000482
_081CDD04: .4byte 0x0000054F
_081CDD08: .4byte 0x0000054C
_081CDD0C: .4byte 0x0000054E
_081CDD10: .4byte 0x00000541
_081CDD14: .4byte 0x000005BC
_081CDD18: .4byte 0x00000542
_081CDD1C: .4byte 0x030046B8
_081CDD20: .4byte 0x000003FF
_081CDD24: .4byte 0x0203B400
_081CDD28:
	mov sb, sp
	ldr r6, _081CDD64 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CDD68
	adds r0, #4
	b _081CDD72
	.align 2, 0
_081CDD64: .4byte 0x030046A4
_081CDD68:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081CDD72:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _081CDDAC @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _081CDDB4
	ldr r0, _081CDDB0 @ =0xFFFFFDFF
	ldr r2, [sp, #0x9c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081CDDDE
	.align 2, 0
_081CDDAC: .4byte 0x000004A4
_081CDDB0: .4byte 0xFFFFFDFF
_081CDDB4:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081CDDD4
	cmp r0, #2
	beq _081CDDD0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CDDD0:
	movs r0, #1
	b _081CDDE0
_081CDDD4:
	ldr r0, _081CDDF4 @ =0xFFFFFDFF
	ldr r3, [sp, #0x9c]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081CDDDE:
	movs r0, #0
_081CDDE0:
	cmp r0, #0
	bne _081CDDFC
	ldr r4, _081CDDF8 @ =0x000005C4
	adds r0, r7, r4
_081CDDE8:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081CDDFE
	.align 2, 0
_081CDDF4: .4byte 0xFFFFFDFF
_081CDDF8: .4byte 0x000005C4
_081CDDFC:
	movs r0, #1
_081CDDFE:
	cmp r0, #0
	bne _081CDE6E
	ldr r5, _081CDE34 @ =0x000004A4
	adds r0, r7, r5
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081CDE3C
	ldr r0, _081CDE38 @ =0xFFFFFDFF
	ldr r2, [sp, #0x9c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081CDE66
	.align 2, 0
_081CDE34: .4byte 0x000004A4
_081CDE38: .4byte 0xFFFFFDFF
_081CDE3C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081CDE5C
	cmp r0, #2
	beq _081CDE58
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CDE58:
	movs r0, #1
	b _081CDE68
_081CDE5C:
	ldr r0, _081CDED0 @ =0xFFFFFDFF
	ldr r3, [sp, #0x9c]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081CDE66:
	movs r0, #0
_081CDE68:
	cmp r0, #0
	bne _081CDE6E
	b _081CE5AC
_081CDE6E:
	movs r0, #4
	ldr r5, _081CDED4 @ =0x00000222
	adds r2, r7, r5
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r2, [r0]
	movs r1, #0x1a
	ldr r4, _081CDED8 @ =0x0000046D
	adds r0, r7, r4
	movs r4, #1
	strb r4, [r0]
	ldr r6, _081CDEDC @ =0x0000046B
	adds r0, r7, r6
	strb r3, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	movs r1, #0xc
	subs r6, #0xeb
	adds r0, r7, r6
	strb r3, [r0]
	ldr r2, _081CDEE0 @ =0x00000469
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _081CDEE4 @ =0x0000046A
	adds r0, r7, r3
	strb r1, [r0]
	adds r6, #0x1c
	adds r0, r7, r6
	str r5, [r0]
	ldr r1, _081CDEE8 @ =0x0000046C
	adds r0, r7, r1
	strb r4, [r0]
	b _081CE644
	.align 2, 0
_081CDED0: .4byte 0xFFFFFDFF
_081CDED4: .4byte 0x00000222
_081CDED8: .4byte 0x0000046D
_081CDEDC: .4byte 0x0000046B
_081CDEE0: .4byte 0x00000469
_081CDEE4: .4byte 0x0000046A
_081CDEE8: .4byte 0x0000046C
_081CDEEC:
	adds r0, r7, #0
	bl FUN_080faa98
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CDEFA
	b _081CE644
_081CDEFA:
	movs r2, #0x10
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r0, [r0]
	strh r4, [r0, #6]
	adds r3, r7, r5
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x98]
	str r2, [sp, #0x74]
	cmp r4, #0
	blt _081CDF4A
	cmp r1, #0
	blt _081CDF4A
	ldr r0, _081CDF50 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081CDF4A
	ldr r0, _081CDF54 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CDF58
_081CDF4A:
	movs r4, #0
	b _081CDF66
	.align 2, 0
_081CDF50: .4byte 0x030046A8
_081CDF54: .4byte 0x030046AC
_081CDF58:
	ldr r0, _081CDF78 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081CDF66:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CDF7C
	adds r0, #4
	b _081CDF88
	.align 2, 0
_081CDF78: .4byte 0x030046A4
_081CDF7C:
	ldr r0, _081CDF9C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CDF88:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CDFA0
	cmp r2, #2
	beq _081CDFA4
	b _081CDFA8
	.align 2, 0
_081CDF9C: .4byte 0x030046A4
_081CDFA0:
	ldrb r0, [r5, #4]
	b _081CDFA6
_081CDFA4:
	ldrb r0, [r5]
_081CDFA6:
	subs r1, r1, r0
_081CDFA8:
	strh r1, [r5, #2]
	ldr r0, _081CDFBC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081CDFC0
	movs r0, #1
	b _081CDFC2
	.align 2, 0
_081CDFBC: .4byte 0x030047A4
_081CDFC0:
	movs r0, #0
_081CDFC2:
	cmp r0, #0
	beq _081CE000
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r1, [r0]
	cmp r1, #0
	beq _081CDFE2
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081CDFDE
	adds r2, r0, #0
_081CDFDE:
	cmp r2, #0
	bge _081CDFEC
_081CDFE2:
	ldr r1, _081CDFE8 @ =0x000005C4
	adds r0, r7, r1
	b _081CE528
	.align 2, 0
_081CDFE8: .4byte 0x000005C4
_081CDFEC:
	ldr r1, _081CDFFC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081CE048
	.align 2, 0
_081CDFFC: .4byte 0x03002BE0
_081CE000:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081CE02C
	cmp r1, #0
	blt _081CE02C
	ldr r0, _081CE030 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CE02C
	ldr r0, _081CE034 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CE038
_081CE02C:
	movs r5, #0
	b _081CE046
	.align 2, 0
_081CE030: .4byte 0x030046A8
_081CE034: .4byte 0x030046AC
_081CE038:
	ldr r0, _081CE080 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081CE046:
	movs r2, #0
_081CE048:
	ldr r3, _081CE084 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _081CE068
	ldr r1, _081CE088 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081CE068
	b _081CE464
_081CE068:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x9c]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x40]
	cmp r0, #0
	beq _081CE08C
	movs r0, #0
	b _081CE53E
	.align 2, 0
_081CE080: .4byte 0x030046A4
_081CE084: .4byte 0x00000256
_081CE088: .4byte 0x03002BE0
_081CE08C:
	ldr r5, _081CE130 @ =0x00000222
	adds r2, r7, r5
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r6, [sp, #0x9c]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	str r2, [sp, #0xac]
	cmp r0, #0
	beq _081CE150
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _081CE134 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x44]
	movs r3, #1
	strb r3, [r2]
	ldr r4, _081CE138 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x48]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _081CE13C @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x4c]
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x50]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	add r2, sp, #0x40
	ldrh r2, [r2]
	strh r2, [r5]
	movs r0, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r6, #0
	strb r6, [r4]
	ldr r1, _081CE140 @ =0x00000469
	adds r3, r7, r1
	strb r6, [r3]
	ldr r6, _081CE144 @ =0x0000046A
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081CE148 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x40]
	str r6, [r1]
	ldr r6, _081CE14C @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x44]
	str r6, [sp, #0x8c]
	ldr r6, [sp, #0x48]
	str r6, [sp, #0x84]
	ldr r6, [sp, #0x4c]
	str r6, [sp, #0xb0]
	ldr r6, [sp, #0x50]
	str r6, [sp, #0xb4]
	str r5, [sp, #0xa0]
	str r4, [sp, #0x78]
	str r3, [sp, #0x7c]
	str r2, [sp, #0x80]
	str r1, [sp, #0x94]
	str r0, [sp, #0x88]
	b _081CE322
	.align 2, 0
_081CE130: .4byte 0x00000222
_081CE134: .4byte 0x0000046D
_081CE138: .4byte 0x0000046B
_081CE13C: .4byte 0x00000553
_081CE140: .4byte 0x00000469
_081CE144: .4byte 0x0000046A
_081CE148: .4byte 0x00000484
_081CE14C: .4byte 0x0000046C
_081CE150:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081CE214 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x54]
	strb r0, [r2]
	ldr r3, _081CE218 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x58]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081CE21C @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x5c]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x60]
	str r1, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x64]
	mov r2, ip
	strh r2, [r1]
	movs r1, #5
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x68]
	strb r4, [r3]
	ldr r4, _081CE220 @ =0x00000469
	adds r5, r7, r4
	movs r6, #0
	strb r6, [r5]
	ldr r2, _081CE224 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r6, _081CE228 @ =0x00000484
	adds r3, r7, r6
	mov r1, ip
	str r1, [r3]
	subs r6, #0x18
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x98]
	ldr r0, [r0]
	str r0, [sp, #0x6c]
	ldr r1, [sp, #0x74]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x6c]
	strh r1, [r6]
	ldr r6, [sp, #0x74]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x6c]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x54]
	str r0, [sp, #0x8c]
	ldr r6, [sp, #0x58]
	str r6, [sp, #0x84]
	ldr r0, [sp, #0x5c]
	str r0, [sp, #0xb0]
	ldr r6, [sp, #0x60]
	str r6, [sp, #0xb4]
	ldr r0, [sp, #0x64]
	str r0, [sp, #0xa0]
	ldr r6, [sp, #0x68]
	str r6, [sp, #0x78]
	str r5, [sp, #0x7c]
	str r4, [sp, #0x80]
	str r3, [sp, #0x94]
	str r2, [sp, #0x88]
	mov r0, sb
	cmp r0, #0
	blt _081CE210
	cmp r1, #0
	blt _081CE210
	ldr r0, _081CE22C @ =0x030046A8
	ldr r0, [r0]
	cmp sb, r0
	bhs _081CE210
	ldr r0, _081CE230 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CE234
_081CE210:
	movs r4, #0
	b _081CE244
	.align 2, 0
_081CE214: .4byte 0x0000046D
_081CE218: .4byte 0x0000046B
_081CE21C: .4byte 0x00000553
_081CE220: .4byte 0x00000469
_081CE224: .4byte 0x0000046A
_081CE228: .4byte 0x00000484
_081CE22C: .4byte 0x030046A8
_081CE230: .4byte 0x030046AC
_081CE234:
	ldr r0, _081CE254 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sb
	adds r4, r0, r1
_081CE244:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CE258
	adds r0, #4
	b _081CE264
	.align 2, 0
_081CE254: .4byte 0x030046A4
_081CE258:
	ldr r0, _081CE278 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CE264:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CE27C
	cmp r2, #2
	beq _081CE282
	b _081CE288
	.align 2, 0
_081CE278: .4byte 0x030046A4
_081CE27C:
	ldr r2, [sp, #0x6c]
	ldrb r0, [r2, #4]
	b _081CE286
_081CE282:
	ldr r3, [sp, #0x6c]
	ldrb r0, [r3]
_081CE286:
	subs r1, r1, r0
_081CE288:
	ldr r4, [sp, #0x6c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x98]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081CE2B4
	cmp r1, #0
	blt _081CE2B4
	ldr r0, _081CE2B8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CE2B4
	ldr r0, _081CE2BC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CE2C0
_081CE2B4:
	movs r4, #0
	b _081CE2CE
	.align 2, 0
_081CE2B8: .4byte 0x030046A8
_081CE2BC: .4byte 0x030046AC
_081CE2C0:
	ldr r0, _081CE2E4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081CE2CE:
	ldr r6, [sp, #0x98]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CE2E8
	adds r0, #4
	b _081CE2F4
	.align 2, 0
_081CE2E4: .4byte 0x030046A4
_081CE2E8:
	ldr r0, _081CE308 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CE2F4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081CE30C
	cmp r3, #2
	beq _081CE310
	b _081CE314
	.align 2, 0
_081CE308: .4byte 0x030046A4
_081CE30C:
	ldrb r0, [r5, #4]
	b _081CE312
_081CE310:
	ldrb r0, [r5]
_081CE312:
	subs r2, r2, r0
_081CE314:
	ldr r1, [sp, #0x98]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x98]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081CE322:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x70]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x9c]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _081CE34C @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x90]
	cmp r0, #0
	bne _081CE42C
	movs r1, #4
	ldr r6, [sp, #0xac]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081CE350
	movs r0, #1
	b _081CE352
	.align 2, 0
_081CE34C: .4byte 0x00000482
_081CE350:
	movs r0, #0
_081CE352:
	ldr r1, _081CE43C @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x90]
	cmp r0, #0
	bne _081CE42C
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xbc]
	ldr r0, _081CE440 @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _081CE444 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _081CE448 @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa8]
	ldr r0, _081CE44C @ =0x00000541
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _081CE450 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xb8]
	ldr r2, _081CE454 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	ldr r1, _081CE458 @ =0x030046B8
	adds r2, r4, #0
_081CE39A:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _081CE45C @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _081CE460 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _081CE3BE
	adds r3, #1
	cmp r3, #3
	ble _081CE39A
	adds r0, r4, #0
_081CE3BE:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0xb4]
	ldr r0, [r1]
	ldr r2, [sp, #0xbc]
	str r0, [r2]
	ldr r4, [sp, #0xb0]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x7c]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x80]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa8]
	strb r0, [r6]
	add r0, sp, #0x70
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xb8]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x8c]
	strb r1, [r4]
	ldr r5, [sp, #0x84]
	strb r3, [r5]
	ldr r6, [sp, #0xb0]
	strb r0, [r6]
	ldr r0, [sp, #0xb4]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xa0]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x78]
	strb r0, [r5]
	ldr r6, [sp, #0x7c]
	strb r1, [r6]
	ldr r0, [sp, #0x80]
	strb r2, [r0]
	ldr r2, [sp, #0x94]
	str r3, [r2]
	ldr r3, [sp, #0x88]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa4]
	strb r0, [r4]
_081CE42C:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x90]
	strh r0, [r5]
	movs r0, #0
	b _081CE53E
	.align 2, 0
_081CE43C: .4byte 0x00000482
_081CE440: .4byte 0x0000054F
_081CE444: .4byte 0x0000054C
_081CE448: .4byte 0x0000054E
_081CE44C: .4byte 0x00000541
_081CE450: .4byte 0x000005BC
_081CE454: .4byte 0x00000542
_081CE458: .4byte 0x030046B8
_081CE45C: .4byte 0x000003FF
_081CE460: .4byte 0x0203B400
_081CE464:
	add r6, sp, #8
	ldr r0, _081CE4A4 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	mov sl, r6
	cmp r0, #0
	beq _081CE4A8
	adds r0, #4
	b _081CE4B4
	.align 2, 0
_081CE4A4: .4byte 0x030046A4
_081CE4A8:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081CE4B4:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _081CE4EC @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _081CE4F4
	ldr r0, _081CE4F0 @ =0xFFFFFDFF
	ldr r6, [sp, #0x9c]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081CE51E
	.align 2, 0
_081CE4EC: .4byte 0x000004A4
_081CE4F0: .4byte 0xFFFFFDFF
_081CE4F4:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _081CE514
	cmp r0, #2
	beq _081CE510
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CE510:
	movs r0, #1
	b _081CE520
_081CE514:
	ldr r0, _081CE534 @ =0xFFFFFDFF
	ldr r2, [sp, #0x9c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081CE51E:
	movs r0, #0
_081CE520:
	cmp r0, #0
	bne _081CE53C
	ldr r3, _081CE538 @ =0x000005C4
	adds r0, r7, r3
_081CE528:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081CE53E
	.align 2, 0
_081CE534: .4byte 0xFFFFFDFF
_081CE538: .4byte 0x000005C4
_081CE53C:
	movs r0, #1
_081CE53E:
	cmp r0, #0
	bne _081CE5C4
	ldr r4, _081CE574 @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081CE57C
	ldr r0, _081CE578 @ =0xFFFFFDFF
	ldr r2, [sp, #0x9c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081CE5A6
	.align 2, 0
_081CE574: .4byte 0x000004A4
_081CE578: .4byte 0xFFFFFDFF
_081CE57C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081CE59C
	cmp r0, #2
	beq _081CE598
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081CE598:
	movs r0, #1
	b _081CE5A8
_081CE59C:
	ldr r0, _081CE5BC @ =0xFFFFFDFF
	ldr r3, [sp, #0x9c]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081CE5A6:
	movs r0, #0
_081CE5A8:
	cmp r0, #0
	bne _081CE5C4
_081CE5AC:
	ldr r4, _081CE5C0 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081CE644
	.align 2, 0
_081CE5BC: .4byte 0xFFFFFDFF
_081CE5C0: .4byte 0x000005C4
_081CE5C4:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _081CE620 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _081CE624 @ =0x0000046B
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #0x4d
	adds r0, r7, r5
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _081CE628 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081CE62C @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _081CE630 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #4
	strh r0, [r1]
	b _081CE644
	.align 2, 0
_081CE620: .4byte 0x0000046D
_081CE624: .4byte 0x0000046B
_081CE628: .4byte 0x00000469
_081CE62C: .4byte 0x0000046A
_081CE630: .4byte 0x00000484

	thumb_func_start FUN_081ce634
FUN_081ce634: @ 0x081CE634
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081CE644:
	add sp, #0xc0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081ce654
FUN_081ce654: @ 0x081CE654
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	bl FUN_081cb3a4
	ldr r1, _081CE698 @ =0x000004BE
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _081CE688
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrb r0, [r0]
	ldr r2, _081CE69C @ =0x0000062C
	adds r1, r4, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080e4964
_081CE688:
	adds r0, r5, #0
	bl FUN_081cb3dc
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081CE698: .4byte 0x000004BE
_081CE69C: .4byte 0x0000062C

	thumb_func_start FUN_081ce6a0
FUN_081ce6a0: @ 0x081CE6A0
	push {lr}
	bl FUN_080f06b0
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_081ce6ac
FUN_081ce6ac: @ 0x081CE6AC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _081CE6C4 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081CE6C8
	ldr r0, [r4, #0x44]
	bl FUN_0822a4e0
	b _081CE6D0
	.align 2, 0
_081CE6C4: .4byte 0x0000025D
_081CE6C8:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl FUN_0822f1c0
_081CE6D0:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _081CE6EC @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _081CE6F0
	movs r0, #1
	b _081CE6F2
	.align 2, 0
_081CE6EC: .4byte 0x00000474
_081CE6F0:
	movs r0, #0
_081CE6F2:
	cmp r0, #0
	beq _081CE6FE
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_08022428
_081CE6FE:
	ldr r1, _081CE758 @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _081CE716
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_080138fc
	movs r0, #1
	strb r0, [r5]
_081CE716:
	ldr r0, _081CE75C @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _081CE72E
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08247504
	movs r0, #1
	strb r0, [r5]
_081CE72E:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081CE746
	adds r0, r4, #0
	bl FUN_08002a58
_081CE746:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081CE760
	movs r0, #1
	b _081CE762
	.align 2, 0
_081CE758: .4byte 0x0000044C
_081CE75C: .4byte 0x0000044D
_081CE760:
	movs r0, #0
_081CE762:
	cmp r0, #0
	beq _081CE76E
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_081CE76E:
	adds r0, r4, #0
	bl FUN_0823b284
	adds r0, r4, #0
	adds r0, #0xd8
	bl FUN_08236424
	adds r0, r4, #0
	bl FUN_080ec6fc
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081ce78c
FUN_081ce78c: @ 0x081CE78C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1a4
	adds r7, r0, #0
	str r7, [sp, #0x24]
	movs r1, #0xd5
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r6, #0
	str r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_080e37e8
	ldr r2, _081CE818 @ =0x000001DF
	adds r1, r7, r2
	movs r0, #0x15
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_081c6410
	ldr r3, _081CE81C @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081CE828
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _081CE820 @ =0x0000D635
	bl FUN_0822b16c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	ldr r1, _081CE824 @ =0x0000F6E7
	bl FUN_080e3804
	ldr r4, _081CE818 @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0xa4]
	cmp r1, #0x11
	beq _081CE806
	cmp r1, #0x17
	bne _081CE80A
_081CE806:
	movs r0, #1
	strb r0, [r5, #7]
_081CE80A:
	movs r5, #0xef
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strb r0, [r1]
	b _081CE890
	.align 2, 0
_081CE818: .4byte 0x000001DF
_081CE81C: .4byte 0x0000025D
_081CE820: .4byte 0x0000D635
_081CE824: .4byte 0x0000F6E7
_081CE828:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r0, sp, #0x14
	mov r8, r0
	str r6, [sp, #0x10]
	add r0, sp, #0x10
	mov r1, r8
	ldr r2, _081CE90C @ =0x05000002
	bl CpuSet
	ldr r0, _081CE910 @ =0x0000CB05
	ldr r1, _081CE914 @ =0x0000D635
	bl GetFile
	adds r1, r0, #0
	adds r2, r4, #0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r2!, {r3, r5}
	adds r0, r4, #0
	bl OpenSpriteSetFile
	adds r0, r4, #0
	adds r0, #0x20
	movs r1, #2
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	mov r6, r8
	str r6, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	ldr r0, _081CE918 @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _081CE91C @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0xa4]
_081CE890:
	str r7, [sp, #0x28]
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r2, r2, r7
	mov sb, r2
	movs r4, #0
	str r4, [r2]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r3, r3, r7
	mov r8, r3
	str r4, [r3]
	ldr r5, _081CE920 @ =0x0000046F
	adds r0, r7, r5
	strb r4, [r0]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r1, r7, r6
	movs r0, #0
	mov sl, r0
	movs r0, #8
	strh r0, [r1]
	movs r0, #0x4d
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r1, _081CE924 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _081CE90C @ =0x05000002
	bl CpuSet
	ldr r3, _081CE928 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1a0]
	bl prepare_08231510
	mov r1, sb
	str r1, [sp, #0x68]
	mov r3, r8
	str r3, [sp, #0x70]
	str r6, [sp, #0x4c]
	ldr r2, [sp, #0x1a0]
	adds r6, r2, #0
	cmp r0, #0
	bne _081CE8FC
	b _081CEA5C
_081CE8FC:
	bl VM_GetPC
	cmp r0, #0
	beq _081CE92C
	bl Script_GetValue
	adds r1, r0, #0
	b _081CE92E
	.align 2, 0
_081CE90C: .4byte 0x05000002
_081CE910: .4byte 0x0000CB05
_081CE914: .4byte 0x0000D635
_081CE918: .4byte 0x000004B7
_081CE91C: .4byte 0x000001DF
_081CE920: .4byte 0x0000046F
_081CE924: .4byte 0x00000474
_081CE928: .4byte 0x000004B6
_081CE92C:
	movs r1, #0
_081CE92E:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _081CE954 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0xf0]
	str r4, [sp, #0xf4]
	cmp r0, #0
	beq _081CE958
	bl Script_GetValue
	adds r1, r0, #0
	b _081CE95A
	.align 2, 0
_081CE954: .4byte 0x00000251
_081CE958:
	movs r1, #0
_081CE95A:
	ldr r2, _081CE990 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _081CE994 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0xf0]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0xf8]
	cmp r0, #0
	beq _081CE998
	bl Script_GetValue
	b _081CE99C
	.align 2, 0
_081CE990: .4byte 0x00000252
_081CE994: .4byte 0x000004B4
_081CE998:
	ldr r4, [sp, #0xf0]
	ldrb r0, [r4]
_081CE99C:
	strb r0, [r6]
	ldr r5, [sp, #0xf0]
	ldrb r1, [r5]
	ldr r6, [sp, #0xf8]
	ldrb r2, [r6]
	add r0, sp, #0x1c
	bl FUN_08234f90
	add r0, sp, #0x1c
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, sp
	ldrh r0, [r1, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081CE9D4
	cmp r1, #0
	blt _081CE9D4
	ldr r0, _081CE9D8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081CE9D4
	ldr r0, _081CE9DC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081CE9E0
_081CE9D4:
	movs r1, #0
	b _081CE9EE
	.align 2, 0
_081CE9D8: .4byte 0x030046A8
_081CE9DC: .4byte 0x030046AC
_081CE9E0:
	ldr r0, _081CEA08 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081CE9EE:
	ldr r2, _081CEA0C @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081CEA10
	adds r0, #4
	b _081CEA1C
	.align 2, 0
_081CEA08: .4byte 0x030046A4
_081CEA0C: .4byte 0x00000256
_081CEA10:
	ldr r0, _081CEA30 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081CEA1C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081CEA34
	cmp r2, #2
	beq _081CEA38
	b _081CEA3C
	.align 2, 0
_081CEA30: .4byte 0x030046A4
_081CEA34:
	ldrb r0, [r4, #4]
	b _081CEA3A
_081CEA38:
	ldrb r0, [r4]
_081CEA3A:
	subs r1, r1, r0
_081CEA3C:
	ldr r3, _081CEA54 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _081CEA58 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _081CEA9C
	.align 2, 0
_081CEA54: .4byte 0x00000472
_081CEA58: .4byte 0x0000FFFF
_081CEA5C:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _081CEAC0 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _081CEAC4 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _081CEAC8 @ =0x000004B4
	adds r1, r7, r6
	adds r0, r1, r0
	mov r6, sl
	strb r6, [r0]
	ldrb r2, [r2]
	movs r0, #1
	eors r0, r2
	adds r1, r1, r0
	strb r6, [r1]
	movs r0, #0
	str r0, [sp, #0x2c]
	str r5, [sp, #0xf0]
	str r4, [sp, #0xf4]
	str r3, [sp, #0xf8]
_081CEA9C:
	movs r0, #0x4e
	movs r1, #0
	bl Script_GetKeywordValue
	mov sb, r0
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _081CEAE6
	bl VM_GetPC
	cmp r0, #0
	beq _081CEACC
	bl Script_GetValue
	adds r4, r0, #0
	b _081CEACE
	.align 2, 0
_081CEAC0: .4byte 0x00000251
_081CEAC4: .4byte 0x00000252
_081CEAC8: .4byte 0x000004B4
_081CEACC:
	movs r4, #0x30
_081CEACE:
	bl VM_GetPC
	cmp r0, #0
	beq _081CEAE0
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _081CEAE2
_081CEAE0:
	movs r5, #0x40
_081CEAE2:
	mov r8, r4
	b _081CEAEC
_081CEAE6:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_081CEAEC:
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _081CEB24
	bl VM_GetPC
	cmp r0, #0
	beq _081CEB06
	bl Script_GetValue
	adds r6, r0, #0
	b _081CEB08
_081CEB06:
	movs r6, #0
_081CEB08:
	bl VM_GetPC
	cmp r0, #0
	beq _081CEB18
	bl Script_GetValue
	adds r1, r0, #0
	b _081CEB1A
_081CEB18:
	movs r1, #0
_081CEB1A:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _081CEB2E
_081CEB24:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_081CEB2E:
	movs r0, #0x61
	bl prepare_08231510
	ldr r1, _081CEDA8 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0x10c]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xe8]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x7c]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x78]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xfc]
	lsls r4, r4, #0x10
	str r4, [sp, #0x98]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0xa0]
	lsls r6, r6, #0x10
	str r6, [sp, #0xa8]
	lsls r5, r5, #0x10
	str r5, [sp, #0x9c]
	ldr r4, _081CEDAC @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0x108]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x90]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x34]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xac]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xb0]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x38]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x3c]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x30]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x5c]
	ldr r1, _081CEDB0 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x50]
	ldr r2, _081CEDB4 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x54]
	ldr r3, _081CEDB8 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x58]
	ldr r4, _081CEDBC @ =0x000004A4
	adds r4, r7, r4
	str r4, [sp, #0x6c]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x74]
	movs r6, #0xb0
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x100]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x110]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x118]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x128]
	ldr r4, _081CEDC0 @ =0x000005A4
	adds r4, r7, r4
	str r4, [sp, #0x12c]
	movs r5, #0xb8
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x140]
	ldr r6, _081CEDC4 @ =0x000005C4
	adds r6, r7, r6
	str r6, [sp, #0x144]
	ldr r1, _081CEDC8 @ =0x000005CC
	adds r1, r7, r1
	str r1, [sp, #0x14c]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x150]
	ldr r3, _081CEDCC @ =0x000005D4
	adds r3, r7, r3
	str r3, [sp, #0x154]
	ldr r4, _081CEDD0 @ =0x000005DC
	adds r4, r7, r4
	str r4, [sp, #0x15c]
	movs r5, #0xb9
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x148]
	ldr r6, _081CEDD4 @ =0x00000584
	adds r6, r7, r6
	str r6, [sp, #0x104]
	ldr r1, _081CEDD8 @ =0x00000604
	adds r1, r7, r1
	str r1, [sp, #0x180]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x184]
	ldr r3, _081CEDDC @ =0x0000021D
	adds r3, r7, r3
	str r3, [sp, #0xb8]
	ldr r4, _081CEDE0 @ =0x0000060C
	adds r4, r7, r4
	str r4, [sp, #0x188]
	movs r5, #0xbe
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x170]
	ldr r6, _081CEDE4 @ =0x000005E4
	adds r6, r7, r6
	str r6, [sp, #0x164]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x174]
	ldr r2, _081CEDE8 @ =0x000005FC
	adds r2, r7, r2
	str r2, [sp, #0x178]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x17c]
	ldr r4, _081CEDEC @ =0x00000614
	adds r4, r7, r4
	str r4, [sp, #0x18c]
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x190]
	ldr r6, _081CEDF0 @ =0x000005BC
	adds r6, r7, r6
	str r6, [sp, #0x13c]
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x168]
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x160]
	ldr r3, _081CEDF4 @ =0x000005EC
	adds r3, r7, r3
	str r3, [sp, #0x16c]
	movs r4, #0xbb
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x158]
	movs r5, #0xb5
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x130]
	ldr r6, _081CEDF8 @ =0x00000624
	adds r6, r7, r6
	str r6, [sp, #0x194]
	ldr r1, _081CEDFC @ =0x0000058C
	adds r1, r7, r1
	str r1, [sp, #0x114]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x198]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x138]
	ldr r4, _081CEE00 @ =0x00000594
	adds r4, r7, r4
	str r4, [sp, #0x11c]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x120]
	ldr r6, _081CEE04 @ =0x0000059C
	adds r6, r7, r6
	str r6, [sp, #0x124]
	ldr r1, _081CEE08 @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0x134]
	ldr r2, _081CEE0C @ =0x00000543
	adds r2, r7, r2
	str r2, [sp, #0xb4]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x80]
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x84]
	ldr r5, _081CEE10 @ =0x00000496
	adds r5, r7, r5
	str r5, [sp, #0x64]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x40]
	ldr r1, _081CEE14 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0x44]
	ldr r2, _081CEE18 @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x48]
	ldr r3, _081CEE1C @ =0x00000553
	adds r3, r7, r3
	str r3, [sp, #0xbc]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xec]
	movs r5, #0x92
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x60]
	movs r6, #0xea
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x94]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	ldr r2, _081CEE20 @ =0x00000572
	adds r2, r7, r2
	str r2, [sp, #0xe4]
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x88]
	movs r4, #0xae
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xe0]
	ldr r5, _081CEE24 @ =0x0000055C
	adds r5, r7, r5
	str r5, [sp, #0xc0]
	movs r6, #0xac
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xc4]
	ldr r1, _081CEE28 @ =0x00000564
	adds r1, r7, r1
	str r1, [sp, #0xc8]
	ldr r2, _081CEE2C @ =0x00000565
	adds r2, r7, r2
	str r2, [sp, #0xcc]
	ldr r3, _081CEE30 @ =0x00000566
	adds r3, r7, r3
	str r3, [sp, #0xd0]
	ldr r4, _081CEE34 @ =0x00000567
	adds r4, r7, r4
	str r4, [sp, #0xd4]
	movs r5, #0xad
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xd8]
	ldr r6, _081CEE38 @ =0x0000056C
	adds r6, r7, r6
	str r6, [sp, #0xdc]
	cmp r0, #0
	bne _081CED78
	b _081CEE92
_081CED78:
	movs r0, #0
	mov sl, r0
	movs r1, #0x8d
	lsls r1, r1, #2
	adds r1, r1, r7
	mov sb, r1
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r2, r2, r7
	mov r8, r2
	movs r3, #0x8b
	lsls r3, r3, #2
	adds r5, r7, r3
	movs r6, #0x89
	lsls r6, r6, #2
	adds r4, r7, r6
_081CED98:
	bl VM_GetPC
	cmp r0, #0
	beq _081CEE3C
	bl Script_GetValue
	b _081CEE3E
	.align 2, 0
_081CEDA8: .4byte 0x0000025D
_081CEDAC: .4byte 0x0000025A
_081CEDB0: .4byte 0x0000047A
_081CEDB4: .4byte 0x0000047C
_081CEDB8: .4byte 0x0000047E
_081CEDBC: .4byte 0x000004A4
_081CEDC0: .4byte 0x000005A4
_081CEDC4: .4byte 0x000005C4
_081CEDC8: .4byte 0x000005CC
_081CEDCC: .4byte 0x000005D4
_081CEDD0: .4byte 0x000005DC
_081CEDD4: .4byte 0x00000584
_081CEDD8: .4byte 0x00000604
_081CEDDC: .4byte 0x0000021D
_081CEDE0: .4byte 0x0000060C
_081CEDE4: .4byte 0x000005E4
_081CEDE8: .4byte 0x000005FC
_081CEDEC: .4byte 0x00000614
_081CEDF0: .4byte 0x000005BC
_081CEDF4: .4byte 0x000005EC
_081CEDF8: .4byte 0x00000624
_081CEDFC: .4byte 0x0000058C
_081CEE00: .4byte 0x00000594
_081CEE04: .4byte 0x0000059C
_081CEE08: .4byte 0x000005B4
_081CEE0C: .4byte 0x00000543
_081CEE10: .4byte 0x00000496
_081CEE14: .4byte 0x00000469
_081CEE18: .4byte 0x0000046A
_081CEE1C: .4byte 0x00000553
_081CEE20: .4byte 0x00000572
_081CEE24: .4byte 0x0000055C
_081CEE28: .4byte 0x00000564
_081CEE2C: .4byte 0x00000565
_081CEE30: .4byte 0x00000566
_081CEE34: .4byte 0x00000567
_081CEE38: .4byte 0x0000056C
_081CEE3C:
	movs r0, #0x18
_081CEE3E:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _081CEE50
	bl Script_GetValue
	b _081CEE52
_081CEE50:
	movs r0, #0x18
_081CEE52:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _081CEE64
	bl Script_GetValue
	b _081CEE66
_081CEE64:
	movs r0, #0
_081CEE66:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _081CEE78
	bl Script_GetValue
	b _081CEE7A
_081CEE78:
	movs r0, #0
_081CEE7A:
	strh r0, [r6]
	movs r0, #2
	add sb, r0
	movs r1, #4
	add r8, r1
	adds r5, #2
	adds r4, #2
	movs r2, #1
	add sl, r2
	mov r3, sl
	cmp r3, #3
	ble _081CED98
_081CEE92:
	movs r0, #0x6c
	bl prepare_08231510
	cmp r0, #0
	beq _081CEEDE
	bl VM_GetPC
	cmp r0, #0
	beq _081CEEAC
	bl Script_GetValue
	adds r4, r0, #0
	b _081CEEB0
_081CEEAC:
	movs r4, #0x96
	lsls r4, r4, #1
_081CEEB0:
	bl VM_GetPC
	cmp r0, #0
	beq _081CEEC0
	bl Script_GetValue
	adds r6, r0, #0
	b _081CEEC4
_081CEEC0:
	movs r6, #0x96
	lsls r6, r6, #1
_081CEEC4:
	bl VM_GetPC
	cmp r0, #0
	beq _081CEED2
	bl Script_GetValue
	b _081CEED8
_081CEED2:
	movs r5, #0x96
	lsls r5, r5, #1
	adds r0, r5, #0
_081CEED8:
	ldr r1, [sp, #0xe8]
	strh r0, [r1]
	b _081CEEE6
_081CEEDE:
	movs r4, #0
	movs r6, #0
	ldr r2, [sp, #0xe8]
	strh r6, [r2]
_081CEEE6:
	movs r0, #0x62
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081CEEFE
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r3, [sp, #0x70]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_081CEEFE:
	movs r0, #0x46
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r5, [sp, #0x7c]
	strh r0, [r5]
	movs r0, #0x52
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r1, [sp, #0x78]
	strh r0, [r1]
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _081CEFCC
	bl VM_GetPC
	cmp r0, #0
	beq _081CEF2E
	bl Script_GetValue
	b _081CEF30
_081CEF2E:
	movs r0, #0
_081CEF30:
	ldr r2, [sp, #0xfc]
	strh r0, [r2]
	ldrh r0, [r2]
	cmp r0, #0
	blt _081CEF3E
	asrs r1, r0, #1
	b _081CEF44
_081CEF3E:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081CEF44:
	ldr r3, _081CEF58 @ =0x00000546
	adds r0, r7, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081CEF5C
	bl Script_GetValue
	b _081CEF5E
	.align 2, 0
_081CEF58: .4byte 0x00000546
_081CEF5C:
	movs r0, #0
_081CEF5E:
	movs r5, #0xc3
	lsls r5, r5, #1
	adds r1, r7, r5
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081CEF74
	bl Script_GetValue
	b _081CEF76
_081CEF74:
	movs r0, #0
_081CEF76:
	ldr r2, _081CEF8C @ =0x00000187
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081CEF90
	bl Script_GetValue
	adds r1, r0, #0
	b _081CEF92
	.align 2, 0
_081CEF8C: .4byte 0x00000187
_081CEF90:
	movs r1, #0
_081CEF92:
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r0, r7, r3
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081CEFA8
	bl Script_GetValue
	b _081CEFAA
_081CEFA8:
	movs r0, #0
_081CEFAA:
	movs r5, #0xc5
	lsls r5, r5, #1
	adds r1, r7, r5
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081CEFC2
	bl Script_GetValue
	adds r1, r0, #0
	b _081CEFC4
_081CEFC2:
	movs r1, #0
_081CEFC4:
	movs r2, #0xc6
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_081CEFCC:
	ldr r3, [sp, #0xfc]
	ldrh r1, [r3]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r4, [sp, #0x98]
	lsrs r2, r4, #0x10
	ldr r5, [sp, #0xa0]
	lsrs r3, r5, #0x10
	ldr r6, [sp, #0xa8]
	lsrs r0, r6, #0x10
	str r0, [sp]
	ldr r1, [sp, #0x9c]
	lsrs r0, r1, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl prepare_08231510
	cmp r0, #0
	beq _081CF02E
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r6, r7, r2
	bl VM_GetPC
	cmp r0, #0
	beq _081CF014
	bl Script_GetValue
	b _081CF016
_081CF014:
	movs r0, #0
_081CF016:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _081CF026
	bl Script_GetValue
	b _081CF028
_081CF026:
	movs r0, #0
_081CF028:
	ldr r3, _081CF090 @ =0x00000189
	adds r1, r7, r3
	strb r0, [r1]
_081CF02E:
	movs r0, #0x4b
	movs r1, #2
	bl Script_GetKeywordValue
	ldr r4, [sp, #0x108]
	strh r0, [r4]
	movs r0, #0x48
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081CF052
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r5, [sp, #0x70]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_081CF052:
	movs r0, #0x4c
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081CF06A
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r6, [sp, #0x70]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
_081CF06A:
	ldr r0, [sp, #0x90]
	lsrs r1, r0, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x28]
	add r2, sp, #0x1c
	movs r3, #0
	bl FUN_0823b400
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x4c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081CF094
	movs r0, #1
	b _081CF096
	.align 2, 0
_081CF090: .4byte 0x00000189
_081CF094:
	movs r0, #0
_081CF096:
	cmp r0, #0
	beq _081CF0A6
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _081CF0D0 @ =FUN_080f48ac
	ldr r1, [sp, #0x28]
	bl FUN_0807f558
_081CF0A6:
	ldr r3, [sp, #0x10c]
	ldrb r0, [r3]
	movs r1, #0
	cmp r0, #0
	bne _081CF0B2
	ldr r1, [r7, #0x44]
_081CF0B2:
	ldr r0, [sp, #0x28]
	bl FUN_0823b46c
	ldr r4, [sp, #0xa4]
	ldrb r0, [r4]
	cmp r0, #0x15
	bne _081CF0D4
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x34]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _081CF0E0
	.align 2, 0
_081CF0D0: .4byte FUN_080f48ac
_081CF0D4:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x34]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_081CF0E0:
	ldr r5, [sp, #0xa4]
	ldrb r1, [r5]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081CF12E
	adds r0, r1, #0
	cmp r0, #0xb
	beq _081CF12E
	cmp r0, #0x16
	beq _081CF12E
	cmp r0, #0x14
	beq _081CF12E
	cmp r0, #9
	beq _081CF12E
	cmp r0, #0x19
	beq _081CF12E
	cmp r0, #0x1a
	beq _081CF12E
	cmp r0, #0xd
	beq _081CF12E
	cmp r0, #0x1b
	beq _081CF12E
	cmp r0, #0x1f
	beq _081CF12E
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r6, [sp, #0xf0]
	ldrb r2, [r6]
	ldr r0, [sp, #0xf4]
	ldrb r3, [r0]
	ldr r4, [sp, #0xf8]
	ldrb r0, [r4]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl FUN_0823b490
_081CF12E:
	movs r1, #8
	ldr r5, [sp, #0x4c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081CF13E
	movs r0, #1
	b _081CF140
_081CF13E:
	movs r0, #0
_081CF140:
	cmp r0, #0
	beq _081CF14E
	ldr r6, [sp, #0xb0]
	ldr r0, [r6]
	ldr r1, [sp, #0xac]
	str r0, [r1]
	b _081CF160
_081CF14E:
	ldr r2, [sp, #0xb0]
	ldr r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, [sp, #0xac]
	str r0, [r3]
_081CF160:
	ldrh r0, [r7]
	ldr r4, [sp, #0x38]
	strh r0, [r4]
	ldr r5, [sp, #0x30]
	ldr r6, [sp, #0x3c]
	str r5, [r6]
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	beq _081CF18A
	adds r0, r7, #0
	adds r0, #0xa4
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	lsrs r0, r0, #0xc
	movs r1, #7
	ands r0, r1
	adds r0, #5
	ands r0, r1
	lsls r0, r0, #5
	ldr r1, [sp, #0x28]
	strb r0, [r1, #5]
_081CF18A:
	movs r0, #0x50
	bl prepare_08231510
	cmp r0, #0
	beq _081CF1D2
	bl VM_GetPC
	cmp r0, #0
	beq _081CF1A4
	bl Script_GetValue
	adds r1, r0, #0
	b _081CF1A6
_081CF1A4:
	movs r1, #0xc8
_081CF1A6:
	ldr r2, [sp, #0x24]
	ldr r3, _081CF1C0 @ =0x000006CC
	adds r0, r2, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081CF1C4
	bl Script_GetValue
	adds r1, r0, #0
	b _081CF1CA
	.align 2, 0
_081CF1C0: .4byte 0x000006CC
_081CF1C4:
	movs r4, #0xa0
	lsls r4, r4, #1
	adds r1, r4, #0
_081CF1CA:
	ldr r5, [sp, #0x24]
	ldr r6, _081CF1F0 @ =0x000006CE
	adds r0, r5, r6
	strh r1, [r0]
_081CF1D2:
	movs r0, #0x59
	bl prepare_08231510
	cmp r0, #0
	beq _081CF252
	ldr r0, [sp, #0x24]
	ldr r1, _081CF1F4 @ =0x000006B4
	adds r4, r0, r1
	bl VM_GetPC
	cmp r0, #0
	beq _081CF1F8
	bl Script_GetValue
	b _081CF1FA
	.align 2, 0
_081CF1F0: .4byte 0x000006CE
_081CF1F4: .4byte 0x000006B4
_081CF1F8:
	movs r0, #0
_081CF1FA:
	str r0, [r4]
	ldr r2, [sp, #0x24]
	ldr r3, _081CF21C @ =0x000006B4
	adds r1, r2, r3
	ldr r0, [r1]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	str r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081CF220
	bl Script_GetValue
	adds r1, r0, #0
	b _081CF226
	.align 2, 0
_081CF21C: .4byte 0x000006B4
_081CF220:
	movs r5, #0xa0
	lsls r5, r5, #2
	adds r1, r5, #0
_081CF226:
	ldr r6, [sp, #0x24]
	ldr r2, _081CF240 @ =0x000006C2
	adds r0, r6, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081CF244
	bl Script_GetValue
	adds r1, r0, #0
	b _081CF24A
	.align 2, 0
_081CF240: .4byte 0x000006C2
_081CF244:
	movs r3, #0xa0
	lsls r3, r3, #2
	adds r1, r3, #0
_081CF24A:
	ldr r4, [sp, #0x24]
	ldr r5, _081CF2A0 @ =0x000006C4
	adds r0, r4, r5
	strh r1, [r0]
_081CF252:
	ldr r6, [sp, #0x24]
	movs r0, #0xda
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, _081CF2A4 @ =0x0000FFFF
	strh r0, [r1]
	ldr r2, _081CF2A8 @ =0x000006D4
	adds r1, r6, r2
	movs r0, #0
	strh r0, [r1]
	ldr r4, _081CF2AC @ =0x000001F5
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r3, [sp, #0x5c]
	strh r0, [r3]
	ldr r6, [sp, #0x50]
	strh r4, [r6]
	ldr r0, [sp, #0x54]
	strh r5, [r0]
	ldrh r0, [r3]
	adds r0, r0, r4
	ldr r1, [sp, #0x58]
	strh r0, [r1]
	ldrh r1, [r6]
	ldrh r0, [r3]
	adds r1, r1, r0
	ldr r2, [sp, #0x10c]
	ldrb r0, [r2]
	cmp r0, #0
	bne _081CF2B0
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _081CF2BC
	.align 2, 0
_081CF2A0: .4byte 0x000006C4
_081CF2A4: .4byte 0x0000FFFF
_081CF2A8: .4byte 0x000006D4
_081CF2AC: .4byte 0x000001F5
_081CF2B0:
	ldr r2, [r7, #0x44]
	ldr r0, _081CF2F4 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_081CF2BC:
	ldr r3, [sp, #0x10c]
	ldrb r0, [r3]
	cmp r0, #1
	bne _081CF30C
	ldr r4, [sp, #0xa4]
	ldrb r0, [r4]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _081CF2F8
	movs r0, #5
	bl FUN_080ecf60
	adds r4, r0, #1
	movs r0, #6
	bl FUN_080ecf60
	adds r4, r4, r0
	movs r0, #7
	bl FUN_080ecf60
	adds r4, r4, r0
	movs r0, #8
	bl FUN_080ecf60
	adds r4, r4, r0
	b _081CF302
	.align 2, 0
_081CF2F4: .4byte 0x03003584
_081CF2F8:
	ldr r5, [sp, #0xa4]
	ldrb r0, [r5]
	bl FUN_080ecf60
	adds r4, r0, #1
_081CF302:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_081CF30C:
	adds r0, r7, #0
	bl FUN_081c6850
	ldr r6, [sp, #0x24]
	ldr r1, _081CF4CC @ =0x000006DC
	adds r0, r6, r1
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r6, r6, r2
	mov r8, r6
	ldr r3, _081CF4D0 @ =FUN_081ce654
	mov sb, r3
	ldr r4, _081CF4D4 @ =FUN_081c6604
	mov sl, r4
	ldr r5, _081CF4D8 @ =FUN_081c7ffc
	mov ip, r5
	ldr r5, _081CF4DC @ =FUN_081cd624
	ldr r3, _081CF4E0 @ =FUN_080f62b0
	ldr r6, _081CF4E4 @ =FUN_080f62ac
	str r6, [sp, #0x19c]
	movs r4, #0
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r6, [sp, #0x68]
	ldr r1, [r6]
	orrs r1, r2
	str r1, [r6]
	ldr r1, [sp, #0x6c]
	str r0, [r1]
	mov r2, r8
	ldr r6, [sp, #0x74]
	str r2, [r6]
	mov r1, sb
	ldr r2, [sp, #0x100]
	str r1, [r2]
	mov r6, sl
	ldr r1, [sp, #0x110]
	str r6, [r1]
	mov r2, ip
	ldr r6, [sp, #0x118]
	str r2, [r6]
	ldr r1, _081CF4E8 @ =FUN_081c7fb4
	ldr r2, [sp, #0x128]
	str r1, [r2]
	ldr r6, _081CF4EC @ =FUN_081c7fd8
	ldr r1, [sp, #0x12c]
	str r6, [r1]
	ldr r2, _081CF4F0 @ =FUN_081c869c
	ldr r6, [sp, #0x140]
	str r2, [r6]
	ldr r1, [sp, #0x144]
	str r3, [r1]
	ldr r2, [sp, #0x14c]
	str r5, [r2]
	ldr r3, _081CF4F4 @ =FUN_081ca3a8
	ldr r5, [sp, #0x150]
	str r3, [r5]
	ldr r1, _081CF4F8 @ =FUN_080f44f4
	ldr r6, [sp, #0x154]
	str r1, [r6]
	ldr r1, _081CF4FC @ =FUN_080f410c
	ldr r2, [sp, #0x15c]
	str r1, [r2]
	ldr r3, _081CF500 @ =FUN_081c88b4
	ldr r5, [sp, #0x148]
	str r3, [r5]
	ldr r6, _081CF504 @ =FUN_081c8698
	ldr r1, [sp, #0x104]
	str r6, [r1]
	ldr r2, [sp, #0x19c]
	ldr r3, [sp, #0x180]
	str r2, [r3]
	ldr r1, _081CF508 @ =FUN_080f0430
	ldr r5, [sp, #0x184]
	str r1, [r5]
	movs r1, #1
	ldr r6, [sp, #0xb8]
	strb r1, [r6]
	ldr r1, _081CF50C @ =0x085AD470
	ldr r2, [sp, #0x188]
	str r1, [r2]
	ldr r1, _081CF510 @ =FUN_080e73c8
	ldr r3, [sp, #0x170]
	str r1, [r3]
	ldr r5, [sp, #0x164]
	str r4, [r5]
	ldr r6, [sp, #0x174]
	str r4, [r6]
	ldr r1, [sp, #0x178]
	str r4, [r1]
	ldr r2, [sp, #0x17c]
	str r4, [r2]
	ldr r3, [sp, #0x18c]
	str r4, [r3]
	ldr r1, _081CF514 @ =FUN_080f0320
	ldr r5, [sp, #0x190]
	str r1, [r5]
	ldr r1, _081CF518 @ =FUN_080eff14
	ldr r6, [sp, #0x13c]
	str r1, [r6]
	ldr r1, _081CF51C @ =FUN_080e72b0
	ldr r2, [sp, #0x168]
	str r1, [r2]
	ldr r3, [sp, #0x160]
	str r4, [r3]
	ldr r1, _081CF520 @ =FUN_080f47c8
	ldr r5, [sp, #0x16c]
	str r1, [r5]
	ldr r1, _081CF524 @ =FUN_080f54e4
	ldr r6, [sp, #0x158]
	str r1, [r6]
	ldr r1, [sp, #0x130]
	str r4, [r1]
	ldr r1, _081CF528 @ =FUN_080f6e64
	ldr r2, [sp, #0x194]
	str r1, [r2]
	ldr r1, _081CF52C @ =FUN_080f64f0
	ldr r3, [sp, #0x114]
	str r1, [r3]
	ldr r1, _081CF530 @ =FUN_080f84d4
	ldr r5, [sp, #0x198]
	str r1, [r5]
	ldr r1, _081CF534 @ =FUN_080f624c
	ldr r6, [sp, #0x138]
	str r1, [r6]
	ldr r1, _081CF538 @ =FUN_080f56ec
	ldr r2, [sp, #0x11c]
	str r1, [r2]
	ldr r1, _081CF53C @ =FUN_080f5b34
	ldr r3, [sp, #0x120]
	str r1, [r3]
	ldr r1, _081CF540 @ =FUN_080f5fac
	ldr r5, [sp, #0x124]
	str r1, [r5]
	ldr r6, [sp, #0x134]
	str r4, [r6]
	movs r1, #0x28
	ldr r2, [sp, #0xb4]
	strb r1, [r2]
	ldr r1, [sp, #0x30]
	bl FUN_082362fc
	adds r0, r7, #0
	bl FUN_080e6204
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _081CF544 @ =FUN_081c64b4
	str r0, [r1]
	ldr r5, _081CF548 @ =0x000005FC
	adds r1, r7, r5
	ldr r0, _081CF54C @ =FUN_081c65f0
	str r0, [r1]
	ldr r6, _081CF550 @ =0x000005AC
	adds r1, r7, r6
	ldr r0, _081CF554 @ =FUN_081c5c94
	str r0, [r1]
	movs r0, #0xb6
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081CF558 @ =FUN_081c5dc0
	str r0, [r1]
	ldr r2, _081CF55C @ =0x0000058C
	adds r1, r7, r2
	ldr r0, _081CF560 @ =FUN_081cc550
	str r0, [r1]
	subs r3, #0x3c
	adds r1, r7, r3
	ldr r0, _081CF564 @ =FUN_081c9f70
	str r0, [r1]
	adds r5, #0x1c
	adds r1, r7, r5
	ldr r0, _081CF568 @ =FUN_081c7108
	str r0, [r1]
	adds r6, #0x7c
	adds r1, r7, r6
	ldr r0, _081CF56C @ =FUN_080fa384
	str r0, [r1]
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	subs r2, #0x49
	adds r1, r7, r2
	movs r0, #0x14
	strb r0, [r1]
	movs r1, #0xe0
	lsls r1, r1, #0xf
	ldr r3, [sp, #0x68]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r1, #8
	ldr r4, [sp, #0x70]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	adds r0, r7, #0
	bl FUN_080e5dd4
	movs r0, #0x49
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r5, [sp, #0x80]
	strh r0, [r5]
	movs r0, #0x47
	bl prepare_08231510
	cmp r0, #0
	beq _081CF57A
	movs r6, #0xce
	lsls r6, r6, #1
	adds r5, r7, r6
	movs r4, #4
_081CF4BC:
	bl VM_GetPC
	cmp r0, #0
	beq _081CF570
	bl Script_GetValue
	b _081CF572
	.align 2, 0
_081CF4CC: .4byte 0x000006DC
_081CF4D0: .4byte FUN_081ce654
_081CF4D4: .4byte FUN_081c6604
_081CF4D8: .4byte FUN_081c7ffc
_081CF4DC: .4byte FUN_081cd624
_081CF4E0: .4byte FUN_080f62b0
_081CF4E4: .4byte FUN_080f62ac
_081CF4E8: .4byte FUN_081c7fb4
_081CF4EC: .4byte FUN_081c7fd8
_081CF4F0: .4byte FUN_081c869c
_081CF4F4: .4byte FUN_081ca3a8
_081CF4F8: .4byte FUN_080f44f4
_081CF4FC: .4byte FUN_080f410c
_081CF500: .4byte FUN_081c88b4
_081CF504: .4byte FUN_081c8698
_081CF508: .4byte FUN_080f0430
_081CF50C: .4byte 0x085AD470
_081CF510: .4byte FUN_080e73c8
_081CF514: .4byte FUN_080f0320
_081CF518: .4byte FUN_080eff14
_081CF51C: .4byte FUN_080e72b0
_081CF520: .4byte FUN_080f47c8
_081CF524: .4byte FUN_080f54e4
_081CF528: .4byte FUN_080f6e64
_081CF52C: .4byte FUN_080f64f0
_081CF530: .4byte FUN_080f84d4
_081CF534: .4byte FUN_080f624c
_081CF538: .4byte FUN_080f56ec
_081CF53C: .4byte FUN_080f5b34
_081CF540: .4byte FUN_080f5fac
_081CF544: .4byte FUN_081c64b4
_081CF548: .4byte 0x000005FC
_081CF54C: .4byte FUN_081c65f0
_081CF550: .4byte 0x000005AC
_081CF554: .4byte FUN_081c5c94
_081CF558: .4byte FUN_081c5dc0
_081CF55C: .4byte 0x0000058C
_081CF560: .4byte FUN_081cc550
_081CF564: .4byte FUN_081c9f70
_081CF568: .4byte FUN_081c7108
_081CF56C: .4byte FUN_080fa384
_081CF570:
	movs r0, #0
_081CF572:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081CF4BC
_081CF57A:
	movs r0, #0x44
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r1, [sp, #0x84]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl Script_GetKeywordValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x64]
	strh r0, [r3]
	cmp r2, #0
	beq _081CF5B2
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x68]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _081CF5B2
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_081CF5B2:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x4c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081CF5C4
	movs r0, #1
	b _081CF5C6
_081CF5C4:
	movs r0, #0
_081CF5C6:
	cmp r0, #0
	beq _081CF5D8
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x70]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_081CF5D8:
	cmp r2, #1
	beq _081CF618
	movs r1, #0
	ldr r0, [sp, #0x40]
	strb r1, [r0]
	ldr r2, [sp, #0x44]
	strb r1, [r2]
	ldr r3, [sp, #0x48]
	strb r1, [r3]
	ldr r4, _081CF628 @ =0x00000484
	adds r0, r7, r4
	str r1, [r0]
	ldr r5, _081CF62C @ =0x0000046C
	adds r0, r7, r5
	movs r2, #1
	strb r2, [r0]
	ldr r6, [sp, #0x12c]
	ldr r3, [r6]
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, [sp, #0xbc]
	strb r1, [r6]
	ldr r0, [sp, #0xec]
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_081CF618:
	movs r1, #2
	ldr r3, [sp, #0x4c]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081CF630
	movs r0, #1
	b _081CF632
	.align 2, 0
_081CF628: .4byte 0x00000484
_081CF62C: .4byte 0x0000046C
_081CF630:
	movs r0, #0
_081CF632:
	cmp r0, #0
	beq _081CF64C
	ldr r0, _081CF648 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x60]
	strh r0, [r5]
	b _081CF656
	.align 2, 0
_081CF648: .4byte 0x030046A0
_081CF64C:
	ldr r0, [sp, #0x30]
	bl FUN_08241574
	ldr r6, [sp, #0x60]
	strh r0, [r6]
_081CF656:
	movs r1, #0x40
	ldr r2, [sp, #0x4c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081CF666
	movs r0, #1
	b _081CF668
_081CF666:
	movs r0, #0
_081CF668:
	cmp r0, #0
	beq _081CF678
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _081CF69C @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_081CF678:
	movs r0, #0x53
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	bne _081CF6AA
	ldr r0, _081CF6A0 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x60]
	ldrh r4, [r4]
	cmp r0, r4
	bne _081CF6A4
	movs r0, #1
	b _081CF6A6
	.align 2, 0
_081CF69C: .4byte 0xFFFFFEFF
_081CF6A0: .4byte 0x030046A0
_081CF6A4:
	movs r0, #0
_081CF6A6:
	cmp r0, #0
	bne _081CF6B2
_081CF6AA:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_081CF6B2:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r5, [sp, #0x10c]
	ldrb r0, [r5]
	cmp r0, #0
	bne _081CF79A
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081CF6F4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081CF6FC
_081CF6F4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081CF6FC:
	str r0, [r5]
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
	beq _081CF720
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081CF728
_081CF720:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081CF728:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _081CF760 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081CF7A4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081CF764
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081CF758
	ldrb r0, [r4, #5]
_081CF758:
	subs r0, #1
	strh r0, [r4, #8]
	b _081CF774
	.align 2, 0
_081CF760: .4byte 0x0000FFFF
_081CF764:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081CF774
	strh r1, [r4, #8]
_081CF774:
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
	bne _081CF7A4
	movs r0, #1
	strb r0, [r4, #7]
	b _081CF7A4
_081CF79A:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
_081CF7A4:
	movs r0, #0
	ldr r3, [sp, #0x94]
	str r0, [r3]
	ldr r0, _081CF7BC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081CF7C0
	movs r0, #1
	b _081CF7C2
	.align 2, 0
_081CF7BC: .4byte 0x030047A4
_081CF7C0:
	movs r0, #0
_081CF7C2:
	cmp r0, #0
	bne _081CF802
	ldr r4, [sp, #0xa4]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081CF7EA
	adds r0, r1, #0
	cmp r0, #7
	beq _081CF7EA
	cmp r0, #6
	beq _081CF7EA
	cmp r0, #0x15
	beq _081CF7EA
	cmp r0, #0x14
	beq _081CF7EA
	cmp r0, #0x17
	bne _081CF802
_081CF7EA:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl FUN_080223f4
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x4c]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_081CF802:
	ldr r6, [sp, #0x8c]
	ldr r3, [r6]
	ldr r1, [sp, #0x5c]
	ldrh r0, [r1]
	cmp r0, #1
	bls _081CF812
	cmp r0, #4
	bne _081CF824
_081CF812:
	ldr r4, _081CF820 @ =0x000006AC
	adds r2, r3, r4
	movs r0, #0x80
	lsls r0, r0, #0xb
	str r0, [r2]
	b _081CF83A
	.align 2, 0
_081CF820: .4byte 0x000006AC
_081CF824:
	ldr r0, _081CF8DC @ =0x000006AC
	adds r2, r3, r0
	movs r0, #0x80
	lsls r0, r0, #0xb
	str r0, [r2]
	movs r4, #0xd6
	lsls r4, r4, #3
	adds r1, r3, r4
	movs r0, #0xe1
	lsls r0, r0, #0xa
	str r0, [r1]
_081CF83A:
	movs r5, #0xd7
	lsls r5, r5, #3
	adds r1, r3, r5
	ldr r0, _081CF8E0 @ =0x0000FFFF
	str r0, [r1]
	ldr r6, _081CF8E4 @ =0x000006BC
	adds r1, r3, r6
	ldr r0, [r2]
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_080f3680
	adds r0, r7, #0
	bl FUN_081cc53c
	adds r0, r7, #0
	bl FUN_081cb138
	adds r0, r7, #0
	bl FUN_081cb390
	ldr r1, [sp, #0x4c]
	ldrh r0, [r1]
	ldr r2, [sp, #0xe4]
	strh r0, [r2]
	ldr r3, [sp, #0x88]
	ldrh r0, [r3]
	ldr r4, [sp, #0xe0]
	strh r0, [r4]
	ldr r5, [sp, #0x68]
	ldr r0, [r5]
	ldr r6, [sp, #0xc0]
	str r0, [r6]
	ldr r1, [sp, #0x70]
	ldr r0, [r1]
	ldr r2, [sp, #0xc4]
	str r0, [r2]
	ldrb r0, [r7, #5]
	ldr r3, [sp, #0xc8]
	strb r0, [r3]
	ldr r4, [sp, #0x40]
	ldrb r0, [r4]
	ldr r5, [sp, #0xcc]
	strb r0, [r5]
	ldr r6, [sp, #0x44]
	ldrb r0, [r6]
	ldr r1, [sp, #0xd0]
	strb r0, [r1]
	ldr r2, [sp, #0x48]
	ldrb r0, [r2]
	ldr r3, [sp, #0xd4]
	strb r0, [r3]
	ldr r4, [sp, #0xec]
	ldr r0, [r4]
	ldr r5, [sp, #0xd8]
	str r0, [r5]
	ldr r6, [sp, #0xbc]
	ldrb r0, [r6]
	ldr r1, [sp, #0xdc]
	strb r0, [r1]
	ldr r2, _081CF8E8 @ =0x0000057C
	adds r1, r7, r2
	ldr r0, _081CF8EC @ =FUN_080f09e0
	str r0, [r1]
	ldr r3, _081CF8F0 @ =0x0000061C
	adds r1, r7, r3
	ldr r0, _081CF8F4 @ =FUN_081ce6a0
	str r0, [r1]
	movs r4, #0xc4
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _081CF8F8 @ =FUN_081ce6ac
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CF8FC
	movs r0, #0
	b _081CF900
	.align 2, 0
_081CF8DC: .4byte 0x000006AC
_081CF8E0: .4byte 0x0000FFFF
_081CF8E4: .4byte 0x000006BC
_081CF8E8: .4byte 0x0000057C
_081CF8EC: .4byte FUN_080f09e0
_081CF8F0: .4byte 0x0000061C
_081CF8F4: .4byte FUN_081ce6a0
_081CF8F8: .4byte FUN_081ce6ac
_081CF8FC:
	movs r0, #1
	rsbs r0, r0, #0
_081CF900:
	add sp, #0x1a4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

@ 通信対戦専用のエネミー
	thumb_func_start EnemyDogLink_Create
EnemyDogLink_Create: @ 0x081CF910
	push {r4, r5, lr}
	movs r5, #0xe2
	lsls r5, r5, #3
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _081CF93E
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl FUN_081ce78c
	cmp r0, #0
	bge _081CF93E
	adds r0, r4, #0
	bl FUN_081ce6ac
	adds r0, r4, #0
	bl Free
_081CF93E:
	pop {r4, r5}
	pop {r0}
	bx r0
