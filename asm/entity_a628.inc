	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a0774
FUN_080a0774: @ 0x080A0774
	push {lr}
	ldr r3, _080A0790 @ =0x03002C3C
	ldr r1, [r3]
	cmp r1, #0
	beq _080A078A
	adds r1, #0x36
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r3]
	strh r2, [r0, #0x34]
_080A078A:
	pop {r0}
	bx r0
	.align 2, 0
_080A0790: .4byte 0x03002C3C

	thumb_func_start FUN_080a0794
FUN_080a0794: @ 0x080A0794
	push {lr}
	ldr r2, _080A07B0 @ =0x03002C3C
	ldr r1, [r2]
	cmp r1, #0
	beq _080A07AA
	adds r1, #0x36
	movs r0, #0
	strb r0, [r1]
	ldr r1, [r2]
	movs r0, #8
	strh r0, [r1, #0x34]
_080A07AA:
	pop {r0}
	bx r0
	.align 2, 0
_080A07B0: .4byte 0x03002C3C

	thumb_func_start FUN_080a07b4
FUN_080a07b4: @ 0x080A07B4
	push {lr}
	bl FUN_080a0774
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a07c0
FUN_080a07c0: @ 0x080A07C0
	push {lr}
	bl FUN_080a0794
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a07cc
FUN_080a07cc: @ 0x080A07CC
	push {r4, lr}
	ldr r0, _080A07EC @ =0x03002C3C
	ldr r4, [r0]
	cmp r4, #0
	beq _080A07E6
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	bne _080A07E6
	adds r0, r4, #0
	bl FUN_080a0844
	movs r0, #1
	strb r0, [r4, #0x1f]
_080A07E6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A07EC: .4byte 0x03002C3C

	thumb_func_start FUN_080a07f0
FUN_080a07f0: @ 0x080A07F0
	push {lr}
	ldr r0, _080A0804 @ =0x03002C3C
	ldr r1, [r0]
	cmp r1, #0
	beq _080A07FE
	movs r0, #0
	strb r0, [r1, #0x1f]
_080A07FE:
	pop {r0}
	bx r0
	.align 2, 0
_080A0804: .4byte 0x03002C3C

	thumb_func_start FUN_080a0808
FUN_080a0808: @ 0x080A0808
	push {lr}
	ldr r0, _080A0828 @ =0x03002B80
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #1
	bne _080A0816
	movs r1, #1
_080A0816:
	cmp r1, #0
	bne _080A0830
	ldr r0, _080A082C @ =0x03002C3C
	ldr r0, [r0]
	cmp r0, #0
	beq _080A0830
	ldrb r0, [r0, #0x1f]
	b _080A0832
	.align 2, 0
_080A0828: .4byte 0x03002B80
_080A082C: .4byte 0x03002C3C
_080A0830:
	movs r0, #0
_080A0832:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a0838
FUN_080a0838: @ 0x080A0838
	push {lr}
	bl FUN_080a0808
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a0844
FUN_080a0844: @ 0x080A0844
	ldr r1, _080A085C @ =0x030046A0
	ldr r1, [r1]
	ldr r2, _080A0860 @ =0x00000932
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #0
	strh r1, [r0, #0x30]
	movs r1, #0x96
	lsls r1, r1, #1
	strh r1, [r0, #0x32]
	strh r2, [r0, #0x34]
	bx lr
	.align 2, 0
_080A085C: .4byte 0x030046A0
_080A0860: .4byte 0x00000932

	thumb_func_start FUN_080a0864
FUN_080a0864: @ 0x080A0864
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080A0884 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A08C0
	ldr r0, _080A0888 @ =0x03002C68
	ldr r1, [r0]
	cmp r1, #0
	bne _080A088C
	movs r1, #1
	rsbs r1, r1, #0
	b _080A0890
	.align 2, 0
_080A0884: .4byte 0x030047A4
_080A0888: .4byte 0x03002C68
_080A088C:
	movs r2, #0x18
	ldrsh r1, [r1, r2]
_080A0890:
	ldr r0, [r0]
	cmp r0, #0
	bne _080A089A
	movs r0, #0
	b _080A08A0
_080A089A:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_080A08A0:
	cmp r0, #0
	beq _080A08A8
	movs r0, #0
	b _080A08B6
_080A08A8:
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	bne _080A090E
	adds r0, r4, #0
	bl FUN_080a0844
	movs r0, #1
_080A08B6:
	strb r0, [r4, #0x1f]
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	bne _080A090E
	b _080A0920
_080A08C0:
	ldr r0, _080A08E4 @ =0x03002B80
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #1
	bne _080A08CC
	movs r2, #1
_080A08CC:
	cmp r2, #0
	beq _080A08E8
	adds r0, r4, #0
	adds r0, #0x37
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _080A0902
	movs r0, #1
	strb r0, [r5]
	b _080A0902
	.align 2, 0
_080A08E4: .4byte 0x03002B80
_080A08E8:
	adds r0, r4, #0
	adds r0, #0x37
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	beq _080A0902
	strb r2, [r5]
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	beq _080A0920
	adds r0, r4, #0
	bl FUN_080a0844
_080A0902:
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	beq _080A0920
	ldrb r0, [r5]
	cmp r0, #0
	bne _080A0920
_080A090E:
	movs r0, #0x80
	lsls r0, r0, #2
	ldr r2, _080A091C @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _080A092A
	.align 2, 0
_080A091C: .4byte 0x03003E78
_080A0920:
	ldr r0, _080A0930 @ =0x03003E78
	ldr r1, _080A0934 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_080A092A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A0930: .4byte 0x03003E78
_080A0934: .4byte 0xFFFFFDFF

	thumb_func_start FUN_080a0938
FUN_080a0938: @ 0x080A0938
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r0, #0x36
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A09B0
	ldrh r0, [r7, #0x34]
	cmp r0, #6
	bhi _080A0998
	adds r0, #1
	strh r0, [r7, #0x34]
	ldrh r0, [r7, #0x34]
	movs r4, #8
	subs r4, r4, r0
	adds r6, r4, #1
	movs r1, #0x28
	ldrsh r0, [r7, r1]
	muls r0, r4, r0
	ldr r5, _080A0994 @ =0x03003540
	movs r2, #0
	ldrsh r1, [r5, r2]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r7, #0x28]
	movs r3, #0x2a
	ldrsh r0, [r7, r3]
	muls r0, r4, r0
	movs r2, #2
	ldrsh r1, [r5, r2]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r7, #0x2a]
	movs r3, #0x2c
	ldrsh r0, [r7, r3]
	muls r0, r4, r0
	movs r4, #4
	ldrsh r1, [r5, r4]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	b _080A0CFE
	.align 2, 0
_080A0994: .4byte 0x03003540
_080A0998:
	movs r0, #8
	strh r0, [r7, #0x34]
	ldr r1, _080A09AC @ =0x03003540
	ldrh r0, [r1]
	strh r0, [r7, #0x28]
	ldrh r0, [r1, #2]
	strh r0, [r7, #0x2a]
	ldrh r0, [r1, #4]
	b _080A0CFE
	.align 2, 0
_080A09AC: .4byte 0x03003540
_080A09B0:
	ldr r1, _080A09EC @ =0x03002BE0
	ldrb r2, [r7, #0x1e]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r3, [r0]
	ldr r4, _080A09F0 @ =0x000003CE
	adds r0, r3, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r6, r1, #0
	mov ip, r2
	cmp r0, #0
	bne _080A09CC
	b _080A0AC8
_080A09CC:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _080A09FC
	ldr r0, _080A09F4 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080A09F8 @ =0x00000932
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	b _080A0A06
	.align 2, 0
_080A09EC: .4byte 0x03002BE0
_080A09F0: .4byte 0x000003CE
_080A09F4: .4byte 0x030046A0
_080A09F8: .4byte 0x00000932
_080A09FC:
	ldr r0, _080A0A80 @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _080A0A84 @ =0x00000932
	adds r0, r0, r3
	ldrh r0, [r0]
_080A0A06:
	strh r0, [r7, #0x30]
	ldrh r0, [r7, #0x34]
	cmp r0, #6
	bhi _080A0A8C
	adds r0, #1
	strh r0, [r7, #0x34]
	ldrh r0, [r7, #0x34]
	movs r4, #8
	subs r4, r4, r0
	adds r5, r4, #1
	movs r1, #0x28
	ldrsh r0, [r7, r1]
	muls r0, r4, r0
	mov r2, ip
	lsls r1, r2, #2
	adds r1, r1, r6
	ldr r1, [r1]
	movs r3, #0xf0
	lsls r3, r3, #2
	adds r1, r1, r3
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	adds r1, r5, #0
	bl Div
	strh r0, [r7, #0x28]
	movs r3, #0x2a
	ldrsh r0, [r7, r3]
	muls r0, r4, r0
	ldrb r1, [r7, #0x1e]
	lsls r1, r1, #2
	adds r1, r1, r6
	ldr r1, [r1]
	ldr r2, _080A0A88 @ =0x000003C2
	adds r1, r1, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	adds r1, r5, #0
	bl Div
	strh r0, [r7, #0x2a]
	movs r1, #0x2c
	ldrsh r0, [r7, r1]
	muls r0, r4, r0
	ldrb r1, [r7, #0x1e]
	lsls r1, r1, #2
	adds r1, r1, r6
	ldr r1, [r1]
	movs r2, #0xf1
	lsls r2, r2, #2
	adds r1, r1, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	adds r1, r5, #0
	bl Div
	b _080A0CFE
	.align 2, 0
_080A0A80: .4byte 0x030046A0
_080A0A84: .4byte 0x00000932
_080A0A88: .4byte 0x000003C2
_080A0A8C:
	movs r0, #8
	strh r0, [r7, #0x34]
	mov r4, ip
	lsls r0, r4, #2
	adds r0, r0, r6
	ldr r0, [r0]
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r7, #0x28]
	ldrb r0, [r7, #0x1e]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ldr r2, _080A0AC4 @ =0x000003C2
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r7, #0x2a]
	ldrb r0, [r7, #0x1e]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r0, [r0]
	movs r3, #0xf1
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrh r0, [r0]
	b _080A0CFE
	.align 2, 0
_080A0AC4: .4byte 0x000003C2
_080A0AC8:
	ldr r2, _080A0B00 @ =0x030046A0
	ldr r0, [r2]
	ldr r4, _080A0B04 @ =0x00000932
	adds r0, r0, r4
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldrh r4, [r7, #0x30]
	ldr r3, _080A0B08 @ =0xFFFFFF00
	adds r0, r4, r3
	subs r1, r1, r0
	movs r0, #0xff
	ands r1, r0
	movs r0, #0x80
	subs r0, r0, r1
	adds r3, r0, #0
	cmp r0, #0
	bge _080A0AEC
	rsbs r3, r0, #0
_080A0AEC:
	cmp r3, #0x10
	bgt _080A0B4C
	cmp r1, #0x80
	beq _080A0B1C
	cmp r1, #0x7f
	bgt _080A0B0C
	asrs r0, r0, #2
	adds r1, r0, #1
	adds r0, r4, r1
	b _080A0B16
	.align 2, 0
_080A0B00: .4byte 0x030046A0
_080A0B04: .4byte 0x00000932
_080A0B08: .4byte 0xFFFFFF00
_080A0B0C:
	adds r0, r1, #0
	subs r0, #0x80
	asrs r0, r0, #2
	subs r0, r4, r0
	adds r0, #0xff
_080A0B16:
	movs r1, #0xff
	ands r0, r1
	strh r0, [r7, #0x30]
_080A0B1C:
	movs r4, #0x32
	ldrsh r0, [r7, r4]
	lsls r1, r0, #1
	adds r1, r1, r0
	ldr r0, _080A0B44 @ =0xFFFFFED4
	adds r1, r1, r0
	asrs r1, r1, #2
	strh r1, [r7, #0x32]
	lsls r0, r1, #0x10
	cmp r0, #0
	bge _080A0B88
	rsbs r0, r1, #0
	strh r0, [r7, #0x32]
	ldr r0, [r2]
	ldr r1, _080A0B48 @ =0x00000932
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r7, #0x30]
	b _080A0B88
	.align 2, 0
_080A0B44: .4byte 0xFFFFFED4
_080A0B48: .4byte 0x00000932
_080A0B4C:
	cmp r1, #0
	beq _080A0B70
	cmp r1, #0x7f
	bgt _080A0B5C
	asrs r0, r1, #2
	adds r1, r0, #1
	adds r0, r4, r1
	b _080A0B6A
_080A0B5C:
	movs r0, #0x80
	lsls r0, r0, #1
	subs r1, r0, r1
	asrs r1, r1, #2
	adds r1, #1
	adds r0, r4, r0
	subs r0, r0, r1
_080A0B6A:
	movs r1, #0xff
	ands r0, r1
	strh r0, [r7, #0x30]
_080A0B70:
	movs r2, #0x32
	ldrsh r1, [r7, r2]
	ldr r0, _080A0BB4 @ =0x0000012B
	cmp r1, r0
	bgt _080A0B88
	lsls r0, r1, #1
	adds r0, r0, r1
	movs r4, #0x96
	lsls r4, r4, #1
	adds r0, r0, r4
	asrs r0, r0, #2
	strh r0, [r7, #0x32]
_080A0B88:
	ldrh r0, [r7, #0x34]
	adds r3, r0, #0
	cmp r3, #1
	bls _080A0C6C
	ldr r2, _080A0BB8 @ =0x085B0A08
	ldrh r0, [r7, #0x30]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r4, #0x32
	ldrsh r0, [r7, r4]
	muls r0, r1, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _080A0BBC
	asrs r1, r0, #0xc
	b _080A0BC2
	.align 2, 0
_080A0BB4: .4byte 0x0000012B
_080A0BB8: .4byte 0x085B0A08
_080A0BBC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A0BC2:
	mov r2, ip
	lsls r0, r2, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ldrh r0, [r0, #0x2c]
	adds r0, r0, r1
	strh r0, [r7, #0x20]
	ldrb r0, [r7, #0x1e]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r2, [r0]
	ldr r1, _080A0C0C @ =0x0000097A
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #0x80
	subs r0, r0, r1
	movs r1, #0x96
	muls r0, r1, r0
	asrs r0, r0, #7
	ldrh r2, [r2, #0x2e]
	adds r0, r0, r2
	strh r0, [r7, #0x22]
	ldrh r1, [r7, #0x30]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r4, #0x32
	ldrsh r0, [r7, r4]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A0C10
	asrs r1, r0, #0xc
	b _080A0C16
	.align 2, 0
_080A0C0C: .4byte 0x0000097A
_080A0C10:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A0C16:
	mov r2, ip
	lsls r0, r2, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ldrh r0, [r0, #0x30]
	adds r0, r0, r1
	strh r0, [r7, #0x24]
	subs r0, r3, #1
	strh r0, [r7, #0x34]
	ldrh r1, [r7, #0x34]
	adds r4, r1, #1
	movs r3, #0x28
	ldrsh r0, [r7, r3]
	muls r0, r1, r0
	movs r2, #0x20
	ldrsh r1, [r7, r2]
	adds r0, r0, r1
	adds r1, r4, #0
	bl Div
	strh r0, [r7, #0x28]
	movs r3, #0x2a
	ldrsh r1, [r7, r3]
	ldrh r0, [r7, #0x34]
	muls r0, r1, r0
	movs r2, #0x22
	ldrsh r1, [r7, r2]
	adds r0, r0, r1
	adds r1, r4, #0
	bl Div
	strh r0, [r7, #0x2a]
	movs r3, #0x2c
	ldrsh r1, [r7, r3]
	ldrh r0, [r7, #0x34]
	muls r0, r1, r0
	movs r2, #0x24
	ldrsh r1, [r7, r2]
	adds r0, r0, r1
	adds r1, r4, #0
	bl Div
	b _080A0CFE
_080A0C6C:
	movs r0, #0
	strh r0, [r7, #0x34]
	ldr r2, _080A0C94 @ =0x085B0A08
	ldrh r0, [r7, #0x30]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r4, #0x32
	ldrsh r0, [r7, r4]
	muls r0, r1, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _080A0C98
	asrs r1, r0, #0xc
	b _080A0C9E
	.align 2, 0
_080A0C94: .4byte 0x085B0A08
_080A0C98:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A0C9E:
	mov r2, ip
	lsls r0, r2, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ldrh r0, [r0, #0x2c]
	adds r0, r0, r1
	strh r0, [r7, #0x28]
	ldrb r0, [r7, #0x1e]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r2, [r0]
	ldr r3, _080A0CE8 @ =0x0000097A
	adds r0, r2, r3
	ldrh r1, [r0]
	movs r0, #0x80
	subs r0, r0, r1
	movs r1, #0x96
	muls r0, r1, r0
	asrs r0, r0, #7
	ldrh r2, [r2, #0x2e]
	adds r0, r0, r2
	strh r0, [r7, #0x2a]
	ldrh r1, [r7, #0x30]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r2, #0x32
	ldrsh r0, [r7, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A0CEC
	asrs r1, r0, #0xc
	b _080A0CF2
	.align 2, 0
_080A0CE8: .4byte 0x0000097A
_080A0CEC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A0CF2:
	mov r3, ip
	lsls r0, r3, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ldrh r0, [r0, #0x30]
	adds r0, r0, r1
_080A0CFE:
	strh r0, [r7, #0x2c]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EntityA628_Update
EntityA628_Update: @ 0x080A0D08
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	bl FUN_080a0864
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	beq _080A0DDC
	adds r0, r4, #0
	bl FUN_080a0938
	add r5, sp, #4
	adds r6, r4, #0
	adds r6, #0x28
	ldrh r0, [r4, #0x28]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080A0D40
	asrs r0, r0, #8
	b _080A0D46
_080A0D40:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080A0D46:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080A0D58
	asrs r0, r0, #8
	b _080A0D5E
_080A0D58:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080A0D5E:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r6, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080A0D72
	asrs r1, r0, #8
	b _080A0D78
_080A0D72:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_080A0D78:
	subs r0, r2, r1
	strh r0, [r5, #2]
	adds r0, r2, r1
	strh r0, [r5, #4]
	ldr r2, _080A0DAC @ =0x030047C8
	movs r3, #0
	ldrsh r1, [r2, r3]
	add r0, sp, #4
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r4, r1, r0
	adds r3, r4, #0
	adds r3, #0x80
	movs r1, #2
	ldrsh r0, [r2, r1]
	add r1, sp, #4
	movs r2, #2
	ldrsh r1, [r1, r2]
	subs r0, r0, r1
	adds r5, r0, #0
	adds r5, #0x80
	cmp r4, #0
	blt _080A0DB0
	asrs r1, r4, #3
	b _080A0DB6
	.align 2, 0
_080A0DAC: .4byte 0x030047C8
_080A0DB0:
	rsbs r0, r4, #0
	asrs r0, r0, #3
	rsbs r1, r0, #0
_080A0DB6:
	adds r0, r5, #0
	subs r0, #0x80
	cmp r0, #0
	blt _080A0DC2
	asrs r2, r0, #3
	b _080A0DC8
_080A0DC2:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r2, r0, #0
_080A0DC8:
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	subs r3, #0x78
	adds r0, r5, #0
	subs r0, #0x5a
	str r0, [sp]
	movs r0, #1
	bl Video_GenerateBGMap
_080A0DDC:
	movs r0, #0
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityA628_Destroy
EntityA628_Destroy: @ 0x080A0DE8
	ldr r1, _080A0DF0 @ =0x03002C3C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080A0DF0: .4byte 0x03002C3C

	thumb_func_start FUN_080a0df4
FUN_080a0df4: @ 0x080A0DF4
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080A0E48 @ =0x0000C091
	ldr r1, _080A0E4C @ =0x00000B12
	bl GetFile
	adds r2, r0, #0
	str r2, [r4, #0x18]
	movs r0, #0
	str r0, [sp, #0xc]
	str r0, [sp]
	movs r5, #1
	str r5, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #2
	movs r3, #0
	bl Video_SetupBGLayout
	movs r0, #1
	movs r1, #1
	bl SetBGPrioDirect
	ldr r0, _080A0E50 @ =0x03002B80
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #1
	bne _080A0E32
	movs r1, #1
_080A0E32:
	cmp r1, #0
	beq _080A0E5C
	ldr r2, _080A0E54 @ =0x03003E78
	ldr r0, _080A0E58 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	adds r0, #0x37
	strb r5, [r0]
	b _080A0E86
	.align 2, 0
_080A0E48: .4byte 0x0000C091
_080A0E4C: .4byte 0x00000B12
_080A0E50: .4byte 0x03002B80
_080A0E54: .4byte 0x03003E78
_080A0E58: .4byte 0xFFFFFDFF
_080A0E5C:
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	beq _080A0E74
	movs r0, #0x80
	lsls r0, r0, #2
	ldr r2, _080A0E70 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _080A0E7E
	.align 2, 0
_080A0E70: .4byte 0x03003E78
_080A0E74:
	ldr r0, _080A0E90 @ =0x03003E78
	ldr r1, _080A0E94 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_080A0E7E:
	adds r1, r4, #0
	adds r1, #0x37
	movs r0, #0
	strb r0, [r1]
_080A0E86:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A0E90: .4byte 0x03003E78
_080A0E94: .4byte 0xFFFFFDFF

	thumb_func_start EntityA628_Init
EntityA628_Init: @ 0x080A0E98
	push {r4, lr}
	adds r4, r0, #0
	strh r1, [r4, #0x1c]
	strb r2, [r4, #0x1e]
	strb r3, [r4, #0x1f]
	bl FUN_080a0df4
	adds r0, r4, #0
	bl FUN_080a0844
	ldr r2, _080A0ECC @ =0x085B0A08
	ldrh r0, [r4, #0x30]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0x32
	ldrsh r0, [r4, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A0ED0
	asrs r1, r0, #0xc
	b _080A0ED6
	.align 2, 0
_080A0ECC: .4byte 0x085B0A08
_080A0ED0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A0ED6:
	ldr r3, _080A0F24 @ =0x03002BE0
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldrh r0, [r0, #0x2c]
	subs r0, r0, r1
	strh r0, [r4, #0x28]
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r2, [r0]
	ldr r1, _080A0F28 @ =0x0000097A
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #0x80
	subs r0, r0, r1
	movs r1, #0x96
	muls r0, r1, r0
	asrs r0, r0, #7
	ldrh r2, [r2, #0x2e]
	adds r0, r0, r2
	strh r0, [r4, #0x2a]
	ldr r2, _080A0F2C @ =0x085B0A08
	ldrh r1, [r4, #0x30]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0x32
	ldrsh r0, [r4, r2]
	muls r0, r1, r0
	ldrb r2, [r4, #0x1e]
	cmp r0, #0
	blt _080A0F30
	asrs r1, r0, #0xc
	b _080A0F36
	.align 2, 0
_080A0F24: .4byte 0x03002BE0
_080A0F28: .4byte 0x0000097A
_080A0F2C: .4byte 0x085B0A08
_080A0F30:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A0F36:
	lsls r0, r2, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldrh r0, [r0, #0x30]
	subs r0, r0, r1
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl EntityA628_Update
	ldr r0, _080A0F54 @ =0x03002C3C
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A0F54: .4byte 0x03002C3C

	thumb_func_start EntityA628_Create
EntityA628_Create: @ 0x080A0F58
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	ldr r0, _080A0F98 @ =0x03002C3C
	ldr r4, [r0]
	cmp r4, #0
	bne _080A0FA4
	movs r0, #9
	movs r1, #0x38
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A0FA4
	ldr r1, _080A0F9C @ =EntityA628_Update
	ldr r2, _080A0FA0 @ =EntityA628_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl EntityA628_Init
	cmp r0, #0
	bge _080A0FA4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A0FA6
	.align 2, 0
_080A0F98: .4byte 0x03002C3C
_080A0F9C: .4byte EntityA628_Update
_080A0FA0: .4byte EntityA628_Destroy
_080A0FA4:
	adds r0, r4, #0
_080A0FA6:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a0fac
FUN_080a0fac: @ 0x080A0FAC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080A0FCC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A0FDA
	ldr r0, _080A0FD0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080A0FD4
	movs r4, #1
	rsbs r4, r4, #0
	b _080A0FEE
	.align 2, 0
_080A0FCC: .4byte 0x030047A4
_080A0FD0: .4byte 0x03002C68
_080A0FD4:
	movs r1, #0x18
	ldrsh r4, [r0, r1]
	b _080A0FEE
_080A0FDA:
	movs r0, #0x69
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A0FEC
	bl VM_GetValue
	adds r4, r0, #0
	b _080A0FEE
_080A0FEC:
	movs r4, #0
_080A0FEE:
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1000
	bl VM_GetValue
	adds r2, r0, #0
	b _080A1002
_080A1000:
	movs r2, #1
_080A1002:
	adds r0, r5, #0
	adds r1, r4, #0
	bl EntityA628_Create
	pop {r4, r5}
	pop {r1}
	bx r1
