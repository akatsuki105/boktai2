	push {r4, r5, r6, r7, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	movs r4, #0
	movs r3, #0
	ldr r5, _0817843C @ =0x00001012
	adds r2, r1, r5
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r3, r0
	bge _08178468
	movs r7, #1
	movs r0, #3
	rsbs r0, r0, #0
	mov ip, r0
	adds r5, r2, #0
	ldr r0, _08178440 @ =0x00000755
	adds r2, r1, r0
	movs r6, #0x92
	lsls r6, r6, #1
_08178430:
	ldrb r0, [r2]
	ands r0, r7
	cmp r0, #0
	beq _08178444
	movs r0, #1
	b _08178446
	.align 2, 0
_0817843C: .4byte 0x00001012
_08178440: .4byte 0x00000755
_08178444:
	movs r0, #0
_08178446:
	cmp r0, #0
	bne _0817845C
	cmp r4, #1
	bne _08178452
	movs r4, #0
	b _0817845C
_08178452:
	ldrb r1, [r2]
	mov r0, ip
	ands r0, r1
	strb r0, [r2]
	adds r4, #1
_0817845C:
	adds r2, r2, r6
	adds r3, #1
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r3, r0
	blt _08178430
_08178468:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
