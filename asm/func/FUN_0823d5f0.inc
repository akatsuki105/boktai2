	push {lr}
	ldr r0, _0823D668 @ =0x03002BE0
	ldr r2, [r0]
	cmp r2, #0
	beq _0823D678
	ldr r0, _0823D66C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0823D678
	movs r1, #1
	ldr r0, _0823D670 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0823D678
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0823D678
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0823D678
	ldr r1, _0823D674 @ =0x00000446
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0823D64C
	subs r1, #4
	adds r0, r2, r1
	ldrh r0, [r0]
	subs r0, #5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _0823D678
_0823D64C:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	movs r1, #1
	cmp r0, #1
	bls _0823D660
	cmp r0, #7
	beq _0823D660
	movs r1, #0
_0823D660:
	cmp r1, #0
	beq _0823D678
	movs r0, #1
	b _0823D67A
	.align 2, 0
_0823D668: .4byte 0x03002BE0
_0823D66C: .4byte 0x030047A4
_0823D670: .4byte 0x03002BC0
_0823D674: .4byte 0x00000446
_0823D678:
	movs r0, #0
_0823D67A:
	pop {r1}
	bx r1
	.align 2, 0
