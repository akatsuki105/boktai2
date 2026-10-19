	push {r4, lr}
	adds r2, r0, #0
	adds r0, #0x61
	ldrb r0, [r0]
	adds r4, r0, #0
	adds r4, #0x20
	movs r0, #0xff
	ands r4, r0
	movs r0, #0xac
	lsls r0, r0, #2
	adds r3, r2, r0
	ldr r0, [r2, #0x64]
	ldr r1, [r2, #0x68]
	str r0, [r3]
	str r1, [r3, #4]
	ldrb r0, [r2, #6]
	cmp r0, #2
	beq _0820637C
	cmp r0, #9
	bne _08206394
_0820637C:
	ldrb r0, [r2, #0x1a]
	cmp r0, #4
	bne _08206394
	ldrh r0, [r3]
	subs r0, #0xc
	strh r0, [r3]
	movs r0, #0xad
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #0x10
	b _082063E2
_08206394:
	asrs r0, r4, #6
	cmp r0, #1
	beq _082063AE
	cmp r0, #1
	bgt _082063A4
	cmp r0, #0
	beq _082063D8
	b _082063E4
_082063A4:
	cmp r0, #2
	beq _082063B4
	cmp r0, #3
	beq _082063CC
	b _082063E4
_082063AE:
	movs r0, #0xac
	lsls r0, r0, #2
	b _082063DC
_082063B4:
	movs r0, #0xac
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #0x18
	strh r0, [r1]
	movs r0, #0xad
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #6
	b _082063E2
_082063CC:
	movs r0, #0xac
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #6
	strh r0, [r1]
_082063D8:
	movs r0, #0xad
	lsls r0, r0, #2
_082063DC:
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #0x20
_082063E2:
	strh r0, [r1]
_082063E4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
