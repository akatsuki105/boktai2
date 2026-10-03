	push {lr}
	ldr r0, _0809C458 @ =0x0300013C
	ldr r1, [r0]
	cmp r1, #0
	beq _0809C452
	ldr r2, _0809C45C @ =0x000009FE
	adds r0, r1, r2
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0809C452
	ldr r0, _0809C460 @ =0x00000A22
	adds r1, r1, r0
	movs r0, #4
	strh r0, [r1]
_0809C452:
	pop {r0}
	bx r0
	.align 2, 0
_0809C458: .4byte 0x0300013C
_0809C45C: .4byte 0x000009FE
_0809C460: .4byte 0x00000A22
