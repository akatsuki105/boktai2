	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	movs r1, #0
	bl SetBGPrioDirect
	ldr r0, _0809CAFC @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0809CB00
	movs r0, #1
	rsbs r0, r0, #0
	b _0809CB04
	.align 2, 0
_0809CAFC: .4byte 0x03002C68
_0809CB00:
	movs r1, #0x18
	ldrsh r0, [r0, r1]
_0809CB04:
	ldr r3, _0809CB5C @ =0x000009DF
	adds r2, r4, r3
	movs r1, #0
	strb r0, [r2]
	adds r3, #0x1d
	adds r0, r4, r3
	strh r1, [r0]
	ldrb r0, [r2]
	ldr r1, _0809CB60 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r4, r2
	str r1, [r0]
	adds r0, r4, #0
	bl FUN_0809bd14
	adds r0, r4, #0
	bl FUN_0809ca08
	adds r0, r4, #0
	bl FUN_0809c880
	ldr r3, _0809CB64 @ =0x00000A9A
	adds r1, r4, r3
	movs r0, #0xff
	strb r0, [r1]
	ldr r0, _0809CB68 @ =0x00000A9B
	adds r1, r4, r0
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	ldr r2, _0809CB6C @ =0x000009FF
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _0809CB70 @ =0x0300013C
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809CB5C: .4byte 0x000009DF
_0809CB60: .4byte 0x03002BE0
_0809CB64: .4byte 0x00000A9A
_0809CB68: .4byte 0x00000A9B
_0809CB6C: .4byte 0x000009FF
_0809CB70: .4byte 0x0300013C
