	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl FUN_08013d10
	cmp r0, #0
	beq _08013F9E
	adds r1, r4, #0
	bl FUN_08013d28
	adds r2, r0, #0
	cmp r2, #0
	bne _08013FA4
_08013F9E:
	movs r0, #1
	rsbs r0, r0, #0
	b _08013FC6
_08013FA4:
	strb r5, [r2, #2]
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08013FB8
	adds r0, r2, #0
	adds r0, #0xc
	bl FUN_08013698
	b _08013FC4
_08013FB8:
	cmp r0, #2
	bne _08013FC4
	adds r0, r2, #0
	adds r0, #0xc
	bl FUN_080136b4
_08013FC4:
	movs r0, #0
_08013FC6:
	pop {r4, r5}
	pop {r1}
	bx r1
