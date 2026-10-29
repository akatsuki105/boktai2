	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	ldr r0, _080176BC @ =0x0300006C
	str r7, [r0]
	ldr r0, _080176C0 @ =0x0000CB05
	ldr r1, _080176C4 @ =0x00005D04
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _080176C8
	movs r0, #1
	rsbs r0, r0, #0
	b _0801773A
	.align 2, 0
_080176BC: .4byte 0x0300006C
_080176C0: .4byte 0x0000CB05
_080176C4: .4byte 0x00005D04
_080176C8:
	adds r1, r7, #0
	adds r1, #0x1c
	adds r0, r2, #0
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r5, r7, #0
	adds r5, #0x1c
	adds r0, r5, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	movs r0, #0
	str r0, [r7, #0x18]
	add r4, sp, #0x14
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r4, #0
	ldr r2, _0801774C @ =0x05000002
	bl CpuSet
	mov sb, r5
	mov sl, r4
	movs r6, #0
	movs r5, #1
	mov r8, r5
	adds r4, r7, #0
	adds r4, #0x60
	adds r5, r7, #0
	adds r5, #0x3c
	movs r7, #7
_0801770C:
	str r6, [r5]
	mov r0, r8
	strb r0, [r5, #4]
	strb r6, [r5, #6]
	str r6, [r5, #0xc]
	mov r3, r8
	str r3, [sp]
	str r6, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	movs r3, #0x11
	bl MainSprite_Add
	adds r4, #0x84
	adds r5, #0x84
	subs r7, #1
	cmp r7, #0
	bge _0801770C
_0801773A:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801774C: .4byte 0x05000002
