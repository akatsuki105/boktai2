	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0xe
	bhi _08221188
	lsls r0, r0, #2
	ldr r1, _0822110C @ =_08221110
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0822110C: .4byte _08221110
_08221110: @ jump table
	.4byte _08221188 @ case 0
	.4byte _08221188 @ case 1
	.4byte _08221188 @ case 2
	.4byte _08221188 @ case 3
	.4byte _08221188 @ case 4
	.4byte _08221188 @ case 5
	.4byte _08221188 @ case 6
	.4byte _08221188 @ case 7
	.4byte _0822114C @ case 8
	.4byte _08221188 @ case 9
	.4byte _08221188 @ case 10
	.4byte _08221180 @ case 11
	.4byte _08221188 @ case 12
	.4byte _08221188 @ case 13
	.4byte _08221188 @ case 14
_0822114C:
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r3, _08221178 @ =0x000003BE
	adds r1, r4, r3
	movs r5, #0
	ldrsh r1, [r1, r5]
	adds r3, #2
	adds r2, r4, r3
	movs r5, #0
	ldrsh r2, [r2, r5]
	movs r3, #0
	str r3, [sp]
	ldr r5, _0822117C @ =0x000003C2
	adds r3, r4, r5
	movs r4, #0
	ldrsh r3, [r3, r4]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_082364f8
	b _08221188
	.align 2, 0
_08221178: .4byte 0x000003BE
_0822117C: .4byte 0x000003C2
_08221180:
	ldr r5, _08221190 @ =0x000003D9
	adds r1, r4, r5
	movs r0, #0
	strb r0, [r1]
_08221188:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08221190: .4byte 0x000003D9
