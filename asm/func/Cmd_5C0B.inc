	push {r4, r5, r6, r7, lr}
	ldr r0, _0800372C @ =0x03000020
	ldr r5, [r0]
	cmp r5, #0
	bne _08003730
	movs r0, #1
	rsbs r0, r0, #0
	b _08003772
	.align 2, 0
_0800372C: .4byte 0x03000020
_08003730:
	ldr r1, [r5, #0x70]
	movs r4, #0
	ldrh r0, [r5, #0x18]
	cmp r4, r0
	bge _08003770
	ldr r6, _08003778 @ =EntityD9AEElem_UpdateBreak
_0800373C:
	ldrb r0, [r1, #0x1e]
	cmp r0, #0
	beq _08003762
	ldrb r3, [r1]
	cmp r3, #1
	bne _08003762
	movs r0, #0
	strh r0, [r1, #0x16]
	ldrh r2, [r1, #4]
	cmp r2, #0
	bne _08003762
	movs r7, #0xcc
	lsls r7, r7, #1
	adds r0, r1, r7
	str r6, [r0]
	strh r2, [r1, #2]
	strb r3, [r1, #0x11]
	movs r0, #3
	strh r0, [r1, #4]
_08003762:
	movs r0, #0xce
	lsls r0, r0, #1
	adds r1, r1, r0
	adds r4, #1
	ldrh r7, [r5, #0x18]
	cmp r4, r7
	blt _0800373C
_08003770:
	movs r0, #0
_08003772:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08003778: .4byte EntityD9AEElem_UpdateBreak
