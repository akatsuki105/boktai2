	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r1, _08216C14 @ =0x082527F0
	add r0, sp, #4
	movs r2, #0xc
	bl memcpy
	ldr r0, _08216C18 @ =0x0000166C
	adds r3, r4, r0
	ldr r2, _08216C1C @ =0x00001FDC
	adds r1, r4, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0xb
	bgt _08216C28
	add r0, sp
	adds r0, #4
	ldrb r1, [r0]
	ldr r2, _08216C20 @ =0x0000174C
	adds r0, r4, r2
	movs r2, #0
	strh r1, [r0]
	ldr r1, _08216C24 @ =0x0000174E
	adds r0, r4, r1
	strh r2, [r0]
	b _08216C42
	.align 2, 0
_08216C14: .4byte 0x082527F0
_08216C18: .4byte 0x0000166C
_08216C1C: .4byte 0x00001FDC
_08216C20: .4byte 0x0000174C
_08216C24: .4byte 0x0000174E
_08216C28:
	movs r2, #0
	ldrsh r0, [r1, r2]
	subs r0, #0xc
	add r0, sp
	adds r0, #4
	ldrb r1, [r0]
	ldr r2, _08216C80 @ =0x0000174C
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _08216C84 @ =0x0000174E
	adds r1, r4, r0
	movs r0, #0x10
	strh r0, [r1]
_08216C42:
	adds r1, r3, #0
	adds r1, #0xe0
	ldrh r0, [r1]
	subs r0, #0x80
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r1]
	adds r0, #0x10
	strh r0, [r1]
	adds r2, r3, #0
	adds r2, #0xc8
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r0, r3, #0
	adds r0, #0xc0
	adds r1, r4, #0
	adds r1, #0x18
	movs r2, #4
	str r2, [sp]
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08216C80: .4byte 0x0000174C
_08216C84: .4byte 0x0000174E
