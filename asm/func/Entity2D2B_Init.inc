	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldr r0, _08008538 @ =0x03000034
	str r6, [r0]
	movs r5, #0
	movs r0, #0x20
	adds r0, r0, r6
	mov r8, r0
	mov sb, r6
_0800851C:
	ldr r0, _0800853C @ =0x085AA66C
	lsls r1, r5, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	ldr r0, _08008540 @ =0x0000CB05
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _08008544
	movs r0, #1
	rsbs r0, r0, #0
	b _080085A2
	.align 2, 0
_08008538: .4byte 0x03000034
_0800853C: .4byte 0x085AA66C
_08008540: .4byte 0x0000CB05
_08008544:
	mov r1, sb
	adds r1, #0x20
	adds r0, r2, #0
	ldm r0!, {r3, r4, r7}
	stm r1!, {r3, r4, r7}
	ldm r0!, {r3, r4, r7}
	stm r1!, {r3, r4, r7}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	mov r0, r8
	adds r1, r2, #0
	bl OpenMainSpriteFile
	movs r7, #0x20
	add r8, r7
	movs r0, #0x20
	add sb, r0
	adds r5, #1
	cmp r5, #1
	ble _0800851C
	movs r0, #0x6e
	movs r1, #8
	bl VM_GetNamedArgValue
	str r0, [r6, #0x18]
	movs r1, #0xe8
	adds r4, r0, #0
	muls r4, r1, r4
	adds r0, r4, #0
	bl Malloc
	str r0, [r6, #0x1c]
	adds r1, r4, #0
	bl ClearMemory
	ldr r4, [r6, #0x1c]
	movs r5, #0
	b _0800859C
_08008590:
	adds r0, r6, #0
	adds r1, r4, #0
	bl Entity2D2BElem_Init
	adds r5, #1
	adds r4, #0xe8
_0800859C:
	ldr r1, [r6, #0x18]
	cmp r5, r1
	blo _08008590
_080085A2:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
