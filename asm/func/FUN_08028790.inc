	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	mov sb, r1
	movs r1, #0x82
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xc7
	cmp r0, #0
	beq _080287AE
	movs r1, #0xc5
_080287AE:
	lsls r1, r1, #5
	mov r8, r1
	ldr r2, _08028808 @ =0x000008F4
	adds r4, r5, r2
	movs r7, #0
	movs r6, #2
_080287BA:
	movs r0, #2
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r0, sb
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r2, #0xb5
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #0
	ldr r3, _0802880C @ =0x00000201
	bl MainSprite_Add
	movs r0, #0x82
	lsls r0, r0, #7
	strh r0, [r4, #0x3a]
	ldr r0, _08028810 @ =0x03003584
	ldr r1, [r0]
	add r1, r8
	ldr r2, _08028814 @ =0x0000093C
	adds r0, r5, r2
	adds r0, r0, r7
	str r1, [r0]
	adds r4, #0x60
	adds r7, #0x60
	subs r6, #1
	cmp r6, #0
	bge _080287BA
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028808: .4byte 0x000008F4
_0802880C: .4byte 0x00000201
_08028810: .4byte 0x03003584
_08028814: .4byte 0x0000093C
