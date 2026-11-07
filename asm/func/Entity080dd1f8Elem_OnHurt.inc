	push {lr}
	adds r3, r2, #0
	mov ip, r3
	movs r1, #4
	ldr r2, [r0, #0x38]
	ands r1, r2
	cmp r1, #0
	beq _080DC62E
	movs r0, #0x99
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0
	b _080DC64A
_080DC62E:
	movs r0, #8
	ands r2, r0
	cmp r2, #0
	beq _080DC64C
	movs r1, #0x99
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	cmp r0, #0x59
	bls _080DC64C
	movs r0, #0x9f
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
_080DC64A:
	strh r0, [r1]
_080DC64C:
	pop {r0}
	bx r0
