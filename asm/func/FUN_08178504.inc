	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	mov r8, r0
	movs r2, #0xcb
	lsls r2, r2, #3
	add r2, r8
	ldr r0, _08178560 @ =0x00001022
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	beq _0817859C
	ldr r0, _08178564 @ =0x00001012
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r5, r0, #1
	cmp r5, #0
	blt _0817859C
	movs r0, #1
	mov sb, r0
	lsls r0, r5, #3
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r1, r0, #0
	adds r1, #0x1c
	adds r7, r1, r2
	adds r1, #0x7c
	adds r6, r1, r2
	adds r0, #0xfd
	adds r4, r0, r2
_08178550:
	ldrb r0, [r4]
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq _08178568
	movs r0, #1
	b _0817856A
	.align 2, 0
_08178560: .4byte 0x00001022
_08178564: .4byte 0x00001012
_08178568:
	movs r0, #0
_0817856A:
	cmp r0, #0
	bne _0817858E
	adds r0, r6, #0
	bl Hitbox_Unregister
	ldrb r1, [r4]
	mov r0, sb
	orrs r0, r1
	strb r0, [r4]
	ldr r1, _081785A8 @ =0x00001022
	add r1, r8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	movs r1, #0xa
	bl FUN_08176530
_0817858E:
	ldr r0, _081785AC @ =0xFFFFFEDC
	adds r7, r7, r0
	adds r6, r6, r0
	adds r4, r4, r0
	subs r5, #1
	cmp r5, #0
	bge _08178550
_0817859C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081785A8: .4byte 0x00001022
_081785AC: .4byte 0xFFFFFEDC
