	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0800298c
FUN_0800298c: @ 0x0800298C
	push {r4, r5, lr}
	adds r3, r0, #0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	adds r4, r3, #0
	adds r4, #0x90
	movs r1, #0
	ldr r2, [r3, #0x20]
	b _080029A2
_0800299E:
	adds r4, #8
	adds r1, #1
_080029A2:
	cmp r1, r2
	bge _080029AC
	ldrh r0, [r4]
	cmp r0, #0
	bne _0800299E
_080029AC:
	ldr r0, [r3, #0x20]
	cmp r1, r0
	beq _080029C4
	adds r0, r5, #0
	bl FUN_0823b2d0
	str r0, [r4, #4]
	cmp r0, #0
	beq _080029C4
	movs r0, #1
	strh r0, [r4]
	strh r5, [r4, #2]
_080029C4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080029cc
FUN_080029cc: @ 0x080029CC
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	adds r2, r4, #0
	adds r2, #0x90
	movs r3, #0
	ldr r0, [r4, #0x20]
	cmp r3, r0
	bge _080029FA
	movs r1, #0
_080029E2:
	ldrh r0, [r2, #2]
	cmp r0, r5
	bne _080029F0
	strh r1, [r2]
	str r1, [r2, #4]
	strh r1, [r2, #2]
	b _080029FA
_080029F0:
	adds r2, #8
	adds r3, #1
	ldr r0, [r4, #0x20]
	cmp r3, r0
	blt _080029E2
_080029FA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08002a00
FUN_08002a00: @ 0x08002A00
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _08002A38 @ =0x00007BE3
	bl FUN_08230e70
	adds r2, r0, #0
	cmp r2, #0
	beq _08002A3C
	ldr r1, [r2, #0x28]
	cmp r1, #0xf
	bhi _08002A3C
	lsls r1, r1, #2
	adds r0, r2, #0
	adds r0, #0x2c
	adds r0, r0, r1
	strh r4, [r0]
	ldr r1, [r2, #0x28]
	lsls r1, r1, #2
	adds r0, r2, #0
	adds r0, #0x2e
	adds r0, r0, r1
	strh r5, [r0]
	ldr r0, [r2, #0x28]
	adds r0, #1
	str r0, [r2, #0x28]
	movs r0, #0
	b _08002A40
	.align 2, 0
_08002A38: .4byte 0x00007BE3
_08002A3C:
	movs r0, #1
	rsbs r0, r0, #0
_08002A40:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08002a48
FUN_08002a48: @ 0x08002A48
	push {lr}
	ldrh r1, [r0]
	movs r0, #0
	bl FUN_08002a00
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08002a58
FUN_08002a58: @ 0x08002A58
	push {lr}
	ldrh r1, [r0]
	movs r0, #1
	bl FUN_08002a00
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityE28B_Update
EntityE28B_Update: @ 0x08002A68
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x88
	str r0, [sp, #0x44]
	ldr r0, [r0, #0x1c]
	cmp r0, #0
	bne _08002AAE
	movs r0, #1
	ldr r1, [sp, #0x44]
	str r0, [r1, #0x1c]
	movs r5, #0
	ldr r0, [r1, #0x24]
	adds r6, r1, #0
	adds r6, #0x88
	cmp r5, r0
	bge _08002AAE
_08002A8E:
	ldr r1, [r6]
	movs r0, #0x2c
	muls r0, r5, r0
	adds r1, r0, r1
	ldrb r0, [r1, #4]
	cmp r0, #0
	bne _08002AA4
	adds r0, r1, #0
	movs r1, #0
	bl FUN_0822a340
_08002AA4:
	adds r5, #1
	ldr r2, [sp, #0x44]
	ldr r0, [r2, #0x24]
	cmp r5, r0
	blt _08002A8E
_08002AAE:
	movs r5, #0
	ldr r3, [sp, #0x44]
	ldr r0, [r3, #0x28]
	adds r6, r3, #0
	adds r6, #0x88
	adds r7, r3, #0
	adds r7, #0x90
	cmp r5, r0
	bhs _08002AF6
	adds r4, r3, #0
	adds r4, #0x2e
_08002AC4:
	lsls r1, r5, #2
	ldr r0, [sp, #0x44]
	adds r0, #0x2c
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08002AD8
	cmp r0, #1
	beq _08002AE2
	b _08002AEA
_08002AD8:
	ldrh r1, [r4]
	ldr r0, [sp, #0x44]
	bl FUN_0800298c
	b _08002AEA
_08002AE2:
	ldrh r1, [r4]
	ldr r0, [sp, #0x44]
	bl FUN_080029cc
_08002AEA:
	adds r4, #4
	adds r5, #1
	ldr r1, [sp, #0x44]
	ldr r0, [r1, #0x28]
	cmp r5, r0
	blo _08002AC4
_08002AF6:
	movs r0, #0
	ldr r2, [sp, #0x44]
	str r0, [r2, #0x28]
	movs r3, #0
	str r3, [sp, #0x48]
	ldr r6, [r6]
	mov r8, r6
	mov sb, r7
	movs r7, #0
	ldr r0, [r2, #0x20]
	cmp r3, r0
	blt _08002B10
	b _08002E24
_08002B10:
	mov r0, sp
	adds r0, #0x20
	str r0, [sp, #0x58]
	mov r1, sp
	adds r1, #0x2c
	str r1, [sp, #0x5c]
_08002B1C:
	mov r2, sb
	ldr r4, [r2, #4]
	ldrh r0, [r2]
	adds r3, r7, #1
	str r3, [sp, #0x60]
	adds r2, #8
	str r2, [sp, #0x64]
	cmp r0, #0
	bne _08002B30
	b _08002E14
_08002B30:
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _08002B42
	ldr r0, [r0, #8]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08002B42
	b _08002E14
_08002B42:
	ldr r1, [r4, #0x28]
	cmp r1, #0
	beq _08002B5E
	ldr r1, [r1]
	movs r0, #1
	ands r1, r0
	adds r0, r7, #1
	str r0, [sp, #0x60]
	mov r2, sb
	adds r2, #8
	str r2, [sp, #0x64]
	cmp r1, #0
	beq _08002B5E
	b _08002E14
_08002B5E:
	movs r1, #1
	ldrh r0, [r4, #2]
	ands r0, r1
	adds r3, r7, #1
	str r3, [sp, #0x60]
	mov r1, sb
	adds r1, #8
	str r1, [sp, #0x64]
	cmp r0, #0
	beq _08002B74
	b _08002E14
_08002B74:
	movs r3, #0xa
	ldrsh r2, [r4, r3]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r2, r0
	str r2, [sp, #0x50]
	ldrh r0, [r4, #8]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r4, #0xc]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldr r0, [sp, #0x50]
	asrs r0, r0, #8
	str r0, [sp, #0x54]
	str r0, [sp]
	movs r5, #0xff
	str r5, [sp, #0x10]
	ldrh r1, [r4, #8]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0x3f
	bgt _08002BE0
	ldrh r1, [r4, #0xc]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0x3f
	bgt _08002BC4
	adds r0, r3, #1
	str r0, [sp, #0x20]
	str r2, [sp, #0x2c]
	ldr r1, [sp, #0x58]
	str r0, [r1, #4]
	adds r0, r2, #1
	ldr r2, [sp, #0x5c]
	str r0, [r2, #4]
	str r3, [r1, #8]
	str r0, [r2, #8]
	movs r3, #0
	b _08002C28
_08002BC4:
	subs r0, r3, #1
	str r0, [sp, #0x20]
	adds r1, r2, #1
	str r1, [sp, #0x2c]
	ldr r2, [sp, #0x58]
	str r3, [r2, #4]
	ldr r0, [sp, #0x5c]
	str r1, [r0, #4]
	adds r0, r3, #1
	str r0, [r2, #8]
	ldr r2, [sp, #0x5c]
	str r1, [r2, #8]
	movs r3, #1
	b _08002C28
_08002BE0:
	ldrh r1, [r4, #0xc]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0x3f
	bgt _08002C12
	adds r0, r3, #1
	str r0, [sp, #0x20]
	subs r1, r2, #1
	str r1, [sp, #0x2c]
	ldr r3, [sp, #0x58]
	str r0, [r3, #4]
	ldr r1, [sp, #0x5c]
	str r2, [r1, #4]
	str r0, [r3, #8]
	adds r0, r2, #1
	str r0, [r1, #8]
	movs r2, #2
	str r2, [sp, #0x4c]
	mov r3, sp
	adds r3, #0x20
	str r3, [sp, #0x68]
	mov r0, sp
	adds r0, #0x2c
	str r0, [sp, #0x6c]
	b _08002C36
_08002C12:
	adds r0, r3, #1
	str r0, [sp, #0x20]
	str r2, [sp, #0x2c]
	ldr r1, [sp, #0x58]
	str r0, [r1, #4]
	adds r0, r2, #1
	ldr r2, [sp, #0x5c]
	str r0, [r2, #4]
	str r3, [r1, #8]
	str r0, [r2, #8]
	movs r3, #3
_08002C28:
	str r3, [sp, #0x4c]
	mov r0, sp
	adds r0, #0x20
	str r0, [sp, #0x68]
	mov r1, sp
	adds r1, #0x2c
	str r1, [sp, #0x6c]
_08002C36:
	movs r5, #0
	mov r2, sp
	adds r2, #0x38
	str r2, [sp, #0x70]
	add r6, sp, #0x10
	adds r3, r7, #1
	str r3, [sp, #0x60]
	mov r0, sb
	adds r0, #8
	str r0, [sp, #0x64]
	movs r1, #1
	str r1, [sp, #0x74]
	add r2, sp, #4
	mov sl, r2
	movs r3, #4
	str r3, [sp, #0x78]
	mov r0, sp
	adds r0, #0x14
	str r0, [sp, #0x7c]
	ldr r1, [sp, #0x70]
	str r1, [sp, #0x80]
	movs r2, #0
	str r2, [sp, #0x84]
_08002C64:
	ldr r3, [sp, #0x6c]
	ldr r1, [sp, #0x84]
	adds r0, r3, r1
	ldr r1, [r0]
	ldr r2, _08002C98 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r3, [sp, #0x68]
	ldr r2, [sp, #0x84]
	adds r0, r3, r2
	ldr r0, [r0]
	adds r4, r1, r0
	ldr r3, [sp, #0x80]
	str r4, [r3]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08002C9C
	adds r3, r0, #4
	b _08002CA8
	.align 2, 0
_08002C98: .4byte 0x030046A4
_08002C9C:
	ldr r1, _08002CC8 @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r3, r0, r1
_08002CA8:
	cmp r3, #0
	beq _08002CBA
	ldrh r1, [r3, #2]
	movs r2, #0x10
	mov sb, r2
	mov r0, sb
	ands r0, r1
	cmp r0, #0
	beq _08002CCC
_08002CBA:
	movs r0, #0
	mov r3, sl
	str r0, [r3]
	movs r0, #0xff
	ldr r1, [sp, #0x7c]
	b _08002D3A
	.align 2, 0
_08002CC8: .4byte 0x030046A4
_08002CCC:
	ldrb r1, [r3]
	movs r2, #0xf
	mov ip, r2
	mov r0, ip
	ands r0, r1
	mov r1, sl
	str r0, [r1]
	ldr r4, [sp]
	subs r0, r0, r4
	ldr r7, [sp, #0x74]
	cmp r0, #0
	bge _08002CE6
	rsbs r0, r0, #0
_08002CE6:
	cmp r0, #1
	ble _08002D34
	ldr r0, [sp, #0x80]
	ldr r2, [r0]
	ldr r1, _08002D18 @ =0x030046A4
	ldr r0, [r1]
	ldr r1, [r0, #4]
	cmp r1, #0
	beq _08002D0C
	lsls r0, r2, #2
	adds r0, #0xc
	adds r2, r1, r0
	cmp r2, #0
	beq _08002D0C
	ldrh r1, [r2, #2]
	mov r0, sb
	ands r0, r1
	cmp r0, #0
	beq _08002D1C
_08002D0C:
	lsls r0, r7, #2
	adds r0, r6, r0
	movs r1, #0xff
	str r1, [r0]
	b _08002D3C
	.align 2, 0
_08002D18: .4byte 0x030046A4
_08002D1C:
	ldrb r1, [r2]
	mov r0, ip
	ands r0, r1
	cmp r0, r4
	bgt _08002D2C
	ldr r2, [sp, #0x78]
	adds r1, r6, r2
	b _08002D38
_08002D2C:
	ldr r3, [sp, #0x78]
	adds r1, r6, r3
	ldrb r0, [r2, #1]
	b _08002D3A
_08002D34:
	ldr r0, [sp, #0x78]
	adds r1, r6, r0
_08002D38:
	ldrb r0, [r3, #1]
_08002D3A:
	str r0, [r1]
_08002D3C:
	ldr r1, [sp, #0x74]
	adds r1, #1
	str r1, [sp, #0x74]
	movs r2, #4
	add sl, r2
	ldr r3, [sp, #0x78]
	adds r3, #4
	str r3, [sp, #0x78]
	ldr r0, [sp, #0x7c]
	adds r0, #4
	str r0, [sp, #0x7c]
	ldr r1, [sp, #0x80]
	adds r1, #4
	str r1, [sp, #0x80]
	ldr r2, [sp, #0x84]
	adds r2, #4
	str r2, [sp, #0x84]
	adds r5, #1
	cmp r5, #2
	bgt _08002D66
	b _08002C64
_08002D66:
	movs r5, #0
_08002D68:
	adds r0, r5, #1
	lsls r2, r0, #2
	mov r3, sp
	adds r1, r3, r2
	ldr r3, [sp]
	ldr r1, [r1]
	adds r7, r0, #0
	cmp r3, r1
	bge _08002E0E
	adds r0, r6, r2
	ldr r0, [r0]
	cmp r0, #0xff
	beq _08002E0E
	ldr r0, [sp, #0x4c]
	cmp r0, #1
	bne _08002D8E
	ldr r0, [sp, #8]
	cmp r3, r0
	bge _08002E0E
_08002D8E:
	ldr r1, [sp, #0x4c]
	cmp r1, #2
	bne _08002D9A
	ldr r0, [sp, #8]
	cmp r3, r0
	bge _08002E0E
_08002D9A:
	lsls r2, r5, #2
	ldr r3, [sp, #0x70]
	adds r0, r3, r2
	ldr r3, [sp, #0x54]
	lsls r1, r3, #0x10
	ldr r5, [r0]
	orrs r5, r1
	ldr r0, [sp, #0x44]
	adds r0, #0x8c
	ldr r4, [r0]
	movs r3, #0
	ldr r0, [sp, #0x48]
	cmp r3, r0
	bge _08002DC8
	b _08002DC2
_08002DB8:
	adds r3, #1
	adds r4, #4
	ldr r1, [sp, #0x48]
	cmp r3, r1
	bge _08002DC8
_08002DC2:
	ldr r0, [r4]
	cmp r0, r5
	bne _08002DB8
_08002DC8:
	ldr r0, [sp, #0x48]
	cmp r3, r0
	bne _08002E0E
	lsls r0, r7, #2
	adds r0, r6, r0
	ldr r0, [r0]
	mov r1, r8
	strh r0, [r1, #0x10]
	ldr r3, [sp, #0x68]
	adds r0, r3, r2
	ldr r0, [r0]
	lsls r0, r0, #8
	adds r0, #0x80
	strh r0, [r1, #0x1c]
	add r0, sp, #0x50
	ldrh r0, [r0]
	strh r0, [r1, #0x1e]
	ldr r1, [sp, #0x6c]
	adds r0, r1, r2
	ldr r0, [r0]
	lsls r0, r0, #8
	adds r0, #0x80
	mov r2, r8
	strh r0, [r2, #0x20]
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	str r5, [r4]
	ldr r3, [sp, #0x48]
	adds r3, #1
	str r3, [sp, #0x48]
	movs r0, #0x2c
	add r8, r0
_08002E0E:
	adds r5, r7, #0
	cmp r5, #2
	ble _08002D68
_08002E14:
	ldr r7, [sp, #0x60]
	ldr r1, [sp, #0x64]
	mov sb, r1
	ldr r2, [sp, #0x44]
	ldr r0, [r2, #0x20]
	cmp r7, r0
	bge _08002E24
	b _08002B1C
_08002E24:
	ldr r3, [sp, #0x44]
	ldr r0, [r3, #0x24]
	ldr r1, [sp, #0x48]
	cmp r1, r0
	bge _08002E4C
	movs r1, #1
_08002E30:
	mov r2, r8
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r3, #0x2c
	add r8, r3
	ldr r0, [sp, #0x48]
	adds r0, #1
	str r0, [sp, #0x48]
	ldr r2, [sp, #0x44]
	ldr r0, [r2, #0x24]
	ldr r3, [sp, #0x48]
	cmp r3, r0
	blt _08002E30
_08002E4C:
	movs r0, #0
	add sp, #0x88
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityE28B_Destroy
EntityE28B_Destroy: @ 0x08002E60
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
	b _08002E82
_08002E68:
	adds r0, r5, #0
	adds r0, #0x88
	ldr r1, [r0]
	movs r0, #0x2c
	muls r0, r4, r0
	adds r1, r0, r1
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _08002E80
	adds r0, r1, #0
	bl FUN_0822a4e0
_08002E80:
	adds r4, #1
_08002E82:
	ldr r0, [r5, #0x24]
	cmp r4, r0
	blt _08002E68
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start EntityE28B_Init
EntityE28B_Init: @ 0x08002E90
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r0, #0
	strh r1, [r6, #0x18]
	strh r2, [r6, #0x1a]
	str r0, [r6, #0x1c]
	str r0, [r6, #0x28]
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _08002EB8
	bl Script_GetValue
	adds r1, r0, #0
	adds r4, r6, #0
	adds r4, #0x6c
	b _08002EC8
_08002EB8:
	adds r4, r6, #0
	adds r4, #0x6c
	ldr r0, _08002EDC @ =0x08251B2C
	bl FUN_08230860
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
_08002EC8:
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r7, r4, #0
	cmp r0, #0
	bne _08002EE0
	movs r0, #1
	rsbs r0, r0, #0
	b _08002F32
	.align 2, 0
_08002EDC: .4byte 0x08251B2C
_08002EE0:
	movs r5, #0
	ldr r0, [r6, #0x24]
	cmp r5, r0
	bge _08002F14
	movs r0, #0x88
	adds r0, r0, r6
	mov r8, r0
_08002EEE:
	movs r0, #0x2c
	muls r0, r5, r0
	mov r1, r8
	ldr r4, [r1]
	adds r4, r4, r0
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #1
	bl FUN_0822a4b0
	ldr r0, [r4, #0x18]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r4, #0x18]
	adds r5, #1
	ldr r0, [r6, #0x24]
	cmp r5, r0
	blt _08002EEE
_08002F14:
	movs r0, #2
	movs r1, #0xc
	movs r2, #0x2c
	bl FUN_0822ceb4
	movs r0, #0
	movs r1, #0x10
	bl FUN_0822cec8
	ldr r0, _08002F3C @ =0x00007BE3
	adds r1, r6, #0
	movs r2, #0
	bl FUN_08230e30
	movs r0, #0
_08002F32:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08002F3C: .4byte 0x00007BE3

	thumb_func_start EntityE28B_Create
EntityE28B_Create: @ 0x08002F40
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _08002F68
	bl Script_GetValue
	adds r5, r0, #0
	b _08002F6A
_08002F68:
	movs r5, #8
_08002F6A:
	lsls r0, r5, #5
	adds r0, r0, r5
	lsls r0, r0, #2
	mov r8, r0
	lsls r0, r5, #3
	adds r6, r0, #0
	adds r6, #0x90
	mov r0, r8
	adds r1, r0, r6
	lsls r0, r5, #1
	adds r7, r0, r5
	lsls r0, r7, #2
	adds r1, r1, r0
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08002FCC
	ldr r1, _08002FC4 @ =EntityE28B_Update
	ldr r2, _08002FC8 @ =EntityE28B_Destroy
	bl SetEntityRoutine
	adds r1, r4, #0
	adds r1, #0x88
	adds r0, r4, r6
	str r0, [r1]
	adds r1, #4
	add r0, r8
	str r0, [r1]
	str r5, [r4, #0x20]
	str r7, [r4, #0x24]
	adds r0, r4, #0
	mov r1, sl
	mov r2, sb
	bl EntityE28B_Init
	cmp r0, #0
	bge _08002FCC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08002FCE
	.align 2, 0
_08002FC4: .4byte EntityE28B_Update
_08002FC8: .4byte EntityE28B_Destroy
_08002FCC:
	adds r0, r4, #0
_08002FCE:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08002fdc
FUN_08002fdc: @ 0x08002FDC
	push {r4, lr}
	movs r0, #0x6d
	movs r1, #0
	bl Script_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r0, #0
	cmp r1, #0
	beq _08002FFE
	adds r0, r4, #0
	bl FUN_08002a00
	b _08003002
_08002FFE:
	movs r0, #1
	rsbs r0, r0, #0
_08003002:
	pop {r4}
	pop {r1}
	bx r1
