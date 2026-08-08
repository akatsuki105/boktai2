	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, _0822B11C @ =0x0300358C
	ldr r0, [r0]
	cmp r0, #0
	bne _0822B124
	b _0822B140
	.align 2, 0
_0822B11C: .4byte 0x0300358C
_0822B120:
	adds r0, r1, #0
	b _0822B142
_0822B124:
	adds r1, r0, #0
	adds r1, #0xc
	movs r2, #0
	ldrh r0, [r0, #6]
	cmp r2, r0
	bge _0822B140
	adds r3, r0, #0
_0822B132:
	ldrh r0, [r1]
	cmp r0, r4
	beq _0822B120
	adds r2, #1
	adds r1, #8
	cmp r2, r3
	blt _0822B132
_0822B140:
	movs r0, #0
_0822B142:
	pop {r4}
	pop {r1}
	bx r1
