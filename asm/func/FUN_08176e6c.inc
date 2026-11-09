	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, _08176EAC @ =0x00001012
	adds r1, r2, r0
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r3, r0
	bge _08176ECE
	movs r5, #1
	adds r6, r1, #0
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	ldr r7, _08176EB0 @ =0x00000755
	adds r1, r0, r7
	adds r1, r1, r2
	movs r4, #0xcb
	lsls r4, r4, #3
	adds r0, r0, r4
	adds r2, r0, r2
	movs r4, #0x92
	lsls r4, r4, #1
_08176E9E:
	ldrb r0, [r1]
	ands r0, r5
	cmp r0, #0
	beq _08176EB4
	movs r0, #1
	b _08176EB6
	.align 2, 0
_08176EAC: .4byte 0x00001012
_08176EB0: .4byte 0x00000755
_08176EB4:
	movs r0, #0
_08176EB6:
	cmp r0, #0
	bne _08176EC0
	ldr r0, [r2]
	orrs r0, r5
	str r0, [r2]
_08176EC0:
	adds r1, r1, r4
	adds r2, r2, r4
	adds r3, #1
	movs r7, #0
	ldrsh r0, [r6, r7]
	cmp r3, r0
	blt _08176E9E
_08176ECE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
