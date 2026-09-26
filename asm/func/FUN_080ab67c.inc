	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0x9d
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080AB6CE
	movs r3, #0
	movs r0, #0xb4
	lsls r0, r0, #1
	adds r4, r6, r0
	adds r1, #6
	adds r5, r6, r1
	movs r7, #0xb
_080AB69C:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080AB6B8
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, [r4, #0x18]
	adds r0, r5, #0
	str r3, [sp]
	bl _call_via_r2
	ldr r3, [sp]
	adds r3, #1
_080AB6B8:
	adds r4, #0x44
	adds r5, #0x44
	subs r7, #1
	cmp r7, #0
	bge _080AB69C
	cmp r3, #0
	bne _080AB6CE
	movs r1, #0x9d
	lsls r1, r1, #1
	adds r0, r6, r1
	strb r3, [r0]
_080AB6CE:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
