	push {r4, r5, r6, lr}
	ldr r4, _0822E7F4 @ =0x03000724
	ldr r0, [r4]
	cmp r0, #0
	beq _0822E7F8
	movs r0, #0
	b _0822E83C
	.align 2, 0
_0822E7F4: .4byte 0x03000724
_0822E7F8:
	movs r0, #0xc
	bl Malloc
	str r0, [r4]
	cmp r0, #0
	beq _0822E838
	movs r1, #0xc
	bl ClearMemory
	ldr r0, _0822E830 @ =0x0000A635
	ldr r1, _0822E834 @ =0x00003F51
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _0822E838
	ldr r1, [r4]
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldr r1, [r4]
	ldr r0, [r1, #4]
	adds r0, r0, r2
	str r0, [r1, #4]
	ldr r0, [r1, #8]
	adds r0, r0, r2
	str r0, [r1, #8]
	movs r0, #0
	b _0822E83C
	.align 2, 0
_0822E830: .4byte 0x0000A635
_0822E834: .4byte 0x00003F51
_0822E838:
	movs r0, #1
	rsbs r0, r0, #0
_0822E83C:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
