	push {r4, r5, lr}
	ldr r2, _0808FFF0 @ =0x00004044
	adds r1, r0, r2
	movs r2, #0
	strh r2, [r1]
	ldr r3, _0808FFF4 @ =0x00004046
	adds r1, r0, r3
	strh r2, [r1]
	ldr r5, _0808FFF8 @ =0x00004038
	adds r4, r0, r5
	ldrb r1, [r4]
	ldr r2, _0808FFFC @ =0x0000402C
	adds r3, r0, r2
	ldr r2, [r3]
	lsls r1, r1, #4
	adds r1, r1, r2
	ldrb r1, [r1, #4]
	subs r1, #0x1e
	lsls r1, r1, #3
	adds r5, #0x10
	adds r2, r0, r5
	strh r1, [r2]
	ldrb r1, [r4]
	ldr r2, [r3]
	lsls r1, r1, #4
	adds r1, r1, r2
	ldrb r1, [r1, #5]
	subs r1, #0x14
	lsls r1, r1, #3
	adds r5, #2
	adds r2, r0, r5
	strh r1, [r2]
	ldrb r1, [r4]
	ldr r2, [r3]
	lsls r1, r1, #4
	adds r1, r1, r2
	ldrb r1, [r1, #2]
	lsls r1, r1, #3
	adds r5, #2
	adds r2, r0, r5
	strh r1, [r2]
	ldrb r1, [r4]
	ldr r2, [r3]
	lsls r1, r1, #4
	adds r1, r1, r2
	ldrb r1, [r1, #3]
	lsls r1, r1, #3
	ldr r2, _08090000 @ =0x0000404E
	adds r0, r0, r2
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808FFF0: .4byte 0x00004044
_0808FFF4: .4byte 0x00004046
_0808FFF8: .4byte 0x00004038
_0808FFFC: .4byte 0x0000402C
_08090000: .4byte 0x0000404E
