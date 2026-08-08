	push {r4, r5, lr}
	adds r2, r0, #0
	adds r5, r1, #0
	ldr r3, [r2, #0x1c]
	cmp r3, #1
	bne _0807AD8A
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r1, [r0]
	cmp r1, #2
	beq _0807AD8A
	movs r0, #0xfb
	lsls r0, r0, #2
	adds r4, r2, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _0807AD94
	ldr r1, _0807AD90 @ =0x000003EA
	adds r0, r2, r1
	strh r3, [r0]
_0807AD8A:
	movs r0, #0
	b _0807ADB6
	.align 2, 0
_0807AD90: .4byte 0x000003EA
_0807AD94:
	subs r0, r1, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0807ADAC
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r2, r1
	strb r3, [r0]
	adds r1, #1
	adds r0, r2, r1
	strb r3, [r0]
_0807ADAC:
	strh r5, [r4]
	ldr r1, _0807ADBC @ =0x000003EA
	adds r0, r2, r1
	strh r3, [r0]
	movs r0, #1
_0807ADB6:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0807ADBC: .4byte 0x000003EA
