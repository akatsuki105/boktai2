	push {r4, r5, r6, r7, lr}
	ldr r3, _0822E77C @ =0x02035C00
	movs r2, #0
	ldr r4, _0822E780 @ =0x03000720
	ldr r0, [r4]
	mov ip, r4
	cmp r2, r0
	bhs _0822E76E
	ldr r7, _0822E784 @ =0x030006A0
	ldr r6, _0822E788 @ =0x0600A000
	ldr r1, _0822E78C @ =0x040000D4
	ldr r5, _0822E790 @ =0x84000008
_0822E754:
	adds r0, r2, r7
	ldrb r0, [r0]
	lsls r0, r0, #5
	adds r0, r0, r6
	str r3, [r1]
	str r0, [r1, #4]
	str r5, [r1, #8]
	ldr r0, [r1, #8]
	adds r3, #0x20
	adds r2, #1
	ldr r0, [r4]
	cmp r2, r0
	blo _0822E754
_0822E76E:
	movs r0, #0
	mov r1, ip
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822E77C: .4byte 0x02035C00
_0822E780: .4byte 0x03000720
_0822E784: .4byte 0x030006A0
_0822E788: .4byte 0x0600A000
_0822E78C: .4byte 0x040000D4
_0822E790: .4byte 0x84000008
